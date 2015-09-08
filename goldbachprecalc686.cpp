#include<bits/stdc++.h>
using namespace std;
int n;
int lim = (1 << 15)+1;
vector<int> primes;
bool criba[(1 << 15)+1];
int solve(){
    int sol = 0;
    int i = -1;
    while(primes[++i] <= n/2){
        if(criba[n-primes[i]]) sol++;
    }
    return sol;
}
int main(){

    memset(criba,true,sizeof(criba));
    for(int i = 2; i < lim; i ++){
        if(!criba[i]) continue;
        primes.push_back(i);
        for(int j = i*2; j <= lim; j +=i){
            criba[j] = false;
        }
    }
    cin >> n;
    while(n !=0)
    {
        cout << solve() << endl;
        cin >> n;
    }

}
