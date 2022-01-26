#include <iostream>
#include <conio.h> //Menggunakan getch
#include <stdlib.h> //Menggunakan system "CLS"
#define MAX 100 //Maksimal banyaknya nomor antrian
using namespace std;

int nomor [MAX];
int head=-1;
int tail=-1;

// Fungsi yang berguna untuk menunjukkan bahwa tail = -1
bool IsEmpty() {
	if(tail == -1 && head == -1){
		return true;
	}else{
		return false;
	}
}

// Fungsi yang berguna untuk menunjukkan bahwa tail = MAX -1
bool IsFull(){
	if(tail == MAX-1){
		return true;
	}else {
		return false;
	}
}

void AntrianMasuk(int no) {
	if (IsEmpty()) {
		head=tail=0;
	}else {
		tail++;
	}
	nomor[tail] = no;
}

int AntrianKeluar(){
	int x = 0;
	if(IsEmpty()) {
		cout << "Antrian sudah kosong! ";
		getch();
	} else if (head == tail){
		x = nomor[head];
		head = tail = -1;
	} else {
		x = nomor[head];
		head ++;
	}
	return x;
}

void Clear(){
	head=tail=-1;
}

void View(){
	if(IsEmpty()) {
		cout << "Antrian Kosong ";
	}else {
		system("cls");
		for(int a=head; a<=tail; a++){
			cout << "=========================================="
				 << "\n >> No. Antri : [" << nomor[a] << "]"
				 << "\n=========================================="<< endl;
		}
	}
}

void login(){
	string nama,pass;
	system("cls");
	cout << "\t     ======= STAFF =======\n";
	cout << "\n\tMasukkan Username dan Password";
	cout << "\n\tUsername : ";
	cin >> nama;
	cout << "\tPassword : ";
	cin >> pass;
	if (nama == "kelompok12"){
		if (pass == "admin"){
			cout << "\n\t ======= LOGIN BERHASIL =======";
			cout << "\n\n\tAnda Login Sebagai : " << nama;
		}
		else{
			cout << "\n\t Password Anda Salah!" << endl;
			exit(0);
		}
	}
	else if (pass == "admin"){
		cout << "\n\t Username Anda Salah!" << endl;
		exit(0);
	}
	else {
		cout << "\n\tUSERNAME DAN PASSWORD ANDA SALAH!" << endl;
		exit(0);
	}
	cout << "\n\n\t Tekan Enter untuk melanjutkan";
	getch();
}

void pelanggan(){
	int choose, p=1, urut;
	do {
		system("cls");
		cout << "\n=========================================================\n";
		cout << "\t\t ** Selamat Datang! ** ";
		cout << "\n=========================================================";
		cout << "\n1. Menambah Antrian";
		cout << "\n2. Melihat Daftar Antrian";
		cout << "\n3. Keluar";
		cout << "\n=========================================================\n";
		cout << "\nMasukkan Pilihan : "; cin >> choose;
		if(choose == 1){
			if(IsFull()){
				cout << "Antrian Sudah Penuh";
			}
			else {
				urut = p;
				AntrianMasuk(urut);
				cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n" << endl;
				cout << " \t     NO. ANTRIAN					   " << endl;
				cout << " \t\t  " << p << "				         \n" << endl; 
				cout << "**************************************** \n" << endl;
				cout << " \t  Silahkan Mengantri				   " << endl;
				cout << " \t Menunggu " << tail << " Antrian     \n" << endl;
				cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^   " << endl;
				p++;
			}
				cout << "\nTekan Enter untuk kembali ke menu utama" << endl;
		}
		else if(choose == 2){
			View();
		}
		else if(choose == 3){
		}
		else{
			cout << "Menu yang Anda ketik tidak terdaftar! \n" << endl;
		}
		getch();
	}while(choose != 3);
}

void staff(){
	int pil;
	login();
	do {
		system("cls");
		cout << "\n=============================================\n";
		cout << "\t\t ** STAFF ** ";
		cout << "\n=============================================";
		cout << "\n1. Memanggil Antrian";
		cout << "\n2. Melihat Daftar Antrian";
		cout << "\n3. Mereset Antrian";
		cout << "\n4. Keluar";
		cout << "\n=============================================";
		cout << "\nPilihan : ";
		cin >> pil;
		if(pil == 1){
			cout << "======================================="   << endl;
			cout << "\t No. Antri : [" << nomor[head] << "]" ;
			cout << "\n=======================================" << endl;
			AntrianKeluar();
			cout << "Silahkan menuju ke customer service!"		<< endl;
		}
		else if(pil == 2){
			View();
		}
		else if(pil == 3){
			Clear();
			cout << "Antrian Dikosongkan";
		}
		else if(pil == 4){
		}
		else{
			cout << "Menu yang Anda ketik tidak terdaftar! \n" << endl;
		}getch();
	}while(pil != 4);
}

//Fungsi Utama
int main(){
		int menu;
	do {
		system("cls");
		cout <<"\t+-------------------------------------------------+\n";
		cout <<"\t|                 Program Antrian                 |\n";
		cout <<"\t|                ** Barbershop **	          |\n";
		cout <<"\t|            	      '12'            	          |\n";
		cout <<"\t+-------------------------------------------------+\n";
		cout <<"\t| 1. Pelanggan                                    |\n";
		cout <<"\t| 2. Staff                         		  |\n";
		cout <<"\t| 3. Keluar Program                 		  |\n";
		cout <<"\t+-------------------------------------------------+\n";
		cout <<"\tPilihan : ";
		cin >> menu;
		switch (menu){
		case 1:
			pelanggan();
			break;
		case 2:
			staff();
			break;
		case 3:
			system("cls");
			cout <<"\n\tTerima Kasih sudah berkunjung! ";	
		}
	}while (menu!=3);
}
