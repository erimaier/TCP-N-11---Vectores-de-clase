#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno {
private:
    string nombre;
    double nota1;
    double nota2;
    double nota3;
    int edad; // Nuevo atributo para la edad
    string estado; // Atributo para el estado (aprobado/desaprobado)

    // Método privado para actualizar el estado basado en el promedio
    void actualizarEstado() {
        if (calcularPromedio() >= 7.0) { // Cambiamos a 7.0 como la nota mínima para aprobar
            estado = "Aprobado";
        } else {
            estado = "Desaprobado";
        }
    }

public:
    // Constructor modificado
    Alumno(string nombre, double nota1, double nota2, double nota3, int edad)
        : nombre(nombre), nota1(nota1), nota2(nota2), nota3(nota3), edad(edad) {
        actualizarEstado(); // Actualiza el estado al crear el alumno
    }

    // Getters
    string getNombre() const { return nombre; }
    double getNota1() const { return nota1; }
    double getNota2() const { return nota2; }
    double getNota3() const { return nota3; }
    int getEdad() const { return edad; } // Getter para la edad
    string getEstado() const { return estado; } // Getter para el estado

    // Método para calcular el promedio
    double calcularPromedio() const { return (nota1 + nota2 + nota3) / 3; }
};

int main() {
    // Vector para almacenar los alumnos
    vector<Alumno> alumnos;
    // Ingresar datos de los alumnos y agregarlos al vector
    string nombre;
    double nota1, nota2, nota3;
    int edad;
    int numAlumnos;

    cout << "Ingrese el número de alumnos: ";
    cin >> numAlumnos;

    for (int i = 0; i < numAlumnos; i++) {
        cout << "Ingrese el nombre del alumno: ";
        cin >> nombre;
        cout << "Ingrese la edad del alumno: "; // Solicitar edad
        cin >> edad;
        cout << "Ingrese la nota 1 del alumno: ";
        cin >> nota1;
        cout << "Ingrese la nota 2 del alumno: ";
        cin >> nota2;
        cout << "Ingrese la nota 3 del alumno: ";
        cin >> nota3;
        alumnos.push_back(Alumno(nombre, nota1, nota2, nota3, edad)); // Pasar edad al constructor
    }

    // Mostrar los datos de los alumnos y sus promedios
    cout << "\nDatos de los alumnos:" << endl;
    // Usar un bucle tradicional para evitar problemas de compilación en C++98
    for (size_t i = 0; i < alumnos.size(); i++) {
        const Alumno& alumno = alumnos[i]; // Referencia constante para evitar copias
        cout << "Nombre: " << alumno.getNombre() << endl;
        cout << "Edad: " << alumno.getEdad() << endl; // Mostrar edad
        cout << "Nota 1: " << alumno.getNota1() << endl;
        cout << "Nota 2: " << alumno.getNota2() << endl;
        cout << "Nota 3: " << alumno.getNota3() << endl;
        cout << "Promedio: " << alumno.calcularPromedio() << endl;
        cout << "Estado: " << alumno.getEstado() << endl; // Mostrar estado
        cout << endl;
    }

    return 0;
}
