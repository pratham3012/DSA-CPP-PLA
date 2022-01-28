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
    return 0;
}