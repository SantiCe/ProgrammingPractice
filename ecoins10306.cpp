#include<bits/stdc++.h>
#define INF 100000
using namespace std;

int sol[301][301];
int l[41]; int r[41];
map<int,int> sqr;
int n,m,S,SS,ans;
vector< pair<int,int> > vec;

int solve(){
    for(int i = 0; i < 301; i ++){
        for(int j = 0; j < 301; j ++){
            sol[i][j] = INF;
        }
    }
    sol[0][0] = 0;
    for(int i = 0; i <= S; i ++){
        for(int j = 0; j <= S; j ++){
            for(int k = 0; k < m; k ++){
                if(l[k] <= i && r[k] <= j){
                    sol[i][j] = min(sol[i][j], sol[i-l[k]][j-r[k]] + 1);
                }
            }
        }
    }
    ans = INF;
    for(int i = 0; i < vec.size(); i ++){
        pair<int,int> p = vec[i];
        ans = min(ans,sol[p.first][p.second]);
    }
    return ans;
}

void fillVector(){
    vec.clear();
    for(int i = 0; i <= S; i ++){
        if(sqr.find(SS-i*i) != sqr.end()){
            pair<int,int> p;
            p.first = i; p.second = sqr[SS-i*i];
            vec.push_back(p);
        }
    }
   // cout << "PRINTING VEC" << endl;
   // for(int i = 0; i < vec.size(); i ++){
       // cout << vec[i].first << " " << vec[i].second << endl;
    //}
   // cout << "DONE" << endl;
}

int main(){
    for(int i = 0; i < 301; i ++){
        sqr[i*i] = i;
    }
    cin >> n;
    while((--n) >= 0){
        cin >> m >> S;
        SS = S*S;
        fillVector();
        for(int i = 0; i < m; i ++){
            cin >> l[i] >> r[i];
        }
        solve();
        if(ans == INF) cout << "not possible" << endl;
        else cout << ans << endl;
    }
}
