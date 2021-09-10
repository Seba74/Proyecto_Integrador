// Librerias 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 5

// Variables y estructuras 
// ESTRUCTURA PARA LAS PREGUNTAS 
	typedef char t_string[200];
    typedef t_string tipo_preguntas[MAX];
	typedef struct {
		tipo_preguntas pregunta; //Pregunta
    }td_preguntas;

// Procedimiento 

	void iniciarArchivo();
	void registrarDatos();
	void ingresarDatos();
	void cerrarArchivo();

// Definición de variables globales 
    td_preguntas cola_preguntas;
	FILE *educatrivia;
	int contDatos;

// Bloque principal 
	int main(){

		iniciarArchivo();
		registrarDatos();
		cerrarArchivo();	
		return 0;
	}
	
// Crear e Iniciar Archivo 

	void iniciarArchivo(){
	
	educatrivia = fopen("educatrivia.dat", "ab");
	if(educatrivia == NULL){
		printf("Error al intentar crear el archivo...\n");
	}else {
			printf("Archivo Creado!...\n\n");
	}}

// Registrar Datos 

	void registrarDatos(){
		
		char opcion = 's';
		while(tolower(opcion) != 'n'){
			contDatos++;
			ingresarDatos();
			
			// Grabar registro en el archivo
			
			fwrite(&cola_preguntas, sizeof(td_preguntas), 1, educatrivia);
			
			printf("\n\tArchivo guardado.\n\n");
			printf("Desea ingresar otro inscripto? ('n' para finalizar || 's' para continuar): ");
			fflush(stdin);
			scanf("%c", &opcion);
			printf("\n");
			
		}
		}

// Ingresar datos  

	void ingresarDatos(){
		int i;
		printf("\n\n\tIngrese las preguntas correspondientes a la trivia\n\n");
		for(i=0;i<MAX;i++){
		    printf("pregunta %d: ", i+1);
		    fflush(stdin);
		    scanf("%[^\n]s", cola_preguntas.pregunta[i]);
        	}
	}
	
// Cerrar Archivo 

	void cerrarArchivo(){
		
		printf("\n\tSe han ingresado %d datos con exito.\n", contDatos);
		
		fclose(educatrivia);
	}
