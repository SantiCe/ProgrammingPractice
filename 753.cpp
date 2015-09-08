#include<bits/stdc++.h>
using namespace std;

map<string,int> mapa;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI w;
bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching() {
  VI mr = VI(w.size(), -1);
  VI mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

struct P{
    int female,male;
};
int T,m,n,k;

int main(){
    cin >> T;
    while(--T>=0){
        cin >> n;
        int index = 0;
        vector<int> tomas;
        vector<int> cables;
        vector<P> adapters;
        mapa.clear();
        for(int i = 0;i < n; i ++){
            string s;
            cin >> s;
            int toma;
            if(mapa.find(s) == mapa.end()){
                mapa[s] = index;
                toma = index;
                ++index;
            }
            else{
                toma = mapa[s];
            }
            tomas.push_back(toma);

        }

        cin >>m;
        for(int i = 0; i < m; i ++){
            string s;
            cin >> s;
            cin >> s;
            int cable;
            if(mapa.find(s) == mapa.end()){
                mapa[s] = index;
                cable = index;
                ++index;
            }
            else{
                cable = mapa[s];
            }
            cables.push_back(cable);
        }

        cin >> k;
        for(int i = 0; i < k; i ++){
            string s;
            cin >> s;
            int fem;
            if(mapa.find(s) == mapa.end()){
                mapa[s] = index;
                fem = index;
                ++index;
            }
            else{
                fem = mapa[s];
            }
            int men;
            cin >> s;
            if(mapa.find(s) == mapa.end()){
                mapa[s] = index;
                men = index;
                ++index;
            }
            else{
                men = mapa[s];
            }
            P p;
            p.female=fem;
            p.male = men;
            adapters.push_back(p);
        }

        // armar la matriz y hacer floyd
        bool mat[index][index];
        memset(mat,false,sizeof(mat));
        for(int i = 0; i < index; i ++){
            mat[i][i] = true;
        }

        for(int a = 0; a < adapters.size(); a++){
            P p = adapters[a];
            mat[p.female][p.male] = true;
        }

        for(int k = 0; k < index; k ++){
            for(int i = 0; i< index; i ++){
                for(int j = 0; j < index; j ++ ){
                    mat[i][j] |= (mat[i][k] && mat[k][j]);
                }
            }
        }

        //match
        w.clear();
        for(int i = 0; i < cables.size(); i ++){
            vector<int> vec;

            for(int j = 0; j < tomas.size(); j++){
                if(mat[cables[i]][tomas[j]]){
                    vec.push_back(1);
                }
                else{
                    vec.push_back(0);
                }
            }
            w.push_back(vec);
        }

        cout << (m - BipartiteMatching()) << endl;
        if(T != 0) cout << endl;
    }
}
