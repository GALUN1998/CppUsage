#include <iostream>
using namespace std;

typedef struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
}TreeNode;

TreeNode* ret;

bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return false;
    bool lson = dfs(root->left, p, q);
    bool rson = dfs(root->right, p, q);
    // p在左边，q在右边或者p在右边，q在左边
    if(lson && rson) {
        ret = root;
    }
    // p和q都在左边或者p和q都在右边
    // 判断公共节点的方式也只是比较值是否相等
    if((lson || rson) && (root->data == p->data || root->data == q->data)) {
        ret = root;
    }
    // 如果以上这两种情况可以满足，就可以确定公共节点了，如果不行的话，就继续遍历

    // 这部分没有特别理解
    return lson || rson || root->data == p->data || root->data == q->data;
}

// 输入参数，root、p和q
TreeNode* findPublicAnce(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, p, q);
    return ret;
}
// 公共祖先：
int main() {

}