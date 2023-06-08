#include <stdio.h>
#include "users.h"
#include "menu.h"

int main() {
    List_Users *lista = NULL;
    inicializarDiccionario();
    int option;
    do {
        show_menu();
        printf("Selecciona una opcion:");
        scanf("%d", &option);
        if(option==1){//Insertar nuevo usuario
            new_usuario(&lista);
        }
        else if(option==2){//insertar usuarios por fichero
            leer_file(&lista);
        }
        else if(option==3){//listar usuarios
            listar(lista);
        }
        else if(option==4){//operar usuario
            op_usuario(lista);
        }
        else if(option==5){//muestra el top10 de palabras mas usadas en las publicaciones.
            mostrarTop10Palabras();
        }
        else if(option==6) {//salir, borra la memoria dinamica assignada y cualquier cosa abierta.
            liberar_memoria(lista);
            printf("Saliste del programa");
        }
        else{
            printf("\nOpcion invalida");
        }
    } while (option!=6);
}
