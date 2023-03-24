//
// Created by 人即、 on 2023/3/24.
//

#include "dvb_pl.h"

    vector<complex<double>> PL_Header_mod = plheader(int modcod, bool type1, bool type2)
    {
            int SOF[26] = {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0};
    int G[6][32] = {
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    //将modcod转化为二进制
    vector<int> acm_code_num(6);
    for (int i = 0; i < 5; ++i)
    {
        acm_code_num[i] = modcod % 2;
        modcod /= 2;
    }
    acm_code_num[5] = int(type1);
     vector<int> y(32);
     for(int i = 0; i < 32; ++i)
     {
        for(int j = 0; j < 6; ++j)
        {
            y[i] += acm_code_num[j]*G[j][i]  ;
        }
        y[i] %= 2;
     }
     vector<int> y_all(64);
     for(int i = 0; i < 32; ++i)
     {
        y_all[2*i] = y[i];
        //type2为1时，表示有导频，此时y_all[2*i+1]取反
        if(type2)
            y_all[2*i+1] = (y[i] + 1) % 2;
        else
            y_all[2*i+1] = y[i];
     }
    const  vector<int> bit_dis = {0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1,
     0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0};
      //加扰，将y_all与bit_dis异或
     vector<int> y_dis(64);
    for (int i = 0; i < 64; ++i)
    {
        y_dis[i] = (y_all[i] + bit_dis[i]) % 2;
    }
        
     vector<int> pl_header(90);
    //前26位为SOF
    for (int i = 0; i < 26; ++i)  
        {
            pl_header[i] = SOF[i];
        }
    //后64位为y_dis
    for (int i = 0; i < 64; ++i)
        pl_header[i + 26] = y_dis[i];
     vector< complex<double>> PL_Header_mod(pl_header.size());
    for (int i = 0; i < pl_header.size(); ++i)
    {
        if (pl_header[i] == 0 && i % 2 == 0)
            PL_Header_mod[i] =  complex<double>(1.0 /  sqrt(2), 1.0 /  sqrt(2));
        else if (pl_header[i] == 1 && i % 2 == 0)
            PL_Header_mod[i] =  complex<double>(-1.0 /  sqrt(2), -1.0 /  sqrt(2));
        else if (pl_header[i] == 0 && i % 2 == 1)
            PL_Header_mod[i] =  complex<double>(-1.0 /  sqrt(2), 1.0 /  sqrt(2));
        else
            PL_Header_mod[i] =  complex<double>(1.0 /  sqrt(2), -1.0 /  sqrt(2));
    }
    return PL_Header_mod;
    }

vector<complex<double>> dvb_pl(vector<complex<double>> data, int modcod, bool type1, bool type2)
{
    int S;
    // 根据编码方式得到 S 的数量
    if (!type)
    {
        if (modcod >= 1 && modcod <= 11)
            S = 360;
        else if (modcod >= 12 && modcod <= 17)
            S = 240;
        else if (modcod >= 18 && modcod <= 23)
            S = 180;
        else if (modcod >= 24 && modcod <= 28)
            S = 144;
    }
    else
    {
        if (modcod >= 1 && modcod <= 10)
            S = 90;
        else if (modcod >= 12 && modcod <= 16)
            S = 60;
        else if (modcod >= 18 && modcod <= 22)
            S = 45;
        else if (modcod >= 24 && modcod <= 27)
            S = 36;
    }

    // pl 帧头
    vector<complex<double>> PL_Header_mod = plheader(modcod,type1,type2);
    // 判断是否生成虚拟帧
    if (data.empty())
    {
        data.resize(36 * 90);
        for (int i = 0; i < 36 * 90; i++)
            data[i] = (1 / sqrt(2)) + 1i * (1 / sqrt(2));
    }
    // 判断是否加入导频
    vector<complex<double>> data_pilot;
    if (acm_code_num(7)) // 加入导频
        data_pilot = pl_pilot(data, S);
    else
        data_pilot = data;

    int n = 0;
    vector<complex<double>> data_dis = pl_dis(data_pilot, n);
    vector<complex<double>> data_pl(PL_Header_mod.size() + data_dis.size());
    copy(PL_Header_mod.begin(), PL_Header_mod.end(), data_pl.begin());
    copy(data_dis.begin(), data_dis.end(), data_pl.begin() + PL_Header_mod.size());

    return data_pl;
}




