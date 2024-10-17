
# Overriding Methods
''' AIM:-----by the end of this video is to be able to add multiply subtract in compare points without having to reference their attributes outside of the class so rightnow if I do p1 plus p2 our programsgonna crash because it doesn't know what that means but by the end of this video'''
class Point():
    def __init__(self,x=0,y=0):
        self.x=x
        self.y=y
        self.cords=(self.x,self.y)

    def move(self,x,y):
        self.x +=x
        self.y +=y   
    def __add__(self,p):
        return Point(self.x + p.x, self.y + p.y)
    
    def __sub__(self,p):
        return Point(self.x - p.x, self.y - p.y)
    
    def __mul__(self,p):
        return self.x * p.x, self.y * p.y
    
    def __str__(self):
        return "("+str(self.x)+','+str(self.y)+")"
    
    

p1=Point(3,4)
p2=Point(3,2)
p3=Point(1,3)
p4=Point(0,1)  

p5=p1+p2
p6=p4-p1
p7=p2*p3

print(p5,p6,p7)
    



