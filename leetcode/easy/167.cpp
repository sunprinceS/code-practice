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
    vector<int> twoSum(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
      int it1 = 0;
      int it2 = nums.size()-1;
      int nn;
      while(it1 < it2){
        nn = nums[it1] + nums[it2];
        if(nn > target) --it2;
        else if(nn < target) ++ it1;
        else return {it1+1,it2+1};
      }
        
    }
};

int main(){
  Solution sol;
  vector<int> nums = {2,7,11,15};
  cout << sol.twoSum(nums,9) << endl;
}
