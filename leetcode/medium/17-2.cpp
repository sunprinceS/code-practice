// DFS solution
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
    vector<string> letterCombinations(string digits) {
      if(digits.length() == 0) return {};


      string cur_str;
      vector<string> ret;

      dfs(digits,cur_str,ret,0);
      return ret;
    }

  private:
    vector<string> mapping = {
      "",
      "", 
      "abc", 
      "def", 
      "ghi", 
      "jkl", 
      "mno", 
      "pqrs", 
      "tuv", 
      "wxyz"
    };

    void dfs(const string& digits,string& cur_str, vector<string>& ret, int pos){
      if(pos == digits.length()){
        ret.push_back(cur_str);
      }
      else{
        for (auto ch: mapping[digits[pos] - '0']){
          cur_str.push_back(ch);
          dfs(digits,cur_str,ret,pos+1);
          cur_str.pop_back();
        }
      }
    }
};

int main(){
  Solution sol;
  cout << sol.letterCombinations("21") << endl;
  cout << sol.letterCombinations("234") << endl;
}
