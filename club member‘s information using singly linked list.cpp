/* Name : ROSHAN VINOD NAGMAL
  Rollno - 35

 Practical no. 7: Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. 
 Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. 
 Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. 

a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists.*/

#include <iostream>
#include <string>
using namespace std;

class ClubList {
private:
    struct Node {
        int PRN;
        string name;
        Node* next;
    };
    Node* president; // First Node
    Node* secretary; // Last Node

public:
    ClubList() {
        president = new Node();
        secretary = new Node();
        president->next = secretary;
        secretary->next = nullptr;
    }

    void insertPresident(int prn, const string& name) {
        Node* newNode = new Node();
        newNode->PRN = prn;
        newNode->name = name;
        newNode->next = president->next;
        president->next = newNode;
    }

    void displayMembers() {
        Node* current = president->next;
        cout << "**** Members in Club ****" << endl;
        while (current != secretary) {
            cout << current->PRN << "  " << current->name << endl;
            current = current->next;
        }
    }

    // Other methods can be implemented similarly based on user menu choices
    // For example, deletePresident, deleteSecretary, deleteMember, countMembers, reverseDisplay, etc.
};

int main() {
    ClubList club;

    int choice;
    do {
        cout << "Enter Your Choice : (1.Insert President 2.Insert Secretary 3.Insert Member 4.Delete President 5.Delete Secretary 6.Delete Member 7.Display 8.Count 9.Reverse 10.Concat 11.Exit)" << endl;
        cin >> choice;
        int prn;
        string name;
        switch (choice) {
            case 1:
                cout << "Enter PRN and Name:" << endl;
                cin >> prn >> name;
                club.insertPresident(prn, name);
                club.displayMembers();
                break;
            // Add cases for other menu options as required
            case 7:
                club.displayMembers();
                break;
            case 11:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 11);

    return 0;
}/*
****Linked List*****

1.Insert President 
2.Insert Secretary 
3.Insert Member 
4.Delete President 
5.Delete Secretary 
6.Delete Member 
7.Display 
8.Count  
9.Reverse 
10.Concat 
11.Exit

Enter Your Choice :(1.Insert President 2.Insert Secretary 3.Insert Member 4.Delete President 5.Delete Secretary 6. Delete Member 7.Display 8.Count 9. Reverse 10.Concat 11.Exit)
1
Enter PRN and Name:
35 Roshan
**** Members in Club ****
35  Roshan

Enter Your Choice :(1.Insert President 2.Insert Secretary 3.Insert Member 4.Delete President 5.Delete Secretary 6. Delete Member 7.Display 8.Count 9. Reverse 10.Concat 11.Exit)



*/
