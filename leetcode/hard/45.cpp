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
  //BFS, O(n)
  int jump(vector<int>& nums){
    queue<int> q;
    vector<int> DP(nums.size(),0);
    iota(DP.begin(),DP.end(),0);
    q.push(0);
    int cur_node;
    int cur_reach = 0;
    int tmp_reach;
    while(!q.empty()){
      cur_node = q.front();
      q.pop();
      if(cur_reach < cur_node + nums[cur_node]){
        tmp_reach = cur_reach;
        cur_reach = cur_node + nums[cur_node];
        for(size_t i=tmp_reach- cur_node+1;i<=nums[cur_node] && cur_node + i<nums.size();++i){
          q.push(cur_node + i);
          DP[cur_node+i] = DP[cur_node] + 1;
          }
        }
        if(cur_reach == nums.size()-1) break;
      }
      return DP[nums.size()-1];
    }
  // O(nlgn), TLE
  //int jump(vector<int>& nums) {
    //vector<int> DP(nums.size(),nums.size()+1);
    //DP[0] = 0;
    //multimap<int,int> max_reach;
    //for(int i=0;i<nums.size();++i){
      //max_reach.insert({i+nums[i],i});
    //}
    //return jump(nums,DP,max_reach,nums.size()-1);
  //}
  //int jump(vector<int>& nums,vector<int>&DP,multimap<int,int> max_reach,int fin_loc){
    //for(auto s = max_reach.lower_bound(fin_loc);s!=max_reach.end();++s){
      //if(s->second < fin_loc && DP[s->second] == nums.size()+1){
        //DP[s->second] = jump(nums,DP,max_reach,s->second);
      //}
      //DP[fin_loc] = min(DP[s->second] + 1,DP[fin_loc]);
    //}
    //max_reach.erase(fin_loc);
    //return DP[fin_loc];
  //}
  // O(n^2), TLE
  //int jump(vector<int>& nums) {
    //vector<int> DP(nums.size(),nums.size()+1);
    //DP[0] = 0;
    //for(size_t i=0;i<nums.size();++i){
      //for(size_t j=1;j<=nums[i] && i+j < nums.size();++j){
        //DP[i+j] = min(DP[i+j], 1 + DP[i]);
      //}
    //}
    //return DP.back(); 
  //}   
};

int main(){
  vector<int> nums({2,1,0});
  Solution sol;
  cout << sol.jump(nums) << endl;
}
