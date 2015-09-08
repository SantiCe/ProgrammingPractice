#include<bits/stdc++.h>
using namespace std;

int bear;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int posx,posy;
int H,W;
bool mat[51][51];

bool inBound(int x, int y){
        return (x >= 0 && x <= W && y >= 0 && y <= H);
}

void resBear(char c){
    if(c == 'E') bear = 1;
    else if (c == 'N') bear = 0;
    else if (c == 'S') bear = 2;
    else bear = 3;
}

char coord(){
    if(bear == 0) return 'N';
    else if (bear == 1) return 'E';
    else if (bear == 2) return 'S';
    else return 'W';
}
void solve(string s){
    char *ar = &s[0u];
    for(int i = 0; i < s.length(); i ++){
        char c = ar[i];
        if(c == 'R') bear = (bear + 1)%4;
        else if (c == 'L') bear = (bear + 3)%4;
        else{
            int nx = posx + dx[bear];
            int ny = posy + dy[bear];
            if(inBound(nx,ny)){
                posx = nx;
                posy = ny;
            }
            else{
                if(!mat[posx][posy]){
                    cout << posx << " " << posy << " " << coord() << " LOST" << endl;
                    mat[posx][posy] = true;
                    return;
                }
            }
        }
    }
    cout << posx << " " << posy << " " << coord() << endl;
}

int main(){
    cin >> W >> H;
    char c;
    while(cin >> posx >> posy >> c){
        resBear(c);
        string s;
        cin >> s;
        solve(s);
    }
}

