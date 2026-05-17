#include <bits/stdc++.h>
using namespace std;
typedef struct Elementtype{
    int id;
    char *name;
}Element;
struct StackInfo{
    int capacity;
    int count;
    Element *thearray;
};
typedef struct StackInfo *Stack;
Stack create_stack(int capacity){
    Stack S=new StackInfo;
    S->capacity=capacity;
    S->count=0;
    S->thearray=new Element[capacity];
    return S;
}
int is_empty(Stack S){
    return S->count==0;
}
int is_full(Stack S){
    return S->count==S->capacity;
}
int push(Stack S,Element e){
    if(is_full(S)){
        return 0;
    }
    S->thearray[S->count]=e;
    S->count++;
    return 1;
}
Element* pop(Stack S){
    if(is_empty(S))return nullptr;
    S->count--;
    return &S->thearray[S->count];
}
Element* top(Stack S){
    if(is_empty(S))return nullptr;
    return &S->thearray[S->count-1];
}
// ✅ Thêm hàm in stack để kiểm tra
void print_stack(Stack S) {
    if (is_empty(S)) {
        cout << "Stack rong!" << endl;
        return;
    }
    cout << "Stack (top -> bottom):" << endl;
    for (int i = S->count - 1; i >= 0; i--) {
        cout << "  [" << S->thearray[i].id << "] " << S->thearray[i].name << endl;
    }
}
// ✅ Giải phóng bộ nhớ
void destroy_stack(Stack S) {
    delete[] S->thearray;
    delete S;
}
int main() {
    // ✅ Sửa: truyền capacity vào create_stack
    Stack S = create_stack(10);
    Element e1, e2, e3;
    // ✅ Sửa: bỏ dấu = thừa trước e1.name / e2.name / e3.name
    e1.id = 1; e1.name = (char*)"Nguyen Van A";
    e2.id = 2; e2.name = (char*)"Nguyen Van B";
    e3.id = 3; e3.name = (char*)"Nguyen Van C";
    // Push các phần tử vào stack
    push(S, e1);
    push(S, e2);
    push(S, e3);
    cout << "=== Sau khi push 3 phan tu ===" << endl;
    print_stack(S);
    // Xem phần tử đỉnh (top)
    Element* t = top(S);
    if (t) cout << "\nTop: [" << t->id << "] " << t->name << endl;
    // Pop một phần tử
    Element* p = pop(S);
    if (p) cout << "Da pop: [" << p->id << "] " << p->name << endl;
    cout << "\n=== Sau khi pop 1 phan tu ===" << endl;
    print_stack(S);
    destroy_stack(S);
    return 0;
}