#include <iostream>
#include "Menu.h"

using namespace std;

int selectMenu(){
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "|                                MENU                                 |" << endl;
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "| 1.  Insert data parent                                              |" << endl;
    cout << "| 2.  Show all data parent                                            |" << endl;
    cout << "| 3.  Hapus data parent dan relasinya                                 |" << endl;
    cout << "| 4.  Mencari data parent tertentu                                    |" << endl;
    cout << "| 5.  Tambahkan data child                                            |" << endl;
    cout << "| 6.  Show all data child                                             |" << endl;
    cout << "| 7.  Mencari data child tertentu                                     |" << endl;
    cout << "| 8.  Menghubungkan data parent ke data child                         |" << endl;
    cout << "| 9.  Tampilkan seluruh data parent beserta childnya                  |" << endl;
    cout << "| 10. Mencari data child pada parent tertentu                         |" << endl;
    cout << "| 11. Menghapus data child pada parent tertentu beserta relasinya     |" << endl;
    cout << "| 12. Menghitung jumlah data child dari parent tertentu               |" << endl;
    cout << "| 0.  Exit                                                            |" << endl;
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "                                                                       " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "||  | PILIHAN | [1][2][3][4][5][6][7][8][9][10][11][12][0] ||" << endl;
    cout << "-------------------------------------------------------------" << endl;

    int input = 0;
    cout << "PILIHAN : ";
    cin >> input;
    cout << " " << endl;

    return input;
}

void Pilihan_1(List_P &LP){
    int input;
    infotype_Parent info;
    cout << "Masukan Jumlah Penerbangan Yang Akan Ditambahkan : ";
    cin >> input;
    for (int i = 0; i < input; i++){
        cout << "Hari Penerbangan   : ";
        cin >> info.Hari;
        cout << "Bandara            : ";
        cin >> info.NamaBandara;
        cout << "Daerah Bandara     : ";
        cin >> info.DaerahBandara;
        cout << " " << endl;

        if (findPenerbangan_P(LP, info.NamaBandara) != NULL){
            cout << "Penerbangan telah ada" << endl;
            cout << " " << endl;
        }else {
            address_Parent P = createElmtParent(info);
            insertLast(LP, P);
        }
    }
}

void Pilihan_2(List_P LP){
    address_Parent P = first(LP);

    if (P == NULL){
        cout << "LIST KOSONG" << endl;
        cout << " " << endl;
    }else {
        cout << "DAFTAR LIST PARENT" << endl;
        cout << "------------------" << endl;
        ShowDataParent(LP);
    }
}

void Pilihan_3(List_R &LR, List_P &LP){
    string NamaBandara, KodePenerbangan;
    address_Parent P;
    address_Child C;
    address_Relasi R;

    ShowDataParent(LP);
    cout << "Masukan Nama Bandara Yang Akan Dihapus : ";
    cin >> NamaBandara;

    R = first(LR);
    address_Relasi Q = findElementRelation(LR, P, C);
    while (R != NULL){
        if (findElementRelation(LR, P, C) == Q){
            deleteElementRelasi(LR, R);
        }
        R = next(R);
    }
    P = findPenerbangan_P(LP, NamaBandara);
    if (P == NULL){
        cout << "data tidak ditemukan" << endl;
    }else {
        deleteDataParent(LP, P);
    }

}

void  Pilihan_4(List_P LP){
    string NamaBandara;
    address_Parent P;

    cout << "Masukan Nama Bandara : ";
    cin >> NamaBandara;
    cout << " " << endl;
    P = findPenerbangan_P(LP, NamaBandara);
    if (P == NULL){
        cout << "Penerbangan Tidak Tersedia" << endl;
        cout << " " << endl;
    }else {
        cout << "Hari                   : " << info(P).Hari << endl;
        cout << "Bandara                : " << info(P).NamaBandara << endl;
        cout << "Daerah Bandara         : " << info(P).DaerahBandara << endl;
        cout << " " << endl;
    }
}

void Pilihan_5(List_C &LC){
    int X;
    infotype_Child info;
    cout << "Masukan Jumlah Maskapai Yang Akan Ditambahkan : ";
    cin >> X;
    for (int i = 0; i < X; i++){
        cout << "Nama Pesawat           : ";
        cin >> info.NamaPesawat;
        cout << "Kode Penerbangan       : ";
        cin >> info.KodePenerbangan;
        cout << "Asal Pesawat           : ";
        cin >> info.Asal;
        cout << "Jumlah Penumpang       : ";
        cin >> info.JumlahPenumpang;
        cout << " " << endl;

        if (findMaskapai(LC, info.KodePenerbangan) != NULL){
            cout << "Maskapai Dengan Kode Penerbangan Tersebut Telah Ada";
            cout << " " << endl;
        }else {
            address_Child P = createElmtChild(info);
            insertLast(LC, P);
        }
    }
}

void Pilihan_6(List_C LC){
    address_Relasi R;
    address_Child C = first(LC);
    if (C == NULL){
        cout << "LIST KOSONG" << endl;
        cout << " " << endl;
    }else {
       ShowDataChild(LC);
    }
}

void Pilihan_7(List_C LC){
    string Kode;
    address_Child C;

    ShowDataChild(LC);
    cout << "Masukan Kode Penerbangan : ";
    cin >> Kode;
    cout << " " << endl;
    C = findMaskapai(LC, Kode);

    if (C == NULL){
        cout << "Maskapai Tidak Tersedia" << endl;
        cout << " " << endl;
    }else {
        cout << "Nama Pesawat           : " << info(C).NamaPesawat << endl;
        cout << "Kode Penerbangan       : " << info(C).KodePenerbangan << endl;
        cout << "Asal Pesawat           : " << info(C).Asal << endl;
        cout << "Jumlah Penumpang       : " << info(C).JumlahPenumpang << endl;
        cout << " " << endl;
    }
}

void Pilihan_8(List_R &LR, List_P &LP, List_C &LC){
    string NamaBandara, KodePenerbangan;

    cout << "Masukan Parent Yang Akan Dihubungkan : ";
    cin >> NamaBandara;
    cout << "Masukan Child Yang Akan Dihubungkan  : ";
    cin >> KodePenerbangan;
    cout << " " << endl;

    address_Parent P = findPenerbangan_P(LP, NamaBandara);
    address_Child C = findMaskapai(LC, KodePenerbangan);

    if (P == NULL || C == NULL){
        cout << "Data Tidak Ditemukan" << endl;
        cout << " " << endl;
    }else {
        address_Relasi R = craeteELmtRelation(P, C);
        insertLastRelasi(LR, R);
        cout << "Data Telah Terhubung" << endl;
        cout << " " << endl;
    }

}

void Pilihan_9(List_R LR){

    address_Relasi R = first(LR);
    while (R != NULL){
        PrintRelasi(LR);
        R = next(R);
    }
}

void Pilihan_10(List_R LR){
    string NamaBandara;
    address_Relasi R;

    cout << "Masukan Nama Bandara : ";
    cin >> NamaBandara;
    bool x = false;
    R = first(LR);
    while (R != NULL){
        if (info(parent(R)).NamaBandara == NamaBandara){
            x = true;
            cout << "Maskapai           : " << info(child(R)).NamaPesawat << endl;
            cout << "Kode Penerbangan   : " << info(child(R)).KodePenerbangan << endl;
            cout << "Asal Pesawat       : " << info(child(R)).Asal << endl;
            cout << "Jumlah Penumpang   : " << info(child(R)).JumlahPenumpang << endl;
            cout << " " << endl;
        }
        R = next(R);
    }
    if (!x){
        cout << "Parent Tidak Memiliki Child" << endl;
        cout << " " << endl;
    }

}

void Pilihan_11(List_R &LR, List_C &LC){
    string NamaBandara;
    address_Relasi Q;


    cout << "Masukan Nama Bandara Yang Akan Dihapus Childnya : ";
    cin >> NamaBandara;
    address_Relasi R = first(LR);
    while (R != NULL){
        Q = next(R);
        if (info(parent(R)).NamaBandara == NamaBandara){
            deleteDataChild(LC, child(R));
            deleteElementRelasi(LR, R);
        }
        R = Q;
    }
    cout << "Semua data child pada parent berhasil dihapus" << endl;
    cout << " " << endl;
}

void Pilihan_12(List_R LR){
    string NamaBandara;
    int jumlah = 0;
    address_Relasi R;

    cout << "Masukan Nama Bandara : ";
    cin >> NamaBandara;

    R = first(LR);
    while (R != NULL){
        if (info(parent(R)).NamaBandara == NamaBandara){
            jumlah++;
            R = next(R);
        }
    }
    cout << "Jumlah Child Pada Parent : " << jumlah << endl;
    cout << " " << endl;
}
