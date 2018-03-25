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
/* 觀察到 min d_i 等價於 min t_i 
 * (t_i: #different markers on i-th day, equal to m_i + d_i + 1)
 * t_i = max(t_{i-1},m_i+1) (至少要跟m_i個**相異**marker在不同地方，所以加自己需 \geq m_i+1)
 * 注意到一定是有m_i+1個相異的marker (e.g 0 0 0 3 一定表示前三個人是相異，不然第四個不會有3)
 * 這也是<t_i>數列間隔元素值相差至多1考慮到的事 (所以再反向算回來去保證這個性質) 
 * */
int main(){
  vector<int> m; 
  m.reserve(int(1e5)+5);
  int n;
  cin >> n;
  vector<int> tot(n);
  for(size_t i=0;i<n;++i){
    cin >> m[i];
  }
  tot[0] = 1;
  for(size_t i=1;i<n;++i){
    tot[i] = max(tot[i-1],m[i]+1);
  }
  for(int i=n-2;i>=0;--i){
    tot[i] = max(tot[i+1]-1,tot[i]);
  }
  //cout << tot << endl;
  long long ret = 0;
  for(size_t i=0;i<n;++i){
    ret += (tot[i] - m[i] - 1);
  }
  cout << ret << endl;
}

