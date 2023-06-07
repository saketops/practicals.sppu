#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
}*root;
class BST
{
    public :void create_tree(); 
            void display(node *r1);
            BST()
            {
                root= NULL;
            }
};
void BST :: create_tree()
{
    int tbooks,tchapters,i,j,k;
    root = new node();
    cout<<"Enter name of Book :";
    cin>>root->label;
    cout<<"Enter no. of chapter in book :";
    cin>>tchapters;
    root->ch_count = tchapters;
    for(int i=0;i<tchapters;i++)
    {
        root->child[i]=new node;
        cout<<"Enter chapter name :"<<endl;
        cin>>root->child[i]->label;
        cout<<"Enter no.of sections in Chapter : "<<root->child[i]->label<<endl;
        cin>>root->child[i]->ch_count;
        for(j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j] = new node();
            cout<<"Enter Section :"<<j+1<<" name\n";
            cin>>root->child[i]->child[i]->label;
        }
    }
}
void BST :: display(node *r1)
{
    int i,j,k,tchapters;
    if(r1 != NULL)
    {
        cout<<endl<<"-----BOOK HEIRARCHY-----"<<endl;
        cout<<endl<<"BOOK TITLE : "<<r1->label;
        tchapters = r1->ch_count;
        for(i=0;i<tchapters;i++)
        {
            cout<<"\n CHAPTERS "<<i+1;
            cout<<" "<<r1->child[i]->label;
            cout<<"\nSECTIONS";
            for(j=0;j<r1->child[i]->ch_count;j++)
            {
                cout<<"\n"<<r1->child[i]->child[j]->label;
            }
        }
    }
}
int main()
{
    int choice;
    BST bst;
    while(true)
    {
        cout<<"----------------------------------"<<endl;
        cout<<"BOOK TREE CREATION :"<<endl;
        cout<<"__________________________________"<<endl;
        cout<<"1.CREATE :"<<endl;
        cout<<"2.DISPLAY :"<<endl;
        cout<<"3.QUIT :"<<endl;
        cout<<"Enter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                bst.create_tree();
                break;
            case 2:
                bst.display(root);
                break;
            case 3:
                exit(0);
            default :
                cout<<"Enter correct choice  :"<<endl;
        }
    }
    return 0;
}

/***********OUTPUT*********
 * ----------------------------------
BOOK TREE CREATION :
__________________________________
1.CREATE :
2.DISPLAY :
3.QUIT :
Enter your choice :1
Enter name of Book :ExploreScience
Enter no. of chapter in book :2
Enter chapter name :
Chapter_1
Enter no.of sections in Chapter : Chapter_1
2
Enter Section :1 name
Physics
Enter Section :2 name
Chemistry
Enter chapter name :
Chapter_2
Enter no.of sections in Chapter : Chapter_2
1
Enter Section :1 name
Biology
*/

/*Certainly! Let's dive deeper into the code and explore each function in more detail:

1. The code starts by including the necessary header files for input/output (`iostream`), string operations (`string.h`), and the `exit()` function (`cstdlib`).

2. The code defines a structure called `node`, which represents a node in the binary search tree. It has three members: `label` (a character array to store the name of the node), `ch_count` (an integer to store the number of child nodes), and `child` (an array of pointers to child nodes).

3. Next, a class `BST` is defined, which represents the binary search tree. It has three member functions:

   a. `create_tree()`: This function is responsible for creating the binary search tree by taking input from the user. It first creates the root node using the `new` operator and prompts the user to enter the name of the book. Then, it asks for the number of chapters in the book and stores it in `tchapters`. It uses a loop to iterate over each chapter and does the following:
      - Creates a new node for the chapter using `new`.
      - Prompts the user to enter the chapter name and stores it in `root->child[i]->label`.
      - Asks for the number of sections in the chapter and stores it in `root->child[i]->ch_count`.
      - Uses another loop to iterate over each section and does the following:
         * Creates a new node for the section using `new`.
         * Prompts the user to enter the section name and stores it in `root->child[i]->child[j]->label`.
   At the end of the function, the binary search tree is created with the provided hierarchy of books, chapters, and sections.

   b. `display()`: This function recursively traverses the binary search tree and displays the book hierarchy. It takes a node `r1` as a parameter, representing the current node being processed. If the current node is not `NULL`, it does the following:
      - Prints the book title stored in `r1->label`.
      - Retrieves the number of chapters in the book from `r1->ch_count` and iterates over each chapter.
      - For each chapter, it prints the chapter name, followed by the sections in that chapter.
   This function is called from the `main()` function with the root of the binary search tree as the parameter.

   c. Constructor: The constructor initializes the `root` of the binary search tree to `NULL`.

4. The `main()` function is where the program execution begins. It starts by declaring some variables, including an instance of the `BST` class called `bst`. This instance will be used to create and manipulate the binary search tree.

5. Inside the `while` loop, a menu-driven interface is provided to the user. The user is prompted to enter their choice: 1 to create a book hierarchy, 2 to display the hierarchy, or 3 to quit the program. Based on the user's choice, the corresponding member function of the `BST` class is called.

6. The `create_tree()` function is called when the user chooses option 1. It creates the binary search tree by taking input from the user, as explained earlier.

7. The `display()` function is called when the user chooses option 2. It displays the book hierarchy by recursively traversing the binary search tree and printing the book title, chapters, and sections.

8. If the user chooses option 3, the `exit()` function is called to terminate the program.

9. If the user enters an invalid choice, a default message is printed to inform them to enter a

 correct choice.

That's a more detailed explanation of the code. It provides the user with an interactive interface to create and display a hierarchical structure of books, chapters, and sections using a binary search tree.