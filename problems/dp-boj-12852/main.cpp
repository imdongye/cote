/*
    https://www.acmicpc.net/problem/2579


*/
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int steps[301];
int dp[301];
int sum = 0;

int main(int argc, char** argv)
{   
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &steps[i]);
        sum += steps[i];
    }

    dp[1] = steps[1];
    dp[2] = steps[2];
    dp[3] = steps[3];

    for(int i=4; i<n; i++) {
        dp[i] = min(dp[i-3], dp[i-2]);
        dp[i] += steps[i];
    }

    int subn = min(dp[n-2], dp[n-1]);

    printf("%d\n", sum - subn);
    return 0;
}