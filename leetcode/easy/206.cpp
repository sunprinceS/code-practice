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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curNode = NULL;
        ListNode* nextNode = head;

        while( nextNode!= NULL){
          curNode = nextNode;
          nextNode = curNode -> next;
          curNode -> next = prev;
          prev = curNode;
        }
        return curNode;
    }
};

int main(){
  Solution sol;
}
