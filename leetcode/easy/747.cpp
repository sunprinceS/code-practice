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
    //int dominantIndex(vector<int>& nums){
      //if(nums.size() <= 1)
        //return 0;

      //int max_idx = 0,max_num = nums[0];
      //bool ok = true;
      //for(size_t i=1;i<nums.size();++i){
        //if(nums[i] < max_num){
          //if(ok)
            //ok = (nums[i]*2 <= max_num);
        //}
        //else{
          //ok = (max_num*2 <= nums[i]);
          //max_idx=  i;
          //max_num = nums[i];
        //}
      //}
      //return (ok)?max_idx:-1;
    //}
    int dominantIndex(vector<int>& nums){
      int ret;
      int max_num = *max_element(nums.begin(),nums.end());
      for(size_t i=0;i<nums.size();++i){
        if(max_num == nums[i]) ret = i;
        else if(max_num < 2*nums[i]){
          return -1;
        }
      }
      return ret;

    }
};

int main(){
  Solution sol;
  vector<int> nums = {2};
  //vector<int> nums = {0,2,3,0};
  cout << sol.dominantIndex(nums) << endl;
}
