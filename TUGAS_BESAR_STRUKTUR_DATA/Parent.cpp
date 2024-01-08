#include "Parent.h"

void createList_Parent(List_P &LP){
    first(LP) = NULL;
}

address_Parent createElmtParent(infotype_Parent X){
    address_Parent P = new ElmtList_Parent;
    info(P) = X;
    next(P) = NULL;
    return P;
}

bool isEmptyP(List_P &LP){
    if (first(LP) == NULL){
        return true;
    }else {
        return false;
    }
}

void insertLast(List_P &LP, address_Parent P){
    address_Parent q;
    if (isEmptyP(LP)){
        first(LP) = P;
    }else{
        q = first(LP);
        while(next(q) != NULL){
            q = next(q);
        }
        next(q) = P;
    }
}

void deleteDataParent(List_P &LP, address_Parent P){

    address_Parent Q = first(LP);
    if (first(LP) != NULL){
        if (next(first(LP)) == NULL && first(LP) == P){
            first(LP) = NULL;
        }else if (next(first(LP)) != NULL && first(LP) == P){
            first(LP) = next(P);
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

void ShowDataParent(List_P LP){
    address_Parent P = first(LP);
    while (P != NULL){
        cout << "Hari                   : " << info(P).Hari << endl;
        cout << "Bandara                : " << info(P).NamaBandara << endl;
        cout << "Daerah Bandara         : " << info(P).DaerahBandara << endl;
        cout << " " << endl;
        P = next(P);
    }
}

address_Parent findPenerbangan_P(List_P &LP, string NamaBandara){
    address_Parent P = first(LP);
    while (P != NULL){
        if(info(P).NamaBandara == NamaBandara){
            return P;
        }
        P = next(P);
    }
    return NULL;
}


