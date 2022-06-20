/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void insert_BST(struct TreeNode* root, struct TreeNode* move, int key)
{
    if (root && root->val > key)
    {
        if (root->left)
            insert_BST(root->left, move, key);
        else
            root->left = move;
    }
    else if (root && root->val < key)
    {
        if (root->right)
            insert_BST(root->right, move, key);
        else
            root->right = move;
    }
}

struct TreeNode* search_key_move(struct TreeNode* root, int key)
{
    if (root && root->val > key)
        if (root->left && root->left->val != key)
            return (search_key_move(root->left, key));
    if (root && root->val < key)
        if (root->right && root->right->val != key)
            return (search_key_move(root->right, key));
    if (root && root->left && root->left->val == key)
    {
        struct TreeNode* p = root->left->right;
        root->left = root->left->left;
        return (p);
    }
    if (root && root->right && root->right->val == key)
    {
        struct TreeNode* p = root->right->left;
        root->right = root->right->right;
        return (p);
    }
    return (NULL);
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    struct TreeNode* move = NULL;

    if (root && root->val == key)
    {
        if (!root->left)
            root = root->right;
        else if (!root->right)
            root = root->left;
        else
        {
            move = root->left;
            root = root->right;
        }
    }
    else
        move = search_key_move(root, key);
    if (move)
            insert_BST(root, move, move->val);
    return (root);
}