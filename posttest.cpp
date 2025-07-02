#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    int umur;
    string jurusan;

    Mahasiswa *next;
};
Mahasiswa *head, *tail, *curr, *newNode, *del;

void tambahDataPertama(string nama, int umur, string jurusan) {
    head = new Mahasiswa;
    head->nama = nama;
    head->umur = umur;
    head->jurusan = jurusan;
    head->next = NULL;
    tail = head;
}

void tambahData(string nama, int umur, string jurusan) {
    newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->umur = umur;
    newNode->jurusan = jurusan;
    newNode->next = nullptr;
    
}

void tampilData() {
    curr = head;
    while (curr != nullptr) {
        cout << "Nama: " << curr->nama << ", Umur: " << curr->umur << ", Jurusan: " << curr->jurusan << endl;
        curr = curr->next;
    }
}

void hapusData(string nama) {
    curr = head;
    del = nullptr;

    if (head == nullptr) {
        cout << "Tidak ada data untuk dihapus." << endl;
        return;
    }

    if (head->nama == nama) {
        del = head;
        head = head->next;
        delete del;
        cout << "Data dengan nama " << nama << " telah dihapus." << endl;
        return;
    }

    while (curr->next != nullptr && curr->next->nama != nama) {
        curr = curr->next;
    }

    if (curr->next == nullptr) {
        cout << "Data dengan nama " << nama << " tidak ditemukan." << endl;
    } else {
        del = curr->next;
        curr->next = del->next;
        delete del;
        cout << "Data dengan nama " << nama << " telah dihapus." << endl;
    }
}

int main() {
    head = nullptr;
    tail = nullptr;

    tambahData("Alice", 20, "Teknik Informatika");
    tambahData("Bob", 22, "Sistem Informasi");
    tambahData("Charlie", 21, "Teknik Komputer");

    cout << "Data Mahasiswa:" << endl;
    tampilData();

    hapusData("Bob");
    cout << "\nSetelah menghapus data Bob:" << endl;
    tampilData();

    hapusData("David"); // Data tidak ada

    return 0;
}
