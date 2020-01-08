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

      if (k == 0) return 1;
      if (k == m * n) return m * n;

      int lb = 1, rb = m*n;
      int mid, num_smaller, s;

      while(lb < rb){
        num_smaller = 0;
        mid = lb + (rb-lb) / 2;
        for(int i=1;i<=m;++i){
          //s = ceil(mid/float(i) - 1); // ^^"
          s = mid / i;
          if (s > n) s = n;
          if (s == 0) break;
          num_smaller += s;
        }
        if(num_smaller < k) lb = mid + 1;
        else rb = mid;
      }
      return lb;
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
