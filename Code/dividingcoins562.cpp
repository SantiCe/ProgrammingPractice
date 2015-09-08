#include<bits/stdc++.h>
using namespace std;



struct P{
    int a,b;
      bool operator<( const P& val ) const {
            return a < val.a;
        }
        bool operator==( const P& val ) const {
            return a == val.a;
        }
};

set<P> coins;
int n,m,c;
set<P>::iterator it;

int main(){
    cin >> n;
    while((--n) >= 0){
        cin >> m;
        if (m == 0){
            cout << 0 << endl;
            continue;
        }
        else if(m == 1){
            cin >> c;
            cout << c << endl;
            continue;
        }
        coins.clear();
        int sum = 0;
        while((--m)>=0){
            cin >> c;
            sum+=c;
            P p = {c,m};
            coins.insert(p);
            it = coins.begin();
            for(;it != coins.end(); ++it){
                if(it->b != m){
                    p = {it->a + c,m};
                    coins.insert(p);
                }
            }
        }
        P p = {sum/2,0};
        it = coins.lower_bound(p);
        cout << abs(2*it->a - sum) << endl;
        //cout << it-> a << " " << it->b << " " << sum << endl;
    }
}
