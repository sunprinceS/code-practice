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
  IOS;
  vector<int> states;
  int n,U;
  cin >> n >> U;
  states.resize(n);
  for(size_t i=0;i<n;++i){
    cin >> states[i];
  }
  double ret = -1;
  int idx;
  int m;
  for(size_t i=0;i<n-2;++i){
    idx = upper_bound(states.begin()+i,states.end(),states[i] + U) - states.begin() - 1;
    if( i+2 <= idx ){
      m = states[idx] - states[i];
      ret = max(ret,1-((double)(states[i+1] - states[i])/m));
    }
  }
  cout << setprecision(10) << ret << endl;
}

