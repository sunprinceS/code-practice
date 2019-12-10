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
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      int sum = 0;
      int ret = 0;
      unordered_map<int, int> occurence;
      occurence[0] = 1;
      //occurence.insert({0,1});

      for(auto& num: nums){
        sum += num;
        if(occurence[sum - k]) ret += occurence[sum - k];
        occurence[sum] += 1;
        //auto got1 = occurence.find(sum - k);
        //if(got1 != occurence.end()) ret += got1 -> second;
        //auto got2 = occurence.find(sum);
        //if(got2 != occurence.end()) got2 -> second += 1;
        //else occurence.insert({sum, 1});
      }
      return ret;
    }
};

int main(){
  Solution sol;
  //vector<int> nums = {1,1,1,1,1};
  vector<int> nums = {0,1};
  cout << sol.subarraySum(nums, 1) << endl;
}
