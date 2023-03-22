#include "getKbch.h"
// create a function to get the value of Kbch according to the value of acm_code_num
int getKbch(int modcod,bool type1 )
{
    int Kbch = 0;
     if (~type1)
     {
         if (modcod == 1)
             
            Kbch=16008;//信息位长

         if (modcod == 2)
             
            Kbch=21408;//信息位长
    
         if (modcod == 3)
             
            Kbch=25728;//信息位长
    
         if (modcod == 4)
             
            Kbch=32208;//信息位长
    
         if (modcod == 5 || modcod == 12)
             
            Kbch=38688;//信息位长
    
         if (modcod == 6 || modcod == 13 || modcod == 18)
             
            Kbch=43040;//信息位长
    
         if (modcod == 7 || modcod == 14 || modcod == 19 || modcod == 24)
             
            Kbch=48408;//信息位长
    
         if (modcod == 8 || modcod == 20 || modcod == 25)
             
            Kbch=51648;//信息位长
    
         if (modcod == 9 || modcod == 15 || modcod == 21 || modcod == 26) 
             
            Kbch=53840;//信息位长
    
         if (modcod == 10 || modcod == 16 || modcod == 22 || modcod == 27)
             
            Kbch=57472;//信息位长
    
         if (modcod == 11 || modcod == 17 || modcod == 23 || modcod == 28)
             
            Kbch=58192;//信息位长
     }
       
    else
    {
    if (modcod == 1)
                
                Kbch=3240;//信息位长
        
             if (modcod == 2)
                
                Kbch=5400;//信息位长
        
             if (modcod == 4)
                
                Kbch=7200;//信息位长
        
             if (modcod == 5 || modcod == 12)
                
                Kbch=9720;//信息位长
        
             if (modcod == 6 || modcod == 13 || modcod == 18)
                
                Kbch=10800;//信息位长
        
             if (modcod == 7 || modcod == 14 || modcod == 19 || modcod == 24)
                
                Kbch=11880;//信息位长
        
             if (modcod == 8 || modcod == 20 || modcod == 25)
                
                Kbch=12600;//信息位长
            
             if (modcod == 9 || modcod == 15 || modcod == 21 || modcod == 26) 
                
                Kbch=13320;//信息位长
        
             if (modcod == 10 || modcod == 16 || modcod == 22 || modcod == 27)
                
                Kbch=14400;//信息位长
        
             else
                Kbch = 0;
                
    }
        
return Kbch;

}
    