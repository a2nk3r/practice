#include<iostream>
#include<stack>
using namespace std;
stack<int> st, minst;
void Push(int x){
    if(st.empty()){
        st.push(x);
        minst.push(x);
    }else{
        st.push(x);
        minst.push((x < minst.top() ? x : minst.top()));
    }
}
void Pop(){
    if(!st.empty() || !minst.empty()){
        st.pop();
        minst.pop();
    }
}
int getTop(){
    return st.top();
}
int getMin(){
    return minst.top();
}
int main(){
    int n, x;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> x;
        Push(x);
    }
    for(int i = 0;i < n;i++){
        cout << getTop() << " " << getMin() << endl;
        Pop();
        
    }
}