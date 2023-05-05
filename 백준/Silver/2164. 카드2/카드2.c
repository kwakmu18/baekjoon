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
    int data_cnt;
}Queue;

void init(Queue *q) {
    q->front=NULL;
    q->rear=NULL;
    q->data_cnt=0;
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
    q->data_cnt++;
}

int dequeue(Queue *q) {
    int data;
    if (is_empty(q)) {
        printf("큐가 비어 있음\n");
        return -1;
    }
    else if (q->front==q->rear) {
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
    q->data_cnt--;
    return data;
}

void show(Queue *q) {
    Node *temp = q->front;
    if (!temp) {
        printf("큐가 비어 있음");
        return;
    }
    printf("<front> ");
    while (temp) {
        printf("%d ", temp->data);
        temp=temp->bef;
    }
    printf("<rear>");
}

int main(void) {
    int N, i;
    scanf("%d", &N);
    if (N<=2) {
        printf("%d", N);
        return 0;
    }
    Queue q;
    init(&q);
    
    for(i=1;i<=N;i++) enqueue(&q, i);

    while (1) {
        if (q.data_cnt==1) {
            printf("%d", dequeue(&q));
            break;
        }
        dequeue(&q);
        int front = dequeue(&q);
        enqueue(&q, front);
    }
}