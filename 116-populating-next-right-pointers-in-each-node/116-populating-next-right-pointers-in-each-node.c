/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void con(struct Node* l, struct Node* r)
{
    if (!l)
        return (l);
    l->next = r;
    con(l->right, r->left);
    con(l->left, l->right);
    con(r->left, r->right);
}


struct Node* connect(struct Node* root)
{
	if (!root)
        return (root);
    root->next = NULL;
    con(root->left, root->right);
    return (root);
}