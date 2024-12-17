/*
  Name: ROSHAN VINOD NAGMAL
  Rollno- 35
Practical no. 8: The ticket booking system of Cinemax theater has to be implemented using C++ program. 
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. 
Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand 
a) The list of available seats is to be displayed 
b) The seats are to be booked 
c) The booking can be cancelled*/


#include <iostream>
using namespace std;

class Node {
public:
    bool isBooked;
    Node* next;
    Node* prev;

    Node(bool booked = false) {
        isBooked = booked;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    void createCircularList(int seats) {
        head = new Node(false);
        Node* current = head;

        for (int i = 1; i < seats; ++i) {
            Node* newNode = new Node(false);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }

        current->next = head;
        head->prev = current;
    }

    void displayAvailableSeats() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            if (!temp->isBooked) {
                cout << "Seat is available." << endl;
            } else {
                cout << "Seat is booked." << endl;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void bookSeat(int seatNumber) {
        Node* temp = head;
        for (int i = 0; i < seatNumber - 1; ++i) {
            temp = temp->next;
        }

        if (temp->isBooked) {
            cout << "Seat already booked." << endl;
        } else {
            temp->isBooked = true;
            cout << "Seat booked successfully." << endl;
        }
    }

    void cancelBooking(int seatNumber) {
        Node* temp = head;
        for (int i = 0; i < seatNumber - 1; ++i) {
            temp = temp->next;
        }

        if (!temp->isBooked) {
            cout << "Seat is not booked." << endl;
        } else {
            temp->isBooked = false;
            cout << "Booking canceled successfully." << endl;
        }
    }
};

int main() {
    const int rows = 10;
    const int seatsPerRow = 7;

    CircularLinkedList* rowsList[rows];

    for (int i = 0; i < rows; ++i) {
        rowsList[i] = new CircularLinkedList();
        rowsList[i]->createCircularList(seatsPerRow);
    }

    int choice;
    do {
        cout << "1. Display available seats\n2. Book a seat\n3. Cancel booking\n4. Exit\nEnter choice: ";
        cin >> choice;

        int row, seat;
        switch (choice) {
            case 1:
                cout << "Enter row number: ";
                cin >> row;
                rowsList[row - 1]->displayAvailableSeats();
                break;
            case 2:
                cout << "Enter row number and seat number: ";
                cin >> row >> seat;
                rowsList[row - 1]->bookSeat(seat);
                break;
            case 3:
                cout << "Enter row number and seat number: ";
                cin >> row >> seat;
                rowsList[row - 1]->cancelBooking(seat);
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


#OUTPUT-
#onworks@onworks-standerd-PC-i440fx-PIIX-1996:~/Desktop$ g++ PRACTICLE8.cpp
#onworks@onworks-standerd-PC-i440fx-PIIX-1996:~/Desktop$ ./a.out
#1. Display available seats
#2. Book a seat
##3. Cancel booking
#4. Exit
#Enter choice: 2
#Enter row number and seat number: 10 7
#Seat booked successfully.
#1. Display available seats
#2. Book a seat
#3. Cancel booking
#4. Exit
#Enter choice: 1
#Enter row number: 10
#Seat is available.
#Seat is available.
#Seat is available.
#Seat is available.
#Seat is available.
#Seat is available.
#Seat is booked.
#1. Display available seats
#2. Book a seat
#3. Cancel booking
#4. Exit
#Enter choice: 3
#Enter row number and seat number: 10 7
#Booking canceled successfully.