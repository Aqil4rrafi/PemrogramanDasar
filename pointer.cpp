#include <iostream>
using namespace std;

// fungsi penjumlahan
void tambah(int *a, int *b) {
    cout << "Penjumlahan = " << *a + *b << endl;
}

// fungsi swap
void swapNilai(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// fungsi kuadrat
void kuadrat(int *a) {
    *a = (*a) * (*a);
}

// fungsi luas persegi panjang
void luasPersegi(int *p, int *l) {
    int luas = (*p) * (*l);
    cout << "Luas Persegi Panjang = " << luas << endl;
}

// fungsi rata-rata array
void rataRata(int *arr, int n) {
    int jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += *(arr + i);
    }
    double rata = jumlah / (double)n;
    cout << "Rata-rata Array = " << rata << endl;
}

// kalkulator sederhana
void kalkulator(int *a, int *b) {
    cout << "Tambah  = " << *a + *b << endl;
    cout << "Kurang  = " << *a - *b << endl;
    cout << "Kali    = " << *a * *b << endl;
    cout << "Bagi    = " << *a / *b << endl;
}

int main() {
    int x, y;
    cout << "Masukkan angka pertama : ";
    cin >> x;
    cout << "Masukkan angka kedua   : ";
    cin >> y;
    int *px = &x;
    int *py = &y;
    cout << "\n=== OPERASI POINTER ===" << endl;

    // penjumlahan
    tambah(px, py);

    // kalkulator
    cout << "\n=== KALKULATOR ===" << endl;
    kalkulator(px, py);

    // swap
    cout << "\n=== SWAP NILAI ===" << endl;
    cout << "Sebelum swap: x = " << x << ", y = " << y << endl;
    swapNilai(px, py);
    cout << "Sesudah swap: x = " << x << ", y = " << y << endl;

    // kuadrat
    cout << "\n=== KUADRAT ===" << endl;
    kuadrat(px);
    cout << "Nilai x setelah dikuadratkan = " << x << endl;

    // luas persegi panjang
    cout << "\n=== LUAS PERSEGI PANJANG ===" << endl;
    luasPersegi(px, py);

    // array
    cout << "\n=== RATA-RATA ARRAY ===" << endl;
    int angka[5] = {2, 4, 6, 8, 10};
    rataRata(angka, 5);

    // informasi pointer
    cout << "\n=== INFORMASI POINTER ===" << endl;
    cout << "Alamat x = " << px << endl;
    cout << "Nilai x  = " << *px << endl;
    cout << "Alamat y = " << py << endl;
    cout << "Nilai y  = " << *py << endl;
    return 0;
}