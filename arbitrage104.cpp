#include<bits/stdc++.h>
using namespace std;

double g[21][21][21];
double EPS = 0;
int via[21][21][21];


int n;
int t;

int main(){
    while(cin >> n){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(i == j) g[i][j][1] = 1;
                else{
                    cin >> g[i][j][1];
                }
            }
        }
        bool go = true;
        for(t = 2;t <=n && go; ++t){
            for(int i = 0; i < n && go; i++){
                for(int j = 0; j < n && go; j ++){
                        g[i][j][t] = g[i][j][t-1];
                    for(int k = 0; k < n && go; k ++){
                        if(g[i][j][t]<g[i][k][t-1]*g[k][j][1]){
                            via[i][j][t] = k;
                            g[i][j][t]=g[i][k][t-1]*g[k][j][1];
                        }
                    }
                    if(i == j && g[i][j][t] > 1.01 ){
                        deque<int> way;
                        int fin = i;
                        int si = t;
                        while(si != 0){
                            way.push_front(fin+1);
                            fin = via[i][fin][si];
                            --si;
                        }

                        cout << (i+1) << " ";
                        for(int l = 0; l < t; l ++){
                            cout << way[l];
                            if(l != t-1) cout << " ";
                        }
                        go = false;
                    }
                }
            }
        }
        if(go){
            cout << "no arbitrage sequence exists" << endl;
        }

    }


}
