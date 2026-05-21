#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
typedef vector<vector<int>> Matriks;
void inputElemenMatriks(Matriks &M, string nama);
void buatMatriks(Matriks &M, bool &isCreated);
void cetakMatriks(const Matriks &M, string nama);
bool tambahMatriks(const Matriks &M1, const Matriks &M2, Matriks &Hasil);
bool kaliMatriks(const Matriks &M1, const Matriks &M2, Matriks &Hasil);
void cetakDiagonal(const Matriks &M, bool isCreated);
void cetakSegitigaBawah(const Matriks &M, bool isCreated);
void cetakSegitigaAtas(const Matriks &M, bool isCreated);
int main(){
    Matriks A(3, vector<int>(4));
    Matriks B(3, vector<int>(4));
    Matriks C(3, vector<int>(4)); 
    Matriks D(2, vector<int>(3));
    Matriks E(2, vector<int>(4));
    bool isCreated = false;
    int pilihan;
    do {
        cout << "Selamat Datang di Program Operasi Matriks C++\n";
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
    }
    switch (pilihan) {
        case 1:
            buatMatriks(A, isCreated);
            buatMatriks(B, isCreated);
            buatMatriks(C, isCreated);
            buatMatriks(D, isCreated);
            buatMatriks(E, isCreated);
            break;
        case 2:
            cetakMatriks(A, "A");
            cetakMatriks(B, "B");
            cetakMatriks(C, "C");
            cetakMatriks(D, "D");
            cetakMatriks(E, "E");
            break;
        case 3:
            tambahMatriks(A, B, C);
            cetakMatriks(C, "Hasil Penambahan A + B");
            break;
        case 4:
            kaliMatriks(D, A, E);
            cetakMatriks(E, "Hasil Perkalian D * A");
            break;
        case 5:
            cetakDiagonal(A, isCreated);
            cetakDiagonal(B, isCreated);
            cetakDiagonal(C, isCreated);
            cetakDiagonal(D, isCreated);
            cetakDiagonal(E, isCreated);
            break;
        case 6:
            cetakSegitigaBawah(A, isCreated);
            cetakSegitigaBawah(B, isCreated);
            cetakSegitigaBawah(C, isCreated);
            cetakSegitigaBawah(D, isCreated);
            cetakSegitigaBawah(E, isCreated);
            break;
        case 7:             
            cetakSegitigaAtas(A, isCreated);
            cetakSegitigaAtas(B, isCreated);
            cetakSegitigaAtas(C, isCreated);
            cetakSegitigaAtas(D, isCreated);
            cetakSegitigaAtas(E, isCreated);
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
void inputElemenMatriks(Matriks &M, string nama){
    int baris = M.size();
    int kolom = M[0].size();
    cout << "\nMasukkan elemen untuk " << nama << " (" << baris << "x" << kolom << "):\n";
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
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
void buatMatriks(Matriks &M, bool &isCreated){
    inputElemenMatriks(M, "Matriks " + to_string(M.size()) + "x" + to_string(M[0].size()));
    isCreated = true;
}
void cetakMatriks(const Matriks &M, string nama){
    cout <<"\nMatriks " << nama << ":\n";
    int baris = M.size();
    int kolom = M[0].size();
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            cout << setw(5) << M[i][j] << " ";
        }
        cout << endl;
    }
}
bool kaliMatriks(const Matriks &M1, const Matriks &M2, Matriks &Hasil){
    int barisM1 = M1.size();
    int kolomM1 = M1[0].size();
    int barisM2 = M2.size();
    int kolomM2 = M2[0].size();
    if (kolomM1 != barisM2) {
        cout << "\n[Error] Dimensi tidak cocok untuk perkalian!\n";
        return false;
    } else {
        for (int i = 0; i < barisM1; i++){
            for(int j = 0; j < kolomM2; j++){
                Hasil[i][j] = 0;
                for (int k =0; k < kolomM1; k++){
                    Hasil[i][j] += M1[i][k] * M2[k][j];
                }
            }
        }
    }
    return true;
}
bool tambahMatriks(const Matriks &M1, const Matriks &M2, Matriks &Hasil){
    int barisM1 = M1.size();
    int kolomM1 = M1[0].size();
    int barisM2 = M2.size();
    int kolomM2 = M2[0].size();
    if (barisM1 != barisM2 || kolomM1 != kolomM2) {
        cout << "\n[Error] Dimensi matriks tidak cocok untuk penambahan!\n";
        return false;
    } else {
        for (int i = 0; i < barisM1; i++){
            for(int j = 0; j < kolomM1; j++){
                Hasil[i][j] = M1[i][j] + M2[i][j];
            }
        }
    }
    return true;
}
void cetakDiagonal(const Matriks &M, bool isCreated){
    if (!isCreated) {
        cout << "\n[Error] Matriks belum dibuat. Silakan buat matriks terlebih dahulu.\n";
        return;
    }
    cout << "\nDiagonal Matriks:\n";
    for(int i = 0; i < M.size(); i++){  
        for(int j = 0; j < M[i].size(); j++){
            if (i == j) cout << setw(5) << M[i][j] << " ";
            else cout << setw(5) << "-" << " ";
        }
        cout << endl;
    }
}
void cetakSegitigaBawah(const Matriks &M, bool isCreated){
    if (!isCreated) {
        cout << "\n[Error] Matriks belum dibuat. Silakan buat matriks terlebih dahulu.\n";
        return;
    }
    cout << "\nSegitiga Bawah:\n";
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++){
            if (i >= j) cout << setw(5) << M[i][j] << " ";
            else cout << setw(5) << "0" << " ";
        }
        cout << endl;
    }
}
void cetakSegitigaAtas(const Matriks &M, bool isCreated){
    if (!isCreated) {
        cout << "\n[Error] Matriks belum dibuat. Silakan buat matriks terlebih dahulu.\n";
        return;
    }
    cout << "\nSegitiga Atas:\n";
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++){
            if (i <= j) cout << setw(5) << M[i][j] << " ";
            else cout << setw(5) << "0" << " ";
        }
        cout << endl;
    }
}   