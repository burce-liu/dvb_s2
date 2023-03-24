//
// Created by 人即、 on 2023/3/24.
//

#include "data_interweave.h"
vector<bool> interweave(vector<bool>data_ldpc,int modcod,bool type)
{
    int n = 0;
    int col = 0;
    int row = 0;
    vector<bool> data_interweave;

    if(~type)
    {
        n = 64800;
    }
    else
    {
        n = 16200;
    }
    data_interweave.reserve(n);
    if(modcod<=17&&modcod>=12)
    {
        col = 3;
        row = n/col;
    }
    else if(modcod<=23&&modcod>=18)
    {
        col = 4;
        row = n/col;
    }
    else if(modcod<=28&&modcod>=24)
    {
        col = 5;
        row = n/col;
    }
    else 
    {
        col = 1;
        row = n/col;
    }

    //交织
    if(modcod!=12)
    {
        
        for(int j = 0; j<row;j++)
        {
         for(int i = 0;i<col;i++)
            {
                //插入数据
                data_interweave.push_back(data_ldpc[i*row+j]);
            }
        }
    }
    else
    {
                for(int j = 0; j<row;j++)
        {
         for(int i = col-1 ;i>=0;i--)
            {
                //插入数据
                data_interweave.push_back(data_ldpc[i*row+j]);
            }
        }
    }
    
}
