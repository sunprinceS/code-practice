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
  //private:
   //vector<pair<int,bool>> r_stack;
   //vector<pair<int,bool>> l_stack;
  //public:
    //bool isSymmetric(TreeNode* root) {
      //if(root == NULL || !root->left && !root->right) {return true;}
      //if((!root->left && root->right) || (!root->right && root->left)){
        //return false;
      //}
      //traverseL(root->left,true);
      //traverseR(root->right,true);
      //if(r_stack.size() != l_stack.size()) return false;
      //else{
        //for(size_t i=0;i<r_stack.size();++i){
          //if(r_stack[i] != l_stack[i])
            //return false;
        //}
        //return true;
      //}
    //}
    //void traverseL(TreeNode* node,bool bLeft){
      //l_stack.push_back({node->val,bLeft});
      //if(node->left) {traverseL(node->left,true);}
      //if(node->right) {traverseL(node->right,false);}
    //}
    //void traverseR(TreeNode* node,bool bRight){
      //r_stack.push_back({node->val,bRight});
      //if(node->right) {traverseR(node->right,true);}
      //if(node->left) {traverseR(node->left,false);}
    //}
    // iterative method: 其實沒有比較快 XD
 public:
    bool isSymmetric(TreeNode* root){
      TreeNode* l;
      TreeNode* r;
      if(!root) return true;
      
      queue<TreeNode*> ql,qr;
      ql.push(root->left);
      qr.push(root->right);
      while(!ql.empty() && !qr.empty()){
        l = ql.front();
        r = qr.front();

        ql.pop();
        qr.pop();
        if(l == NULL && r == NULL) {continue;}
        if(l == NULL || r == NULL) {return false};
        if(l->val != r-> val) {return false;}
        else{
          ql.push(l->left);
          ql.push(l->right);
          qr.push(r->right);
          qr.push(r->left);
        }
      }
      return (ql.empty() == qr.empty());
    }
};
int main(){
  Solution sol;
}
