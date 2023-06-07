#include<iostream>
using namespace std;

int main()
{
    int  arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=0;
    }
    arr[4] = 11111111;
    arr[1] = 22222222;
    arr[2] = 33333333;
    arr[5] = 44444444;
    arr[7] = 55555555;
    arr[3] = 66666666;
    arr[9] = 77777777;

    // for(int i=0;i<10;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    cout<<endl;
    string name;
    cout<<"Enter name to search number fom phonebook"<<endl;
    cin>>name;
    int len = name.length();
    int pos = len%10;
    cout<<"Name   :  Phone no "<<endl;
    if(arr[pos] == 0)
    {
        cout<<"No data Found :";
    }
    else
    {
        cout<<name<<"  :  "<<arr[pos];
    }
    return 0;
}


/***********OUTPUT********
Enter name to search number fom phonebook
jhon
Name   :  Phone no 
jhon  :  11111111




This code represents a simple phonebook program that stores phone numbers based on a hashing technique using an array.

Let's go through the code step by step:

1. The code includes the necessary header file `iostream` for input/output.

2. In the `main()` function, an integer array `arr` of size 10 is declared. Each element of the array is initialized to 0.

3. Some specific indices of the array are assigned phone numbers to simulate a phonebook. These phone numbers are stored at indices 4, 1, 2, 5, 7, 3, and 9.

4. The code prompts the user to enter a name to search for a phone number in the phonebook.

5. The length of the entered name is calculated using the `length()` function.

6. The position in the array (`pos`) to search for the phone number is determined by taking the modulus of the length with 10.

7. The code checks if the value at `arr[pos]` is 0. If it is, it means no phone number is stored for that position, and it displays a message "No data Found". Otherwise, it prints the name and the corresponding phone number stored at `arr[pos]`.

8. The program ends after displaying the search result.

That's the overall explanation of the code. It simulates a simple phonebook program where phone numbers are stored based on a hashing technique using an array. The user can search for a phone number by entering a name, and the program retrieves and displays the corresponding phone number if found in the phonebook.





*/




















