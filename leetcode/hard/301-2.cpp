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
      int l = 0;
      int r = 0;
      for(auto &c: s){
        if (c == '(') ++l;
        else if(c == ')'){
          if (l > 0) --l;
          else ++r;
        }
      }
      vector<string> ans;
      dfs(ans, s, 0, r, l );
      return ans;
    }

    void dfs(vector<string>& ans, string& cur, int pos, int r, int l){
      if (r == 0 && l == 0){
        if(is_valid(cur)) ans.push_back(cur);
        return;
      }
      else{
        for (int i=pos; i < cur.length(); ++i){
          if (i == pos || cur[i] != cur[i-1]){
            if (cur[i] == ')' && r > 0){
              string tmp = cur;
              dfs(ans, tmp.erase(i, 1),i, r -1 , l);
            }
            else if(cur[i] == '(' && l > 0){
              string tmp = cur;
              dfs(ans,tmp.erase(i,1), i, r, l-1);
            }
          }
        }
      }

    }
    bool is_valid(string s){
      int  cnt = 0;
      for(auto &c: s){
        if (c == '(') ++cnt;
        else if(c == ')') --cnt;

        if (cnt < 0) return false;
      }
      return cnt == 0;
    }
};

int main(){
  Solution sol;
  //string s("(a)())()");
  string s(")(");
  cout << sol.removeInvalidParentheses(s) << endl;
}
