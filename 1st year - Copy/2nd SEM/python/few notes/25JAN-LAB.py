'''append --> list.append('whatever you want to append')
   insert--> list.insert(position,item) 
   indexing--> print(list[]) {print between 0 and n+1 will give 0,1,2....n}
   pop--> list.pop(2)'''

'''Consider a sequence of numbers with some missing values. Write a python program for inserting the missing values and to remove some of the existing values 
   adding some values for the list and display the list '''


num=list()
n=int(input('enter the number of elements  in the list'))
while True:
    if n>0:
        i=int(input('enter the number to insert'))
        num.append(i)
        n=n-1
    else:
        break
print(num)

while True:
    print("\n menu")
    print("\n1.insert \n2.append \n3.pop \n4.print")
    break 
choice = int (input('enter your choice '))
if (choice == 1):
    num.insert(2,3)
    print(num)
elif (choice == 2):
    num.append(350)
    print(num)   
elif (choice == 3):
    num.pop(3)
    print(num)
elif (choice == 4):
    print(num)


   
   




        




