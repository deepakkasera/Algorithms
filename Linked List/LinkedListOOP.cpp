#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d):data(d),next(NULL){}
};
class LinkedList{
public:
    Node*head;
    Node*tail;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insertAtFront(int d){
        if(head==NULL){
            head  = tail = new Node(d);

        }
        else{
            Node *n = new Node(d);
            n->next = head;
            head = n;
        }
    }
    void insertAtEnd(int d){
        if(head==NULL){
            head = tail = new Node(d);
        }
        else{
            Node* n = new Node(d);
            tail->next = n;
            tail = n;
        }
    }
    int length() const{
        Node* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    void insertAtPosition(int d,int p){
        if(p==0){
            insertAtFront(d);
        }
        else if(p>length()){
            insertAtEnd(d);
        }
        else{
            ///Insert in Middle
            Node* temp=head;
            int jumps=0;
            while(jumps<p-1){
                temp = temp->next;
                jumps++;
            }

            Node*n = new Node(d);
            n->next = temp->next;
            temp->next = n;

        }
    }
    void removeAtFront(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeAtEnd(){
        if(head==NULL){
            return;
        }
        Node* prev = head;
        while(prev->next!=tail){
            prev = prev->next;
        }
        delete tail;
        prev->next = NULL;
        tail = prev;
    }
    void removeAtPosition(int p){
        if(p==0){
            removeAtFront();
        }
        else if(p>=length()){
            removeAtEnd();
        }
        else{
            int jumps=0;
            Node*temp = head;
            while(jumps<p-1){
                jumps++;
                temp = temp->next;
            }
            Node* n  = temp->next;
            temp->next = n->next;
            delete n;
        }

    }
    void print(){
        Node*temp = head;
        while(temp!=NULL){
            cout<< temp->data <<"-->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    Node* getMid(){
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node* fast = head->next;
        Node* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    friend ostream& operator<<(ostream& os,LinkedList &l);
};

istream& operator>>(istream& is,LinkedList &l){
    int d;
    is>>d;

    while(d!=-1){
        l.insertAtEnd(d);
        cin>>d;
    }
    return is;
}
ostream& operator<<(ostream& os,LinkedList &l){
    Node*temp = l.head;
        while(temp!=NULL){
            cout<< temp->data <<"-->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
}

Node* merge(Node*a,Node*b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        Node* newHead;
        if(a->data < b->data ){
            newHead = a;
            newHead->next = merge(a->next,b);
        }
        else{
            newHead = b;
            newHead->next = merge(a,b->next);
        }
        return newHead;
}
void reverse(Node*head){
    Node*prev = NULL;
    Node*current = head;
    Node*next;

    while(current!=NULL){
        ///Save the next node
        next = current->next;

        ///Reverse the arrow
        current->next = prev;
        ///Update Prev and Current to next position
        prev = current;
        current = next;
    }
    head = prev;
}
Node* findMid(Node*head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node* fast = head->next;
        Node* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
Node* mergeSort(Node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    ///Otherwise
    Node*mid = findMid(head);
    Node* a = head;

    Node* b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    Node* newHead = merge(a,b);
    return newHead;
}


int main(){

            LinkedList l;
        l.insertAtFront(4);
        l.insertAtFront(2);
        l.insertAtFront(1);
        l.insertAtFront(0);
        l.insertAtEnd(5);
        l.insertAtEnd(6);
        l.print();

        l.insertAtPosition(3,3);
        l.print();

        l.removeAtFront();
        l.removeAtEnd();
        l.print();
        l.removeAtPosition(3);
        l.print();

        LinkedList l2,l3;
        cin>>l2>>l3;
        cout<<l2<<l3;
        l2.head = mergeSort(l2.head);
        l3.head = mergeSort(l3.head);
        //l2.head = merge(l2.head,l3.head);
        cout<<l2<<endl;
        //reverse(l2.head);
        cout<<l3<<endl;
return 0;
}