#include <bits/stdc++.h>
using namespace std;
typedef struct elementtype{
    int id;
    char *name;
}Element;
struct NodeInfo{
    Element e;
    struct Nodeinfo*next;
};
typedef struct NodeInfo *Node;
typedef struct NodeInfo *Stack;
Stack create(){
    Node header=new NodeInfo;
    header->next=nullptr;
    return header;
}
int is_empty(Stack S){
    return S->next==nullptr;
}
void push(Stack S,Element e){
    Node newnode= new NodeInfo;
    newnode->e=e;
    nenwode->next=S->next;
    S->next=newnode;
}
Node pop(Stack S){
    if(is_empty(S)){
        return NULL;
    }


}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   
}
/*
#include <bits/stdc++.h>
using namespace std;

typedef struct elementtype {
    int id;
    char *name;
} Element;

struct NodeInfo {
    Element e;
    struct NodeInfo *next;
};

typedef struct NodeInfo *Node;
typedef struct NodeInfo *Stack;

// ✅ Tạo stack rỗng
Stack create() {
    Node header = new NodeInfo;
    header->next = nullptr;
    return header;
}

// ✅ Kiểm tra stack rỗng
int is_empty(Stack S) {
    return S->next == nullptr;
}

// ✅ Push: thêm phần tử vào đỉnh stack
void push(Stack S, Element e) {
    Node newnode = new NodeInfo;
    newnode->e = e;
    newnode->next = S->next;  // fix typo: nenwode -> newnode
    S->next = newnode;
}

// ✅ Pop: lấy và xóa phần tử ở đỉnh — trả về node (NULL nếu rỗng)
Node pop(Stack S) {
    if (is_empty(S)) return NULL;

    Node top = S->next;       // lấy node đỉnh
    S->next = top->next;      // nối header sang node kế tiếp
    top->next = nullptr;      // cắt liên kết an toàn
    return top;               // caller chịu trách nhiệm delete
}

// ✅ Peek: xem phần tử đỉnh mà KHÔNG xóa
Node peek(Stack S) {
    if (is_empty(S)) return NULL;
    return S->next;
}

// ✅ Đếm số phần tử trong stack
int size(Stack S) {
    int count = 0;
    Node cur = S->next;
    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }
    return count;
}

// ✅ In toàn bộ stack từ đỉnh xuống đáy
void print_stack(Stack S) {
    if (is_empty(S)) {
        printf("Stack rong!\n");
        return;
    }
    Node cur = S->next;
    printf("Stack (dinh -> day): ");
    while (cur != nullptr) {
        printf("[id=%d, name=%s] ", cur->e.id, cur->e.name);
        cur = cur->next;
    }
    printf("\n");
}

// ✅ Xóa toàn bộ stack, giải phóng bộ nhớ
void clear(Stack S) {
    Node cur = S->next;
    while (cur != nullptr) {
        Node tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    S->next = nullptr;
}

// ✅ Hủy hoàn toàn stack (kể cả header)
void destroy(Stack &S) {
    clear(S);
    delete S;
    S = nullptr;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Stack S = create();

    Element e1 = {1, (char *)"Alice"};
    Element e2 = {2, (char *)"Bob"};
    Element e3 = {3, (char *)"Charlie"};

    push(S, e1); push(S, e2); push(S, e3);
    print_stack(S);                          // Charlie -> Bob -> Alice

    printf("Peek: id=%d\n", peek(S)->e.id); // 3
    printf("Size: %d\n", size(S));           // 3

    Node popped = pop(S);
    printf("Popped: %s\n", popped->e.name); // Charlie
    delete popped;

    print_stack(S);  // Bob -> Alice

    destroy(S);
    return 0;
}
*/