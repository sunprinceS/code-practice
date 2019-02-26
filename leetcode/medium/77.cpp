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

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int> > ans;
      vector<int> cur;
      dfs(n,ans,cur,k,1);
      return ans;
    }

private:
    void dfs(int n, vector<vector<int> >& ans, vector<int>& cur, int k, int pos){
      if(cur.size() == k){
        ans.push_back(cur);
        return;
      }
      else{
        for(int i=pos;i<=n;++i){
          cur.push_back(i);
          dfs(n,ans,cur,k,i+1);
          cur.pop_back();
        }
      }
    }
};

int main(){
  Solution sol;
  cout << sol.combine(4,2) << endl;
  cout << sol.combine(4,1) << endl;
  cout << sol.combine(4,0) << endl;
}
