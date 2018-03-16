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

//Solve it w/o division with constant space complexity (不算 return 的 array 的話)
class Solution{
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> ret(nums.size(),1);
      int fromBegin = nums.front(),fromLast = nums.back();
      for(size_t i=1;i<nums.size();++i){
        ret[i] *= fromBegin;
        fromBegin *= nums[i];
      }
      for(int i=nums.size()-2;i>=0;--i){
        ret[i] *= fromLast;
        fromLast *= nums[i];
      }
      return ret;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {1};
  cout << sol.productExceptSelf(nums) << endl;
}
