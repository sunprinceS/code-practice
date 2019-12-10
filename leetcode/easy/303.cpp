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

class NumArray {
public:
    NumArray(vector<int>& nums) {
      sums = vector<int>(nums.size() + 1, 0);
      for(int i=1; i<= nums.size(); ++i){
        sums[i] = sums[i-1] + nums[i-1];
      }
    }
    
    int sumRange(int i, int j) {
      return sums[j+1] - sums[i];
    }
    vector<int> sums;
};


int main(){
  vector<int> nums = {-2,0,3,-5,2,-1};
  NumArray* obj = new NumArray(nums);
  cout << obj -> sumRange(0,2) << endl;
  cout << obj -> sumRange(2,5) << endl;
  cout << obj -> sumRange(0,5) << endl;
}
