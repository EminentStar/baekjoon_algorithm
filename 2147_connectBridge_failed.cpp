//
//  main.cpp
//  baekjoon_2146_connectBridge
//
//  Created by EminentStar on 2016. 4. 17..
//  Copyright © 2016년 EminentStar. All rights reserved.
//

//baekjoon 2146 다리만들기
//with dfs
/*
 
    왜안되지..? 하아,,,
 */

#include <iostream>
#include <string.h>

#define INF 987654321

using namespace std;

int N;
int a[111][111];
bool check[111][111];
int mStep[111][111];
int dirR[4] = {-1, 1, 0, 0};
int dirC[4] = {0, 0, -1, 1};
int minStep;
int cnt;

void countDfs(int r, int c, int num){
    int nextR, nextC;
    
    a[r][c] = num;
    check[r][c] = true;
    
    for(int i = 0 ; i < 4 ; i++){
        nextR = r + dirR[i];
        nextC = c + dirC[i];
        
        if(nextR < 1 || nextR > N || nextC < 1 || nextC > N) //out of boundary
            continue;
        if(a[nextR][nextC] == 0) //not LAND
            continue;
        if(check[nextR][nextC] == false)
            countDfs(nextR, nextC, num);
    }
}

void stepDfs(int r, int c, int num, int step){
    //check[r][c] = true;
    
    if(a[r][c] != 0 && a[r][c] != num){
        if(minStep > step - 1){
            minStep = step - 1;
        }
        return;
    }
    
    int nextR, nextC;
    for(int i = 0; i< 4 ; i++){
        nextR = r + dirR[i];
        nextC = c + dirC[i];
        
        if(nextR < 1 || nextR > N || nextC < 1 || nextC > N) //out of boundary
            continue;
        if(a[nextR][nextC] == num)
            continue;
        
        if(check[nextR][nextC] == false || (check[nextR][nextC] == true && mStep[nextR][nextC] > step + 1) ){
            check[nextR][nextC] = true;
            mStep[nextR][nextC] = step + 1;
            stepDfs(nextR, nextC, num, step + 1);
        }
    }
    
    //check[r][c] = false;
}

int main(int argc, const char * argv[]) {
    N = cnt = 0;
    minStep = INF;
    for(int i = 0; i < 101; i++){
        memset(a[i], 0, 101);
        memset(check[i], false, 101);
    }
    
    scanf("%d", &N);
    
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(a[i][j] != 0 && check[i][j] == false)
                countDfs(i, j, ++cnt);
        }
    }
    
    //check initialize
    for(int i = 1; i <= N; i++){
        memset(check[i], false, N);
    }
    
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            if(a[i][j] != 0){
                mStep[i][j] = 0;
                stepDfs(i, j, a[i][j], 0);
            }
        }
    }
    
    /*
    printf("\n---------------\n");
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n---------------\n");
    for(int i = 1; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            printf("%d ", mStep[i][j]);
        }
        printf("\n");
    }
    */
    if(minStep ==INF)
        printf("0\n");
    else
        printf("%d\n", minStep);
    
    
    return 0;
}
