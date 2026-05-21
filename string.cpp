#include <iostream>
#include <string>
using namespace std;

int main() {

    string teks;

    cout << "Masukkan teks: ";
    getline(cin, teks);
    cout << "\nPROGRAM MANIPULASI STRING";

    // 1. PANJANG STRING
    cout << "\n1. Panjang String";
    cout << "\nJumlah karakter = "
         << teks.length() << endl;

    // 2. REVERSE STRING
    cout << "\n2. Reverse String";
    cout << "\nHasil = ";
    for (int i = teks.length() - 1; i >= 0; i--) {
        cout << teks[i];
    }
    cout << endl;

    // 3. PALINDROME
    bool palindrome = true;

    for (int i = 0; i < teks.length() / 2; i++) {

        if (tolower(teks[i]) !=
            tolower(teks[teks.length() - 1 - i])) {

            palindrome = false;
            break;
        }
    }

    cout << "\n3. Palindrome";
    if (palindrome) {
        cout << "\nTeks adalah palindrome\n";
    }
    else {
        cout << "\nTeks bukan palindrome\n";
    }

    // 4. JUMLAH VOKAL
    int vokal = 0;
    for (int i = 0; i < teks.length(); i++) {
        char c = tolower(teks[i]);
        if (c == 'a' || c == 'i' ||
            c == 'u' || c == 'e' ||
            c == 'o') {
            vokal++;
        }
    }
    cout << "\n4. Jumlah Huruf Vokal";
    cout << "\nJumlah vokal = "
         << vokal << endl;

    // 5. JUMLAH KATA
    int kata = 1;
    for (int i = 0; i < teks.length(); i++) {

        if (teks[i] == ' ') {
            kata++;
        }
    }
    cout << "\n5. Jumlah Kata";
    cout << "\nJumlah kata = "
         << kata << endl;

    // 6. UPPERCASE
    string upper = teks;

    for (int i = 0; i < upper.length(); i++) {
        upper[i] = toupper(upper[i]);
    }
    cout << "\n6. Uppercase";
    cout << "\n" << upper << endl;

    // 7. LOWERCASE
    string lower = teks;
    for (int i = 0; i < lower.length(); i++) {
        lower[i] = tolower(lower[i]);
    }
    cout << "\n7. Lowercase";
    cout << "\n" << lower << endl;

    // 8. HAPUS SPASI
    string tanpaSpasi = "";
    for (int i = 0; i < teks.length(); i++) {
        if (teks[i] != ' ') {
            tanpaSpasi += teks[i];
        }
    }
    cout << "\n8. Hapus Spasi";
    cout << "\n" << tanpaSpasi << endl;

    // 9. CAESAR CIPHER
    string cipher = teks;

    for (int i = 0; i < cipher.length(); i++) {
        if (isalpha(cipher[i])) {
            cipher[i] = cipher[i] + 1;
        }
    }
    cout << "\n9. Caesar Cipher (+1)";
    cout << "\n" << cipher << endl;

    // 10. FREKUENSI KARAKTER
    char cari;
    int jumlah = 0;

    cout << "\n10. Frekuensi Karakter";
    cout << "\nMasukkan huruf yang dicari: ";
    cin >> cari;
    for (int i = 0; i < teks.length(); i++) {
        if (tolower(teks[i]) ==
            tolower(cari)) {
            jumlah++;
        }
    }
    cout << "Jumlah huruf '" << cari
         << "' = " << jumlah << endl;

    // 11. SUBSTRING
    if (teks.length() >= 5) {

        cout << "\n11. Substring";
        cout << "\n5 karakter pertama = "
             << teks.substr(0, 5) << endl;
    }

    // 12. INFORMASI INDEX
    cout << "\n12. Index Karakter";
    for (int i = 0; i < teks.length(); i++) {
        cout << "Index "
             << i
             << " = "
             << teks[i]
             << endl;
    }

    return 0;
}