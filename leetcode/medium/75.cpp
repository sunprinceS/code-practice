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
    void sortColors(vector<int>& nums) {
      vector<int> cnt(3);
      for(auto n:nums) ++cnt[n];
      int start = 0;
      int end = cnt[0];
      fill(nums.begin()+start,nums.begin()+end,0);
      for(size_t i=1;i<3;++i){
        start = end;
        end += cnt[i];
        fill(nums.begin()+start,nums.begin()+end,i);
      }
    }
};

int main(){
  Solution sol;
  vector<int> nums = {0};
  sol.sortColors(nums);
  cout << nums << endl;
}
