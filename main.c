//
// Created by estel on 26/04/2023.
//
#include <stdio.h>
#include "menu.h"
#include "base.h"
#include "main.h"
int main() {
    List_Users *li ;
    li=NULL;
    usuario u;
    li->total_users=0;
    int op=0, opcion;
    do {

        new_lista(u,li);
        show_menu();
        opcion= comprobarm();
        op=elegirm(opcion, li);






    }while(op!=1);
    return 0;
}

