#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct Data_Maskapai infotype_Child;
typedef struct ElmtList_Child *address_Child;

struct Data_Maskapai {
    string NamaPesawat, KodePenerbangan, Asal;
    int JumlahPenumpang;
};

struct ElmtList_Child{
    infotype_Child info;
    address_Child next;
};

struct List_C{
    address_Child first;
};

// create List for child
void createList_Child(List_C &LC);

// create List for element child
address_Child createElmtChild(infotype_Child X);

// check List NULL or not
bool isEmptyP(List_C &LC);

// insert list
void insertLast(List_C &LC, address_Child P);

// delete list
void deleteDataChild(List_C &LC, address_Child &P);

// show list
void ShowDataChild(List_C LC);

//find elemen list
address_Child findMaskapai(List_C &LC, string Kode);


#endif // CHILD_H_INCLUDED
