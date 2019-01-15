#include<bits/stdc++.h>
using namespace std;
int findCandidate(vector<int> arr){
    int idx = 0, count = 1;
    for(int i = 0;i < arr.size();i++){
        count += (arr[i] == arr[idx]) ? 1 : -1;
        if(count == 0){
            idx = i;
            count = 1;
        }
    }
    return arr[idx];
}
bool isMajority(vector<int> arr, int candidate){
    int count = 0;
    for(int i = 0;i < arr.size();i++)
        count += (arr[i] == candidate) ? 1 : 0;
    if(count > arr.size()/2)
        return true;
    return false;
}
int main(){
    int n, x;
    cin >> n;
    vector<int> arr;
    for(int i = 0;i < n;i++){
        cin >> x;
        arr.push_back(x);
    }
    int candidate = findCandidate(arr);
    if(isMajority(arr, candidate))
        cout << candidate;
    else cout << "No majority element";
    cout << endl;
}