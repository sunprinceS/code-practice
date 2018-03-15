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
   int countSubstrings(string s){
     int cnt = s.length();
     bool palin[s.length()][s.length()];
     for(size_t i=0;i<s.length();++i){
       for(size_t j=0;j<s.length();++j)
         palin[i][j] = false;
     }
     for(size_t i=1;i<s.length();++i){
       for(size_t j=i;j<s.length();++j){
         if(i>2){
           palin[j-i][j] = ((s[j-i] == s[j]) && palin[j-i+1][j-1]);
         }
         else{
           palin[j-i][j] = (s[j-i] == s[j]);
         }
         if(palin[j-i][j]){
           ++cnt;
           //cout << "( " << j-i << " , " << j << ")" << endl;
         }
       }
     }
     return cnt;
   }
    
};

int main(){
  Solution sol;
  cout << sol.countSubstrings("abc") << endl;
  cout << sol.countSubstrings("aaa") << endl;
}
