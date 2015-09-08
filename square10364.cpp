#include<bits/stdc++.h>
using namespace std;
int N,M;
int ar[21];
int goal;
int length(int subset){
    int sum = 0;
    for(int i = 0; i < M; i ++){
        if(subset & (1 << i)) sum += ar[i];
    }
    return sum % goal;
}

void print(int s){
    for(int i = 0; i < M; i ++){
        if(s & (1 << i)) cout << 1;
        else cout << 0;
    }
}
// http://stackoverflow.com/questions/22253426/uva-10364-tell-if-it-is-possible-to-use-sticks-of-varying-lengths-to-make-a-squa
int main(){
    cin >> N;
    while(--N >= 0){
        cin >> M;
        int sum = 0;
        for(int i = 0; i < M; i ++){
            cin >> ar[i];
            sum+=ar[i];
        }
        if(sum % 4 != 0){
            cout << "no" << endl;
            continue;
        }
        goal = sum/4;
        int can[1 << M];
        can[0] = 0;
        for(int s = 0; s < (1 << M); s++){
            if(s != 0) can[s] = -1;
            for(int i = 0; i < M && can[s] == -1; i ++){
                if(s & (1 << i)){
                    int quit = s & ~(1 << i);
                    if((can[quit] != -1) && (((can[quit] % goal) + ar[i]) <= goal))
                        can[s] = can[quit] + ar[i];
                }
            }
            //print(s);
            //cout << " " << can[s] << endl;
        }
        if(can[(1 << M)-1] !=-1) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
