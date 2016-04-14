#include<iostream>
#include <queue>
#include<string.h>

//using bfs

using namespace std;

int map[60][60];
int check[60][60];
int iCnt = 0;
int w, h;
queue<int> qR;
queue<int> qC;
int dirR[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirC[8] = {0, 1, 1, 1, 0, -1, -1, -1};


void bfs(int r, int c){
	if(map[r][c] == 0 || check[r][c] == 1) { return; }
	qR.push(r); qC.push(c);
	check[r][c] = 1;
	int curR;
	int curC;
	int nextR, nextC;

	while(!qR.empty()){
		curR = qR.front(); qR.pop();
		curC = qC.front(); qC.pop();
		
		for(int i = 0 ; i<8; i++){
			nextR = curR + dirR[i];
			nextC = curC + dirC[i];

			if((nextR < 1) || (nextR > h) || (nextC < 1) || (nextC > w)){ //경계 처리
				continue;
			}

			if( map[nextR][nextC] == 1 && check[nextR][nextC] == 0){
				qR.push(nextR);
				qC.push(nextC);
				check[nextR][nextC] = 1;
			}
		}
	}
	iCnt++;
}

int main(void){
	for(int i = 0; i< 60; i++){
		memset(map[i], 0, 60);
		memset(check[i], 0 ,60);
	}

	iCnt = 0;
	w = h = 0;
    

	scanf("%d %d", &w, &h);
	
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(check[i][j] == 0)
				bfs(i, j);
		}
	}

	printf("%d\n", iCnt);

	return 0;
}
