#include "pila.h"
#include "testing.h"
#include <stdio.h>


static void prueba_pila_vacia(void) {
    printf("INICIO DE PRUEBAS PILA VACIA\n");

    /* Declaro las variables a utilizar*/
    pila_t *pila = pila_crear();

    /* Inicio de pruebas */
    print_test("crear pila", pila != NULL);
    print_test("la pila esta vacia", pila_esta_vacia(pila));

    /* Pruebo ver el tope de una pila vacia */
    print_test("ver tope de una pila vacia es NULL", pila_ver_tope(pila) == NULL);

    /* Pruebo desapilar de una pila vacia */
    print_test("desapilar un pila vacia es NULL", pila_desapilar(pila) == NULL);

    /* Destruyo la pila*/
    pila_destruir(pila);
    print_test("la pila fue destruida", true);
}

static void prueba_apilar_desapilar(void) {
    printf("INICIO DE PRUEBAS DE APILAR Y DESAPILAR\n");
    
    pila_t *pila2 = pila_crear();
    print_test("crear pila", pila2 != NULL);
    
    /* Declaro las variables a utilizar*/
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    int n5 = 5;
    int *valor1 = &n1;
    int *valor2 = &n2;
    int *valor3 = &n3;
    int *valor4 = &n4;
    int *valor5 = &n5;
    
    /* Pruebo apilar*/
    print_test("se apilo el elemento 1", pila_apilar(pila2, valor1));
    
    /* Pruebo que el elemento apilado es el nuevo tope */
    print_test("el tope es el elemento 1", (pila_ver_tope(pila2) == valor1));
    
    print_test("se apilo el elemento 2", pila_apilar(pila2, valor2));
    print_test("el tope es el elemento 2", pila_ver_tope(pila2) == valor2);
    
    print_test("se apilo el elemento 3", pila_apilar(pila2, valor3));
    print_test("el tope es el elemento 3", pila_ver_tope(pila2) == valor3);
    
    print_test("se apilo el elemento 4", pila_apilar(pila2, valor4));
    print_test("el tope es el elemento 4", pila_ver_tope(pila2) == valor4);
    
    print_test("se apilo el elemento 5", pila_apilar(pila2, valor5));
    print_test("el tope es el elemento 5", pila_ver_tope(pila2) == valor5);
    
    /* Pruebo desapilar */
    print_test("se desapilo el elemento 5", pila_desapilar(pila2) == valor5);
    
    /* Pruebo que el siguiente elemento es el nuevo tope */
    print_test("el tope es el elemento 4", pila_ver_tope(pila2) == valor4);
    
    print_test("se desapilo el elemento 4", pila_desapilar(pila2) == valor4);
    print_test("el tope es el elemento 3", pila_ver_tope(pila2) == valor3);
    
    print_test("se desapilo el elemento 3", pila_desapilar(pila2) == valor3);
    print_test("el tope es el elemento 2", pila_ver_tope(pila2) == valor2);
    
    print_test("se desapilo el elemento 2", pila_desapilar(pila2) == valor2);
    print_test("el tope es el elemento 1", pila_ver_tope(pila2) == valor1);
    
    print_test("se desapilo el elemento 1", pila_desapilar(pila2) == valor1);
    
    /* Pruebo que la pila este vacia */
    print_test("la pila esta vacia", pila_esta_vacia(pila2));
    
    /* Pruebo ver el tope de la pila vacia */
    print_test("ver tope de una pila vacia es NULL", pila_ver_tope(pila2) == NULL);
    
    /* Pruebo desapilar de la pila vacia */
    print_test("desapilar un pila vacia es NULL", pila_desapilar(pila2) == NULL);
    
    /* Destruyo la pila*/
    pila_destruir(pila2);
    print_test("la pila fue destruida", true);
}

static void prueba_elemento_NULL(void) {
    printf("INICIO DE PRUEBAS ELEMENTO NULL\n");
    
    pila_t *pila3 = pila_crear();
    print_test("crear pila", pila3 != NULL);
    
    /* Pruebo apilar NULL */
    print_test("se apilo el elemento NULL", pila_apilar(pila3, NULL));
    
    /* Pruebo que la pila NO este vacia */
    print_test("la pila NO esta vacia", !pila_esta_vacia(pila3));
    
    /* Pruebo desapilar NULL */
    print_test("desapilo NULL", pila_desapilar(pila3) == NULL);
    
    /* Pruebo que la pila este vacia */
    print_test("la pila esta vacia", pila_esta_vacia(pila3));
    
    /* Destruyo la pila*/
    pila_destruir(pila3);
    print_test("la pila fue destruida", true);
}

static void prueba_pila_volumen(void) {
    printf("INICIO DE PRUEBAS DE VOLUMEN\n");
    
    pila_t *pila4 = pila_crear();
    print_test("crear pila", pila4 != NULL);
    
    /* Declaro las variables a utilizar*/
    bool ok = true;
    bool ok2 = true;
    bool ok3 = true;
    int valores[500];
    for (int i = 0; i<500; i++) {
        valores[i] = i;
    }
    
    /* Pruebo que se pueden apilar muchos elementos */
    for (int i = 0; i<500; i++) {
        ok &= pila_apilar(pila4, &valores[i]);
        ok2 &= pila_ver_tope(pila4) == &valores[i];
    }
    
    print_test("se pudieron apilar todos los elementos", ok);
    print_test("todos los topes fueron correctos", ok2);
    
    /* Pruebo que se pueden desapilar muchos elementos */
    for (int i = 499; i>=0; i--) {
        ok3 = pila_desapilar(pila4) == &valores[i];
    }
    
    print_test("se pudieron desapilar todos los elementos", pila_esta_vacia(pila4));
    print_test("todos los topes fueron correctos", ok3);
    
    /* Destruyo la pila*/
    pila_destruir(pila4);
    print_test("la pila fue destruida", true);  
}

void pruebas_pila_estudiante() {
    prueba_pila_vacia();
    prueba_apilar_desapilar();
    prueba_elemento_NULL();
    prueba_pila_volumen();
}



#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_pila_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
