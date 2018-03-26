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
  int n;
  vector<int> a;a.reserve(int(2e5) + 5);
  cin >> n;
  string s;
  bool fail = false;
  int cur_max = 0;
  for(size_t i=1;i<=n;++i){
    cin >> a[i];
  }
  cin >> s;
  for(size_t i=1;i<n;++i){
    cur_max = max(cur_max,a[i]);
    if(s[i-1] == '0' && cur_max > i){
      fail = true;
      break;
    }
  }
  if(fail) cout << "No" << endl;
  else cout << "Yes" << endl;

}

