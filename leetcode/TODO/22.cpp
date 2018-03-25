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
    vector<string> generateParenthesis(int n) {
      unordered_set<string> candidate;
      candidate.insert("()");
      unordered_set<string> ret = candidate;
      for(size_t i=2;i<=n;++i){
        ret.clear();
        for(auto c: candidate){
          ret.insert( '(' + c + ')' );
          ret.insert( "()" + c );
          ret.insert( c + "()");
        }
        candidate = ret;
      }
      return vector<string>(ret.begin(),ret.end());
    }
};

int main(){
  Solution sol;
  // WA: n=4, case: (())(())
  cout << sol.generateParenthesis(1) << endl;
}
