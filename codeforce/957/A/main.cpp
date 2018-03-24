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
  string seq;
  bool success = true;
  bool can_done = false;

  cin >> n;
  cin >> seq;

  for(size_t i=0;i<n;++i){
    if(seq[i] == '?'){
      if(i == 0 || i == n-1){
        can_done = true;
      }
      if(i>=1 && seq[i-1] == '?'){ // ??
        can_done = true;
      }
      if(i>=1 && i<=n-2){
        if(seq[i-1] == seq[i+1]){
          can_done = true;
        }
      }
    }
    else{
      if(i>=1 && seq[i-1] == seq[i]){
        success = false;
        break;
      }
    }
  }
  if(n==1) cout << "Yes" << endl;
  else{
    if(success && can_done) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

