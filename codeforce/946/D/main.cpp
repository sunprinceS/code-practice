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

const int MAXN = 1e3;
vector<vector<int> > work;
vector<int> min_interval;
int DP[MAXN][MAXN];
int n,m,k;

int main(){
  IOS;
  string tmp;
  while(cin >> n >> m >> k){
    work.resize(n);
    for(size_t i=0;i<n;i++){
      cin >> tmp;
      for(size_t j=0;j<m;j++){
        if(tmp[j] == '1') work[i].push_back(j);
      }
    }
    //start 

    for(size_t day=0;day<n;++day){
      min_interval.clear();
      min_interval.resize(k+1);
      //precompute min interval
      for(size_t skip = 0;skip <= k;++skip){
        if(skip >= work[day].size()){
          min_interval[skip] = 0;
        }
        else if(skip == work[day].size()-1){
          min_interval[skip] = 1;
        }
        else{
          min_interval[skip] = MAXN;
          for(size_t i=0;i<=skip;++i){
            min_interval[skip] = min(min_interval[skip],work[day][work[day].size()-1-skip+i] - work[day][i]+1);
          }
        }
      }
      //DP part
      for(size_t skip = 0;skip <=k;++skip){
        DP[day][skip] = 1e9;
        if(day > 0){
          for(size_t i=0;i<=skip;++i){
              DP[day][skip] = min(DP[day][skip],DP[day-1][i] + min_interval[skip-i]);
          }
        }
        else{
          DP[day][skip] = min_interval[skip];
        }
      }
    }
    cout << DP[n-1][k] << endl;
  }
}

