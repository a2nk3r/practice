// Bell number using bell triangle
// counts the no. of ways to partition a set
/*
1
1 2
2 3 5
5 7 10 15
15 20 27 37 52
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int bell[n][n] = {0};
    bell[0][0] = 1;
    for(int i = 1;i < n;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0) bell[i][j] = bell[i-1][i-1];
            else bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
        }
    }
    for(int i = 0;i < n;i++)
        cout << bell[i][i] << " ";
    cout << endl;
}
