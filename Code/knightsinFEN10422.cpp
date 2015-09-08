#include<bits/stdc++.h>
using namespace std;


int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

bool inBound(int x, int y){
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}


struct Board{
    int n;
    int hole;
    int steps;
    bool operator == (const Board o) const{
        return (n == o.n && hole == o.hole);
    }

    bool operator < (const Board o ) const{
        return (n < o.n || (n == o.n && hole < o.hole));
    }
};

set<Board> marc;
deque<Board> bfs;
Board start;
Board goal;

int solve(){
    marc.insert(start);
    bfs.push_back(start);
    while(!bfs.empty()){
        Board actual = bfs.front();
        if(marc.find(actual) != marc.end()) continue;
        if(actual == goal) return actual.steps;
        if(actual.steps >= 11) continue;
        bfs.pop_front();
        marc.insert(actual);

        bool tab[5][5];
        for(int i = 0; i < 5; i ++){
            for(int j = 0; j < 5; j ++){
                int pos = i*5+j;
                if(actual.n && (1 << pos)){
                    tab[i][j] = true;
                }
                else{
                    tab[i][j] = false;
                }
            }
        }
        int hx = actual.hole/5;
        int hy = actual.hole % 5;

        for(int i = 0; i < 8; i ++){
            for(int j = 0; j < 8; j ++){
                int fx = hx-dx[i];
                int fy = hy-dy[i];
                if(!inBound(fx,fy)) continue;
                bool oldVal = tab[fx][fy];
                tab[fx][fy] = true;
                tab[hx][hy] = oldVal;
                int newN = (1 << 25);
                for(int i = 0; i < 5; i ++){
                    for(int j = 0; j < 5; j ++){
                        int pos  = i*5+j;
                        if(tab[i][j]) newN |= (1 << pos);
                    }
                }
                Board b;
                b.n = newN;
                b.steps = actual.steps+1;
                b.hole = fx*5 + fy;
                bfs.push_back(b);
                tab[fx][fy] = oldVal;
                tab[hx][hy] = true;
            }
        }
    }
    return -1;
}
int main(){
    int N;

    int g = (1 << 25);
    for(int i = 0; i < 5; i ++){
        for(int j = i; j < 5; j ++){
            int pos = i*5+j;
            g |= (1 << pos);
        }
    }
    goal.n = g;
    goal.hole = 12;
    cin >> N;
    while(--N >= 0){
        Board start;
        start.n = (1 << 25);
        start.steps = 0;
        int pos = 0;
        string s;
        for(int i = 0; i < 5; i ++){
            getline(cin,s);
            for(int j = 0; j < 5; j ++){
                char c = s[j];
                if(c == ' '){
                    start.hole = pos;
                    start.n |= (1 << pos);
                }
                else if (c == '1'){
                    start.n |= (1 << pos);
                }
                ++pos;
            }
        }
        marc.clear();
        bfs.clear();
        bfs.push_back(start);
        cout << solve() << endl;
    }
}

