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

class MinStack{
 private:
      stack<int> st;
      stack<int> min_ele;
  public:

    void push(int x) {
      st.push(x);
      if(!min_ele.empty()){
        min_ele.push(min(min_ele.top(),x));
      }
      else{
        min_ele.push(x);
      }
    }
    
    void pop() {
      st.pop();
      min_ele.pop();
    }
    
    int top() {
      return st.top();
    }
    
    int getMin() {
      return min_ele.top();
    }
};

int main(){
  MinStack minStack = new MinStack();
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  minStack.getMin();  // --> Returns -3.
  minStack.pop();
  minStack.top();  //    --> Returns 0.
  minStack.getMin();   //--> Returns -2.
}
