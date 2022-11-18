#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

string* nombre, * clasificacion, * caracteristicas, * descripcion, * genero, encontrar;
int opcion, registros, opcion2, eliminar, modificar;
int* idarticulo, * numoc, * fecha;
float* precio, * iva, * total;

void Crear()
{
	printf("Articulos va a crear: \n");
	scanf("%d", &registros);
	idarticulo = new int[registros];
	numoc = new int[registros];
	precio = new float[registros];
	iva = new float[registros];
	total = new float[registros];
	nombre = new string[registros];
	fecha = new int[registros];
	clasificacion = new string[registros];
	caracteristicas = new string[registros];
	descripcion = new string[registros];
	genero = new string[registros];


	//crear articulo
	for (int i = 0;i < registros;i++)
	{
		printf("id del articulo: \n");
		scanf("%d", &idarticulo[i]);
		printf("Numero del articulo: \n");
		scanf("%d", &numoc[i]);
		printf("Nombre del articulo: \n");
		cin.ignore();
		getline(cin, nombre[i]);
		printf("Fecha del articulo: \n");
		scanf("%d", &fecha[i]);
		printf("Clasificacion del articulo: \n");
		cin.ignore();
		getline(cin, clasificacion[i]);
		printf("Caracteristicas del articulo: \n");
		cin.ignore();
		getline(cin, caracteristicas[i]);
		printf("Descripcion del articulo: \n");
		cin.ignore();
		getline(cin, descripcion[i]);
		printf("Genero del articulo: \n");
		cin.ignore();
		getline(cin, genero[i]);
		printf("Precio unitario del articulo: \n");
		scanf("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];
		printf("Articulo creado correctamente \n");
	}
}

void Lista()
{
	printf("Lista de los articulos \n Ingrese una opcion para encontrar el articulo \n");
	printf("1.-Clasificacion \n 2.-Genero \n");
	scanf("%d", &opcion2);
	switch (opcion2)
	{
	case 1:
	{
		printf("Ingrese la clasificacion del articulo \n");
		cin.ignore();
		getline(cin, encontrar);
		int i = 0;
		if (clasificacion[i] == encontrar)
		{
		   if(numoc[i] != 0)
		   {
			printf("Numero de compra: %d\n", numoc[i]);
			printf("Nombre del articulo: %s\n", nombre[i].c_str());
			printf("Fecha del articulo: %d\n", fecha[i]);
			printf("Clasificacion del articulo: %s\n", clasificacion[i].c_str());
			printf("Caracteristicas del articulo: %s\n", caracteristicas[i].c_str());
			printf("Descrpcion del articulo: %s\n", descripcion[i].c_str());
			printf("Genero del articulo:%s\n",genero[i].c_str());
			printf("Total: %f\n", total[i]);
			break;
		   }
		}
    }
	case 2: 
	{
		printf("Ingrese el genero del articulo \n ");
		cin.ignore();
		getline(cin, encontrar);
		int i = 0;
		if (genero[i] == encontrar)
		{
		    if(numoc[i] != 0)
		    {
			printf("Numero de compra: %d\n", numoc[i]);
			printf("Nombre del articulo: %s\n", nombre[i].c_str());
			printf("Fecha del articulo: %d\n", fecha[i]);
			printf("Clasificacion del articulo: %s\n", clasificacion[i].c_str());
			printf("Caracteristicas del articulo: %s\n", caracteristicas[i].c_str());
			printf("Descrpcion del articulo: %s\n", descripcion[i].c_str());
			printf("Genero del articulo: %s\n", genero[i].c_str());
			printf("Total:%f\n", total[i]);
			break;
		    }
		}
	}
	default:
	{
		printf("Seleccione una opcion valida \n");
		return Lista();
		break;
	}
	}
}

void Eliminar() 
{
	printf("id de articulo a eliminar \n");
	scanf("%d", &eliminar);
	for (int i = 0;i < registros;i++)
	{
	    if(eliminar == numoc[i])
	    {
          numoc[i] = 0;
          printf("Se elimino exitosamente \n");
	    }
	}
}

void Modificar() 
{
	do
	{
		printf("id del articulo a modificar \n");
		scanf("%d", &modificar);
	}    while(modificar <= 0);
	for (int i = 0;i < registros;i++)
	{
		if (modificar == idarticulo[i])
		{
			printf("Ingrese id del articulo\n");
			scanf("%d", &idarticulo[i]);
			printf("Ingrese el numero de compra:\n");
			scanf("%d", &numoc[i]);
			printf("Nombre del articulo: \n");
			cin.ignore();
			getline(cin, nombre[i]);
			printf("Fecha del articulo\n");
			scanf("%d", &fecha[i]);
			printf("Clasificacion del articulo: \n");
			cin.ignore();
			getline(cin, clasificacion[i]);
			printf("Caracteristicas del articulo: \n");
			cin.ignore();
			getline(cin, caracteristicas[i]);
			printf("Descrpcion del articulo: \n");
			cin.ignore();
			getline(cin, descripcion[i]);
			printf("Genero del articulo: \n");
			cin.ignore();
			getline(cin, genero[i]);
			printf("Precio unitario del articulo: \n");
			scanf("%f", &precio[i]);
			iva[i] = precio[i] * .16;
			total[i] = precio[i] + iva[i];
			printf("Articulo cambiado correctamente\n");
		}
	}
}

void Archivo()
{
	string nombrearchivo;
	ofstream archivo;
	archivo.open("Articulos.txt", ios::out);
	if (archivo.fail())
	{
		printf("No se pudo crear el archivo \n");
	}
	else 
	{
	    for (int i = 0; i < registros; i++)
		{
		    if (clasificacion[i] == encontrar) 
		    {
			   printf("Numero de compra: %d\n", numoc[i]);
			   printf("Nombre del articulo: %s\n", nombre[i].c_str());
			   printf("Fecha del articulo: %d\n", fecha[i]);
			   printf("Clasificacion del articulo: %s\n", clasificacion[i].c_str());
			   printf("Caracteristicas del articulo: %s\n", caracteristicas[i].c_str());
			   printf("Descrpcion del articulo: %s\n", descripcion[i].c_str());
			   printf("Genero del articulo: %s\n", genero[i].c_str());
			   printf("Total: %f\n", total[i]);
		    }
		}
	}
	archivo.close();
}

int main()
{
	while (opcion!=6)
	{
		printf("Bienvenido a la tienda de gamers para gamers, \n Seleccione una opcion \n");
		printf("1.-Crear articulo \n 2.-Lista de articulo \n 3.-Modificar articulo \n 4.-Eliminar \n 5.-Limpiar pantalla \n 6.-Salir del programa \n");
		scanf("%d", &opcion);
		switch (opcion)
		{
		case 1: 
		{
			Crear();
			system("pause");
			
			break;
		}
		case 2: 
		{
			Lista();
			system("pause");

			break;
		}
		case 3: 
		{
			Modificar();
			break;
		}
		case 4: 
		{
			Eliminar();
			break;
		}
		case 5: 
		{
			system("cls");
			
			break;
		}
		case 6: 
		{
			printf("Hasta luego :) \n");
			break;
		}
		default: 
		{
			printf("Ingrese una opcion valida \n");
			break;
		}
		}
	}
	void archivo();
}

