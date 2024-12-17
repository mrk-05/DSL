#Name: ROSHAN VINOD NAGMAL
# Rollno- 35
#Practical no 4: Write a python program to store first year percentage of students in array. 
#Write function for sorting array of floating point numbers in asending order using
# a)Selection sort
# b)Bubble sort and display to five scores


def bubbleSort(arr):
    n = len(arr)
    # Traverse through all array elements
    for i in range(n-1):
        for j in range(0, n-i-1):
            # Traverse the array from 0 to n-i-1
            # Swap if the elements found is greater than the next elements
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

arr = []
Num = int(input("Enter the number of students you have to enter their percentage marks: "))
for i in range(Num):
    per = float(input("Enter the percntage marks of students: "))
    arr.append(per)

bubbleSort(arr) # Pass the arr value to function

print("Sorted array is: ")
for i in range(len(arr)):
    print(" %f " %arr[i])

arr2 = arr[::-1]
print("Top 5 Marks are: ")
if len(arr2) > 5:
    for i in range (5):
        print(" %f " %arr2[i])
else:
    for i in range(len(arr2)):
        print(" %f " %arr2[i])

def selectionSort(arr1):
    for i in range(len(arr1)):
        min_idx = i
        for j in range(i+1, len(arr1)):
            if arr1[min_idx] > arr1[j]:
                min_idx = j

    # Swap the found minimum elements with the first elements
        arr1[i], arr1[min_idx] = arr1[min_idx], arr1[i]

arr1 = []
num = int(input("Enter the number of students second time: "))
for i in range(num):
    per = float(input("Enter the percentage marks of students: "))
    arr1.append(per)

selectionSort(arr1)

# Deriver code to test above

print("Sorted array is: ")
for i in range(len(arr1)):
    print(" %f " %arr1[i])

arr2 = arr1[::-1]
print("Top 5 Students Marks: ")
if len(arr2) >5:
    for i in range(5):
        print(" %f " %arr2[i])
else:
    for i in range(len(arr2)):
        print(" %f " %arr2[i])


#Output:
#Enter the number of students you have to enter their percentage marks: 2
#Enter the percntage marks of students: 33
#Enter the percntage marks of students: 44
#Sorted array is:
 #33.000000
 #44.000000
#Top 5 Marks are:
 #44.000000
 #33.000000
