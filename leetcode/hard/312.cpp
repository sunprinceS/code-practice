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
    int maxCoins(vector<int>& nums) {
      size_t N = nums.size();
      nums.insert(nums.begin(),1);
      nums.push_back(1);
      vector<vector<int> > DP(N+2,vector<int>(N+2));
      
      size_t end;
      for(size_t len=1;len<=N;++len){
        for(size_t start=1;start<=N+1-len;++start){
          end = start + len -1;
          for(size_t f = start;f<=end;++f){
            DP[start][end] = max(DP[start][end],
                                nums[start-1]*nums[f]*nums[end+1] + DP[start][f-1] + DP[f+1][end]);
          }
        }
      }
      return DP[1][N];
    }
};

int main(){
  vector<int> nums({3,1,5,8});
  Solution sol;
  cout << sol.maxCoins(nums) << endl;
}
