#create an empty list

numbers = []

# Read ther size of the list
n = int(input("Enter the size of the list"))

# Reading the list elements
while True :
    if n > 0 :
        i = int(input("Enter the element to insert "))
        numbers.append(i)
        n-=1

    else :
        break


# print the contents of the list
print("List : ",numbers)

# performing the list operations
while (True) :
    print("\n=====MENU=====")
    print("1. Inserting at specific position \n2. Remove values from the list.\n3. Adding elements to the list.\n4. Displaying the list")
    choice = int(input("Enter the choice"))
    if choice == 1 :
        position = int(input("Enter the position to insert"))
        item = int(input("Enter the item to insert at position"))
        numbers.insert(position,item)
    elif choice == 2 :
        position = int(input("Enter the position to delete an item"))
        numbers.pop(position)
    elif choice == 3 :
        item = int(input("Enter an item to add"))
        numbers.append(item)
    elif choice == 4 :
        print("\n====List Content====")
        print(numbers)
    else :
        print("\nExiting")
        break
