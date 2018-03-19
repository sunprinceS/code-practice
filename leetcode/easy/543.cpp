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
    int diameter;
    int diameterOfBinaryTree(TreeNode* root){
      diameter = 0;
      if(root == NULL) return 0;
      traverse(root);
      return diameter;
    }
    int traverse(TreeNode* root){
      int l_dep = -1,r_dep = -1;
      if(root -> left != NULL) l_dep = traverse(root->left);
      if(root -> right != NULL) r_dep = traverse(root->right);
      
      if(l_dep + r_dep + 2 > diameter){
        diameter = l_dep + r_dep + 2;
      }
      return max(l_dep,r_dep)+1;
    }
    
};

int main(){
  Solution sol;
}
