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
    vector<int> majorityElement(vector<int>& nums) {
      if(nums.empty()) return {};
      // b 用成一個 impossible 的值，是為了避免nums[0],nums[1] 是否相同的雜子(?)判斷
      int a = nums.front(),b = INT_MAX,cnt_a = 1,cnt_b = 0;
      // 重點在 else if 會跳過某些減 counter 的步驟，如此可以確保 a 和 b 會存不一樣的 element
      for(size_t i=1;i<nums.size();++i){
        if( nums[i] == a ) {++cnt_a;}
        else if( nums[i] == b ) {++cnt_b;}
        else if( cnt_a == 0) {cnt_a = 1; a = nums[i];}
        else if( cnt_b == 0) {cnt_b = 1; b = nums[i];}
        else {--cnt_a;--cnt_b;}
      }
      // a,b 為 2-top frequent elements，但不保證滿足 > \floor{n/3} 的條件
      vector<int> ret;
      cnt_a = 0;cnt_b = 0;
      for(auto n:nums){
        if(n == a) ++cnt_a;
        else if(n == b) ++cnt_b;
      }
      if(cnt_a > nums.size()/3) ret.push_back(a);
      if(cnt_b > nums.size()/3) ret.push_back(b);

      return ret;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {2,3,4,2,2,3,3,4};
  cout << sol.majorityElement(nums) << endl;
}
