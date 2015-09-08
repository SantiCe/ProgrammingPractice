#include<bits/stdc++.h>
using namespace std;

int ar[10005];
int n,m,ma,i,j;
main(){
    cin >> n;
    while(n!= 0){
        ma = -10000005;
        for(i = 0; i < n; i ++){
            cin >> m;
            ar[i] = m;
            if(i > 0) ar[i]+=ar[i-1];
            //cout << i << " " << ar[i] << endl;
            ma = max(ma,ar[i]);
            for(j = 0; j < i; j ++){
                ma = max(ma,ar[i]-ar[j]);
            }
        }
        if(ma > 0) cout << "The maximum winning streak is " << ma <<"."<<endl;
        else cout << "Losing streak." << endl;
        cin >> n;
    }
}
