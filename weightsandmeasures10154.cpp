#include<bits/stdc++.h>
using namespace std;

int inf;


struct Turtle{
    int w,s;

    bool operator <(const Turtle &t) const{
        return ((s-w) < (t.s-t.w) || ((s-w)==(t.s-t.w) && w < t.w));
    }
};

multiset<Turtle> turts;
int n;
int solve(){
    if(n == 0) return 0;

    int mw[2][n+1];
    for(int i = 0; i < 2; i ++){
        for(int h = 0; h <= n; h ++){
            mw[i][h] = inf;
        }
    }

    for(int i = 0; i < 2; i ++){
        mw[i][0] = 0;
    }

    multiset<Turtle>::iterator it = turts.begin();
    /*for(; it != turts.end(); ++it){
        cout << it->w << " " << it->s << " " << (it->s - it->w) << endl;
    }
    it = turts.begin();*/
    if(it->w <= it->s) mw[0][1] = it->w;
    ++it;
    for(int i = 1; i < n; i ++){
        for(int h = 1; h <= i+1; h++){
            mw[i%2][h] = inf;
            mw[i%2][h] = min(mw[i%2][h], mw[(i+1)%2][h]);
            if((it->s - it->w) >= mw[(i+1)%2][h-1]){
                mw[i%2][h] = min(mw[i%2][h], mw[(i+1)%2][h-1] + it->w);
            }
            //cout << "m["<<i<<","<<h<<"] "<<mw[i][h] << endl;
        }
        ++it;
    }
    int ma =0;
    for(int h = 1; h<=n; h ++){
        if(mw[(n-1)%2][h] < inf)ma=h;
    }
    return ma;
}

int main(){
    n = 0;
    int x,y;
    inf = 0;
    while(cin >> x >> y){
        Turtle t;
        t.w = x;
        t.s = y;
        inf+=x;
        turts.insert(t);
        n++;
    }
    ++inf;
    cout << solve() << endl;
}
