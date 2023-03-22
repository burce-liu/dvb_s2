#include "dvb_s2.h"
#pragma once
#include "getKbch.h"
#include "generate_crc.h"
#include "get_bbheader.h"
// DVB-S2 TS packet

#define CRC_POLY 0xAB


//create a struct to add DVB-S2 BBheader include 8bits mytpye1, 8bits mytype2,16bits upl,16bits dpl, 8bits sync, 16bits syncd, 8bits crc


//创建一个函数 将字符串转化为十进制数
#define N 16
int binarytod(char s[])
{
    int i,sum=0;
    for(i=0;s[i]!='\0'&&i<N;i++)
        sum=2*sum+(s[i]-48);       //这里的48等价于'0'
    return sum;
}

vector<bool> scraming(vector<bool> data, int Kbch) {
    // Implement this function
    return data;
}

// Computes the BCH code of a given binary string
vector<bool> dvb_bch2(vector<bool>& data, int modcod, bool type) {
    // TODO: Implement BCH encoding
    return data;
}

// Computes the LDPC code of a given binary string
vector<bool> dvb_ldpc(vector<bool>& data, int modcod, bool type) {
    // TODO: Implement LDPC encoding
    return data;
}

// Interweaves the bits of a given binary string
vector<bool> interweave(vector<bool>& data, int modcod, bool type) {
    // TODO: Implement bit interleaving
    return data;
}

// Reflects the bits of a given binary string
vector<std::complex<double>> dvb_reflect(vector<bool>& data, int modcod) {
    // TODO: Implement bit reflection
    vector<std::complex<double>> complex_ve;
    return complex_ve;
}

vector<std::complex<double>> dvb_pl(vector<std::complex<double>> data, int modcod,bool type1,bool type2) {
    // Implement this function
    vector<std::complex<double>> complex_ve;
    return complex_ve;
}




//turntobool


//crc
vector<bool>  crc_data(vector<bool> data)
{
    vector<bool> temp3;
    int data_crc = data.size();
    int num_crc = data_crc/188/8;
        for (int i = 0; i < num_crc; i++)
        {
            vector<bool> temp2;
             //将data的每个188*8位的数据分别取出到temp2中
            for (int j = i*188*8+8; j < (i+1)*188*8; j++)
               {
                temp2.push_back(data[j]);
                temp3.push_back(data[j]);
               } 
            //将temp2的数据进行crc校验
            vector<bool> crc_code = generate_crc(temp2);
            
            //释放temp2的内存
            temp2.clear();

            //将crc_code的数据添加到temp3中
            for (int k = 0; k < crc_code.size(); k++)
                {
                    temp3.push_back(crc_code[k]);

                }
            cout<<endl;
        }
           

        return temp3;
}


int main()
{
    // initial
    char modulation[]="00111";
    int modcod;
    modcod=binarytod(modulation);
    bool type1 = 0;
    bool type2 = 1;

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


    FILE *fp = fopen("D:\\dvb_s2\\test.ts", "rb");
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
       /* while (~feof(fp))
        {*/
            //判断此次读入的数据大小是否大于预估的dfl长度
            if (file_length < dfl_pre)
            {
                dfl_pre = file_length;
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
            for (int i = 0; i < 100; i++)
            {
                printf("%d\t", buffer[i]);
            }
            cout<<endl;


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
        /*    //打印temp1的值
            int k = 0;
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
        /*    //打印data_crc的每8位的值转化为十进制打印
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
            vector<bool>().swap(temp1);

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

            //
            //padding data_crc to Kbch length
            int num = Kbch - data_crc.size();
            for(int i=0;i<num;i++)
            {
                data_crc.push_back(0);
            }
            cout<<data_crc[data_crc.size()-1];
            
            // scraming
            vector<bool> data_scram = scraming(data_crc,modcod);

            // bch
            vector<bool> data_bch = dvb_bch2(data_scram,modcod,type1);

            // ldpc
            vector<bool> data_ldpc = dvb_ldpc(data_bch,modcod,type1);

            // interweave
            vector<bool> data_interweave = interweave(data_ldpc,modcod,type1);

            // reflect
            vector<std::complex<double>> data_reflect = dvb_reflect(data_interweave,modcod);

            // pl
            vector<complex<double>> data_pl = dvb_pl(data_reflect,modcod,type1,type2);


            

            


        }
    //}



    fclose(fp);




}
