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
    vector<string> letterCasePermutation(string S) {
      vector<string> ans;
      string cur;
      dfs(ans,cur,S,0);
      return ans;
    }
private:
    void dfs(vector<string>& ans,string& cur,const string& S, int pos){
      if(cur.length() == S.length()){
        ans.push_back(cur);
        return;
      }
      else{
        if(isdigit(S[pos])){
          cur += S[pos];
          dfs(ans,cur,S,pos+1);
          cur.pop_back(); // SHOULD POP_BACK, DON'T FORGET
        }
        else{
          cur += tolower(S[pos]);
          dfs(ans,cur,S,pos+1);
          cur.pop_back();
          cur += toupper(S[pos]);
          dfs(ans,cur,S,pos+1);
          cur.pop_back();
        }
      }
    }
};

int main(){
  Solution sol;
  string s = "A1B";
  cout << sol.letterCasePermutation(s) << endl;
}
