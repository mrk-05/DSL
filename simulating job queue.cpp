/*
  Name: ROSHAN VINOD NAGMAL
  Rollno- 35
Practical no. 11:    Queues are frequently used in computer programming, and a typical example is the creation of a job 
queue by an operating system. If the operating system does not use priorities,
then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. 
Write functions to add job and delete job from queue.
*/ 


#include <iostream>
using namespace std;

#define SIZE 5

int FRONT = -1;
int REAR = -1;
int QUEUE[SIZE];

void enqueue(int x) {
    if (REAR >= SIZE - 1)
        cout << "Queue is overflow";
    else {
        REAR = REAR + 1;
        QUEUE[REAR] = x;
        if (FRONT == -1)
            FRONT = 0;
    }
}

void dequeue() {
    if (FRONT == -1)
        cout << "Queue is underflow";
    else {
        cout << "Deleted element is: " << QUEUE[FRONT];
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        } else {
            FRONT = FRONT + 1;
        }
    }
}

void display() {
    int i;
    if (FRONT == -1)
        cout << "Queue is empty\n";
    else {
        for (i = FRONT; i <= REAR; i++)
            cout << QUEUE[i] << " ";
        cout << endl;
    }
}

int main() {
    int x, ch;
    while (1) {
        cout << "\n1: Add Job";
        cout << "\n2: Delete Job";
        cout << "\n3: Display";
        cout << "\n4: Exit Your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter Job: ";
                cin >> x;
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}


/*OUTPUT-

onworks@onworks-standerd-PC-i440fx-PIIX-1996:~/Desktop$ g++ PRACTICLE11.cpp
onworks@onworks-standerd-PC-i440fx-PIIX-1996:~/Desktop$ ./a.out
1: Add Job
2: Delete Job
3: Display
4: Exit Your Choice: 1
Enter Job: 12

1: Add Job
2: Delete Job
3: Display
4: Exit Your Choice: 2
Deleted element is: 12
1: Add Job
2: Delete Job
3: Display
4: Exit Your Choice: 3
Queue is empty
*/