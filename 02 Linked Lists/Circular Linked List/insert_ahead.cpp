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

    void addAhead(int newElement){
        Node* newNode = new Node();
        newNode -> data = newElement;
        newNode -> next = NULL;
        if(head == NULL) {
            head = newNode;
            newNode -> next = head;
        }
        else{
            Node* temp = head;
            while(temp -> next != head){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = head;
            head = newNode;
        }
    }

    void printList(){
        Node* temp = head;
        if(temp != NULL){
            cout << "The List Contains: ";
            while(true){
                cout<< temp -> data << "";
                temp = temp -> next;
                if(temp == head){
                    break;
                }
            }
        }
        else{
            cout<<"The list is empty:";
        }
    }
};

int main(){
    LinkedList MyList;

    MyList.addAhead(10);
    MyList.addAhead(20);
    MyList.addAhead(30);
    MyList.addAhead(40);

    MyList.printList();
    return 0;
}