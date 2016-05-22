#include <cstdio>
#include <iostream>

/*
 * 10844: 쉬운계단수 (DP)
 */

using namespace std;

int N;
int d[101][11] = {0,};
int mod = 1000000000;

int main(void){
	scanf("%d", &N);
	
	for(int i = 1; i < 10; i++)
		d[1][i] = 1;
	
	for(int i = 2; i <= N ; i++){
		for(int k = 0; k <= 9; k++){
			d[i][k] = d[i-1][k+1]+ d[i-1][k-1];
			d[i][k] %= mod;
		}
	}

	long long ans = 0;

	for(int i = 0; i < 10; i++){
		ans += d[N][i];
	}

	ans %= mod;

	printf("%d\n", ans);
	

	return 0;
}
