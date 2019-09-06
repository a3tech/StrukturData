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
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef int itemtipe;
typedef struct simpul node;
struct simpul
{
	itemtipe item;
	node *next;
};

struct Stack{
	node *TOS;
};

node *baru;

void awal()
{
	cout<<"PROGRAM LINKED LIST DENGAN STACK"<<endl;
}

void allocate_node(itemtipe x)
{
	baru = (node *) malloc (sizeof(node));
	if(baru==NULL)
	{
		cout<<"Penempatan Gagal\n";
		exit(1);
	}
	else
	{
		baru->item=x;
		baru->next=NULL;
	}
}

void inisialisasi(Stack *s)
{
	s->TOS = NULL;
}

int kosong(Stack *s)
{
	return s->TOS==NULL;
}

void push(Stack *s)
{
	baru->next = s->TOS;
	s->TOS = baru;
}

itemtipe pop(Stack *s)
{
	node *temp;
	if(kosong(s))
	{
		cout<<"Data Kosong\n";
		return ' ';
	}
	else
	{
		temp = s->TOS;
		s->TOS = s->TOS->next;
		return temp->item;
		free(temp);
		temp=NULL;
	}
}

void tampil(Stack *s)
{
	Stack bantu;
	bantu = *s;
	cout<<"\nData Pada Simpul =  ";
	while(bantu.TOS!=NULL)
	{
		printf("%d ", bantu.TOS->item);		bantu.TOS = bantu.TOS->next;}
	cout<<"\n\n";
}

int main()
{
	int pilih, data;
	char ulang='y';
	Stack ujung;

	inisialisasi(&ujung);
	while(ulang=='y')
	{
		system("CLS");
		awal();
		//tampil(&ujung);
		cout<<"Menu Pilihan Anda :\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Tampilkan Stack\n";
		cout<<"\nMasukan Pilihan Anda          : ";
		scanf("%d", &pilih);
		switch(pilih)
		{
		case 1:
			cout<<"Masukkan data     : ";
			scanf("%d", &data);
			allocate_node(data);
			push(&ujung);
			break;
		case 2:
			pop(&ujung);
			break;
		case 3:
			tampil(&ujung);
			break;
		}
		fflush(stdin);
		cout<<"Anda Ingin Input Lagi ? (Y/T)= ";
		scanf("%c", &ulang);
	}
}