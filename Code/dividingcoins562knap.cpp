#include<bits/stdc++.h>
using namespace std;
int n,m,c,i,j,maxj;
bool dyn[2][50001];
int coins[101];

int main(){

    cin >> n;
    while((--n) >= 0){

        cin >> m;
        if (m == 0){
            cout << 0 << endl;
            continue;
        }
        else if(m == 1){
            cin >> c;
            cout << c << endl;
            continue;
        }
        else{
            memset(dyn,false,sizeof(dyn));
            i = 0;
            c  = 0;
            while(i < m){
                cin >> coins[i];
                c+=coins[i];
                ++i;
            }
            dyn[0][0] = true;
            dyn[0][coins[0]] = true;


            for(i = 1; i < m; i ++){
                for(j = 0; j < c/2 + 1; j ++){
                    dyn[i%2][j] = dyn[(i-1)%2][j];
                    if(j >= coins[i]) dyn[i%2][j] |= dyn[(i-1)%2][j-coins[i]];
                    if(dyn[i%2][j] && j > maxj) maxj = j;
                    if(maxj == c/2) {
                        j = c; i = m;
                    }
                }
            }
            cout << abs(c - 2*maxj) << endl;
        }
}
}


