#include<iostream>
using namespace std;

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

    //Add 3 elements at the end of linked list
    void addEnd(int newElement)
    {
        Node *newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }

    // Delete the last node of the linked list
    void deleteLast(){
        if(head != NULL){
            if(head -> next = NULL){
                head = NULL;
            }
            else{
                Node* temp = head;
                while(temp -> next -> next = NULL){
                    temp = temp -> next;
                }
                Node* lastNode = temp -> next;
                temp -> next = NULL;
                free(lastNode);
            }
        }
    }

    // Prints the Linked List
    void printList(){
        Node* temp = head;
        if(temp != NULL){
            cout << "The list contains: ";
            while(temp != NULL){
                cout << temp -> data<< " ";
                temp = temp -> next;
            }
            cout << endl;

        }
        else {
            cout<< "The list is empty: \n";
        }
    }
};

int main(){
   LinkedList MyList;

   //Add 5 elements in the last
   MyList.addEnd(10);
   MyList.addEnd(20);
   MyList.addEnd(30);
   MyList.addEnd(40);
   MyList.addEnd(50); 
    MyList.printList();
    
    // Delete the last nodes 
    MyList.deleteLast();
   
    // Print the List
    MyList.printList();


}