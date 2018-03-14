//http://codeforces.com/problemset/problem/160/A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int num_coins;
	while(cin >> num_coins){
		size_t* coin_vals;
		size_t total=0;
		size_t youget=0;
		coin_vals = new size_t [num_coins];
		 for (int i = 0; i < num_coins; ++i) {
			cin >> coin_vals[i];
			total += coin_vals[i];
		}
		sort(coin_vals,coin_vals+num_coins);
		reverse(coin_vals,coin_vals+num_coins);
		size_t i=0;
		size_t cnt=0;
		while(youget <= total - youget){
			youget += coin_vals[i];
			++i;
			++cnt;
		}
		cout << cnt << endl;
	}
	return 0;
}
