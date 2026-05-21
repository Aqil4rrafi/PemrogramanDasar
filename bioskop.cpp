#include <iostream>
using namespace std;
int main(){
    int kursiBioskop[3][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int baris, kolom;
    char pilihan;
    do {
        cout << "\n=== DENAH KURSI BIOSKOP ===" << endl;
        cout << "      [K0] [K1] [K2] [K3] [K4]" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Baris " << i << " ";
            for (int j = 0; j < 5; j++) {
                cout << " [" << kursiBioskop[i][j] << "]";
            }
            cout << endl;
        }
        cout << "Keterangan: 0 = Kosong, 1 = Terisi\n" << endl;
        cout << "Pilih Baris (0-2): ";
        cin >> baris;
        cout << "Pilih Kolom (0-4): ";
        cin >> kolom;
        if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 5) {
            if (kursiBioskop[baris][kolom] == 0) {
                kursiBioskop[baris][kolom] = 1; // Ubah nilai array menjadi 1 (Dipesan)
                cout << "🎉 Berhasil booking kursi [B" << baris << "][K" << kolom << "]!" << endl;
            } else {
                cout << "❌ Maaf, kursi tersebut sudah dipesan orang lain!" << endl;
            }

        } else {
            cout << "⚠️ Pilihan baris atau kolom salah (di luar jangkauan)!" << endl;
        }
        cout << "\nIngin booking kursi lain? (y/n): ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');
    cout << "\nTerima kasih sudah menggunakan sistem kasir bioskop!" << endl;
    return 0;
}