#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *bef;
    struct Node *next;
}Node;

typedef struct Queue {
    struct Node *front;
    struct Node *rear;
    int cnt;
}Queue;

void init(Queue *);
int is_empty(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);

int N, M, V, A, B;
int **edge;
int *visited;

void dfs(int now) {
    visited[now]=1;
    int i;
    printf("%d ", now+1);
    for(i=0;i<N;i++) {
        if (edge[now][i]==1 && visited[i]==0) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    int i;
    Queue q;
    init(&q);
    enqueue(&q, start);
    while (!is_empty(&q)) {
        int now = dequeue(&q);
        if (visited[now]) continue;
        visited[now]=1;
        printf("%d ", now+1);
        for(i=0;i<N;i++) {
            if (!edge[now][i] || visited[i]) continue;
            enqueue(&q, i);
        }
    }
}

int main(void) {
    int i,j;
    scanf("%d %d %d", &N, &M, &V);
    edge = (int **)malloc(sizeof(int *)*N);
    visited = (int *)malloc(sizeof(int)*N);
    for(i=0;i<N;i++) {
        visited[i] = 0;
        edge[i] = (int *)malloc(sizeof(int)*N);
        for(j=0;j<N;j++) edge[i][j]=0;
    }
    for(i=0;i<M;i++) {
        scanf("%d %d", &A, &B);
        edge[A-1][B-1]=1;
        edge[B-1][A-1]=1;
    }
    dfs(V-1);
    printf("\n");
    for(i=0;i<N;i++) visited[i] = 0;
    bfs(V-1);
}

void init(Queue *q) {
    q->front=NULL;
    q->rear=NULL;
}

int is_empty(Queue *q) {
    return (q->front==NULL && q->rear==NULL);
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->bef = NULL;
    if (is_empty(q)) {
        q->front=newNode;
        q->rear=newNode;
    }
    else {
        q->rear->bef = newNode;
        newNode->next = q->rear;
        q->rear=newNode;
    }
}

int dequeue(Queue *q) {
    int data;
    if (q->front==q->rear) {
        data = q->front->data;
        free(q->front);
        q->front=NULL;
        q->rear=NULL;
    }
    else {
        data = q->front->data;
        Node *temp = q->front;
        q->front=temp->bef;
        q->front->next = NULL;
        free(temp);
    }
    return data;
}