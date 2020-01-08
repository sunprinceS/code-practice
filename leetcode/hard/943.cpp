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
    string shortestSuperstring(vector<string>& A) {
      if(A.size() == 1) return A[0];
      else{
        vector<string> ans;
        string cur;
        dfs(ans, A, cur, 0, A.size());
        sort(ans.begin(), ans.end(), [](string l, string r){return l.size() < r.size();});
        cout << ans << endl;
        return ans[0];
      }
    }
    void dfs(vector<string>& ans,vector<string>& A, string cur, int pos, int target){
      if(target == 0){
        ans.push_back(cur);
        return;
      }
      for(int i=pos;i< A.size(); ++i){
        string cur_backup = cur;
        swap(A[pos],A[i]);
        dfs(ans, A, merge_str(cur, A[pos]), pos+1, target-1);
        swap(A[pos], A[i]);
        cur = cur_backup;
      }
    }
    string merge_str(string l_str, string r_str){
      int rp = 0;
      for(int lp = l_str.length() - 1; lp >= 0; --lp){

      }
      int lp = l_str.length() - 1;
      int rp = 0;
      while(lp >= 0 && rp < r_str.length()){
        if(l_str[lp] != r_str[rp]) return l_str + r_str.substr(rp);
      }
      return l_str.length()>r_str.length()?l_str:r_str;
    }

};

int main(){
  Solution sol;
  vector<string> As = {"alex","loves","leetcode"};
  cout << sol.shortestSuperstring(As) << endl;
}
