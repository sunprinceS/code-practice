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
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ret;
      if(nums.size() == 0){
        ret.push_back({});
        return ret;
      }
      else{
        ret.push_back({});
        ret.push_back(vector<int>(1,nums[0]));
        vector<int> ss;
        for(size_t i=1;i<nums.size();++i){
          int la = ret.size();
          for(size_t j=0;j<la;++j){
            ss = ret[j];
            ss.push_back(nums[i]);
            ret.push_back(ss);
          }
        }
      }
      return ret;    
    }
    
};

int main(){
  Solution sol;
  vector<int> nums = {1,2,3};
  cout << sol.subsets(nums) << endl;
}
