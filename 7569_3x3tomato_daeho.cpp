#include <iostream>
 
using namespace std;
 
int N, M, H;
int map[111][111][111];
int step[111][111][111];
int queueR[1111111];
int queueC[1111111];
int queueH[1111111];
int front = 0, rear = 0;
int dirR[6] = {-1, 0, 1, 0, 0, 0};
int dirC[6] = {0, 1, 0, -1, 0, 0};
int dirH[6] = {0, 0, 0, 0, 1, -1};
int maxVal = 1;
 
void bfs(){
 
 
 
 
 
    while(front<rear){
 
        int curR = queueR[front];
        int curC = queueC[front];
        int curH = queueH[front++];
 
        for(int u = 0; u<6; u++){
 
            int nextR = curR + dirR[u];
            int nextC = curC + dirC[u];
            int nextH = curH + dirH[u];
 
            if((nextR>=1 && nextR <=N) && (nextC>=1 && nextC<=M) && (nextH>=1 && nextH<=H)){
                if(map[nextR][nextC][nextH] == 0 && step[nextR][nextC][nextH] == 0){
 
                    step[nextR][nextC][nextH] = step[curR][curC][curH] + 1;
                    if(maxVal < step[nextR][nextC][nextH]) maxVal = step[nextR][nextC][nextH];
                    queueR[rear] = nextR;
                    queueC[rear] = nextC;
                    queueH[rear++] = nextH;
 
                }
            }
        }
    }
}
 
int main(){
 
    scanf("%d %d %d", &M, &N, &H);
 
    for(int a = 1; a<=H; a++){
        for(int b = 1; b<=N; b++){
            for(int c = 1; c<=M; c++){
                scanf("%d", &map[b][c][a]);
                if(map[b][c][a] == 1){
                    queueR[rear] = b;
                    queueC[rear] = c;
                    queueH[rear++] = a;
                }
                step[b][c][a] = map[b][c][a];
            }
        }
    }
 
    bfs();
 
    int flag = 0;
    for(int k = 1; k<=H; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=M; j++){
                if(step[i][j][k] == 0){
                    flag = 1;
                    break;
                }
            }
        }
    }
    if(flag == 0) printf("%d\n", maxVal-1);
    else printf("-1\n");
 
    return 0;
}
