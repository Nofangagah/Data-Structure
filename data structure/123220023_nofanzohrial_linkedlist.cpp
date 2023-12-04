#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct{
	string namabuku;
	float hargabuku;
} data;

struct node{
	data info;
	node *next;
} * first, *last, *help, *del;

// Fungsi untuk membuat linked list kosong
void createnewlist(){
	first = NULL;
	last = NULL;
}

// Fungsi untuk memeriksa apakah linked list kosong
int emptylist(){
	if (first == NULL)
		return (true);
	else
		return (false);
}

// Fungsi untuk menyisipkan node baru berdasarkan harga buah
void sisipNode(data IB){
	node *NB, *help; // NB = Nilai Baru
	NB = new node;
	NB->info = IB;
	NB->next = NULL;
	if (emptylist()){
		first = NB;
		last = NB;
	}
	else if (IB.hargabuku <= first->info.hargabuku) { // Sisip di depan
		NB->next = first;
		first = NB;
	}
	else{
		help = first;
		while (help->next != NULL && IB.hargabuku > help->next->info.hargabuku)
			help = help->next;
		NB->next = help->next; // Sisip di tengah atau di belakang
		help->next = NB;
		if (IB.hargabuku > last->info.hargabuku)
			last = NB;
	}
}

// Fungsi untuk menghapus node berdasarkan nama buah
void deleteNode(string IH) {
    node *del, *help, *help2 = NULL; // Inisialisasi help2 ke NULL
    if (emptylist())
        cout << "List masih kosong" << endl;
    else if (first->info.namabuku == IH) {
        del = first; // Hapus di awal
        first = del->next;
        delete del; // Menggunakan delete untuk menghapus node
        cout << "Data berhasil dihapus" << endl;
    }
    else {
        help = first;
        while (help->next != NULL && IH != help->info.namabuku) {
            help2 = help; // Memperbarui help2 saat iterasi
            help = help->next;
        }
        if (IH == help->info.namabuku) {
            del = help;
            if (del == last) { // Hapus di akhir
                last = help2; // Menggunakan help2 untuk menghapus node terakhir
                last->next = NULL;
            }
            else {
                help2->next = del->next; // Hapus di tengah
            }
            delete del; // Menggunakan delete untuk menghapus node
            cout << "Data berhasil dihapus" << endl;
        }
        else
            cout << "Node tidak ditemukan!\n";
    }
}

// Fungsi untuk mencetak data buah dalam urutan terbalik
void bacaMundur()
{
    node *front, *help;
    front = first;
    first = last;
    do
    {
        help = front;
        while (help->next != last)
            help = help->next;
        last->next = help;
        last = help;
    } while (last != front);
    last->next = NULL;
    help = first;
    while (help != NULL)
    {
        cout << "Nama buku\t: " << help->info.namabuku << endl;
        cout << "Harga buku\t: " << help->info.hargabuku << endl;
        cout << endl;
        help = help->next;
    }
}
void bacaMaju()
{
    node *help;
    help = first;
    if (help == NULL)
    {
        cout << "Data tidak ada" << endl;
    }
    else
    {
        while (help != NULL)
        {
            cout << "Nama buku\t: " << help->info.namabuku << endl;
            cout << "Harga buku\t: " << help->info.hargabuku << endl;
            cout << endl;
            help = help->next;
        }
    }
}

int main(){
	int pilih, pilihBaca, jumlahdata = 0;
	string kembali = "y", name;
	data buku;
	while (kembali == "y"){
		//main menu
		system("cls");
		cout << "1. Input nama buku" << endl;
		cout << "2. tampilkan nama buku" << endl;
		cout << "3. hapus buku" << endl;
		cout << "4. Exit" << endl;
		cout << "pilih menu\t: ";
		cin >> pilih;
		//menu 1
		if (pilih == 1){
			system("cls");
			cout << "masukkan jumlah data\t: ";
			cin >> jumlahdata;
			cout << endl;
			for (int i = 0; i < jumlahdata; i++){
				cin.ignore();
				cout << "Nama buku \t: ";
				getline(cin, buku.namabuku);
				cout << "harga buku\t: ";
				cin >> buku.hargabuku;
				cout << endl;
				sisipNode(buku);
			}
			cout << "kembali ke menu awal? (y/n)";
			cin >> kembali;
			cout << endl;
		}
		//menu 2
		else if (pilih == 2){
			system("cls");
			system("cls");
            cout << "1. Baca Maju" << endl;
            cout << "2. Baca Mundur" << endl;
            cout << "Pilih\t: ";
            cin >> pilihBaca;
            if (pilihBaca == 1)
            {
				system("cls");
                bacaMaju();
            }
            else if (pilihBaca == 2)
            {
				system("cls");
                bacaMundur();
            }
            else
                cout << "Menu Tidak Ditemukan" << endl;

            cout << "Kembali ke menu awal?(y/n)";
            cin >> kembali;
            cout << endl;
		}
		//menu 3
		else if (pilih == 3){
			system("cls");
			cin.ignore();
			cout << "\nmasukkan nama buku yang ingin dihapus" << endl;
			cout << "nama buku\t: ";
			getline(cin, name);
			deleteNode(name);
			cout << "kembali ke menu awal? (y/n)";
			cin >> kembali;
			cout << endl;
		}
		//menu 4
		else if (pilih == 4){
			system("cls");
			exit(0);
		}
		//salah menginput menu atau input menu yang tidak tersedia
		else
			system("cls");
			cout << "tidak ada" << endl;
	}
}
