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
   private:
    vector<int> time_ref;
    int global_ref;

  public:
   bool DFS(vector<vector<int> >&g,size_t node){
     if(time_ref[node] == global_ref) return false;
     else{
       time_ref[node] = global_ref;
       for(size_t to = 0;to < g.size();++to){
         return DFS(g,to);
       }
       
     }
   }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      time_ref.resize(numCourses); // all 0
      global_ref = 1;

      vector<vector<int> > g(numCourses,vector<int>(numCourses,0));
      //cout << g << endl;
      for(auto e:prerequisites){
        g[e.first][e.second] = 1;
      }

      for(size_t from = 0;from < numCourses;++from){
        for(size_t to = 0;to < numCourses;++to){
          if(g[from][to] == 1){
            if(!DFS(g,to)) return false;
          }
        }
        global_ref++;
      }
      return true;
    }
};

int main(){
  Solution sol;
}
