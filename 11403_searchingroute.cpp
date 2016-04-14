#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[111][111];
int exist[111][111];
int check[111];
int n = 0;

void dfs(int start, int x){

	if(exist[start][x] == 1) return;
	check[x] = 1;
	printf("%d %d\n", start, x);
	for(int i = 1; i <= n ; i++){
		int y = a[x][i];

		if( i == start && check[i] == 1){
			exist[start][i] = 1;
		}

		if( y == 1 && check[i] == 0){
			exist[x][i] = 1;
			exist[start][i] = 1;
			check[i] = 1;

			dfs(start, i);
			check[i] = 0;
		}
	}
	check[x] = 0;
}

int main(void) {
	n = 0;
	for(int i = 0 ; i < 111 ; i++){
		for(int j = 0; j < 111 ; j++){
			a[i][j] = 0;
			exist[i][j] = 0;
		}
	}
	for(int i = 0 ; i < 111 ; i++){
		check[i] = 0;
	}

	scanf("%d", &n);
	
	for(int i = 1; i <= n ; i++ ){
		for(int j = 1; j<= n ; j++){
			scanf("%1d", &a[i][j]);
		}
	}

	for(int i = 1; i <= n ; i++ ){
		dfs(i,i);
	}

	for(int i = 1; i <= n ; i++){
		for(int j = 1; j<= n; j++){
			printf("%d ", exist[i][j]);
		}
		printf("\n");
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
