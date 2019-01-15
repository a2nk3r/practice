#include<iostream>
#include<stack>
using namespace std;
void okay(int i){
    cout << "okay:" << i << endl;
}
int main(){
    int n;
    stack<int> st;
    cin >> n;
    int prices[n], span[n];
    for(int i = 0;i < n;i++)
        cin >> prices[i];
    st.push(0);
    span[0] = 1;
    for(int i = 1;i < n;i++){
        while(!st.empty() && prices[i] > prices[st.top()])
            st.pop();
        span[i] = (st.empty()) ? i+1 : i - st.top();
        st.push(i);
    }
    for(int i = 0;i < n;i++)
        cout << span[i] << " ";
    cout << endl;
    
}