#include<bits/stdc++.h>
using namespace std;
int n,pas,coun;
int ar[25][25];
bool marc[25][25];

int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {-1,-1,-1,0,1,1,1,0};

bool valid(int x, int y){
    int f = x;
    if(!(f >= 0 && f < n )) return false;
    f = y;
    if(!(f >= 0 && f < n )) return false;
    return true;
}

void dfs(int x, int y){
    if(!marc[x][y]){
        marc[x][y] = true;
        for(int i = 0; i < 8; i ++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(valid(nx,ny) && ar[nx][ny] == 1){
                    dfs(nx,ny);
                }
        }
    }
}

int main(){
    pas = 1;
    while(cin >> n){
        coun = 0;
        memset(marc,0,sizeof(marc));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++)
            {
                char c;
                cin >> c;
                ar[i][j] = c-'0';
            }
        }

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(!marc[i][j] && ar[i][j] == 1){
                    dfs(i,j);
                    coun++;
                }
            }
        }

        cout << "Image number " << pas << " contains " << coun << " war eagles."<<endl; pas++;
    }
}


