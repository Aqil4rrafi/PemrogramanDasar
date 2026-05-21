#include <iostream>
#include <string>

using namespace std;

class Buku {
private: 
    // Variabel ini "private" (rahasia), fungsi main() tidak bisa akses langsung
    string judul;
    int harga;

public:
    // 1. CONSTRUCTOR (Namanya sama dengan nama class, tanpa void)
    Buku(string inputJudul, int inputHarga) {
        judul = inputJudul;
        harga = inputHarga;
        cout << "-> Objek '" << judul << "' berhasil dibuat lewat Constructor!" << endl;
    }

    // 2. METHOD untuk menampilkan data (Getter)
    void getData() {
        cout << "Judul Buku: " << judul << endl;
        cout << "Harga     : Rp" << harga << endl;
        cout << "-------------------------" << endl;
    }

    // 3. METHOD untuk mengubah data jika sewaktu-waktu ada diskon (Setter)
    void setHargaDiskon(int hargaBaru) {
        harga = hargaBaru;
    }
};

int main() {
    // Saat kita membuat objek, kita langsung mengirim data ke CONSTRUCTOR
    Buku buku1("Belajar C++ Sampai Mumet", 85000);
    Buku buku2("Tutorial Lolos Ujian OOP", 120000);

    cout << "\n=== Menampilkan Data Menggunakan getData() ===\n";
    // Kita panggil method getData() untuk melihat isinya
    buku1.getData();
    buku2.getData();

    cout << "=== Buku 1 Mengalami Diskon ===\n";
    buku1.setHargaDiskon(50000); // Mengubah data private lewat method setter
    buku1.getData();             // Tampilkan lagi untuk melihat perubahan

    return 0;
}