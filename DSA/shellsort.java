/***** Code 11 ****/
class shellsort
{
    public shellsort(int arr[],int n)
    {
        int temp,i;
        for(int gap = n/2;gap>0;gap=gap/2)
        {
            for(int j=gap;j<n;j=j+1)
            {
                temp=arr[j];
                i=0;
                for(i=j;i>=gap && arr[i-gap]>temp;i=i-gap)
                {
                    arr[i]=arr[i-gap];
                }
                arr[i]=temp;
            }
        }
    }
    public static void main(String args[])
    {
        int arr[] = {5,28,90,67,0,23,1,78,4};
        for(int i=0;i<9;i++)
        {
            System.out.print(arr[i]+" ");
        }
        new shellsort(arr,9);
        System.out.println("\nAfter Shell Sorting :");
        for(int i=0;i<9;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}

/*******Output******
5 28 90 67 0 23 1 78 4 
After Shell Sorting :  
0 1 4 5 23 28 67 78 90 



The code you provided demonstrates the implementation of the Shell Sort algorithm in Java. Here's a breakdown of the code:

1. Class `shellsort`:
   - This class contains a constructor that takes an array `arr` and its length `n` as parameters.
   - The constructor implements the Shell Sort algorithm to sort the array in ascending order.
   - The algorithm uses a series of decreasing gaps to compare and swap elements in the array.
   - The outer loop controls the gaps by initializing `gap` to `n/2` and dividing it by 2 in each iteration until `gap` becomes 0.
   - The inner loop performs the comparison and swapping of elements based on the current gap.
   - Within the inner loop, a temporary variable `temp` is used to hold the value of the current element being compared.
   - The variable `i` is used to track the index while shifting the elements to their correct positions within each gap.
   - After the loops complete, the array is sorted in ascending order.

2. `main()` method:
   - The `main()` method serves as the entry point for the program.
   - Inside the method, an array `arr` is initialized with some values.
   - The initial values of the array are printed using a `for` loop.
   - An instance of the `shellsort` class is created with the `arr` array and its length `9`.
   - The Shell Sort algorithm is applied to the array, sorting it in ascending order.
   - The sorted values of the array are then printed using another `for` loop.

Overall, this code demonstrates the implementation of the Shell Sort algorithm to sort an array in ascending order. The algorithm utilizes a series of decreasing gaps to compare and swap elements, resulting in an efficient sorting mechanism.*/
