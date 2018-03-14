#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define ALL(x) begin(x),end(x)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 3e5 + 20;
int tail[32 * MAXN];
int cnt[32 * MAXN];
int nodes[32*MAXN][2];
int A[MAXN];
int N;
int tot = 1;

/*
 * nodes 記轉移狀態，e.g nodes[cur][0] = a 表示在**現在**收到0時，該往 a 走去
 * 所以現在如果還沒有這個狀態，那麼我們新添加一個node (編號tot，並increment tot)
 * 再設好轉移，cur = nodes[cur][0 or 1];
 * 而cnt[cur]則表示 **其前綴為cur所對應到的字串** 有幾個
 * 在最後的 tail[cur] 則是將cur所對應的那個字串直接寫好，可以不用沿路記憶，
 * 適用於比較的東西是定長度者
 * */
void insert(int num){
  int cur = 0;
  for(int i=31;i>=0;--i){
    if(!nodes[cur][(num >> i)& 0x1]) nodes[cur][(num>>i)&0x1] = ++tot;
    cur = nodes[cur][(num>>i)& 0x1];
    ++cnt[cur];
  }
  tail[cur] = num;
}
int query(int num){
  int cur = 0;
  for(int i=31;i>=0;--i){
    if((nodes[cur][(num>>i) & 0x1]) && cnt[nodes[cur][(num >> i) & 0x1]] > 0){
      --cnt[nodes[cur][(num >> i) & 0x1]];
      cur = nodes[cur][(num>>i) & 0x1];
    }
    else{
      --cnt[nodes[cur][!((num >> i) & 0x1)]];
      cur = nodes[cur][!((num>>i) & 0x1)];

    }
  }
  return tail[cur];
}
int main(){
  IOS;
  int tmp;
  while(cin >> N){
    for(size_t i=0;i<N;++i){
      cin >> A[i];
    }
    for(size_t i=0;i<N;++i){
      cin >> tmp;
      insert(tmp);
    }
    for(size_t i=0;i<N;++i){
      cout << (A[i] ^ query(A[i])) << " ";
    }

  }
}

