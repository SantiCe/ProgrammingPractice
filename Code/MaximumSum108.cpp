#include<bits/stdc++.h>
using namespace std;
int N,m;
int ar[101][101];
int sum[101][101];

int area(int i, int jl, int jr){
    if(jl == 0) return sum[i][jr];
    else return sum[i][jr]-sum[i][jl-1];
}
int main(){
m = -100000000;
cin >> N;
for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j ++){
            cin >> ar[i][j];
            sum[i][j] = ar[i][j];
            if(j != 0) sum[i][j]+= sum[i][j-1];
        }
}


for(int jl = 0; jl < N; jl ++){
    for(int jr = jl; jr < N; jr ++){
        for(int il = 0; il < N; il ++){
            int temp = area(il,jl,jr);
            m = max(m,temp);
            for(int ir = il+1; ir < N; ir++){
                temp = temp+area(ir,jl,jr);
                m = max(m,temp);
            }
        }
    }
}

cout << m << endl;
}
