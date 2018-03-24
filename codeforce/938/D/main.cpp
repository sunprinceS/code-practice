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

vector<vector<pair<int,long long>>> out_edges(int(2e5)+5);
vector<long long> dist(int(2e5)+5);
priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>> pq;

int main(){
  IOS;
  
  int n,m;
  int u,v;
  long long c;
  long long a;
  while(cin>> n >> m){
    for(size_t i=0;i<m;++i){
      cin >> u >> v >> c;
      out_edges[u-1].push_back({v-1,2*c});
      out_edges[v-1].push_back({u-1,2*c});
    }
    for(size_t i=0;i<n;++i){
      cin >> a;
      pq.push({a,i});
    }
    int cnt = 0;
    while(!pq.empty() && cnt < n){
      long long cost = pq.top().first;
      int cur_node = pq.top().second;
      pq.pop();
      if(dist[cur_node] == 0){
        dist[cur_node] = cost;
        ++cnt;
      }
      // since the popped cost in ascending, no need to push the setted node
      // again
      for(auto next:out_edges[cur_node]){
        if(dist[next.first] == 0){
          pq.push({cost+next.second,next.first});
        }
      }
    }
    for(size_t i=0;i<n;++i){
      cout << dist[i] << " ";
    }


  }
}

