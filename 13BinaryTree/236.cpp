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
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if(root == NULL){
        return NULL;
    }
    if(root->val == p || root->val == q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL && right == NULL){
        return NULL;
    } else if(left == NULL){
        return right;
    } else if(right == NULL){
        return left;
    } else{
        return root;
    }
}
int main(){
    int p, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d %d", &p, &q);
    TreeNode* root = buildTree(1);
    TreeNode* res = lowestCommonAncestor(root, p, q);
    return 0;
}