#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long int r,c,value,i;
    scanf("%ld%ld",&r,&c);
    if(r%2!=0)
     {
         r=r-1;
         value=r*5;
         i=1;
         while(i<c){
             value+=2;
             i++;
         }
     }
     else
     {
         r=r-2;
         value=r*5+1;
         i=1;
         while(i<c)
         {
             value+=2;
             i++;
         }
     }
     printf("%ld",value);
    return 0;
}
