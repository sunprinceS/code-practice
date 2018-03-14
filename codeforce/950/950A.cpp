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
  int l,r,a;
  while(cin >> l >> r >> a){
    if(r<l) swap(r,l);

    if(r>l+a){
      cout << (l+a)*2 << endl;
    }
    else{
      cout << (r + (a-r+l)/2)*2 << endl;
    }
  }
}

