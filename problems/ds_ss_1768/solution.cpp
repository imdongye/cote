#define N 4

typedef struct {
           int strike;
           int ball;
} Result;
 
// API
extern Result query(int guess[]);


#define MAX_HISTORY 64
static int nr_history;
static int history[MAX_HISTORY][N+2]; // 4: strike, 5: ball
static bool used[10];
static int* num;

int get_unused() {
    for(int j=0; j<10; j++) {
        if(!used[j]) {
            used[j] = true;
            return j;
        }
    }
}

void make_num() {
    for(int i = 0; i<10; i++) {
        used[i] = false;
    }
    for(int i=0; i<N; i++) {
        num[i] = get_unused();
    }

    for(int i=0; i<MAX_HISTORY; i++) {
        int* row = history[i];
        for(int j=0; j<N; j++) {
            if(row[j]==num[j]) {
                get_unused();
            }
        }
    }
}

void solve()
{
    make_num();
    Result rst = query(num);
    if(rst.)
}
 
void doUserImplementation(int guess[]) {
    num = guess;
    nr_history = 0;
    solve();
}
