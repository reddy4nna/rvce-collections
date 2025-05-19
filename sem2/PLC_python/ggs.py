# Read the input
n = int(input("Enter the Number: "))
maxPrime = -1

# Run this loop for even numbers
while n % 2 == 0:
    maxPrime = 2
    n = n // 2

# Run this loop for odd numbers from 3 to sqrt(n)
for i in range(3, int(n**0.5) + 1, 2):
    while n % i == 0:
        maxPrime = i
        n = n // i

# If n is a prime number greater than 2
if n > 2:
    maxPrime = n

print("Max Prime factor:", int(maxPrime))
