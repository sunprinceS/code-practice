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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      unordered_map<int,int> counter;
      vector<vector<int>> ans;
      vector<int> cur;
      for (auto num: nums){
        auto got = counter.find(num);
        if(got == counter.end()){
          counter.insert({num,1});
        }
        else{
          got->second += 1;
        }
      }
      dfs(ans, counter, cur, nums.size());
      return ans;
    }

    void dfs(vector<vector<int>>& ans, unordered_map<int,int>& counter, vector<int>& cur, int target){
      if(target == 0){
        ans.push_back(cur);
        return;
      }
      for(auto &p: counter){
        if(p. second > 0){
          p.second -= 1;
          cur.push_back(p.first);
          dfs(ans, counter, cur, target -1);
          cur.pop_back();
          p.second += 1;
        }
      }
    }
};

int main(){
  Solution sol;
  vector<int> nums = {1,2,1,2};
  cout << sol.permuteUnique(nums) << endl;
}
