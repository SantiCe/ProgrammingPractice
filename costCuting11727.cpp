#include<bits/stdc++.h>
using namespace std;
int a,b,c,cas,T;

int main(){
    cin >> T;
    cas = 1;
    while(cas <= T){
        cin >> a >> b >> c;
        cout << "Case "<< cas<<": ";
        if(a <= b && a >= c || a >= b && a <= c) cout << a << endl;
        else if (b <= a && b >= c || b >= a && b <= c) cout << b << endl;
        else cout << c << endl;
        ++cas;
    }


}
