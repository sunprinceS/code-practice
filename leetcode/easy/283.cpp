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
    void moveZeroes(vector<int>& nums) {
      int front_ptr = 0,back_ptr;
      while(front_ptr < nums.size() && nums[front_ptr] != 0) ++front_ptr;
      back_ptr = front_ptr + 1;
      while(back_ptr < nums.size() && nums[back_ptr] == 0) ++back_ptr;

      while(back_ptr < nums.size()){
        if(nums[front_ptr] == 0){
          swap(nums[front_ptr],nums[back_ptr]);
        }
        ++front_ptr;

        if(front_ptr == back_ptr || nums[back_ptr] == 0){
          while(nums[back_ptr] == 0) ++back_ptr;
        }
      }
    }
};

int main(){
  Solution sol;
  vector<int> nums = {1,1,1,3,12};
  sol.moveZeroes(nums);
  cout << nums << endl;
}
