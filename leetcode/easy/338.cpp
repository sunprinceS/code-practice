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
    vector<int> countBits(int num){
      vector<int> ret(num+1);
      ret[0] = 0;
      ret[1] = 1;
      int cur_mod = 2;
      for(size_t i=2;i<=num;++i){
        ret[i] = 1 + ret[i%cur_mod];
        if(i % (cur_mod * 2) == 0)
          cur_mod *= 2;
      }
      return ret;
      //Better sol
      //ret[i] = ret[i&(i-1)] + 1
    }
};

int main(){
  Solution sol;
  cout << sol.countBits(8) << endl;
}
