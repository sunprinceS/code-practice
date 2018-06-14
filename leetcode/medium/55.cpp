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
    bool canJump(vector<int>& nums){
      size_t max_reach = 0;
      for(size_t i=0;i<nums.size();++i){
        if(i > max_reach) return false;
        else max_reach = max(max_reach,nums[i] + i);
      }
      return max_reach >= nums.size();
    }
    //bool canJump(vector<int>& nums) {
      //if(DP.empty())
        //DP.resize(nums.size(),-1);
      //else
        //fill(DP.begin(),DP.end(),-1);
      //DP[0] = 1;
      //return canJump(nums,nums.size()-1);
    //}
    
    //int canJump(vector<int>&nums,int fin_loc){
      //for(int i=fin_loc-1;i>=0;--i){
        //if(i + nums[i] >= fin_loc){
          //if(DP[i] == -1)
            //DP[i] = canJump(nums,i);
          //if(DP[i] == 1){
            //DP[fin_loc] = 1;
            //break;
          //}
        //}
      //}
      //DP[fin_loc] = (DP[fin_loc] == -1)?0:1;
      //return DP[fin_loc];
    //}
    //vector<int> DP;
};

int main(){
  Solution sol;
  vector<int> nums({2,3,1,1,4});
  cout << sol.canJump(nums) << endl;
  vector<int> nums_1({3,2,1,0,4});
  cout << sol.canJump(nums_1) << endl;
}
