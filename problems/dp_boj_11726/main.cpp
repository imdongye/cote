/*
    https://www.acmicpc.net/problem/12852

출력:
    최소 횟수
    경로
*/
#include <iostream>
using namespace std;

int n;
int dp[1000001][2]; // 0 : 횟수, 1 : 경로
int idx, tidx;

int main(int argc, char** argv)
{   

    cin>>n;
    dp[1][0]= 0;
    dp[1][1]= -1;
    for(int i=2; i<=n; i++)
    {    
        idx = i-1;
        dp[i][0] = dp[idx][0];

        if( i%2==0 ) {
            tidx = i/2;
            if( dp[i][0] > dp[tidx][0] ) {
                idx = tidx;
                dp[i][0] = dp[idx][0];
            }
        }
        
        if( i%3==0 ) {
            tidx = i/3;
            if( dp[i][0] > dp[tidx][0] ) {
                idx = tidx;
                dp[i][0] = dp[idx][0];
            }
        }

        dp[i][0] += 1;
        dp[i][1] = idx;
    }
    cout<<dp[n][0]<<"\n";
    while(n>0) {
        cout<<n<<" ";
        n = dp[n][1];
    }
    return 0;
}