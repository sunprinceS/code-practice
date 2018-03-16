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
   //wrong solution, but catch the idea
    //vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
      //vector<pair<int,int> >ret(people.size()); // 0,0
      //vector<int> ptr(people.size());
      //iota(ptr.begin(),ptr.end(),0);
      //sort(people.begin(),people.end());
      
      //for(auto& p: people){
        //while(ret[ptr[p.second]].first != 0){
          //ptr[p.second]++;
        //}
        //ret[ptr[p.second]] = p;
        //ptr[p.second]++;
      //}
      //return ret;
    //}
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
      sort(people.begin(),people.end(),[](pair<int,int> p1,pair<int,int> p2){
           return p1.first > p2.first || ((p1.first == p2.first) && (p1.second < p2.second));
           });
      vector<pair<int,int> > ret;
      for(auto p: people){
        ret.insert(ret.begin()+p.second,p);
      }
      return ret;
    }
};

int main(){
  Solution sol;
  vector<pair<int,int> > people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  cout << sol.reconstructQueue(people) << endl;
}
