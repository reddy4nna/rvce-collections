# Writing a return is optional in a function
'''def name():
    print('RVCE')
name() '''
#Write
#syntax=filename.write('content')
'''file=open('myfile.txt','w')
file.write('string')'''
#REad
'''file=opem.('myfile','r')
data=file.read()
print(data)'''

#Question--> Create a text file called my_file.txt with some content and capitalize the first letter of every word and print the content of the file in reverse order 
def write():
    string=input('enter the text ')
    file=open('myy_file.txt','w')
    file.write(string)
    file.close
def read():
    file=open('myy_file.txt','r')
    data=file.read()
    print(data)    
    print(data.title())
    print(data[::-1])
write()
read()    











