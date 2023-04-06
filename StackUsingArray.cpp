#include<iostream>
#include<ctime>
#include<chrono>

#define length 20 //length of the stack

using namespace std;
using namespace std :: chrono;

int arr[length]; //initializing the stack
int head = -1; //head pointer

bool isEmpty(){
    //check whether the stack is empty
    if(head < 0){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    //check whether the stack is full
    if(head < (length-1)){
        return false;
    }
    else{
        return true;
    }
}

void push(int element){
    //push an element to the stack
    head++;

    if (isFull()){
        //check whether the stack is full before pushing an element
        cout << "Stack Overflow." << endl;
        return;
    }
    else{
        arr[head] = element;
        return;
    }
    return;
}

int pop(){
    //pop an element from the stack
    int value;

    if (isEmpty()){
        //check whether the stack is empty before popping an element
        cout << "Stack underflow." << endl;
    }
    else{
        value = arr[head];
        head--;
        return value;
    }
    // return;
}

void display(){
    //display the current stack
    if(!isEmpty()){
        cout << "updated stack : " ;
        for (int i = 0; i < head+1; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < head+1; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;

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
