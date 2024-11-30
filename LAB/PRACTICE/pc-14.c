#include <stdio.h>
#define MAX 2

int arr[MAX][MAX] = {0};

void create() {
    int temp;
    printf("Enter values:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &temp);
            arr[i][j] = temp;
        }
    }
}

void DFS(int n) {
    int i,j,top=-1;
    int visited[MAX]={0},stack[MAX];
    stack[++top]=n;
    visited[n]=1;
    while (top!=-1)
    {
        
    }
    
}

void display() {
    printf(" Matrix is:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    create();
    DFS(2);
    display();
    return 0;
}
