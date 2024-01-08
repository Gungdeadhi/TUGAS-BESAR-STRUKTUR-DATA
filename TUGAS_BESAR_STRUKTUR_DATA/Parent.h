#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct Data_Penerbangan infotype_Parent;
typedef struct ElmtList_Parent *address_Parent;

struct Data_Penerbangan {
    string Hari, NamaBandara, DaerahBandara;
};

struct ElmtList_Parent{
    infotype_Parent info;
    address_Parent next;
};

struct List_P{
    address_Parent first;
};

// create List for parent
void createList_Parent(List_P &LP);

// create List for elemen parent
address_Parent createElmtParent(infotype_Parent X);

// check List NULL or not
bool isEmptyP(List_P &LP);

// insert list
void insertLast(List_P &LP, address_Parent P);

// delete list
void deleteDataParent(List_P &LP, address_Parent P);

// show list
void ShowDataParent(List_P LP);

//find elemen list
address_Parent findPenerbangan_P(List_P &LP, string NamaBandara);

#endif // PARENT_H_INCLUDED
