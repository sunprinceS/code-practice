#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define ALL(x) begin(x),end(x)
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

// 思路: 直接去 simulate ，O(N^2) 一定不行，所以在每個回合，想找一個 O(lg N)的方
// 法算出融雪，所以想到以下可能 - Binary Search 或 bit indexed array (但BIT 不太
// 適合這個情境)
int main(){
  IOS;
  int N;
  vector<long long> vol;
  vector<long long> prev_tem;
  vector<int> tem;

  while(cin >> N){
    vol.resize(N);
    prev_tem.resize(N);
    tem.resize(N);

    for(size_t i=0;i<N;++i){
      cin >> vol[i];
    }
    cin >> tem[0];
    prev_tem[0] = tem[0];

    for(size_t i=1;i<N;++i){
      cin >> tem[i];
      prev_tem[i] = prev_tem[i-1]+tem[i];
    }
    for(size_t i=1;i<N;++i){
      vol[i] += prev_tem[i-1];
    }

    multiset<long long> ms;
    multiset<long long>::iterator ms_it;
    long long sum;

    if(vol[0] < tem[0]){
      cout << vol[0] << " ";
    }
    else{
      ms.insert(vol[0]);
      cout << tem[0] << " ";
    }

    for(size_t i=1;i<N;++i){
      ms.insert(vol[i]);
      sum = 0; //reset
      ms_it = ms.upper_bound(prev_tem[i]);//用 lower_bound 會錯...不知道為啥？
      for(multiset<long long>::iterator it = ms.begin();it != ms_it;++it){
        sum += (*it-prev_tem[i-1]);
      }
      ms.erase(ms.begin(),ms_it);
      cout << ms.size()*tem[i] + sum << " ";
    }
  }
}

