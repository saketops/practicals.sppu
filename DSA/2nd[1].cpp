#include<iostream>
#include<string>
using namespace std;

class node
{
    public :string data;
            node *left;
            node *right;
};

node *insert(node * &root,string value)
{
    node *temp = new node();
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    if(root == NULL)
    {
        root=temp;
        return temp;
    }
    else if(value <= root->data)
    {
        root->left = insert(root->left,value);
    }
    else
    {
        root->right = insert(root->right,value);
    }
    return root;
}
void postorder(node * &root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    node *root = NULL;
    insert(root,"+");
    insert(root,"*");
    insert(root,"D");
    insert(root,"A");
    insert(root,"B");
    insert(root,"()");
    cout<<"*****Postorder display*****"<<endl;//lexicographically
    postorder(root);
    return 0;
}

/*****OUTPUT*****
 * *****Postorder display*****
() * B A D + 


This code represents a binary search tree (BST) implementation for inserting and displaying nodes in postorder traversal.

Let's go through the code step by step:

1. The code includes the necessary header file `iostream` for input/output and `string` for string operations.

2. A class `node` is defined, which represents a node in the binary search tree. It has three members: `data` (a string to store the node's value), `left` (a pointer to the left child node), and `right` (a pointer to the right child node).

3. The `insert()` function is defined to insert a new node into the binary search tree. It takes two parameters: a reference to the `root` of the tree (a pointer to a pointer) and the value to be inserted. The function creates a new node, assigns the value to it, and sets its left and right pointers to `NULL`. If the `root` is `NULL`, indicating an empty tree, the new node becomes the root. If the value is less than or equal to the `root->data`, the function is recursively called on the left subtree. Otherwise, it is called on the right subtree. Finally, the function returns the `root` of the modified tree.

4. The `postorder()` function is defined to traverse the binary search tree in postorder and display the node values. It takes a reference to the `root` of the tree as a parameter. The function recursively visits the left subtree, then the right subtree, and finally prints the value of the current node. This order ensures a postorder traversal. The function uses a recursive approach and stops when it reaches a `NULL` node.

5. In the `main()` function, a `root` pointer is initialized to `NULL`.

6. The `insert()` function is called multiple times to insert nodes into the binary search tree. Each call passes the `root` pointer and a string value to be inserted. The nodes are inserted in a specific order to create a particular tree structure.

7. After inserting the nodes, the `postorder()` function is called to display the node values in postorder traversal. The function starts from the `root` of the tree and recursively visits the left and right subtrees, printing the values.

8. Finally, the program prints a message indicating the postorder display.

That's the overall explanation of the code. It creates a binary search tree and displays the node values in postorder traversal.
*/