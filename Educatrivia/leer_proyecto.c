// LIBRERIAS 
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>
	#include <ctype.h>
	#include "banco_preguntas.h"
	
// DECLARACION DE ESTRUCTURA TIPO COLA 
	typedef char t_string[30];
		typedef struct{
			int id_participante;
			t_string nombre;
			int tipo_tema;
			int att; // Cantidad de vidas, valor *constante*
		}td_datos;

		typedef struct nodo{
			td_datos datos_participante;
			struct nodo * siguiente;
		}td_cola;
		
		typedef struct {
			td_cola * frente;
			td_cola * final;
		}t_cola;

		t_cola cola_competidores; 
		FILE * educatrivia;

// PROTOTIPOS 

// Lectura y corte de control 
	void iniciarArchivo();
	void leerRegistro();
	void procesarCorte();
	void principioCorte();
	void finDeCorte();
	void cerrarArchivo();

// funciones Educatrivia 
	bool colaVacia(t_cola);
	void inicializarCola();
	void participanteEducatrivia();
	void convertirMayus(t_string);
	void cuentaRegresiva(int);
	void juegoEducatrivia(banco_preguntas, respuestas);

// DECLARACION DE VARIABLES GLOBALES
	char opcion;
	td_datos participante; // Variable contendiente del archivo
	t_string nombre_mejor, participante_anterior;
	int control_participante, vidas_participante, puntuacion, mejor_puntuacion;
	int puntuacion_maxima = 8; // Puntuacion maxima alcanzada en un trivia 

// BLOQUE PRINCIPAL
	int main(){
		iniciarArchivo();
		procesarCorte();
		cerrarArchivo();
		return 0;
	}

	void iniciarArchivo(){
		educatrivia = fopen("educatrivia.dat","rb");
		mejor_puntuacion = 0;
		printf("\nRegistro abierto.../\n" );
		leerRegistro();
		printf("\n\t\t==========================\t\n");
		printf("\t\tBIENVENIDO A EDUCATRIVIA");
		printf("\n\t\t==========================\t\n");
		printf("\n=================================================================================\n");
		printf("\nEn este juego podra encontrar trivias relacionadas a su tema de preferencia\n");
		printf("\nGanara el participante que sume la mayor cantidad de puntos hasta un maximo de %d!\n", puntuacion_maxima);
		printf("\nRecuerde que tiene %d vidas (intentos de juego)\n", participante.att);
		printf("\nExitos y disfruta del juego.../\n");
		printf("\n================================================================================\n\n");
		system("pause");
		system("cls");
	}

	void leerRegistro(){
        fread(&participante, sizeof(td_datos), 1 , educatrivia);
    }
	
	void convertirMayus(t_string p_palabra){
		int l, i;
		l = strlen(p_palabra);
		for(i=0;i<l;i++){
			p_palabra[i] = toupper(p_palabra[i]);
		}
	}

	void procesarCorte(){
		while(!feof(educatrivia)){
			principioCorte();
			while(!feof(educatrivia) && participante.id_participante == control_participante){
				participanteEducatrivia();
				leerRegistro();
			}
			finDeCorte();
		}
	}

	void principioCorte(){
		control_participante=participante.id_participante;
		strcpy(participante_anterior, participante.nombre);

		puntuacion = 0;
		printf("\n\t=====================================================================================\n");
			printf("\t\t\t\t\tDatos del Participante\t\t");
			printf("\n\t=====================================================================================\n");
		printf("\n\tID: %d || Nombre: %s\n", control_participante, participante.nombre);
	}

	void participanteEducatrivia(){
		printf("\n\tEleccion: %s\n", temas[participante.tipo_tema]);
		printf("\n\t=============================\t\n");
		system("pause");
		system("cls");
		convertirMayus(temas[participante.tipo_tema]);
		if(participante.tipo_tema == 1){
			juegoEducatrivia(historia, r_historia);
		}else{
			if(participante.tipo_tema == 2){
				juegoEducatrivia(geografia, r_geografia);
			}else{
				juegoEducatrivia(biologia, r_biologia);
			}
		}
	}

	void cuentaRegresiva(int p_numero){
		if(p_numero>0){
            printf("\n\t\t%d\n", p_numero);
            sleep(1);
            cuentaRegresiva(p_numero-1);
		}
    }

	void juegoEducatrivia(banco_preguntas p_tema, respuestas p_respuestas){
		int i;
		char respuesta;
		printf("\n\t====================================================\n");
		printf("\n\tBienvenido a la trivia de '%s'\n", temas[participante.tipo_tema]);
		printf("\n\t====================================================\n\n");
		system("pause");
		system("cls");
		printf("\tEl juego comenzara en:\n");
		cuentaRegresiva(3);
		system("cls");
		while(participante.att != 0 && puntuacion <puntuacion_maxima){ 
			srand (time (NULL));
			i = rand() % 12;
				printf("\n\t%s?\n\n", p_tema[i+1]);
				printf("\tV - verdadero\n");
				printf("\tF - Falso\n");
				printf("\tOpcion: ");
				fflush(stdin);
				scanf("%c", &respuesta);
				if(toupper(respuesta) == p_respuestas[i+1]){
					printf("\n\tRespuesta Correcta!\n");
					puntuacion ++;
				}else{
					printf("\n\tRespuesta Incorrecta!\n");
					participante.att--;
					if(participante.att == 0){
						printf("\tTe quedaste sin vidas :c, vuelve a intentarlo!\n\n");	
					}else{
						printf("\tTe quedan %d vidas\n\n", participante.att);
					}
				}
				system("pause");
				system("cls");
		}		
				if(puntuacion == puntuacion_maxima){
					printf("\tHaz completado la trivia de historia exitosamente!\n");
					printf("\tCantidad de vidas: %d\n\n", participante.att);
					participante.att == 0;
				}
				printf("\n\t==========================");
				printf("\n\t|| PUNTAJE OBTENIDO: %d ||", puntuacion);
				printf("\n\t==========================\n\n");
				system("pause");
				system("cls");
	}

	void finDeCorte(){
		if(mejor_puntuacion < puntuacion){
			mejor_puntuacion = puntuacion;
			strcpy(nombre_mejor, participante_anterior);
		}
			convertirMayus(nombre_mejor);
	}

	void cerrarArchivo(){
		printf("\n\t==========================================================================");
		printf("\n\tEL PARTICIPANTE CON EL MAYOR PUNTAJE ES '%s' || PUNTAJE OBTENIDO: %d", nombre_mejor, mejor_puntuacion);
		printf("\n\t==========================================================================\n\n");
		fclose(educatrivia);
	}
