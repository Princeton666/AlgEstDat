#include <iostream>
#include <cstdlib>

class CVector {
private:
    int* m_pVect;   // Puntero al buffer
    int m_nCount;   // Cantidad de elementos actualmente usados
    int m_nMax;     // Cantidad máxima de elementos permitidos
    int m_nDelta;   // Incremento para el crecimiento del vector

    void Init(int delta);   // Inicializar las variables privadas
    void Resize();          // Redimensionar el vector cuando ocurre un desbordamiento

public:
    // Constructor
    CVector(int delta = 10);

    // Destructor
    ~CVector();

    void Insert(int elem);

    // Método para imprimir el contenido del vector
    void Print() const;

    // Sobrecarga del operador []
    int& operator[](int index);

    // Otros métodos pueden ser añadidos aquí
};

// Implementación de los métodos de la clase CVector

CVector::CVector(int delta) {
    Init(delta);
}

CVector::~CVector() {
    free(m_pVect);
}

void CVector::Init(int delta) {
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = delta;
    m_pVect = (int*)malloc(sizeof(int) * m_nMax);
}

void CVector::Resize() {
    m_pVect = (int*)realloc(m_pVect, sizeof(int) * (m_nMax + m_nDelta));
    m_nMax += m_nDelta;
}

void CVector::Insert(int elem) {
    if (m_nCount == m_nMax) {
        Resize();
    }
    m_pVect[m_nCount++] = elem;
}

void CVector::Print() const {
    for (int i = 0; i < m_nCount; i++) {
        std::cout << m_pVect[i] << " ";
    }
    std::cout << std::endl;
}

// Sobrecarga del operador []
int& CVector::operator[](int index) {
    if (index < 0 || index >= m_nCount) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_pVect[index];
}

int main() {
    CVector myVector(5); 

    
    for (int i = 0; i < 15; i++) {
        myVector.Insert(i);
    }


    for (int i = 0; i < 15; i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
