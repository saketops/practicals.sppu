#include<iostream>
#include<cstring>
#define MAX 10;
using namespace std;

class node
{
    private :char keyword[10];
             char meaning[10];
             node *left;
             node *right;
    public :node();
            node(char [],char []);
            friend class BST;
};
node :: node()
{
    keyword[0]='0';
    meaning[0]='0';
    left = NULL;
    right = NULL;
}
node :: node(char key[],char mean[])
{
    strcpy(keyword,key);
    strcpy(meaning,mean);
    left = NULL;
    right = NULL;
}
class BST
{
    private :node *root;
             void inorder(node *root);
             void inorderrev(node *root);
             node *insert(node *root,node *);
             node *search(char key[]);
             node *remove(node *root,char key[]);
    public :BST();
            void update(char []);
            void recinsert(char [],char []);
            node *search(node *,char[]);
            void find(char key[]);
            void printAscending();
            void printDescending();
            void removeword(char val[]);
};
BST :: BST()
{
    root = NULL;
}
void BST :: recinsert(char k[],char m[])
{
    node *newnd = new node(k,m);
    root = insert(root,newnd);
}
node *BST :: insert(node *root,node *newnd)
{
    if(root == NULL)
        root = newnd;
    else if(strcmp(newnd->keyword,root->keyword)<0)
        root->left=insert(root->left,newnd);
    else if(strcmp(newnd->keyword,root->keyword)>0)
        root->right=insert(root->right,newnd);
    else
        cout<<"\nDuplicate Values :";
    return root;
}
node * BST::remove(node *root,char key[])
{
    if(root==NULL)
        return NULL;
    else if(strcmp(key,root->keyword)<0)
        root->left=remove(root->left,key);
    else if (strcmp(key,root->keyword)>0)
        root->right=remove(root->right,key);
    else
    {
        if(root->right!=NULL)
        {
            node *in_succ = root->right;
            while(in_succ->left!=NULL)
            {
                in_succ = in_succ->left;
            }
            strcpy(root->keyword,in_succ->keyword);
            strcpy(root->meaning,in_succ->meaning);
            root->right=remove(root->right,in_succ->keyword);
        }
        else
        {
            return root->left;
        }
    }
    return root;
}
void BST :: removeword(char val[])
{
    remove(root,val);
}
void BST :: update(char k[])
{
    node *tempnd;
    tempnd = search(k);
    if(tempnd == NULL)
        cout<<"\nWord not present for Update :";
    else
    {
        cout<<"\nEnter new meaning for this word :";
        cin>>tempnd->meaning;
    }
}
node *BST::search(char val[])
{
    node *tempnd=root;
    tempnd=search(tempnd,val);
    return tempnd;
}
node *BST::search(node *tempnd, char k[])
{
    if(tempnd!= NULL)
    {
        if(strcmp(k,tempnd->keyword)==0)
            return tempnd;
        else if(strcmp(k, tempnd->keyword)<0)
            search(tempnd->left, k);
        else
            search(tempnd->right, k);
    }
    else
        return NULL;
}
void BST::find(char val[])
{
    node *tempnd;
    tempnd=search(val);
    if (tempnd == NULL)
    {
        cout<<endl<<"NOT FOUND :\n";
    }
    else
    {
        cout<<endl<<"Founnd....";
        cout<<"\nMeaning is "<<tempnd->meaning;
    }
}
void BST::inorder(node *root)
{
    if(root!= NULL)
    {
        inorder(root->left);
        cout<<endl<<root->keyword<<" : "<<root->meaning;
        inorderrev(root->right);
    }
}
void BST :: inorderrev(node *root)
{
    if(root!= NULL)
    {
        inorderrev(root->right);
        cout<<endl<<root->keyword<<" : "<<root->meaning;
        inorderrev(root->left);
    }
}
void BST :: printAscending()
{
    inorder(root);
}
void BST :: printDescending()
{
    inorderrev(root);
}
int menu()
{
    int choice;
    cout<<endl<<"DICTIONARY APPLICATION :"<<endl;
    cout<<"1>INSERT :"<<endl;
    cout<<"2.UPDATE :"<<endl;
    cout<<"3.DELETE :"<<endl;
    cout<<"4.Print ASCENDING :"<<endl;
    cout<<"5.Print DESCENDING :"<<endl;
    cout<<"6.FIND :"<<endl;
    cout<<"7.EXIT :"<<endl;
    cout<<"Enter your Choice :";
    cin>>choice;
    return choice;
    return 0;
}
int main()
{
    BST t;
    char k[10],m[10];
    char keyword [40];
    int n,choice;
    while(true)
    {
        choice = menu();
        switch(choice)
        {
            case 1:
                cout<<"\n How many element you want to insert :";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    cout<<"\nEnter new Keyword :";
                    cin>>k;
                    cout<<"\nEnter meaning of "<<k<<" : ";
                    cin>>m;
                    t.recinsert(k,m);
                }
                break;
            case 2:
                cout<<"\nEnter keyword to be found :";
                cin>>k;
                t.update(k);
                break;
            case 3:
                cout<<"\nEnter the Keyword :";
                cin>>keyword;
                t.removeword(keyword);
                break;
            case 4:
                cout<<"\n Print Dictionary in ascending Order :";
                t.printDescending();
                break;
            case 5:
                cout<<"\n Print Dictionary in descending order :";
                t.printDescending();
                break;
            case 6:
                cout<<"Enter the Keyword :";
                cin>>keyword;
                t.find(keyword);
                break;
            case 7:
                cout<<"\nProgram ending...\n";
                return 0;
            default:
                    cout<<"\nEnter correct choice :";
        }
    }
}

/******OUTPUT**********
DICTIONARY APPLICATION :
1>INSERT :
2.UPDATE :
3.DELETE :
4.Print ASCENDING :     
5.Print DESCENDING :    
6.FIND :
7.EXIT :
Enter your Choice :1    

 How many element you want to insert :3

Enter new Keyword :abrupt

Enter meaning of abrupt : quickly

Enter new Keyword :least

Enter meaning of least : small

Enter new Keyword :glad

Enter meaning of glad : happy

DICTIONARY APPLICATION :
1>INSERT :
2.UPDATE :
3.DELETE :
4.Print ASCENDING :
5.Print DESCENDING :
6.FIND :
7.EXIT :
Enter your Choice :2

Enter keyword to be found :least

Enter new meaning for this word :smallest

DICTIONARY APPLICATION :
1>INSERT :
2.UPDATE :
3.DELETE :
4.Print ASCENDING :
5.Print DESCENDING :
6.FIND :
7.EXIT :
Enter your Choice :3

Enter the Keyword :abrupt

DICTIONARY APPLICATION :
1>INSERT :
2.UPDATE :
3.DELETE :
4.Print ASCENDING :
5.Print DESCENDING :
6.FIND :
7.EXIT :
Enter your Choice :4

 Print Dictionary in ascending Order :
least : smallest
glad : happy
DICTIONARY APPLICATION :
1>INSERT :
2.UPDATE :
3.DELETE :
4.Print ASCENDING :
5.Print DESCENDING :
6.FIND :
7.EXIT :
Enter your Choice :5

 Print Dictionary in descending order :
least : smallest
glad : happy
DICTIONARY APPLICATION :
1>INSERT :
2.UPDATE :
3.DELETE :
4.Print ASCENDING :
5.Print DESCENDING :
6.FIND :
7.EXIT :
Enter your Choice :6
Enter the Keyword :glad

Founnd....
Meaning is happy
DICTIONARY APPLICATION :
1>INSERT :
2.UPDATE :
3.DELETE :
4.Print ASCENDING :
5.Print DESCENDING :
6.FIND :
7.EXIT :
Enter your Choice :7

Program ending...

This code implements a basic dictionary application using a binary search tree (BST) in C++. Here's how it works:

1. The code defines a class `node` to represent each node in the BST. Each node contains a keyword, a meaning, and pointers to the left and right child nodes.

2. The code also defines a class `BST` to represent the binary search tree. It contains member functions for inserting a node, searching for a keyword, updating the meaning of a keyword, removing a node, and printing the tree in ascending and descending order.

3. The code provides a menu function `menu()` that displays the available operations and returns the user's choice.

4. In the `main()` function, an instance of the `BST` class is created.

5. The user is prompted to choose an operation from the menu, and based on the choice, the corresponding function of the `BST` class is called.

6. For example, if the user chooses to insert a new keyword, they are prompted to enter the number of elements to insert. Then, for each element, they enter a keyword and its meaning, which are inserted into the BST using the `recinsert()` function.

7. Similarly, other operations such as updating a keyword, deleting a keyword, printing the dictionary in ascending or descending order, and finding a keyword are implemented using the appropriate functions of the `BST` class.

8. The program continues to display the menu and perform operations until the user chooses to exit.

The code demonstrates a basic implementation of a dictionary using a binary search tree. It allows users to insert new keywords with their meanings, update the meanings of existing keywords, delete keywords, and print the dictionary in ascending or descending order.
*/