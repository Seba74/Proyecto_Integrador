// Librerias
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <ctype.h>
	#define MAX 5

// Variables y estructuras 

// ESTRUCTURA PARA LAS PREGUNTAS 
	typedef char t_string[200];
    typedef t_string tipo_preguntas[MAX];
	typedef struct {
		tipo_preguntas pregunta; //Pregunta
		int frente;
		int final;
    }td_preguntas;

// Procedimiento 

	void iniciarArchivo();
    void inicializarCola();
    bool colaVacia(td_preguntas);
    bool colaLlena(td_preguntas);
    void mostrarMenu();
	void menu(int *);
    void ingresarDatos();
    void agregarDatos(t_string);
    void eleminarElementoFF(); 
    void espaciosDisponibles(td_preguntas);
    void visualizarElementos(td_preguntas);	
	void registrarDatos();
	void cerrarArchivo();

// Definicion de variables globales 
    td_preguntas cola_preguntas;
	FILE *educatrivia;
	int contDatos = 0;
	
// Bloque principal 
	int main(){

		inicializarCola();
		iniciarArchivo();
		mostrarMenu();
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

// Inicializar Cola();
    void inicializarCola(){
        cola_preguntas.frente = -1;
        cola_preguntas.final = -1;
    }

// Comprabar si la cola esta vacia 
    bool colaVacia(td_preguntas p_cola){
        return(p_cola.frente == -1 && p_cola.final == -1);
    }

// comprobar si la cola esta llena 
    bool colaLlena(td_preguntas p_cola){
        return(p_cola.final == MAX-1);
    }

// Crear y mostrar menu 
   void mostrarMenu(){
        int opcion = -1;
        while (opcion != 0){
            printf("\n\t*** Que desea hacer en la lista de preguntas? ***\n\n");
            printf("\t1-Agregar una pregunta\n");
            printf("\t2-Eliminar pregunta\n");
            printf("\t3-Averiguar capacidad de preguntas restantes\n");
            printf("\t4-Mostrar Lista de preguntas\n");
            printf("\n\tOpcion (0 - para guardar): ");
        
            menu(&opcion);
    	}
	}

    void menu(int *_opcion){
        scanf("%d", _opcion);
        system("cls");
        switch (*_opcion) {
            case 1: ingresarDatos(); break;
            case 2: eleminarElementoFF(); break;
            case 3: espaciosDisponibles(cola_preguntas); break;
            case 4: visualizarElementos(cola_preguntas); break;
			case 0: break;
            default: printf("Opcion no valida.\n"); break;
        }
    }

// Ingresar pregunta  
    void ingresarDatos(){
        t_string tipo_pregunta; 
        printf("\nIngrese una pregunta: ");
        fflush(stdin);
        scanf("%[^\n]s", &tipo_pregunta);
        agregarDatos(tipo_pregunta);
    }

// Agregar preguntas al archivo
    void agregarDatos(t_string p_pregunta){
        if(colaLlena(cola_preguntas)){
            printf("\n\tNo hay lugares disponibles...\n");
        }else{
			contDatos++;
            cola_preguntas.final ++;
            strcpy(cola_preguntas.pregunta[cola_preguntas.final], p_pregunta);
            if(cola_preguntas.final == 0){ 
                cola_preguntas.frente = 0;
            } printf("\nSe inserto la pregunta: %s a la lista \n\n", p_pregunta);
        }   
    }
// Eliminar pregunta de la cola 
	void eleminarElementoFF(){
		t_string borrar_pregunta;
		int i;
		if(colaVacia(cola_preguntas) ) {
			printf("\n\tNo hay elementos para eliminar\n");
		} else {	
			contDatos = contDatos-1;
			strcpy( borrar_pregunta, cola_preguntas.pregunta[cola_preguntas.frente] );
			strcpy(cola_preguntas.pregunta[cola_preguntas.frente], " ");
			
			// Reacomodar la cola
			for(i=cola_preguntas.frente; i<cola_preguntas.final; i++ ) {
				strcpy(cola_preguntas.pregunta[i], cola_preguntas.pregunta[i+1] );			
			}
			strcpy(cola_preguntas.pregunta[cola_preguntas.final], " ");
			
			if(cola_preguntas.frente == cola_preguntas.final) {
				inicializarCola();
			} else {
				cola_preguntas.final = cola_preguntas.final -1;
			}
			printf("\tElemento eliminado: %s\n", borrar_pregunta);
		}
	}


	// Averiguar si hay espacio para a�adir m�s preguntas  
    void espaciosDisponibles(td_preguntas p_cola){
        if(colaLlena(p_cola)){
            printf("\n\tNo hay espacio para preguntas disponibles...\n");
        } else{
            printf("\n\tHay %d posiciones para preguntas disponibles!\n", (MAX-1)-cola_preguntas.final);
        }
    }

// Visualizar lista
    void visualizarElementos(td_preguntas p_cola){
        int i;
        if(colaVacia(p_cola)){
            printf("\n\tNo hay preguntas en lista.\n");
        } else{
            printf("\n\t*** LISTA DE PREGUNTAS ***\n\n");
            for(i=p_cola.frente;i<=p_cola.final;i++){
                printf("Pregunta %s\n", p_cola.pregunta[i]);
            } printf("\n");
        }
    }


// Registrar las preguntas en el archivo
	void registrarDatos(){
			// Grabar registro en el archivo
			fwrite(&cola_preguntas, sizeof(td_preguntas), 1, educatrivia);
			printf("\n\tArchivo guardado.\n\n");
	}

// Cerrar Archivo 
	void cerrarArchivo(){
        registrarDatos();
		printf("\n\tSe han ingresado %d preguntas con exito.\n", contDatos);
		fclose(educatrivia);
	}
