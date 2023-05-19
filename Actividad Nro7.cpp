#include <iostream>
#include <string>
using namespace std;

class MaterialBibliografico 
{
    protected:
        string titulo;
        string autor;
        string editorial;
        int fechapublicacion;

    MaterialBibliografico(string titulo, string autor, string editorial, int fechapublicacion) 
        {
            this->titulo = titulo;
            this->autor = autor;
            this->editorial = editorial;
            this->fechapublicacion = fechapublicacion;
        }

        virtual void mostrarInformacion() const 
        {
            cout << "Título: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Editorial: " << editorial << endl;
            cout << "Fecha de Publicación: " << fechapublicacion << endl;
        }
};

//La clase Revista hereda públicamente de MaterialBibliografico, lo cual permite acceder 
//a los miembros protegidos de la clase base desde la clase derivada y también desde el exterior.
class Revista : public MaterialBibliografico {
public:
    Revista(const string& titulo, const string& autor, const string& editorial, int fechapublicacion)
        : MaterialBibliografico(titulo, autor, editorial, fechapublicacion) {}

    void mostrarInformacion() const override {
        cout << "Información de la Revista:" << endl;
        MaterialBibliografico::mostrarInformacion();
    }
};

//La clase Libro hereda protegida (protected) de MaterialBibliografico, lo cual permite que los 
//miembros protegidos de la clase base sean accesibles en la clase derivada, pero no desde el exterior.
class Libro : protected MaterialBibliografico {
public:
    Libro(const string& titulo, const string& autor, const string& editorial, int fechapublicacion)
        : MaterialBibliografico(titulo, autor, editorial, fechapublicacion) {}

    void mostrarInformacion() const override {
        cout << "Información del Libro:" << endl;
        MaterialBibliografico::mostrarInformacion();
    }
};


//La clase Tesis hereda de forma privada (private) de MaterialBibliografico, lo cual limita el acceso a los
//miembros protegidos de la clase base solo dentro de la clase derivada. Esto significa que los miembros protegidos 
//de MaterialBibliografico no serán accesibles desde el exterior ni desde otras clases derivadas.
class Tesis : private MaterialBibliografico {
public:
    Tesis(const string& titulo, const string& autor, const string& editorial, int fechapublicacion)
        : MaterialBibliografico(titulo, autor, editorial, fechapublicacion) {}

    void mostrarInformacion() const {
        cout << "Información de la Tesis:" << endl;
        MaterialBibliografico::mostrarInformacion();
    }
};

int main() {
    Revista revista("France Football Nro 3736", "Amaury Média", "Éditions Philippe Amaury", 2017);
    Libro libro("El imperio final", "Brandon Sanderson", "Tor Books", 2008);
    Tesis tesis("Breve historia de los videojuegos", "Simone Belli y Cristian López Raventós", "Athenea Digital", 2008);

    revista.mostrarInformacion();
    cout << endl;

    libro.mostrarInformacion();
    cout << endl;

    tesis.mostrarInformacion();
    cout << endl;

    return 0;
}


