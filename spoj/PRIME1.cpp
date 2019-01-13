#include <bits/stdc++.h>
#define N 1000001
using namespace std;

int main() {
	int t, m, n;
	bool isPrime[N];
	memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
	for(int i= 2;i*i<=N;i++){
		if(isPrime[i]){
			for(int j = i*i;j<=N;j+=i)
				isPrime[j] = false;
		}
	}
	cin >> t;
	while(t--){
		cin >> m >> n;
		for(int i = m;i <= n;i++){
			if(isPrime[i]) cout << i << endl;
		}
		cout << endl;
	}
}