#include<bits/stdc++.h>
using namespace std;

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

class Solution{
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<int> seq;
      vector<int> status(numCourses+1,0);
      vector<vector<int>> edges(numCourses+1,vector<int>());
      for(auto& p:prerequisites){
        edges[p.second].push_back(p.first);
      }
      for(int i=0;i<numCourses;++i){
        edges[numCourses].push_back(i); //superNode
      }
      if(DFS(numCourses,edges,status,seq)){
        reverse(seq.begin(),seq.end());
        return vector<int>(seq.begin()+1,seq.end());
      }
      else return {};
      
        
    }
    bool DFS(int s,vector<vector<int>>& edges,vector<int>& status,vector<int>& seq){
      if(status[s] == 0){
        status[s] = 1;
        for(int& v:edges[s]){
          bool b = DFS(v,edges,status,seq);
          if(!b) return false;
        }
        status[s] = 2;// seq. will followe the finish time
        seq.push_back(s);
        return true;
      }
      else if(status[s] == 2) return true;
      else return false;
    }
};

int main(){
  Solution sol;
  vector<pair<int,int>> prerequisites({});
  cout << sol.findOrder(3,prerequisites) << endl;
}
