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
    int numSquarefulPerms(vector<int>& A) {
      int ans = 0;
      vector<int> cur;
      unordered_map<int, int> counter;
      if(A.size() == 0) return 0;
      else if(A.size() == 1) return 1;
      else{ 
        for(auto num: A){
          auto got = counter.find(num);
          if(got == counter.end()) counter.insert({num,1});
          else got-> second += 1;
        }
        dfs(ans, counter, cur, A.size(),0);
      }
      return ans;
    }
    void dfs(int& ans, unordered_map<int,int>& counter, vector<int>& cur, int target, int cur_size){
      if((cur_size > 1 && is_square(cur[cur_size-1]+cur[cur_size-2])) || cur_size <= 1){
        if(cur_size == target) ans += 1;
        else{
          for(auto &p: counter){
            if(p.second > 0){
              p.second -= 1;
              cur.push_back(p.first);
              dfs(ans, counter, cur, target, cur_size+1);
              cur.pop_back();
              p.second += 1;
            }
          }
        }
      }
    }

    bool is_square(int num){
      int root = sqrt(num);
      return root * root == num;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {2,2,3};
  cout << sol.numSquarefulPerms(nums) << endl;
}
