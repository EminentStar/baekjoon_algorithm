#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

//2589 보물섬
//with BFS

char map[51][51] = {0,} ;
int check[51][51] = {0,} ;
int t = 0;
int R, C;
int maxH = 0;
int maxR, maxC;
queue<int> qR, qC;
int dirR[4] = {-1, 1, 0, 0};
int dirC[4] = {0, 0, -1, 1};



void bfs(int r, int c){
    if(check[r][c] != 0) return;
    int cR ;
    int cC ;
    qR.push(r);
    qC.push(c);
    
    check[r][c] = 1;
    maxH = 1;
    maxR = r;
    maxC = c;
    
    while(!qR.empty()){
        cR = qR.front(); qR.pop();
        cC = qC.front(); qC.pop();
        //printf("(%d, %d)\n", cR, cC);
        
        for(int i = 0; i < 4 ; i++){
            int nR = cR + dirR[i];
            int nC = cC + dirC[i];
            printf(" -- (%d, %d) \n", nR, nC);
            if(( (nR < 0) || ( nR >= R)) || ( (nC < 0) || ( nC >= C)))
                continue;
            //if(map[nR][nC] == 'L' && (check[nR][nC] == 0 || check[nR][nC] > check[cR][cC] + 1 ) ){
            if(map[nR][nC] == 'L' && (check[nR][nC] == 0) ){
                check[nR][nC] = check[cR][cC] + 1;
                printf("(%d, %d)\n", nR, nC);
                qR.push(nR);
                qC.push(nC);
                if(maxH < check[nR][nC]){
                    maxH = check[nR][nC];
                    maxR = nR;
                    maxC = nC;
                }
                
            }
        }
        
        
        
    }
}

int main(void){
    int R, C;
    t = 0;
    
    for(int i = 0; i< 51 ; i++){
        memset(map[i], 0, 51);
        memset(check[i], 0, 51);
    }
    
    
    scanf("%d %d", &R, &C);
    
    for(int i = 0 ; i < R ; i++){
        scanf("%s", map[i]);

    }
    
    
    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j< C ; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < R ; i++){
         for(int j = 0; j < C ; j++){
             if(map[i][j] == 'L'){
                 bfs(i, j);
             }
         }
    }
    
    int newR = maxR;
    int newC = maxC;
    
    for(int i = 0; i < 51; i++){
        for(int j = 0; j < 51; j++){
            check[i][j] = 0;
        }
    }
    
    bfs(newR, newC);
    
    printf("%d\n", maxH);
    
    return 0;
}
