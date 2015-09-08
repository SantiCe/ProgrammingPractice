#include<bits/stdc++.h>
using namespace std;

int a,b,sum,n;


int main(){
    cin >> n;
    int i = 0;
    while((++i) <= n){
        cin >> a >> b;
        sum = 0;
        for(int j = a; j <= b; j ++){
            if(j%2 == 1) sum+=j;
        }
        cout << "Case "<<i<<": "<<sum<<endl;
    }
}
