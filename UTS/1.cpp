#include <iostream>
#include <cctype>
using namespace std;

int main(){
    system("cls");
    int pesanan;
    int nomor = 1;
    cout<<"Selamat datang di IKLC Paws & Treats\n";
    cout<<"Masukkan jumlah pesanan : "; cin>>pesanan;

    string* nama_hewan = new string[pesanan];
    string* menu_makanan = new string[pesanan];
    int* status = new int[pesanan];

    for(int i = 0; i<pesanan;i++){
        cout<<"\nPesanan "<<i+1<<endl;
        cout<<"Nama Hewan : "; cin>>nama_hewan[i];
        cin.ignore();
        cout<<"Menu Pesanan : "; getline(cin,menu_makanan[i]);
        cout<<"Status VIP (1 = biasa, 2 = VIP) : "; cin>>status[i];   
        if (status[i] < 1 || status[i] > 2){
            cout<<"Status salah, ulang kembali :) "<<endl;
            i--;
            continue;
        }  
    }

    for(int i = 0; i < pesanan;  i++){
        for(int j =  0 ; j< nama_hewan[i].length(); j++)
        nama_hewan[i][j] = toupper(nama_hewan[i][j]);
    }

    for (int i = 0; i < pesanan ; i++){
        if(status[i] == 2)
            cout<< nomor++ <<". "<<nama_hewan[i]<<" - "<<menu_makanan[i]<<" [VIP]"<<endl;
    }
    for (int i = 0; i<pesanan ; i++){
        if (status[i] == 1)
        cout<< nomor++ <<". "<<nama_hewan[i]<<" - "<<menu_makanan[i]<<" "<<endl;   
    }

    // Bersihkan memori
    delete[] nama_hewan;
    delete[] menu_makanan;
    delete[] status;

    return 0;
}