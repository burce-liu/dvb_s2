//
// Created by 人即、 on 2023/3/24.
//

#include "data_reflect.h"
vector< complex<double>>  dvb_reflect(vector<bool>data_interweave,int modcod)
{
    int mod = 0;
    double r0, r1, r2, r3, r4;
      double m = 1.0 , ratio1 = 0,ratio2 = 0;
      r1 = m;
    vector< complex<double>> data_reflect;
    //qpsk
    if (modcod>=1 && modcod<=11)
    {
        mod = 2;
        int len = data_interweave.size()/mod;
        //qpsk
        for(int i = 0; i<len; i++)
        {
            //00
            if(data_interweave[i*2]==0&&data_interweave[i*2+1]==0)
            {
                data_reflect.emplace_back( (r1 * cos(M_PI / 4.0)), (r1 * sin(M_PI / 4.0)));
            }
            //01
            else if(data_interweave[i*2]==0&&data_interweave[i*2+1]==1)
            {
                data_reflect.emplace_back( (r1 * cos(7 * M_PI / 4.0)), (r1 * sin(7 * M_PI / 4.0)));
            }
            //10
            else if(data_interweave[i*2]==1&&data_interweave[i*2+1]==0)
            {
                data_reflect.emplace_back( (r1 * cos(3 * M_PI / 4.0)), (r1 * sin(3 * M_PI / 4.0)));
            }
            //11
            else if(data_interweave[i*2]==1&&data_interweave[i*2+1]==1)
            {
                data_reflect.emplace_back( (r1 * cos(5 * M_PI / 4.0)), (r1 * sin(5 * M_PI / 4.0)));
            }
        
  
        }
    }
    //8PSK modulation
    else if(modcod>=12 && modcod<=17)
    {
        mod = 3;
        int len = data_interweave.size()/mod;
        //8PSK
        for(int i =0; i< len;i++)
        {
            //000
            if(data_interweave[i*3]==0&&data_interweave[i*3+1]==0&&data_interweave[i*3+2]==0)
            {
                data_reflect.emplace_back( (r1 * cos(M_PI / 4.0)), (r1 * sin(M_PI / 4.0)));
                
            }
            //001
            else if(data_interweave[i*3]==0&&data_interweave[i*3+1]==0&&data_interweave[i*3+2]==1)
            {
                data_reflect.emplace_back( (r1 * cos(0.0)), (r1 * sin(0.0)));
            }
            //010
            else if(data_interweave[i*3]==0&&data_interweave[i*3+1]==1&&data_interweave[i*3+2]==0)
            {
                data_reflect.emplace_back( (r1 * cos(4 * M_PI / 4.0)), (r1 * sin(4 * M_PI / 4.0)));
            }
            //011
            else if(data_interweave[i*3]==0&&data_interweave[i*3+1]==1&&data_interweave[i*3+2]==1)
            {
                data_reflect.emplace_back( (r1 * cos(5 * M_PI / 4.0)), (r1 * sin(5 * M_PI / 4.0)));
            }
            //100
            else if(data_interweave[i*3]==1&&data_interweave[i*3+1]==0&&data_interweave[i*3+2]==0)
            {
                data_reflect.emplace_back( (r1 * cos(2 * M_PI / 4.0)), (r1 * sin(2 * M_PI / 4.0)));
            }
            //101
            else if(data_interweave[i*3]==1&&data_interweave[i*3+1]==0&&data_interweave[i*3+2]==1)
            {
                data_reflect.emplace_back( (r1 * cos(7 * M_PI / 4.0)), (r1 * sin(7 * M_PI / 4.0)));
            }
            //110
            else if(data_interweave[i*3]==1&&data_interweave[i*3+1]==1&&data_interweave[i*3+2]==0)
            {
                data_reflect.emplace_back( (r1 * cos(3 * M_PI / 4.0)), (r1 * sin(3 * M_PI / 4.0)));
            }
            //111
            else if(data_interweave[i*3]==1&&data_interweave[i*3+1]==1&&data_interweave[i*3+2]==1)
            {
                data_reflect.emplace_back( (r1 * cos(6 * M_PI / 4.0)), (r1 * sin(6 * M_PI / 4.0)));
            }


        }
    }

    //16APSK modulation
    else if (modcod>=18 && modcod<=23) {
        mod = 4;
        int len = data_interweave.size() / mod;
        if (modcod == 18) {
            ratio1 = 3.15;
            r1 = sqrt(4 / (1 + 3 * pow(ratio1, 2))); // 内圆半径
            r2 = ratio1 * r1; // 外圆半径
        } else if (modcod == 19) {
            ratio1 = 2.85;
            r1 = sqrt(4 / (1 + 3 * pow(ratio1, 2))); // 内圆半径
            r2 = ratio1 * r1; // 外圆半径
        } else if (modcod == 20) {
            ratio1 = 2.75;
            r1 = sqrt(4 / (1 + 3 * pow(ratio1, 2))); // 内圆半径
            r2 = ratio1 * r1; // 外圆半径
        } else if (modcod == 21) {
            ratio1 = 2.70;
            r1 = sqrt(4 / (1 + 3 * pow(ratio1, 2))); // 内圆半径
            r2 = ratio1 * r1; // 外圆半径
        } else if (modcod == 22) {
            ratio1 = 2.60;
            r1 = sqrt(4 / (1 + 3 * pow(ratio1, 2))); // 内圆半径
            r2 = ratio1 * r1; // 外圆半径
        } else if (modcod == 23) {
            ratio1 = 2.57;
            r1 = sqrt(4 / (1 + 3 * pow(ratio1, 2))); // 内圆半径
            r2 = ratio1 * r1; // 外圆半径
        }
        //16APSK
        for (int i = 0; i < len; i++) {
            //0000
            if (data_interweave[i * 4] == 0 && data_interweave[i * 4 + 1] == 0 && data_interweave[i * 4 + 2] == 0 &&
                data_interweave[i * 4 + 3] == 0) {
                data_reflect.emplace_back( (r2 * cos(M_PI / 4.0)), (r2 * sin(M_PI / 4.0)));
            }
                //0001
            else if (data_interweave[i * 4] == 0 && data_interweave[i * 4 + 1] == 0 &&
                     data_interweave[i * 4 + 2] == 0 && data_interweave[i * 4 + 3] == 1) {
                data_reflect.emplace_back( (r2 * cos(7 * M_PI / 4.0)), (r2 * sin(7 * M_PI / 4.0)));
            }
                //0010
            else if (data_interweave[i * 4] == 0 && data_interweave[i * 4 + 1] == 0 &&
                     data_interweave[i * 4 + 2] == 1 && data_interweave[i * 4 + 3] == 0) {
                data_reflect.emplace_back( (r2 * cos(3 * M_PI / 4.0)), (r2 * sin(3 * M_PI / 4.0)));
            }
                //0011
            else if (data_interweave[i * 4] == 0 && data_interweave[i * 4 + 1] == 0 &&
                     data_interweave[i * 4 + 2] == 1 && data_interweave[i * 4 + 3] == 1) {
                data_reflect.emplace_back( (r2 * cos(5 * M_PI / 4.0)), (r2 * sin(5 * M_PI / 4.0)));
            }
                //0100
            else if (data_interweave[i * 4] == 0 && data_interweave[i * 4 + 1] == 1 &&
                     data_interweave[i * 4 + 2] == 0 && data_interweave[i * 4 + 3] == 0) {
                data_reflect.emplace_back( (r2 * cos(M_PI / 12.0)), (r2 * sin(M_PI / 12.0)));
            }
                //0101
            else if (data_interweave[i * 4] == 0 && data_interweave[i * 4 + 1] == 1 &&
                     data_interweave[i * 4 + 2] == 0 && data_interweave[i * 4 + 3] == 1) {
                data_reflect.emplace_back( (r2 * cos(-M_PI / 12.0)), (r2 * sin(-M_PI / 12.0)));
            }
                //0110
            else if (data_interweave[i * 4] == 0 && data_interweave[i * 4 + 1] == 1 &&
                     data_interweave[i * 4 + 2] == 1 && data_interweave[i * 4 + 3] == 0) {
                data_reflect.emplace_back( (r2 * cos(11 * M_PI / 12.0)), (r2 * sin(11 * M_PI / 12.0)));
            }
                //0111
            else if (data_interweave[i * 4] == 0 && data_interweave[i * 4 + 1] == 1 &&
                     data_interweave[i * 4 + 2] == 1 && data_interweave[i * 4 + 3] == 1) {
                data_reflect.emplace_back( (r2 * cos(-11 * M_PI / 12.0)), (r2 * sin(-11 * M_PI / 12.0)));
            }
                //1000
            else if (data_interweave[i * 4] == 1 && data_interweave[i * 4 + 1] == 0 &&
                     data_interweave[i * 4 + 2] == 0 && data_interweave[i * 4 + 3] == 0) {
                data_reflect.emplace_back( (r2 * cos(5 * M_PI / 12.0)), (r2 * sin(5 * M_PI / 12.0)));
            }
                //1001
            else if (data_interweave[i * 4] == 1 && data_interweave[i * 4 + 1] == 0 &&
                     data_interweave[i * 4 + 2] == 0 && data_interweave[i * 4 + 3] == 1) {
                data_reflect.emplace_back( (r2 * cos(-5 * M_PI / 12.0)), (r2 * sin(-5 * M_PI / 12.0)));
            }
                //1010
            else if (data_interweave[i * 4] == 1 && data_interweave[i * 4 + 1] == 0 &&
                     data_interweave[i * 4 + 2] == 1 && data_interweave[i * 4 + 3] == 0) {
                data_reflect.emplace_back( (r2 * cos(7 * M_PI / 12.0)), (r2 * sin(7 * M_PI / 12.0)));
            }
                //1011
            else if (data_interweave[i * 4] == 1 && data_interweave[i * 4 + 1] == 0 &&
                     data_interweave[i * 4 + 2] == 1 && data_interweave[i * 4 + 3] == 1) {
                data_reflect.emplace_back( (r2 * cos(-7 * M_PI / 12.0)), (r2 * sin(-7 * M_PI / 12.0)));
            }
                //1100
            else if (data_interweave[i * 4] == 1 && data_interweave[i * 4 + 1] == 1 &&
                     data_interweave[i * 4 + 2] == 0 && data_interweave[i * 4 + 3] == 0) {
                data_reflect.emplace_back( (r1 * cos(M_PI / 4.0)), (r1 * sin(M_PI / 4.0)));
            }
                //1101
            else if (data_interweave[i * 4] == 1 && data_interweave[i * 4 + 1] == 1 &&
                     data_interweave[i * 4 + 2] == 0 && data_interweave[i * 4 + 3] == 1) {
                data_reflect.emplace_back( (r1 * cos(-M_PI / 4.0)), (r1 * sin(-M_PI / 4.0)));
            }
                //1110
            else if (data_interweave[i * 4] == 1 && data_interweave[i * 4 + 1] == 1 &&
                     data_interweave[i * 4 + 2] == 1 && data_interweave[i * 4 + 3] == 0) {
                data_reflect.emplace_back( (r1 * cos(3 * M_PI / 4.0)), (r1 * sin(3 * M_PI / 4.0)));
            }
                //1111
            else if (data_interweave[i * 4] == 1 && data_interweave[i * 4 + 1] == 1 &&
                     data_interweave[i * 4 + 2] == 1 && data_interweave[i * 4 + 3] == 1) {
                data_reflect.emplace_back( (r1 * cos(-3 * M_PI / 4.0)), (r1 * sin(-3 * M_PI / 4.0)));
            }
        }
    }
        //32APSK
    else if(modcod>=24 && modcod<=28)
        {
            mod = 5;
            int len = data_interweave.size()/mod;

            
            if (modcod == 24) {
                ratio1 = 2.84;
                ratio2 = 5.27;
            } else if (modcod == 25) {
                ratio1 = 2.72;
                ratio2 = 4.87;
            } else if (modcod == 26) {
                ratio1 = 2.64;
                ratio2 = 4.64;
            } else if (modcod == 27) {
                ratio1 = 2.54;
                ratio2 = 4.33;
            } else if (modcod == 28) {
                ratio1 = 2.53;
                ratio2 = 4.30;
            }
            r1 = sqrt(8.0 / (1 + 3 * pow(ratio1, 2) + 4 * pow(ratio2, 2)));
            r2 = ratio1 * r1;
            r3 = ratio2 * r1;
            for(int i = 0;i<len;i++)
            {
                //00000
                 if(data_interweave[i*5]==0&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r2 * cos(M_PI / 4.0)), (r2 * sin(M_PI / 4.0)));
                }
                //00001
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r2 * cos(5* M_PI / 12)), (r2 * sin(5* M_PI / 12)));
                }
                //00010
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r2 * cos(-M_PI / 4.0)), (r2 * sin(-M_PI / 4.0)));
                }
                //00011
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r2 * cos(-5 * M_PI / 12.0)), (r2 * sin(-5 * M_PI / 12.0)));
                }
                //00100
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r2 * cos(3 * M_PI / 4.0)), (r2 * sin(3 * M_PI / 4.0)));
                }

                //00101
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r2 * cos(7 * M_PI / 12.0)), (r2 * sin(7 * M_PI / 12.0)));
                }
                //00110
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r2 * cos(-3 * M_PI / 4.0)), (r2 * sin(-3 * M_PI / 4.0)));
                }
                //00111
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r2 * cos(-7 * M_PI / 12.0)), (r2 * sin(-7 * M_PI / 12.0)));
                }
                //01000
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r3 * cos(M_PI / 8.0)), (r3 * sin(M_PI / 8.0)));
                }
                //01001
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r3 * cos(3 * M_PI / 8.0)), (r3 * sin(3 * M_PI / 8.0)));
                }
                //01010
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r3 * cos(-M_PI / 4.0)), (r3 * sin(-M_PI / 4.0)));
                }
                //01011
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r3 * cos(-M_PI / 2.0)), (r3 * sin(-M_PI / 2.0)));
                }
                //01100
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r3 * cos(3 * M_PI / 4.0)), (r3 * sin(3 * M_PI / 4.0)));
                }
                //01101
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r3 * cos(M_PI / 2.0)), (r3 * sin(M_PI / 2.0)));
                }
                //01110
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r3 * cos(-7 * M_PI / 8.0)), (r3 * sin(-7 * M_PI / 8.0)));
                }
                //01111
                else if(data_interweave[i*5]==0&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r3 * cos(-5 * M_PI / 8.0)), (r3 * sin(-5 * M_PI / 8.0)));
                }
                //10000
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r2 * cos(M_PI / 12.0)), (r2 * sin(M_PI / 12.0)));
                }
                //10001
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r1 * cos(M_PI / 4.0)), (r1 * sin(M_PI / 4.0)));
                }
                //10010
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r2 * cos(-M_PI / 12.0)), (r2 * sin(-M_PI / 12.0)));
                }
                //10011
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r1 * cos(-M_PI / 4.0)), (r1 * sin(-M_PI / 4.0)));
                }
                //10100
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r2 * cos(11 * M_PI / 12.0)), (r2 * sin(11 * M_PI / 12.0)));
                }
                //10101
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r1 * cos(3 * M_PI / 4.0)), (r1 * sin(3 * M_PI / 4.0)));
                }
                //10110
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r2 * cos(-11 * M_PI / 12.0)), (r2 * sin(-11 * M_PI / 12.0)));
                }
                //10111
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==0&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r1 * cos(-3 * M_PI / 4.0)), (r1 * sin(-3 * M_PI / 4.0)));
                }
                //11000
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r3 * cos(0.0)), (r3 * sin(0.0)));
                }
                //11001
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r3 * cos(M_PI / 4.0)), (r3 * sin(M_PI / 4.0)));
                }
                //11010
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r3 * cos(-M_PI / 8.0)), (r3 * sin(-M_PI / 8.0)));
                }
                //11011
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==0&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r3 * cos(-3 * M_PI / 8.0)), (r3 * sin(-3 * M_PI / 8.0)));
                }
                //11100
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r3 * cos(7 * M_PI / 8.0)), (r3 * sin(7 * M_PI / 8.0)));
                }
                //11101
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==0&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r3 * cos(5 * M_PI / 8.0)), (r3 * sin(5 * M_PI / 8.0)));
                }
                //11110
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==0)
                {
                    data_reflect.emplace_back( (r3 * cos(M_PI)), (r3 * sin(M_PI)));
                }
                //11111
                else if(data_interweave[i*5]==1&&data_interweave[i*5+1]==1&&data_interweave[i*5+2]==1&&data_interweave[i*5+3]==1&&data_interweave[i*5+4]==1)
                {
                    data_reflect.emplace_back( (r3 * cos(-3 * M_PI / 4.0)), (r3 * sin(-3 * M_PI / 4.0)));
                }

                
            }
                

            

        }

    
    return data_reflect;
}