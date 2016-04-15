#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

//11403 경로 찾기
//with Floyd 마샬 algorithm

/*
//floyd marshall algorithm의 구현
//정점의 개수
int V;
//그래프의 인접 행렬 표현
//adj[u][v] = u 에서 v로가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
int adj[MAX_V][MAX_V];
//플로이드의 모든 쌍 최단 거리 알고리즘 (책 p950)
//모든 쌍 간의 최단 거리를 구하고 싶다면 
void floyd(){
	for(int i = 0; i < V; ++i) adj[0][0] = 0;
	
	for(int k = 0; k < V; ++k){
		for(int i = 0; i < V ; ++i ){
			for(int j = 0; j < V ; ++j){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}
*/

int a[111][111];
int exist[111][111];
int check[111];
int N = 0;


int main(void) {
	N = 0;
	for(int i = 0 ; i < 111 ; i++){
		for(int j = 0; j < 111 ; j++){
			a[i][j] = 0;
			exist[i][j] = 0;
		}
	}
	for(int i = 0 ; i < 111 ; i++){
		check[i] = 0;
	}

	scanf("%d", &N);
	
	for(int i = 1; i <= N ; i++ ){
		for(int j = 1; j<= N ; j++){
			scanf("%1d", &a[i][j]);
		}
	}

	for(int k = 1 ; k <= N ; k++){
		for( int i = 1; i <= N ; i++){
			for(int j = 1; j <= N ; j++){
				if(a[i][k] == 1 && a[k][j] == 1)
					a[i][j] = 1;
					
			}
		}
	}


	for(int i = 1; i <= N ; i++){
		for(int j = 1; j<= N; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
