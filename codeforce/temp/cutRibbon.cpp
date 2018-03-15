//http://codeforces.com/problemset/problem/189/A

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e8;

int main(void)
{
	int n,a;
	while(cin >> n){
		vector<int> max_ribbons;
		max_ribbons.resize(n+1,-1*INF);
		max_ribbons[0] = 0;
		for(size_t i=0;i<3;++i){
			cin >> a;
			for(size_t j=a;j<=n;++j){
				max_ribbons[j] = max(max_ribbons[j-a]+1,max_ribbons[j]);
			}
		}
		cout << max_ribbons[n];
	}
	return 0;
}
