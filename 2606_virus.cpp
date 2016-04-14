#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

//2606 바이러스
//with DFS

vector<vector<int>> a(101);
int check[101] = {0,};
int vCnt = 0;
int N = 0;

void dfs(int x){
	check[x] = 1;
	vCnt++;

	for(int i = 0; i < a[x].size() ; i++){
		int y = a[x][i];
		if(check[y] == 0){
			dfs(y);
		}
	}
}

int main(void){
	N = 0;
	int M = 0;
	vCnt = 0;
	memset(check, 0, 101);

	scanf("%d", &N);
	scanf("%d", &M);
	for(int i = 0; i < M ; i++){
		int u,v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v); a[v].push_back(u);
	}

	dfs(1);
	
	printf("%d\n", vCnt - 1);

	return 0;
}
