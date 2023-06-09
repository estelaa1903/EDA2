#include <stdio.h>
#include "users.h"
#include "menu.h"

int main() {
    List_Users *lista = NULL;
    inicializarDiccionario();
    int option;
    printf("%c   %c  %c%c%c%c%c  %c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177);
    printf("%c   %c  %c   %c  %c   \n",177,177,177,177,177);
    printf("%c   %c  %c%c%c%c%c  %c%c%c%c   \n",177,177,177,177,177,177,177,177,177,177,177);
    printf("%c%c%c%c%c  %c      %c   \n",177,177,177,177,177,177,177);
    printf("\nBIENVENIDOS A UNICONNECT\n\n");
    printf("Esta red ha sido creada con fines academicos\n");
    printf("Haced publicaciones para informar a los demas estudiantes sobre\n");
    printf("fechas de examenes,informacion importante sobre el curso, hacer preguntas...\n");

    printf("\n             COMPARTID VUESTRA SABIDURIA!\n");
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
            printf("\nSaliste del programa");
        }
        else{
            printf("\nOpcion invalida");
        }
    } while (option!=6);
}
