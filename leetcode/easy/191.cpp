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
    int hammingWeight(uint32_t n) {
      int ret = 0;
      while( n > 0 ){
        ret += (n & 0x1);
        n = n >> 1;
      }
      return ret;
    }
};

int main(){
  Solution sol;
  cout << 11 << '\t' << sol.hammingWeight(11) << endl;
  cout << 8 << '\t' << sol.hammingWeight(8) << endl;
  cout << 1 << '\t' << sol.hammingWeight(1) << endl;
  cout << 15 << '\t' << sol.hammingWeight(15) << endl;
}
