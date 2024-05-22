#include <stdio.h>
#include <stdlib.h>

int visited[100],ad[100][100];
int n;

void bfs(int start) {
    int q[100],i,k,front = -1, rear = -1;
    for(k = 0; k < n; k++) {
        visited[k] = 0;
    }
    q[++rear] = start;
    front++;
    visited[start] = 1;
    while(rear >= front) {
        start = q[front++];
        printf("%d ",start);
        for(i = 0; i < n; i++) {
            if(ad[start][i] == 1 && visited[i] == 0 ) {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start) {
    int stack[100], top = -1;
    for(int k = 0; k < n; k++) {
        visited[k]=0;
    }
    stack[++top] = start;
    visited[start] = 1;
    while(top != -1) {
        start = stack[top--];
        printf("%d ",start);
        for(int i=0;i<n;i++){
            if(ad[start][i]==1&&visited[i]==0){
                stack[top+1] = i;
                visited[i] = 1;
    }
    }

    }
}
int main() {
    int i,j,s;
    printf("Enter vertices no:");
    scanf("%d",&n);
    printf("Enter source vertex: ");
    scanf("%d", &s);
    printf("Enter adjacent matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
    {
        scanf("%d",&ad[i][j]);
    }
    }
    printf("bfs:");
    bfs(s);
    printf("dfs:");
    dfs(s);
    return 0;
}
