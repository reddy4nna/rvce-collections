'''a=-16
v=int(input("enter the value of velocity"))
t=-v/(2*a)
h = -16*t*t + v*t
ph= float(input("enter the player height"))
print(h+ph)'''

# we need to remember the formula 

'''list=[1,2]
list.append(3)
print(list)'''

n=int(input("enter the value of n "))
fiblist = [0,1]
for i in range (0,n):
    fiblist.append(fiblist[i]+fiblist[i+1])
print(fiblist)  
for i in range (1,n+1) :
    goldenratio = fiblist[i+1]/fiblist[i]
    print(goldenratio)
    

    













