#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    freopen(INPUT_FILE_PATH, "r", stdin);
    freopen(OUTPUT_FILE_PATH, "w", stdout);
    ios::sync_with_stdio(false); // c++ stream만 사용
    cin.tie(false); // cout과 연동 끊기
    
    int a, b, c;
    cin>>a>>b>>c;
    cout<<a<<b<<c;
    return 0;
}