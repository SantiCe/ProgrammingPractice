#include<bits/stdc++.h>
using namespace std;

long int router[101][3];
int T,n,m;
int x,y;

int main(){
    cin >> T;
    int i = 0;
    while((++i) <= T){
        cout << "Case "<<i<<":";
        if(true) cout << endl;
        cin >> n >> m;
        for(int j = 0; j < n; j ++){
            cin >> router[j][0] >> router[j][1]>>router[j][2];
            router[j][2]*=router[j][2];
        }
        for(int j = 0; j < m; j ++){
            cin >> x >> y;
            bool got = false;
            for(int k = 0; k < n && got == false; k ++){
                if((x-router[k][0])*(x-router[k][0]) + (y - router[k][1])*(y - router[k][1]) <= router[k][2]){
                    got = true;
                }
            }
            if(got) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
