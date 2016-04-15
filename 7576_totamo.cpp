//
//  main.cpp
//  baekjoon_7576_tomato_bfs
//
//  Created by EminentStar on 2016. 4. 16..
//  Copyright © 2016년 EminentStar. All rights reserved.
//
/*
 오답노트:
 -1로 초기화하지말자(by 대호형.. 뭔가 이유가 있었던 것같다.)
 맵을 입력받을때 check에도 덮어씌우자
 
 틀린이유가 아마, check초기화를 -1로 하는데, 이게,, 탐색돌면서 안익은건 -1이 다른거로 바뀐다.
 그런데 인접한 익은 토마토가 없는 안익은 토마토는 탐색종료후에도 -1이 되게 된다.
 이것은 텅빈 곳과 값이 같게되고,, 마지막에 안익은걸 체크할때 텅빈곳과 값이 같게 된다.(-1)
 */


#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int map[1001][1001];
int check[1001][1001];
int N, M;
queue<int> qR, qC;
int dirR[4] = {-1, 1, 0, 0};
int dirC[4] = {0, 0, -1, 1};

int main(void) {
    int isCompleted = true;
    for(int i = 0; i < 1001 ;i++){
        memset(map[i], 0, 1001);
        //memset(check[i], -1, 1001);
        memset(check[i], 0, 1001);
    }
    N = M = 0;
    scanf("%d %d", &M, &N);
    
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= M; j++){
            scanf("%d", &map[i][j]);
            check[i][j] = map[i][j];
            if(map[i][j] == 1){
                qR.push(i);
                qC.push(j);
            }
        }
    }

    //BFS
    while(!qR.empty()){
        int curR = qR.front(); qR.pop();
        int curC = qC.front(); qC.pop();
        int nextR, nextC;
        
        /*
        if(check[curR][curC] == -1){
            check[curR][curC] = 0;
        }
         */
         
        for(int i = 0; i<4 ; ++i){
            nextR = curR + dirR[i];
            nextC = curC + dirC[i];
            
            if( nextR < 1 || nextR > N || nextC < 1 || nextC > M ) //out of boundary
                continue;
            if(map[nextR][nextC] == -1) //no tomato
                continue;
             
            //if(check[nextR][nextC] == -1 || (check[nextR][nextC] != -1 &&(check[nextR][nextC] > check[curR][curC] + 1))){ //틀린조건?
            if(map[nextR][nextC] == 0 && (check[nextR][nextC] == 0 || check[nextR][nextC] > check[curR][curC] + 1)){
                check[nextR][nextC] = check[curR][curC] + 1;
                qR.push(nextR); qC.push(nextC);
            }
        }
    }
    
    int totalDay = 1;
    //find the total days
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(check[i][j] > totalDay)
                totalDay = check[i][j];
            //if(map[i][j] == -1) //이게 문제였다...******** map은 그냥 토마토가 잇는지 없는지 익엇는지를 나타낸다..
            if(check[i][j] == 0)
                isCompleted = false;
        }
    }

    if(isCompleted)
        printf("%d\n", totalDay - 1 );
    else
        printf("-1\n");
    
    return 0;
}
