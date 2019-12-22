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
    int peakIndexInMountainArray(vector<int>& A) {
      int lb = 0, rb = A.size() - 1;
      int mid;
      while(lb < rb){
        mid = (lb + rb) / 2;
        if(A[mid] < A[mid + 1]) lb = mid + 1;
        else rb = mid;
      } 
      return lb;
    }
};

int main(){
}
