#include <iostream>

using namespace std;
int n, m;
bool used[10];
int arr[8];

void btk(int k)
{
    if(k==m) {
        for(int i=0; i<m; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1; i<=n; i++) {
        if(used[i]) continue;
        used[i]=true;
        arr[k]=i;
        btk(k+1);
        used[i]=false;
    }
}

int main(int argc, char** argv)
{
    cin>>n>>m;
    btk(0);
}