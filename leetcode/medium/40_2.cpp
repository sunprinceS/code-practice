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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int> > ans;
      vector<int> cur;
      dfs(ans, candidates, cur, target, 0);
      return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& candidates, vector<int>& cur, int target, int pos){
      if(target == 0){
        ans.push_back(cur);
        return;
      }
      else{
        for(int i=pos; i< candidates.size(); ++i){
          if(candidates[i] > target){ break; }
          else if(i > pos && candidates[i] == candidates[i-1]) {continue;}
          cur.push_back(candidates[i]);
          dfs(ans, candidates, cur, target - candidates[i], i+1);
          cur.pop_back();
        }
      }
    }
};

int main(){
  Solution sol;
  vector<int> c1 = {10, 1, 2,7, 6, 1, 5};
  vector<int> c2= {2,5,2,1,2};

  cout << sol.combinationSum2(c1, 8) << endl;
  cout << sol.combinationSum2(c2, 5) << endl;
}
