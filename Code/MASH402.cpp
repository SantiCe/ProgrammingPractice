#include<bits/stdc++.h>
using namespace std;

int deck[20];
int N,X,pas;
vector<int> vec;
int main(){
    pas = 1;
    while(cin >> N >> X){

        for(int i = 0; i < 20; i ++) cin >> deck[i];
        vec.clear();
        for(int i = 1; i <= N; i ++) vec.push_back(i);
        int deckpos = 0;
        while(vec.size() > X && deckpos < 20){
            int linepos = deck[deckpos];

            while(vec.size() > linepos-1 && vec.size() > X){
                vec.erase(vec.begin()+(linepos-1));
                linepos = linepos+deck[deckpos]-1;
            }
            deckpos++;
        }
        cout << "Selection #" << pas<<endl;
        ++pas;
        for(int i = 0; i < vec.size(); i ++){
            cout<<vec[i];
            if(i != vec.size()-1)cout << " ";
        }
        cout << endl;
        cout << endl;
    }

}
