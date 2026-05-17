#include <bits/stdc++.h>
using namespace std;
typedef struct Elementtype{
    int id;
    const char *name;
}Element;
struct QueueInfo{
    int capacity;
    int count;
    int front;
    int rear;
    Element *thearray;
};
typedef struct QueueInfo* Queue;
Queue create_queue(int capacity){
    Queue q=new QueueInfo;
    q->capacity=capacity;
    q->count=0;
    q->front=1;
    q->rear=0;
    q->thearray=new Element[capacity];
    return q;
}
int is_full(Queue q){
    return q->count==q->capacity;
}
int isEmpty(Queue q){
    return q->count==0;
}
int increase(int value,int capacity){
    value++;
    if(value>=capacity){
        return 0;
    }
    return value;
}
int enqueue(Queue q,Element e){
    if(is_full(q)){
        return 0;
    }
    q->rear=increase(q->rear,q->capacity);
    q->thearray[q->rear]=e;
    q->count++;
    return 1;
}
Element* dequeue(Queue q){
    if(isEmpty(q))return nullptr;
    Element*tmp=&q->thearray[q->front];
    q->front=increase(q->front,q->capacity);
    q->count--;
    return tmp;
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   Element e1,e2,e3;
   e1.id=1;e1.name="Nguyen van a";
   e2.id=2;e2.name="Nguyen van b";
   e3.id=3;e3.name="Nguyen van c";
   Queue q=create_queue(10);
   enqueue (q,e1);
   enqueue (q,e2);
   enqueue(q,e3);
   while(!isEmpty(q)){
    Element*tmp=dequeue(q);
    cout<<"Id: "<<tmp->id<<" Name:"<<tmp->name<<endl;
   }
   return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

struct Element {
    int id;
    string name;
};

class Queue {
private:
    int capacity;
    int count;
    int front;
    int rear;
    vector<Element> arr;

    int increase(int value) {
        value++;
        if (value >= capacity)
            return 0;
        return value;
    }

public:
    Queue(int cap) {
        capacity = cap;
        count = 0;
        front = 0;
        rear = -1;
        arr.resize(capacity);
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    bool enqueue(Element e) {
        if (isFull())
            return false;

        rear = increase(rear);
        arr[rear] = e;
        count++;

        return true;
    }

    Element dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue rong");
        }

        Element temp = arr[front];
        front = increase(front);
        count--;

        return temp;
    }
};

int main() {

    Queue q(10);

    q.enqueue({1, "Nguyen Van A"});
    q.enqueue({2, "Nguyen Van B"});
    q.enqueue({3, "Nguyen Van C"});

    while (!q.isEmpty()) {
        Element x = q.dequeue();

        cout << "ID: " << x.id
             << " | Name: " << x.name << endl;
    }

    return 0;
}


*/