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
  int t;
  int n,k;
  vector<int> x;x.reserve(201);
  int cur_max;
  cin >> t;
  while(t--){
    while(cin >> n >> k){
      cur_max = 0;
      x.resize(k);
      for(size_t i=0;i<k;++i){
        cin >> x[i];
      }
      if(n == k){
        cout << 1 << endl;
        break;
      }
      for(int i=1;i<=n;++i){
        int ii = lower_bound(ALL(x),i)-x.begin();
        if(ii == 0) cur_max = max(cur_max,x[ii] - i);
        else if(ii==k) cur_max = max(cur_max,i-x[k-1]); 
        else cur_max = max(cur_max,min(i-x[ii-1],x[ii]-i)); 
      }
      cout << cur_max + 1 << endl;
    }

  }
}

