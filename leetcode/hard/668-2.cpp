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
    int findKthNumber(int m, int n, int k) {
      if(k == 1 || k == m*n) return k;
      
      int lb = 1, rb = m * n;

      int mid, n_smaller, s;

      while(lb < rb){
        mid = (lb + rb) / 2;
        n_smaller = 0;

        for(int i=1; i<=m; ++i){
          s = mid / i;
          if (s > n) s = n;
          if (s == 0) break;
          n_smaller += s;
        }

        if(n_smaller < k) lb = mid + 1;
        else rb = mid;
      }
      return rb;
    }
};

int main(){
  Solution sol;
  cout << sol.findKthNumber(3,3,5) << endl;
  cout << sol.findKthNumber(2,3,6) << endl;
  cout << sol.findKthNumber(1000,1,508) << endl;
  cout << sol.findKthNumber(1,1000,508) << endl;
  cout << sol.findKthNumber(1000,1000,508) << endl;
  //cout << sol.findKthNumber(3,3,5) << endl;
}
