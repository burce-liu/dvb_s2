//
// Created by 人即、 on 2023/3/23.
//

#include "dvb_bch.h"
vector<bool> gfconv(vector<bool> P, vector<bool> Q) {
    int n = P.size(), m = Q.size();
    vector<bool> result(n + m - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i+j] = result[i+j]^(P[i] & Q[j]) ;
        }
    }
    return result;
}

vector<bool> build_bch_ploy( int modcod, bool type) 
{
    vector<bool> polyn01 ={true,false,true,true,false,true,false,false,false,false,false,false,false,false,false,false,true};
    vector<bool> polyn02 ={true,true,false,false,true,true,true,false,true,false,false,false,false,false,false,false,true};
    vector<bool> polyn03 ={true,false,true,true,true,true,false,true,true,true,true,true,false,false,false,false,true};
    vector<bool> polyn04 ={true,false,true,false,true,false,true,false,false,true,false,true,true,false,true,false,true};
    vector<bool> polyn05 ={true,true,true,true,false,true,false,false,true,true,true,true,true,false,false,false,true};
    vector<bool> polyn06 ={true,false,true,false,true,true,false,true,true,true,true,false,true,true,true,true,true};
    vector<bool> polyn07 ={true,false,true,false,false,true,true,false,true,true,true,true,false,true,false,true,true};
    vector<bool> polyn08 ={true,true,true,false,false,true,true,false,true,true,false,false,true,true,true,false,true};
    vector<bool> polyn09 ={true,false,false,false,false,true,false,true,false,true,true,true,false,false,false,false,true};
    vector<bool> polyn10 ={true,true,true,false,false,true,false,true,true,false,true,false,true,true,true,false,true};
    vector<bool> polyn11 ={true,false,true,true,false,true,false,false,false,true,false,true,true,true,false,false,true};
    vector<bool> polyn12 ={true,true,false,false,false,true,true,true,false,true,false,true,true,false,false,false,true};

    // Short polynomials
    vector<bool> polys01 ={true,true,false,true,false,true,false,false,false,false,false,false,false,false,true};
    vector<bool> polys02 ={true,false,false,false,false,false,true,false,true,false,false,true,false,false,true};
    vector<bool> polys03 ={true,true,true,false,false,false,true,false,false,true,true,false,false,false,true};
    vector<bool> polys04 ={true,false,false,false,true,false,false,true,true,false,true,false,true,false,true};
    vector<bool> polys05 ={true,false,true,false,true,false,true,false,true,true,false,true,false,true,true};
    vector<bool> polys06 ={true,false,false,true,false,false,false,true,true,true,false,false,false,true,true};
    vector<bool> polys07 ={true,false,true,false,false,true,true,true,false,false,true,true,false,true,true};
    vector<bool> polys08 ={true,false,false,false,false,true,false,false,true,true,true,true,false,false,true};
    vector<bool> polys09 ={true,true,true,true,false,false,false,false,false,true,true,false,false,false,true};
    vector<bool> polys10 ={true,false,false,true,false,false,true,false,false,true,false,true,true,false,true};
    vector<bool> polys11 ={true,false,false,false,true,false,false,false,false,false,false,true,true,false,true};
    vector<bool> polys12 ={true,true,true,true,false,true,true,true,true,false,true,false,false,true,true};
    vector<bool> g;
    if (~type)
    {
        if (modcod == 1 || modcod == 2 || modcod == 3 || modcod == 4 || (modcod == 5 || modcod == 12) || (modcod == 7 || modcod == 14 || modcod == 19 || modcod == 24)|| (modcod == 8 || modcod == 20 || modcod == 25))
            g=gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(polyn01,polyn02),polyn03),polyn04),polyn05),polyn06),polyn07),polyn08),polyn09),polyn10),polyn11),polyn12);
        else if ((modcod == 6 || modcod == 13 || modcod == 18) || (modcod == 9 || modcod == 15 || modcod == 21 || modcod == 26))
            g=gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(polyn01,polyn02),polyn03),polyn04),polyn05),polyn06),polyn07),polyn08),polyn09),polyn10);
        else if ((modcod == 10 || modcod == 16 || modcod == 22 || modcod == 27) || (modcod == 11 || modcod == 17 || modcod == 23 || modcod == 28))
            g=gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(polyn01,polyn02),polyn03),polyn04),polyn05),polyn06),polyn07),polyn08);
    }


    else
       {
            if (modcod == 11 || modcod == 17 || modcod == 23 || modcod == 28)
            g = {true};
            else
            g=gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(gfconv(polys01,polys02),polys03),polys04),polys05),polys06),polys07),polys08),polys09),polys10),polys11),polys12);
    
       }
    //reverse g的数据
    reverse(g.begin(),g.end());
    return g;
}

vector<bool> dvb_bch2(vector<bool>& data, int modcod, bool type) {
    // TODO: Implement BCH encoding
          // Normal polynomials
    vector<bool> g = build_bch_ploy(modcod,type);
    //计算余数
    int n = data.size(), k = g.size() - 1;
    vector<bool> remainder = data;
    for(int i = 0;i<k;i++)
    {
        remainder.push_back(0);
    }

    for (int i = 0; i < n; i++) {
        if (remainder[i]) {
            for (int j = 0; j < k + 1; j++) {
                remainder[i + j] = remainder[i + j] ^ g[j];
            }
        }
    }
    //将余数添加到data后面
    data.insert(data.end(), remainder.begin() + n , remainder.end());

    return data;
}
