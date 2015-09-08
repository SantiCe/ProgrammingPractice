#include<bits/stdc++.h>
using namespace std;

multiset<int> s;
int N,M;
int main(){
while(cin >> N){
s.clear();
for(int i = 0; i < N; i ++){
int x;
cin >> x;
s.insert(x);
}
cin >> M;
int s1,s2;
for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
int x = *it;
if(x > M-x) break;
if(x < M-x){
if(s.find(M-x) != s.end()){
s1 = x;
s2 = M-x;
}
}
else{
if(s.count(x) > 1) {
s1 = x;
s2 = x;
}
}
}
cout << "Peter should buy books whose prices are "<< s1 << " and "<<s2<<"."<<endl;
cout << endl;
}
}
