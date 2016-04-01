//============================================================================
// Name        : ProyectoP1.cpp
// Author      : Diego Ramirez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Trabajador {

	int codigo;
 	char nombre[15];
	int edad;
	char area[20]; };

	struct Indice{

	int carnet;
 	int posicion;	};

	int main(){

	int op, b;
	Trabajador empleado, auxiliar;
	Indice index, auxi;

	do{

	ofstream datos("empleado.txt", ios::binary | ios::app);
	ofstream in("indice.txt", ios::binary | ios::app);
	ifstream indices("indice.txt", ios::binary);

	cout<<"---------- HOLA A TODOS ----------"<<endl<<endl<<endl;
	cout<<"Base de Datos de Empresa Industrial Antigua"<<endl<<endl;

	cout<<"1. Agregar nuevo empleado"<<endl;
	cout<<"2. Buscar datos de trabajador ingresado"<<endl;
	cout<<"3. Despedir Empleado"<<endl;
	cout<<"4. Exit-----Salir"<<endl;

	cout<<endl<<"Que opcion deseas:  ";
	cin>>op;
	cout<<endl;

	if(op>0 && op<4){
		switch(op){

	case 1:

		if(!datos && !in){
		cout<<"Error no se pudo abrir el archivo"<<endl;
		}else{

		cout<<"Ingrese codigo de trabajo: ";
		cin>>empleado.codigo;
		cout<<endl;

		while(!indices.eof()){

	indices.read((char*) &auxi, sizeof(struct Indice));

	if (empleado.codigo==auxi.carnet){

		cout<<"El archivo ya existe, Posicion: "<<auxi.posicion;
		cout<<endl;

		b=10;
	}
		}

	indices.close();

		if(b!=10){

		cout<<"Agrege su nombre: ";
		cin>>empleado.nombre;
		cout<<endl;

		cout<<"Agrege su edad: ";
		cin>>empleado.edad;
		cout<<endl;

		cout<<"Agrege el area en donde trabajara: ";
		cin>>empleado.area;
		cout<<endl;

		datos.write((char*) &empleado, sizeof(struct Trabajador));
		datos.seekp(0, ios::end);

		index.carnet=empleado.codigo;

		index.posicion=datos.tellp()/sizeof(struct Trabajador);

		in.write((char*) &index, sizeof(struct Indice));
		cout<<"Guardado en posicion: "<<"["<<index.posicion<<"]"<<endl;
		datos.close();
		in.close();	}

		system("PAUSE"); break;

		}
		break;

	case 2:

		int buscar;
		cout<<"Escriba carnet de alumno a buscar: ";
		cin>>buscar;

		while(!indices.eof()){
		indices.read((char*) &auxi, sizeof(struct Indice));

		if (buscar==auxi.carnet){

		cout<<endl<<"POSICION: "<<auxi.posicion;

		cout<<endl<<endl;
		ifstream dato("empleado.txt", ios::binary);

		b=auxi.posicion-1;

		dato.seekg(sizeof(struct Trabajador)*b, ios::beg);
		dato.read((char*) &auxiliar, sizeof(struct Trabajador));

		cout<<"Codigo:  "<<auxiliar.codigo<<endl;
		cout<<"Nombre:  "<<auxiliar.nombre<<endl;
		cout<<"Edad:    "<<auxiliar.edad<<endl;
		cout<<"Area donde trabaja: "<<auxiliar.area<<endl;

		dato.close();

		system("PAUSE");

		}
			}

		indices.close();

		break;

	case 3:

		b=0;

		if(b==0){

			ifstream eliminar("empleado.txt", ios::binary);
			ifstream elim_ind("indice.txt", ios::binary);
			ofstream temp("temporal.txt", ios::binary | ios::out);
			ofstream temp_index("tmp.txt", ios::binary | ios::out);

		if(!eliminar || !elim_ind){

			cout<<"Error al abrir el archivo"<<endl;

		}else{

			cout<<"Ingrese el numero de carnet del alumno que desea borrar: ";
			cin>>op;

		while(!eliminar.eof()){

		eliminar.read((char*) &auxiliar, sizeof(struct Trabajador));

		if(auxiliar.codigo==op){

			cout<<"El archivo se ha eliminado de datos"<<endl;

		}else{

		temp.write((char*) &auxiliar, sizeof(struct Trabajador));

		}
			}

		while(!elim_ind.eof()){

		elim_ind.read((char*) &auxi, sizeof(struct Indice));

		if(auxi.carnet==op){

			cout<<"El archivo se ha eliminado de indice"<<endl;

		}else{

		temp_index.write((char*) &auxi, sizeof(struct Indice));

		}
			}
				}

		eliminar.close();
		temp.close();
		elim_ind.close();
		temp_index.close();

		 }

		remove("empleado.txt");
		remove("indice.txt");
		rename("temporal.txt", "alumnos.txt");
		rename("tmp.txt", "indice.txt");

	system("PAUSE"); break;



		}
			}

		} while(op>0 && op!=4);


	system("PAUSE");


	}
