#include <iostream>
#include <queue>

//with BFS

using namespace std;

queue<int> qx;
queue<int> qy;

int map[111][111];
int check[111][111];
int dirR[4] = {-1, 1, 0, 0}; //상하좌우 순
int dirC[4] = {0, 0, -1 , 1};


void bfs(int r, int c, int n, int m){

	//q.push(p1);
	qx.push(r);
	qy.push(c);
	//check[p1.x][p1.y] = 1;
	check[r][c] = 1;

	while(!qx.empty()){
		int nowR = qx.front();
		int nowC = qy.front();
		//q.pop();
		qx.pop();
		qy.pop();

		for(int i = 0 ; i < 4 ; i++){
			//pos nextP;
			int nextR = nowR + dirR[i];
			int nextC = nowC + dirC[i];
			//if(nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) continue;//********* 이런 인덱스빠져나가지 않는 조건이 필요하다
			//if(map[nextR][nextC] == 1 && (check[nextR][nextC] == 0 || check[nextR][nextC] > check[nowR][nowR] + 1)){
			//check[nextR][nextC] > check[nowR][nowR] + 1  //위의 조건중 이 조건은 DFS시에 꼭 해줘야하는 조건이다.
			//다음칸으로 가야하는데, 자신의 현재 위치에서 1을 더한것보다 클때만 가줘야한다.
			//같거나 작을때 가주면
			if((nextR < 1 || nextR > n) || (nextC < 1 || nextC > m)){//이런 좌표이탈 체크도 해줘야 시간초과가 안뜬다
				continue;
			}
			if(map[nextR][nextC] == 1 && check[nextR][nextC] == 0){
				check[nextR][nextC] = check[nowR][nowC] + 1;
				qx.push(nextR);
				qy.push(nextC);
			}
		}
	}
}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int n, m; 
		int cnt = 0;
		for(int i = 0; i < 111; i++){
			for(int j = 0; j < 111; j++){
				map[i][j] = 0;
			}
		}

		for(int i = 0; i < 111; i++){
			for(int j = 0; j < 111; j++){
				check[i][j] = 0;
			}
		}

		scanf("%d %d", &n , &m);

		for(int i = 1; i <= n ; i++ ){
			for(int j = 1; j <= m ; j++){
				scanf("%1d", &map[i][j]);
			}
		}

		bfs(1,1, n, m);

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("%d\n", check[n][m]);

	return 0;   // 정상종료 시 반드시 0을 리턴해야 합니다.
}
