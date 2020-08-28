#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

#define kMaxSize 100001
#define kMaxMismatch 1

typedef long long int lli;

int findDna8b(char *p, char *v, int vc);

int main()
{
    // The code below sets files for stdin and stdout, and times the results for testing.
    // If left in it will cause the solution to fail at HackerRank.
    //char test_file_path[] = "";
    //freopen(test_file_path, "r", stdin);
    //char test_file_out[] = "";
    //freopen(test_file_out, "w", stdout);
    
    // Start the clock.
    //static double time_consumed = 0;
    //clock_t start, end;
    //start = clock();
    
    // Allocate memory for strings.
    char *p = (char*)malloc(kMaxSize * sizeof(char));
    char *v = (char*)malloc(kMaxSize * sizeof(char));
    
    // Test cases.
    int tc;
    scanf("%d", &tc);
    while (0 < tc--)
    {
        // Load strings.
        scanf("%s %s", p, v);
        int pc = (int)strlen(p);
        int vc = (int)strlen(v);
        
        // Look for v in p. Print starting index of each match.
        int c = (pc-vc);
        int matched = 0;
        for (int i = 0; i <= c; i++){
            if (findDna8b(&p[i], v, vc) == 1){
                matched++;
                printf("%d ", i);
            }
        }
        
        // We have to indicate if no matches were found.
        if (matched <= 0)
            printf("No Match!\n");
        else
            printf("\n");
    }
    
    // Cleanup
    free(p);
    free(v);
    
    // Comment out or this will fail HackerRank.
    //end = clock();
    //time_consumed += (double)(end - start);
    //printf("%f\n", time_consumed / CLOCKS_PER_SEC);
    
    return 0;
}

int findDna8b(char *p, char *v, int vc)
{
    // Cast strings to lli pointers.
    lli *p8 = (lli*)p;
    lli *v8 = (lli*)v;
    
    int mismatch = 0;
    int c = vc/8;
    int i;
    for (i = 0; i < c; i++)
    {
        if (p8[i] != v8[i])
        {
            int jc = (i*8)+8;
            for (int j = i*8; j < jc; j++)
            {
                if (p[j] != v[j]){
                    mismatch++;
                    if (mismatch > kMaxMismatch)
                        return -1;
                }
            }
        }
    }
    
    for (int j = i*8; j < vc; j++)
    {
        if (p[j] != v[j]){
            mismatch++;
        }
    }
    
    if (mismatch > kMaxMismatch)
        return -1;
    else
        return 1;
}
