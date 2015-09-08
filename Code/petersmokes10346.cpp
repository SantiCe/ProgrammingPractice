#include<bits/stdc++.h>
using namespace std;
long long m,k;
long long solve(int n, int c){
     if(n == 0 && c < k) return 0;
     return n + solve((n+c)/k, (n+c)%k);
}

int main(){
    while(cin >> m >> k){
        cout << solve(m,0) << endl;
    }
}
