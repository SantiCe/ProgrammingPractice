#include<bits/stdc++.h>
using namespace std;

bool marc[101][101];
bool mat[101][101];
int m,n;
int dx[] = {-1,0,1,1,1,0,-1,-1};
int dy[] = {1,1,1,0,-1,-1,-1,0};

bool inBound(int x, int y){
    return (x >= 0 && x < m && y>= 0 && y < n);
}
void dfs(int x, int y){
    if(marc[x][y]) return;
    marc[x][y] = true;
    for(int i = 0; i < 8; i ++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!inBound(nx,ny)) continue;
        if(mat[nx][ny] && !marc[nx][ny]) dfs(nx,ny);
    }
}



int main(){
    cin >> m >> n;
    while(m != 0){
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                char c;
                cin >> c;
                if(c == '@'){
                    mat[i][j] = true;
                }
                else mat[i][j] = false;
                marc[i][j] = false;
            }
        }

        int sum = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(mat[i][j]){
                    if(!marc[i][j]){
                        ++sum;
                        dfs(i,j);
                    }
                }
            }
        }
        cout << sum << endl;
        cin >> m >> n;
    }

}
