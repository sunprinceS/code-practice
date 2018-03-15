#include <iostream>
#include <vector>
/*需要考慮某一維度只有1維的情況！*/
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
		int ret=0;
		for(size_t i=0;i<grid.size();++i){
			for(size_t j=0;j<grid[i].size();++j){
				if(grid[i][j] == 1){

					//detect vertical linkage
					if (i==0){
						if (i < grid.size()-1) ret += 2-grid[i+1][j];
						else ret += 2;
					}
					else if(i== grid.size()-1) ret += 2-grid[i-1][j];
					else ret += 2-(grid[i+1][j]+grid[i-1][j]);

					//detect horizontal linkage
					if (j==0){
						if (j < grid[i].size()-1) ret +=2-grid[i][j+1];
						else ret += 2;
					}
					else if(j==grid[i].size() -1) ret += 2-grid[i][j-1];
					else ret += 2-(grid[i][j+1]+grid[i][j-1]);
				}
			}
		}
		return ret;
    }
};
