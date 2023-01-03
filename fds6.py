#Write a python program to store names and mobile numbers of your friend sorted order on names.

data = []
name = []
phone = []
flag = 0
print("enter name and phone number to add in phonebook")  # swap 8888


def fibo1(m):
    if (m <= 1):
        return m
    else:
        return (fibo1(m - 1) + fibo1(m - 2))


# visha 98685
while True:
    d1 = input("")
    data.append(d1)
    if (d1 == ""):
        break
    else:
        d1 = d1.split(" ")
        name.append(d1[0])
        phone.append(d1[1])
print("names entered by user")
print(name)
print("phone no entered by user")
print(phone)
fib_size = len(name)
k = fib_size
fibo = []

for i in range(0, fib_size):
    p = fibo1(i)
    fibo.append(p)

print("fibonacci value list", fibo)
fib_len = len(fibo)
print("enter name  that you want to search")
d2 = input("")

# d2=d2.split(" ")
namekey = d2

if (fibo[k - 1] == 0):
    print("element not found")

offset2 = -1


def fibo_search(namekey1, name1, offset1, fibo2, k1, fib_size1):
    while (fibo2[k1 - 1] > 1):
        i = min(offset1 + fibo2[k1 - 2], fib_size1 - 1)
        # print("value of i",i)
        # print(namekey1)
        if (namekey1 == name1[i]):
            #flag = flag + 1
            return 1


        elif (namekey1 > name1[i]):
            k1 = k1 - 1
            offset1 = i
            fibo_search(namekey1, name1, offset1, fibo2, k1, fib_size1)
        elif (namekey1 < name1[i]):
            k1 = k1 - 2
            fibo_search(namekey1, name1, offset1, fibo2, k1, fib_size1)


p = 0
# flag=0
p=fibo_search(namekey, name, offset2, fibo, k, fib_len)
flag=0
if (p!=1):
    print("name does not exist in phonebook ")
    #ph1 = input(int("enter phone no to add in phonebook"))
    flag=flag+1
    ''' i = 0
    count1 = 0
    while (namekey > name[i]):
        i = i + 1
        count1 = count1 + 1

    print(count1)
    name.insert(count1, namekey)
    phone.insert(count1, ph1)'''
else:
    print("name already exist in phonebook ")

if(flag!=0):
    ph1 = input("enter phone no to add in phonebook")
    i = 0
    count1 = 0
    while (namekey > name[i]):
        i = i + 1
        count1 = count1 + 1

    name.insert(count1, namekey)
    phone.insert(count1, ph1)

print("names present in phonebook")
print(name)
print("phone no present in phonebook")
print(phone)