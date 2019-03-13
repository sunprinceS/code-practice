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
    vector<string> removeInvalidParentheses(string s) {
      int l=0;
      int r=0;

      for (auto c:s){
        if(c == '(') ++l;
        else if(c == ')'){
          if(l == 0) ++r;
          else --l;
        }
      }
      vector<string> ans;
      dfs(ans,s,l,r,0);
      return ans;
    }

private:
    void dfs(vector<string>&ans, string& cur, int l, int r, int pos){
      if(r == 0 && l == 0){
        if(is_valid(cur)) ans.push_back(cur);
      }
      else{
        for(int i=pos;i<cur.length();++i){
          if(i > pos && cur[i] == cur[i-1]) continue;
          else{
            if(cur[i] == '(' && l > 0){
              string tmp = cur;
              tmp.erase(i,1);
              dfs(ans,tmp,l-1,r,i);
            }
            else if(cur[i] == ')' && r > 0){
              string tmp = cur;
              tmp.erase(i,1);
              dfs(ans,tmp,l,r-1,i);
            }
          }
        }
      }
    }
    bool is_valid(string s){
      int cnt = 0;
      for(auto c:s){
        if(c == '(') ++cnt;
        else if(c == ')') --cnt;
        else continue;

        if(cnt < 0) return false;
      }
      return (cnt == 0);
    }
};

int main(){
  Solution sol;
  cout << sol.removeInvalidParentheses("()())()") << endl;
}
