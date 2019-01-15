#include<iostream>
#include<queue>
using namespace std;
queue<int> q1, q2;
void Push(int x){
    if(!q1.empty())
        q1.push(x);
    else
        q2.push(x);
    cout << "pushed " << x << endl;
}
int Pop(){
    int t = -1;
    if(q1.empty()){
        if(q2.empty()){
            cout << "error: stack underflow" << endl;
            return t;
        }
        while(q2.size() != 1){
            t = q2.front();
            q2.pop();
            q1.push(t);
        }
        t = q2.front();
        q2.pop();
    }
    else{
        while(q1.size() != 1){
            t = q1.front();
            q1.pop();
            q2.push(t);
        }
        t = q1.front();
        q1.pop();
    }
    cout << "popped " << t << endl;
    return t;
}
int main(){
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    cout << Pop() << endl;
    cout << Pop() << endl;
    Push(6);
    cout << Pop() << endl;
    cout << Pop() << endl;
    cout << Pop() << endl;
    cout << Pop() << endl;
    cout << Pop() << endl;
}