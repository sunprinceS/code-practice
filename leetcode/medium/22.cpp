#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
return s<<"("<<p.first<<","<<p.second<<")";
}

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
s<<"[ ";
for (auto it : c) s << it << " , ";
s<<"]";
return s;
}

//DFS 的 action 要想一下 (以個別 parathensis 為單位，而不是一組"()")
class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> ans;
      string cur;
      dfs(ans,cur,n,n);
      return ans;
    
    }
    void dfs(vector<string>& ans, string& cur, int l, int r){
      if (r == 0 && l == 0){
        ans.push_back(cur);
        return;
      }
      else{
        if (r < l) return;
        
        if(r > 0){
          cur += ")";
          dfs(ans,cur,l,r-1);
          cur.pop_back();
        }
        
        if(l > 0){
          cur += "(";
          dfs(ans,cur,l-1,r);
          cur.pop_back();
        }
      }
    }
};

int main(){
  Solution sol;
  cout << sol.generateParenthesis(3) << endl;
}
