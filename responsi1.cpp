#include <iostream>
using namespace std;
int main() {
    int n, jumlah = 0, temp;
    cout << "Masukkan Bilangan: ";
    cin >> n;
    temp = n;
    cout << "Digit dari kanan ke kiri: ";
    while (temp > 0) {
        cout << temp % 10;
        jumlah += temp % 10;
        temp /= 10;
    }
    if (jumlah % 9 == 0) {
        cout << "\nBilangan " << n << " adalah Bilangan Harshad";
    } else {
        cout << "\nBilangan " << n << " bukan Bilangan Harshad";
    }
    return 0;
}