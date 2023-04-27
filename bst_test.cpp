#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key <<" ";
        //("%d ", root->key);
        traverseInOrder(root->right);
    }
}

// Insert a node
// A node will not be inserted if a node with the same value is already present in the tree.
struct node *insertNode(struct node *node, int key) {
if (node == NULL) return newNode(key);
      if (key < node->key)
         node->left = insertNode(node->left, key);
      else if (key > node->key)
         node->right = insertNode(node->right, key);
   return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, search the left sub tree for the key.
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is larger than the root's key, search the right sub tree for the key.
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is equal to root's key, perform the deletion operation.
    //Prior to performing the deletion, check if the node has any children.
    else {
        // node has no children
        if (root->left == NULL and root->right == NULL)
            return NULL;

        // node has only one child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // node has two children
        //Identify the node with the minimum value in the right sub tree. (inorder succesor)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
