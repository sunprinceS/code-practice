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
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> freq;
      priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >pq;
      for(auto& n:nums) freq[n]++;
      for(auto& pr:freq){
        pq.push({pr.second,pr.first});
        if(pq.size() > k) pq.pop();
      }
      vector<int> ret;ret.reserve(k);
      while(!pq.empty()){
        ret.push_back(pq.top().second);
        pq.pop();
      }

      return ret;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {1,2,3,4,2,2};
  cout << sol.topKFrequent(nums,3) << endl;
}
