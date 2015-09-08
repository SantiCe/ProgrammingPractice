#include<bits/stdc++.h>
using namespace std;

int C[200];
int a[11][21][200];
int t[200];
int N,Q,d,M,s,n,k,i,q,inv;

int tt(int l){
    return ((C[l] % d) + d ) % d;
}
int solve(){

    /* llenar paso 1 */
    for(i = 0; i < N; i ++){
        t[i] = tt(i);
        for(n = 0; n <= M; n ++)
            for(k = 0; k < d; k ++)
                a[n][k][i] = 0;
    }
    a[1][t[0]][0] = 1;
    //for(n = 1; n < N; n ++){
      //  a[1][t[n]][n] = 1;
        //for(k = 0; k < d; k ++){
          //  a[1][k][n] += a[1][k][n-1];
        //}
    //}

    /* Recurrencia */
    for(n = 1; n < N; n ++){
        a[1][t[n]][n] = 1;
        for(i = 1; i <= M; i ++){
            for(k = 0; k < d; k ++){
                inv = (d+k-t[n])%d;
                a[i][k][n] += a[i][k][n-1] + a[i-1][inv][n-1];
                if(i == M && n == N-1) return a[M][0][N-1];
            }
        }
    }
    /* Respuesta */

}


int main(){

    s = 1;
    while((cin >> N >> Q) && N != 0){
        cout << "SET " << s<<":\n";
        for(n = 0; n < N; n ++){
            cin >> C[n];
        }
         for(q = 1; q <= Q; q++){
            cin >> d >> M;
            cout << "QUERY "<<q<<": "<<solve()  <<endl;
         }
    s++;
    }
}
