#include <iostream>
using namespace std;
int main () {
    double tagihanPerOrang, jumlahTeman, n, totalHarga, diskon;
    cout << "Masukkan jumlah teman: ";
    cin >> jumlahTeman;
    while (jumlahTeman <= 1 || jumlahTeman >= 9999){
        cout << "Jumlah teman harus lebih dari 1 dan kurang dari 9999. Masukkan jumlah teman: ";
        cin >> jumlahTeman;
    }
    cout << "Masukkan nominal diskon (dalam persen): ";
    cin >> n;
    cout << "Masukkan jumlah total tagihan: ";
    cin >> totalHarga;
    diskon = (n * totalHarga) / 100;
    tagihanPerOrang = (totalHarga / jumlahTeman) - diskon;
    cout << "Tagihan per Orang: " << tagihanPerOrang << endl;
    cout << "Diskon: " << diskon << endl;
    cout << "Total yang harus dibayar: " << totalHarga - diskon << endl;
}