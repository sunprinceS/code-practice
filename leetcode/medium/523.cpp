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
    bool checkSubarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> sums(n);

      if(n <=1) return false;
      for(int i=0;i< n-1; ++i){
        if(nums[i] == 0 && nums[i+1] == 0) return true;
      }
      if(k == 0) return false;
      sums[0] = nums[0];
      for(int i=1; i< n; ++i){
        sums[i] = (nums[i] + sums[i-1]) % k;
        if (sums[i] == 0) return true;
      }
      unordered_map<int,int> occurence;
      occurence.reserve(min(n,k));

      for(int i=0; i< n; ++i){
        auto got = occurence.find(sums[i]);
        if (got == occurence.end()) occurence.insert({sums[i],i});
        else{
          if (got -> second < i-1) return true;
        }
      }
      return false;
    }
};

//O(n^2)
//class Solution {
//public:
    //bool checkSubarraySum(vector<int>& nums, int k) {
        //int n = nums.size();
        //if(n <= 1) return false;
        //for(int i=0; i< n-1; ++i){
            //if(nums[i] == 0 && nums[i+1] ==0) return true;
        //}
        //if(k == 0) return false; 
        
        //vector<vector<int>> range_sum(n);
        //for(auto&v : range_sum){
            //v = vector<int>(n);
        //}
        //for(int i=0;i< n; ++i){
            //range_sum[i][i] = nums[i];
        //}
        
        //for(int d=1;d<n;++d){
            //for(int i=0;i<n && i+d < n;++i){
                //range_sum[i][i+d] = range_sum[i][i+d-1] + nums[i+d];
                //if(range_sum[i][i+d] % k == 0) return true;
            //}
        //}
        //return false;
        
    //}
//};

int main(){
  Solution sol;
  vector<int> nums = {1,0,1};
  cout << sol.checkSubarraySum(nums, 2) << endl;
}
