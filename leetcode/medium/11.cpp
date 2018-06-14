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
    //Solution2
    int maxArea(vector<int>& height) {
      int l = 0,r = height.size() - 1;
      int max_area = (r-l) * min(height[l],height[r]);
      while(l!=r){
        if(height[l] < height[r]) ++l;
        else --r;

        max_area = max(max_area,(r-l)*min(height[l],height[r]));
      }
      return max_area;
    }
};

int main(){
  vector<int> heights({1,1});
  Solution sol;
  cout << sol.maxArea(heights) << endl;
}
