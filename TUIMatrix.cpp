#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Menggunakan double karena operasi Gauss-Jordan dan LU menghasilkan nilai pecahan
typedef vector<vector<double>> Matriks;

// ==========================================
// DEKLARASI FUNGSI
// ==========================================
void inputElemen(Matriks &M, string nama);
void buatSemuaMatriks(Matriks &A, Matriks &B, Matriks &D, bool &isCreated);
void cetakMatriks(const Matriks &M, string nama);
bool tambahMatriks(const Matriks &A, const Matriks &B, Matriks &Hasil);
bool kaliMatriks(const Matriks &M1, const Matriks &M2, Matriks &Hasil);

// Fungsi Algoritma Lanjut
void eliminasiGaussJordan(Matriks A);
void faktorisasiLU(const Matriks &A, Matriks &L, Matriks &U);

// ==========================================
// PROGRAM UTAMA
// ==========================================
int main() {
    // Matriks diubah menjadi persegi (3x3) khusus A dan B agar LU & Gauss-Jordan berfungsi
    Matriks A(3, vector<double>(3));
    Matriks B(3, vector<double>(3));
    Matriks C(3, vector<double>(3)); 
    
    Matriks D(2, vector<double>(3));
    Matriks E(2, vector<double>(3)); // Hasil D(2x3) * A(3x3)

    bool isCreated = false;
    int pilihan;

    do {
        cout << "\n=========================================\n";
        cout << "   PROGRAM MATRIKS (GAUSS-JORDAN & LU)   \n";
        cout << "=========================================\n";
        cout << "1. Buat matriks (Input User)\n";
        cout << "2. Tampilkan semua matriks\n";
        cout << "3. Hasil Penambahan (A + B)\n";
        cout << "4. Hasil Perkalian (D * A)\n";
        cout << "5. Diagonal Matriks A (Eliminasi Gauss-Jordan)\n";
        cout << "6. Segitiga Bawah Matriks A (L dari LU Factorization)\n";
        cout << "7. Segitiga Atas Matriks A (U dari LU Factorization)\n";
        cout << "8. Keluar\n";
        cout << "Pilih menu (1-8): ";
        
        if (!(cin >> pilihan)) {
            cout << "\n[!] Input tidak valid.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (pilihan >= 2 && pilihan <= 7 && !isCreated) {
            cout << "\n[WARNING] Matriks belum dibuat!\n";
            cout << "Jalan Keluar: Silakan pilih Menu 1 terlebih dahulu.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                buatSemuaMatriks(A, B, D, isCreated);
                break;
            case 2:
                cetakMatriks(A, "Matriks A (3x3)");
                cetakMatriks(B, "Matriks B (3x3)");
                cetakMatriks(D, "Matriks D (2x3)");
                break;
            case 3:
                if (tambahMatriks(A, B, C)) cetakMatriks(C, "Hasil A + B (3x3)");
                break;
            case 4:
                if (kaliMatriks(D, A, E)) cetakMatriks(E, "Hasil D * A (2x3)");
                break;
            case 5:
                cout << "\n--- Mengubah Matriks A menjadi Diagonal ---\n";
                eliminasiGaussJordan(A);
                break;
            case 6: {
                Matriks L(A.size(), vector<double>(A.size(), 0));
                Matriks U(A.size(), vector<double>(A.size(), 0));
                faktorisasiLU(A, L, U);
                cetakMatriks(L, "Matriks Segitiga Bawah (L)");
                break;
            }
            case 7: {
                Matriks L(A.size(), vector<double>(A.size(), 0));
                Matriks U(A.size(), vector<double>(A.size(), 0));
                faktorisasiLU(A, L, U);
                cetakMatriks(U, "Matriks Segitiga Atas (U)");
                break;
            }
            case 8:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "[!] Pilihan tidak tersedia.\n";
        }
    } while (pilihan != 8);

    return 0;
}

// ==========================================
// IMPLEMENTASI FUNGSI DASAR
// ==========================================

void inputElemen(Matriks &M, string nama) {
    int baris = M.size();
    int kolom = M[0].size();
    cout << "\nInput " << nama << " (" << baris << "x" << kolom << "):\n";
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            cout << "  Baris " << i+1 << ", Kolom " << j+1 << " : ";
            cin >> M[i][j];
        }
    }
}

void buatSemuaMatriks(Matriks &A, Matriks &B, Matriks &D, bool &isCreated) {
    inputElemen(A, "Matriks A (Wajib bisa dibalik / non-singular)");
    inputElemen(B, "Matriks B");
    inputElemen(D, "Matriks D");
    isCreated = true;
    cout << "\n[SUKSES] Semua matriks telah diisi.\n";
}

void cetakMatriks(const Matriks &M, string nama) {
    cout << "\n" << nama << ":\n";
    // Mengatur agar format angka desimal rapi
    cout << fixed << setprecision(2);
    for(int i = 0; i < M.size(); i++) {
        for(int j = 0; j < M[i].size(); j++) {
            cout << setw(8) << M[i][j] << " ";
        }
        cout << "\n";
    }
}

bool tambahMatriks(const Matriks &A, const Matriks &B, Matriks &Hasil) {
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[i].size(); j++) {
            Hasil[i][j] = A[i][j] + B[i][j];
        }
    }
    return true;
}

bool kaliMatriks(const Matriks &M1, const Matriks &M2, Matriks &Hasil) {
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

// ==========================================
// IMPLEMENTASI ALGORITMA LANJUTAN
// ==========================================

// 5. Membuat Diagonal Matriks menggunakan Gauss-Jordan
void eliminasiGaussJordan(Matriks M) { // Mem-passing dengan value agar matriks asli (A) tidak rusak
    int n = M.size();
    
    // Proses mengubah elemen non-diagonal menjadi 0
    for (int i = 0; i < n; i++) {
        if (M[i][i] == 0) {
            cout << "[ERROR] Elemen pivot bernilai 0. Matriks tidak bisa di-diagonalisasi tanpa row-swapping.\n";
            return;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double rasio = M[j][i] / M[i][i];
                for (int k = 0; k < n; k++) {
                    M[j][k] -= rasio * M[i][k];
                }
            }
        }
    }
    cetakMatriks(M, "Matriks Diagonal (Bentuk RREF sebelum disederhanakan)");
}

// 6 & 7. Membuat Segitiga Bawah dan Atas menggunakan Faktorisasi LU (Metode Doolittle)
void faktorisasiLU(const Matriks &A, Matriks &L, Matriks &U) {
    int n = A.size();
    
    for (int i = 0; i < n; i++) {
        // Mencari elemen untuk Segitiga Atas (Upper / U)
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        // Mencari elemen untuk Segitiga Bawah (Lower / L)
        for (int k = i; k < n; k++) {
            if (i == k) {
                L[i][i] = 1; // Elemen diagonal L pada Doolittle selalu 1
            } else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                if (U[i][i] == 0) {
                    cout << "[ERROR] Pembagian dengan 0 pada pemfaktoran LU.\n";
                    return;
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}