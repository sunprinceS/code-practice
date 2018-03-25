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

vector<int> vis;
int cycle_cnt;

void dfs(int n,vector<vector<int>>& edges){
  vis[n] = 1;
  for(size_t i=0;i<edges[n].size();++i){
    if(!vis[edges[n][i]]) dfs(i,edges);
    else if(vis[edges[n][i]] == 1) ++cycle_cnt; // cycle found

    if(cycle_cnt == 2) break;
  }
  vis[n] = 2;
  /*允許到cycle_cnt == 2時才宣告失敗，因為vis若非0，便不會再去拜訪，所以如果有一
   * 個 cycle 存在，拜訪完之後，所有 cycle 上的點都是2(相當於構成這些cycle的點都被拔掉了)。
   * 但該如何偵測該cycle同時又包含了其他cycle呢？
   * 高明的地方在於，我們需要確定在鎖定的這個cycle結束之前，這些迴圈上的點都不會再被拜訪
   * ，像example1的例子，從2做dfs會失敗，3做會成功
   * 因為2同時有兩個cycle的邊拉回自己，而3只有一個
   * 但如果選的點不是那種關鍵點，那便不會成功，但反正只要存在一個點會通即可！
   * */

  /*會成功的條件為 存在一個點，其做dfs，只有**一條回來的邊**可以形成迴路*/
}

int main(){
  vis.reserve(500);
  bool success = false;
  int n,m;
  int from,to;
  cin >>n >> m;
  vis.resize(n);
  vector<vector<int>> edges(n,vector<int>());
  for(size_t i=0;i<m;++i){
    cin >> from >> to;
    edges[from-1].push_back(to-1);
  }
  for(size_t i=0;i<n;++i){
    cycle_cnt = 0;
    fill(ALL(vis),0);
    dfs(i,edges);
    for(size_t j=0;j<n;++j){
      if(!vis[j]) dfs(j,edges); // check whether exists cycle in un-connected part 
      if(cycle_cnt == 2) break;
    }
    if(cycle_cnt < 2){
      success = true;
      break;
    }
  }
  if(success) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}

