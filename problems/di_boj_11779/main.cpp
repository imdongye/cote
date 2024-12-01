/*
    https://www.acmicpc.net/problem/11779


*/
#include <iostream>
#include <queue>
using namespace std;

constexpr int INF = 1e9;

int v, e;
int ori, dst;

// gph[ori] = {weight, dst}
vector<vector<pair<int, int>>> gph;
vector<int> ds;
vector<int> path;

priority_queue<
    pair<int, int> // d, node  
    , vector<pair<int, int>>
    , greater<pair<int, int>>
    > pq;

int main(int argc, char** argv)
{   
    cin >> v >> e;
    gph.resize(v + 1);
    ds.resize(v + 1, INF);
    path.resize(v + 1);

    for( int i = 0; i < e; i++ ) {
        int a, b, w;
        cin >> a >> b >> w;
        gph[a].push_back({w, b});
    }
    cin >> ori >> dst;

    ds[ori] = 0;
    path[ori] = -1;

    pq.push({ 0, ori });

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if( ds[cur.second] != cur.first )
            continue;

        for(auto& nxt : gph[cur.second]) {
            int new_dist = ds[cur.second] + nxt.first;
            if( ds[nxt.second] > new_dist ) {
                ds[nxt.second] = new_dist;
                path[nxt.second] = cur.second;
                pq.push({new_dist, nxt.second});
            }
        }
    }
    cout<<ds[dst]<<"\n";

    vector<int> ans;
    int cur = dst;
    while(cur != -1) {
        ans.push_back(cur);
        cur = path[cur];
    }
    
    int nr_ans = ans.size();
    cout<<nr_ans<<"\n";

    for(int i=nr_ans-1; i>=0; i--) {
        cout<<ans[i]<<" ";
    }

    return 0;
}