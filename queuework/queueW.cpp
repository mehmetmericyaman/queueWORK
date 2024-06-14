#include <iostream>

using namespace std;

class QueueNode{
    public:
    int data;
    QueueNode *next;
    QueueNode(const int& data= 0, QueueNode *next=NULL): data(data), next(next){}

};
class Queue{
    QueueNode *root;
    void makeEmpty(){ //dışardan erişilmemesi lazım gibi düşün ondan private
        while(!isEmpty())
            dequeue();
    }
    public:
    Queue() : root(NULL){}
    Queue(const Queue &rhs) : Queue() {*this = rhs;} //copy cnst.
    ~Queue(){makeEmpty();}//dest.
    Queue &assing(const Queue &rhs){
        makeEmpty();
        QueueNode *tmp=rhs.root;
        while(tmp != NULL){
            enqueue(tmp->data);
            tmp=tmp->next;
        }
        return *this;
    }
    bool isEmpty()const{ return root ==NULL; }
    void enqueue(const int &value){
        if(isEmpty())
            root= new QueueNode(value);
        else{
            QueueNode *tmp= root;
            while(tmp->next != NULL){
                tmp=tmp->next;            
            }
            tmp->next= new QueueNode(value);
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"BOŞŞŞ"<<endl;
        }
        else{
            QueueNode *tmp=root;
            root=root->next;
            delete tmp;
        }
    }
    int size()const{
        if(isEmpty()){
            return 0;
        }
        else{
            QueueNode *tmp= root;
            int size=1;
            while(tmp->next!=NULL){
                tmp=tmp->next;
                size++;
            }
            return size;
            
        }
    }
    void print()const{
        QueueNode *tmp = root;
        while(tmp != NULL){
            cout<< tmp->data << " ";
            tmp = tmp->next;
        }
        cout<< endl;
    }
    int front()const{
        if(isEmpty()){
            cout<<"BOŞşş"<<endl;
        }
        else
            return root->data;
    }
    int back()const{
        QueueNode *tmp= root;
        if(isEmpty()){
            cout<<"BOŞşş"<<endl;
        }
        else{
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            return tmp->data;
        }

    }
};
int main(){
    Queue q;
    cout<< q.isEmpty()<<endl;
    q.enqueue(15);
    q.enqueue(10);
    q.enqueue(45);
    q.enqueue(7);
    q.enqueue(99);
    q.print();
    q.dequeue();
    q.print();
    cout<<"size: "<<q.size()<<endl;
    cout<<"ilkkk: "<<q.front()<<endl;
    cout<<"sonn: "<<q.back()<<endl;
    Queue q2;
    q2.assing(q);
    q2.print();







    return 0;
}