//
// Created by estel on 26/04/2023.
//
#include <stdio.h>
#include "menu.h"
#include "main.h"
int main() {
    List_Users l;
    l.numusers=0;
   int op, opcion;
    do {
        show_menu();
        opcion= comprobarm();
        if (op!=4){
            op=elegirm(opcion);

        }
    }while(op!=1);
}


