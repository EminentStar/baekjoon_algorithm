//
//  main.cpp
//  baekjoon_2667_votePresident
//
//  Created by EminentStar on 2016. 4. 16..
//  Copyright © 2016년 EminentStar. All rights reserved.
//

//baekjoon_2667 vote president
//floyd-warshall algorithms


#include <iostream>
#include <string.h>

using namespace std;

int N = 0;
int a[51][51];
int capt[51];
int minVal = 987654321;
int cCnt = 0;
int cSorted[51] = {0,};
int cSortedCnt = 0;


int main(void) {
    N = 0;
    for(int i = 0 ; i < 51; i++){
        memset(a[i], 0, 51);
    }
    scanf("%d", &N);
    
    while(true){
        int u,v;
        scanf("%d %d", &u, &v);
        if((u == -1) && (v == -1))
            break;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    
    for(int k = 1 ; k <= N; k++){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                if(a[i][k] != 0 && a[k][j] != 0)
                    if(a[i][j] > a[i][k] + a[k][j])
                        a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
    
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j<+ N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 1; i <= N; i++){
        int max = a[i][1];
        for(int j = 2; j <= N ; j++){
            if(i == j)
                continue;
            if(max > a[i][j])
                max = a[i][j];
        }
        if(minVal > max)
            minVal = max;
        capt[i] = max;
    }
    
    for(int i = 1; i <= N ; i++){
        if(capt[i] == minVal){
            cCnt++;
            cSorted[cSortedCnt++] = i;
        }
    }
    
    printf("%d %d\n", minVal, cCnt);
    for(int i = 0 ; i < cCnt ; i++)
        printf("%d ", cSorted[i]);
    
    
    return 0;
}
