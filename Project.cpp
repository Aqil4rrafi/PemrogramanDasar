#include <iostream>
using namespace std;

struct Node {
    int id;
    string namaPengirim;
    string namaPenerima;
    float beratPaket;
    string tujuanPengiriman;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;
Node* top = nullptr;
int idCounter = 1;

void tambahPaket(){
    Node* nodebaru = new Node();
    nodebaru->id = idCounter++;
    cin.ignore(); 
    cout << "\nMasukkan Nama Pengirim: ";
    getline(cin, nodebaru->namaPengirim);
    cout << "Masukkan Nama Penerima: ";
    getline(cin, nodebaru->namaPenerima);
    cout << "Masukkan Berat Paket (Kg): ";
    cin >> nodebaru->beratPaket;
    cin.ignore(); 
    cout << "Masukkan Alamat Tujuan Pengiriman: ";
    getline(cin, nodebaru->tujuanPengiriman);
    nodebaru->next = nullptr;

    if(front == nullptr){
        front = rear = nodebaru;
    } else {
        rear->next = nodebaru;
        rear = nodebaru;
    }
    cout << "\nSelamatt! Paket berhasil ditambahkan ke dalam antrean, Paket anda memiliki ID: " << nodebaru->id << endl;
}

void masukkanRiwayat(Node* nodebaru){
    nodebaru->next = top;
    top = nodebaru;
}

void prosesPaket(){
    if (front == nullptr){
        cout << "\nAntrean masih kosong\n";
        return;
    } 
    Node* nodeProses = front;
    front = front->next;
    if (front == nullptr){
        rear = nullptr;
    }
    masukkanRiwayat(nodeProses);
    cout << "\nYeayy paket dengan ID " << nodeProses->id << " berhasil diproses\n";
}

    void lihatPaketTerakhir(){
        if(top==nullptr){
            cout << "\nRiwayat masih kosong\n";
        } else {
            cout << "Paket Terakhir Yang Diproses\n";
            cout << "ID       : " << top->id << endl;
            cout << "Pengirim : " << top->namaPengirim << endl; 
            cout << "Penerima : " << top->namaPenerima << endl;
            cout << "Berat    : " << top->beratPaket << " kg\n";
            cout << "Tujuan   : " << top->tujuanPengiriman << endl;
            cout << "_____________________________________________________\n"; 
        }
    }

void tampilkanAntrean(){
    if(front==nullptr){
        cout << "\nAntrean masih kosong\n";
    } else {
        Node* temp = front;
        cout << "Antrean Paket\n";
        while(temp!=nullptr){
            cout << "ID       : " << temp->id << endl;
            cout << "Pengirim : " << temp->namaPengirim << endl; 
            cout << "Penerima : " << temp->namaPenerima << endl;
            cout << "Berat    : " << temp->beratPaket << " kg\n";
            cout << "Tujuan   : " << temp->tujuanPengiriman << endl;
            cout << "_____________________________________________________\n"; 
            temp = temp->next; 
        }
    }
}

void tampilkanRiwayat(){
    if(top==nullptr){
        cout << "\nRiwayat masih kosong\n";
    } else {
        Node* temp = top;
        cout << "Riwayat Paket yang Sudah Diproses\n";
        while(temp!=nullptr){
            cout << "ID       : " << temp->id << endl;
            cout << "Pengirim : " << temp->namaPengirim << endl; 
            cout << "Penerima : " << temp->namaPenerima << endl;
            cout << "Berat    : " << temp->beratPaket << " kg\n";
            cout << "Tujuan   : " << temp->tujuanPengiriman << endl;
            cout << "_____________________________________________________\n"; 
            temp = temp->next; 
        }
    }
}

int main (){
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Paket\n";
        cout << "2. Proses Paket\n";
        cout << "3. Lihat Paket Terakhir Diproses\n";
        cout << "4. Tampilkan Antrean\n";
        cout << "5. Tampilkan Riwayat\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch(pilihan){
            case 1:
                tambahPaket();
                break;
            case 2:
                prosesPaket();
                break;
            case 3:
                lihatPaketTerakhir();
                break;
            case 4:
                tampilkanAntrean();
                break;
            case 5:
                tampilkanRiwayat();
                break;
            case 6:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    } while(pilihan != 6);

    return 0;
}


