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

      vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      vector<string> ret;ret.reserve(10000);
      vector<string> new_ret;new_ret.reserve(10000);
      ret.push_back("");
      for(auto d:digits){
        if(d == '0' || d == '1'){
          return {};
        }
        else{
          new_ret.clear();
          for(auto c: v[d-'0']){
            for(auto prefix: ret)
              new_ret.push_back(prefix + c);
          }
          ret = new_ret;
        }
      }
      return ret;

    }
};

int main(){
  Solution sol;
  cout << sol.letterCombinations("23") << endl;
}
