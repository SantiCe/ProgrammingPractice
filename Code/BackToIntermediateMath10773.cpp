#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int c = 1; c <= n; c ++){
        double d,v,u;
        cin >> d >> v >> u;
        if(v >= u || u == 0 || v==0){
            cout << "Case "<<c<<": can't determine"<<endl;
            continue;
        }
        //shortest path
        double angle = asin(v/u);
        double vy = sqrt(u*u-v*v);
        double sptime = d/vy;
        //fastest way

        double fwtime = u;
        fwtime = d/fwtime;
        std::cout.setf( std::ios::fixed, std:: ios::floatfield );
        cout.precision(3);
        cout << "Case "<<c<<": "<<(sptime-fwtime)<<endl;
    }
}
