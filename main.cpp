#include <chrono>
#include "dvb_s2.h"
#include "getKbch.h"
#include "get_bbheader.h"
#include "crc_data.h"
#include "scraming.h"
#include "dvb_bch.h"
#include "dvb_ldpc.h"
#include "data_reflect.h"
#include "data_interweave.h"
#include "dvb_pl.h"
// DVB-S2 TS packet


//创建一个函数 将字符串转化为十进制数
#define N 16
int binarytod(char s[])
{
    int i,sum=0;
    for(i=0;s[i]!='\0'&&i<N;i++)
        sum=2*sum+(s[i]-48);       //这里的48等价于'0'
    return sum;
}

void print_vector(vector<bool> data, int i, int start)
{
    for(int k=start;k<start+i;k++)
    {

        cout<<data[k]<<" ";
    }
}

void print_vector(vector<complex<double>> data, int i, int start)
{
    for(int k=start;k<start+i;k++)
    {

        cout<<data[k]<<" ";
    }
}



int main()
{
    auto start_time = chrono::high_resolution_clock::now();


    // 程序代码


    // initial
    char modulation[]="00111";
    int modcod;
    modcod=binarytod(modulation);
    bool type1 = false;
    bool type2 = true;
    int k = 0;

    // get Kbch value and read data length
    int Kbch = getKbch(modcod,type1);
    int upl = 188*8; //bits
    int dfl_pre = upl*floor((Kbch-80)/upl)/8;//预估的dfl长度 字节数

    // create a struct BBheader pointer to store the value of BBheader
    BBHeader *bbheader = (BBHeader *)malloc(sizeof(BBHeader));
    //将二进制'11110001'赋值给bbheader->mytype1
    // 单TS流 不同步 CCM 非空包删除 滚降系数0.25
    bbheader->mytype1 = 0xF1;
    bbheader->mytype2 = 0x00;
    bbheader->upl = upl;
    bbheader->sync = 0x47;
    bbheader->syncd = 0x0000;


    FILE *fp = fopen("D:\\dvb_s2\\overflowqpsk_276_45_2.ts", "rb");
    //读取文件总长度
    fseek(fp, 0, SEEK_END);
    int file_length = ftell(fp);
    //将文件指针指向文件开头
    fseek(fp, 0, SEEK_SET);
    if (fp == NULL) {
        printf("open file error");
    }
    else
    {
        printf("open file success");
        //判断文件是否读完
        while (file_length>0)
        {
            //判断此次读入的数据大小是否大于预估的dfl长度
            cout<<"file_length:"<<file_length<<"bytes"<<endl;
            if (file_length < dfl_pre)
            {
                dfl_pre = file_length;
                file_length = 0;
            }
            //如果大于则读入预估的dfl长度，并且将文件长度减去预估的dfl长度
            else
            {
                file_length = file_length - dfl_pre;
            }
            //创建一个buffer用来存储读入的数据 十进制形式
            unsigned char *buffer = (unsigned char *)malloc(dfl_pre);
            fread(buffer, dfl_pre, 1, fp);
            //打印buffer的值in binary
            /*
            for (int i = 0; i < 100; i++)
            {
                printf("%d\t", buffer[i]);
            }
            cout<<endl;*/


            //将buffer全部转化为bool类型的vector
            //temp1是读入的原始数据二进制形式
            vector<bool> temp1;
            for(int i=0;i<dfl_pre;i++)
            {
                bitset<8> b(buffer[i]);
                for(int j=8;j>0;j--)
                {
                    temp1.push_back(b[j-1]);
                }
            }
            //打印temp1的值
        /* int k = 0;
         cout<<"temp1"<<endl;
         for (bool b : temp1)
         {
             if(k>100)
             {
                 break;
             }
             else
             {
                 k++;
                 cout<<b<<" ";
             }

         }
*/

            //释放掉buffer的内存
            free(buffer);
            //将temp1中的数据按照1504bits分别进行crc-8校验
            vector<bool> data_crc = crc_data(temp1);

/*           //打印data_crc的每8位的值转化为十进制打印
           k = 0;
           cout<<"data_crc"<<endl;
           for (bool b : data_crc)
           {
               if(k>200)
               {
                   break;
               }
               else
               {
                   k++;
                   cout<<b<<" ";
               }

           }
           cout<<endl;

           //打印data_crc i*188*8-8到i*188*8的值
           k = 0;
           cout<<"data_crc"<<endl;
           for(k=1;k<10;k++)
           {
               cout<<k<<"crc:";
               for(int j=0;j<8;j++)
               {
                   cout<<data_crc[k*188*8+j-8]<<" ";
               }
               cout<<endl;
           }
       */

            //释放掉vector temp1的内存
            temp1.clear();

            //计算bbheader->dpl的值 bit值
            bbheader->dpl = dfl_pre*8;

            //创建一个vector 将结构bbheader的数据转化为bool类型的vector 并计算bbheader的crc
            vector<bool> bbheader_vector = get_bbheader(bbheader);


        /*//打印bbheader
            k = 0;
            cout<<"bbheader"<<endl;
            for(k=0;k<80;k++)
            {

                    cout<<bbheader_vector[k]<<" ";
            }*/

            // 将bbheader_vector的数据添加到vector data_crc最前方
            for(int i=bbheader_vector.size();i>0;i--)
            {
                data_crc.insert(data_crc.begin(),bbheader_vector[i-1]);
            }


            //padding data_crc to Kbch length
            int num = Kbch - data_crc.size();
            for(int i=0;i<num;i++)
            {
                data_crc.push_back(bool(0));
            }

        /*//打印data_crc的前500个值
        cout<<"data_pad"<<endl;
        print_vector(data_crc,500);*/

            // scraming
            vector<bool> data_scram = scraming(data_crc,Kbch);

            //清楚data_crc内存
            data_crc.clear();

            // bch
            vector<bool> data_bch = dvb_bch(data_scram,modcod,type1);




/*
        //打印data_bch的后500个值
        cout<<endl<<"data_bch"<<endl;
        print_vector(data_bch,192,Kbch);
        */

            vector<bool> data_ldpc = dvb_ldpc(data_bch,modcod,type1);

           /* //打印data_bch的后500个值
            cout<<endl<<"data_ldpc"<<endl;
            print_vector(data_ldpc,240,data_ldpc.size()-240);
            */

           // interweave
            vector<bool> data_interweave = interweave(data_ldpc,modcod,type1);

         /*   //打印data_interweave的后500个值
            cout<<endl<<"data_interweave"<<endl;
            print_vector(data_interweave,240,0);   */

            // reflect
            vector<complex<double>> data_reflect = dvb_reflect(data_interweave,modcod);

            // pl
            vector<complex<double>> data_pl = dvb_pl(data_reflect,modcod,type1,type2);
            auto end_time = chrono::high_resolution_clock::now();

            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

            cout << duration.count() << " us" << endl;

            }

        }

    fclose(fp);

}
