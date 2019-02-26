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

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      int r = min(n,9); // can only use numbers from 1-9

      vector<vector<int> > ans;
      vector<int> cur;
      dfs(ans,cur, n ,1,r,k);
      return ans;
    }
private:
    void dfs(vector<vector<int> >& ans, vector<int>& cur, int target, int pos, const int r, const int k){
      if (cur.size() == k){
        if(target == 0) ans.push_back(cur);
        return;
      }
      else{
        for(int i=pos; i <= r; ++i){
          cur.push_back(i);
          dfs(ans,cur,target - i, i+1, r, k);
          cur.pop_back();
        }
      }
      
    }
};

int main(){
  Solution sol;
  cout << sol.combinationSum3(3,7) << endl;
  cout << sol.combinationSum3(3,9) << endl;
}
