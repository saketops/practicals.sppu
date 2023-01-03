#net amount of bank account

balance=0
while True:
    print('opening balance')
    s=input()
    if not s:
        break
    print('Enter your bank transactions')
    data=s.split(' ')
    Type=data[0]
    amt=int(data[0])
    if Type=='D':
        balance+=amt
    elif Type=='W':
        balance-=amt
    else:
        pass
print('your Current Balance : ',balance)