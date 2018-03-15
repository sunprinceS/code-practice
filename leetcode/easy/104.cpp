#include <iostream>
#include <algorithm>
using namesapce std;

class Solution {
public:
	int maxDepth(TreeNode* node) {
		if(node->left == NULL && node->right == NULL)
			return 0;
		else
			return 1 + max(maxDepth(node->right),maxDepth(node->left));
	}
};
