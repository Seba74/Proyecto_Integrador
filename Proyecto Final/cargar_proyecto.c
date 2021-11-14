// LIBRERIAS
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #define ATT 3 // Cantidad de intentos   

// DECLARACION DE ESTRUCTURA TIPO COLA
    typedef char t_string[30];
    typedef t_string t_temas[];
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

//PROTOTIPOS 

// Manipulacion del archivo
    void iniciarArchivo();
    void continuarPrograma();
    void grabarRegistroParticipante(td_datos);
    void cerrarArchivo();

// Manipulacion de la cola de usuarios
    void inicializarCola();
    bool colaVacia(t_cola);
    void ejecutarPrograma();
    void ejecutarMenu();
    td_datos ingresarDatos();
    void agregarDatosCola(td_datos);
    void eliminarParticipante();
    void visualizarParticipantes(t_cola);
    td_cola * primerParticipante(t_cola);
    void mostrarPrimerParticipante();
 
//DECLARACION DE VARIABLES GLOBALES

    char opcion;
    int total_datos = 0;
    td_datos datos_guardados; // DATOS DEL PARTICIPANTE

// BLOQUE PRINCIPAL
    int main(){
        iniciarArchivo();
        ejecutarPrograma();
        return 0;
    }

// INICIALIZAR PROGRAMA 

    void inicializarCola(){
        cola_competidores.frente= NULL;
        cola_competidores.final= NULL;
        printf("...!\n");
    }

    bool colaVacia(t_cola p_cola){
        return(p_cola.frente==NULL && p_cola.final==NULL);
    }

    void iniciarArchivo(){
        educatrivia = fopen("educatrivia.dat", "wb");
            if(educatrivia == NULL){
                printf("Error al intentar crear el archivo...\n");
            }else {
                    printf("Archivo Creado!...\n\n");
            }
        system("pause");
    }

// EJECUTAR PROGRAMA PRINCIPAL  
    void ejecutarPrograma(){
        continuarPrograma();
        inicializarCola();
        while(toupper(opcion)== 'S'){
            ejecutarMenu();
            continuarPrograma();
        }
        cerrarArchivo();
    }

    void continuarPrograma(){
        printf("\n\tDesea ingresar al menu?: S-N: ");
        fflush(stdin);
        scanf("%c",&opcion);
        system("cls");
    }

// MENU
    void ejecutarMenu(){
        int eleccion;
            td_datos e;
            printf("\n\t\t------------------------------------");
            printf("\n\t\tBIENVENIDO AL MENU DE EDUCATRIVIA");
            printf("\n\t\t------------------------------------\n");
            printf("\n\t|| 0 - Salir del menu\t\t\t\t||");
            printf("\n\t|| 1 - Ingresar datos de participante\t\t||");
            printf("\n\t|| 2 - Eliminar participante\t\t\t||");	
            printf("\n\t|| 3 - Mostrar participantes en la cola\t\t||");
            printf("\n\t|| 4 - Mostrar el primer participante\t\t||");
            printf("\n\n\tOpcion: ");
            scanf("%d", &eleccion);
            system("cls");
            switch (eleccion){
                case 0: break;
                case 1: e = ingresarDatos(); 
                        agregarDatosCola(e);
                        ejecutarMenu();
                        break;
                case 2: eliminarParticipante(); 
                        ejecutarMenu();
                        break;
                case 3: visualizarParticipantes(cola_competidores); 
                        ejecutarMenu();
                        break;
                case 4: mostrarPrimerParticipante(); 
                        ejecutarMenu();
                        break;
                default: printf("Opcion no valida\n"); break;
            }
    }

// INGRESAR DATOS DE PARTICIPANTES
    td_datos ingresarDatos(){
        td_datos p1; // Variable donde se guardaran los datos ingresados por teclado
        system("cls");
            printf("\n\t*** INGRESO DE DATOS DEL PARTICIPANTE ***\n\n");
            printf("\tID: ");
            scanf("%d",&p1.id_participante);
            printf("\tNombre: ");
            fflush(stdin);
            scanf("%[^\n]s",&p1.nombre);
            system("cls");
            printf("\t--- Eliga un tema a preferencia ---\n\n");
            printf("\t1 - Historia\n");
            printf("\t2 - Geografia\n");
            printf("\t3 - Biologia\n");
            printf("\tOpcion: ");
            scanf("%d", &p1.tipo_tema);
            p1.att = ATT;
            return p1;
    }
        
    void agregarDatosCola(td_datos p_datos){
        td_cola *nuevo_nodo;
        nuevo_nodo =(td_cola *) malloc(sizeof(td_cola));	
        nuevo_nodo->datos_participante = p_datos;
        total_datos ++;
        nuevo_nodo->siguiente = NULL;
        if(colaVacia(cola_competidores)){
            cola_competidores.frente = nuevo_nodo;
            cola_competidores.final = nuevo_nodo;
        } else {
            cola_competidores.final->siguiente = nuevo_nodo;
            cola_competidores.final = nuevo_nodo;
        }
        grabarRegistroParticipante(p_datos);
    }

    void eliminarParticipante(){
        if(colaVacia(cola_competidores)) {
            printf("\n\tNo hay competidores en la cola\n");
        } else {
            td_cola * competidor_eliminar;
            competidor_eliminar = cola_competidores.frente;
            if( cola_competidores.frente == cola_competidores.final ) {
                inicializarCola();
            } else {
                cola_competidores.frente = competidor_eliminar->siguiente;
            }
            printf("\n\t||ID: %d||Nombre: %s||\n", competidor_eliminar->datos_participante.id_participante, competidor_eliminar->datos_participante.nombre);
            free(competidor_eliminar);
            total_datos --;
            competidor_eliminar = NULL;		
        } 	
    }

    void visualizarParticipantes(t_cola p_cola){
        t_temas temas={" ", "Matematicas", "Literatura", "Biologia"};
        if(!colaVacia(cola_competidores)) {
            td_cola * aux;
            aux = p_cola.frente;
            printf("\n\t\t\t *** PARTICIPANTES *** \n");
            while( aux != NULL ) {
                printf("\n\t|| ID: %d || Nombre: %s|| Tema de preferencia: %s ||\n", aux->datos_participante.id_participante, aux->datos_participante.nombre, temas[aux->datos_participante.tipo_tema]);
                aux = aux->siguiente;
            }	
        } else {
            printf("\n\tNo hay participantes para visualizar!\n");
        }	
    }

    td_cola * primerParticipante(t_cola p_cola){
        if(!colaVacia(p_cola)){
            return p_cola.frente;	
        }else{
            return NULL;
        }	
    }

    void mostrarPrimerParticipante(){

        if(primerParticipante(cola_competidores)){
            printf("\n\t|| ID: %d|| Nombre: %s||\n", cola_competidores.frente->datos_participante.id_participante, cola_competidores.frente->datos_participante.nombre);
        }else{
            printf("No hay participantes en la Cola...\n");
        }
    }

    void grabarRegistroParticipante(td_datos p_participante){
        fwrite( &p_participante, sizeof(td_datos), 1, educatrivia);
        printf( "\n\tRegistro del Participante agregado con exito!\n\n" );
    }

    void cerrarArchivo() {
        system("cls");
        printf("\n\tSe ingresaron %d datos con exito!\n\n", total_datos);
        fclose(educatrivia);
    }
