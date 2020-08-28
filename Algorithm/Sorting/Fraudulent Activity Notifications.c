#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int GetMedian(int f[], int d);

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int s[n];
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    
    int frequency[201];
    for(i = 0; i < 201; i++) {
        frequency[i] = 0;
    }
    
    for(i = 0; i < d; i++) {
        frequency[s[i]]++;
    }
    
    int m[n];
    m[d] = GetMedian(frequency, d);
    
    for(i = d + 1; i < n; i++) {
        frequency[s[i-1]]++;
        frequency[s[i-d-1]]--;
        m[i] = GetMedian(frequency, d);
    }
    int not = 0;
    for(i = d; i < n; i++) {
        if(s[i] >= m[i]){
            not++;
        }
    }
    printf("%d", not);
    return 0;
}

int GetMedian(int f[], int d) {
    int Median;
    if(d % 2 == 0) {
        int mid = d/2;
        int cF = 0;
        for(int i = 0; i < 201; i ++) {
            cF += f[i];
            if(cF > mid) {
                Median = 2*i;
                break;
            }
            else if(cF == mid) {
                for(int j = i + 1; j < 201; j++) {
                    if(f[j] != 0) {
                        //printf("\n%d %d\n", i, j);
                        Median = i + j;
                        break;
                    }
                }
                break;
            }
        }
    }
    else {
        int mid = d/2 + 1;
        int cF = 0;
        for(int i = 0; i < 201; i++) {
            cF += f[i];
            if(cF >= mid) {
                Median = 2*i;
                break;
            }
        }
    }
    //printf("%d", Median);
    return Median;
}
