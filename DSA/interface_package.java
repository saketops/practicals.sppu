/*****Code 12 ****/
import java.util.*;
interface tenth
{
    float percent = 82.00f;
    int year = 2019;
}
interface twelve
{
    float percentage = 88.00f;
    int years = 2021;
}
class data implements tenth,twelve
{
    private String name;
            int age;
            int pyear = 2023;
    public 
            Scanner obj = new Scanner(System.in);
            void data0()
            {
                System.out.println("Enter name :");
                name = obj.nextLine();
                System.out.println("Enter age :");
                age = obj.nextInt(); 

                System.out.println("Candidate Name       :"+name);
                System.out.println("          Age        :"+age);
                System.out.println("          PresentYear:"+pyear);
            }
            void data1()
            {
                System.out.println("*****10th Result Data*****");
                System.out.println("          Percentage :"+percent);
                System.out.println("          Year       :"+year);

            }
            void data2()
            {
                System.out.println("*****12th Result Data*****");
                System.out.println("          Percentage :"+percentage);
                System.out.println("          Year       :"+years);
            }
}
class interface_package
{
    public static void main(String args[])
    {
        data obj = new data();
        obj.data0();
        obj.data1();
        obj.data2();
    }
}

/*********OUTPUT ********
Enter name :
JHON DOE
Enter age :
20
Candidate Name       :JHON DOE
          Age        :20  
          PresentYear:2023
*****10th Result Data*****
          Percentage :82.0
          Year       :2019
*****12th Result Data*****
          Percentage :88.0
          Year       :2021
 Sure! Let's dive deeper into the code and explain each part in more detail:

1. Interfaces:
   - The `tenth` interface declares two constant variables: `percent` and `year`. These variables represent the percentage and year of completion for the 10th grade.
   - The `twelve` interface declares two constant variables: `percentage` and `years`. These variables represent the percentage and year of completion for the 12th grade.

2. Class `data`:
   - This class implements both the `tenth` and `twelve` interfaces, indicating that it provides the implementation for the methods and variables defined in those interfaces.
   - It has private member variables: `name`, `age`, and `pyear`. These variables hold the candidate's name, age, and the current year.
   - The class contains three methods:
     - `data0()`: This method prompts the user to enter their name and age using the `Scanner` class. It then displays the entered name, age, and the current year (`pyear`) using `System.out.println()`.
     - `data1()`: This method displays the 10th grade result data by accessing the constants `percent` and `year` from the `tenth` interface and displaying them using `System.out.println()`.
     - `data2()`: This method displays the 12th grade result data by accessing the constants `percentage` and `years` from the `twelve` interface and displaying them using `System.out.println()`.

3. `interface_package` class:
   - This class contains the `main()` method, which serves as the entry point for the program.
   - Inside the `main()` method, an instance of the `data` class named `obj` is created using the `new` keyword.
   - The `data0()`, `data1()`, and `data2()` methods of the `obj` object are called sequentially to display the user's information and academic result data.

Overall, this code demonstrates the use of interfaces to define constants and how a class can implement those interfaces to provide the implementation for the declared methods and access the constants. The `data` class uses the implemented interfaces to display the user's information and academic result data.*/
