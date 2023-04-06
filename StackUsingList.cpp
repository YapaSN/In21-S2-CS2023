#include<iostream>
#include<ctime>
#include<chrono>

#define length 20 //length of the stack

using namespace std;
using namespace std :: chrono;

struct Node{
    //initializing node for the stack
    int data;
    struct Node *next;
};

struct Node* head = NULL; //head pointer

bool isEmpty(){
    //check whether the stack is empty
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void push(int element){
    //push an element to the stack
    Node* newNode = new Node(); //creating a node for the new element
    
    newNode->data = element;
    newNode->next = NULL;

    if (isEmpty()){
        //add new node as the first element if the stack is empty
        head = newNode;
    }
    else{
        //add new element to the end of the stack
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int pop(){
    //pop an elment from the stack
    int value;
    
    if(isEmpty()){
        //check whether the stack is empty before popping an element
        cout << "Stack underflow." << endl;
    }

    else if(head->next == NULL){
        value = head->data;
        head = NULL;
        return value;
    }
    else{
        //pop an element from the stack
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        value = temp->next->data;
        temp->next = NULL;
        return value;
    }
}

void display(){
    //display the current stack
    if(isEmpty()){
        cout << "Stack is empty. Nothing to display." << endl;
        return;
    }
    else{
        cout << "Updated array: ";
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return;
}


int main(int argc, char const *argv[])
{
    int popped;

    auto start = high_resolution_clock::now();
   
    {push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();}

    // stop the clock
    auto stop = high_resolution_clock::now();

    // calculate the elapsed time
    auto duration = duration_cast<microseconds>(stop - start);

    // print the elapsed time in seconds and microseconds
    cout << "Elapsed time: " << duration.count() / 1000000.0 << " seconds (" << duration.count() << " microseconds)" << endl;

    return 0;
}
