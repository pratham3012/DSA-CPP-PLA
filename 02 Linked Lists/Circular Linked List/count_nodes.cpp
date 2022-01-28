#include <iostream>
using namespace std;

//node structure
struct Node {
    int data;
    Node* next;
};

class LinkedList {
  private:
    Node* head;
  public:
    LinkedList(){
      head = NULL;
    }
 
    //Add new element at the end of the list
    void push_back(int newElement) {
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

    //count nodes in the list
    int countNodes() {
      Node* temp = head;
      int i = 0;
      if(temp != NULL) {
        i++;
        temp = temp->next;
      }
      while(temp != head) {
        i++;
        temp = temp->next;
      }
      return i;  
    } 

    //display the content of the list
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

// test the code 
int main() {
  LinkedList MyList;

  //Add four elements in the list.
  MyList.push_back(10);
  MyList.push_back(20);
  MyList.push_back(30);
  MyList.push_back(40);

  //Display the content of the list.
  MyList.PrintList();

  //number of nodes in the list
  cout<<"No. of nodes: "<<MyList.countNodes();
  
  return 0; 
}