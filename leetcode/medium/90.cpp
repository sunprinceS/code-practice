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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int> > ans;
      vector<int> cur;
      sort(nums.begin(),nums.end());
      dfs(nums, ans, cur, 0);
      return ans;
 
    }
private:
    void dfs(const vector<int>& nums, vector<vector<int> >& ans, vector<int>& cur, int pos){
      ans.push_back(cur);
      for(int i=pos; i< nums.size();++i){
        if (i == pos || nums[i] != nums[i-1]){
          cur.push_back(nums[i]);
          dfs(nums,ans,cur,i+1);
          cur.pop_back();
        }
      }

    }
};

int main(){
  Solution sol;
  vector<int> c = {1,2,2};
  cout << sol.subsetsWithDup(c) << endl;
}
