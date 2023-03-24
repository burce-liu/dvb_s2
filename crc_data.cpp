//
// Created by 人即、 on 2023/3/23.
//
#include "crc_data.h"
#include "generate_crc.h"
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

    }


    return temp3;
}
