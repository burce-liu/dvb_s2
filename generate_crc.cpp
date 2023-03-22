//
// Created by 人即、 on 2023/3/22.
//
#include "generate_crc.h"
vector<bool> generate_crc(vector<bool> data) {

    bool b = 0;
    for(int j=0;j<8;j++)
    {
        data.push_back(b);
    }
    for(int i = 0 ; i< data.size()-8; i++)
    {
        if(data[i])
        {
            data[i+1] = data[i+1] ^ 1;
            data[i+2] = data[i+2] ^ 1;
            data[i+4] = data[i+4] ^ 1;
            data[i+6] = data[i+6] ^ 1;
            data[i+8] = data[i+8] ^ 1;
        }
        else
        {

        }
    }
    vector<bool> result;
    result.reserve(8);
    for (int i = 0; i <8; i++) {
        int j = data.size()-1 ;
        result.insert(result.begin(),data[j-i]);
    }

    return result;
}