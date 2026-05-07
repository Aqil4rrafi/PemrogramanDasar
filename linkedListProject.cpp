#include <iostream>
using namespace std;


struct Node {
    string namaPengirim;
    string namaPenerima;
    float beratPaket;
    string tujuanPengiriman;
    Node* next;
};


Node* front = NULL;
Node* rear = NULL;
Node* top = NULL;


void tambahPaket() {
    Node* nodeBaru = new Node();
    cout << "Nama Pengirim: ";
    cin >> nodeBaru->namaPengirim;
    cout << "Nama Penerima: ";
    cin >> nodeBaru->namaPenerima;
    cout << "Berat Paket: ";
    cin >> nodeBaru->beratPaket;
    cout << "Tujuan Pengiriman: ";
    cin >> nodeBaru->tujuanPengiriman;
    nodeBaru->next = NULL;

    if (front == NULL) {
        front = rear = nodeBaru;
    } else {
        rear->next = nodeBaru;
        rear = nodeBaru;
    }

    cout << "Paket berhasil ditambahkan ke antrean.\n";
}


void pushRiwayat(Node* nodeBaru) {
    nodeBaru->next = top;
    top = nodeBaru;
}


void prosesPaket() {
    if (front == NULL) {
        cout << "Antrean kosong.\n";
    } else {
        Node* nodeProses = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
        pushRiwayat(nodeProses);
        cout << "Paket berhasil diproses.\n";
    }
}


void lihatTerakhir() {
    if (top == NULL) {
        cout << "Belum ada riwayat.\n";
    } else {
        cout << "\nPaket Terakhir Diproses\n";
        cout << "Pengirim : " << top->namaPengirim << endl;
        cout << "Penerima : " << top->namaPenerima << endl;
        cout << "Berat    : " << top->beratPaket << " kg\n";
        cout << "Tujuan   : " << top->tujuanPengiriman << endl;
    }
}


void tampilkanAntrean() {
    if (front == NULL) {
        cout << "Antrean kosong.\n";
    } else {
        Node* temp = front;
        cout << "\nAntrean Paket\n";
        while (temp != NULL) {
            cout << "Pengirim : " << temp->namaPengirim << endl;
            cout << "Penerima : " << temp->namaPenerima << endl;
            cout << "Berat    : " << temp->beratPaket << " kg\n";
            cout << "Tujuan   : " << temp->tujuanPengiriman << endl;
            temp = temp->next;
        }
    }
}


void tampilkanRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong.\n";
    } else {
        Node* temp = top;
        cout << "\nRiwayat Pengiriman \n";
        while (temp != NULL) {
            cout << "Pengirim : " << temp->namaPengirim << endl;
            cout << "Penerima : " << temp->namaPenerima << endl;
            cout << "Berat    : " << temp->beratPaket << " kg\n";
            cout << "Tujuan   : " << temp->tujuanPengiriman << endl;
            temp = temp->next;
        }
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n MENU \n";
        cout << "1. Tambah Paket\n";
        cout << "2. Proses Paket\n";
        cout << "3. Lihat Paket Terakhir\n";
        cout << "4. Tampilkan Antrean\n";
        cout << "5. Tampilkan Riwayat\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahPaket();
                break;
            case 2:
                prosesPaket();
                break;
            case 3:
                lihatTerakhir();
                break;
            case 4:
                tampilkanAntrean();
                break;
            case 5:
                tampilkanRiwayat();
                break;
            case 6:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 6);

    return 0;
}