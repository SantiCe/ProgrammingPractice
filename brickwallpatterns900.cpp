#include<bits/stdc++.h>
using namespace std;

long long ans[51];
int n;
int main(){
    ans[1] = 1;
    ans[2] = 2;
    for(int i = 3; i <= 50; i ++){
        ans[i] = ans[i-1]+ans[i-2];
    }
    cin >> n;
    while(n != 0){
            cout << ans[n] << endl; cin >> n;
    }
}
