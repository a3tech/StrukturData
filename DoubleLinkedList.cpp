/*Nama Anggota Kelompok :

Farhan Arintoko	16.12.9117
Annas Al Amin	16.12.9118
Ridho Bekti H	16.12.9119
M Fajar Al M	16.12.9123
M Lutfi Alfian	16.12.9150
Aditya Gilang P	16.12.9157
Ramdan Hidayat	16.12.9168

Kelas		16.S1SI.03*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct simpul{
	int nilai;
simpul *simpulnext, *simpulback;}
*baru, *head=NULL, *tail=NULL, *temp;


void alokasi_simpul(int a){
	baru = (simpul *) malloc (sizeof(simpul));
	if(baru==NULL){
		cout<<"Alokasi Gagal !";
	exit(1);}
	else{
	baru->nilai=a;
	baru->simpulnext=NULL;
	baru->simpulback=NULL;}}
	

void buat_baru(){
	cout<<"Data Masih Kosong Dan Simpul Akan Dibuat Dengan Nilai Yang Diinputkan"<<endl;
	system("PAUSE");
	head=tail=baru;}
	
void sisip_awal(){
	if(head==NULL && tail==NULL)
		buat_baru();
	else{
		baru->simpulnext=head;
		head->simpulback=baru;
		head=baru;
		cout<<"Nilai "<<baru->nilai<<" Berhasil Diinputkan Dalam Simpul"<<endl;}
cout<<endl<<endl<<endl;}

void sisip_akhir(){
	if(head==NULL && tail==NULL)
		buat_baru();
	else{
		baru->simpulback=tail;
		tail->simpulnext=baru;
		tail=baru;
		cout<<"Nilai "<<baru->nilai<<" Berhasil Diinputkan Dalam Simpul"<<endl;}
cout<<endl<<endl<<endl;}

void pesan(){
	cout<<"Simpul Baru Tidak Dapat Disisipkan Karena Nilai Tidak Sesuai"<<endl<<endl;
	system("PAUSE");}

void pesan1(){
	cout<<"Tidak Ada Nilai Yang Dihapus"<<endl<<endl;
	system("PAUSE");}
	
void tambah_sebelum(int s)
{
	simpul *before=head;
	int cek=0;
	if(before->simpulnext==NULL)
		cek=1;
	else
	{
		while(before->simpulnext->nilai!=s)
		{
			before=before->simpulnext;
			if(before->simpulnext==NULL)
			{
				cek = 1;
				break;
			}
		}
	}
	if(cek==0)
	{
		baru->simpulback = before;
		baru->simpulnext = before->simpulnext;
		before->simpulnext->simpulback = baru;
		before->simpulnext = baru;
	}
	else
		pesan();
}

void tambah_sesudah(int s)
{
	simpul *after=tail;
	int cek=0;
	if(after->simpulback == NULL)
		cek=1;
	else
	{
		while(after->simpulback->nilai!=s)
		{
			after=after->simpulback;
			if(after->simpulback==NULL)
			{
				cek = 1;
				break;
			}
		}
	}
	if(cek==0)
	{
		baru->simpulnext = after;
		baru->simpulback = after->simpulnext;
		after->simpulback->simpulnext = baru;
		after->simpulback = baru;
	}
	else
		pesan();
}

void free_simpul(simpul *h){
	free(h);
	h=NULL;
cout<<"Data Berhasil Dihapus"<<endl<<endl;}

void hapus_satu()
{
	simpul *hapus = head;
	head = NULL;
	tail = NULL;
	free_simpul(hapus);
}

void hapus_awal()
{
	simpul *hapus = head;
	head->simpulnext->simpulback = NULL;
	head =  head->simpulnext;
	free_simpul(hapus);
}

void hapus_akhir()
{
	simpul *hapus = tail;
	tail->simpulback->simpulnext = NULL;
	tail =  tail->simpulback;
	free_simpul(hapus);
}

void hapus_tengah(int s)
{
	simpul *hapus=head;
	int cek=0;
	while(hapus->nilai!=s)
	{
		if(hapus->simpulnext==NULL)
		{
			cek=1;
			break;
		}
		hapus = hapus->simpulnext;
	}
	if(cek==0)
	{
		hapus->simpulback->simpulnext = hapus->simpulnext;
		hapus->simpulnext->simpulback = hapus->simpulback;
		free_simpul(hapus);
	}
	else
		pesan1();
}

void tampil()
{
	temp= head;
	cout<<"Data Dalam Simpul = "<<endl<<endl;
	while(temp!=NULL)
	{
		cout<<temp->nilai<<endl<<endl;
		temp=temp->simpulnext;
	}
}

main(){

head=baru;
int pil, s, nilai;

do{

cout<<"Program Utuk Menginputkan Nilai/Angka Dengan Double Linked List"<<endl;
cout<<"Pilihan Untuk Mengakses Linked List"<<endl;
cout<<"1.Sisip Awal"<<endl;
cout<<"2.Sisip Akhir"<<endl;
cout<<"3.Tambah Sebelum Simpul"<<endl;
cout<<"4.Tambah Sesudah Simpul"<<endl;
cout<<"5.Hapus Awal"<<endl;
cout<<"6.Hapus Akhir"<<endl;
cout<<"7.Hapus Tengah"<<endl;
cout<<"8.Tampilkan"<<endl;
cout<<"9.Selesai"<<endl;
cout<<"Masukan Pilihan Anda	=";cin>>pil;

switch(pil){

	case 1 :
		cout<<"Masukan Nilai	=";
		cin>>nilai;
		alokasi_simpul(nilai);
		sisip_awal();
		break;
	
	case 2 :
		cout<<"Masukan Nilai	=";
		cin>>nilai;
		alokasi_simpul(nilai);
		sisip_akhir();
		break;
	
	case 3 :
		cout<<"Masukan Nilai	=";
		cin>>nilai;
		temp= head;
		cout<<"Data Dalam Simpul = "<<endl<<endl;
		while(temp!=NULL)
		{
		cout<<temp->nilai<<endl<<endl;
		temp=temp->simpulnext;
		}
		alokasi_simpul(nilai);
		if(head==NULL && tail==NULL)
		buat_baru();
		else{
		cout<<"Dimasukan Sebelum	=";
		cin>>s;
		if(s==head->nilai)
			sisip_awal();
		else
			tambah_sebelum(s);}
		break;
	
	case 4 :
		cout<<"Masukan Nilai	=";
		cin>>nilai;
		temp= head;
		cout<<"Data Dalam Simpul = "<<endl<<endl;
		while(temp!=NULL)
		{
		cout<<temp->nilai<<endl<<endl;
		temp=temp->simpulnext;
		}
		alokasi_simpul(nilai);
		if(head==NULL && tail==NULL)
		buat_baru();
		else{
		cout<<"Dimasukan Sesudah	=";
		cin>>s;
		if(s==tail->nilai)
			sisip_akhir();
		else
			tambah_sesudah(s);}
		break;
	
	case 5 :
		if(head == NULL && tail == NULL)
			pesan1();
		else if(head == tail)
			hapus_satu();
		else
			hapus_awal();
		break;
	
	case 6 :
		if(head == NULL && tail == NULL)
			pesan1();
		else if(head == tail)
			hapus_satu();
		else
			hapus_akhir();
		break;
	
	case 7 :
		temp= head;
		cout<<"Data Dalam Simpul = "<<endl<<endl;
		while(temp!=NULL)
		{
		cout<<temp->nilai<<endl<<endl;
		temp=temp->simpulnext;
		}
		cout<<"Masukan Nilai Yang Akan Dihapus =";
		cin>>nilai;cout<<endl;
		if(head == NULL && tail == NULL)
		pesan1();
		else if(nilai == head->nilai && nilai == tail->nilai && head == tail)
			hapus_satu();
		else if(nilai == head->nilai)
			hapus_awal();
		else if(nilai == tail->nilai)
			hapus_akhir();
		else
			hapus_tengah(nilai);
		break;
		
	case 8 :
		tampil();
		break;
		
	case 9 :
		return 0;
		break;
	
	break;
	
	default :
	cout<<"Anda Salah Pilihan BRO !";
}}
while(pil!=10);
getch();}