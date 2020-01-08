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
 string addBinary(string a, string b){
   string s="";
   int c = 0, aptr=a.length() - 1, bptr = b.length() - 1;
   while(aptr >= 0 || bptr >= 0 || c == 1){
     if(aptr >=0) c += (a[aptr] - '0'), --aptr;
     if(bptr >=0) c += (b[bptr] - '0'), --bptr;

     s = char(c % 2 + '0') + s;
     c /= 2;
   }
   return s;
 }
};

int main(){
  Solution sol;
  string a("11");
  string b("1");

  cout << sol.addBinary(a,b) << endl;
}
