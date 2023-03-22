//
// Created by 人即、 on 2023/3/22.
//
#include "get_bbheader.h"
#include "generate_crc.h"
vector<bool> get_bbheader(BBHeader* bbheader)

{

    vector<bool> temp1;
    bitset<8> b(bbheader->mytype1);
    // 由于b是反转的 故reverse b to push_back

    for(int j=7;j>=0;j--)
    {
        temp1.push_back(b[j]);
    }
    bitset<8> b1(bbheader->mytype2);
    for(int j=7;j>=0;j--)
    {
        temp1.push_back(b1[j]);
    }
    bitset<16> b2(bbheader->upl);
    for(int j=15;j>=0;j--)
    {
        temp1.push_back(b2[j]);
    }
    bitset<16> b3(bbheader->dpl);
    for(int j=15;j>=0;j--)
    {
        temp1.push_back(b3[j]);
    }
    bitset<8> b4(bbheader->sync);
    for(int j=7;j>=0;j--)
    {
        temp1.push_back(b4[j]);
    }
    bitset<16> b5(bbheader->syncd);
    for(int j=15;j>=0;j--)
    {
        temp1.push_back(b5[j]);
    }

    //计算crc 并创建完整的bbheader
    vector<bool> bbheader_crc;
    bbheader_crc.reserve(8);

    //创建一个函数 计算bbheader->crc的值
    bbheader_crc = generate_crc(temp1);
    //将bbheader_crc的值加入到bbheader_vector中
    for(int i=0;i<8;i++)
    {
        temp1.push_back(bbheader_crc[i]);
    }


    return temp1;
}

