#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};

struct Node* top;

// function to push an element into a linked list
void push(int data){
    struct Node* temp;
    temp = new Node();

    if(!temp){
        cout<<"Heap Overflow";
        exit(1);
    }
    temp -> data = data;
    temp -> link = top;

    top = temp;
}

// function to check if stack is empty or not
int isEmpty(){
    return top == NULL; 
}

// function to return top element of the stack
int peek(){
    if(!isEmpty){
        return top-> data;
    }
    else exit(1);
}

// function to pop an element from the stack
void pop(){
    struct Node* temp;
    if(top == NULL){
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    else{
        temp = top;
        top = top -> link;
        temp -> link = NULL;
        free(temp);
    }
}

void display(){
    struct Node* temp;

    if(top == NULL){
        cout <<"Stack Underflow"<<endl;
        exit(1);
    }
    else{
        temp = top;
        while(temp != NULL){
            cout << temp -> data<< "->";
            temp = temp -> link;
        }
    }
}

int main(){
    push(11);
    push(22);
    push(33);
    display();

    pop();
    display();

    cout << "\n Top element is:" << peek()<<endl;

    return 0;
}
