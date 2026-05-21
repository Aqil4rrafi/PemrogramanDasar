#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Masukkan ukuran array : ";
    cin >> n;
    int *dynamicArray = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen ke-"
             << i + 1 << " : ";
        cin >> dynamicArray[i];
    }

    cout << "\nIsi Dynamic Array:\n";
    for (int i = 0; i < n; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    int terbesar = dynamicArray[0];
    for (int i = 1; i < n; i++) {
        if (dynamicArray[i] > terbesar) {
            terbesar = dynamicArray[i];
        }
    }
    cout << "Nilai Terbesar = "
         << terbesar << endl;

    cout << "\n--- Hasil Array Unik (Tanpa Duplikat) ---\n";
    int ukuranBaru = 0;

    for (int i = 0; i < n; i++) {
        bool sudahAda = false;

        // Cek ke belakang, apakah dynamicArray[i] sudah pernah muncul sebelumnya?
        for (int j = 0; j < i; j++) {
            if (dynamicArray[i] == dynamicArray[j]) {
                sudahAda = true; // Ketemu duplikat!
                break;           // Hentikan cek ke belakang, lanjut ke elemen berikutnya
            }
        }

        // Jika BELUM PERNAH ADA, berarti ini angka unik, boleh dicetak!
        if (!sudahAda) {
            cout << "Elemen unik: " << dynamicArray[i] << endl;
            ukuranBaru++;
        }
    }
    cout << "Ukuran Array Baru = " << ukuranBaru << endl;
    delete[] dynamicArray;
    return 0;
}