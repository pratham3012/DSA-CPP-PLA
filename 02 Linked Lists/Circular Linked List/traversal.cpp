#include<iostream>
using namespace std;

// Program to traverse the circular linked list

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    private:
        Node* head;
    public:
    LinkedList(){
        head = NULL;
    }

    // Add new element at the end of the list
    void addEnd(int newElement){
        Node* newNode = new Node();
        newNode -> data = newElement;
        newNode -> next = NULL;
        if(head == NULL){
            head = newNode;
            newNode -> next = head;
        }

    }

    // Print all the elements added in the list
    void printList(){
        Node* temp = head;
        if (temp != NULL){
            cout<< "The list contains: ";
            while(true){
                cout << temp -> data << " ";
                temp = temp -> next;
                if(temp == head)
                    break;
            }
            cout << endl;
        }
        else{
            cout<< "The list is empty:";
        }
    }
};

int main(){
    LinkedList MyList;

    MyList.addEnd(10);
    MyList.addEnd(20);
    MyList.addEnd(30);
    MyList.addEnd(40);

    MyList.printList();
    return 0;
}