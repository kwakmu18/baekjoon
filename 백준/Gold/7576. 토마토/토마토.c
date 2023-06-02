#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
    int time;
}Point;

typedef struct Node {
    Point *p;
    struct Node *bef;
    struct Node *next;
}Node;

typedef struct Queue {
    struct Node *front;
    struct Node *rear;
}Queue;

void init(Queue *);
int is_empty(Queue *);
void enqueue(Queue *, Point *);
Point *dequeue(Queue *);

int N, M, V, A, B;
int **tomato;
int **time;
int ans;

int pos[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void bfs(Queue *q) {
    int i,j;
    while (!is_empty(q)) {
        Point *now = dequeue(q);
        int nowX = now->x, nowY = now->y, nowTime = now->time;
        if (time[nowY][nowX]<nowTime) continue;
        for(i=0;i<4;i++) {
            int newX = nowX+pos[i][0], newY=nowY+pos[i][1], newTime=nowTime+1;
            if (newX>=0 && newY>=0 && newX<M && newY<N && tomato[newY][newX]==0 && time[newY][newX]>newTime) {
                time[newY][newX]=newTime;
                tomato[newY][newX]=1;
                ans=newTime;
                Point *p = (Point *)malloc(sizeof(Point));
                p->x = newX; p->y = newY; p->time = newTime;
                enqueue(q, p);
            }
        }
        free(now);
    }
}

int main(void) {
    Queue q;
    init(&q);
    int i,j,flag=1;
    scanf("%d %d", &M, &N);
    tomato = (int **)malloc(sizeof(int *)*N);
    time = (int **)malloc(sizeof(int *)*N);
    for(i=0;i<N;i++) {
        time[i] = (int *)malloc(sizeof(int)*M);
        tomato[i] = (int *)malloc(sizeof(int)*M);
        for(j=0;j<M;j++) {
            scanf("%d", &tomato[i][j]);
            if (tomato[i][j]==1) {
                Point *p = (Point *)malloc(sizeof(Point));
                p->x = j; p->y = i; p->time = 0;
                enqueue(&q,p);
                time[i][j]=0;
            }
            else time[i][j]=987654321;
        }
    }
    bfs(&q);
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            if (tomato[i][j]==0) {
                flag=0;
                break;
            }
        }
        if (!flag) break;
    }
    if (flag) printf("%d", ans);
    else printf("-1");
}

void init(Queue *q) {
    q->front=NULL;
    q->rear=NULL;
}

int is_empty(Queue *q) {
    return (q->front==NULL && q->rear==NULL);
}

void enqueue(Queue *q, Point *p) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->p = p;
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

Point *dequeue(Queue *q) {
    Point *ret = (Point *)malloc(sizeof(Point));
    ret->x = q->front->p->x;
    ret->y = q->front->p->y;
    ret->time = q->front->p->time;
    if (q->front==q->rear) {
        free(q->front);
        q->front=NULL;
        q->rear=NULL;
    }
    else {
        Node *temp = q->front;
        q->front=temp->bef;
        q->front->next = NULL;
        free(temp);
    }
    return ret;
}