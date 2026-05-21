#include <iostream>
using namespace std;
#include <algorithm>
struct Books {
    string bookName;
    string authorName;
    int year;
    long cost;
} book[5];
void getData();
bool compareBooks(const Books &a, const Books &b);
void showData();
int main(){
    cout << "====== My Favoreite Books ======" << endl;
    cout << "Masukkan data buku (judul, penulis, tahun terbit, harga): " << endl;
    getData();
    sort(book, book + 5, compareBooks);
    cout << "\nBuku yang sudah diurutkan berdasarkan harga: " << endl;
    showData();
    return 0;
}
void getData(){
    for (int i = 0; i < 5; i++){
        cout << "Judul Buku " << i + 1 << ": ";
        cin >> book[i].bookName;
        cout << "Penulis Buku " << i + 1 << ": ";
        cin >> book[i].authorName;
        cout << "Tahun Terbit Buku " << i + 1 << ": ";
        cin >> book[i].year;
        cout << "Harga Buku " << i + 1 << ": ";
        cin >> book[i].cost;
    }
}
void showData(){
    for (int i = 0; i < 5; i++){
        cout << "Judul Buku: " << book[i].bookName << ", Penulis: " << book[i].authorName
            << ", Tahun Terbit: " << book[i].year << ", Harga: " << book[i].cost << endl;
    }
}
bool compareBooks(const Books &a, const Books &b){
    return a.cost < b.cost;
}
