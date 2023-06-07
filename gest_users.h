

#ifndef EDA2_GEST_USERS_H
#define EDA2_GEST_USERS_H

void insertarSolicitud(usuario* user, char nombre[MAX_USUARIO]);
void mostrarAmistades(usuario* user);
void enviarSolicitud(List_Users* l, usuario* user);
void procesarSolicitudesPendientes(usuario* user);
#endif //EDA2_GEST_USERS_H

