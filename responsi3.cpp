#include <iostream>
using namespace std;
int main(){
    int a, b, sum, absDifference;
    int *pa = &a;
    int *pb = &b;
    cout << "Masukkan angka pertama : ";
    cin >> a;
    cout << "Masukkan angka kedua   : ";
    cin >> b;
    sum = *pa + *pb;
    absDifference = (*pa > *pb) ? *pa - *pb : *pb - *pa;
    cout << "\n=== HASIL OPERASI ===" << endl;
    cout << "Jumlah: " << sum << endl;
    cout << "Selisih mutlak: " << absDifference << endl;
    return 0;
}