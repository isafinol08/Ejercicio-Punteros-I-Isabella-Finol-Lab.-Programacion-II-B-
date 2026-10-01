#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

int* crearArreglo(int tamanio) {

    if (tamanio <= 0) {
        cout << "Error: El tamaño del arreglo debe ser mayor que cero." << endl;
        return nullptr;
    }
    
    int* nuevoArreglo = new (nothrow) int[tamanio];
    
    if (nuevoArreglo == nullptr) {
        cout << "Error: No se pudo asignar memoria dinámicamente." << endl;
        return nullptr;
    }
    
    return nuevoArreglo;
}

void llenarArreglo(int* arreglo, int tamanio) {
    
    if (arreglo == nullptr) {
        cout << "Error: El arreglo es nulo." << endl;
        return;
    }
    
    cout << "Ingrese " << tamanio << " números enteros:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arreglo[i];
    }
}

void mostrarArreglo(int* arreglo, int tamanio) {
   
    if (arreglo == nullptr) {
        cout << "Error: El arreglo es nulo." << endl;
        return;
    }
    
    if (tamanio <= 0) {
        cout << "El arreglo está vacío." << endl;
        return;
    }
    
    cout << "\nElementos del arreglo: [ ";
    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
    }
    cout << "]" << endl;
}

int encontrarMayor(int* arreglo, int tamanio) {
    
    if (arreglo == nullptr || tamanio <= 0) {
        return 0;
    }
    
    int mayor = arreglo[0];
    
    for (int i = 1; i < tamanio; i++) {
        if (arreglo[i] > mayor) {
            mayor = arreglo[i];
        }
    }
    
    return mayor;
}

float calcularPromedio(int* arreglo, int tamanio) {
    if (arreglo == nullptr || tamanio <= 0) {
        return 0.0f;
    }
    
    float suma = 0.0f;
    for (int i = 0; i < tamanio; i++) {
        suma += arreglo[i];
    }
    
    
    return suma / tamanio;
}

void liberarArreglo(int*& arreglo) {
    
    if (arreglo != nullptr) {
        delete[] arreglo;  
        arreglo = nullptr; 
    }
}

void mostrarMenu() {
    cout << "\n=== GESTIÓN DE ARREGLOS DINÁMICOS ===" << endl;
    cout << "1. Crear y llenar arreglo" << endl;
    cout << "2. Mostrar arreglo" << endl;
    cout << "3. Encontrar número mayor" << endl;
    cout << "4. Calcular promedio" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    setlocale(LC_ALL, "spanish");
    
    int* arreglo = nullptr;
    int tamanio = 0;
    
    cout << "=== GESTIÓN DE ARREGLOS DINÁMICOS ===" << endl;
    cout << "Implementación completada correctamente." << endl;
    
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                if (arreglo != nullptr) {
                    liberarArreglo(arreglo);
                }

                cout << "Ingrese el tamaño del arreglo: ";
                cin >> tamanio;
                
                arreglo = crearArreglo(tamanio);
                if (arreglo != nullptr) {
                    llenarArreglo(arreglo, tamanio);
                    cout << "Arreglo creado y llenado correctamente." << endl;
                } else {
                    cout << "Error al crear el arreglo." << endl;
                    tamanio = 0; // Restablecer tamaño si falló
                }
                break;
            }
            
            case 2: {
                // Mostrar arreglo
                if (arreglo != nullptr) {
                    mostrarArreglo(arreglo, tamanio);
                } else {
                    cout << "No hay arreglo creado. Use la opción 1 primero." << endl;
                }
                break;
            }
            
            case 3: {
                // Encontrar número mayor
                if (arreglo != nullptr && tamanio > 0) {
                    int mayor = encontrarMayor(arreglo, tamanio);
                    cout << "El número mayor es: " << mayor << endl;
                } else {
                    cout << "No hay arreglo creado o está vacío." << endl;
                }
                break;
            }
            
            case 4: {
                // Calcular promedio
                if (arreglo != nullptr && tamanio > 0) {
                    float promedio = calcularPromedio(arreglo, tamanio);
                    cout << "El promedio es: " << fixed << setprecision(2) << promedio << endl;
                } else {
                    cout << "No hay arreglo creado o está vacío." << endl;
                }
                break;
            }
            
            case 5: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            
            default: {
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
            }
        }
    } while (opcion != 5);
    
    liberarArreglo(arreglo);
    
    cout << "Programa finalizado. Memoria liberada." << endl;
    return 0;
}