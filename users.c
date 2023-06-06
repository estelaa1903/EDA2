#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"
#include "menu.h"
#include "gest_users.h"

int encontrado;

void new_usuario(List_Users** l) {
    usuario user;
    char usu[MAX_USUARIO], larg[MAX_LENGTH];
    printf("\n-Cual es su nombre de usuario? (MAX. 15)");
    scanf("%s", usu);
    strcpy(user.nombre, usu);

    printf("\n-Cual es su edad?");
    scanf("%d", &user.edad);

    printf("\n-Cual es su correo electronico? (MAX. 50)");
    scanf("%s", larg);
    strcpy(user.correo, larg);

    printf("\n-Cual es su Ciudad?(MAX. 50)");
    scanf("%s", larg);
    strcpy(user.ubi, larg);

    printf("\nListe 5 preferencias:");
    printf("\nNum. 1:");
    scanf("%s", larg);
    strcpy(user.pref.pref1, larg);

    printf("\nNum. 2:");
    scanf("%s", larg);
    strcpy(user.pref.pref2, larg);

    printf("\nNum. 3:");
    scanf("%s", larg);
    strcpy(user.pref.pref3, larg);

    printf("\nNum. 4:");
    scanf("%s", larg);
    strcpy(user.pref.pref4, larg);

    printf("\nNum. 5:");
    scanf("%s", larg);
    strcpy(user.pref.pref5, larg);

    List_Users* new_list = malloc(sizeof(List_Users));
    new_list->user = user;
    new_list->next = NULL;
    new_list->user.amigos= NULL;
    new_list->user.cola_solicitudes= NULL;
    if (*l == NULL) {
        *l = new_list;
    } else {
        List_Users* current = *l;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_list;
    }
    (*l)->total_users++;
}

void listar(List_Users* l) {
    if (l == NULL) {
        printf("No hay usuarios para listar\n");
        return;
    } else {
        List_Users* current = l;
        while (current != NULL) {
            printf("%s\n", current->user.nombre);
            current = current->next;
        }
    }
}

void op_usuario(List_Users* l) {
    char nombre_usuario[MAX_USUARIO];
    usuario* select_user;
    printf("Ingresa el nombre del usuario:  ");
    scanf("%s", nombre_usuario);
    select_user = busqueda(l, nombre_usuario);
    if (encontrado == 1) {
        printf("Has iniciado sesion como %s\n", select_user->nombre);
        int option1;
        do {
            show_submenu();
            printf("Selecciona una opcion:");
            scanf("%d", &option1);
            if (option1 == 1) { //enviar solicitud
                enviarSolicitud(l, select_user);

            }
            if (option1 == 2) { //gestionar solicitudes
                procesarSolicitudesPendientes(select_user);
            }
            if (option1 == 3) { //realizar publicacion.

            }
            if (option1 == 4) { //Mostrar amigos
                mostrarAmistades(select_user);
            }
        } while (option1 != 5);
    } else {
        printf("Usuario no encontrado\n");
    }
}

usuario* busqueda(List_Users* l, char nombre[MAX_USUARIO]) {
    List_Users* current = l;
    encontrado = 0;
    while (current != NULL) {
        if (strcmp(nombre, current->user.nombre) == 0) {
            encontrado = 1;
            return &(current->user);
        }
        current = current->next;
    }
    return NULL;
}

void leer_file(List_Users** l) {
    FILE* file;
    usuario user;
    file = fopen("file_users.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %d %s %s %s %s %s %s %s", user.nombre, &user.edad, user.correo, user.ubi, user.pref.pref1, user.pref.pref2, user.pref.pref3, user.pref.pref4, user.pref.pref5) == 9) {
            List_Users* new_list = malloc(sizeof(List_Users));
            new_list->user = user;
            new_list->next = NULL;
            new_list->user.amigos= NULL;
            new_list->user.cola_solicitudes= NULL;

            if (*l == NULL) {
                *l = new_list;
            }
            else {
                List_Users* current = *l;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = new_list;
            }
            (*l)->total_users++;
        }
        printf("Usuarios registrados con exito\n");
        fclose(file);
    }
    else {
        perror("Error al abrir el archivo");
    }
}

void liberar_memoria(List_Users *l) {
    List_Users *current = l;
    List_Users *temp;
    while (current != NULL) {
        temp = current;
        current = (List_Users *)current->next;
        free(temp);
    }
}
// Función para insertar una solicitud en la cola
void insertarSolicitud(usuario* user, char nombre[MAX_USUARIO]) {
    Node* newNode = malloc(sizeof(Node)); // Crea un nuevo nodo con la solicitud
    strcpy(newNode->name_sol, nombre); // Guarda el nombre del usuario que envió la solicitud

    if (user->cola_solicitudes == NULL) { // Si la cola está vacía
        user->cola_solicitudes = newNode; // El nuevo nodo se convierte en el frente de la cola
    } else {
        Node* temp = user->cola_solicitudes; // Puntero temporal para recorrer la cola
        while (temp->siguiente != NULL) { // Recorre la cola hasta el último nodo
            temp = temp->siguiente;
        }
        temp->siguiente = newNode; // Agrega el nuevo nodo al final de la cola
    }
}

// Función para mostrar las amistades aceptadas
void mostrarAmistades(usuario* user) {
    if (user->amigos == NULL) { // Si la lista de amigos está vacía
        printf("No tienes amistades aceptadas.\n");
    } else {
        List_Users* temp = user->amigos; // Puntero temporal para recorrer la lista de amigos
        printf("Tus amistades aceptadas son:\n");
        while (temp != NULL) { // Recorre la lista hasta el final
            printf("- %s\n", temp->user.nombre); // Imprime el nombre del amigo
            temp = temp->next; // Avanza al siguiente nodo
        }
    }
}
void enviarSolicitud(List_Users* l, usuario* user) {
    char nombre[MAX_USUARIO];
    usuario* req_user;
    printf("Ingresa el nombre del usuario al que deseas enviar la solicitud: ");
    scanf("%s", nombre);
    req_user = busqueda(l, nombre);
    if (encontrado == 1) {
        // Inserta aquí la lógica para enviar la solicitud de amistad
        insertarSolicitud(req_user, user->nombre);
        printf("Solicitud enviada a %s\n", req_user->nombre);
    } else {
        printf("El usuario no fue encontrado\n");
    }
}
int aceptarSolicitud(usuario* user, char nombre[MAX_USUARIO]) {
    // Buscar la solicitud en la cola de solicitudes pendientes
    Node* temp = user->cola_solicitudes;
    Node* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name_sol, nombre) == 0) {
            // Mostrar la solicitud al usuario y solicitar su decisión
            printf("Has recibido una solicitud de amistad de %s\n", nombre);
            printf("¿Deseas aceptarla? (s/n): ");
            char decision;
            scanf(" %c", &decision);

            if (decision == 's' || decision == 'S') {
                // Aceptar la solicitud y agregar al usuario a la lista de amigos
                if (user->amigos == NULL) {
                    user->amigos = malloc(sizeof(List_Users));
                    strcpy(user->amigos->user.nombre, nombre);
                    user->amigos->next = NULL;
                } else {
                    List_Users* amigoTemp = user->amigos;
                    while (amigoTemp->next != NULL) {
                        if (strcmp(amigoTemp->user.nombre, nombre) == 0) {
                            printf("Ya eres amigo de %s.\n", nombre);
                            return 0;
                        }
                        amigoTemp = amigoTemp->next;
                    }

                    if (strcmp(amigoTemp->user.nombre, nombre) == 0) {
                        printf("Ya eres amigo de %s.\n", nombre);
                        return 0;
                    }

                    List_Users* nuevoAmigo = malloc(sizeof(List_Users));
                    strcpy(nuevoAmigo->user.nombre, nombre);
                    nuevoAmigo->next = NULL;
                    amigoTemp->next = nuevoAmigo;
                }

                // Eliminar la solicitud de la cola de solicitudes pendientes
                if (prev == NULL) {
                    user->cola_solicitudes = temp->siguiente;
                } else {
                    prev->siguiente = temp->siguiente;
                }

                free(temp);
                return 1; // Solicitud aceptada correctamente
            } else {
                // Rechazar la solicitud
                printf("Has rechazado la solicitud de amistad de %s\n", nombre);

                // Eliminar la solicitud de la cola de solicitudes pendientes
                if (prev == NULL) {
                    user->cola_solicitudes = temp->siguiente;
                } else {
                    prev->siguiente = temp->siguiente;
                }

                free(temp);
                return 0; // Solicitud rechazada
            }
        }

        prev = temp;
        temp = temp->siguiente;
    }

    // La solicitud no fue encontrada en la cola de solicitudes pendientes
    printf("No se encontró ninguna solicitud de amistad de %s\n", nombre);
    return 0; // Solicitud no encontrada
}


void procesarSolicitudesPendientes(usuario* user) {
    if (user->cola_solicitudes == NULL) { // Si no hay solicitudes pendientes
        printf("No tienes solicitudes pendientes.\n");
        return;
    }

    Node* temp = user->cola_solicitudes;
    int opcion;

    printf("Tienes solicitudes pendientes:\n");
    int index = 1;
    while (temp != NULL) {
        printf("%d. Usuario: %s\n", index, temp->name_sol);
        temp = temp->siguiente;
        index++;
    }

    printf("Seleccione el número de solicitud que desea procesar (0 para cancelar): ");
    scanf("%d", &opcion);

    if (opcion == 0) {
        return;
    }

    if (opcion < 1 || opcion > index - 1) {
        printf("Opción inválida. Por favor, seleccione un número válido.\n");
        return;
    }

    temp = user->cola_solicitudes;
    Node* prev = NULL;
    int count = 1;

    while (count != opcion) {
        prev = temp;
        temp = temp->siguiente;
        count++;
    }

    if (prev == NULL) { // Si la solicitud a procesar es la primera de la cola
        user->cola_solicitudes = temp->siguiente; // Actualiza el frente de la cola
    } else {
        prev->siguiente = temp->siguiente; // Salta el nodo de la solicitud a procesar
    }

    // Agrega el usuario a la lista de amigos si la solicitud es aceptada
    if (aceptarSolicitud(user, temp->name_sol)==1) {
        printf("Solicitud aceptada. Ahora eres amigo de %s.\n", temp->name_sol);
    } else {
        printf("Solicitud rechazada.\n");
    }

    free(temp); // Libera la memoria del nodo de solicitud procesado
}

