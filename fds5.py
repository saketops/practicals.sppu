from django import middleware


data=[]
name=[]
phone=[]
print("enter name and phone number to add in phonebook")
while True:
    d1=input("")
    data.append(d1)
    if(d1==""):
        break
    else:
        d1=d1.split(" ")
        name.append(d1[0])
        phone.append(d1[1])
print("names entered by user")
print(name)
print("phone no entered by user")
print(phone)
print("enter name and phone number that you want to search")
d2=input("")
d2=d2.split(" ")
namekey=d2[0]
phonekey=d2[1]
start=0;
end=len(name)-1
def binarysearch(name,start,end):
    if(start<=end):
      mid=int((start+end)/2)
if(name[middleware]==namekey):
            print("name and phone number already exist in phonebook at location",mid)
elif(namekey<name[mid]):
         binarysearch(name,start,mid-1)
elif(namekey>name[mid]):
         binarysearch(name,mid+1,end)
else:                   
         print("entred name and phone number doesnt exist in phonebook")
if(namekey<name[0]):
                name.insert(0,namekey)
                phone.insert(0,phonekey)
elif(namekey>name[len(name)-1]):
                name.insert(len(name),namekey)
                phone.insert(len(name),phonekey)
else:
                i=0
                count1=0
                while(namekey>name[i]):
                    i=i+1
                    count1=count1+1
                print(count1)
                name.insert(count1,namekey)
                phone.insert(count1,phonekey)
print("after adding new details in phonebook at correct position")
print("names present in phonebook")
print(name)
print("phone numbers present in phonebook")
print(phone)
binarysearch(name,start,end)