#include <stdio.h>
#define MAX_SIZE 100001

typedef struct heap {
    int data[MAX_SIZE];
    int data_cnt;
}Heap;

void init(Heap *h) {
    h->data_cnt = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapInsert(Heap *h, int data) {
    if (h->data_cnt>=MAX_SIZE) {
        printf("데이터 수 초과\n");
        return;
    }
    h->data_cnt++;

    int newIndex = h->data_cnt;
    h->data[newIndex] = data;

    while (newIndex>=2 && h->data[newIndex]<=h->data[newIndex/2]) {
        swap(&(h->data[newIndex]), &(h->data[newIndex/2]));
        newIndex/=2;
    }
}

int heapDelete(Heap *h) {
    if (h->data_cnt==0) {
        return 0;
    }
    else if (h->data_cnt==1) {
        h->data_cnt--;
        return h->data[1];
    }
    int retValue = h->data[1];
    swap(&(h->data[1]), &(h->data[h->data_cnt]));
    int parent = 1;
    h->data_cnt--;
    while (1) {
        int leftChild = parent*2, rightChild = parent*2+1;
        if (rightChild<=h->data_cnt) {
            if (h->data[parent]<h->data[rightChild] && h->data[parent]<h->data[leftChild]) break;
            if (h->data[rightChild]<h->data[leftChild]) {
                swap(&(h->data[rightChild]), &(h->data[parent]));
                parent = rightChild;
            }
            else {
                swap(&(h->data[leftChild]), &(h->data[parent]));
                parent = leftChild;
            }
        }
        else if (leftChild<=h->data_cnt) {
            if (h->data[leftChild]<h->data[parent]) {
                swap(&(h->data[leftChild]), &(h->data[parent]));
                parent = leftChild;
            }
            else break;
        }
        else break;
    }

    return retValue;
}

int main(void) {
    Heap h;
    init(&h);

    int N;
    scanf("%d", &N);

    int input;
    while (N--) {
        scanf("%d", &input);
        if (input==0) {
            int pop = heapDelete(&h);
            if (pop==-1) printf("0\n");
            else printf("%d\n", pop);
        }
        else heapInsert(&h, input);
    }
}