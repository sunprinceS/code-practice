#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
	size_t days;
	while(cin >> days){
		vector<int> gains;
		gains.resize(days);

		for(size_t i=0;i<days;++i)
			cin >> gains[i];

		vector<int>R;
		vector<int>best;
		R.resize(days);
		best.resize(days);

		R[0]=best[0]=1;
		for(size_t i=1;i<days;++i){
			if(gains[i] < gains[i-1])
				R[i] = 1;
			else
				R[i] = R[i-1] + 1;

			best[i] = max(R[i],best[i-1]);
		}
		cout << best[days-1] << endl;
	}
	return 0;
}

