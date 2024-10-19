// https://www.acmicpc.net/problem/1926

#include <iostream>
#include <array>
#include <queue>
using namespace std;

int width, height;

int board[502][502]; // 0: empty, 1: unchecked draw, 2: checked draw

int nr_draws = 0;
int max_area = 0;

struct Pos {
    int x, y;
};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void solve()
{
    queue<Pos> Q;
    for(int y=1; y<=height; y++) for(int x=1; x<=width; x++) {
        if(board[y][x] != 1)
            continue;
            
        board[y][x] = 2;
        Q.push({x, y});
        nr_draws++;

        int area = 0;
        while(!Q.empty()) {
            Pos p = Q.front();
            Q.pop();
            area++;
            for(int i=0; i<4; i++) {
                Pos new_p = {p.x + dx[i], p.y + dy[i]};
                if(board[new_p.y][new_p.x] != 1)
                    continue;
                board[new_p.y][new_p.x] = 2;
                Q.push(new_p);
            }
        }

        max_area = max(max_area, area);
    }
}

int main(int argc, char** argv)
{
    // freopen(INPUT_FILE_PATH, "r", stdin);
    // freopen(OUTPUT_FILE_PATH, "w", stdout);
    // ios::sync_with_stdio(false); // c++ stream만 사용
    // cin.tie(false); // cout과 연동 끊기
    

    cin>>height>>width;
    for(int y=1; y<=height; y++) for(int x=1; x<=width; x++) {
        cin>>board[y][x];
    }

    solve();

    cout<<nr_draws<<' '<<max_area;

    return 0;
}