#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
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

int main(){
  IOS;
  int TT;
  int N;
  int ans;
  vector<vector<int> >nums(2,vector<int>());
  nums[0].reserve(50005);
  nums[1].reserve(50005);
  cin >> TT;
  bool suc;
  for(size_t t=1;t<=TT;++t){
    cin >> N;
    suc = true;
    nums[0].resize(ceil((float)N/2));
    nums[1].resize(N/2);
    for(size_t n=0;n<N;++n){
      cin >> nums[n%2][n/2];
    }
    sort(nums[0].begin(),nums[0].end());
    sort(nums[1].begin(),nums[1].end());
    for(size_t n=0;n<N-1;++n){
      if(((n%2 == 0)&&(nums[0][n/2] > nums[1][n/2])) || ((n%2 == 1)&&(nums[1][n/2] > nums[0][(n/2)+1]))){
        ans = n;
        suc = false;
        break;
      }
    }
    if(suc){
      cout << "Case #" << t << ": " << "OK" << endl;
    }
    else{
      cout << "Case #" << t << ": " << ans << endl;
    }
  }
  
}

