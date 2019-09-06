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

class linked_list_queue{
		private :
        struct node{
        int data;
        node *next;};
        node *rear;
        node *entry;
        node *print;
        node *front;
		
		public :
        linked_list_queue();
        void enqueue();
        void dequeue();
        void print_list();};

linked_list_queue::linked_list_queue(){
    rear=NULL;
   front=NULL;
}

void linked_list_queue::enqueue(){
    int angka;
   cout<<"Masukkan Angka Kedalam Queue:";cin>>angka;
   entry=new node;
   if(rear==NULL){
          entry->data=angka;
          entry->next=NULL;
          rear=entry;
          front=rear;
   }
   else{
       entry->data=angka;
      entry->next=NULL;
      rear->next=entry;
      rear=entry;
   }
   cout<<endl;
   cout<<"Data "<<angka<<" Telah Masuk"<<endl;
   getch();
}

void linked_list_queue::dequeue(){
    if(front==NULL){
       cout<<"Queue kosong";cout<<endl;
   }
   else{
       int deleted_element=front->data;
      node *temp;
      temp=front;
      front=front->next;
      delete temp;
      cout<<deleted_element<<" Telah Dihapus";
      cout<<endl;
    }
    getch();
}

void linked_list_queue::print_list(){
    print=front;
    if(print!=NULL){
         cout<<"Dara Dalam Queue:"<<endl;
    }
    else{
        cout<<"Queue Kosong";cout<<endl;
    }
    while(print!=NULL){
          cout<<print->data<<" ";
          print=print->next;
    }
   getch();
}

main(){
    int pilih;
   linked_list_queue queue;
   do{
   cout<<"\n\nPROGRAM LINKED LIST DENGAN QUEUE"<<endl;
   cout<<"\n1.Enqueue data"<<endl;
   cout<<"2.Dequeue data"<<endl;
   cout<<"3.Tampilkan data"<<endl;
   cout<<"Masukan Pilihan Anda:";cin>>pilih;cout<<endl;
   if(pilih==1){
            queue.enqueue();
   }
   if(pilih==2){
            queue.dequeue();
   }
   if(pilih==3){
            queue.print_list();
   }
    }
    while(pilih!=0||pilih>3);
  getch();

} 