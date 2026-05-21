#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;
typedef vector<vector<int>> Matriks;

void inputElemen(Matriks &M, string nama);
void buatSemuaMatriks(Matriks &A, Matriks &B, Matriks &D, bool &isCreated);
void cetakMatriks(const Matriks &M, string nama);
bool tambahMatriks(const Matriks &A, const Matriks &B, Matriks &Hasil);
bool kaliMatriks(const Matriks &M1, const Matriks &M2, Matriks &Hasil);
void cetakDiagonal(const Matriks &M);
void cetakSegitigaBawah(const Matriks &M);
void cetakSegitigaAtas(const Matriks &M);

int main() {
    Matriks A(3, vector<int>(4));
    Matriks B(3, vector<int>(4));
    Matriks C(3, vector<int>(4)); 
    Matriks D(2, vector<int>(3));
    Matriks E(2, vector<int>(4));
    bool isCreated = false;
    int pilihan;
    do {
        cout << "\n=========================================\n";
        cout << "       PROGRAM OPERASI MATRIKS C++       \n";
        cout << "=========================================\n";
        cout << "1. Membuat matriks-matriks (Input User)\n";
        cout << "2. Menampilkan matriks yang sudah dibuat\n";
        cout << "3. Menampilkan hasil penambahan (A + B)\n";
        cout << "4. Menampilkan hasil perkalian (D * A)\n";
        cout << "5. Menampilkan diagonal matriks A\n";
        cout << "6. Menampilkan segitiga bawah matriks A\n";
        cout << "7. Menampilkan segitiga atas matriks A\n";
        cout << "8. Keluar\n";
        cout << "Pilih menu (1-8): ";
        
        if (!(cin >> pilihan)) {
            cout << "\n[WARNING] Input harus berupa angka!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (pilihan >= 2 && pilihan <= 7 && !isCreated) {
            cout << "\n[Peringatan/Warning]: Anda belum membuat matriks!\n";
            cout << "Jalan Keluar: Silakan pilih Menu 1 terlebih dahulu untuk mengisi data.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                buatSemuaMatriks(A, B, D, isCreated);
                break;
            case 2:
                cout << "\n--- Daftar Matriks ---\n";
                cetakMatriks(A, "Matriks A (3x4)");
                cetakMatriks(B, "Matriks B (3x4)");
                cetakMatriks(D, "Matriks D (2x3)");
                break;
            case 3:
                if (tambahMatriks(A, B, C)) {
                    cetakMatriks(C, "Hasil Penambahan A + B (3x4)");
                }
                break;
            case 4:
                if (kaliMatriks(D, A, E)) {
                    cetakMatriks(E, "Hasil Perkalian D * A (2x4)");
                }
                break;
            case 5:
                cetakDiagonal(A);
                break;
            case 6:
                cetakSegitigaBawah(A);
                break;
            case 7:
                cetakSegitigaAtas(A);
                break;
            case 8:
                cout << "Program selesai. Sampai jumpa!\n";
                break;
            default:
                cout << "[Error] Pilihan menu tidak valid.\n";
        }
    } while (pilihan != 8);

    return 0;
}

void inputElemen(Matriks &M, string nama) {
    int baris = M.size();
    int kolom = M[0].size();
    cout << "\nMasukkan elemen untuk " << nama << " (" << baris << "x" << kolom << "):\n";
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            while (true) {
                cout << "Baris " << i+1 << ", Kolom " << j+1 << ": ";
                if (cin >> M[i][j]) {
                    break; // Input valid
                } else {
                    cout << "   [Error] Masukkan angka saja!\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }
    }
}

void buatSemuaMatriks(Matriks &A, Matriks &B, Matriks &D, bool &isCreated) {
    inputElemen(A, "Matriks A");
    inputElemen(B, "Matriks B");
    inputElemen(D, "Matriks D");
    isCreated = true;
    cout << "\n[Sukses] Semua matriks telah berhasil diisi oleh user.\n";
}


void cetakMatriks(const Matriks &M, string nama) {
    cout << "\n" << nama << ":\n";
    for(int i = 0; i < M.size(); i++) {
        for(int j = 0; j < M[i].size(); j++) {
            cout << setw(5) << M[i][j] << " ";
        }
        cout << endl;
    }
}

bool tambahMatriks(const Matriks &A, const Matriks &B, Matriks &Hasil) {
    if (A.size() != B.size() || A[0].size() != B[0].size()) {
        cout << "[Error] Dimensi matriks tidak cocok untuk penambahan!\n";
        return false;
    }
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[i].size(); j++) {
            Hasil[i][j] = A[i][j] + B[i][j];
        }
    }
    return true;
}

bool kaliMatriks(const Matriks &M1, const Matriks &M2, Matriks &Hasil) {
    if (M1[0].size() != M2.size()) {
        cout << "[Error] Dimensi tidak cocok untuk perkalian!\n";
        return false;
    }
    for(int i = 0; i < M1.size(); i++) {
        for(int j = 0; j < M2[0].size(); j++) {
            Hasil[i][j] = 0;
            for(int k = 0; k < M2.size(); k++) {
                Hasil[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    return true;
}

void cetakDiagonal(const Matriks &M) {
    cout << "\nDiagonal Matriks (Sampel Matriks A):\n";
    for(int i = 0; i < M.size(); i++) {
        for(int j = 0; j < M[i].size(); j++) {
            if (i == j) cout << setw(5) << M[i][j] << " ";
            else cout << setw(5) << "-" << " ";
        }
        cout << endl;
    }
}

void cetakSegitigaBawah(const Matriks &M) {
    cout << "\nSegitiga Bawah (Sampel Matriks A):\n";
    for(int i = 0; i < M.size(); i++) {
        for(int j = 0; j < M[i].size(); j++) {
            if (i >= j) cout << setw(5) << M[i][j] << " ";
            else cout << setw(5) << "0" << " ";
        }
        cout << endl;
    }
}

void cetakSegitigaAtas(const Matriks &M) {
    cout << "\nSegitiga Atas (Sampel Matriks A):\n";
    for(int i = 0; i < M.size(); i++) {
        for(int j = 0; j < M[i].size(); j++) {
            if (i <= j) cout << setw(5) << M[i][j] << " ";
            else cout << setw(5) << "0" << " ";
        }
        cout << endl;
    }
}