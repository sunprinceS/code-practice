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

//int gcd(int a,int b){
  //if(b == 0) return a;
  //else return gcd(b,a%b);
//}
int main(){
  IOS;
 int n,k;
 vector<int> a;a.reserve(105);
 cin >> n >> k;
 a.resize(n);
 for(size_t i=0;i<n;++i){
   cin >> a[i];
 }
 sort(ALL(a));
 for(int i=n-1;i>=0;--i){
   if(k%a[i] == 0){
     cout << k/a[i] << endl;
     break;
   }
 }
}

