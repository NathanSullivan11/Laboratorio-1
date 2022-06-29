/*
 * funcionesABM.c
 *
 *  Created on: 30 abr. 2022
 *      Author: DESKTOP
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesABM.h"
#include "ingreso_de_datos.h"
#include "validaciones.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJADO -1

void inicializarAlbumes(eAlbum albumes[], int tamanio){

	int i;
	for(i = 0;i < tamanio; i++)
	{
		albumes[i].estado = LIBRE;
	}

}

int hardcodearAlbumes(eAlbum albumes[], int id, int cantidad){

	int i;
	char titulo[][51] = {"Piano Bar", "El salmón", "Circo Beat", "Siempre es hoy"};
	int dia[] = {22 , 24, 20, 26};
	int mes[] = {9, 10, 02, 11};
	int anio[] = {1984, 2000, 1994, 2002};
	float importe[] = {1500, 999.99, 1799.99, 600};
	int idArtista[] = {2, 4, 1, 3};
	int idTipoArtista[] = {1, 2, 2, 1};
	int idDiscografica[] = {3, 1, 2, 2};
	int idPais[] = {2, 1, 3, 5};

	for(i = 0; i < cantidad; i++)
	{
		albumes[i].id = id;
		id++;
		albumes[i].estado = OCUPADO;
		strcpy(albumes[i].titulo, titulo[i]);
		albumes[i].fechaPublicacion.anio = anio[i];
		albumes[i].fechaPublicacion.dia = dia[i];
		albumes[i].fechaPublicacion.mes = mes[i];
		albumes[i].importe = importe[i];
		albumes[i].idArtista = idArtista[i];
		albumes[i].idTipoArtista = idTipoArtista[i];
		albumes[i].idDiscografica = idDiscografica[i];
		albumes[i].idPais = idPais[i];
	}

	return id;
}
void hardcodearPaises(ePais paises[], int cantidad){

	int i;
	char nombresPaises[][51] = {"China", "Argentina" ,"Brasil", "Chile", "EEUU"};

	for(i = 0; i < cantidad; i++)
	{
		paises[i].id = i+1;
		strcpy(paises[i].descripcion, nombresPaises[i]);
	}
}

void hardcodearArtistas(eArtista artistas[], int cantidad){
	int i;
	char nombreArtista[][51] = {"Fito Páez", "Charly Garcia" ,"Gustavo Cerati", "Andrés Calamaro"};
	for(i = 0; i < cantidad; i++)
	{
		artistas[i].id = i+1;
		strcpy(artistas[i].nombre,nombreArtista[i]);
	}
}
void hardcodearTipoDeArtistas(eTipoArtista tipoArtista[], int cantidad){
	int i;
	char descripcionTipo[][51] = {"Solista", "Banda"};
	for(i = 0; i < cantidad; i++)
	{
		tipoArtista[i].id = i+1;
		strcpy(tipoArtista[i].descripcion, descripcionTipo[i]);

	}
}
void hardcodearDiscograficas(eDiscografica discografica[], int cantidad){
	int i;
	char descripcionDiscografica[][51] = {"Excalibur", "Label Record", "Retromix"};
	for(i = 0; i < cantidad; i++)
	{
		discografica[i].id = i+1;
		strcpy(discografica[i].descripcion, descripcionDiscografica[i]);

	}
}


int menu(char opciones[], int minimo, int maximo){

	int opcion, opcionValidada;

	printf(opciones);

	opcion = get_Entero("\nOpción: ");
	opcionValidada = validarEnterosMaxMin("Opción INEXISTENTE (1 - 6): ", opcion, minimo, maximo);

	return opcionValidada;
}

char subMenu(char opciones[], char minimo, char maximo){

	char opcion;

	printf(opciones);

	opcion = get_Char("\nOpción: ");
	opcion = validarCharMaxMin("Ingrese: ", opcion, minimo, maximo);

	return opcion;
}

int buscarLibre(eAlbum albumes[], int tamanio){
	int retorno = -1;
	int i;

	for(i = 0; i < tamanio; i++)
	{
		if(albumes[i].estado == LIBRE)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

int buscarAlbumPorId(eAlbum albumes[], int tamanio, int id){

	int retorno = -1;
	int i;

	if(albumes != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			if(albumes[i].id == id && albumes[i].estado == OCUPADO)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}

int alta(eAlbum albumes[], int tamanio, int id, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscografica, ePais paises[], int tamPaises){
	int retorno = -1;
	int index;

	index = buscarLibre(albumes, tamanio);
	if(index != -1)
	{
		retorno = 0;
		albumes[index] = cargarTodosLosDatos(id, artistas, tamArtistas, tipoArtistas, tamTipo, discograficas, tamDiscografica, paises, tamPaises);
	}

	return retorno;
}

eAlbum cargarTodosLosDatos(int id, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises){

	eAlbum aux;
	aux.id = id;
	aux.estado = OCUPADO;
	get_String("Título del album: ",aux.titulo);
	validarString("Título (50 caracteres max):", aux.titulo, 51);
	aux.fechaPublicacion = pedirFecha();
	aux.importe = get_FlotantePositivo("Importe: ", "El importe no puede ser negativo");
	aux.idArtista = pedirArtista(artistas, tamArtistas);
	aux.idTipoArtista = pedirTipoDeArtista(tipoArtistas, tamTipo);
	aux.idDiscografica = pedirDiscografica(discograficas, tamDiscograficas);
	aux.idPais = pedirPais(paises, tamPaises);
	return aux;
}

eFecha pedirFecha(void){

	eFecha auxFecha;
	int dia, mes, anio;
	anio = get_Entero("Año de publicación: ");
	auxFecha.anio = validarEnterosMaxMin("Año (1900 - 2022): ", anio, 1900, 2022);
	mes = get_Entero("Mes: ");
	auxFecha.mes = validarEnterosMaxMin("Mes (1 - 12): ", mes, 1, 12);
	dia = get_Entero("Día: ");
	auxFecha.dia = validarEnterosMaxMin("Día (1 - 31): ", dia, 1, 31);

	return auxFecha;
}
int pedirPais(ePais paises[], int tamPaises)
{
	int opcionPais;
	listarPaises(paises, tamPaises);
	opcionPais = get_Entero("Elija el pais: ");
	opcionPais = validarEnterosMaxMin("Elija el pais (1 - 5): ", opcionPais, 1, 5);
	return opcionPais;
}

int pedirArtista(eArtista artistas[], int tamArtistas){

	int opcionArtista;
	listarArtistas(artistas, tamArtistas);
	opcionArtista = get_Entero("Elija el artista: ");
	opcionArtista = validarEnterosMaxMin("Elija el artista (1 - 4): ", opcionArtista, 1, 4);
	return opcionArtista;
}

int pedirDiscografica(eDiscografica discograficas[], int tamDiscograficas){

	int opcionDiscografica;
	listarDiscograficas(discograficas, tamDiscograficas);
	opcionDiscografica = get_Entero("Elija la discográfica: ");
	opcionDiscografica = validarEnterosMaxMin("Elija la discográfica (1 - 3): ", opcionDiscografica, 1, 3);
	return opcionDiscografica;
}

int pedirTipoDeArtista(eTipoArtista tipoArtistas[], int tamTipo){

	int opcionTipoDeArtista;
	listarTipoDeArtistas(tipoArtistas, tamTipo);
	opcionTipoDeArtista = get_Entero("Elija el tipo de artista: ");
	opcionTipoDeArtista = validarEnterosMaxMin("Elija el tipo de artista (1 - 2): ",opcionTipoDeArtista, 1, 2);
	return opcionTipoDeArtista;
}

void baja(eAlbum albumes[], int tamanio){

	int index, id;
	char confirmar;
	id = get_Entero("Ingrese el ID del album a dar de baja: ");
	index = buscarAlbumPorId(albumes, tamanio, id);
	if(index != -1)
	{
		confirmar = get_Char("Confirmar [S/N]: ");
		confirmar = validarCharDosOpciones("Ingrese 'S' (SI) o 'N' (NO): ", confirmar, 'S', 'N');
		if(confirmar == 'S')
		{
			albumes[index].estado = BAJADO;
			printf("\n===========================\nAlbum con ID %d DADO DE BAJA\n===========================\n", id);
		}
		else
		{
			printf("\n=========================\nBaja CANCELADA con exito\n=========================\n");
		}
	}
	else
	{
		printf("\n============================\nAlbum con ID %d NO ENCONTRADO\n============================\n", id);
	}
}

void modificar(eAlbum albumes[], int tamanio, ePais paises[], int tamPaises){

	int index, id;
	char opcion;
	id = get_Entero("Ingrese el ID del album a modificar: ");
	index = buscarAlbumPorId(albumes, tamanio, id);
	if(index != -1)
	{
		opcion = subMenu("Modificar:\nA. Título\nB.Fecha de publicación\nC.Importe\nD.Pais", 'A', 'D');
		switch(opcion)
		{
			case 'A':
				get_String("Título del album: ", albumes[index].titulo);
				validarString("Título (1 - 50 caracteres):", albumes[index].titulo, 51);
			break;
			case 'B':
				albumes[index].fechaPublicacion = pedirFecha();
			break;
			case 'C':
				albumes[index].importe = get_FlotantePositivo("Importe: ", "El importe no puede ser negativo");
			break;
			case 'D':
				albumes[index].idPais = pedirPais(paises, tamPaises);
			break;
		}
		printf("\n=======================================\nAlbum con ID %d MODIFICADO CORRECTAMENTE\n=======================================\n", id);
	}
	else
	{
		printf("\n============================\nAlbum con ID %d NO ENCONTRADO\n============================\n", id);
	}
}


void informar(eAlbum albumes[], int tamanio){

	int opcionInformar, cantidadAlbumesMenorPromedio;
	float total, promedio;

	opcionInformar = subMenu("\nInformar:\nA. Total y promedio de los importes, cuántos albumen no superan el promedio\nB. Cantidad de álbumes publicados despues del 31/12/1999", 'A', 'B');

	switch(opcionInformar)
	{
		case 'A':
			total = totalImportes(albumes, tamanio);
			promedio = promedioImportes(albumes, tamanio);
			cantidadAlbumesMenorPromedio = listarContarAlbumesMenorAlPromedioImportes(albumes, tamanio, 1);
			printf("\n=================================================\nTotal Importes: $%.2f\nPromedio Importes: %.2f\nCantidad de álbumes que no superan el promedio: %d\n=================================================\n", total, promedio, cantidadAlbumesMenorPromedio);
		break;
		case 'B':
			cantidadAlbumesMenorPromedio = listarContarAlbumesPublicadosDespuesAnio1999(albumes, tamanio, 1);
			printf("\n====================================================\nCantidad de álbumes publicados a partir del año 2000: %d\n====================================================\n", cantidadAlbumesMenorPromedio);
		break;
	}
}

float totalImportes(eAlbum albumes[], int tamanio){

	int i;
	float acumuladorImportes = 0;
	for(i = 0; i < tamanio; i++)
	{
		if(albumes[i].estado == OCUPADO)
		{
			acumuladorImportes += albumes[i].importe;
		}
	}
	return acumuladorImportes;
}

float promedioImportes(eAlbum albumes[], int tamanio){

	int i, total;
	int contadorImportes = 0;
	float promedioTotal;
	total = totalImportes(albumes, tamanio);

	for(i = 0; i < tamanio; i++)
	{
		if(albumes[i].estado == OCUPADO)
		{
			contadorImportes++;
		}
	}
	promedioTotal = total / contadorImportes;
	return promedioTotal;
}

void mostrarUnAlbum(eAlbum album){

	printf("\nID: %d\n   Título del album: %s\n   Fecha de publicación: %d/%d/%d\n   Importe: $%.2f\n", album.id, album.titulo, album.fechaPublicacion.dia, album.fechaPublicacion.mes, album.fechaPublicacion.anio, album.importe);
}

void mostrarUnAlbumCompleto(eAlbum album, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises){

	int i;
	int artistaId, tipoId, discogId, paisId;

	for(i = 0; i < tamArtistas; i++)
	{
		if( artistas[i].id == album.idArtista)
		{
			artistaId = i;
		}

	}

	for(i = 0; i < tamTipo; i++)
	{

		if( tipoArtistas[i].id == album.idTipoArtista)
		{
			tipoId = i;
		}

	}
	for(i = 0; i < tamDiscograficas; i++)
	{

		if( discograficas[i].id == album.idDiscografica)
		{
			discogId = i;
		}

	}

	for(i = 0; i < tamPaises; i++)
	{

		if( paises[i].id == album.idPais)
		{
			paisId = i;
		}

	}
	printf("\nID: %d\n   Título del album: %s\n   Fecha de publicación: %d/%d/%d\n   Importe: $%.2f\n   Artista: %s\n   Tipo de Artista: %s\n   Discografica: %s\n   Pais: %s\n",album.id, album.titulo, album.fechaPublicacion.dia, album.fechaPublicacion.mes, album.fechaPublicacion.anio, album.importe, artistas[artistaId].nombre, tipoArtistas[tipoId].descripcion ,discograficas[discogId].descripcion, paises[paisId].descripcion);

}

void listar(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises){

	int opcion;
	opcion = subMenu("Listar:\nA. Todas las discográficas.\nB. Todos los tipos de artistas musicales.\nC. Todos los artistas.\nD. Todos los álbumes.\nE. Álbumes ordenados por importe/título\nF. Todos los álbumes cuya fecha de publicación es posterior a 31/12/1999.\nG. Todos los álbumes que no superan el promedio de los importes.\nH. Todos los álbumes de un artista determinado.\nI. Todos los álbumes de cada año.\nJ. El álbum o los álbumes más baratos.\nK. Todos los paises\nL. Todos los álbumes que no sean de argentina.\nM. Todos los álbumes de argentina de un año determinado", 'A', 'M');
	switch(opcion)
	{
		case 'A':
			listarDiscograficas(discograficas, tamDiscograficas);
		break;
		case 'B':
			listarTipoDeArtistas(tipoArtistas, tamTipo);
		break;
		case 'C':
			listarArtistas(artistas, tamArtistas);
		break;
		case 'D':
			listarAlbumes(albumes, tamanio, artistas, tamArtistas, tipoArtistas, tamTipo, discograficas, tamDiscograficas, paises, tamPaises);
		break;
		case 'E':
			ordenarAlbumes(albumes, tamanio);
			listarAlbumes(albumes, tamanio, artistas, tamArtistas, tipoArtistas, tamTipo, discograficas, tamDiscograficas, paises, tamPaises);
		break;
		case 'F':
			listarContarAlbumesPublicadosDespuesAnio1999(albumes, tamanio, 2);
		break;
		case 'G':
			listarContarAlbumesMenorAlPromedioImportes(albumes, tamanio, 2);
		break;
		case 'H':
			listarAlbumPorArtista(albumes, tamanio, artistas, tamArtistas);
		break;
		case 'I':
			listarAlbumesPorAnio(albumes, tamanio);
		break;
		case 'J':
			listarAlbumesMasBaratos(albumes, tamanio);
		break;
		case 'K':
			listarPaises(paises, tamPaises);
		break;
		case 'L':
			listarAlbumesNoArgentina(albumes, tamanio, artistas, tamArtistas, tipoArtistas, tamTipo, discograficas, tamDiscograficas, paises, tamPaises);
		break;
		case 'M':
			listarAlbumesArgentinosPorAnio(albumes, tamanio, artistas, tamArtistas, tipoArtistas, tamTipo, discograficas, tamDiscograficas, paises, tamPaises);
		break;
	}
}
void listarPaises(ePais paises[], int tamanio){

	int i;
	printf("\nPaises:\n");
	for(i = 0; i < tamanio; i++)
	{
		printf("%d-  %s\n", paises[i].id, paises[i].descripcion);
	}
}

void listarArtistas(eArtista artistas[], int tamanio){
	int i;
	printf("\nArtistas:\n");
	for(i = 0; i < tamanio; i++)
	{
		printf("%d-  %s\n", artistas[i].id, artistas[i].nombre);
	}
}

void listarTipoDeArtistas(eTipoArtista tipoArtistas[], int tamanio){
	int i;
	printf("\nTipos de artistas:\n");
	for(i = 0; i < tamanio; i++)
	{
		printf("%d-  %s\n", tipoArtistas[i].id, tipoArtistas[i].descripcion);
	}
}

void listarDiscograficas(eDiscografica discograficas[], int tamanio){
	int i;
	printf("\nDiscográficas:\n");
	for(i = 0; i < tamanio; i++)
	{
		printf("%d-  %s\n", discograficas[i].id, discograficas[i].descripcion);
	}
}


void listarAlbumes(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises){

	int i;
	int bandera = 0;

	for(i = 0; i < tamanio; i++)
	{
		if(albumes[i].estado == OCUPADO)
		{
			bandera = 1;
			mostrarUnAlbumCompleto(albumes[i], albumes, tamanio, artistas, tamArtistas, tipoArtistas, tamTipo, discograficas, tamDiscograficas, paises, tamPaises);
		}
	}
	if(bandera == 0)
	{
		printf("\n=============================================\nTodos los álbumes ingresado se dieron DE BAJA\n=============================================\n");
	}
}

int listarContarAlbumesMenorAlPromedioImportes(eAlbum albumes[], int tamanio, int accion){

	int i;
	int contadorAlbumes = 0;
	float promedio;
	promedio = promedioImportes(albumes, tamanio);
	for(i = 0; i < tamanio; i++)
	{
		if(albumes[i].importe < promedio && albumes[i].estado == OCUPADO)
		{
			switch(accion)
			{
				case 1:
					contadorAlbumes++;
				break;
				case 2:
					 mostrarUnAlbum(albumes[i]);
				break;
			}
		}
	}
	return contadorAlbumes;
}

int listarContarAlbumesPublicadosDespuesAnio1999(eAlbum albumes[], int tamanio, int accion){

	int contadorAlbumes = 0;
	int i;

	for(i = 0; i < tamanio; i++)
	{
		if(albumes[i].fechaPublicacion.anio > 1999 && albumes[i].estado == OCUPADO)
		{
			switch(accion)
			{
				case 1:
					contadorAlbumes++;
				break;
				case 2:
					mostrarUnAlbum(albumes[i]);
				break;
			}

		}
	}
	return contadorAlbumes;
}

void ordenarAlbumes(eAlbum albumes[], int tamanio){

	eAlbum aux;
	int i,j;

	if(albumes != NULL && tamanio > 0)
	{
		for(i = 0; i < tamanio; i++)
		{
			for(j = i + 1; j < tamanio; j++)
			{
				if(albumes[i].estado == OCUPADO && albumes[j].estado == OCUPADO)
				{

					if(albumes[i].importe < albumes[j].importe)
					{
						aux = albumes[i];
						albumes[i] = albumes[j];
						albumes[j] = aux;
					}
					else
					{
						if(albumes[i].importe == albumes[j].importe)
						{
							if(strcmp(albumes[i].titulo, albumes[j].titulo) > 0)
							{
								aux = albumes[i];
								albumes[i] = albumes[j];
								albumes[j] = aux;
							}
						}
					}
				}
			}
		}
	}
}

void listarAlbumPorArtista(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas){

	int idDelArtistaAMostrar, bandera;
	int i, j;
	idDelArtistaAMostrar = pedirArtista(artistas, tamArtistas);

	bandera = 0;
	for(i = 0; i < tamArtistas; i++)
	{

		if( idDelArtistaAMostrar == artistas[i].id )
		{
			for(j = 0; j < tamanio; j++){

				if( idDelArtistaAMostrar == albumes[j].idArtista && albumes[j].estado == OCUPADO)
				{
					bandera = 1;
					mostrarUnAlbum(albumes[j]);
					printf("   Artista: %s\n", artistas[i].nombre);
				}
			}
		break;
		}
	}
	if(bandera == 0)
	{
		printf("\n====================================================\nNo existe ningun album del artista: %s\n====================================================\n", artistas[i].nombre);

	}
}

void listarAlbumesPorAnio(eAlbum albumes[], int tamanio){

	int anios[tamanio];
	int i, j, k, l, m;

	for (i = 0; i < tamanio; i++)
	{
		anios[i] = 0;
		if(albumes[i].estado == OCUPADO)
		{
			anios[i] = albumes[i].fechaPublicacion.anio;
		}
	}
	for(j = 0; j < tamanio-1; j++)
	{
		for(k = j + 1; k < tamanio; k++){

			if(anios[j] == anios[k])
			{
				anios[k] = 0;
			}
		}
	}
	for(l = 0; l < tamanio; l++)
	{
		if(anios[l] != 0)
		{
			printf("\nÁlbumes del año: %d", anios[l]);
			for(m = 0; m < tamanio; m++)
			{
				if(anios[l] == albumes[m].fechaPublicacion.anio)
				{
					mostrarUnAlbum(albumes[m]);
				}
			}
		}
	}
}

void listarAlbumesMasBaratos(eAlbum albumes[], int tamanio){

	float importeMasBarato;
	int bandera = 0;
	int i,j;

	for(i = 0; i < tamanio; i++)
	{

		if(albumes[i].estado == OCUPADO && (albumes[i].importe < importeMasBarato || bandera == 0))
		{
			importeMasBarato = albumes[i].importe;
			bandera = 1;
		}
	}
	printf("\nAlbum/álbumes con el importe más barato:\n");
	for(j = 0; j < tamanio; j++)
	{
		if(albumes[j].estado == OCUPADO && albumes[j].importe == importeMasBarato)
		{
			mostrarUnAlbum(albumes[j]);
		}
	}
}

void listarAlbumesNoArgentina(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises){

	int i;
	int bandera = 0;
	for(i = 0; i < tamanio; i++)
	{
		if(albumes[i].estado == OCUPADO && albumes[i].idPais != 2)
		{
			bandera = 1;
			mostrarUnAlbumCompleto(albumes[i], artistas, tamArtistas, tipoArtistas, tamTipo, discograficas, tamDiscograficas, paises, tamPaises);
		}
	}
	if(bandera == 0)
	{
		printf("\n=========================================================\nNo existen álbumes que no sean de ARGENTINA\n=========================================================\n");
	}
}

void listarAlbumesArgentinosPorAnio(eAlbum albumes[], int tamanio, eArtista artistas[], int tamArtistas, eTipoArtista tipoArtistas[], int tamTipo, eDiscografica discograficas[], int tamDiscograficas, ePais paises[], int tamPaises){

	int i, bandera;
	int opcionAnio;
	bandera = 0;
	opcionAnio = get_Entero("Ingrese un año: ");
	opcionAnio = validarEnterosMaxMin("Año (1900 - 2022): ", opcionAnio, 1900, 2022);

	for(i = 0; i < tamanio;i++)
	{
		if(albumes[i].estado == OCUPADO && albumes[i].fechaPublicacion.anio == opcionAnio && albumes[i].idPais == 2)
		{
			bandera = 1;
			mostrarUnAlbumCompleto(albumes[i], artistas, tamArtistas, tipoArtistas, tamTipo, discograficas, tamDiscograficas, paises, tamPaises);
		}
	}
	if(bandera == 0)
	{
		printf("\n=========================================================\nNo existen álbumes argentinos publicados en el año: %d\n=========================================================\n", opcionAnio);
	}

}
