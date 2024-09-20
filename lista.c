#include"lista_enlasada.h"
#include<stdlib.h>
#include<string.h>

// crea un nodo que contendra un libro con sus valores, (titulo y autor)
Nodo* crear_nodo(Libro* libro){
    Nodo* nodo = (nodo*) malloc(sizeof(nodo));
    strncpy(nodo->libro.titulo, libro->titulo, 50);
    strncpy(nodo->libro.autor, libro->autor, 50);
    nodo->siguiente = NULL; // apunta a NULL ya que de esta manera no habra punteros sueltos
    
    return nodo;
    
}
// destruye o elimina un nodo creado
void destruir_nodo (Nodo* nodo){
    free(nodo);
}

//inserta un libro al principio de la lsita de libros
void insertar_principio(Lista* lista, Libro* libro){
    Nodo* nodo = crear_nodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

// inserta un libro al final de la lista de libros
void Insertar_final(Lista* lista, Libro* libro){
    Nodo* nodo = crear_nodo(libro);
    if (lista->cabeza ==NULL){
        lista->cabeza = nodo;
    } else {
        Nodo* puntero = lista->cabeza;
        while(puntero->siguiente){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

// inserta un libro en la posicion que que quiera (n)
void insertar_n_posicion(int n, Lista* lista, Libro* libro){
    Nodo* nodo = crear_nodo(libro);
    if (lista->cabeza == NULL){
        lista->cabeza = nodo;
    }else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        //                 && puntero->siguiente valida que haya elementos y si no los hay se sale en la posicion que este
        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
    lista->longitud++;
    
}

//  devuelte el libro en la posicion N 
Libro* obtener_libro (int n, Lista* lista){
    if (lista->cabeza == NULL){
        printf("No hay nada");
        //return NULL;
    }else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        //                 && puntero->siguiente valida que haya elementos y si no los hay se sale en la posicion que este
        while(posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }
        if (posicion != n){
            return NULL;
        }else {
            return &puntero->libro;
        }
    }
} 
    
//cuenta cuantos elementos hay en la lista
int contar (Lista* lista){
    return lista->longitud;
}

//para saber si la lista esta vacia
int estara_vacia(Lista* lista){
    return lista->cabeza == NULL;
}

//para eliminar el primer elemento de la lista
void eliminar_primero(Lista* lista){
    if (lista->cabeza){
        Nodo* eliminado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        destruir_nodo (eliminado);
        lista->longitud--;
    }
}

//elimina el ultimo elemento de la lista
void eliminar_ultimo(Lista* lista){
    if (lista->cabeza){
        if (lista->cabeza->siguiente){
            Nodo* puntero = lista->cabeza;
             while(puntero->siguiente->siguiente){
                puntero= puntero->siguiente;
            }
            Nodo* eliminar = puntero->siguiente;
            puntero->siguiente = NULL;
            destruir_nodo(eliminar);
            lista->longitud--;
        }else{
            Nodo* eliminar = lista->cabeza;
            lista->cabeza = NULL
            destruir_nodo(eliminar);
            lista->longitud--;
        }
    }
}

//eliminar un elemento numero n de la lista
void eliminar_n_posicion(int n, Lista* lista){
    if (lista->cabeza){
        if (n == 0){
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            destruir_nodo (eliminado);
            lista->longitud--;
        }else if (n < lista->longitud){
            Nodo* puntero = lista->cabeza;
            int posicion=0;
                while(posicion < (n-1)){
                    puntero = puntero->siguiente;
                    posicion++;
                }      
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            destruir_nodo(eliminado);
            lista->longitud--;
        }
    }
}
