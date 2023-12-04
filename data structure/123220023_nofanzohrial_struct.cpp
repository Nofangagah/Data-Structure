#include <iostream>
using namespace std;
int banyak, beli;
string backtomenu, Buah;
bool backmenu = true;



struct food {
	float harga;
	string nama;
	
	
	
};
food foods [100];

  void input () {
  cout<<"Banyak Data : ";
  cin>>banyak;
  cin.ignore();
   for (int i = 0; i < banyak; i ++) {
	cout<<"Nama buah : ";
	getline (cin, foods[i].nama);
	cout<<"Harga Buah : ";
	cin>>foods[i].harga;
	cin.ignore();
	
	
	
 }
	
 } 

 void output () {
	 cout<<"Display Data"<<endl;
	 cout<<"Banyak data : " <<banyak<<endl;
	 for (int i = 0; i < banyak; i++) {
		 cout<<"Nama Buah : "<<foods[i].nama<<endl;
		 cout<<"Harga Buah : "<<foods[i].harga<<endl;
			  
	 }
}


void buy () {
	string buah;
	int tot;
	cout<<"Data Buah"<<endl;
	for (int i = 0; i < banyak; i++){
		cout<<"Nama Buah  : "<<foods[i].nama<<endl;
		cout<<"Harga Buah : "<<foods[i].harga<<endl;
	    cout<<endl;
	}
	cin.ignore();
	cout<<"Masukkan Nama Buah : ";
	getline(cin, buah);
	while ( tot < banyak) {
		if (buah == foods[tot].nama) {
			cout<<"Nama Buah     : "<<foods[tot].nama<<endl;
			cout<<"Harga Buah    : "<<foods[tot].harga<<endl;
			cout<<"Beli Berapa ? : ";
			cin>>beli;
			cout<<"Total Harga : "<<beli * foods[tot].harga<<endl;
			break;
			
			
		} else {
			tot++;
			
		}
			
	}
	
	
}
 
void back() {
	 backmenu = true;
	while (backmenu) {
		cout<<"kembali?(y/n) : ";
	    cin>>backtomenu;
		if (backtomenu == "y") {
			system("cls");
			backmenu = false;
		} else if (backtomenu == "n"){
			system("cls");
			cout<<"yaaaawrf";
			exit(0);
			
		} else {
			cout<<"invalid input, cuma y/n ajah"<<endl;
			
		}
		
		
	}
	
}


int main () {
	while (true) {
  string pil;
  cout<<"Data Buah"<<endl;
  cout<<"1.Nama Buah"<<endl;
  cout<<"2.Dsiplay Data Buah"<<endl;
  cout<<"3.Total"<<endl;
  cout<<"pilih 1-3 : ";
  cin>>pil;
  if (pil == "1") {
	  system("cls");
	  input();
	  back();
	  
	  
	  
  }else if (pil == "2") {
	  system("cls");
	  output();
	  back();
	  
	  
	  
	  
  }else if (pil == "3") {
	 buy();
	 back(); 
	 
	  
  }else {
	  cout<<"invalid input"<<endl;
	  break;
  }

}
		
}
