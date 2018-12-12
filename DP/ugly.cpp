// Ugly Numbers

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, i2, i3, i5, next_m2, next_m3, next_m5, next_ugly;
    cin >> n;
    int ugly[n];
    ugly[0] = 1;
    i2 = i3 = i5 = 0;
    // 3 choices for next ugly number
    next_m2 = ugly[i2]*2;
    next_m3 = ugly[i3]*3;
    next_m5 = ugly[i5]*5;
    for(int i = 1;i < n;i++){
        next_ugly = min(next_m2, min(next_m3, next_m5));
        ugly[i] = next_ugly;
        if(next_ugly == next_m2){
            i2++;
            next_m2 = ugly[i2]*2;
        }
        if(next_ugly == next_m3){
            i3++;
            next_m3 = ugly[i3]*3;
        }
        if(next_ugly == next_m5){
            i5++;
            next_m5 = ugly[i5]*5;
        }
    }
    cout << next_ugly << endl;
}