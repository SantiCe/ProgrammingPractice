    #include <bits/stdc++.h>
    using namespace std;

    vector<long long> vec;
    long long N,low,high;

    int ceil(int start, int finish, long long x){
        if(x == vec[start]) return start;
        int d = finish-start;
        if(d == 1) return start;
        int mid = start + d/2;
        if(x < vec[mid]) return ceil(start,mid,x);
        return ceil(mid,finish,x);
    }

    int flow(long long x){
        int start = 0;
        int finish = vec.size();
        int d = finish-start;
        while(finish >= start){
            if(x == vec[start]) return start;
            int d = finish-start;
            if(d == 1) return start;
            int mid = start+d/2;
            if(x < vec[mid]) finish = mid;
            else start = mid;
        }
        return vec[start];
    }

    int main(){
        bool criba[1000001];
        memset(criba,true,sizeof(criba));
        criba[2] = true;
        for(long long i = 2; i <= 1000001; i ++){
            if(!criba[i]) continue;

            // es primo
            long long p = i*i;
            while(p <= 1000000000000){
                vec.push_back(p);
                p*=i;
            }

            for(int j = 2*i; j <= 1000001; j+=i){
                criba[j] = false;
            }
        }

        sort(vec.begin(), vec.end());

        int start = 0; int finish = vec.size();

        cin >> N;
        while(--N>=0){
            cin >> low >> high;
            if(high < 4) {
                cout << 0 << endl;
                continue;
            }
            if(low <= 4) low = 4;
            int a = flow(low);
            int ans = flow(high)-a;
            if(vec[a] == low) ans++;
            cout << ans << endl;
        }


    }
