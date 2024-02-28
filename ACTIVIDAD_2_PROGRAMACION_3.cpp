#include <iostream>
#include <string>
#include <ctime> // Para generar números aleatorios
#include <iomanip> // Para setw
#include <algorithm> // Para transform
using namespace std;

// Definición de la estructura LIBRO
struct Libro {
	string titulo;
	string autor;
	string ISBN;
	int anioPublicacion;
	string genero;
	string estado;
	string editorial;
	string idioma;
	string ubicacion;
	string formato;
};

// Definición de la estructura USUARIO
struct Usuario {
	int userID;
	string nombre;
	string apellido;
	string email;
	string direccion;
};

// Definición de la estructura BIBLIOTECARIO
struct Bibliotecario {
	int empleadoID;
	string nombre;
	string apellido;
	string email;
	string telefono;
};

// Función para generar datos aleatorios
string generarDatoAleatorio(string lista[], int longitud) {
	return lista[rand() % longitud];
}

// Función para llenar una estructura Libro
void llenarLibro(Libro& libro, string listaTitulos[], string listaAutores[], string listaISBN[], string listaGeneros[], string listaEditoriales[]) {
	libro.titulo = generarDatoAleatorio(listaTitulos, 4); // Se ha aumentado el tamaño del arreglo de títulos
	libro.autor = generarDatoAleatorio(listaAutores, 3);
	libro.ISBN = generarDatoAleatorio(listaISBN, 5);
	libro.anioPublicacion = rand() % 50 + 1970;
	libro.genero = generarDatoAleatorio(listaGeneros, 3);
	libro.estado = "disponible";
	libro.editorial = generarDatoAleatorio(listaEditoriales, 3);
	libro.idioma = "Español";
	libro.ubicacion = "Estantería " + to_string(rand() % 10 + 1);
	libro.formato = "Impreso";
}

// Función para llenar una estructura Usuario
void llenarUsuario(Usuario& usuario, string listaNombres[], string listaApellidos[]) {
	usuario.userID = rand() % 5 + 1;
	usuario.nombre = generarDatoAleatorio(listaNombres, 3);
	usuario.apellido = generarDatoAleatorio(listaApellidos, 3);
	usuario.email = usuario.nombre + usuario.apellido + "@gmail.com";
	usuario.direccion = "Calle " + usuario.nombre + " " + usuario.apellido + ", Ciudad";
}

// Función para llenar una estructura Bibliotecario
void llenarBibliotecario(Bibliotecario& bibliotecario, string listaNombres[], string listaApellidos[]) {
	bibliotecario.empleadoID = rand() % 5 + 1;
	bibliotecario.nombre = generarDatoAleatorio(listaNombres, 3);
	bibliotecario.apellido = generarDatoAleatorio(listaApellidos, 3);
	bibliotecario.email = bibliotecario.nombre + bibliotecario.apellido + "@library.com";
	bibliotecario.telefono = "123-456-789";
}

// Función para imprimir una estructura Libro
void imprimir(const Libro& libro) {
	cout << "Título: " << libro.titulo << ", Autor: " << libro.autor << ", ISBN: " << libro.ISBN
		<< ", Año de Publicación: " << libro.anioPublicacion << ", Género: " << libro.genero
		<< ", Estado: " << libro.estado << ", Editorial: " << libro.editorial << endl;
	cout << "Idioma: " << libro.idioma << ", Ubicación: " << libro.ubicacion << ", Formato: " << libro.formato << endl;
}

// Función para imprimir una estructura Usuario
void imprimir(const Usuario& usuario) {
	cout << "ID: " << usuario.userID << ", Nombre: " << usuario.nombre << ", Apellido: " << usuario.apellido
		<< ", Email: " << usuario.email << ", Dirección: " << usuario.direccion << endl;
}

// Función para imprimir una estructura Bibliotecario
void imprimir(const Bibliotecario& bibliotecario) {
	cout << "ID: " << bibliotecario.empleadoID << ", Nombre: " << bibliotecario.nombre << ", Apellido: " << bibliotecario.apellido
		<< ", Email: " << bibliotecario.email << ", Teléfono: " << bibliotecario.telefono << endl;
}

// Funciones de búsqueda

// Función para buscar un libro por título y listar los resultados
void buscarPorNombre(const Libro libros[], int size, const string &titulo, int index = 0) {
	if (index < size) {
		string tituloLower = titulo;
		transform(tituloLower.begin(), tituloLower.end(), tituloLower.begin(), ::tolower); // Convertir a minúsculas
		string libroLower = libros[index].titulo;
		transform(libroLower.begin(), libroLower.end(), libroLower.begin(), ::tolower); // Convertir a minúsculas
		if (libroLower.find(tituloLower) != string::npos) {
			cout << "Libro encontrado:" << endl;
			imprimir(libros[index]);
		}
		buscarPorNombre(libros, size, titulo, index + 1);
	} else {
		cout << "No se encontraron libros con el título \"" << titulo << "\"." << endl;
	}
}

// Función para buscar un usuario por nombre y apellido y listar los resultados
void buscarPorNombreApellidoUsuario(const Usuario usuarios[], int size, const string &nombre, const string &apellido, int index = 0) {
	if (index < size) {
		string nombreCompleto = usuarios[index].nombre + " " + usuarios[index].apellido;
		transform(nombreCompleto.begin(), nombreCompleto.end(), nombreCompleto.begin(), ::tolower);
		string nombreApellidoLower = nombre + " " + apellido;
		transform(nombreApellidoLower.begin(), nombreApellidoLower.end(), nombreApellidoLower.begin(), ::tolower);
		if (nombreCompleto.find(nombreApellidoLower) != string::npos) {
			cout << "Usuario encontrado:" << endl;
			imprimir(usuarios[index]);
		}
		buscarPorNombreApellidoUsuario(usuarios, size, nombre, apellido, index + 1);
	} else {
		cout << "No se encontraron usuarios con el nombre o apellido \"" << nombre << " " << apellido << "\"." << endl;
	}
}

// Función para buscar un bibliotecario por nombre y apellido y listar los resultados
void buscarPorNombreApellidoBibliotecario(const Bibliotecario bibliotecarios[], int size, const string &nombre, const string &apellido, int index = 0) {
	if (index < size) {
		string nombreCompleto = bibliotecarios[index].nombre + " " + bibliotecarios[index].apellido;
		transform(nombreCompleto.begin(), nombreCompleto.end(), nombreCompleto.begin(), ::tolower);
		string nombreApellidoLower = nombre + " " + apellido;
		transform(nombreApellidoLower.begin(), nombreApellidoLower.end(), nombreApellidoLower.begin(), ::tolower);
		if (nombreCompleto.find(nombreApellidoLower) != string::npos) {
			cout << "Bibliotecario encontrado:" << endl;
			imprimir(bibliotecarios[index]);
		}
		buscarPorNombreApellidoBibliotecario(bibliotecarios, size, nombre, apellido, index + 1);
	} else {
		cout << "No se encontraron bibliotecarios con el nombre o apellido \"" << nombre << " " << apellido << "\"." << endl;
	}
}

// Función para mostrar el menú principal
void mostrarMenu() {
	cout << "\nMenú Principal:\n";
	cout << "1. Llenar datos\n";
	cout << "2. Mostrar listados\n";
	cout << "3. Realizar búsquedas\n";
	cout << "0. Salir\n";
}

// Función para mostrar el submenú de listados
void mostrarSubMenuListados() {
	cout << "\nSubmenú Listados:\n";
	cout << "A. Listar libros\n";
	cout << "B. Listar usuarios\n";
	cout << "C. Listar bibliotecarios\n";
	cout << "X. Volver al menú principal\n";
}

// Función para mostrar el submenú de búsquedas
void mostrarSubMenuBusquedas() {
	cout << "\nSubmenú Búsquedas:\n";
	cout << "A. Buscar libro por título\n";
	cout << "B. Buscar usuario por nombre y apellido\n";
	cout << "C. Buscar bibliotecario por nombre y apellido\n";
	cout << "X. Volver al menú principal\n";
}

// Función principal
int main() {
	// Inicializar la semilla para la generación de números aleatorios
	srand(time(0));
	
	// Número de libros, usuarios y bibliotecarios
	const int numLibros = 20;
	const int numUsuarios = 5; // Ajustado para coincidir con el llenado de datos
	const int numBibliotecarios = 5; // Ajustado para coincidir con el llenado de datos
	
	// Arreglos para almacenar libros, usuarios y bibliotecarios
	Libro libros[numLibros];
	Usuario usuarios[numUsuarios];
	Bibliotecario bibliotecarios[numBibliotecarios];
	
	// Listas de datos para generación aleatoria
	string listaTitulos[] = {"Aprende C++", "Python", "Buleavard","Cien años de soledad"};
	string listaAutores[] = {"Autor A", "Autor B", "Autor C","Autor D"};
	string listaISBN[] = {"1", "2", "3", "4", "5","6"};
	string listaGeneros[] = {"Ficción", "No ficción", "Fantasía","Romanticismo"};
	string listaEditoriales[] = {"Editorial A", "Editorial B", "Editorial C","Editorial D"};
	string listaNombres[] = {"Juan", "María", "Pedro","Marcos"};
	string listaApellidos[] = {"González", "Rodríguez", "López","Antelos"};
	
	// Variable para almacenar la opción del usuario
	int opcion;
	
	do {
		mostrarMenu();
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			// Llenado de datos
			for (int i = 0; i < 10; ++i) {
				llenarLibro(libros[i], listaTitulos, listaAutores, listaISBN, listaGeneros, listaEditoriales);
			}
			for (int i = 0; i < 5; ++i) { // Ajustado para coincidir con el llenado de datos
				llenarUsuario(usuarios[i], listaNombres, listaApellidos);
				llenarBibliotecario(bibliotecarios[i], listaNombres, listaApellidos);
			}
			cout << "Datos llenados correctamente." << endl;
			break;
		case 2: {
			char opcionListados;
			do {
				mostrarSubMenuListados();
				cout << "Ingrese su opción: ";
				cin >> opcionListados;
				
				switch (opcionListados) {
				case 'A':
					// Listado de libros
					cout << "Listado de libros:" << endl;
					for (int i = 0; i < 10; ++i) {
						imprimir(libros[i]);
					}
					break;
				case 'B':
					// Listado de usuarios
					cout << "Listado de usuarios:" << endl;
					for (int i = 0; i < 5; ++i) { // Ajustado para coincidir con el llenado de datos
						imprimir(usuarios[i]);
					}
					break;
				case 'C':
					// Listado de bibliotecarios
					cout << "Listado de bibliotecarios:" << endl;
					for (int i = 0; i < 5; ++i) { // Ajustado para coincidir con el llenado de datos
						imprimir(bibliotecarios[i]);
					}
					break;
				case 'X':
					cout << "Saliendo al menú principal." << endl;
					break;
				default:
					cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
					break;
				}
			} while (opcionListados != 'X');
			break;
		}
		case 3: {
			char opcionBusquedas;
			do {
				mostrarSubMenuBusquedas();
				cout << "Ingrese su opción: ";
				cin >> opcionBusquedas;
				
				switch (opcionBusquedas) {
				case 'A': {
					string titulo;
					cout << "Ingrese el título del libro a buscar: ";
					cin.ignore();
					getline(cin, titulo);
					buscarPorNombre(libros, 10, titulo); // Ajustado para coincidir con el llenado de datos
					break;
				}
				case 'B': {
					string nombre, apellido;
					cout << "Ingrese el nombre y apellido del usuario a buscar: ";
					cin >> nombre >> apellido;
					buscarPorNombreApellidoUsuario(usuarios, 5, nombre, apellido); // Ajustado para coincidir con el llenado de datos
					break;
				}
				case 'C': {
					string nombre, apellido;
					cout << "Ingrese el nombre y apellido del bibliotecario a buscar: ";
					cin >> nombre >> apellido;
					buscarPorNombreApellidoBibliotecario(bibliotecarios, 5, nombre, apellido); // Ajustado para coincidir con el llenado de datos
					break;
				}
				case 'X':
					cout << "Saliendo al menú principal." << endl;
					break;
				default:
					cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
					break;
				}
			} while (opcionBusquedas != 'X');
			break;
		}
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
			break;
		}
	} while (opcion != 0);
	
	return 0;
}
