#include <stdio.h>
#include <stdlib.h>

typedef struct _bTreeNode {
	char data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
}BTreeNode;

void init(BTreeNode *root, char data) {
	root->data = data;
	root->left = NULL;
	root->right = NULL;
}

void makeLeftSubTree(BTreeNode *root, BTreeNode *left) {
	root->left = left;
}
void makeRightSubTree(BTreeNode *root, BTreeNode *right) {
	root->right = right;
}

void preOrderTraverse(BTreeNode *root) {
	if (root==NULL) return;
	printf("%c", root->data);
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}
void inOrderTraverse(BTreeNode *root) {
	if (root==NULL) return;
	inOrderTraverse(root->left);
    printf("%c", root->data);
	inOrderTraverse(root->right);
}
void postOrderTraverse(BTreeNode *root) {
	if (root==NULL) return;
	postOrderTraverse(root->left);
	postOrderTraverse(root->right);
    printf("%c", root->data);
}

int main(void) {
    int N;
    scanf("%d", &N);
    BTreeNode *nodes = (BTreeNode *)malloc(sizeof(BTreeNode)*N);
    for(int i=0;i<N;i++) init(&nodes[i], 'A'+i);

    for(int i=0;i<N;i++) {
        char root, left, right;
        scanf(" %c %c %c", &root, &left, &right);
        if (left!='.') makeLeftSubTree(&nodes[root-'A'], &nodes[left-'A']);
        if (right!='.') makeRightSubTree(&nodes[root-'A'], &nodes[right-'A']);
    }

    preOrderTraverse(&nodes[0]);
    printf("\n");
    inOrderTraverse(&nodes[0]);
    printf("\n");
    postOrderTraverse(&nodes[0]);
}