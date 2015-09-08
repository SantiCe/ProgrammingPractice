#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    int cas = 1;
    while(cin >> n){
        bool fail = false;
        set<int> sums;
        int last = 0;
        sums.insert(0);
        cout << "Case #"<<cas<<":";
        for(int i = 0; i < n; i ++){
            int x;
            cin >> x;
            cout << " " << x;
            if(!fail){
                if(x <= last){
                    fail = true;
                    continue;
                }
                if(sums.find(x) != sums.end()){
                    fail = true;
                    continue;
                }

                set<int> aux = sums;
                set<int>::iterator it= sums.begin();
                for(; it != sums.end(); ++it){
                    aux.insert(*it+x);
                }
                sums = aux;
            }
            last =
        }
        cout << endl;
        cout << "This is ";
        if(fail) cout << "not ";
        cout << "an A-sequence."<<endl;
        ++cas;
    }
}
