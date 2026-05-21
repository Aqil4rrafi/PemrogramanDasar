#include <iostream>
using namespace std;
struct movies {
    string title;
    int year;
} films [5];
void inputData();
void showData();
int main () {
    cout << "====== My Favorite Movies ======" << endl;
    cout << "Masukkan data film (judul dan tahun rilis): " << endl;
    inputData();
    cout << "\nFilm yang sudah diinput: " << endl;
    showData();
    return 0;
}
void inputData(){
    for (int i = 0; i < 5 ; i++){
        cout << "Judul Film: ";
        cin >> films[i].title;
        cout << "Tahun Rilis: ";
        cin >> films[i].year;
    }
}
void showData(){
    for (int i =0; i < 5; i++){
        cout << "Judul Film: " << films[i].title << ", Tahun Rilis: " << films[i].year << endl;
    }
}