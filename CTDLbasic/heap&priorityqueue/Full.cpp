#include <iostream>
using namespace std;
struct HeapsortInfo {
    int Length;
    int Heap_size;
    int* Array;
};
typedef HeapsortInfo* Heapsort;
Heapsort create(int A[], int capacity) {
    Heapsort NewH = new HeapsortInfo;
    if (NewH == nullptr)
        return nullptr;
    NewH->Length = capacity;
    NewH->Heap_size = capacity;

    NewH->Array = new int[capacity];

    for (int i = 0; i < capacity; i++) {
        NewH->Array[i] = A[i];
    }

    return NewH;
}

// index tính từ 0
void Max_Heapify(Heapsort H, int i) {

    int max = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < H->Heap_size &&
        H->Array[left] > H->Array[max]) {

        max = left;
    }

    if (right < H->Heap_size &&
        H->Array[right] > H->Array[max]) {

        max = right;
    }

    if (max != i) {

        int temp = H->Array[i];
        H->Array[i] = H->Array[max];
        H->Array[max] = temp;

        Max_Heapify(H, max);
    }
}

void Build_Max_Heap(Heapsort H) {

    H->Heap_size = H->Length;

    for (int i = H->Length / 2; i >= 1; i--) {

        Max_Heapify(H, i - 1);
    }
}

int Max(Heapsort H) {

    return H->Array[0];
}

int Heap_Extract_Max(Heapsort H) {

    if (H->Heap_size <= 0) {
        return -2147483647;
    }

    int max = H->Array[0];

    H->Array[0] = H->Array[H->Heap_size - 1];

    H->Heap_size--;

    Max_Heapify(H, 0);

    return max;
}

bool is_empty(Heapsort H) {

    return H->Heap_size == 0;
}

bool is_full(Heapsort H) {

    return H->Heap_size >= H->Length;
}

bool heap_modify_key(Heapsort H, int i, int new_key) {

    if (H->Array[i] > new_key) {

        H->Array[i] = new_key;

        Max_Heapify(H, i);

    } else if (i > 0 && H->Array[i] < new_key) {

        H->Array[i] = new_key;

        while (i > 0 &&
               H->Array[i] > H->Array[(i - 1) / 2]) {

            int temp = H->Array[i];

            H->Array[i] = H->Array[(i - 1) / 2];
            H->Array[(i - 1) / 2] = temp;

            i = (i - 1) / 2;
        }
    }

    return true;
}

// =======================
// THÊM PHẦN TỬ VÀO HEAP
// =======================

bool heap_add_key(Heapsort H, int key) {

    if (is_full(H)) {
        return false;
    }

    int i = H->Heap_size;

    H->Array[i] = key;

    H->Heap_size++;

    while (i > 0 &&
           H->Array[i] > H->Array[(i - 1) / 2]) {

        int temp = H->Array[i];

        H->Array[i] = H->Array[(i - 1) / 2];
        H->Array[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }

    return true;
}

// =======================
// HEAP SORT
// =======================

void heap_sort(Heapsort H) {

    Build_Max_Heap(H);

    int original_size = H->Heap_size;

    for (int i = H->Length - 1; i >= 1; i--) {

        // đổi root với phần tử cuối heap
        int temp = H->Array[0];
        H->Array[0] = H->Array[i];
        H->Array[i] = temp;

        // giảm kích thước heap
        H->Heap_size--;

        // heapify lại
        Max_Heapify(H, 0);
    }

    // khôi phục lại heap_size
    H->Heap_size = original_size;
}

void printHeap(Heapsort H) {

    for (int i = 0; i < H->Heap_size; i++) {

        cout << H->Array[i] << " ";
    }

    cout << endl;
}

void printArray(Heapsort H) {

    for (int i = 0; i < H->Length; i++) {

        cout << H->Array[i] << " ";
    }

    cout << endl;
}

int main() {

    int A[15] = {4, 1, 3, 2, 16, 19, 10, 4, 8, 7};

    Heapsort H = create(A, 10);

    cout << "Mang ban dau:\n";
    printHeap(H);

    Build_Max_Heap(H);

    cout << "\nSau Build_Max_Heap:\n";
    printHeap(H);

    cout << "\nThem 50 vao heap:\n";
    heap_add_key(H, 50);
    printHeap(H);

    cout << "\nThem 100 vao heap:\n";
    heap_add_key(H, 100);
    printHeap(H);

    cout << "\nMax hien tai: "
         << Max(H) << endl;

    cout << "\nExtract Max: "
         << Heap_Extract_Max(H) << endl;

    cout << "\nHeap sau khi extract:\n";
    printHeap(H);

    cout << "\nHeap Sort:\n";

    heap_sort(H);

    printArray(H);

    return 0;
}