#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n, i, top, area = 0, maxArea = -1;
    cin >> n;
    int histogram[n];
    for(int i = 0;i < n;i++)
        cin >> histogram[i];
    stack<int> st;
    for(i = 0;i < n;){
        if(st.empty() || histogram[st.top()] <= histogram[i])
            st.push(i++);
        else{
            top = st.top();
            st.pop();
            area = histogram[top] * (st.empty() ? i : i - st.top() - 1);
            maxArea = max(area, maxArea);
        }
    }
    while(!st.empty()){
        top = st.top();
        st.pop();
        area = histogram[top]*(st.empty() ? i : i - st.top() - 1);
        maxArea = max(area, maxArea);
    }
    cout << maxArea << endl;
}