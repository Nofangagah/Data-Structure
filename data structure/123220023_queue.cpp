#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Mobil {
    string namaPeminjam;
    string tipeMobil;
    string platNomor;
    Mobil* next;
};

Mobil* front = NULL;
Mobil* rear = NULL;
int count = 0;

void enqueue(string namaPeminjam, string tipeMobil, string platNomor) {
    Mobil* newMobil = new Mobil;
    newMobil->namaPeminjam = namaPeminjam;
    newMobil->tipeMobil = tipeMobil;
    newMobil->platNomor = platNomor;
    newMobil->next = NULL;

    if (rear == NULL) {
        front = rear = newMobil;
    } else {
        rear->next = newMobil;
        rear = newMobil;
    }

    count++;

    cout << "Data berhasil ditambahkan ke dalam antrian." << endl;
}
void dequeue(int posisi) {
	
    if (front == NULL) {
        cout << "Antrian kosong." << endl;
        return;
    }

    if (posisi < 1 || posisi > count) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    Mobil* current = front;
    Mobil* prev = NULL;

    
    for (int i = 1; i < posisi; ++i) {
        prev= current;
        current = current->next;
    }

    
    if (prev == NULL) {
       
        front = current->next;
    } else {
        prev->next = current->next;
    }

    if (current == rear) {
        
        rear = prev;
    }

    delete current;
    count--;

    cout << "Data berhasil dihapus dari antrian." << endl;
}



void printQueue() {
    if (front == NULL) {
        cout << "Antrian kosong." << endl;
    } else {
        Mobil* current = front;
        while (current != NULL) {
            cout << "Nama Peminjam: " << current->namaPeminjam << " - Tipe Mobil: " << current->tipeMobil << " - Plat Nomor: " << current->platNomor << endl;
            current = current->next;
        }
    }
}

int jumlahAntrian() {
    return count;
}

void back() {
    string backtomenu;
    bool backmenu = true;
    backmenu = true;
    cout << "kembali?(y/n) : ";
    cin >> backtomenu;
    while (backmenu) {

        if (backtomenu == "y") {
            system("cls");
            backmenu = false;
        } else if (backtomenu == "n") {
            system("cls");
            cout << "Terima kasih." << endl;
            exit(0);
        } else {
            cout << "invalid input, cuma y/n ajah" << endl;
            cin >> backtomenu;
        }
    }
}

int main() {
    int menu;
    string namaPeminjam, tipeMobil, platNomor;


while (true){
    
        cout << "Menu: \n";
        cout << "1. INPUT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. PRINT DATA\n";
        cout << "4. JUMLAH ANTRIAN\n";
        cout << "5. EXIT\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cin.ignore();
                cout << "Masukkan Nama Peminjam: ";
                getline(cin, namaPeminjam);

                cout << "Masukkan Tipe Mobil: ";
                getline(cin, tipeMobil);

                cout << "Masukkan Plat Nomor: ";
                getline(cin, platNomor);
                enqueue(namaPeminjam, tipeMobil, platNomor);
                back();
                break;
            case 2:
            int posisi;
             cout << "Masukkan posisi data yang ingin dihapus: ";
              cin >> posisi;
                dequeue(posisi);
                back();
                break;
            case 3:
                printQueue();
                back();
                break;
            case 4:
                cout << "Jumlah antrian yang terisi: " << jumlahAntrian() << endl;
                back();
                break;
            case 5:
                cout << "kabur" << endl;
                exit(0);
                break;
            default:
                cout << "salah yahh." << endl;
                break;
        }
    
   }


    
    return 0;
}
