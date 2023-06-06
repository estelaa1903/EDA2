
#ifndef EDA_II_RED_SOCIAL_USERS_H
#define EDA_II_RED_SOCIAL_USERS_H
#define MAX_LENGTH 50
#define MAX_USUARIO 15
#define MAX_PUB 120

typedef struct { //estructura que define las preferencias de un usuario
    char pref1[MAX_LENGTH];
    char pref2[MAX_LENGTH];
    char pref3[MAX_LENGTH];
    char pref4[MAX_LENGTH];
    char pref5[MAX_LENGTH];
} gustos;

typedef struct publicacion {
    char pub[MAX_PUB];
    struct publicacion* siguiente;
} publicacion;


typedef struct {//Estructura de solicitudes de amistad
    char name_sol[MAX_USUARIO];
    struct Node* siguiente;
} Node;


typedef struct List_Users List_Users;
typedef struct usuario {
    char nombre[MAX_USUARIO];
    int edad;
    char correo[MAX_LENGTH];
    char ubi[MAX_LENGTH];
    gustos pref;
    //solicitudes aceptadas
    Node* cola_solicitudes;  // Cola de solicitudes de amistad
    List_Users*amigos;


} usuario;


typedef struct List_Users { //Lista de usuarios
    usuario user;
    struct List_Users* next;
    int total_users;
} List_Users;

void new_usuario(List_Users** l);
void listar(List_Users* l);
void op_usuario(List_Users* l);
usuario* busqueda(List_Users* l, char nombre[MAX_USUARIO]);
void leer_file(List_Users** l);
void liberar_memoria(List_Users *l);
#endif //EDA_II_RED_SOCIAL_USERS_H
