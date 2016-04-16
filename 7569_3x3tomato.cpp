//
//  main.cpp
//  baekjoon_7569_tomato33
//
//  Created by EminentStar on 2016. 4. 16..
//  Copyright © 2016년 EminentStar. All rights reserved.
//

// baekjoon 7569 3-dimensional tomato
//with BFS
// 1:12:00 소요
/*
    해맸던 이유들
    1. 입력받을 배열의 row, column, height를 헷갈리게 입력받았다.
    2. 비교 조건이나 연산시 map과 step을 착각하여 바꿔 넣었다.
    3. 전체 탐색 후 마지막으로 덜익은게 있는지 확인할 때 break를 햇으면안됬었다..
        혹시 break를 했었더라면
        결과 출력시 isWholeRiped ==false 인 분기부터 먼저 타고 들어가도록 했어야했다.
 */

#include <iostream>
#include <string.h>
#include <queue>
#define INF -987654321

using namespace std;

int N, M, H;
int map[101][101][101];
int step[101][101][101];
queue<int> qR, qC, qH;
int minVal;

int dirR[6] = { 0, 0, 0, 0, 1, -1 };
int dirC[6] = { 0, 0, -1, 1, 0, 0 };
int dirH[6] = { -1, 1, 0, 0, 0, 0 };

void bfs(){
    int curR, curC, curH;
    int nextR, nextC, nextH;
    
    while(!qR.empty()){
        curR = qR.front(); qR.pop();
        curC = qC.front(); qC.pop();
        curH = qH.front(); qH.pop();
        
        for(int i = 0 ; i < 6 ; i++){
            nextR = curR + dirR[i];
            nextC = curC + dirC[i];
            nextH = curH + dirH[i];
            if((nextR < 1) ||(nextR > N) ||(nextC < 1) ||(nextC > M) ||(nextH < 1) ||(nextH > H)) //out of boundary
                continue;
            if(map[nextR][nextC][nextH] == -1) // empty position
                continue;
            if(step[nextR][nextC][nextH] == 0 ||(step[nextR][nextC][nextR] != 0 && (step[nextR][nextC][nextH] > step[curR][curC][curH] + 1))){ //unriped OR next riped days are longer than current riped day + 1
                step[nextR][nextC][nextH] = step[curR][curC][curH] + 1;
                qR.push(nextR);
                qC.push(nextC);
                qH.push(nextH);
            }
        }
    }
}


int main(void) {
    N = M = H = 0;
    minVal = INF;
    for(int i = 0 ; i< 101; i++){
        for(int j = 0 ; j <101 ; j++){
            memset(map[i][j], 0 , 101);
        }
    }
    
    scanf("%d %d %d", &M, &N, &H);
    
    for(int i = 1 ; i<= H; i++){
        for(int j = 1 ; j <= N ; j++){
            for(int k = 1 ; k <= M ; k++){
                scanf("%d", &map[j][k][i]);
                if(map[j][k][i] == 1){
                    qR.push(j);
                    qC.push(k);
                    qH.push(i);
                }
                step[j][k][i] = map[j][k][i];
            }
        }
    }
    
    bfs();
    
    bool isWhileRiped = true;
    
    for(int i = 1; i <= H ; i++){
        for(int j = 1; j <= N ; j++){
            for(int k = 1; k <= M ; k++){
                if(minVal < step[j][k][i])
                    minVal = step[j][k][i];
                if(step[j][k][i] == 0){
                    isWhileRiped = false;
                    //break;
                }
            }
        }
    }
    
    if(isWhileRiped)
        printf("%d\n", minVal - 1);
    else
        printf("-1\n");
    
    return 0;
}
