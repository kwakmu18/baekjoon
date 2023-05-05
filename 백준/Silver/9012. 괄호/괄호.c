#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __top {
    struct __node *node;
}Stack;

typedef struct __node {
    int data;
    struct __node *next;
} Node;

void init(Stack *top) {
    top->node=NULL;
}

void push(Stack *top, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top->node;
    top->node = newNode;
}

int is_empty(Stack *top) {
    if (top->node == NULL) return 1;
    else return 0;
}

int pop(Stack *top) {
    if (is_empty(top)) {
        printf("스택이 비어 있음\n");
        return -1;
    }
    else {
        Node *temp = top->node;
        int return_data = temp->data;
        top->node = temp->next;
        free(temp);
        return return_data;
    }
}

int get_top(Stack *top) {
    if (is_empty(top)) {
        printf("스택이 비어 있음\n");
        return -1;
    }
    else return (top->node)->data;
}

void print_stack(Stack *top) {
    if (is_empty(top)) {
        printf("스택이 비어 있음\n");
        return;
    }
    Node *temp = top->node;
    printf("top -> ");
    while (temp) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        char line[50];
        scanf("%s", line);
        int line_length = strlen(line);
        int i, flag=1;
        Stack st;
        init(&st);
        for(i=0;i<line_length;i++) {
            if (line[i]=='(') push(&st, '(');
            else {
                if (is_empty(&st)) {
                    flag=0;
                    break;
                }
                else pop(&st);
            }
        }
        if (flag && is_empty(&st)) printf("YES\n");
        else printf("NO\n");
    }
}