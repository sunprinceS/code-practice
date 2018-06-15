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
    vector<int> partitionLabels(string S) {
        vector<pair<int,int> > alphas(26,{-1,-1});
        for(size_t i=0;i<S.length();++i){
          if(alphas[S[i]-'a'].first == -1)
            alphas[S[i]-'a'].first = i;
          else
            alphas[S[i]-'a'].second = i;
        }

        sort(alphas.begin(),alphas.end());
        vector<int> ret;
        int start,end;
        auto it = upper_bound(alphas.begin(),alphas.end(),make_pair(-1,-1));
        tie(start,end) = *it;
        if(end == -1) end = 0;
        ++it;

        for(;it!=alphas.end();++it){
          if(it->first > end){
            ret.push_back(end-start+1);
            if(it->second != -1) tie(start,end) = *it;
            else start = end = it->first;
          }
          else{
            end = max(end,it->second);
          }
        }
        ret.push_back(end-start+1);
        return ret;
    }
};

int main(){
  Solution sol;
  cout << sol.partitionLabels("ababcbacadefegdehijhklij") << endl;
  cout << sol.partitionLabels("ababcbacazyx") << endl;
  cout << sol.partitionLabels("caedbdedda") << endl;
}
