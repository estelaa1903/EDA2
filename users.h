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
}gustos;

typedef struct{//estructura de una publicacion, en este caso escrita
    char pub[MAX_PUB];
    struct publicaciones *siguiente;
}publicaciones;

typedef struct{//solicitudes
    char n_solicitud[MAX_USUARIO];
}solicitudes;

typedef struct {//estructura de usuario
    char nombre[MAX_USUARIO];
    int edad;
    char correo[MAX_LENGTH];
    char ubi[MAX_LENGTH];
    gustos pref;
    publicaciones TimeLine;
    solicitudes ListPeticiones;
    //solicitudes aceptadas
}usuario;

typedef struct{ //Lista de usuarios
    usuario user;
    struct List_Users *next;
    int total_users;
}List_Users;


void new_usuario(List_Users **l);
void listar(List_Users *l );
void op_usuario(List_Users *l);
usuario* busqueda(List_Users *l,char nombre[MAX_USUARIO]);
void leer_file(List_Users **l);
#endif //EDA_II_RED_SOCIAL_USERS_H
