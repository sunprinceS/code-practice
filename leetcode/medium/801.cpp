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
     int minSwap(vector<int>& A, vector<int>& B) {
       vector<vector<int>> dp(2);
       dp[0] = vector<int> (A.size(),2000);
       dp[1] = vector<int> (B.size(),2000);

       dp[0][0] = 0;
       dp[1][0] = 1;
       for(int i=1;i< A.size();++i){
         if(A[i] <= A[i-1] || B[i] <= B[i-1]){
           dp[0][i] = dp[1][i-1];
           dp[1][i] = dp[0][i-1] + 1;
         }
         else if(A[i] <= B[i-1] || B[i] <= A[i-1]){
           dp[0][i] = dp[0][i-1];
           dp[1][i] = dp[1][i-1] + 1;
         }
         else{
           dp[0][i] = min(dp[0][i-1], dp[1][i-1]);
           dp[1][i] = dp[0][i] + 1;
         }
       }
       return min(dp[0].back(),dp[1].back());
    }
};

int main(){
}
