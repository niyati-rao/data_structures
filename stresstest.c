//stresstesting loops for floating point as numbers are stored as approximate
//decimal to binary lag
#include <stdio.h>
#include <stdlib.h>

int main(){
    float i=0.0000000000001;
    float m=0.000000000001; //the max val to be reached
    int count=0;

    for(float sum=0.0;sum<m;sum+=i)
        {
            printf("%d additions done\n",count);
            count++;}
}
