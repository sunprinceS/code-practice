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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto& n:nums){
          pq.push(n);
          if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

int main(){
  Solution sol;
  vector<int> nums({1,2,3,4,1});
  cout << sol.findKthLargest(nums,2) << endl;
}
