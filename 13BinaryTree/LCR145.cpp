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
bool check(TreeNode *left, TreeNode* right){
    if(left == NULL && right == NULL){
        return true;
    } else if(!left || !right){
        return false;
    }
    return left->val == right->val
            && check(left->left, right->right)
            && check(left->right, right->left);
}
bool checkSymmetricTree(TreeNode* root) {
    if(root == NULL){
        return true;
    } else{
        return check(root->left, root->right);
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    TreeNode* root = buildTree(1);
    bool res = checkSymmetricTree(root);
    if(res){
        printf("true\n");
    } else{
        printf("false\n");
    }
    return 0;
}