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

vector<vector<int>> map20(5,vector<int>(4));
vector<vector<int>> map200(20,vector<int>(10));

void init(int a){
  if(a == 20){
    for(auto& r:map20){
      fill(ALL(r),0);
    }
  }
  else{
    for(auto& r:map200){
      fill(ALL(r),0);
    }
  }
}

void solve20(){
  int recv_x,recv_y;
  int glo_cnt = 0;

  // fill middle part
  for(int x = 500;x <=501;++x){
    for(int y =500;y<=502;++y){
      while(!map20[x-499][y-499]){
        ++glo_cnt;
        cin >> recv_x >> recv_y;
        cout << x << " " << y << endl;
        map20[recv_x-499][recv_y-499] = 1;
      }
    }
  }

  //priority queue
  int tmp_pr;
  priority_queue<pair<int,pair<int,int>>> pq;
  for(int x = 500;x<=501;++x){
    for(int y = 500;y<=502;++y){
      tmp_pr = 0;
      for(int xx = -1;xx<=1;++xx){
        for(int yy = -1;yy<=1;++yy){
          if(map20[x+xx-499][y+yy-499] == 0) ++tmp_pr;
        }
      }
      pq.push({tmp_pr,{x,y}});
      map20[x-499][y-499] = tmp_pr;
    }
  }
  pair<int,pair<int,int>> topp;
  int x,y;
  while(true){
    topp = pq.top();
    x = topp.second.first;
    y = topp.second.second;
    cin >> recv_x >> recv_y;
    if(recv_x == 0 && recv_y == 0) return;
    ++glo_cnt;
    cout << x << " " << y << endl;
    cerr << glo_cnt  << "\t" << topp << endl;


    pq.pop();
    if(map20[recv_x-499][recv_y-499] == 0){
      map20[recv_x-499][recv_y-499] = 1;
    }
    
    tmp_pr = 0;
    for(int xx = -1;xx <= 1;++xx){
      for(int yy = -1;yy<=1;++yy){
        if(map20[x+xx-499][y+yy-499] == 0) ++tmp_pr;
      }
    }
    map20[x-499][y-499] = tmp_pr;
    if(map20[x-499][y-499] != 0){
      pq.push({map20[x-499][y-499],{x,y}});
    }
  }
}

void solve200(){
  int recv_x,recv_y;
  int glo_cnt = 0;

  // fill middle part
  for(int x = 500;x <=508;++x){
    for(int y =500;y<=518;++y){
      while(!map200[x-499][y-499]){
        ++glo_cnt;
        cin >> recv_x >> recv_y;
        cout << x << " " << y << endl;
        map200[recv_x-499][recv_y-499] = 1;
      }
    }
  }

  //priority queue
  int tmp_pr;
  priority_queue<pair<int,pair<int,int>>> pq;
  for(int x = 500;x<=508;++x){
    for(int y = 500;y<=518;++y){
      tmp_pr = 0;
      for(int xx = -1;xx<=1;++xx){
        for(int yy = -1;yy<=1;++yy){
          if(map200[x+xx-499][y+yy-499] == 0) ++tmp_pr;
        }
      }
      pq.push({tmp_pr,{x,y}});
      map200[x-499][y-499] = tmp_pr;
    }
  }
  pair<int,pair<int,int>> topp;
  int x,y;
  while(true){
    topp = pq.top();
    x = topp.second.first;
    y = topp.second.second;
    cin >> recv_x >> recv_y;
    if(recv_x == 0 && recv_y == 0) return;
    ++glo_cnt;
    cout << x << " " << y << endl;


    pq.pop();
    if(map200[recv_x-499][recv_y-499] == 0){
      map200[recv_x-499][recv_y-499] = 1;
    }
    
    tmp_pr = 0;
    for(int xx = -1;xx <= 1;++xx){
      for(int yy = -1;yy<=1;++yy){
        if(map200[x+xx-499][y+yy-499] == 0) ++tmp_pr;
      }
    }
    map200[x-499][y-499] = tmp_pr;
    if(map200[x-499][y-499] != 0){
      pq.push({map200[x-499][y-499],{x,y}});
    }
  }
}

int main(){
  int num_test;
  cin >> num_test;
  int area;
  for(size_t t=0;t<num_test;++t){
    cin >> area;
    init(area);
    cout << "500 500" << endl;
    if(area == 20){
        solve20();
    }
    else{ // 200
        solve200();
    }
  }
}

