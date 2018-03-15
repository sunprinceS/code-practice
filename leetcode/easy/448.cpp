/* Find Disapperaed Numbers in array
 * Key Idea: mark negative label to indicate 
 * */

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
    vector<int> findDisappearedNumbers(vector<int>& nums) {

		vector<int> ret;
		ret.reserve(nums.size());
    for(auto n: nums){
      nums[abs(n)-1] = -abs(nums[abs(n)-1]);
    }
    for(size_t i=0;i<nums.size();++i){
      if(nums[i]>0)
        ret.push_back(i+1);
    }
		return ret;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {4,3,2,7,8,2,3,1};
  vector<int> ret = sol.findDisappearedNumbers(nums);
  cout << ret << endl;
}
