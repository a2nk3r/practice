#include<iostream>
using namespace std;
int main(){
    int n, res;
    cin >> n;
    int cat[n] = {0};
    cat[0] = 1;
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j <= i;j++){
            cat[i+1] += cat[j]*cat[i-j];
        }
    }
    for(int i = 0;i < n;i++)
        cout << cat[i] << " ";
    cout << endl;
}