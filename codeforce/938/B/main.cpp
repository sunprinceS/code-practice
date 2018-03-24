#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define ALL(x) begin(x),end(x)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
//freopen(name".in", "r", stdin);
//freopen(name".out", "w", stdout);
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
s<<"[ ";
for (auto it : c) s << it << " ";
s<<"]";
return s;
}

int main(){
  int n;
  vector<int> prizes;prizes.reserve(10005);
  while(cin >> n){
      prizes.resize(n);
      for(size_t i=0;i<n;++i){
        cin >> prizes[i];
      }
      int ret = min(prizes[n-1] - 1,int(1e6)-prizes[0]);
      for(int i=0;i<n-1;++i){
        ret = min(ret,max(prizes[i]-1,int(1e6)-prizes[i+1]));
      }
      cout << ret << endl;
  }
}

