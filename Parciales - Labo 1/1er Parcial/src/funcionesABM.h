/*
 * funcionesABM.h
 *
 *  Created on: 30 abr. 2022
 *      Author: DESKTOP
 */

#ifndef FUNCIONESABM_H_
#define FUNCIONESABM_H_


typedef struct{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct{
	int id;
	char titulo[51];
	eFecha fechaPublicacion;
	float importe;
	int estado;
	int idArtista;
	int idTipoArtista;
	int idDiscografica;
	int idPais;

}eAlbum;

typedef struct{
	int id;
	char nombre[51];

}eArtista;

typedef struct{
	int id;
	char descripcion[51];

}eTipoArtista;

typedef struct{
	int id;
	char descripcion[51];

}eDiscografica;

typedef struct{
	int id;
	char descripcion[51];

}ePais;

/**
 * @brief Setea el estado a LIBRE de todos los elementos de la lista
 * @param albumes Lista a la que se le inicializara sus estados
 * @param tamAlbum Tamaño de la lista albumes
 */
void inicializarAlbumes(eAlbum albumes[], int tamAlbum);

/**
 * @brief Hardcodea albumes en una lista de tipo eAlbum
 * @param albumes Lista a la que se le hara hardcodeo de datos
 * @param id Es el id único, generado automaticamente que se le asignara a cada elemento hardcodeado
 * @param cantidad Es la cantidad de elementos que se hardcodearan
 * @return Devuelve el id al main para que siga un orden autoincremental
 */
int hardcodearAlbumes(eAlbum albumes[], int id, int cantidad);
/**
 * @brief Hardcodea una lista del tipo eArtista
 * @param artistas Lista a la que se le hara hardcodeo de datos
 * @param cantidad Es la cantidad de elementos que se hardcodearan
 */
void hardcodearArtistas(eArtista artistas[], int cantidad);
/**
 * @brief Hardcodea una lista del tipo etipoArtista
 * @param tipoArtista Lista a la que se le hara hardcodeo de datos
 * @param cantidad Es la cantidad de elementos que se hardcodearan
 */
void hardcodearTipoDeArtistas(eTipoArtista tipoArtista[], int cantidad);
/**
 * @brief Hardcodea uuna lista del tipo eDiscografica
 * @param discografica Lista a la que se le hara hardcodeo de datos
 * @param cantidad Es la cantidad de elementos que se hardcodearan
 */
void hardcodearDiscograficas(eDiscografica discografica[], int cantidad);
/**
 * @param Hardcodea uuna lista del tipo ePais
 * @param paises Lista a la que se le hara hardcodeo de datos
 * @param cantidad Es la cantidad de elementos que se hardcodearan
 */
void hardcodearPaises(ePais paises[], int cantidad);
/**
 * @brief Menu que se maneja con valores enteros, que valida que la opcion ingresada este dentro del rango
 * @param opciones Es el mensaje que contiene todas las opciones del menu
 * @param minimo Es el minimo de opciones que tendrael menu
 * @param maximo Es el maximo de opciones que tendrael menu
 * @return Devuelve la opcion ingresada
 */
int menu(char opciones[], int minimo, int maximo);

/**
 * @brief Submenu que se maneja con caracteres, que valida que la opcion ingresada este dentro del rango
 * @param opciones Es ell mensaje que contiene todas las opciones del submenu
 * @param minimo Es el minimo de opciones que tendra el menu
 * @param maximo Es el minimo de opciones que tendrael menu
 * @return Devuelve el caracter de la opcion ingresada
 */
char subMenu(char opciones[], char minimo, char maximo);
/**
 * @brief Se encarga de todo el proceso de alta, dentro de ella se llama a buscarLibre() y a cargarTodosLosDatos()
 * @param albumes Lista que se usara para dar el alta
 * @param tamanio Tamaño de la lista albumes[]
 * @param id  Se le asigna automaticamente a cada elemento que se este por dar de alta
 * @param artistas Lista que se utilizara para pasar como parametros en funciones
 * @param tamArtistas Tamaño de la lista artistas[]
 * @param tipoArtistas Lista que se utilizara para pasar como parametros en funciones
 * @param tamTipo Tamaño de la lista tipoArtistas[]
 * @param discograficas Lista que se utilizara para pasar como parametros en funciones
 * @param tamDiscograficas Tamaño de la lista discograficas[]
 * @param paises Lista que se utilizara para pasar como parametros en funciones
 * @param tamPaises Tamaño de la lista paises[]
 * @return 0, si se pudo dar de alta. -1, si no hay lugar donde cargar los datos
 */
int alta(eAlbum albumes[], int tamanio, int id, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises);
/**
 * @brief Busca un espacio libre dentro de la lista albumes[]
 * @param albumes Lista a recorrer
 * @param tamanio Tamaño de la lista albumes[]
 * @return Devuelve la posicion del primer espacio libre encontradoindex. Devuelve -1 si la lista esta llena
 */
int buscarLibre(eAlbum albumes[], int tamanio);
/**
 * @brief Se encarga de todo el proceso de pedida de dato, llamando a las funciones correspondientes
 * @param id Generado automaticamente para asignar al elemento a cargar
 * @param artistas Lista que se pasara como parametro a la funciones listarArtistas();
 * @param tamArtistas Tamaño de la lista artistas[]
 * @param tipoArtistas Lista que se pasara como parametro a la funciones listarTipoDeArtistas();
 * @param tamTipo Tamaño de la lista tipoArtistas[]
 * @param discograficas Lista que se pasara como parametro a la funciones listarDiscograficas();
 * @param tamDiscograficas Tamaño de la lista discograficas[]
 * @param paises Lista que se pasara como parametro a la funciones listarPaises();
 * @param tamPaises Tamaño de la lista paises[]
 * @return Devuelve una estructura del tipo eAlbum completamente cargado
 */
eAlbum cargarTodosLosDatos(int id, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises);
/**
 * @brief Pide el ingreso de año, dia y mes. Y los valida
 * @return Devuelve una estructura del tipo eFecha
 */
eFecha pedirFecha(void);
/**
 * @brief Muestra la lista completa de los paises, mostrando sus ids y nombres, pidiendo el id de uno de ellos
 * @param paises Lista a imprimir
 * @param tamPaises Tamaño de la lista artistas[]
 * @return Devuelve el id del pais elegido
 */
int pedirPais(ePais paises[], int tamPaises);
/**
 * @brief Muestra la lista completa de los artistas, mostrando sus ids y nombres, pidiendo el id de uno de ellos
 * @param artistas Lista a imprimir
 * @param tamArtistas Tamaño de la lista artistas[]
 * @return Devuelve el id del artista elegido
 */
int pedirArtista(eArtista artistas[], int tamArtistas);
/**
 * @brief Muestra la lista completa de las discograficas, mostrando sus ids y descripciones, pidiendo el id de uno de ellos
 * @param discograficas Lista a imprimir
 * @param tamDiscograficas Tamaño de la lista discograficas[]
 * @return Devuelve el id de la discografica elegida
 */
int pedirDiscografica(eDiscografica discograficas[], int tamDiscograficas);
/**
 * @brief Muestra la lista completa de los tipo de artista, mostrando sus ids y descripciones, pidiendo el id de uno de ellos
 * @param tipoArtistas Lista a imprimir
 * @param tamTipo Tamaño de la lista tipoArtistas[]
 * @return Devuelve el id del tipo de artista elegido
 */
int pedirTipoDeArtista(eTipoArtista tipoArtistas[], int tamTipo);
/**
 * @brief Recorre una lista por su id buscando una igualdad con el id recibido como parametro
 * @param albumes Lista a recorrer
 * @param tamanio Tamaño de la lista albumes[]
 * @param id Se usara para buscar la igualdad
 * @return Devuelve su posicion si encontro al album con el ID ingresado. Devuelve -1 si no lo encontro
 */
int buscarAlbumPorId(eAlbum albumes[], int tamanio, int id);
/**
 * @brief Abre un submenu permitiendo modificar los siguientes atributos de una lista de tipo eAlbum: titulo o fecha de publicacion o importe
 * @param albumes Lista que se modificara dependiendo del seleccionado
 * @param tamanio Tamaño de la lista albumes[]
 * @param paises Lista que se pasara como parametro a la funcion pedirPais(), en caso de que se quiera modificar el pais
 * @param tamPaises Tamaño de la lista paises[]
 */
void modificar(eAlbum albumes[], int tamanio, ePais paises[], int tamPaises);
/**
 * @brief Pide el ingreso de un album por su ID. Si existe, hace una baja lógica únicamente cambiando su estado.
 * @param albumes Lista que contiene el elemento a dar de baja
 * @param tamanio Tamaño de la lista albumes[]
 */
void baja(eAlbum albumes[], int tamanio);
/**
 * @brief Abre un submenu con 2 opciones, y se encarga de llamar a las funciones correspondientes.
 * @param albumes Lista usada para calcular los informes correspondientes
 * @param tamanio Tamaño de la lista albumes[]
 */
void informar(eAlbum albumes[], int tamanio);
/**
 * @brief Calcula el total de todos los importes de la lista albumes[]
 * @param albumes Lista que se recorrera acumulando su importe
 * @param tamanio Tamaño de la lista albumes[]
 * @return Devuelve el total acumulado
 */
float totalImportes(eAlbum albumes[], int tamanio);
/**
 * @brief Calcula el promedio de importes, llamando a la funcion totalImportes() y el total lo divide por la cantidad de albumes ingresados
 * @param albumes Lista utilizada para calcular la cantidad de importes
 * @param tamanio Tamaño de la lista albumes[]
 * @return Devuelve el promedio calculado
 */
float promedioImportes(eAlbum albumes[], int tamanio);
/**
 * @brief Cuenta o muestra la lista de los albumes que no superan el promedio calculado por promedioImportes()
 * @param albumes Lista utilizada para hacer los calculos necesarios
 * @param tamanio Tamaño de la lista albumes[]
 * @param accion Si recibe 1, cuenta la cantidad de los albumes que no superan el promedio. Y si recibe 2 imprime el listado de los mismos
 * @return Devuelve la cantidad de albumes que no superan el promedio.
 */
int listarContarAlbumesMenorAlPromedioImportes(eAlbum albumes[], int tamanio, int accion);
/**
 * @brief Cuenta o muestra la lista de los albumes publicados luego del 31/12/1999
 * @param albumes Lista utilizada para hacer los calculos necesarios
 * @param tamanio Tamaño de la lista albumes[]
 * @param accion Si recibe 1, cuenta la cantidad de albumes publicados a partir del año 2000. Y si recibe 2 imprime el listado de los mismos
 * @return Devuelve la cantidad de albumes que se publicaron despues del 31/12/1999
 */
int listarContarAlbumesPublicadosDespuesAnio1999(eAlbum albumes[], int tamanio, int accion);
/**
 * @brief Lista los albumes de un artista determinado. Primero muestra la lista de los mismos y se pide el ingreso de uno de ellos
 * @param albumes Lista utilizada para
 * @param tamanio Tamaño de la lista albumes[]
 * @param artistas Lista utilizada para
 * @param tamArtistas Tamaño de la lista artistas[]
 */
void listarAlbumPorArtista(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas);
/**
 * @brief Imprime un submenu con las opciones de todos los diferentes listados, y llama a las funciones correspondientes
 * @param albumes Lista utilizada para el llamado de funciones
 * @param tamanio Tamaño de la lista albumes[]
 * @param artistas Lista utilizada para el llamado de funciones
 * @param tamArtistas Tamaño de la lista artistas[]
 * @param tipoArtistas Lista utilizada para el llamado de funciones
 * @param tamTipo Tamaño de la lista tipoArtistas[]
 * @param discograficas Lista utilizada para el llamado de funciones
 * @param tamDiscograficas Tamaño de la lista discograficas[]
 * @param paises Lista  utilizada para el llamado de funciones
 * @param tamPaises Tamaño de la lista paises[]
 */
void listar(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises);
/**
 * @brief Lista todos los atributos de un elemento de la entidad eAlbum
 * @param album Es la estructura de la que va imprimir cada uno de sus atributos
 */
void mostrarUnAlbum(eAlbum album);
/**
 * @brief Muestra un album con todos sus atributos correspondientes
 * @param album Album a mostrar
 * @param albumes Lista a recorrer para mostrar sus respectivos atributos
 * @param tamanio Tamaño de la lista albumes[]
 * @param artistas Lista a recorrer
 * @param tamArtistas Tamaño de la lista artistas[]
 * @param tipoArtistas Lista a recorrer para mostrar sus respectivos atributos
 * @param tamTipo Tamaño de la lista tipoArtista[]
 * @param discograficas Lista a recorrer para mostrar sus respectivos atributos
 * @param tamDiscograficas Tamaño de la lista adiscograficas[]
 * @param paises Lista a recorrer para mostrar sus respectivos atributos
 * @param tamPaises Tamaño de la lista paises[]
 */
void mostrarUnAlbumCompleto(eAlbum album, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises);

/**
 * @brief Mostrar la lista de todos los albumes ingresados con sus respectivos ids y atributos
 * @param albumes Lista a imprimir
 * @param tamanio Tamaño de la lista albumes[]
 * @param artistas Lista que se pasara como parametro a mostrarUnAlbumCompleto()
 * @param tamArtistas Tamaño de la lista artistas[]
 * @param tipoArtistas Lista que se pasara como parametro a mostrarUnAlbumCompleto()
 * @param tamTipo Tamaño de la lista tipoArtista[]
 * @param discograficas Lista que se pasara como parametro a mostrarUnAlbumCompleto()
 * @param tamDiscograficas Tamaño de la lista adiscograficas[]
 * @param paises Lista que se pasara como parametro a mostrarUnAlbumCompleto()
 * @param tamPaises Tamaño de la lista paises[]
 */
void listarAlbumes(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises);
/**
 * @brief Mostrar la lista de todos los paises con sus respectivos ids
 * @param paises Lista a imprimir
 * @param tamanio Tamaño de la lista paises[]
 */
void listarPaises(ePais paises[], int tamanio);
/**
 * @brief Mostrar la lista de los artistas con sus respectivos ids y nombre
 * @param artistas Lista a imprimir
 * @param tamanio Tamaño de la lista artistas[]
 */
void listarArtistas(eArtista artistas[], int tamanio);
/**
 * @brief Mostrar la lista de los tipos de artistas con sus respectivos ids y descripcion
 * @param tipoArtistas Lista a imprimir
 * @param tamanio Tamaño de la lista tipoArtistas[]
 */
void listarTipoDeArtistas(eTipoArtista tipoArtistas[], int tamanio);
/**
 * @brief Mostrar la lista de las discograficas con sus respectivos ids y descripcion
 * @param discograficas Lista a imprimir
 * @param tamanio Tamaño de la lista discograficas[]
 */
void listarDiscograficas(eDiscografica discograficas[], int tamanio);
/**
 * @brief Ordenar los albumes por importe (descendentemente), y como segundo critero, por importe (ascendentemente)
 * @param albumes Lista a ordenar
 * @param tamanio Tamaño de la lista albumes[]
 */
void ordenarAlbumes(eAlbum albumes[], int tamanio);
/**
 * @brief Mostrar lista de albumes por año
 * @param albumes Lista a recorrer
 * @param tamanio Tamaño de la lista albumes[]
 */
void listarAlbumesPorAnio(eAlbum albumes[], int tamanio);
/**
 * @brief Listar los albumes mas baratos (si hay mas de uno)
 * @param albumes Lista a recorrer
 * @param tamanio Tamaño de la lista albumes[]
 */
void listarAlbumesMasBaratos(eAlbum albumes[], int tamanio);
/**
 * @brief Arma un listado de todos los albumes que no sean argentinos
 * @param albumes Lista a recorrer buscando albumes que no sean de argentina
 * @param tamanio  Tamaño de la lista albumes[]
 * @param artistas Lista para pasar como parametro a la funcion mostrarUnAlbumConpleto()
 * @param tamArtistas Tamaño de la lista artistas[]
 * @param tipoArtistas Lista para pasar como parametro a la funcion mostrarUnAlbumConpleto()
 * @param tamTipo Tamaño de la lista tipoArtistas[]
 * @param discograficas Lista para pasar como parametro a la funcion mostrarUnAlbumConpleto()
 * @param tamDiscograficas Tamaño de la lista discograficas[]
 * @param paises Lista a recorrer
 * @param tamPaises Tamaño de la lista paises[]
 */
void listarAlbumesNoArgentina(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises);
/**
 * @brief Arma un listado de todos los albumes argentinos que su año de publicacion sea el ingresado
 * @param albumes Lista a recorrer buscando la igualdad con el año ingresado y que su pais sea argentina
 * @param tamanio Tamaño de la lista albumes[]
 * @param artistas Lista para pasar como parametro a la funcion mostrarUnAlbumConpleto()
 * @param tamArtistas Tamaño de la lista artistas[
 * @param tipoArtistas Lista para pasar como parametro a la funcion mostrarUnAlbumConpleto()
 * @param tamTipo Tamaño de la lista tipoArtistas[]
 * @param discograficas Lista para pasar como parametro a la funcion mostrarUnAlbumConpleto()
 * @param tamDiscograficas Tamaño de la lista discograficas[]
 * @param paises Lista a recorrer
 * @param tamPaises Tamaño de la lista paises[]
 */
void listarAlbumesArgentinosPorAnio(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises);

#endif /* FUNCIONESABM_H_ */
