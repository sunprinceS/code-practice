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
      vector<vector<int>> ans;
      vector<int> cur;
      dfs(ans, cur, k, 1, n);
      return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& cur,int k, int lower, int upper){
      if(cur.size() == k){
        ans.push_back(cur);
      }
      else{
        for(int i=lower; i<= upper; ++i){
          cur.push_back(i);
          dfs(ans, cur, k, i+1, upper);
          cur.pop_back();
        }

      }
    }
};

int main(){
  Solution sol;
  cout << sol.combine(4,2) << endl;
}
