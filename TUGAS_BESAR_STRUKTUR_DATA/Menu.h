#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "Parent.h"
#include "Child.h"
#include "Relasi.h"

using namespace std;

int selectMenu();
void Pilihan_1(List_P &LP);
void Pilihan_2(List_P LP);
void Pilihan_3(List_R &LR, List_P &LP);
void Pilihan_4(List_P LP);
void Pilihan_5(List_C &LC);
void Pilihan_6(List_C LC);
void Pilihan_7(List_C LC);
void Pilihan_8(List_R &LR, List_P &LP, List_C &LC);
void Pilihan_9(List_R LR);
void Pilihan_10(List_R LR);
void Pilihan_11(List_R &LR, List_C &LC);
void Pilihan_12(List_R LR);

#endif // MENU_H_INCLUDED
