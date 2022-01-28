#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class Stack{
    private:
        node* top;
    public:
    Stack(){
        top = NULL;
    }  
    
    void push(int val){
        node* temp;
        temp = new node;    
        cout<<"Enter Data:";
        cin>>temp -> data;
        temp -> next = top;
        top = temp;
    }

    void pop(){
        if(top != NULL){
            node* temp = top;
            top= top-> next;
            cout<< temp -> data <<"Deleted";
            delete temp;
        }
        else{
            cout<<"Stack Empty";
        }
    }

    void display(){
        node* temp = top;
        while(temp != NULL){
            cout<<temp -> data<<" "<<endl;
            temp = temp -> next;
        }
    }
};

int main(){

    Stack st;
    int ch, val;
    cout<<"Select the operation:"<<endl;
    cout<<"1. Push in Stack"<<endl;
    cout<<"2. Pop in Stack"<<endl;
    cout<<"3. Display Stack"<<endl;
    do{
        cout<<"Enter Choice: "<<endl;
        cin>>ch;
        switch(ch){
            case 1 : {
                st.push(val);
                break;
            }
            case 2: {
                st.pop();
                break;
            }
            case 3:{
                st.display();
                break;  
            }
            default: cout<< "Select from above choices:/ - Run Again :) "<<endl;
        }
    } while(ch!=4);
    return 0;

}