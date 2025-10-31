#include <iostream>
#include <string>
using namespace std;

struct Node{
    string nama_barang;
    int harga_barang;
    int jumlah_barang;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void masukDiAwal(string n_b, int h_b, int j_b){
    Node *newNode = new Node;
    newNode->nama_barang = n_b;
    newNode->harga_barang  = h_b;
    newNode->jumlah_barang = j_b;
    newNode->next = head; 
    head = newNode;
    if (tail == NULL) tail = newNode; 
}

void masukDiAkhir(string n_b, int h_b, int j_b){
    Node *newNode = new Node;
    newNode -> nama_barang = n_b;
    newNode -> harga_barang  = h_b;
    newNode -> jumlah_barang = j_b;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        tail = head;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
}

void masukSetelahNama(string n_b, int h_b, int j_b, string masuk_setelah){
    if (head == NULL){
        cout<<"List Kosong, insert di depan dahulu\n";
        return;
    }
    Node *newNode = new Node;
    newNode -> nama_barang = n_b;
    newNode -> harga_barang  = h_b;
    newNode -> jumlah_barang = j_b;
    newNode -> next = NULL;

    Node *p = head;
    while (p != NULL && p -> nama_barang != masuk_setelah){
        p = p -> next;
    }
    if (p==NULL){
        cout<<"Node dengan nilai "<<masuk_setelah<<" tidak ditemukan\n";
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p== tail){
            tail = newNode;
        }
    }
}

void tampilkan(){
    Node *p = head;
    int totalBarang = 0;
    long totalHarga = 0;
    while(p != NULL){
        cout<< p->nama_barang << " - Rp." << p->harga_barang << " x" << p->jumlah_barang;
        totalBarang++;
        totalHarga += p->harga_barang * p->jumlah_barang;
        p = p -> next;
        cout<<endl;
    }
    cout<<endl;
    cout<<"Total Barang : "<< totalBarang << endl;
    cout<<"Total Harga : Rp."<< totalHarga << endl;

}

void hapusNama(const string& hapus_barang) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    if (head->nama_barang == hapus_barang) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
        return;
    }
    Node *p = head;
    while (p->next != NULL && p->next->nama_barang != hapus_barang) {
        p = p->next;
    }
    if (p->next == NULL) {
        cout << "Node dengan nilai " << hapus_barang << " tidak ditemukan!\n";
    } else {
        Node *temp = p->next;
        p->next = temp->next;
        if (temp == tail) tail = p;
        delete temp;
    }
}

int main(){
    system("cls");
    int n;
    cout<<"Organize Shopping Cart"<<endl;
    cout<<"Masukkan Jumlah barang awal : "; cin>>n;

    Node detail;
    for (int i = 0 ;  i < n ; i++){
        string nama;
        int harga;
        int jumlah;
        cout<<"\nBarang "<<i+1<<endl;
        cin.ignore();
        cout<<"Nama : "; getline(cin,nama);
        cout<<"Harga : "; cin>>harga;
        cout<<"Jumlah : "; cin>>jumlah;
        masukDiAkhir(nama,harga,jumlah);      
    }
    char tanya;
    string  hapus_barang;
    cout<<"\nApakah kamu ingin menghapus barang? (Y/N) : "; cin>>tanya;
    if (tanya == 'Y'||tanya =='y'){
        cin.ignore();
        cout<<"Masukkan nama barang yang ingin di hapus: "; getline(cin,hapus_barang);
        if (!hapus_barang.empty()) {
        hapusNama(hapus_barang);
        tampilkan();
        }
    } else if (tanya == 'N' || tanya == 'n'){
        tampilkan();
    } else  {
        cout<<"Perintah tidak diketahui, coba lagi :)"<<endl;
    }
}