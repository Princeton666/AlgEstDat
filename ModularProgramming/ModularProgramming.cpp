#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Vector
struct Vector {
    int* m_pVect;   // Puntero al buffer
    int  m_nCount;  // Cantidad de elementos actualmente usados
    int  m_nMax;    // Cantidad máxima de elementos permitidos
    int  m_nDelta;  // Incremento para el crecimiento del vector
};

void Resize(Vector* pThis);


void Insert(Vector* pThis, int elem) {
    if (pThis->m_nCount == pThis->m_nMax)
        Resize(pThis);
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Resize(Vector* pThis) {
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (static_cast<unsigned long long>(pThis->m_nMax) + pThis->m_nDelta));

    // Incrementar el tamaño máximo permitido
    pThis->m_nMax += pThis->m_nDelta;
}

int main() {
    // Inicialización del vector
    Vector myVector;
    myVector.m_nCount = 0;
    myVector.m_nMax = 10;
    myVector.m_nDelta = 5;
    myVector.m_pVect = (int*)malloc(sizeof(int) * myVector.m_nMax);

    // Insertar elementos en el vector
    for (int i = 0; i < 15; i++) {
        Insert(&myVector, i);
    }

    // Imprimir los elementos del vector
    for (int i = 0; i < myVector.m_nCount; i++) {
        printf("%d ", myVector.m_pVect[i]);
    }

    // Liberar la memoria asignada
    free(myVector.m_pVect);

    return 0;
}
