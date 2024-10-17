#print('hello'=='Hello')
#print(2-3+4>5)
#print ( False == True )
'''age =int( input( 'input your age :'))
if age == 16:
    print('hey youre 16')
else:
    print('youre not 16') '''

'''height = float(input('enter your height'))  
if height<1:
    print('you cannot ride , height under 1 m')
elif height==5:
    print('damn youre tall')        
elif height>2 :
    print('you cannot ride , height over 2 m')    
else:
    print('you can ride')'''

#x=int(input('enter x:'))
#y=int(input('enter y :'))
'''if not ( x==y or x+y==6) :
    print('true')     
else:
    print(':(')'''
'''if x==2:
    if y==3:
        print('x=2,y=3')
    else:
        print('x=2,y!=3')
else:
    print('x!=2')'''


#FOR LOOPS
'''for x in range (0,10,1): #start , stop ,step
    print(x)    '''   


'''#WHILE LOOPS 
loop = True

while loop:
    name = input('enter your name :')
    if name == 'stop':
        loop== False
        break'''

'''fruits=['apple','pear'] 
#print(fruits)
fruits.append('strawberry')
#print(fruits)
fruits[1]='blueberry'
print(fruits)'''

'''position=(2,3)
colours = (255,255,255)
print(type(colours))'''

fruits=['apples','pear','strawberry']
'''for fruit in fruits :
    if fruit=='pear':
        print(fruit)
    else:
        print('not pear')'''  

'''for x in range (len(fruits)):    #len(fruits) is similar to defining (0,3)
    if fruits[x]=='pear':
        print(fruits[x]) 
    else:
        print('not a pear')'''

#text = input('input something:')
#print(text.strip())
#print(len(text))        
#print(text.lower())
#print(text.split('.'))
#print(text.capitalize())

'''text = 'Hello i like python'
fruits= ['apple','pear','strawberrys']
#print(fruits[1:])
fruits[2:2] = 'b'
print(fruits)'''
'''def addTwo (x):
    return x+2
#newNumber = addTwo(7)
#print(newNumber)
def printstring(string):
    print(string)
printstring('hello')    
printstring('my name is aditya')'''
'''def accln(mass,force):
    a=force/mass
    return a
print(accln(2,5))'''
import math
'''print(math.sqrt(25))
print(math.pi)
'''
'''import mymodule
print(mymodule.anotherfunc(7))
print(mymodule.myfunc(3))

'''

'''def func(x):
    print(x)

print(func(7))
'''
'''text=input('Username:')
try:    
    number=int(text)
    print(number)

except:
    print('invalid username')'''
#print('\a')
'''
a='my name is aditya'

print(a.replace('aditya','Aditya'))
''''''
for x in fruits:
    print(x)
for x in 'strawberry':
    print(x)'''

'''adj=['big','red','tasty'] 

for x in adj:
    for y in fruits:
        print(x,y)'''
'''
for x in fruits :
    print(x)
    if x=='strawberry':
        break'''
'''
i=1
while i<=10:
    print('6*',i,'=',6*i)

    if i>=5:
        break
    i=1+1'''
'''
i = 1
while i <= 10:
    print('6*', i, '=', 6*i)
    i += 1 # increment i by 1 in each iteration
    if i > 5:
        break'''
'''
txt = "banana"

x = txt.center(20,'#')

print(x)'''


# Try and except
#Global and Local Variables
'''
var=9
loop=True


def func(x):
    global loop #(The global keyword is used to declare a that a local variable withing a loop / def is now to be used as a global variable )

    loop = 7

func(2)
print(loop)    '''


'''
a=10
while a>=0:
    print('Printing:','a')
    if a==0:
        break
    a-=1

    '''

'''print(5//3) 
print(5/2)
'''


'''a=int(input('enter the first number:'))
b=int(input('enter the second number:'))
c=input('operation:+,-,/,*')

if c== '+':
    print(a+b)
elif c=='-':
    print(a-b)
elif c=='/':
    print(a/b)
elif c=='*':
    print(a*b)
else:
    print('wrong operation intended ')       
            '''

'''
for N in range(11,21):
    print('Multiplication tble of',N)
    for i in range(0,11):
        print(str(N)+'*'+str(i)+'='+str(N*i))'''
           



'''adj=['red','big','tasty']
fruit=['apple','strawberry','banana']
for x in adj:
    for y in fruit:
        print(y,x)'''
'''
dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
del dict['name']
print(dict)


test_dict={'Anuradha': 21, 'Haritha': 21, 'Arushi': 22, 'Mani': 21}
del test_dict['Mani'] 
print(test_dict)'''
'''txt="Hello, welcome to my world"
x=txt.index('welcome') 
print(x)   '''
#Factorial
'''n=int(input('enter the number:'))
factorial=1
sum=0
for i in range (1,n+1):
    factorial=factorial*i
print('factorial of ',n,'is',factorial)
for i in range (1,n+1):
    sum+=i
print(sum)    
''''''
def my_function(**kid):
	print('the last name is '+ kid['lnm'])
my_function(fname='Tobias',lnm='ravi',classs=11)'''
'''with open('file.txt','w') as f:
    print('hello,hi my  me nah ')
with open('file.txt','r') as file:
    data=file.readlines()
    for line in data:
        word=line.split()
        print(word)'''
'''a=input('enter the number')
int(a)
try:
    print(20/a)
except:
    print('an error occured ')
else:
    print('this is the answer')
finally:
    print('yay!')
'''

'''class Bikes:
    name='yamaha'
    gear=4
    engine='135cc'

bike1=Bikes()
bike1.name='yamaha'
print(f"bike name :{bike1.name}")
'''
'''class Room():
    room_length=0.0
    room_breadth=0.0

    def Calc_area(self):
        print('Area=',+self.room_length*self.room_breadth)
study_room=Room()
study_room.room_length=12
study_room.room_breadth=13
study_room.Calc_area() '''       

'''class Persons:
    def __init__(self,fname,lname):
        self.firstname=fname
        self.lastname=lname

    def printname(self):
        print(self.firstname,self.lastname)    

class Student(Persons):
    pass

x=Student('Varun','Sharma')
x.printname()   '''

'''class Vehicles:
    def Vehicle_info(self):
        print('INside Vehicle class')

class Car(Vehicles):
    def  car_info(self):
        print('inside car class') 
car=Car()
car.Vehicle_info()
car.car_info()   '''    

#print(2**3+(5+6)**(1+1))
#print(20>>1)
'''x = 'abcd'
for i in x: 
    print(i.upper())
'''
'''txt='banana'
y=txt.center(len(txt),"*")
print(y)'''
# Program to print a shape using for loop

'''list=['a','i','e','o','u']
list.sort(reverse=True)
print(list)'''
'''def addtwo(X,Y):
    result=[]
    for i in range (len(X)):
        row=[]
        for j in range(len(X[0])):
            row.append(X[i][j]+Y[i][j])
        result.append(row)
    return result        
X=[[1,2,3],[4,5,6],[7,8,9]]
Y=[[1,2,3],[4,5,6],[7,8,9]]
result=addtwo(X,Y)
for row in result:
    print(row)

def trasnpose(X):
    result=[]
    for j in range(len(X[0])):
        row=[]
        for i in range(len(X)):
            row.append(X[i][j])
        result.append(row)
    return result
result1=trasnpose(result)
for row in result1:
    print(row)'''

'''for x in range(1,21):
    if x==3:
        break
    print(x)'''


'''score=float(input('Enter the Score:'))
if score>1:
    print('error')
elif score<0:
    print('error') 
else:
    if score>=0.9:
        print('Grade is A')    
    elif score>=0.8:
        print('Grade is B')        
    elif score>=0.7:
        print('Grade is C') 
    elif score>=0.6:
        print('Grade is D') 
    elif score <0.6:
        print('Grade is F')   ''' 


'''
list=[1,3,5,7,9,11,13,15]
print(2 not in list)
print(type(list))'''


'''n=int(input('enter the number :'))
if n>10:
    print('error')
else:
    for i in range (0,10):
        print(n,'*',i,'=',n*i)
    print('Do you want to continue[Yes/No]?')
    input('1.y\n 2.n\n')
    choice=int(input('enter your choice'))
    
    if choice==1:
        print('exit')
'''
'''a=float(input('enter number1:'))
b=float(input('enter number2:'))

def add(a,b):
    return(a+b)
def sub(a,b):
    return(a-b)
def prod(a,b):
    return(a*b)
def div(a,b):
    return(a/b)

print(' 1.add\n 2.sub\n 3.prod\n 4.div\n')
choice=int(input('enter choice b/w 1 to 4'))
if choice==1:
    print(add(a,b))
if choice==2:
    print(sub(a,b))
if choice==3:
    print(prod(a,b))
if choice==4:
    print(div(a,b))        '''
'''n=int(input('enter:'))
for i in range(n):
    for j in range (n-i-1):
        print(" ",end="")
    for j in range (i+1):
        print('*',end="")
    print()'''
'''
for i in range (5):
    for j in range(5-i):
        print('*',end=" ")
    print()  '''

'''n=5
for i in range(n):
    for j in range(i,n):
        print('',end='')
    for j in range(i):
        print('*',end='')
    for j in range(i+1):
        print('*',end='')
    print() '''                            

'''n = 5
for i in range(n):
    for j in range(i, n):
        print(' ', end='')
    for j in range(i):
        print('*', end='')
    for j in range(i + 1):
        print('*', end='')
    print()'''

'''
for i in range(5):
    for j in range(i+1):
        print(' ',end="")
    for j in range(4-i):
        print('*',end="") 
    for j in range (5-i):
        print('*',end="")       
    print()'''

'''i = 1
while True:
    if i%7 == 0:
        break
    print(i)
    i += 1'''

'''s=input('enter:')
reverse_s=s[::-1]
if s==reverse_s:
    print('palindrome ')
else:
    print('not')    
'''

'''def gcd(x,y):
    if x>y:
        small=y
    else:
        small=x
    for i in range (1,small+1):
        if ((x%i==0) and (y%i==0)):
            gcd=i

    return gcd
print(gcd(48,60))


print(10>>2)
print(33>>4)
print(10<<1)
print(5/2)
print(5//2)
'''
'''for i in range(6):
    for j in range(6-i):
        print(" ",end="")
    for j in range(i):
        print("*",end="")
    for j in range(i-1):
        print("*",end="")
    for j in range(i):
        print(" ",end="")
    print()           
'''
'''print(~12)
print(3+'adi')'''


'''for i in range(6):
    for j in range(6-i):
        print(" ",end="")
    for j in range(i):
        print('*',end="")
    for j in range(i-1):
        print('*',end="")
    for j in range(i):
        print(" ",end="")
    print()

print(10>>4)
print(10<<4)'''

'''a=int(input('enter'))
try:
    print(27/a)
except:
    print('error')
else:
    print('answer')
finally:
    print('always')'''
n=int(input('e:'))
factorial=1
sum=0
for i in range(1,n+1):
    factorial=factorial*i
    sum+=i
print(factorial)
print(sum)