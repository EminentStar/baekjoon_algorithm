#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int map[26][26] = {0,};
int check[26][26] = {0, };
int dirR[4] = {-1, 1, 0, 0};
int dirC[4] = {0, 0, -1, 1};
int sCnt; //단지 개수
int set[1001] = {0, };
queue<int> qR, qC;
int N = 0;


void bfs(int r, int c){
	if(check[r][c] == 1)
		return;
	
	int curR, curC, hCnt = 0;
	qR.push(r);
	qC.push(c);

	while(!qR.empty()){
		curR = qR.front(); qR.pop();
		curC = qC.front(); qC.pop();
		hCnt++;

		for(int i = 0; i < 4 ; i++){
			int nextR = curR + dirR[i];
			int nextC = curC + dirC[i];
			if( ( (nextR < 1) || (nextR > N) ) || ( (nextC < 1) || (nextC > N)  ) )
				continue;
			if(map[nextR][nextC] == 1 && check[nextR][nextC] == 0){
				qR.push(nextR);
				qC.push(nextC);
				check[nextR][nextC] = 1;
			}
		}
	}
	set[++sCnt] = hCnt;
}

int main(void){
	N = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N ; i++){
		for(int j = 1; j <= N ; j++){
			scanf("%1d",&map[i][j]);
		}
	}

	for(int i = 1; i <= N ; i++){
		for(int j = 1; j <= N ; j++){
			if(map[i][j] == 1)
				bfs(i, j);
		}
	}

	//bubble sort
	for(int i = 1; i <= N; i++){
		for(int k = 1 ; k <= N ; k++){
			if(set[k] > set[k+1]){
				int temp = set[k];
				set[k] = set[k+1];
				set[k+1] = temp;
			}
		}
	}

	for(int i = 1; i <= sCnt ; i++){
		printf("%d\n", set[i]);
	}

	return 0;
}
