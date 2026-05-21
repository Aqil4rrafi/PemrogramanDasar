#include <iostream>
#include <cmath> // Wajib untuk fungsi sqrt() dan pow()

using namespace std;

// 1. Membuat Struct untuk menampung koordinat Titik
struct Titik {
    double x;
    double y;
};

int main() {
    // 2. Membuat Array dari Struct untuk menampung 10 titik inputan
    Titik daftarTitik[10];
    Titik titikPusat;

    cout << "=== INPUT 10 TITIK KOORDINAT ===" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Titik ke-" << i + 1 << " (x y): ";
        cin >> daftarTitik[i].x >> daftarTitik[i].y;
    }

    // 3. Input 1 titik pusat tujuan
    cout << "\n=== INPUT TITIK PUSAT (TARGET) ===" << endl;
    cout << "Masukkan koordinat pusat (x y): ";
    cin >> titikPusat.x >> titikPusat.y;

    cout << "\n=== HASIL PERHITUNGAN JARAK ===" << endl;
    
    // 4. Perulangan untuk menghitung jarak setiap titik ke titik pusat
    for (int i = 0; i < 10; i++) {
        // Rumus Euclidean: sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
        double jarak = sqrt(pow(daftarTitik[i].x - titikPusat.x, 2) + 
                            pow(daftarTitik[i].y - titikPusat.y, 2));
        
        cout << "Jarak dari Titik ke-" << i + 1 << " (" << daftarTitik[i].x << ", " << daftarTitik[i].y << ")"
             << " ke Pusat (" << titikPusat.x << ", " << titikPusat.y << ") adalah: " 
             << jarak << endl;
    }

    return 0;
}