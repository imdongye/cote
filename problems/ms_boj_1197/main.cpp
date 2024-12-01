/*
    https://www.acmicpc.net/problem/1197


*/
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int v, e;

// gph[ori] = {weight, dst}
vector<vector<pair<int, int>>> gph;
vector<bool> chks;

priority_queue<
    tuple<int, int, int> // d, node1, node2 
    , vector<tuple<int, int, int>>
    , greater<tuple<int, int, int>>
    > pq;

int main(int argc, char** argv)
{   
    cin >> v >> e;
    gph.resize(v + 1);
    chks.resize(v + 1, false);

    for( int i = 0; i < e; i++ ) {
        int a, b, w;
        cin >> a >> b >> w;
        gph[a].push_back({w, b});
        gph[b].push_back({w, a});
    }

    chks[1] = true;
    for(auto& nxt : gph[1]) {
        pq.push({ nxt.first, 1, nxt.second });
    }

    int cnt = 0;
    int ans = 0;
    while(cnt < v-1) {
        auto [cost, a, b] = pq.top(); pq.pop();
        if( chks[b] ) 
            continue;
        ans += cost;
        chks[b] = true;
        cnt++;
        for(auto& nxt : gph[b]) {
            if( chks[nxt.second] )
                continue;
            pq.push({ nxt.first, b, nxt.second });
        }
    }

    cout << ans;

    return 0;
}