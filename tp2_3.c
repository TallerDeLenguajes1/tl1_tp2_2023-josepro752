#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7

int main () {
    int i,j;
    int mt[N][M];
    int (*p_i)[M] = mt;
    int (*p_j) = *p_i;
    srand(time(NULL));
    for(i = 0;i<N; i++) {
        for(j = 0;j<M; j++) {
            *(p_j)=1+rand()%100;
            printf("%d ", *(p_j));
            p_j++;
        }
        p_i++;
        printf("\n");
    }
    return 0;
}
