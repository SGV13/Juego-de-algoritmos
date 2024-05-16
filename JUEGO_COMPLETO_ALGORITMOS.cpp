#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <locale>  //para setlocale
#include <cctype>  //para toupper y tolower
#include <windows.h>
#include <fstream>
#include <algorithm>
using namespace std;


struct Jugador {
    string nombre;
    int puntuacion;

    Jugador(string nombre, int puntuacion) : nombre(nombre), puntuacion(puntuacion) {}
};

// Función para guardar las puntuaciones de los jugadores en un archivo
void guardarPuntuaciones(const vector<Jugador> &jugadores) {
    ofstream archivo("registro_puntuaciones.txt");
    
    if (archivo.is_open()) {
        for (const Jugador &jugador : jugadores) {
            archivo << "Nombre: " << jugador.nombre << ", Puntuación: " << jugador.puntuacion << endl;
        }
        archivo.close();
        cout << "Registro de puntuaciones guardado en 'registro_puntuaciones.txt'" << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar el registro de puntuaciones" << endl;
    }
}

// Función para obtener un número aleatorio entre min y max
int randomNumber(int min, int max)

{
    return min + rand() % (max - min + 1);
}

// Mostrar reglas y metodo de juego 
void mostrarReglasYInstrucciones() {
    cout<<endl;
    cout<<endl;
    Sleep(1000);
    cout << "                                       Bienvenidos al juego de adivinar criaturas mitologicas" << endl << endl;
    cout<<endl;
    Sleep(1500);
    cout << "                        Primero las reglas... ¿no?" << endl << endl;
    cout << "                        ####################################################################################################################   " << endl;
    cout << "                        ##                                                                                                                ##   " << endl;
    cout << "                        ##   REGLA 1: A la hora de responder a la descripcion, deberas hacerlo en minuscula y sin tildes                  ##   " << endl;
    cout << "                        ##   REGLA 2: Cuando desees la pista, deberas indicar la respuesta con una S o N, siendo S aceptarla y N rechazar ##" << endl;
    cout << "                        ##   REGLA 3: No puedes buscar la respuesta o pedirsela a alguien mas                                             ##" << endl;
    cout << "                        ##   REGLA 4: Deberas respetar el turno, el juego indicara a quien le tocara responder                            ##" << endl;
    cout << "                        ##   REGLA 5: Si respondes tarde, te contara como una respuesta mala aunque este buena, solo por demorarse        ##" << endl;
    cout << "                        ##                                                                                                                ##" << endl;
    cout << "                        ####################################################################################################################   " << endl << endl;
    cout<<endl;
    Sleep(7000);

    cout << "                        COMO FUNCIONA EL JUEGO                                                                                       " << endl << endl;
    cout << "                        ####################################################################################################################   " << endl;
    cout << "                        ##                                                                                                                ##   " << endl;
    cout << "                        ##   1: Todos los jugadores comenzaran con 0 puntos, dependera de ellos si suman o restan                         ##   " << endl;
    cout << "                        ##   2: Cada respuesta correcta te sumara TRES puntos                                                             ##" << endl;
    cout << "                        ##   3: La pista costara 1 punto, se te habilitara cuando tengas los puntos suficientes para usarla               ##" << endl;
    cout << "                        ##   4: Cualquier jugador que escriba 'terminar' en su respuesta, acabara el juego inmediatamente                 ##" << endl;
    cout << "                        ##   5: Cuando falles una respuesta, perderas 1 punto                                                             ##" << endl;
    cout << "                        ##   6: El primero en llegar a 10 puntos gana, se mostrara la puntuacion de cada uno y el ganador                 ##" << endl;
    cout << "                        ##   7: Aparecera el cronometro pero no lo que estas escribiendo, asi que no te equivoques campeon                ##" << endl;
    cout << "                        ##                                                                                                                ##" << endl;
    cout << "                        ####################################################################################################################   " << endl << endl;
    Sleep(7000);
    cout<<endl;
    
    cout << "Aceptas las condiciones?...       presione----[intro]---Si aceptas jejeje"<<endl;
    cin.get(); // Esperar a que el usuario presione Enter
    system("cls"); // Limpiar la pantalla después de que el usuario presione Enter
}

// Función para guardar las pistas y descripciones en un archivo de texto
void guardarCriaturasEnArchivo(const vector<string> &descripciones, const vector<string> &nombres, const vector<string> &pistas)
{
    ofstream archivo("criaturas.txt");

    if (archivo.is_open())
    {
        for (size_t i = 0; i < descripciones.size(); ++i)
        {
            archivo << "Descripción: " << descripciones[i] << endl;
            archivo << "Nombre: " << nombres[i] << endl;
            archivo << "Pista: " << pistas[i] << endl << endl;
        }

        archivo.close();
        cout << "Las criaturas se han guardado en el archivo 'criaturas.txt'" << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo para guardar las criaturas" << endl;
    }
}

// Función para inicializar los vectores de descripciones, nombres y pistas de criaturas
void inicializarCriaturas(vector<string> &descripciones, vector<string> &nombres, vector<string> &pistas)
{
    descripciones =
        {
            "Un reptil gigante que escupe fuego",                                                                                                                                                                      // 1
            "Un ave que renace de sus cenizas",                                                                                                                                                                        // 2
            "Una criatura pequena y magica con alas",                                                                                                                                                                  // 3
            "Un ser humanoide que habita en bosques",                                                                                                                                                                  // 4
            "Una criatura que petrifica con la mirada",                                                                                                                                                                // 5
            "Un ave gigante con pico de aguila",                                                                                                                                                                       // 6
            "Un ser compuesto de varios animales",                                                                                                                                                                     // 7
            "Un caballo con alas",                                                                                                                                                                                     // 8
            "Ser que tiene una pelicula en Dreamworks y posee un burro",                                                                                                                                               // 9
            "Humano con cuerpo de caballo",                                                                                                                                                                            // 10
            "humanoides que viven en el agua",                                                                                                                                                                         // 11
            "Criatura con apariencia de toro",                                                                                                                                                                         // 12
            "Perro de tres cabezas que escupe fuego ",                                                                                                                                                                 // 13
            "Hijo de loki con apariencia de lobo",                                                                                                                                                                     // 14
            "Pulpo gigante",                                                                                                                                                                                           // 15
            "La serpiente del mundo",                                                                                                                                                                                  // 16
            "Ser que se encarga de la herreria",                                                                                                                                                                       // 17
            "Mujer bella con alas",                                                                                                                                                                                    // 18
            "Es la reencarnacion de Adan en serpiente ",                                                                                                                                                               // 19
            "Resultado de una union antinatural entre seres malignos de la naturaleza y mujeres",                                                                                                                      // 20
            "Era un lobo que perseguia a Mani en la mitologia nordica",                                                                                                                                                // 21
            "Era un lobo que perseguia el Sol en la mitologia nordica",                                                                                                                                                // 22
            "Ser humanoide con un solo ojo",                                                                                                                                                                           // 23
            "Un caballo con un cuerno magico en la frente",                                                                                                                                                            // 24
            "Criatura con cabeza humana y cuerpo de ave",                                                                                                                                                              // 25
            "Representada con cabeza de cocodrilo, patas de leon, cuerpo de leopardo y  traseros de hipopotamo",                                                                                                       // 26
            "Criatura mitologica azteca que se considera un ser sobrenatural capaz de adoptar diferentes formas",                                                                                                      // 27
            "Son espiritus femeninos de mujeres que murieron durante el parto",                                                                                                                                        // 28
            "Son criaturas mitologicas aztecas asociadas con los eclipses y otros fenomenos astronomicos",                                                                                                             // 29
            "Se le representa como una serpiente emplumada y es considerado el dios del viento y el conocimiento",                                                                                                     // 30
            "Son los espiritus que se manifiestan en el mundo real segun la cultura Japonesa",                                                                                                                         // 31
            "Son las deidades del panteon sintoista y las figuras mas importantes y respetadas de la cultura nipona",                                                                                                  // 32
            "Se trata de seres orgullosos y traviesos que viven en la montana y se dedican a secuestrar niños, gastar bromas pesadas y hacer que los monjes se pierdan en los bosques",                                // 32
            "Semejantes a una mezcla de rana y tortuga del tamano de un joven humano",                                                                                                                                 // 34
            "Son representados como figuras antropomorficas de gran tamano, con cuernos en la cabeza, afilados colmillos sobresaliendo de su boca, pieles de tigre como vestimenta y blandiendo un garrote metalico ", // 35
            "Son los dioses de la muerte de la cultura japonesa",                                                                                                                                                      // 36

        };

    nombres =
        {
            "dragon",       // 1
            "fenix",        // 2
            "hada",         // 3
            "elfo",         // 4
            "medusa",       // 5
            "grifo",        // 6
            "quimera",      // 7
            "pegaso",       // 8
            "ogro",         // 9
            "centauro",     // 10
            "sirenas",      // 11
            "minotauro",    // 12
            "cerbero",      // 13
            "fenrir",       // 14
            "kraken",       // 15
            "jormundgandr", // 16
            "enano",        // 17
            "valkiria",     // 18
            "leviatan",     // 19
            "nefilim",      // 20
            "hati",         // 21
            "skoll",        // 22
            "ciclope",      // 23
            "unicornio",    // 24
            "ba",           // 25
            "ammit",        // 26
            "nahual",       // 27
            "cihuateteo",   // 28
            "tzitzimime",   // 29
            "quetzalcoatl", // 30
            "yokai",        // 31
            "kami",         // 32
            "tengu",        // 33
            "kappa",        // 34
            "oni",          // 35
            "shinigami",    // 36

        };

    pistas =
        {
            "Tambien tiene alas y es parecido a un wyver",                                                                      // 1
            "Su cuerpo esta envuelto en llamas ",                                                                               // 2
            "Tinker Bell",                                                                                                      // 3
            "Tiene orejas puntiagudas",                                                                                         // 4
            "Su pelo es de serpientes",                                                                                         // 5
            "Hagrid lo presenta como Buckbeak a los alumnos de Hogwarts",                                                       // 6
            "vomitaba llamas y tiene cabeza de leon",                                                                           // 7
            "Su nombre tambien es parte de una aerolinea",                                                                      // 8
            "Se le llama Sherk en la pelicula",                                                                                 // 9
            "Su nombre empieza por Cen",                                                                                        // 10
            "Tiene una pelicula titulada(Mi amiga la ...)",                                                                     // 11
            "Empieza por Mino",                                                                                                 // 12
            "Su nombre es parecido al cantante de Rap venezolano",                                                              // 13
            "Se lo madreo Hulk en la pelicula Ragnarok",                                                                        // 14
            "Es el miedo de los piratas ",                                                                                      // 15
            "Hijo de loki y asesino de Thor",                                                                                   // 16
            "Son seres muy chaparros",                                                                                          // 17
            "tambien conocida por su carta de Clash Royale",                                                                    // 18
            "Tambien conocido como devorador de mundos",                                                                        // 19
            "Son parecidos a los gigantes",                                                                                     // 20
            "Mani es la luna",                                                                                                  // 21
            "Es hermano de hati",                                                                                               // 22
            "Polifemo es parte de esta raza ",                                                                                  // 23
            "¿Enserio pista? es Unicornio malo",                                                                                // 24
            "Era la parte movil e inmaterial del difunto que viajaba por el mundo de los vivos",                                // 25
            "Engullía el corazón de los difuntos pecadores para hacerlos desaparecer para siempre",                             // 26
            "Esta criatura esta asociada con la magia",                                                                         // 27
            "Vagan por la noche y pueden causar enfermedades y muerte a los vivos",                                             // 28
            "Son demonios del mal que intentan devorar al sol y a la luna durante los eclipses",                                // 29
            "Fue uno de los creadores del mundo y tuvo un papel fundamental en la creacion de los seres humanos(Es de mexico)", // 30
            "Tiene una serie de dibujos donde casan estos seres",                                                               // 31
            "Es de Japon",                                                                                                      // 32
            "Son como los duendes pero de Japon",                                                                               // 33
            "Es de la mitologia Jponesa",                                                                                       // 34
            "Tiene una skin en valorant y comienza con O",                                                                      // 35
            "Responsables de llevar las almas de los fallecidos hasta el más alla ",                                            //  36

        };

    // Guardar las criaturas en un archivo de texto
    guardarCriaturasEnArchivo(descripciones, nombres, pistas);
}

// Función para que un jugador adivine la criatura, le agregue la funcion de temporizador 
bool adivinarCriatura(int &puntuacionJugador, const string &nombreJugador, const string &nombreCriatura, bool &jugarDeNuevo)
{
    string respuesta;
    cout << "Tu respuesta fue: ";

    // Iniciar el cronómetro
    clock_t start = clock();

    // Leer la respuesta del jugador
    cin >> respuesta;

    clock_t end = clock();

    // Calcular el tiempo transcurrido en segundos
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;

    // Determinar el tiempo máximo permitido
    int tiempoMaximo = 15;
    if (respuesta == "S" || respuesta == "s")
    {
        Sleep(1000);
        tiempoMaximo = 20; 
    }

    if (elapsed_secs > tiempoMaximo)
    {
        
        if (puntuacionJugador > 0) {
            puntuacionJugador -= 1;
        }
        cout << "Te has demorado demasiado. Pierdes 1 punto." << endl;
        return false; // El jugador se ha demorado, no se evalúa la respuesta
    }

    if (respuesta == nombreCriatura)
    {
        Sleep(500);
        cout << "Respuesta correcta. Ganaste 3 puntos" << endl;
        puntuacionJugador += 3;
        Sleep(500);
        cout << "Puntuacion actual de " << nombreJugador << ": " << puntuacionJugador << " puntos" << endl;
        return true;
    }
    else if (respuesta == "terminar")
    {
        cout << "Terminando el juego..." << endl;
        jugarDeNuevo = false; // Establecer jugarDeNuevo en falso para salir del bucle principal
        return true;
    }
    else
    {
        if (puntuacionJugador > 0) {
            puntuacionJugador -= 1;
        }
        Sleep(500);
        cout << "Respuesta incorrecta. Perdiste 1 punto." << endl;
        Sleep(500);
        cout << "Puntuacion actual de " << nombreJugador << ": " << puntuacionJugador << " puntos" << endl;
        return false;
    }
}

// funcion para el sistema de compra de pistas
void comprarPista(int &puntuacionJugador, const string &nombreJugador, const string &pista)
{
    char respuesta;
    Sleep(1000);
    cout << endl;
    cout << nombreJugador << ", quieres comprar una pista por 1 punto? (S/N): ";
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's')
    {
        if (puntuacionJugador >= 1)
        {
            cout << endl;
            cout << "Pista: " << pista << endl;
            puntuacionJugador -= 1;
            Sleep(1000);
            cout << endl;
            cout << "Has comprado una pista por 1 punto. Tu puntuacion actual es: " << puntuacionJugador << endl;
        }
        else
        {
            Sleep(1000);
            cout << endl;
            cout << "lo siento, necesitas 1 punto o mas para comprar una pista." << endl;
        }
    }
}

// Función para llevar el seguimiento de las puntuaciones de los jugadores
void actualizarPuntuaciones(int &puntuacionJugador, bool respuestaCorrecta)
{
    if (respuestaCorrecta)
    {
        puntuacionJugador += 2;
    }
}

// minuscula
void tolower(string &texto)
{
    for (char &c : texto)
    {
        c = tolower(c);
    }
}

// mayuscula
void toupper(string &texto)
{
    for (char &c : texto)
    {
        c = toupper(c);
    }
}

// Función para obtener un índice aleatorio no repetido
int obtenerIndiceAleatorioNoRepetido(int maximo, vector<int> &indicesUtilizados)
{
    int indiceAleatorio;
    bool repetido;

    do
    {
        indiceAleatorio = randomNumber(0, maximo - 1);
        repetido = false;

        for (int indice : indicesUtilizados)
        {
            if (indice == indiceAleatorio)
            {
                repetido = true;
                break;
            }
        }
    } while (repetido);

    indicesUtilizados.push_back(indiceAleatorio);
    return indiceAleatorio;
}

//Creacion del cronometro
void cronometro(const string &nombreJugador, const string &nombreCriatura)
{
    cout << "Tienes 15 segundos para responder o copiar 'terminar' para finalizar..." << endl;
    for (int i = 15; i > 0; --i)
    {
        cout << i << " ";
        Sleep(1000); // Espera 1 segundo
    }
    cout << endl;

    if (nombreCriatura != "")
    {
        Sleep(1000);
        cout << "La criatura era: " << nombreCriatura << endl;
        Sleep(1000);
    }
}

//bobada 1
void mostrarBarraProgreso(int progreso) {
    cout << "Progreso: ";
    for (int i = 0; i < progreso / 10; ++i) {
        cout << "|";
    }
    cout << " " << progreso << "%" << endl;
}

//PRINCIPAL
void juego1()
{   
    string name1;
    cout << "Bienvenido jugador(a) #1, por favor ingresa tu nombre: ";
    getline(cin, name1);
    cout << endl;
    Sleep(1000);

    string name2;
    cout << "Bienvenido jugador(a) #2, por favor ingresa tu nombre: ";
    getline(cin, name2);
    Sleep(1000);
    cout << endl;
    Sleep(1000);
    cout << endl
         << endl
         << "                                                              QUE COMIENZE EL JUEGO!!!                        " << endl
         << endl;

    // Inicializar el generador de números aleatorios
    srand(time(0));

    // Vectores de descripciones, nombres y pistas de criaturas
    vector<string> descripciones;
    vector<string> nombres;
    vector<string> pistas;
    vector<int> indicesUtilizados;

    // BUCLE PRINCIPAL DEL JUEGO, Le agregue al bucle las funciones del cronometro
     bool jugarDeNuevo = true;
    while (jugarDeNuevo)
    {
        // Puntuaciones iniciales de los jugadores
        int puntuacionJugador1 = 0;
        int puntuacionJugador2 = 0;
        inicializarCriaturas(descripciones, nombres, pistas);

        while (puntuacionJugador1 < 10 && puntuacionJugador2 < 10)
        {
            // Turno del Jugador 1
            Sleep(1000);
            cout << endl;
            toupper(name1);
            cout << "TURNO DE " << name1 << endl;
            cout << endl;
            int indiceAleatorio = obtenerIndiceAleatorioNoRepetido(descripciones.size(), indicesUtilizados);
            Sleep(500);
            cout << "Que criatura crees que es ---> ?  " << descripciones[indiceAleatorio] << endl;

            // Comprar pista Jugador 1
            tolower(name1);
            comprarPista(puntuacionJugador1, name1, pistas[indiceAleatorio]);

            // Llamar función de cronómetro
            cronometro(name1, nombres[indiceAleatorio]);

            // Llamar función de adivinanza
            tolower(name1);
            bool respuestaCorrectaJugador1 = adivinarCriatura(puntuacionJugador1, name1, nombres[indiceAleatorio], jugarDeNuevo);
            if (!jugarDeNuevo)
            {
                break;
            }

            // Verificar si Jugador 1 ha ganado
            if (puntuacionJugador1 >= 10)
            {
                break; // Salir del bucle si Jugador 1 ha ganado
            }

            // Turno del Jugador 2
            Sleep(1000);
            cout << endl;
            toupper(name2);
            cout << "TURNO DE " << name2 << endl;
            cout << endl;
            indiceAleatorio = obtenerIndiceAleatorioNoRepetido(descripciones.size(), indicesUtilizados);
            Sleep(1000);
            cout << "que criatura crees que es ---> " << descripciones[indiceAleatorio] << endl;

            // Comprar pista Jugador 2
            tolower(name2);
            comprarPista(puntuacionJugador2, name2, pistas[indiceAleatorio]);

            // Llamar función de cronómetro
            cronometro(name2, nombres[indiceAleatorio]);

            // llamar función de adivinanza
            tolower(name2);
            bool respuestaCorrectaJugador2 = adivinarCriatura(puntuacionJugador2, name2, nombres[indiceAleatorio], jugarDeNuevo);
            if (!jugarDeNuevo)
            {
                break;
            }

            // Verificar si Jugador 2 ha ganado
            if (puntuacionJugador2 >= 10)
            {
                break; // Salir del bucle si Jugador 2 ha ganado
            }
        }

        // Mostrar puntos totales de cada jugador
        cout << endl;
        Sleep(1000);
        cout << "Puntos totales de " << name1 << ": " << puntuacionJugador1 << endl;
        cout << endl;
        cout << "Puntos totales de " << name2 << ": " << puntuacionJugador2 << endl;

        // Determinar al ganador
        if (puntuacionJugador1 > puntuacionJugador2)
        {
            Sleep(1000);
            cout << endl;
            toupper(name1);
            cout << name1 << " ES EL GANADOR" << endl;
        }
        else if (puntuacionJugador1 < puntuacionJugador2)
        {
            cout << endl;
            toupper(name2);
            cout << name2 << " ES EL GANADOR" << endl;
        }
        else
        {
            cout << endl;
            cout << "Ha habido un empate" << endl;
        }
        Sleep(1000);

        vector<Jugador> jugadores;
        jugadores.push_back({name1, puntuacionJugador1});
        jugadores.push_back({name2, puntuacionJugador2});

        guardarPuntuaciones(jugadores);
    

        cout << "Deseas jugar de nuevo? (S/N): ";
        char opcionJugarDeNuevo;
        cin >> opcionJugarDeNuevo;
        jugarDeNuevo = (opcionJugarDeNuevo == 'S' || opcionJugarDeNuevo == 's');
        int progreso = 0;

        while (progreso <= 100) {
        mostrarBarraProgreso(progreso);
        progreso += 10;
        Sleep(500); 
        }
    
    // Después de determinar al ganador del juego...
  
    
    }
    Sleep(1000);
    cout << "                                                       Gracias por jugar" << endl;
} 


int main() {
    
    // Inicializar el generador de números aleatorios
    srand(time(0));

    // Vectores de descripciones, nombres y pistas de criaturas
    vector<string> descripciones;
    vector<string> nombres;
    vector<string> pistas;

    // Inicializar criaturas y guardarlas en un archivo
    inicializarCriaturas(descripciones, nombres, pistas);

    int juego;

    while (true) {
        cout << "¿Que juego desea jugar? Ingrese 1 para 'adivina criaturas' y 2 para 'una historia' (1/2): ";
        cin >> juego;
        cin.ignore();

        if (juego == 1) {
            mostrarReglasYInstrucciones();
            juego1();
            break;
        }
        else if (juego == 2) {
            Sleep(1000);
            cout << "Lo lamento, este código esta en reparaciones..." << endl;
        }
        else {
            cout << "Opcion invalida. Por favor, ingrese 1 o 2." << endl;
        }
    }

    return 0;
}

