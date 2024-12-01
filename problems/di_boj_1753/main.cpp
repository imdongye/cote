/*
    https://www.acmicpc.net/problem/1753


*/
#include <iostream>
#include <queue>
using namespace std;

constexpr int INF = 1e9;

int v, e, k;

// gph[ori] = {weight, dest}
vector<vector<pair<int, int>>> gph;
vector<int> ds;

priority_queue<
    pair<int, int> // d, node  
    , vector<pair<int, int>>
    , greater<pair<int, int>>
    > pq;

int main(int argc, char** argv)
{   
    cin >> v >> e >> k;
    gph.resize(v + 1);
    ds.resize(v + 1, INF);

    for( int i = 0; i < e; i++ ) {
        int a, b, w;
        cin >> a >> b >> w;
        gph[a].push_back({w, b});
    }

    ds[k] = 0;

    pq.push({ 0, k });

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if( ds[cur.second] != cur.first )
            continue;

        for(auto& nxt : gph[cur.second]) {
            int new_dist = ds[cur.second] + nxt.first;
            if( ds[nxt.second] > new_dist ) {
                ds[nxt.second] = new_dist;
                pq.push({new_dist, nxt.second});
            }
        }
    }
    for( int i=1; i<=v; i++ ) {
        if( ds[i] == INF )
            cout << "INF\n";
        else
            cout << ds[i] << "\n";
    }

    return 0;
}