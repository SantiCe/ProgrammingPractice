#include<bits/stdc++.h>
using namespace std;

set<int> red;
set<int> blue;
int p,n;

int main(){
    cin >> p;
    while(--p>=0){
        red.clear();
        blue.clear();
        cin >> n;
        for(int i = 0; i < n; i ++){
            int x;
            cin >> x;
            if(x < 0){
                red.insert(-x);
            }
            else{
                blue.insert(x);
            }
        }

        if(red.size() == 0){
            if(blue.size() == 0) cout << 0 << endl;
            else cout << 1 << endl;
            continue;
        }
        else if (blue.size() == 0){
            cout << 1 << endl;
            continue;
        }

        int mr = *(--red.end());
        int mb = *(--blue.end());

        // 1 is blue, 0 is red
        int col = 1;
        int last = mb;
        if(mr > mb){
          col = 0;
          last = mr;
        }
        int sum = 1;
        while(true){
            set<int>::iterator it;
            if(col == 1){
                if(last < *red.begin()){
                    break;
                }
                it = red.upper_bound(last);
                --it;
                ++sum;
                last = *it;
                col = 0;
            }
            else if(col == 0){
                if(last < *blue.begin()){
                    break;
                }
                it = blue.upper_bound(last);
                --it;
                ++sum;
                last = *it;
                col = 1;
            }
        }
        cout << sum << endl;
    }
}
