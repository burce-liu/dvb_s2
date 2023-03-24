//
// Created by 人即、 on 2023/3/22.
//

#ifndef DVB_S2_DVB_S2_H
#define DVB_S2_DVB_S2_H
#include <iostream>
#include <cstdio>
#include <bitset>
#include<cstdlib>
#include <vector>
#include<cmath>
#include<complex>
#include<algorithm>
typedef struct BBHeader
{
    uint8_t mytype1;
    uint8_t mytype2;
    unsigned short upl;
    unsigned short dpl;
    uint8_t sync;
    unsigned short syncd;
    uint8_t crc;
} BBHeader;
using namespace std;
#endif //DVB_S2_DVB_S2_H
