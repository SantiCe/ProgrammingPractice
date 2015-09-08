    #include<bits/stdc++.h>
    using namespace std;
    /**
    WA
    **/
    int N,m,act,r,lm;
    int ar[101][101];
    int sum[101][101];
    int arr[101];

    int kadane(){
        r = 0;
        for(int i = 0; i < N; i ++){
            act+=arr[i];
            if(act > r) r = act;
            if(act < r) act = 0;
        }
        return r;
    }
    int solve(){
        for(int i1 = 0; i1 < N; i1++){
            for(int i2 = i1; i2 < N; i2++){
                for(int j = 0; j < N; j ++){
                    arr[j] = sum[i2][j];
                    if(i1 > 0) arr[j]-=sum[i1-1][j];
                }
                 m = max(m, kadane());
            }
        }
        return m;
    }
    int main(){
    m = 0;
    lm = -1270001;
    cin >> N;
    for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j ++){
                cin >> ar[i][j];
                sum[i][j] = ar[i][j];
                if(i != 0) sum[i][j]+= sum[i-1][j];
                lm = max(lm,ar[i][j]);
            }
    }

    if(lm <= 0) m = lm;
    else solve();

    cout << m << endl;
}
