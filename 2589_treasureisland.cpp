#include<iostream>
#include<string.h>

using namespace std;

//2589 보물섬
//with BFS

char map[51][51] = {0,} ;
int check[51][51] = {0,} ;
int t = 0;

int main(void){
	int R, C;
	t = 0;

	for(int i = 0; i< 51 ; i++){
		memset(map[i], 0, 51);
		memset(check[i], 0, 51);
	}	


	scanf("%d %d", &R, &C);

	for(int i = 1 ; i <= R ; i++){
		for(int j = 1; j<= C ; j++){
			scanf("%1c", &map[i][j]);
		}
	}


	for(int i = 1 ; i <= R ; i++){
		for(int j = 1; j<= C ; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}	
	/*
	for(int i = 1; i <= R ; i++){
		for(int j = 1; j <= C ; j++){
			if(check[i][j] == 'L')
		}
	}
	*/


	return 0;
}
