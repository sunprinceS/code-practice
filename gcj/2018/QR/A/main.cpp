#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main(){
  int TT;
  cin >> TT;
  int D;
  string seq;


  size_t last_s;
  int ans = 0;
  int tmp_swap_times;
  int cur_harm;
  vector<int> charges;
  charges.reserve(30);
  for(size_t t=1;t<=TT;++t){

    //reset
    ans = 0;
    cur_harm = 0;
    charges.clear();
    charges.push_back(0);
    cin >> D >> seq;
    
    //trim the last 'C's
    last_s = seq.find_last_of('S');
    if(last_s == string::npos){ // all C -> always feasible
        cout << "Case #" << t << ": " << ans << endl;
    }
    else{
      seq = seq.substr(0,last_s+1);
      for(size_t i=0;i<seq.length();++i){
        if(seq[i] == 'C'){
          charges.push_back(0);
        }
        else{
          ++charges.back();
        }
      }

      if(accumulate(charges.begin(),charges.end(),0) > D){
        cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
      }
      else{
        //calc current harm first
        for(size_t i=0;i<charges.size();++i){
          cur_harm += charges[i] * (1 << (i));
        }


        if(cur_harm <= D){
          cout << "Case #" << t << ": " << ans << endl;
        }
        else{
          for(int i=charges.size()-1;i>=1;--i){
            tmp_swap_times = ceil((double)(cur_harm - D)/(1 << (i-1)));
            if(tmp_swap_times <= charges[i]){
              cout << "Case #" << t << ": " << ans+tmp_swap_times << endl;
            }
            else{
              ans += charges[i];
              charges[i-1] += charges[i];
              cur_harm -= charges[i]*(1<<(i-1));
            }
          }
        }
      }
    }
  }
}
