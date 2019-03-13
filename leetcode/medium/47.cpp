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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> cur;
      dfs(ans,cur,nums.size(),nums,0);
      return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& cur, int n,vector<int>& candidates, int pos){
      if(cur.size() == n){
        ans.push_back(cur);
        return;
      }
      else{
        unordered_set<int> used_nums;
        for(int i=pos;i<n;++i){
          if(used_nums.find(candidates[i]) == used_nums.end()){
            used_nums.insert(candidates[i]);
            cur.push_back(candidates[i]);
            swap(candidates[pos],candidates[i]);
            dfs(ans,cur,n,candidates,pos+1);
            swap(candidates[pos],candidates[i]);
            cur.pop_back();
          }
        }
      }
    }
};


int main(){
  Solution sol;
  vector<int> c = {1,2,1,2,3,3};
  cout << (sol.permuteUnique(c)).size() << endl;
}
