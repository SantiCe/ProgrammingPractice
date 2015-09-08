#include<bits/stdc++.h>
using namespace std;

struct P{
    string st;
    double d = 1;

    bool operator == (const P &b) const{
        return st.compare(b.st) == 0;
    }

    bool operator < (const P &b) const{
        return st.compare(b.st) < 0;
    }

};

set<P> m;
int n;
string s;
int coun;

void solve(){
    if(coun == 0){
        if(n != 1){
            cout << endl;
            return;
        }
    }

    set<P> nset;
    set<P>::iterator it = m.begin();
    for(;it != m.end(); ++it){
        P p = *it;
        p.d = p.d/(double)coun;
        p.d*=100;
        cout << p.st << " " << p.d;
    }
}

int main(){
    coun = 0;
    cin >> n;
    while(n > 0){
        if(n == 1){
            while(getline(cin,s)){
                coun++;
                P p;
                p.st = s;
                set<P>::iterator it = m.find(p);
                if(it == m.end()){
                    m.insert(p);
                }
                else{
                    p = *it;
                    m.erase(it);
                    p.d++;
                    m.insert(p);
                }
            }
            solve();
        }
    }
}


