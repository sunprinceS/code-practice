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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
  public:
   // Wrong sol (有可能跨越奇偶數層的限制！)
   //       4
   //      /
   //     2
   //    /
   //   1
   //  /
   // 3 
    //int rob(TreeNode* root) {
      //vector<int> money(2);
      //if(root){
        //traverse(root,1,money);
      //}
      //return max(money[0],money[1]);
    //}
    //void traverse(TreeNode* node,int level,vector<int>& money){
      //if(node->right) traverse(node->right,level+1,money);
      //if(node->left) traverse(node->left,level+1,money);
      //money[level & 0x1] += node->val;
    //}
    int rob(TreeNode* root){
        vector<int> ret(robSub(root));
      return max(ret[0],ret[1]);

    }
 private:
    vector<int> robSub(TreeNode* node){
      vector<int>  ret(2);
      if(node != NULL){
        vector<int> left(robSub(node -> left));
        vector<int> right(robSub(node->right));

        ret[0] = max(left[0],left[1]) + max(right[0],right[1]);
        ret[1] = node->val + left[0] + right[0];
      }
      return ret;
    }
};
int main(){
  Solution sol;
}
