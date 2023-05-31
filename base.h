//Header donde escribimos las bases

#ifndef EDA2_BASE_H
#define EDA2_BASE_H
#define MAX_LENGTH 50
#define MAX_USUARIO 15
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/*La función de new_usuario es la que guarda, según la estructura usuario, la información de un nuevo
 cliente, no devuelve nada. */

typedef struct {
    char pref1[MAX_LENGTH];
    char pref2[MAX_LENGTH];
    char pref3[MAX_LENGTH];
    char pref4[MAX_LENGTH];
    char pref5[MAX_LENGTH];
}gustos;

typedef struct {
    char nombre[MAX_USUARIO];
    int edad;
    char correo[MAX_LENGTH];
    char ubi[MAX_LENGTH];
    gustos pref;

}usuario;

typedef struct{
    usuario user;
    struct List_Users *next;
    int total_users;
}List_Users;
void new_usuario(List_Users **l);
void listar(List_Users *l);
List_Users* Create_list();
int lista(usuario);
usuario busqueda(List_Users *l,char nombre[MAX_USUARIO]);
usuario Select(List_Users *l,char nombre[MAX_USUARIO]);
void op_usuario(List_Users *l);

#endif //EDA2_BASE_H
