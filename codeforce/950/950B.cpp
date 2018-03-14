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
  vector<int> s1,s2;
  cin >> n >> m;
  s1.resize(n);s2.resize(m);
  int ret = 0;
  int sum1 = 0,sum2 = 0;
  for(size_t i=0;i<n;++i){
    cin >> s1[i];
  }
  int it1 = 0;
  for(size_t i=0;i<m;++i){
    cin >> s2[i];
    sum2 += s2[i];
    while(sum1 < sum2){ sum1+=s1[it1++];};
    if(sum1 == sum2){
      ret++;
      sum2 = 0;
      sum1 = 0;
    }

  }
  cout << ret << endl;

}

