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

void BFS(int n) {
    int queue[MAX], visited[MAX] = {0};
    int front = -1, rear = -1;

    queue[++rear] = n;
    visited[n] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int curr = queue[++front];  
        printf("%d ", curr);
        for (int i = 0; i < MAX; i++) {
            if (arr[curr][i] == 1 && visited[i]!=1) {
                queue[++rear] = i; 
                visited[i] = 1;
            }
        }
    }
    printf("\n");
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
    BFS(2);
    display();
    return 0;
}
