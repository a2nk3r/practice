// giving wrong output
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    int gold[m][n];
    for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
            cin >> gold[i][j];

    int goldMine[m][n];
    memset(goldMine, 0, sizeof(goldMine));

    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j < m;j++){
            int right = (i == n-1) ? 0 : goldMine[j][i+1];
            int right_up = (i == n-1 || j == 0) ? 0 : goldMine[j-1][i+1];
            int right_down = (i == n-1 || j == m-1) ? 0 : goldMine[j+1][i+1];
            goldMine[i][j] = gold[i][j] + max(right, max(right_up, right_down));
        }
    }

    cout << "------------------------" << endl;

    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cout << goldMine[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
    int res = goldMine[0][0];
    for(int i = 1;i < m;i++)
        res = max(res, goldMine[i][0]);
    cout << res << endl;
}