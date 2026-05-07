#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertSLL(Node*& head, int val, string posisi) {
    Node* newNode = new Node{val, nullptr};
    
    if (head == nullptr) {
        head = newNode;
        return;
    }

    if (posisi == "depan") {
        newNode->next = head;
        head = newNode;
    } 
    else if (posisi == "belakang") {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    else if (posisi == "tengah") {
        newNode->next = head->next;
        head->next = newNode;
    }
}

void deleteSLL(Node*& head, string posisi) {
    if (head == nullptr) return;

    if (posisi == "depan") {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else if (posisi == "belakang") {
        if (head->next == nullptr) {
            delete head; 
            head = nullptr; 
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    else if (posisi == "tengah") {
        if (head->next == nullptr) return;
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}

void insertCSLL(Node*& head, int val, string posisi) {
    Node* newNode = new Node{val, nullptr};
    
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) tail = tail->next;

    if (posisi == "depan") {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
    else if (posisi == "belakang") {
        tail->next = newNode;
        newNode->next = head;
    }
    else if (posisi == "tengah") {
        newNode->next = head->next;
        head->next = newNode;
    }
}

void deleteCSLL(Node*& head, string posisi) {
    if (head == nullptr) return;

    Node* tail = head;
    while (tail->next != head) tail = tail->next;

    if (posisi == "depan") {
        if (head->next == head) {
            delete head; 
            head = nullptr;
        } else {
            Node* temp = head;
            tail->next = head->next;
            head = head->next;
            delete temp;
        }
    }
    else if (posisi == "belakang") {
        if (head->next == head) {
            delete head; 
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) temp = temp->next;
            temp->next = head;
            delete tail;
        }
    }
    else if (posisi == "tengah") {
        if (head->next == head) return;
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }
}

void display(Node* head, bool circular = false) {
    if (!head) { 
        cout << "List Kosong" << endl; 
        return; 
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (circular ? temp != head : temp != nullptr);
    cout << (circular ? "(Kembali ke Head)" : "NULL") << endl;
}

int main() {
    Node* sll = nullptr;
    Node* csll = nullptr;

    cout << "IMPLEMENTASI SINGLE LINKED LIST (SLL)" << endl;
    
    insertSLL(sll, 10, "empty");
    cout << "Insert Empty List : "; display(sll);
    insertSLL(sll, 5, "depan");
    cout << "Insert Depan      : "; display(sll);
    insertSLL(sll, 20, "belakang");
    cout << "Insert Belakang   : "; display(sll);
    insertSLL(sll, 15, "tengah");
    cout << "Insert Tengah     : "; display(sll);
    cout << endl;
    deleteSLL(sll, "depan");
    cout << "Delete Depan      : "; display(sll);
    deleteSLL(sll, "tengah");
    cout << "Delete Tengah     : "; display(sll);
    deleteSLL(sll, "belakang");
    cout << "Delete Belakang   : "; display(sll);

    cout << "\nIMPLEMENTASI CIRCULAR SINGLE LINKED LIST (CSLL)" << endl;

    insertCSLL(csll, 100, "empty");
    cout << "Insert Empty List : "; display(csll, true);
    insertCSLL(csll, 50, "depan");
    cout << "Insert Depan      : "; display(csll, true);
    insertCSLL(csll, 200, "belakang");
    cout << "Insert Belakang   : "; display(csll, true);
    insertCSLL(csll, 150, "tengah");
    cout << "Insert Tengah     : "; display(csll, true);
    cout << endl;
    deleteCSLL(csll, "depan");
    cout << "Delete Depan      : "; display(csll, true);
    deleteCSLL(csll, "tengah");
    cout << "Delete Tengah     : "; display(csll, true);
    deleteCSLL(csll, "belakang");
    cout << "Delete Belakang   : "; display(csll, true);

    return 0;
}