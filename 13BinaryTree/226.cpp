//
// Created by WYR on 2025/2/22.
//
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
int n;
int a[1005];
TreeNode* buildTree(int i){
    if(i > n || a[i] == -1){
        return NULL;
    }
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->val = a[i];
    node->left = buildTree(2 * i);
    node->right = buildTree(2 * i + 1);
    return node;
}

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){
        return NULL;
    }
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    TreeNode* root = buildTree(1);

    return 0;
}