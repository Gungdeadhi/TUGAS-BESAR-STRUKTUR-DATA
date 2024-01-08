#include "Child.h"

void createList_Child(List_C &LC){
    first(LC) = NULL;
}

address_Child createElmtChild(infotype_Child X){
    address_Child P = new ElmtList_Child;
    info(P) = X;
    next(P) = NULL;
    return P;
}

bool isEmptyP(List_C &LC){
    if (first(LC) == NULL){
        return true;
    }else {
        return false;
    }
}

void insertLast(List_C &LC, address_Child P){
    address_Child q;
    if (isEmptyP(LC)){
        first(LC) = P;
    }else{
        q = first(LC);
        while(next(q) != NULL){
            q = next(q);
        }
        next(q) = P;
    }
}

void deleteDataChild(List_C &LC, address_Child &P){

   address_Child Q = first(LC);
   if (first(LC) != NULL){
        if (next(first(LC)) == NULL && first(LC) == P){
            first(LC) = NULL;
        }else if (next(first(LC)) != NULL && first(LC) == P){
            first(LC) = next(P);
            next(P) = NULL;
        }else{
            while(next(Q)!= P){
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;
        }
    delete P;
   }

}

void ShowDataChild(List_C LC){
    address_Child P = first(LC);
    while (P != NULL){

        cout << "Nama Pesawat           : " << info(P).NamaPesawat << endl;
        cout << "Kode Penerbangan       : " << info(P).KodePenerbangan << endl;
        cout << "Asal                   : " << info(P).Asal << endl;
        cout << "Jumlah Penumpang       : " << info(P).JumlahPenumpang << endl;
        cout << " " << endl;
        P = next(P);
    }
}
address_Child findMaskapai(List_C &LC, string Kode){
    address_Child P = first(LC);
    while (P != NULL){
        if(info(P).KodePenerbangan == Kode){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

