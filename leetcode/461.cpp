#include <iostream>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int ret = 0,n = x^y;
		while(n){
			if (n & 0x1 == 1){
				ret += 1;
			}
			n = n >> 1;
		}
		return ret;
	}
};
int main(){
	Solution sol;
	cout << sol.hammingDistance(3,4) << endl;
}
