#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
 
public:
    Node(T data){
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class stack{
public:
    Node<T>* head;
    int size;
    stack(){
        head = NULL;
        size = 0;
    }
    int sizestack(){
        return size;
    }
    bool isempty(){
       return size == 0;
    }
    T top(){
       if(isempty()){
        cout<<"stack is empty"<<endl;
        return 0;
       }
       else return head->data;
    }
    void push(T element){
        Node<T> *n = new Node<T> (element);
        if(head == NULL){
            head = n;
            size++;
        }
        else {
            n->next = head;
            head = n;
            size++;
        }
        cout<<head->data<<endl;
    }
    T pop(){
         if(isempty()){
        cout<<"stack is empty"<<endl;
 
       }
       else {
        Node<T>* top =  head;
         head = head->next;
         size--;
         top->next = NULL;
         Node<T> *temp;
         temp->data =  top->data;
         delete top;
         return temp->data;
 
       }
    }
 
};
int main(){
    ios_base::sync_with_stdio(false);
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    cout<<s.sizestack()<<endl<<endl;
 
    stack<char> c;
    c.push('a');
    c.push('b');
    c.push('c');
    c.push('d');
    c.push('e');
    cout<<c.pop()<<endl;
    cout<<c.pop()<<endl;
    cout<<c.top()<<endl;
    cout<<c.sizestack()<<endl;
}