#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define ALL(x) begin(x),end(x)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
//freopen(name".in", "r", stdin);
//freopen(name".out", "w", stdout);
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

vector<int> cnt(10);
vector<int> oddnum;
string s;
int len;
bool solve(){
  int tt;
  for(int i=len-1;i>=0;--i){
    cnt[s[i] - '0']--;
    if(i == 0) tt = 1;
    else tt = 0;

    for(int j=s[i]-'0'-1;j>=tt;--j){
      cnt[j]++;
      oddnum.clear();
      for(int k=0;k<10;++k){
        if(cnt[k] & 0x1)
          oddnum.push_back(k);
      }
      if(oddnum.size() < len-i){ //success
        for(int pp=0;pp<i;++pp){
          cout << s[pp];
        }
        cout << j;
        for(int pp=0;pp<len-i-oddnum.size()-1;++pp){
          cout << '9';
        }
        sort(ALL(oddnum));
        for(int pp=oddnum.size()-1;pp>=0;--pp){
          cout << oddnum[pp];
        }
        cout << endl;
        return true;
      }
      else{
        cnt[j]--;
      }
    }
  }
  return false;
}
int main(){
  IOS;
  int n;
  while(cin >> n){
    for(size_t nn=0;nn<n;++nn){
      cin >> s;
      len = s.length();
      fill(ALL(cnt),0);
      for(auto d:s){
        cnt[ d - '0']++;
      }
      if(!solve()){
        for(size_t i=0;i<len-2;++i)
          cout << '9';
        cout << endl;
      }
    }
  }
  
}

