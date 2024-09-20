/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   lista_enlasada.h
 * Author: alex
 *
 * Created on 15 de septiembre de 2024, 20:57
 */

#ifndef LISTA_ENLASADA_H
#define LISTA_ENLASADA_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
#include <stdio.h>

typedef struct Libro {
    char titulo[50];
    char autor[50];
}Libro;

typedef struct Nodo{
    Libro libro;
    struct Nodo* siguiente;
}Nodo;

typedef struct Lista{
    Nodo* cabeza;
    int longitud;
}Lista;

// crea un nodo que contendra un libro con sus valores, (titulo y autor)
Nodo* crear_nodo(Libro* libro);

// destruye o elimina un nodo creado
void destruir_nodo (Nodo* nodo);

//inserta un libro al principio de la lsita de libros
void insertar_principio(Lista* lista, Libro* libro);

// inserta un libro al final de la lista de libros
void Insertar_final(Lista* lista, Libro* libro);

// inserta un libro en la posicion que que quiera (n)
void insertar_n_posicion(int n, Lista* lista, Libro* libro);

//  devuelte el libro en la posicion N 
Libro* obtener_libro (int n, Lista* lista);

//cuenta cuantos elementos hay en la lista
int contar (Lista* lista);

//para saber si la lista esta vacia
int estara_vacia(Lista* lista);

//para eliminar el primer elemento de la lista
void eliminar_primero(Lista* lista);

//elimina el ultimo elemento de la lista
void eliminar_ultimo(Lista* lista);

//eliminar un elemento numero n de la lista
void eliminar_n_posicion(int n, Lista* lista);

#endif /* LISTA_ENLASADA_H */

