
#ifndef EDA_II_RED_SOCIAL_USERS_H
#define EDA_II_RED_SOCIAL_USERS_H
#define MAX_LENGTH 50
#define MAX_USUARIO 15
#define MAX_PUB 120
#define MAX_PALABRAS 120

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
typedef struct {
    char palabra[MAX_LENGTH];
    int conteo;
} EntradaDiccionario;

EntradaDiccionario diccionario[MAX_PUB];
int numPalabras = 0;

typedef struct {//Estructura de solicitudes de amistad
    char name_sol[MAX_USUARIO];
    struct Node* siguiente;
} Node;


typedef struct List_Users List_Users;
typedef struct usuario {
    char nombre[MAX_USUARIO];//nickname
    int edad;
    char correo[MAX_LENGTH];
    char ubi[MAX_LENGTH];//ciudad donde vive el usuario
    int num_pub; //numero de publicaciones realizadas por el usuario
    gustos pref;//sus 5 gustos
    Node* cola_solicitudes;  // Cola de solicitudes de amistad
    List_Users*amigos;//solicitudes aceptadas
    publicacion* publicaciones; //cola de publicaciones

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
void realizar_publicacion(usuario* user, const char* texto);
void mostrarHistorial(usuario* user);
void mostrarTop10Palabras();
void agregarPalabraDiccionario(char* palabra);
void inicializarDiccionario();
void insertarSolicitud(usuario* user, char nombre[MAX_USUARIO]);
void mostrarAmistades(usuario* user);
void enviarSolicitud(List_Users* l, usuario* user);
void procesarSolicitudesPendientes(usuario* user);
#endif //EDA_II_RED_SOCIAL_USERS_H
