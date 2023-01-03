# Write a Python program to store marks scored in subject “Fundamental of Data
#Structure” by N students in the class.

import string
def read(n):
    i=0
    while(i<n):
        num=input()
        if(num.isdigit()or num.upper()=='NA'):
            marks.append(num)
            i=i+1
        else:
            print("invalid value.")
            
def average():
    s=0.0
    for i in marks:
        if(i.isdigit()):
            s=s+int(i)
    avg=s/len(marks)
    print("average score of the class is:",avg)


def max_and_min():
    max=0
    min=100
    for i in marks:
        if(i.isdigit()):
            if(int(i)>=max):
                max=int(i)
            if(int(i)<=min):
                min=int(i)
    print("the highest marks are:",max)
    print("the lowest marks are:",min)

def absent():
    count=0
    for i in marks:
        if(i.upper()=='NA'):
            count+=1
    print("Enter no of students who are absent:",count)

def frequency():
    frequency_1=0
    frequency_2=0
    high_marks=0
    for i in marks:
        if(i.isdigit()):
            for j in marks:
                if(j.isdigit()):
                    if(int(i)==int(j)):
                        frequency_1+=1
            if(frequency_1>frequency_2):
                frequency_2=frequency_1
                high_marks=int(i)
            frequency_1=0
    if(frequency_2==1):
        print("all the marks having equal frequency is:",high_marks)
    else:
        print("the marks with highest frequency is:",high_marks)
        print("it occured",frequency_2,"times")

def main():
    global marks
    marks=[]
    ch=0
    n=int(input("Enter the number of students:"))
    print("Enter the marks of each student:")
    read(n)
    while(ch!=5):
        print("Enter your choice:")
        print("1.to calculate the average of class:")
        print("2.to display the minimum and maximum marks:")
        print("3.to calculate the number of students absent for the exam:")
        print("4.to calculate the marks with highest frequency:")
        print("5.exit")
        ch=int(input())
        if(ch==1):
            average()
        elif(ch==2):
           max_and_min()
        elif(ch==3):
            absent()
        elif(ch==4):
            frequency()
        elif(ch==5):
            print("thank you")
        else:
            print("invalid input")

if(__name__=="__main__"):
    main()
