//
// Created by estel on 26/04/2023.
//
#include <stdio.h>
#include "menu.h"
#include "base.h"
#include "main.h"
int main() {
    List_Users *l;
    l->total_users=0;
    int op, opcion;
    do {
        show_menu();
        opcion= comprobarm();
        op=elegirm(opcion, l);






    }while(op!=1);
    return 0;
}

