#include<bits/stdc++.h>
using namespace std;
int N,n;
int sum;
vector<int> ones;
vector<int> zeroes;
bool ab[20][100001];
int ar[20];
bool marc[1 << 20];
bool yes;

bool can(){
    int m = ones.size();
    queue<int> q;
    bool yes = false;
    for(int i = 0; i < 1 << m; i ++) marc[i] = false;
        q.push(0);
        while(q.size() != 0){
            int s = 0;
            int k = q.front();
        //   cout << "got " << k << endl;
            q.pop();
            if(marc[k]) continue;
            marc[k] = true;
            for(int i = 0; i < m; i ++){
                if(k & 1 << i) {
                    s+=ones[i];
                }
            }
            if(s == sum/4) {
            //    cout << "Will try it with " << k << endl;
                yes = true;
                if(yes) break;
            }
            else if(s < sum/4){
                for(int i = 0; i < m; i ++){
                    if(!(k & 1 << i)){
                        if(s+ones[i] <= sum/4){
                            q.push(k | 1 << i);
                            int l = k | 1 << i;
                          //  cout << " was at " << k << " got it " << l << " with " << i << " " << ones[i] << endl;
                        }
                    }
                }
            }
        }
    if(!yes) return false;
    for(int i = 0; i < 1 << m; i ++) marc[i] = false;
    yes = false;
    m = zeroes.size();
    while(!q.empty())q.pop();
    for(int i = 0; i < 1 << m; i ++) marc[i] = false;
        q.push(0);
        while(q.size() != 0){
            int s = 0;
            int k = q.front();
           // cout << "got " << k << endl;
            q.pop();
            if(marc[k]) continue;
            marc[k] = true;
            for(int i = 0; i < m; i ++){
                if(k & 1 << i) {
                    s+=zeroes[i];
                }
            }
            if(s == sum/4) {
            //    cout << "Will try it with " << k << endl;
                yes = true;
                if(yes) break;
            }
            else if(s < sum/4){
                for(int i = 0; i < m; i ++){
                    if(!(k & 1 << i)){
                        if(s+zeroes[i] <= sum/4){
                            q.push(k | 1 << i);
                        }
                    }
                }
            }
        }
        return yes;

}

int main(){
    cin >> N;
    while((--N) >= 0){
        cin >> n;
        memset(marc,false,sizeof(marc));
        sum = 0;
        for(int i = 0; i < n; i ++){
            cin >> ar[i];
            sum+=ar[i];
        }
       // if (N == 0) cout << "Reads properly with n  = " << n << endl;
        if(sum % 4 != 0){
            cout << "no" << endl;
            continue;
        }
        yes = false;
        queue<int> q;
        q.push(0);
        while(q.size() != 0){

            ones.clear();
            zeroes.clear();
            int s = 0;
            int k = q.front();
           // cout << "got " << k << endl;
            q.pop();
            if(marc[k]) continue;
            marc[k] = true;
            for(int i = 0; i < n; i ++){
                if(k & 1 << i) {
                    s+=ar[i];
                    ones.push_back(ar[i]);
                }
                else zeroes.push_back(ar[i]);
            }
            if(s == sum/2) {
              //  cout << "Will try it with " << k << endl;
                yes = can();
                if(yes) break;
            }
            else if(s < sum/2){
                for(int i = 0; i < n; i ++){
                    if(!(k & 1 << i)){
                        if(s+ar[i] <= sum/2){
                            q.push(k | 1 << i);
                        }
                    }
                }
            }
        }
        if(yes) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}

