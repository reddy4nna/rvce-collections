# Methods are anything you create using def and they look just like fucntions except you have to call them using a object 
# Attributes are kinda like variables to a certain object. To create an attribute we have to use the self keyword 
# The self keyword stands for the instance your calling for example tim/fred is an instance of type dog 

'''class Dog(object):
    def __init__(self,name,age):             #__init__ is a constructor 
        self.name=name
        self.age=age
        self.li=[1,2,3]

       

    def speak(self):
        print("Hi I am ",self.name,'and I am',self.age,'years old')

    def age_change(self,age):
        self.age=age

    def add_weight(self,weight):
        self.weight=weight        
        
    

tim=Dog('tim',21)
fred=Dog('fred',19) 
tim.age_change(5)
tim.speak()
fred.speak()
tim.add_weight=(70)
print(fred.add_weight)

print(tim.age)'''


# INHERTIANCE


class Dog(object):
    def __init__(self,name,age):            
        self.name=name
        self.age=age
    def speak(self):
        print("Hi I am ",self.name,'and I am',self.age,'years old')    

    def talk(self):
        print('bark!')            
'''
class Cat(object):
    def __init__(self,name,age,color):            
        self.name=name
        self.age=age
        self.color=color

    def speak(self):
        print("Hi I am ",self.name,'and I am',self.age,'years old')  '''       
# We basically copy pasted the same thing for cat however copy pasting is not a good coding practice hence we use another method mentioned below

class Cat(Dog): #Dog is the Parent class and Cat is the child class
    def __init__(self, name , age , color):
        super().__init__(name, age) #he super() function is used to give access to methods and properties of a parent or sibling class. The super() function returns an object that represents the parent class.
        self.color=color
        self.name='tech'

    def talk(self):
        print('meow!')

tim= Cat('tim','5','blue')       
tim.speak() 
tim.talk()
#When we inherit from an other class we actually inherit all the properties attributes and methods of that class
#Anything that is done in the cat class like addition of cuntion such as talk etc is gonna override the the already defined thing in dog
Jim=Dog('Jim','70')
Jim.talk()
tim.talk()
# if we add a new addition in cat class i.e self.name it will take the name defined as the name i.e it will override the existing def which was done in dog class
