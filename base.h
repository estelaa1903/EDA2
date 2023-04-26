//
// Created by estel on 26/04/2023.
//

#ifndef EDA2_BASE_H
#define EDA2_BASE_H
#define MAX_LENGTH 50
#define MAX_USUARIO 15
typedef struct {
    char pref1[MAX_LENGTH];
    char pref2[MAX_LENGTH];
    char pref3[MAX_LENGTH];
    char pref4[MAX_LENGTH];
    char pref5[MAX_LENGTH];
}gustos;

typedef struct{
    char nombre[MAX_USUARIO];
    int edad;
    char correo[MAX_LENGTH];
    char ubi[MAX_LENGTH];
    gustos pref;
}usuarios;

typedef struct{
    usuarios users;
    struct List_Users *next;
    struct List_Users *prev;
}List_Users;

#endif //EDA2_BASE_H
