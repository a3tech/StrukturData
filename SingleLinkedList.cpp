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
using namespace std;

struct simpul{
	int sisi, luas;
simpul *simpulnext;}
*baru, *awal=NULL, *akhir=NULL, *hapus, *temp;

void buat_baru(){
	baru=(simpul*)malloc(sizeof(struct simpul));
	cout<<"Masukan Sisi =";cin>>baru->sisi;
	baru->luas=baru->sisi*baru->sisi;
	cout<<"Data Berhasil Ditambahkan Dalam Simpul"<<endl;
	baru->simpulnext=NULL;}
	
void tambah_depan(){
	buat_baru();
	if(awal==NULL){
		awal=baru;
		akhir=baru;
	akhir->simpulnext=NULL;}
	else{
		baru->simpulnext=awal;
	awal=baru;}
cout<<endl<<endl<<endl;}

void tambah_belakang(){
	buat_baru();
	if(awal==NULL){
	awal=baru;}
	else{
	akhir->simpulnext=baru;}
	akhir=baru;
	akhir->simpulnext=NULL;
cout<<endl;}

void hapus_depan(){
	if(awal==NULL)
		cout<<"Simpul Masih Kosong";
	else{
		hapus=awal;
		awal=awal->simpulnext;
	free(hapus);
	cout<<"Data Berhasil Dihapus"<<endl;}
cout<<endl;}

void hapus_belakang(){
	if(awal==NULL)
		cout<<"Simpul Masih Kosong";
	else if(awal==akhir){
		hapus=awal;
		awal=awal->simpulnext;
	free(hapus);
	cout<<"Data Berhasil Dihapus"<<endl;}
	else{
		hapus=awal;
		while(hapus->simpulnext!=akhir)
		hapus=hapus->simpulnext;
		akhir=hapus;
		hapus=akhir->simpulnext;
		akhir->simpulnext=NULL;
	free(hapus);
	cout<<"Data Berhasil Dihapus"<<endl;}
cout<<endl;}

void tampil(){
	int a=1;
	if(awal==NULL)
		cout<<"Simpul Masih Kosong"<<endl<<endl;
	else{
		temp=awal;
		while(temp!=NULL){
		cout<<"Data Dalam Simpul "<<a<<" : "<<endl;
		cout<<"Sisi Persegi = "<<temp->sisi<<endl;
		cout<<"Luas Persegi = "<<temp->luas<<endl<<endl;
		temp=temp->simpulnext;
		a++;}}}

main(){

int pil;

do{

cout<<"Program Utuk Menghitung Luas Persegi Dengan Single Linked List"<<endl;
cout<<"Pilihan Untuk Mengakses Linked List"<<endl;
cout<<"1.Tambah Depan"<<endl;
cout<<"2.Tambah Belakang"<<endl;
cout<<"3.Hapus Depan"<<endl;
cout<<"4.Hapus Belakang"<<endl;
cout<<"5.Tampilkan"<<endl;
cout<<"6.Selesai"<<endl;
cout<<"Masukan Pilihan Anda	=";cin>>pil;

switch(pil){

	case 1 :
	tambah_depan();
	break;
	
	case 2 :
	tambah_belakang();
	break;
	
	case 3 :
	hapus_depan();
	break;
	
	case 4 :
	hapus_belakang();
	break;
	
	case 5 :
	tampil();
	break;
	
	case 6 :
	return 0;
	break;
	
	default :
	cout<<"Anda Salah Pilihan BRO !";
}}
while(pil!=7);
getch();}