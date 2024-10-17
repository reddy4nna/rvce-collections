# Database of an employee using dictionary and perform operations such as insert etc.
#dic={key1:valuepairs,key2:valuepairs}
#dic={"brand":"Ford","model":"Mustang","year":1964}
#print(dic)
#access  = get is used and will be operated on key value 
'''print(dic.get("brand"))
print(dic.get("model"))
print(dic.get("year"))'''
#dic.pop("model")
#print(dic)
#employee= dic={}
'''empid=int(input("enter the  employee id"))
empdetails=[]
empname=input("enter the name ")
empdob=input("enter date of birth")
empdesg=input("enter the  designaiton")
empdetails.append(empname)
empdetails.append(empdob)
empdetails.append(empdesg)'''



#problem statment = create an employee database using the dictionaries and perfrom insert search display and delete operations 


# Creating the Dictionary
'''Employee = dict()



while True:

    print("===== Employee Database =====\n")
    print(" 1. Create Employee\n 2. Add New Employee\n 3. Search Employee\n 4. Delete Employee\n 5. Display\n")
    print("=============================")

    Choice = int(input("Enter the Choice: "))
    
    if Choice == 1:
        n = int(input("Enter the Number of Employees: "))
        for i in range(n):
            print("---------------------------------------")
            print("Enter the Employee {0} Details".format(i+1))
            print("---------------------------------------")
            EmpId = int(input("Enter the EmployeeId: "))

            EmpDetails = []
            EmpName = input("Enter the Employee Name: ")
            EmpDOB = input("Enter the DOB: ")
            Designation = input("Enter the Disignation: ")

            EmpDetails.append(EmpName)
            EmpDetails.append(EmpDOB)
            EmpDetails.append(Designation)
            Employee[EmpId] = EmpDetails
            print("---------------------------------------")
       
    elif Choice == 2:
        EmpId = int(input("Enter the EmployeeId: "))

        EmpDetails = []
        EmpName = input("Enter the Employee Name: ")
        EmpDOB = input("Enter the DOB: ")
        Designation = input("Enter the Disignation: ")

        EmpDetails.append(EmpName)
        EmpDetails.append(EmpDOB)
        EmpDetails.append(Designation)
        Employee[EmpId] = EmpDetails
        print("-------------------------------------------")

    elif Choice == 3:
        EId = int(input("Enter the EmployeeId to Display: "))
        print(Employee.get(EId))
        print("-------------------------------------------")
              

    elif Choice == 4:
        EId = int(input("Enter the EmployeeId to Delete: "))
        print(Employee.pop(EId))
        print("-------------------------------------------")

    elif Choice == 5:
        Status = bool(Employee)
        if  Status == False:
            print("\n No Employee Details Found to Print \n")
        else:
            print(Employee)

    else:
        print("Invalid Choice")
        break'''



'''Sets and Tuples
Set is a collection of objects it doesnt have any particular order n=basically no indexing also a set cannot have duplicate values it will only print unique values
to add values in a set we use add funciton  
Tuple is ordered basically indexed and is immutable  '''

'''set={"apple","banana","1","apple"}
x={"mango","apple"}
set.update(x)'''
#print(set)
'''tuple=('apple','banana','apple')
print(tuple)
y='mango'''



print(list(range(2, 10, 2)))


