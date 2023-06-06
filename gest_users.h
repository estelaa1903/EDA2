

#ifndef EDA2_GEST_USERS_H
#define EDA2_GEST_USERS_H

void insertarSolicitud(usuario* user, char nombre[MAX_USUARIO]);
void procesarSolicitud(usuario* user);
void mostrarAmistades(usuario* user);
void enviarSolicitud(List_Users* l, usuario* user);
#endif //EDA2_GEST_USERS_H

