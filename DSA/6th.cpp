// Implement all the functions of a dictionary (ADT) using hashing.
// Data: Set of (key, value) pairs, Keys are mapped to values,
// Keys must be comparable, Keys mustbe unique
// Standard Operations: Insert (key, value), Find(key),
// Delete(key)

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class data
{
    private : string hashtable[10];
              string name;
              int cost;
              string del;
              int len,pos,find;
              unordered_map<string,int>map_obj;
    public : void insert();
             void display();
             void search();
             void delete_key();
};
void data :: insert()
{
    cout<<"Enter object name :";
    cin>>name;
    cout<<"Enter object cost :";
    cin>>cost;
    map_obj[name]=cost;
    for(int i=0;i<10;i++)
    {
        hashtable[i]="0";
    }
    len = name.length();
    pos = len%10;
    if(hashtable[pos] == "0")
    {
        hashtable[pos]=name;
    }
    else
    {
        for(int i=pos+1;i%10 != pos;i++)
        {
            if(hashtable[i]=="0")
            {
                hashtable[i]=name;
            }
        }
    }

}
void data :: display()
{
    for(auto &x : map_obj)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
}
void data :: search()
{
    string find;
    cout<<"Enter object to search :";
    cin>>find;
    auto it = map_obj.find(find);
    if(it != map_obj.end())
    {
        cout<<"Name :"<<it->first<<" : "<<"Cost :"<<it->second<<endl;
    }
    else
    {
        cout<<"Not found :";
    }
}
void data :: delete_key()
{
    cout<<"Enter key to delete :";
    cin>>del;
    int dels = map_obj.erase(del);
    
}
int main()
{
    data obj;
    string name;
    int choice;
    do 
    {
        cout<<"Enter choice for operation :"<<endl;
        cout<<"1.Insertion Operation :"<<endl;
        cout<<"2.Display Operation :"<<endl;
        cout<<"3.Search Operation :"<<endl;
        cout<<"4.Deletion Operation :"<<endl;
        cout<<"5.For Termination press 0 :"<<endl<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.search();
                break;
            case 4:
                obj.delete_key();
                break;
            default:
                cout<<"Enter from given option :";
                break;
        }
    }
    while(choice != 0);
    return 0;
}

/******OUTPUT*****
 * Enter choice for operation :
1.Insertion Operation :     
2.Display Operation :       
3.Search Operation :        
4.Deletion Operation :      
5.For Termination press 0 : 

1
Enter object name :apple
Enter object cost :20
Enter choice for operation :
1.Insertion Operation :     
2.Display Operation :       
3.Search Operation :
4.Deletion Operation :
5.For Termination press 0 :

1
Enter object name :mango
Enter object cost :70
Enter choice for operation :
1.Insertion Operation :
2.Display Operation :
3.Search Operation :
4.Deletion Operation :
5.For Termination press 0 :

1
Enter object name :grapes
Enter object cost :30
Enter choice for operation :
1.Insertion Operation :
2.Display Operation :
3.Search Operation :
4.Deletion Operation :
5.For Termination press 0 :

2
grapes : 30
mango : 70
apple : 20
Enter choice for operation :
1.Insertion Operation :
2.Display Operation :
3.Search Operation :
4.Deletion Operation :
5.For Termination press 0 :

3
Enter object to search :mango
Name :mango : Cost :70
Enter choice for operation :
1.Insertion Operation :
2.Display Operation :
3.Search Operation :
4.Deletion Operation :
5.For Termination press 0 :

4
Enter key to delete :apple
Enter choice for operation :
1.Insertion Operation :
2.Display Operation :
3.Search Operation :
4.Deletion Operation :
5.For Termination press 0 :

2
grapes : 30
mango : 70
Enter choice for operation :
1.Insertion Operation :
2.Display Operation :
3.Search Operation :
4.Deletion Operation :
5.For Termination press 0 :

0



This code implements a simple data management program using a hash table and an unordered map in C++.

Let's go through the code step by step:

1. The code includes necessary header files: `iostream` for input/output, `string` for string manipulation, and `unordered_map` for using the unordered map container.

2. The code defines a class named `data` which encapsulates the data management operations.

3. Within the `data` class, there are private member variables: `hashtable` (an array to store the objects), `name` (name of the object), `cost` (cost of the object), `del` (key to delete), `len` (length of the name), `pos` (position in the array), `find` (object to search), and `map_obj` (an unordered map to store the objects and their costs).

4. The `data` class has four member functions: `insert()` for inserting objects into the hash table and unordered map, `display()` for displaying all the objects and their costs, `search()` for searching and displaying the cost of a specific object, and `delete_key()` for deleting an object from the unordered map.

5. In the `insert()` function, the user is prompted to enter the object name and cost. The object and its cost are stored in the unordered map `map_obj`. The object name is hashed to determine the position in the array. If the position in the `hashtable` is empty, the object name is stored directly. Otherwise, linear probing is used to find the next available position in the array.

6. The `display()` function iterates over the unordered map `map_obj` and prints the object names and their corresponding costs.

7. The `search()` function prompts the user to enter an object name to search for in the unordered map. It uses the `find()` function of the unordered map to check if the object name exists. If found, it displays the object name and its cost. Otherwise, it prints "Not found".

8. The `delete_key()` function prompts the user to enter a key (object name) to delete from the unordered map. It uses the `erase()` function of the unordered map to delete the object.

9. In the `main()` function, an object of the `data` class is created named `obj`. The user is presented with a menu to choose an operation (insertion, display, search, or deletion) or to terminate the program.

10. The user's choice is taken as input, and the corresponding operation is performed by calling the appropriate member function of the `obj` object.

11. The loop continues until the user enters 0 to terminate the program.

That's the overall explanation of the code. It provides a basic data management program where objects and their costs can be inserted, displayed, searched, and deleted using a hash table and an unordered map.

*/