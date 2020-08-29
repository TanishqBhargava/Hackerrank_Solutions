#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        int N;
        scanf("%d", &N);

        int nums[N];
        int result;

        for(int i = 0; i < N; i++) scanf("%d", &nums[i]);

        if(N % 2 == 0) {
            result = 0;
        } else {
            result = nums[0];
            for(int idx = 2; idx < N; idx += 2) {
                result ^= nums[idx];
            }
        }

        printf("%d", result);
        if(T != 0) puts("");
    }
}
