#include <stdio.h>
#include "users.h"
#include "menu.h"

int main() {
    List_Users *lista = NULL;
    int option;
    do {
        show_menu();
        printf("Selecciona una opcion:");
        scanf("%d", &option);
        if(option==1){//Insertar nuevo usuario
            new_usuario(&lista);
        }
        else if(option==2){//Mostrar en pantalla los usuarios registrados
            //leer_file();
        }
        else if(option==3){// Operar como usuario
            listar(lista);
        }
        else if(option==4){
            op_usuario(lista);
        }
        /*else if(option==5){//salir, borra la memoria dinamica assignada y cualquier cosa abierta
            salir
        }");
        else{
            printf("Opcion invalida)
        }*/
    } while (option!=5);
}
