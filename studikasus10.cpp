#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

// Fungsi input data
void inputMahasiswa(string *nama, float *nilai, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nama mahasiswa ke-" << i + 1 << ": ";
        cin.ignore(); // untuk menghindari newline error
        getline(cin, *(nama + i));
        cout << "Nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> *(nilai + i);
    }
}

// Fungsi hitung rata-rata
float hitungRataRata(float *nilai, int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += *(nilai + i);
    }
    return total / n;
}

// Fungsi tampil mahasiswa dengan nilai di atas rata-rata
void tampilDiAtasRataRata(string *nama, float *nilai, int n, float rataRata) {
    cout << "\nMahasiswa dengan nilai di atas rata-rata:\n";
    for (int i = 0; i < n; i++) {
        if (*(nilai + i) > rataRata) {
            cout << *(nama + i) << " - " << *(nilai + i) << endl;
        }
    }
}

int main() {
    int n;
    string nama[MAX];
    float nilai[MAX];

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    inputMahasiswa(nama, nilai, n);

    float rataRata = hitungRataRata(nilai, n);
    cout << "\nRata-rata nilai: " << rataRata << endl;

    tampilDiAtasRataRata(nama, nilai, n, rataRata);

    return 0;
}
