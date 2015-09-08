#include<bits/stdc++.h>
using namespace std;
#define N 1001
struct P{
    int r,c;
};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int R,C,n,i,j,x,y,newx,newy,pas;
bool made;
P pos;
char maze[N][N];
vector<P> fires;
vector<P> firesTemp;
vector<P> joes;
vector<P> joesTemp;
bool visit[N][N];

void getMove(){
    newx = x +dx[i];
    newy = y +dy[i];
    if(newx < 0 || newx >= R || newy < 0 || newy >= C) newx = -1; newy = -1;
}

int main(){
    cin >> n;
    while((--n)>= 0){
        cin >> R >> C;
        fires.clear();
        joes.clear();

        memset(visit,false,sizeof(visit));
        for(x = 0; x < R; x ++){
            for(y = 0; y < C; y ++){
                cin >> maze[x][y];
                pos.r = x; pos.c= y;
                if(maze[x][y] == '#') visit[x][y] = true;
                if(maze[x][y] == 'F'){

                    fires.push_back(pos);
                }
                else if (maze[x][y] == 'J') joes.push_back(pos);
            }
        }



        made = false;
        for(pas = 1; joes.size() != 0 && made == false; pas++){
            firesTemp.clear();
            joesTemp.clear();
            for(j = 0; j < fires.size(); j ++){
                P p = fires[j];
                x = p.r; y = p.c;
                if(visit[x][y]) continue;
                visit[x][y] = true;
                if(maze[x][y] != '.') continue;
                maze[x][y] = 'F';
                for(i = 0; i < 4; i ++){
                    getMove();
                    if(newx == -1) continue;
                    pos.r = newx; pos.c = newy;
                    if(!visit[newx][newy]) firesTemp.push_back(pos);
                }
            }
            fires = firesTemp;
            for(j = 0; j< joes.size(); j ++){
                pos=joes[j];
                x = pos.r; y = pos.c;
                if(visit[x][y])continue;
                visit[x][y] = true;
                if(maze[x][y] != '.' && maze[x][y] != 'J') continue;
                maze[x][y] = 'J';
                for(i = 0; i < 4; i ++){
                    getMove();
                    if(newy == -1){
                        made = true;
                        i = 4; j = 1020;
                    }
                    else if(!visit[newx][newy] && maze[newx][newy] == '.'){
                            pos.r = newx; pos.c = newy;
                            joesTemp.push_back(pos);
                    }
                }
            }
            cout << " Paso " << pas << endl;
            for(int r = 0; r < R; r++){
                for(int c = 0; c < C; c ++)
                    cout << maze[r][c];
                cout << endl;
            }
            joes = joesTemp;
        }
        if(!made) cout << "IMPOSSIBLE" << endl;
        else cout << pas-1 << endl;
}
}
