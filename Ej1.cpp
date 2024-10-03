/*Un almacén necesita gestionar su inventario de productos. Cada producto tiene un número único de identificación (ID), y el sistema debe mantener el inventario organizado para realizar búsquedas rápidas de productos y permitir actualizaciones del stock.
Utilizar un árbol AVL para almacenar los IDs de los productos. El árbol debe mantenerse balanceado para garantizar búsquedas rápidas.
Crear un sistema con un menú que permita gestionar las siguientes opciones:
1.	Insertar un código de producto.
2.	Eliminar un código de producto.
3.	Buscar un producto por código.
4.	Imprimir el árbol (mostrando su estructura balanceada).
5.	Salir del programa. */
#include <iostream>
#include "Arbol/ArbolBinarioAVL.h"

using namespace std;

void menu() {
    cout << "\n--- Menu de Opciones ---\n";
    cout << "1. Insertar un codigo de producto\n";
    cout << "2. Eliminar un codigo de producto\n";
    cout << "3. Buscar un codigo de producto\n";
    cout << "4. Imprimir el arbol AVL\n";
    cout << "5. Salir\n";
    cout << "Selecciona una opcion: ";
}

int main() {
    ArbolBinarioAVL<int> arbolProductos;
    int opcion, codigo;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el codigo del producto a insertar: ";
                cin >> codigo;
                try {
                    arbolProductos.put(codigo);
                    cout << "Producto con codigo " << codigo << " insertado exitosamente.\n";
                } catch (int e) {
                    cout << "Error: el codigo ya existe o es invalido.\n";
                }
                break;
            case 2:
                cout << "Ingrese el codigo del producto a eliminar: ";
                cin >> codigo;
                try {
                    arbolProductos.remove(codigo);
                    cout << "Producto con codigo " << codigo << " eliminado exitosamente.\n";
                } catch (int e) {
                    cout << "Error: no se encontro el codigo a eliminar.\n";
                }
                break;
            case 3:
                cout << "Ingrese el codigo del producto a buscar: ";
                cin >> codigo;
                try {
                    arbolProductos.search(codigo);
                    cout << "Producto con codigo " << codigo << " encontrado.\n";
                } catch (int e) {
                    cout << "Error: producto no encontrado.\n";
                }
                break;
            case 4:
                cout << "Estructura del arbol AVL:\n";
                arbolProductos.print(); // Se muestra la estructura balanceada del árbol
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida, intenta nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
    }