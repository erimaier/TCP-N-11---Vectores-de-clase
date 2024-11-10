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
    int edad;
    string estado;

    void actualizarEstado() {
        if (calcularPromedio() >= 6.0) {
            estado = "Aprobado";
        } else {
            estado = "Desaprobado";
        }
    }

public:
    Alumno(string nombre, double nota1, double nota2, double nota3, int edad)
        : nombre(nombre), nota1(nota1), nota2(nota2), nota3(nota3), edad(edad) {
        actualizarEstado(); 
    }

    string getNombre() const { return nombre; }
    double getNota1() const { return nota1; }
    double getNota2() const { return nota2; }
    double getNota3() const { return nota3; }
    int getEdad() const { return edad; }
    string getEstado() const { return estado; } 

    double calcularPromedio() const { return (nota1 + nota2 + nota3) / 3; }
};

int main() {
    vector<Alumno> alumnos;
    string nombre;
    double nota1, nota2, nota3;
    int edad;
    int numAlumnos;

    cout << "Ingrese el número de alumnos: ";
    cin >> numAlumnos;

    for (int i = 0; i < numAlumnos; i++) {
        cout << "Ingrese el nombre del alumno: ";
        cin >> nombre;
        cout << "Ingrese la edad del alumno: "; 
        cin >> edad;
        cout << "Ingrese la nota 1 del alumno: ";
        cin >> nota1;
        cout << "Ingrese la nota 2 del alumno: ";
        cin >> nota2;
        cout << "Ingrese la nota 3 del alumno: ";
        cin >> nota3;
        alumnos.push_back(Alumno(nombre, nota1, nota2, nota3, edad)); 
    }

    cout << "\nDatos de los alumnos:" << endl;

    for (size_t i = 0; i < alumnos.size(); i++) {
        const Alumno& alumno = alumnos[i]; 
        cout << "Nombre: " << alumno.getNombre() << endl;
        cout << "Edad: " << alumno.getEdad() << endl; 
        cout << "Nota 1: " << alumno.getNota1() << endl;
        cout << "Nota 2: " << alumno.getNota2() << endl;
        cout << "Nota 3: " << alumno.getNota3() << endl;
        cout << "Promedio: " << alumno.calcularPromedio() << endl;
        cout << "Estado: " << alumno.getEstado() << endl; 
        cout << endl;
    }

    return 0;
}
