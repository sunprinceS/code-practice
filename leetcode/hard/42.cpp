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
    //Solution1: T: O(n^2), S: O(1)
    //int trap(vector<int>& height) {
        //if(height.size() <= 1) return 0;
        //int l_wall,r_wall;
        //int ret = 0;
        //for(size_t i=1;i<height.size()-1;++i){
          //l_wall = r_wall = height[i];
          //for(int j=i-1;j>=0;--j){
            //l_wall = max(l_wall,height[j]);
          //}
          //for(int j=i+1;j<height.size();++j){
            //r_wall = max(r_wall,height[j]);
          //}
          //ret += min(l_wall,r_wall) - height[i];
        //}
        //return ret;
    //}
    //Solution2: memorization max_right and max_left
    int trap(vector<int>& height) {
        if(height.size() <= 1) return 0;
        int sum = 0;
        vector<int> l_wall(sz);
        vector<int> r_wall(sz);
        l_wall[0] = height.front();
        r_wall[sz-1] = height.back();
        for(size_t i=1;i<sz-1;++i){
          l_wall[i] = max(l_wall[i-1],height[i]);
          r_wall[sz - 1 - i] = max(r_wall[sz - i],height[sz - 1 - i]);
       }
        for(size_t i=1;i<sz-1;++i){
          sum += min(l_wall[i],r_wall[i]) - height[i];
        }
        return sum;
    }
    //Solution3: Stack, w/o reiterating
    int trap(vector<int>& height) {
        if(height.size() <= 1) return 0;
        int sum = 0;
        return sum;
    }
};

int main(){
  vector<int> heights({0,1,0,2,1,0,1,3,2,1,2,1});
  Solution sol;
  cout << sol.trap(heights) << endl;
}
