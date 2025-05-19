Employee = dict()

while True:
    print("1.Insert\n2.Search\n3.Display\n4.Exit")
    choice = int(input("enter choice:"))
    if choice == 1:
        EmpId = int(input("enter employee Id:"))
        
        EmpDetails = []
        EmpName = input("enter employee Name:")
        EmpDOB = input("enter employee DOB:")
        EmpDesignation = input("enter employee designation:")

        EmpDetails.append(EmpName)
        EmpDetails.append(EmpDOB)
        EmpDetails.append(EmpDesignation)

        Employee[EmpId] = EmpDetails

    elif choice == 2:
        EmpId = int(input("enter employee Id for the employee details to be searched:"))
        print(Employee[EmpId])

    elif choice == 3:
        status = bool(Employee)
        if status == False:
            print("no employee details found")
        else:
            print(Employee)

    elif choice == 4:
        break

    else:
        print("enter valid choice")
