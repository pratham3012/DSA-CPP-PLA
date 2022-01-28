#include<iostream>
using namespace std;

//Program to insert a node in doubly linked list at given position

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
    
    //Add new element at the end of the list
    void addEnd(int newElement){
        Node* newNode = new Node();
        newNode -> data = newElement;
        newNode -> next = NULL;
        newNode -> prev = NULL;
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> prev = temp;
        }
    }

    void addPosition(int position, int newElement){
        Node* newNode = new Node();
        newNode -> data = newElement;
        newNode -> next = NULL;
        newNode -> prev = NULL;

        if(position < 1){
            cout << "Position should be greater than or equal to 1";
        }
        else if (position == 1){
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
        else{
            Node* temp = head;
            for(int i=0; i < position-1; i++){
                if(temp != NULL){
                    temp = temp -> next;
                }
            }
            if(temp != NULL){
                newNode -> next = temp -> next;
                newNode -> prev = temp;
                temp -> next = newNode;
                if( newNode -> next != NULL){
                    newNode -> next -> prev = newNode;
                }
                else{
                    cout << "The previous node is already null";
                } 
            }
        }
    }

    // Print the linked list
    void printList(){
        Node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(temp != NULL) {
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    } 
};

int main(){
    LinkedList MyList;

    // Add elements at the back of the linked list
    MyList.addEnd(10);
    MyList.addEnd(20);
    MyList.addEnd(30);
    MyList.addEnd(40);
    MyList.addEnd(50);
    MyList.printList();

    MyList.addPosition(2,40);
    MyList.printList();
}