#include<bits/stdc++.h>
using namespace std;

int s,d,n;
int main(){
    cin >> n;
    while((--n) >= 0){
        cin >> s >> d;
        if(s < d) cout << "impossible" << endl;
        else if((s+d)%2 == 1) cout << "impossible"<<endl;
        else{
            cout << (s+d)/2 << " " << (s-d)/2 << endl;
        }
    }
}
