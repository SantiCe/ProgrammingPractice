#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,1,1,0,-1,-1};
int dy[] = {1,1,1,0,-1,-1,-1,0};

int m,n,len;

bool marc[26][26];
bool mat[26][26];

bool inBound(int x, int y){
    return (x >= 0 && x < m && y>= 0 && y < n);
}
void dfs(int x, int y){
    if(marc[x][y]) return;
    ++len;
    marc[x][y] = true;
    for(int i = 0; i < 8; i ++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!inBound(nx,ny)) continue;
        if(mat[nx][ny] && !marc[nx][ny]) dfs(nx,ny);
    }
}

int main(){
    string s;
    int T;
    cin >> T;
    getline(cin,s);
    cout << s << " BEFORE " << endl;
    while(--T >= 0){
        memset(mat,false,sizeof(mat));
        getline(cin,s);
        cout << s << endl;
        m = 0;
        n = s.length();
        while(s.length() != 0){
            char *ar = &s[0u];
            cout << " HERE " << endl;
            for(int i = 0; i < n; i ++){
                mat[m][i] = ar[i] == '1';
            }
            ++m;
            getline(cin,s);
        }
        int mlen = 0;
        len = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j ++){
                if(!marc[i][j] && mat[i][j]){
                        dfs(i,j);
                        mlen = max(len,mlen);
                        len = 0;
                }
            }
        }
        cout << mlen << endl;
        if(T != 0) cout << endl;
    }
}
