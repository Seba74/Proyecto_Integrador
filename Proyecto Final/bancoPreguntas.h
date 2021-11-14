// LIBRERIAS
    #include <stdio.h>

// BANCO DE PREGUNTAS 

    typedef char t_string[30];
    typedef char preguntas[300];
    typedef preguntas banco_preguntas[];
    typedef char respuestas[];
    typedef t_string t_temas[];
    
    t_temas temas ={" ", "Historia Argentina", "Geografia", "Biologia"};

    banco_preguntas historia = {" ","La moneda oficial de argentina es el euro", "El general Jose de San Martin nacio en corrientes", "El asado es el plato mas famoso en Argentina", "Argentina se independizo el 9 de Julio de 1816", "Domingo Faustino Sarmiento fue el creador de la bandera Argentina.", "El 25 de mayo de 1810 en Tucuman se produjo el evento conocido como la revolucion de mayo", "El primer presidente fue Bernardino Rivadavia", "El aguila es el ave nacional de Argentina", "La guerra de malvinas termino un 14 de junio de 1983", "En la Argentina existe una total libertad de culto. La religion catolica es profesada mayoritariamente pero también se practican otros cultos como el protestantismo, el judaismo, el islamismo, la religion ortodoxa griega, la ortodoxa rusa y otras", "Ciudad de Vera de las Siete Corrientes no fue el nombre original de la ciudad de Corrientes", "La ciudad capital de la provincia de Corrientes fue fundada en 1588"};
	respuestas r_historia = {' ', 'F', 'V', 'V', 'V', 'F', 'F', 'V', 'F', 'F', 'V', 'F', 'V'};

	banco_preguntas geografia = {" ", "La piramide de giza queda en Egipto","Rusia es un pais situado en  America del sur", "El rio amazonas pasa por Brasil", "El monte fuji queda en India", "Paris es la capital de Noruega", "Irlanda es una isla", "Malasia es uno de los 14 paises que conforma Oceania", "El idioma oficial de Costa de Marfil es el ingles", "Ushuaia, ciudad argentina, es la mas austral del mundo", "La capital de Lituania es Vilna", "Chile tiene tres zonas geograficas; Chile continental, Chile insular y el Territorio Chileno Antartico", "Mauna Kea es el volcan más alto del mundo"};
	respuestas r_geografia = {' ','V', 'F', 'V', 'F', 'F', 'V', 'F', 'F', 'V', 'V', 'V', 'F'};

	banco_preguntas biologia = {" ", "La celula eucariota tiene un nucleo","La botanica es la rama de la biologia que estudia a los animales", "Las mariposas son mamiferos", "El esqueleto de un ser humano adulto esta compuesto por 206 huesos", "La ecologia es la rama de la biologia que estudia la relación de los seres vivos y su hábitat", "Todas las serpientes son venenosas", "La sinecologia es la ciencia que estudia las relaciones entre las comunidades biológicas y los ecosistemas de la Tierra", "¿La salamandra es un animal de sangre caliente?", "Las células, nacen unas de otras, se alimentan para crecer y para poder llevar a cabo sus funciones; se reproducen para dar origen a nuevas células y mueren", "Observar y estudiar las células es complicado por su pequeño tamaño, por ello es necesario utilizar el microscopio", "La celulosa es el componente de las celulas animales que permiten a estos mantener su forma", "El nucleo es una esfera que ocupa la zona central de todas las celulas"};
	respuestas r_biologia = {' ','V', 'F', 'F', 'V', 'V', 'F', 'V', 'F', 'V', 'V', 'F', 'F'};
