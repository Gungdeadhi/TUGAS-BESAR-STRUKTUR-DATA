#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "Parent.h"
#include "child.h"
#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define parent(P) P->parent
#define child(P) P->child

using namespace std;

typedef struct elmt_relation *address_Relasi;

struct elmt_relation{
    address_Parent parent;
    address_Child child;
    address_Relasi next;
    address_Relasi prev;
};

struct List_R{
    address_Relasi first;
    address_Relasi last;
};

//create list relation
void createListRelasi(List_R &LR);
address_Relasi craeteELmtRelation(address_Parent P, address_Child C);

//insert list relation
void insertLastRelasi(List_R &LR, address_Relasi P);

//delete list relation
void deleteFirstRelasi(List_R LR, address_Relasi R);
void deleteAfterRelasi(List_R &LR, address_Relasi &Prec, address_Relasi &R);
void deleteLastRelasi(List_R &LR, address_Relasi R);
void deleteElementRelasi(List_R &LR, address_Relasi R);

//find relation
address_Relasi findElementRelation(List_R LR, address_Parent P, address_Child C);

//print relation
void PrintRelasi(List_R LR);

#endif // RELASI_H_INCLUDED
