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
    int majorityElement(vector<int>& nums) {
      int cur_cnt = 1;
      int cur_ele = nums.front();
      for(size_t i=1;i<nums.size();++i){
        if(cur_ele == nums[i]){ 
          ++cur_cnt;
        }
        else{
          --cur_cnt;
          if(cur_cnt == 0){
            cur_cnt = 1;
            cur_ele = nums[i];
          }
        }
      }
      return cur_ele;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {1,2,1,2,1,1,3};
  cout << sol.majorityElement(nums) << endl;
}
