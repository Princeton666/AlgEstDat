#include <vector> // Sin .h
#include <list>
#include <iostream>
using namespace std;

// Función plantilla que imprime los elementos de cualquier contenedor
template <typename Container>
void Write(Container& ds, ostream& os) {
    typename Container::iterator iter = ds.begin(); // Tipo de iterador dependiente del contenedor
    for (; iter != ds.end(); ++iter) {
        os << *iter << "\n";
    }
}

int main() {
    list<float> mylist;
    vector<float> myvector;

    // Añadir elementos a la lista y al vector
    for (int i = 0; i < 10; ++i) {
        mylist.push_back(i);
        myvector.push_back(i + 50);
    }

    // Imprimir elementos de la lista y del vector
    Write(mylist, cout);
    Write(myvector, cout);

    return 0;
}
