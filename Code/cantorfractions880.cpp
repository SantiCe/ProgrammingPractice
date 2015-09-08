#include<bits/stdc++.h>
using namespace std;

long k,n,res;

int main(){

while(cin >> k){
    if(k == 1) {
        cout << "1/1" << endl;
        continue;
    }
    n = (long)sqrt(2*k);

    if(!(2*k > n*(n-1) && 2*k <= n*(n+1))) n++;
    n++;
    //cout << n<<endl;
    int j = (n*(n-1))/2 + 1 - k;
    cout << j << "/" << (n-j) <<    endl;
}
}
