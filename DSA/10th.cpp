/*Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display information of
particular employee. If record of student does not exist an appropriate message is displayed. If it
is, then the system displays the student details. Use sequential file to main the data.*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class data
{
    private :int roll;
             char name[20];
             char div;
             string add;
    public :void getdata();
            void displaydata();
};
void data :: getdata()
{
    cout<<"Enter Roll no :";
    cin>>roll;
    cout<<"Enter name :";
    cin>>name;
    cout<<"Enter Division :";
    cin>>div;
    cout<<"Enter Address :";
    cin.ignore();
    getline(cin,add);
    cout<<endl;
}
void data :: displaydata()
{
    cout<<"     "<<roll<<"      "<<name<<"         "<<div<<"         "<<add<<endl;
}
class student
{
    private : char fname[20];
              int i = 0;
    public : data obj;
             void input();
             void output();
};
void student :: input()
{
    fstream intake;
    intake.open("information.txt",ios :: out | ios :: app );
    obj.getdata();
    intake.write((char*) &obj,sizeof(obj));
    intake.close();
}
void student :: output()
{
    fstream outtake;
    outtake.open("information.txt",ios :: in);
    cout << "------------------- Student Information -------------------" << endl;
    cout<<"| Roll no |"<<"| Name |"<<"| Division |"<<"| Address |"<<endl;
    while(!outtake.eof())
    {
        outtake.read((char*) &obj,sizeof(obj));
        if(!outtake.eof())
        {
            obj.displaydata();
        }
    }
    outtake.close();
}
int main()
{
    student obj;
    int choice;
    do 
    {
        cout<<"1.Write in File :"<<endl;
        cout<<"2.To display data from file :"<<endl;
        cout<<"Enter choice to perform opertion :";
        cin>>choice;
        switch(choice)
        {
            case 1:
            obj.input();
            break;
            case 2:
            obj.output();
            break;
            default :
            cout<<"Enter from above option :";
            break;
        }
    }
    while(choice != 0);
    return 0;
}

/*******OUTPUT*****
 1.Write in File :
2.To display data from file :     
Enter choice to perform opertion :1
Enter Roll no :11
Enter name :ram
Enter Division :A
Enter Address :hadapsar

1.Write in File :
2.To display data from file :     
Enter choice to perform opertion :2
------------------- Student Information -------------------
| Roll no || Name || Division || Address |
     11      ram         A         hadapsar
1.Write in File :
2.To display data from file :
Enter choice to perform opertion :1
Enter Roll no :22
Enter name :sham
Enter Division :B
Enter Address :wanwadi

1.Write in File :
2.To display data from file :
Enter choice to perform opertion :2
------------------- Student Information -------------------
| Roll no || Name || Division || Address |
     11      ram         A         hadapsar
     22      sham         B         wanwadi
1.Write in File :
2.To display data from file :
Enter choice to perform opertion :



This code demonstrates a simple student information management system using file operations. Here's how it works:

1. The code defines a class `data` to represent student information. It has private member variables `roll` (roll number), `name` (name of the student), `div` (division), and `add` (address).

2. The class `data` has member functions `getdata()` and `displaydata()` to get and display student information, respectively.

3. The code also defines a class `student` which acts as an interface for input and output operations on the student information.

4. The `input()` function is used to get student information from the user and write it to a file named "information.txt". It opens the file in append mode and writes the `obj` (student information) to the file using the `write()` function.

5. The `output()` function is used to read and display student information from the "information.txt" file. It opens the file in input mode and reads the `obj` from the file using the `read()` function. It then displays the student information using the `displaydata()` function.

6. In the `main()` function, an instance of the `student` class is created.

7. The program enters a do-while loop to perform the following operations:
   - Display a menu with options to write student information or display information from the file.
   - Based on the user's choice, the corresponding member function of the `student` class is called.

8. The loop continues until the user enters a choice other than 1 or 2.

The code allows the user to input student information and store it in a file. It also provides the functionality to read and display the stored student information from the file. The file acts as a persistent storage for the student data.*/