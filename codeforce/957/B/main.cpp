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
  int n,m;
  bool fail = false;
  cin >> n >> m;
  vector<vector<char>> grid(n,vector<char>(m,'.'));
  for(size_t i=0;i<n;++i){
    for(size_t j=0;j<m;++j){
      cin>> grid[i][j];
    }
  }
  vector<int> la;la.reserve(n);
  for(size_t j=0;j<m && !fail;++j){
    la.clear();
    for(size_t i=0;i<n;++i){
      if(grid[i][j] == '#'){
        la.push_back(i);
      }
    }
    
    for(size_t k=1;k<la.size();++k){
      if(grid[la[k]] != grid[la[k-1]]){
        fail = true;
        cout << "No" << endl;
        break;
      }
    }
  }
  if(!fail) cout << "Yes" << endl;
}


