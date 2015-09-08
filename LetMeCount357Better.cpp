#include<bits/stdc++.h>
using namespace std;
long long sol[5][30001];
int coins[] = {1,5,10,25,50};
int p;

int main(){
    for(int i = 0; i<30001; i ++){
        sol[0][i] = 1LL;
    }
    for(int n = 0; n < 30001;n ++){

        for(int i = 1; i < 5; i ++){
            sol[i][n] = 0;
            int val = coins[i];
            for(int j = 0; j <= n; j+=val){
                sol[i][n] +=sol[i-1][n-j];
            }
        }
    }
    ofstream myfile("myletmeout.txt");
    while(cin >> p){
        if(sol[4][p] == 1){
            cout << "There is only 1 way to produce "<< p << " cents change.\n";
        }
        else{
            cout << "There are "<<sol[4][p] << " ways to produce "<<p<<" cents change.\n";
        }
    }
}
