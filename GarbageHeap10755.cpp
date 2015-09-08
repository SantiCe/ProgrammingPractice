#include<bits/stdc++.h>
using namespace std;

long long cube[21][21][21];
long long cumul[21][21][21];
long long ar[21][21][21];
int n,a,b,c;
long long m;

long long area(int i, int jl, int jr, int kl, int kr){
    return ar[i][jr][kr] - ar[i][jr][kl-1] - ar[i][jl-1][kr] + ar[i][jl-1][kl-1];
}

int main(){
    for(int i = 0; i < 21; i ++)
        for(int j = 0; j < 21; j ++)
            for(int k = 0; k < 21; k ++)
                cube[i][j][k] = ar[i][j][k] = cumul[i][j][k] = 0;

    cin >> n;
    while((--n) >= 0){
         m = -24000000000000LL;
        cin >> a >> b >> c;
        for(int i = 1; i <= a; i ++)
            for(int j = 1; j <= b; j ++)
                for(int k = 1; k <= c; k ++){
            cin >> cube[i][j][k];
            cumul[i][j][k] = cube[i][j][k] + cumul[i][j][k-1];
        }

        for(int i = 1; i <= a; i ++){
            for(int kr = 1; kr <= c; kr++){
                for(int jr = 1; jr <= b; jr++){
                    ar[i][jr][kr] = ar[i][jr-1][kr] + cumul[i][jr][kr];
                }
            }
        }

        for(int jl = 1; jl <= b; jl ++){
            for(int jr = jl; jr <= b; jr ++){
                for(int kl = 1; kl <= c; kl ++){
                    for(int kr = kl; kr <= c; kr++){
                        for(int il = 1; il <= a; il ++){
                            long long temp = area(il,jl,jr,kl,kr);
                            m = max(temp,m);
                            for(int ir = il+1; ir <= a; ir ++){
                                temp = temp+area(ir,jl,jr,kl,kr);
                                m = max(temp,m);
                            }
                        }
                    }
                }
            }
        }

        cout << m << endl;
        if(n != 0) cout << endl;

    }
}




