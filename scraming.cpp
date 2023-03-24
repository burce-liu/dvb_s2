//
// Created by 人即、 on 2023/3/23.
//
#include "scraming.h"
vector<bool> scraming(vector<bool> data, int Kbch) {
    // Implement this function

    //对vector<bool> PRBS_g 赋值 [1 0 0 1 0 1 0 1 0 0 0 0 0 0 0];
    vector<bool> PRBS_g = {1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    //实现加扰算法
    for (int i = 0; i < Kbch; i++) {
        data[i] = data[i] ^ PRBS_g[14] ^ PRBS_g[13];
        PRBS_g.insert(PRBS_g.begin(), PRBS_g[14] ^ PRBS_g[13]);
        PRBS_g.pop_back();
    }


    return data;
}