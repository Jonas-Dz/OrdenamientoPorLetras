#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

const int maxNombres = 5;
const int maxLongitud = 30;

void separar(const char* nombre, int* ascii, int& longitud) {
    longitud = strlen(nombre);
    for (int i = 0; i < longitud; ++i) {
        ascii[i] = nombre[i];
    }
}

void burbuja(int* arreglo, int longitud) {
    for (int i = 0; i < longitud - 1; ++i) {
        for (int j = 0; j < longitud - i - 1; ++j) {
            if (*(arreglo + j) > *(arreglo + j + 1)) {
                int temp = *(arreglo + j);
                *(arreglo + j) = *(arreglo + j + 1);
                *(arreglo + j + 1) = temp;
            }
        }
    }
}

void transcribir(int* arreglo, char* nombre, int longitud) {
    for (int i = 0; i < longitud; ++i) {
        nombre[i] = static_cast<char>(arreglo[i]);
    }
    nombre[longitud] = '\0';
}

int main() {
    char** nombres = new char*[maxNombres];
    for (int i = 0; i < maxNombres; ++i) {
        nombres[i] = new char[maxLongitud];
    }

    cout << "Ingrese " << maxNombres << " nombres:\n";
    for (int i = 0; i < maxNombres; ++i) {
        cout << "Nombre " << i + 1 << ": ";
        cin.getline(nombres[i], maxLongitud);
    }

    for (int i = 0; i < maxNombres; ++i) {
        int longitud = 0;
        int* ascii = new int[strlen(nombres[i])];

        separar(nombres[i], ascii, longitud);
        burbuja(ascii, longitud);
        transcribir(ascii, nombres[i], longitud);

        delete[] ascii;
    }

    cout << "\nNombres ordenados por letras (ASCII):\n";
    for (int i = 0; i < maxNombres; ++i) {
        cout << nombres[i] << endl;
    }

    for (int i = 0; i < maxNombres; ++i) {
        delete[] nombres[i];
    }
    delete[] nombres;

    return 0;
}
