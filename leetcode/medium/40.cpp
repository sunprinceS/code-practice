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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      vector<vector<int> > ans;
      vector<int> cur;
      dfs(candidates,ans,cur,target,0);
      return ans;
        
    }
    void dfs(const vector<int>& candidates, vector<vector<int> >& ans, vector<int>& cur, int target, int pos){
      //**Note: 利用 target 等於 0 與否，就不用再 sum over cur 這個//vector<int>**
      if(target == 0){
        ans.push_back(cur);
        return;
      }
      else{
        for(int i=pos;i<candidates.size();++i){
          if(candidates[i] > target) break;
          else if(i>pos && candidates[i] == candidates[i-1]) continue; // **not use same in number in same depth**
          else{
            cur.push_back(candidates[i]);
            dfs(candidates,ans,cur,target - candidates[i], i+1);
            cur.pop_back();
          }
        }
      }
    }
};

int main(){
  Solution sol;
  vector<int> c1 = {10,1,2,7,6,1,5};
  vector<int> c2 = {2,5,2,1,2,};
  cout << sol.combinationSum(c1,8) << endl;
  cout << sol.combinationSum(c2,5) << endl;
}
