#Write a python program to store roll numbers of student array

nos=int(input("Enter no of students: "))
start=0
end=nos-1
present=[]
print("Enter present student Roll NO: ")
for i in range(0,nos):
    b=int(input())
    present.append(b)
key=int(input("Enter roll no you want to search: "))
flag=False
def binary(present1,start,end):
    if(start<=end):
        mid=int((start+end)/2)
        if(key==present1[mid]):
            print("Roll no found at position: ",mid)
            flag=True
        elif(key>present1[mid]):
            binary(present,mid+1,end)
        elif(key<present1[mid]):
            binary(present1,start,mid-1)
    else:
        print("Roll no not found.")
binary(present,start,end)