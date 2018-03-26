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
//s<<"[ ";
for (auto it : c) s << it << " ";
//s<<"]";
return s;
}

int main(){
  IOS;
  vector<pair<int,int>>s;s.reserve(1005);
  vector<int> ret;ret.reserve(1005);
  int t;
  int n;
  int timer;
  cin >> t;
  while(t--){
    timer = 1;
    cin >> n;
    s.resize(n);
    ret.resize(n);
    fill(ALL(ret),0);
    for(size_t i=0;i<n;++i){
      cin >> s[i].first >> s[i].second;
    }
    for(size_t i=0;i<n;++i){
      while(s[i].first > timer) ++timer;
      if(s[i].second >= timer){
        ret[i] = timer;
        ++timer;
      }
    }
    cout << ret << endl;
  }
}

