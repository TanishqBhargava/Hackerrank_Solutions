#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int setBits(unsigned long long int n) {
    int count = 0 ;
    while(n) {
        n &= (n-1) ;
        count ++ ;
    }
    return count ;
}

int main() {
    int t ;
    scanf("%d\n",&t) ;
    while(t--) {
        unsigned long long int n ;
        scanf("%llu\n",&n) ;
        if (setBits(n-1) & 1) printf("Louise\n") ;
        else printf("Richard\n") ;
    }
    return 0;
}
