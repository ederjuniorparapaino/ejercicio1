#include <iostream>
#include <string>
#include <ctime> // Para generar números aleatorios
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

// Función recursiva para buscar libros por nombre e imprimir la cantidad de libros con el mismo nombre
void buscarPorNombre(const Libro libros[], int cantidadLibros, const string& nombre, int indiceActual = 0, int cantidadEncontrados = 0) {
	// Caso base: si el índice actual es igual o mayor que la cantidad de libros, se imprime la cantidad de libros encontrados
	if (indiceActual >= cantidadLibros) {
		cout << "Cantidad de libros encontrados con el título '" << nombre << "': " << cantidadEncontrados << endl;
		return;
	}
	
	// Si el nombre del libro en el índice actual coincide con el nombre buscado, se incrementa el contador de libros encontrados
	if (libros[indiceActual].titulo == nombre) {
		cantidadEncontrados++;
	}
	
	// Llamada recursiva para buscar en el siguiente libro (incrementando el índice actual)
	buscarPorNombre(libros, cantidadLibros, nombre, indiceActual + 1, cantidadEncontrados);
}

// Función recursiva para buscar usuarios por nombre y apellido e imprimir la cantidad de usuarios con el mismo nombre o apellido
void buscarPorNombreApellido(const Usuario usuarios[], int cantidadUsuarios, const string& nombre, const string& apellido, int indiceActual = 0, int cantidadEncontrados = 0) {
	// Caso base: si el índice actual es igual o mayor que la cantidad de usuarios, se imprime la cantidad de usuarios encontrados
	if (indiceActual >= cantidadUsuarios) {
		cout << "Cantidad de usuarios encontrados con el nombre '" << nombre << "' o el apellido '" << apellido << "': " << cantidadEncontrados << endl;
		return;
	}
	
	// Si el nombre o el apellido del usuario en el índice actual coincide con el nombre o apellido buscado, se incrementa el contador de usuarios encontrados
	if (usuarios[indiceActual].nombre == nombre || usuarios[indiceActual].apellido == apellido) {
		cantidadEncontrados++;
	}
	
	// Llamada recursiva para buscar en el siguiente usuario (incrementando el índice actual)
	buscarPorNombreApellido(usuarios, cantidadUsuarios, nombre, apellido, indiceActual + 1, cantidadEncontrados);
}

// Función para mostrar el menú principal
void mostrarMenu() {
	cout << "----- Menú -----" << endl;
	cout << "1. Llenado de datos" << endl;
	cout << "2. Listados" << endl;
	cout << "3. Búsquedas" << endl;
	cout << "0. Salir" << endl;
	cout << "----------------" << endl;
}

// Función para mostrar el submenú de Listados
void mostrarSubMenuListados() {
	cout << "----- Submenú Listados -----" << endl;
	cout << "A. Listados de libros" << endl;
	cout << "B. Listados de usuarios" << endl;
	cout << "C. Listados de bibliotecarios" << endl;
	cout << "X. Salir" << endl;
	cout << "----------------" << endl;
}

// Función para mostrar el submenú de Búsquedas
void mostrarSubMenuBusquedas() {
	cout << "----- Submenú Búsquedas -----" << endl;
	cout << "A. Búsqueda de libros (título)" << endl;
	cout << "B. Búsqueda de usuarios (nombre y apellido)" << endl;
	cout << "C. Búsqueda de bibliotecarios (nombre y apellido)" << endl;
	cout << "X. Salir" << endl;
	cout << "----------------" << endl;
}

int main() {
	// Semilla para la generación de números aleatorios
	srand(time(0));
	
	// Arrays fijos de referencia
	string listaTitulos[] = {"Aprende C++", "Python", "Buleavard","Cien años de soledad"};
	string listaAutores[] = {"Autor A", "Autor B", "Autor C","Autor D"};
	string listaISBN[] = {"1", "2", "3", "4", "5","6"};
	string listaGeneros[] = {"Ficción", "No ficción", "Fantasía","Romanticismo"};
	string listaEditoriales[] = {"Editorial A", "Editorial B", "Editorial C","Editorial D"};
	string listaNombres[] = {"Juan", "María", "Pedro","Marcos"};
	string listaApellidos[] = {"González", "Rodríguez", "López","Antelos"};
	
	// Arrays para almacenar datos generados aleatoriamente
	Libro libros[10];
	Usuario usuarios[5];
	Bibliotecario bibliotecarios[5];
	
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
			for (int i = 0; i < 5; ++i) {
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
					for (int i = 0; i < 5; ++i) {
						imprimir(usuarios[i]);
					}
					break;
				case 'C':
					// Listado de bibliotecarios
					cout << "Listado de bibliotecarios:" << endl;
					for (int i = 0; i < 5; ++i) {
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
					buscarPorNombre(libros, 10, titulo);
					break;
				}
				case 'B': {
					string nombre, apellido;
					cout << "Ingrese el nombre y apellido del usuario a buscar: ";
					cin >> nombre >> apellido;
					buscarPorNombreApellido(usuarios, 5, nombre, apellido);
					break;
				}
				case 'C': {
					string nombre, apellido;
					cout << "Ingrese el nombre y apellido del bibliotecario a buscar: ";
					cin >> nombre >> apellido;
					buscarPorNombreApellido(usuarios, 5, nombre, apellido);
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
