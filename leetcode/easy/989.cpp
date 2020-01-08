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
    vector<int> addToArrayForm(vector<int>& A, int K) {
      vector<int> ret;ret.reserve(7000);
      int aptr = A.size() - 1;
      int c = 0;
      while(K > 0 || aptr >= 0 || c){
        if(K > 0){
          c += (K%10);
          K /= 10;
        }
        if(aptr >= 0){
          c += A[aptr];
          --aptr;
        }
        ret.push_back(c % 10);
        c /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
    }
};

int main(){
  Solution sol;
  vector<int> A;
  int K;

  A = {1,2,0,0};
  K = 34;
  cout <<  sol.addToArrayForm(A, K) << endl;

  A = {2,7,4};
  K = 181;
  cout << sol.addToArrayForm(A, K) << endl;

  A = {2,1,5};
  K = 806;
  cout << sol.addToArrayForm(A, K) << endl;

  A = {9,9,9,9,9,9,9,9,9,9};
  K = 1;
  cout << sol.addToArrayForm(A, K) << endl;
  
  A = {};
  K = 123;
  cout << sol.addToArrayForm(A, K) << endl;
}
