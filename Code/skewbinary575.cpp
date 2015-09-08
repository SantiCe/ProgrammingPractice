#include<bits/stdc++.h>
using namespace std;

long long solve(string sk){
    char* c = &sk[0u];
    long long pow = 2;
    long long sum = 0;
    for(int i = 0; i < sk.length(); i++){
        int n = c[sk.length()-1-i]-'0';
        sum += n*(pow-1);
        pow*=2;
    }
    return sum;
}

int main(){
    string s;
    cin >> s;
    while(s.compare("0") != 0){
        cout << solve(s) << endl;
        cin >> s;
    }
}
