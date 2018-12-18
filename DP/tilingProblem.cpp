// Given a “2 x n” board and tiles of size “2 x 1”,
// count the number of ways to tile the given board using the 2 x 1 tiles.
// A tile can either be placed horizontally i.e.,
// as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ways[n+1];
    ways[0] = 0;
    ways[1] = 1;
    ways[2] = 2;
    for(int i = 3;i <= n;i++)
        ways[i] = ways[i-1] + ways[i-2];
    
    cout << "No. of ways to tile: " << ways[n] << endl;
    
}