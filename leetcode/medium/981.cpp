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

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        storage.reserve(120000);
    }
    
    void set(string key, string value, int timestamp) {
        auto got = storage.find(key);
        if(got == storage.end()){ // not found
            storage[key] = {{timestamp, value}};
        } 
        else{
            storage[key].push_back({timestamp,value});
        }
    }
    
    string get(string key, int timestamp) {
        auto got = storage.find(key);
        if (got == storage.end()) return "";
        else{
          int ub = binary_search(key, timestamp + 1);
          if (ub == 0) return "";
          else return storage[key][ub - 1].second;
        }
    }

    int binary_search(string key, int t){
      int lb = 0;
      int rb = storage[key].size();
      int mid;

      while(lb < rb){
        mid = (lb + rb) / 2;
        if (storage[key][mid].first >= t) rb = mid;
        else lb = mid + 1;
      }

      return lb;
    }
    
    unordered_map<string, vector<pair<int, string>>> storage; 
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(){
  TimeMap* obj = new TimeMap();
  obj -> set("foo","bar", 1);
}
