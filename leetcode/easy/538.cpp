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
     TreeNode* convertBST(TreeNode* root) {
       if(root){
           int accum = 0;
           inorderTraversal(root,accum);      
       }
       return root;
    }
    void inorderTraversal(TreeNode* root,int& accum){
      if(root->right){
        inorderTraversal(root->right,accum);
      }
      accum += root->val;
      root->val = accum;

      if(root->left){
        inorderTraversal(root->left,accum);
      }
    }
};
int main(){
  Solution sol;
}
