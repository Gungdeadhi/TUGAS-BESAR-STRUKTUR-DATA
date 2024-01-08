#include <iostream>
#include "Parent.h"
#include "Child.h"
#include "Relasi.h"
#include "Menu.h"

using namespace std;

List_P Penerbangan;
List_C Maskapai;
List_R Relasi;

int main(){

    address_Parent P;
    address_Child C;
    address_Relasi R;

    infotype_Parent infoP;


    createList_Parent(Penerbangan);
    createList_Child(Maskapai);
    createListRelasi(Relasi);
    int Pilihan_P = selectMenu();
    while (Pilihan_P != 0){
        switch(Pilihan_P){
        case 1:
            Pilihan_1(Penerbangan);
            break;
        case 2:
            Pilihan_2(Penerbangan);
            break;
        case 3:
            Pilihan_3(Relasi, Penerbangan);
            break;
        case 4:
            Pilihan_4(Penerbangan);
            break;
        case 5:
            Pilihan_5(Maskapai);
            break;
        case 6:
            Pilihan_6(Maskapai);
            break;
        case 7:
            Pilihan_7(Maskapai);
            break;
        case 8:
            Pilihan_8(Relasi, Penerbangan, Maskapai);
            break;
        case 9:
            Pilihan_9(Relasi);
            break;
        case 10:
            Pilihan_10(Relasi);
            break;
        case 11:
            Pilihan_11(Relasi, Maskapai);
            break;
        case 12:
            Pilihan_12(Relasi);
            break;
        }
        Pilihan_P = selectMenu();
    }

    return 0;
}
