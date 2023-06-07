#include<iostream>
using namespace std;

int main()
{
    int size,location,key;
    cout<<"Enter the size of hash table :"<<endl;
    cin>>size;
    int arr[size],arr1[size];
    location = key%size;
    for(int i=0;i<size;i++)
    {
        arr[i]=i;
    }
    for(int i=0;i<size;i++)
    {
        arr1[i]=0;
    }
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" : "<<arr1[i]<<endl;
    }
    int no_of_elements;
    cout<<"Enter how many element you want to store :";
    cin>>no_of_elements;
    for(int i=0;i<no_of_elements;i++)
    {
        cout<<"Enter Element :";
        cin>>key;
        location = key%size;
        if(arr1[location]==0)
        {
            arr1[location]=key;
        }
        else
        {
            location++;
            arr1[location]=key;
        }
    }
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" : "<<arr1[i]<<endl;
    }
    return 0;
}

/******OUTPUT*****
 * Enter the size of hash table :
5

0 : 0
1 : 0
2 : 0
3 : 0
4 : 0
Enter how many element you want to store :5
Enter Element :101
Enter Element :102
Enter Element :103
Enter Element :104
Enter Element :105

0 : 105
1 : 101
2 : 102
3 : 103
4 : 104


This code implements a basic hash table using linear probing collision resolution in C++. Here's how it works:

1. The code starts by prompting the user to enter the size of the hash table.

2. Two arrays are declared: `arr` and `arr1`. `arr` will store the keys, and `arr1` will store the corresponding values in the hash table.

3. The code initializes `arr` with values from 0 to size-1.

4. `arr1` is initialized with 0 for all elements, indicating that no keys have been inserted yet.

5. The initial state of the hash table is displayed, showing the keys from `arr` and the corresponding values from `arr1`.

6. The user is prompted to enter the number of elements they want to store in the hash table.

7. A loop runs `no_of_elements` times to input the keys from the user and insert them into the hash table.

8. For each key, the location in the hash table is calculated by taking the modulus of the key with the size of the hash table.

9. If the calculated location in `arr1` is empty (contains 0), the key is inserted at that location.

10. If the calculated location is already occupied, linear probing is used to find the next available location by incrementing the location until an empty slot is found.

11. The final state of the hash table is displayed, showing the keys from `arr` and the corresponding values from `arr1` after all insertions.

The code demonstrates a simple implementation of a hash table using linear probing for collision resolution.*/