#include<bits/stdc++.h>
using namespace std;
long long sol[30001];
int h,q,d,n,p;
/* coins(0) = half ... coins(4) = penny */

int main(){
    //for(int i = 0; i <= 30000; i ++) sol[i] = 0;
    //for(h = 0; h <= 30000; h += 50){
       // for(q = 0; q + h<= 30000; q +=25){
           // for(d = 0; d +q + h <= 30000; d += 10){
              //  cout << "Using "<< h/50<<" halves, "<<q/25<<" quarters, "<<d/10<<" dimes."<<endl;
               // for(n = 0; n + d + q + h <= 30000; n +=5){
               //    / for(p = 0;n+d+q+h+ p <= 30000; p ++){
                       // sol[n+d+q+h+p]++;
                  //  }
               // }
          //  }//
       // }
  //  }
    ofstream myfile("357Precalc.txt");
    for(int i = 0; i <= 30000; i ++){
        myfile << i << endl;
    }
    while(cin >> p){
        if(sol[p] == 1){
            cout << "There is only one way to produce "<< p << " cents change.\n";
        }
        else{
            cout << "There are "<<sol[p] << " ways to produce "<<p<<" cents change.\n";
        }
    }

}
