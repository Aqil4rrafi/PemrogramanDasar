#include <iostream>
using namespace std;

struct Node {
    int data; // Menyimpan nilai angka (integer)
    Node* next; // Pointer yang menyimpan alamat memori node selanjutnya
};

// SINGLE LINKED LIST (SLL) FUNCTIONS

// 1. INSERT SLL
void insertSLL(Node*& head, int val, string posisi) {
    Node* newNode = new Node{val, nullptr};
    
    // Kasus a: Empty List
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Kasus b: Di Depan
    if (posisi == "depan") {
        newNode->next = head;
        head = newNode;
    } 
    // Kasus d: Di Belakang
    else if (posisi == "belakang") {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    // Kasus c: Di Tengah (Setelah node pertama sebagai contoh)
    else if (posisi == "tengah") {
        newNode->next = head->next;
        head->next = newNode;
    }
}

// 2. DELETE SLL
void deleteSLL(Node*& head, string posisi) {
    if (head == nullptr) return;

    // Kasus a: Di Depan
    if (posisi == "depan") {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // Kasus c: Di Belakang
    else if (posisi == "belakang") {
        if (head->next == nullptr) {
            delete head; head = nullptr; return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    // Kasus b: Di Tengah (Hapus node kedua)
    else if (posisi == "tengah") {
        if (head->next == nullptr) return;
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}

// CIRCULAR SINGLE LINKED LIST (CSLL) FUNCTIONS

// 3. INSERT CSLL
void insertCSLL(Node*& head, int val, string posisi) {
    Node* newNode = new Node{val, nullptr};
    
    // Kasus a: Empty List
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) tail = tail->next;

    // Kasus b: Di Depan
    if (posisi == "depan") {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
    // Kasus d: Di Belakang
    else if (posisi == "belakang") {
        tail->next = newNode;
        newNode->next = head;
    }
    // Kasus c: Di Tengah
    else if (posisi == "tengah") {
        newNode->next = head->next;
        head->next = newNode;
    }
}

// 4. DELETE CSLL
void deleteCSLL(Node*& head, string posisi) {
    if (head == nullptr) return;

    Node* tail = head;
    while (tail->next != head) tail = tail->next;

    // Kasus a: Di Depan
    if (posisi == "depan") {
        if (head->next == head) {
            delete head; head = nullptr;
        } else {
            Node* temp = head;
            tail->next = head->next;
            head = head->next;
            delete temp;
        }
    }
    // Kasus c: Di Belakang
    else if (posisi == "belakang") {
        if (head->next == head) {
            delete head; head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) temp = temp->next;
            temp->next = head;
            delete tail;
        }
    }
    // Kasus b: Di Tengah
    else if (posisi == "tengah") {
        if (head->next == head) return;
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}

// Helper untuk cetak list
void display(Node* head, bool circular = false) {
    if (!head) { cout << "Kosong" << endl; return; }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (circular ? temp != head : temp != nullptr);
    cout << (circular ? "(Back to Head)" : "NULL") << endl;
}

int main() {
    // Inisialisasi list kosong
    Node* sll = nullptr;
    Node* csll = nullptr;

    // --- PEMBUKTIAN SINGLE LINKED LIST (SLL) ---
    cout << "=== PENGUJIAN SLL ===" << endl;
    
    // 1a. Insert di Empty List
    insertSLL(sll, 10, "empty");
    cout << "1a. Insert Empty: "; display(sll);

    // 1b. Insert di Depan
    insertSLL(sll, 5, "depan");
    cout << "1b. Insert Depan: "; display(sll);

    // 1d. Insert di Belakang
    insertSLL(sll, 20, "belakang");
    cout << "1d. Insert Belakang: "; display(sll);

    // 1c. Insert di Tengah (setelah head)
    insertSLL(sll, 15, "tengah");
    cout << "1c. Insert Tengah: "; display(sll);

    cout << "----------------------" << endl;

    // 2a. Delete di Depan
    deleteSLL(sll, "depan");
    cout << "2a. Delete Depan: "; display(sll);

    // 2b. Delete di Tengah
    deleteSLL(sll, "tengah");
    cout << "2b. Delete Tengah: "; display(sll);

    // 2c. Delete di Belakang
    deleteSLL(sll, "belakang");
    cout << "2c. Delete Belakang: "; display(sll);


    // --- PEMBUKTIAN CIRCULAR SINGLE LINKED LIST (CSLL) ---
    cout << "\n=== PENGUJIAN CSLL ===" << endl;

    // 3a. Insert di Empty List
    insertCSLL(csll, 100, "empty");
    cout << "3a. Insert Empty: "; display(csll, true);

    // 3b. Insert di Depan
    insertCSLL(csll, 50, "depan");
    cout << "3b. Insert Depan: "; display(csll, true);

    // 3d. Insert di Belakang
    insertCSLL(csll, 200, "belakang");
    cout << "3d. Insert Belakang: "; display(csll, true);

    // 3c. Insert di Tengah
    insertCSLL(csll, 150, "tengah");
    cout << "3c. Insert Tengah: "; display(csll, true);

    cout << "----------------------" << endl;

    // 4a. Delete di Depan
    deleteCSLL(csll, "depan");
    cout << "4a. Delete Depan: "; display(csll, true);

    // 4b. Delete di Tengah
    deleteCSLL(csll, "tengah");
    cout << "4b. Delete Tengah: "; display(csll, true);

    // 4c. Delete di Belakang
    deleteCSLL(csll, "belakang");
    cout << "4c. Delete Belakang: "; display(csll, true);

    return 0;
}