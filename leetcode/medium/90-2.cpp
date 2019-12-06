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
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> ans;
      vector<int> cur;
      dfs(ans, cur, k, n, 1, 9);
      return ans;
        
    }
    void dfs(vector<vector<int>>& ans, vector<int>& cur, int k, int target, int lower, int upper){
      if(k == 0){
        if(target == 0){
          ans.push_back(cur);
        }
        return;
      }
      else{
        int max_sum = ((2 * upper - k + 1) * k ) / 2;
        if(max_sum < target) return;
        else{
          for(int i=lower; i<= upper; ++i){
            cur.push_back(i);
            dfs(ans, cur, k-1, target - i, i+1, upper);
            cur.pop_back();
          }
        }
      }
    }
};

int main(){
  Solution sol;
  cout << sol.combinationSum3(3,7) << endl;
  cout << sol.combinationSum3(3,9) << endl;
}
