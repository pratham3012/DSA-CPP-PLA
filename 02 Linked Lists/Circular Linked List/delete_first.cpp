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

    // Add nodes at the end of the linked list
    void addEnd(int newElement) {
      Node* newNode = new Node();
      newNode->data = newElement;
      newNode->next = NULL; 
      if(head == NULL) {
        head = newNode;
        newNode->next = head;
      } else {
        Node* temp = head;
        while(temp->next != head)
          temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
      }    
    }

    //Delete the first node of the linked list
    void deleteFirst(){
        if(head != NULL){
            if(head -> next == NULL){
                head = NULL;
            }
            else{
                Node* temp = head;
                Node* firstNode = head; 
                while(temp -> next != head){
                    temp = temp -> next;
                }
                head = head -> next;
                temp -> next = head;
                free(firstNode);
            }
        }
    }
    // Prints the linked list
    void PrintList() {
      Node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(true) {
          cout<<temp->data<<" ";
          temp = temp->next;
          if(temp == head) 
            break;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    }  
};

int main(){
    LinkedList MyList;
    
    MyList.addEnd(10);
    MyList.addEnd(20);
    MyList.addEnd(30);
    MyList.addEnd(40);
    
    MyList.PrintList();

    MyList.deleteFirst();
    MyList.PrintList();

    return 0;


}