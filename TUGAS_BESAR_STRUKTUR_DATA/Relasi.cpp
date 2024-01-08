#include "Relasi.h"


void createListRelasi(List_R &LR){
    first(LR) = NULL;
    last(LR) = NULL;
}

address_Relasi craeteELmtRelation(address_Parent P, address_Child C){
    address_Relasi R = new elmt_relation;

    parent(R) = P;
    child(R) = C;
    next(R) = NULL;
    prev(R) = NULL;

    return R;
}

void insertLastRelasi(List_R &LR, address_Relasi P){
    if (first(LR) == NULL && last(LR) == NULL ){
        first(LR) = P;
        last(LR) = P;
    }else {
        next(last(LR)) = P;
        prev(P) = last(LR);
        last(LR) = P;
    }
}

void deleteFirstRelasi(List_R LR, address_Relasi R){
    if (first(LR) == last(LR)){
        first(LR) = NULL;
        last(LR) = NULL;
    }else{
        first(LR) = next(R);
        next(R) = NULL;
        prev(first(LR)) = NULL;
    }
}

void deleteAfterRelasi(List_R &LR, address_Relasi &Prec, address_Relasi &R){
    R = next(Prec);
    next(Prec) = next(R);
    prev(next(R)) = Prec;
    prev(R) = NULL;
    next(R) = NULL;
}

void deleteLastRelasi(List_R &LR, address_Relasi R){
        R = last(LR);
        last(LR) = prev(last(LR));
        prev(R) = NULL;
        next(last(LR)) = NULL;
}

void deleteElementRelasi(List_R &LR, address_Relasi R){

    address_Relasi Prec = prev(R);
    if (prev(R) == NULL && next(R) == NULL){
        first(LR) = NULL;
        last(LR) = NULL;
        delete R;
    }else if (prev(R) == NULL && next(R) != NULL){
        deleteFirstRelasi(LR, R);
    }else if (prev(R) != NULL && next(R) == NULL){
        deleteLastRelasi(LR, R);
    }else {
        deleteAfterRelasi(LR, Prec, R);
    }

}

address_Relasi findElementRelation(List_R LR, address_Parent P, address_Child C){

    address_Relasi R = first(LR);
    while (R != NULL){
        if (info(P).NamaBandara == info(C).KodePenerbangan) {
            return R;
        }
        R = next(R);
    }
    return NULL;
}

void PrintRelasi(List_R LR){
    address_Relasi R;
    R = first(LR);
    cout << "LIST RELASI" << endl;
    while (R != NULL){
        cout << "Parent" << endl;
        cout << "------" << endl;
        cout << "Hari        : " << info(parent(R)).Hari << endl;
        cout << "Bandara     : " << info(parent(R)).NamaBandara << endl;
        cout << "Daerah      : " << info(parent(R)).DaerahBandara << endl;
        cout << " " << endl;
        cout << "Child" << endl;
        cout << "------" << endl;
        cout << "Maskapai           : " << info(child(R)).NamaPesawat << endl;
        cout << "Kode Penerbangan   : " << info(child(R)).KodePenerbangan << endl;
        cout << "Asal Pesawat       : " << info(child(R)).Asal << endl;
        cout << "Jumlah Penumpang   : " << info(child(R)).JumlahPenumpang << endl;
        R = next(R);
    }
}

