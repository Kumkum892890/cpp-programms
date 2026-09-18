#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }

};
class circular {
    node* head;
    node* tail;

    public:
           circular(){
        head = tail = NULL;
    }
    void insetatHead(int val) {
        node* newNode = new node(val);
        if(head == NULL){
head = tail = newNode;
tail -> next = head;
        }
        else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }

    }
    void print() {
        if(head == NULL) return;
        cout<< head-> data<<"->";
        node* temp = head->next;
        while(temp != head){
            cout<<temp-> data<<"->";
            temp = temp->next;
        }
        cout<< temp->data<<endl;
    }
    void insertatTail(int val){
        node* newNode = new node(val);
        if(head == NULL){
            tail= head= newNode;
            tail->next = head;
        }
        else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteatHead() {
        if(head == NULL)  return ;
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            node* temp =head;
            head = head->next;
            tail-> next = head;
            temp-> next = NULL;
            delete temp;
        }
    }
    void delestTail(){
        if(head == NULL) {
            return;
        }
        else if(head = tail){
            delete head;
            head = tail =NULL;
        } else{
            node* temp = tail;
            node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
                tail= prev;
                tail->next= head;
                temp->next = NULL;
                delete temp;
            }

        }
    }
};
int main(){
    circular cll;
    cll.insetatHead(1);
       cll.insetatHead(2);
          cll.insetatHead(4);
    cll.print();
    cll.insertatTail(9);
  cll.print();
  cll.deleteatHead();
  cll.print();
 
  cll.delestTail();
  cll.print();
    return 0;
}

