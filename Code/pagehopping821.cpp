#include<bits/stdc++.h>
using namespace std;

int M = 100000;
int g[101][101];
int n;
map<int,int> m;
int cas = 1;
int main(){
    #if defined(NOSYNC)
    std::cout.sync_with_stdio(false);
    #endif
    int x,y;
    cin >> x >> y;
    while(x != 0){
        n = 0;
        m.clear();
        for(int i = 0; i < 101; i ++)
        for(int j = 0; j < 101; j ++){
            g[i][j] = M;
            if(i == j) g[i][j] = 0;
        }
        while(x != 0){

            if(m.find(x) == m.end()){
                m[x] = n;
                ++n;
            }
            if(m.find(y) == m.end()){
                m[y] = n;
                ++n;
            }
            g[m[x]][m[y]] = 1;
            cin >> x >> y;
        }


        for(int k = 0; k < n; k ++){
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < n; j ++){
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }

        int paths = 0;
        double sum = 0;

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(i != j){
                    paths++;
                    sum+=g[i][j];
                }
            }
        }

        sum = sum/paths;

        cout << "Case "<<cas<<": average length between pages = ";
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        std::cout << sum << " clicks" << endl;
        cin >> x >> y;
        ++cas;
    }
}
