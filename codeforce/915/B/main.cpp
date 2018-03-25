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
  int n,pos,l,r;
  cin >> n >> pos >> l >> r;
  if(l == 1){
    if(r!=n) cout << abs(r-pos) + 1 << endl;
    else cout << 0 << endl;
  }
  else if(r == n){
    cout << abs(l-pos) + 1 << endl;
  }
  else{
    cout << r-l + min(abs(l-pos),abs(r-pos)) + 2 << endl;
  }
}

