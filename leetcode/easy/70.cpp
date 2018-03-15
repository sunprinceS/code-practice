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
   int climbStairs(int n){
     vector<int> arr(n+1);
     arr[1] = 1;
     arr[2] = 2;
     for(size_t i=3;i<=n;++i){
       arr[i] = arr[i-1] + arr[i-2];
     }
     return arr[n];
   }
    
};

int main(){
  Solution sol;
  cout << sol.climbStairs(4) << endl;
}
