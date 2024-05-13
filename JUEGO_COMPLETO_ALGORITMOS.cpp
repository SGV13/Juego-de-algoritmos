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
using namespace std;

    //probabilidad de no encontrar ningún monstruo {1,2,3,4,5} (Descanso, recuperas un poco de vida)
    //probabilidad de encontrarte un objeto útil {6,7,8,9}
    //probabilidad de encontrar un duende {10,11,12,13}
    //probabilidad de encontrar una hada {14,15} (Duplicas tu fuerza)
    //probabilidad de encontrar un orco {16,17} 
    //probabilidad de encontrar un cofre útil {18,19,20}
    //probabilidad de encontrar un slime{21,22}
    //probabilidad de encontrar un mimic {23,24}
    //probabilidad de encontrarte un demonio {25}
    //probabilidad de encontrarte unos bandidos {26, 27}
    //probabilidad de porbabilidad de encontrar un cofre tranmpa {28,29,30}
    int pp = 5, pv = 100, p = 1;
    string c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, ca12, ca13, ca25, ca26, ca27, poc;
    int k, j = 0, pos, cantidad = 30, a;
    int probmon[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    void eliminarpos(int pos) {
        for (int k = pos - j; k < 30 - j; k++)
        {
            j += 1;
            probmon[k] = probmon [k+1];
        }
        cantidad -= 1;
    }
// Función para obtener un número aleatorio entre min y max
int randomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
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
}

// Función para que un jugador adivine la criatura
bool adivinarCriatura(int &puntuacionJugador, const string &nombreJugador, const string &nombreCriatura, bool &jugarDeNuevo)
{
    string respuesta;
    cout << "Ingresa tu respuesta o escribe 'terminar' para finalizar el juego: ";
    cin >> respuesta;

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
        Sleep(500);
        cout << "Respuesta incorrecta. Perdiste 1 punto." << endl;
        puntuacionJugador -= 1;
        Sleep(500);
        cout << "Puntuacion actual de " << nombreJugador << ": " << puntuacionJugador << " puntos" << endl;
        return false;
    }
clock_t start = clock(); // Guardar el tiempo de inicio
string respuesta;
cout << "Ingresa tu respuesta o escribe 'terminar' para finalizar el juego: ";
cin >> respuesta;
clock_t end = clock(); // Guardar el tiempo de fin


double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;

if (elapsed_secs > 20)
{
    
    puntuacionJugador -= 1;
    cout << "Te has demorado demasiado. Pierdes 1 punto." << endl;
}

}

// funcion para el sistema de compra de pistas
void comprarPista(int &puntuacionJugador, const string &nombreJugador, const string &pista)
{
    char respuesta;
    Sleep(500);
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
            Sleep(500);
            cout << endl;
            cout << "Has comprado una pista por 1 punto. Tu puntuacion actual es: " << puntuacionJugador << endl;
        }
        else
        {
            Sleep(500);
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

    cout << "                                       Bienvenidos " << name1 << " y " << name2 << " al juego de adivinar criaturas mitologicas" << endl
         << endl;
    cout << "                        Primero las reglas...no?  " << endl
         << endl;
    cout << "                        ####################################################################################################################   " << endl;
    cout << "                        ##                                                                                                                ##   " << endl;
    cout << "                        ##   REGLA 1: A la hora de responder a la descripcion, deberas hacerlo en minuscula y sin tildes                  ##   " << endl;
    cout << "                        ##   REGLA 2: Cuando desees la pista, deberas indicar la respuesta con una S o N, siendo S aceptarla y N rechazar ##" << endl;
    cout << "                        ##   REGLA 3: No puedes buscar la respuesta o pedirsela a alguien mas                                             ##" << endl;
    cout << "                        ##   REGLA 4: Deberas respetar el turno, el juego indicara a quien le tocara responder                            ##" << endl;
    cout << "                        ##                                                                                                                ##" << endl;
    cout << "                        ####################################################################################################################   " << endl
         << endl;
    Sleep(5000);
    cout << endl;
    cout << "                        COMO FUNCIONA EL JUEGO                                                                                       " << endl
         << endl;
    cout << "                        ####################################################################################################################   " << endl;
    cout << "                        ##                                                                                                                ##   " << endl;
    cout << "                        ##   1: Todos los jugadores comenzaran con 0 puntos, dependera de ellos si suman o restan                         ##   " << endl;
    cout << "                        ##   2: Cada respuesta correcta te sumara TRES puntos                                                             ##" << endl;
    cout << "                        ##   3: La pista costara 1 punto, se te habilitara cuando tengas los puntos suficientes para usarla               ##" << endl;
    cout << "                        ##   4: Cualquier jugador que escriba terminar en su respuesta acabara el juego inmediatamente                    ##" << endl;
    cout << "                        ##   5: Cuando falles una respuesta perderas 1 punto                                                              ##" << endl;
    cout << "                        ##   6: El primero en llegar a 10 puntos gana, se mostrara la puntuacion de cada uno y el ganador                 ##" << endl;
    cout << "                        ##                                                                                                                ##" << endl;
    cout << "                        ####################################################################################################################   " << endl;
    Sleep(5000);

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

    // BUCLE PRINCIPAL DEL JUEGO
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
            cout << "Que criatura crees que es ---> " << descripciones[indiceAleatorio] << endl;

            // Comprar pista Jugador 1
            tolower(name1);
            comprarPista(puntuacionJugador1, name1, pistas[indiceAleatorio]);

            // Llamar funcion de adivinanza
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
            Sleep(500);
            cout << "que criatura crees que es ---> " << descripciones[indiceAleatorio] << endl;

            // Comprar pista Jugador 2
            tolower(name2);
            comprarPista(puntuacionJugador2, name2, pistas[indiceAleatorio]);

            // llamar funcion de adivinanza
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
        cout<< endl;
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

        cout << "Deseas jugar de nuevo? (S/N): ";
        char opcionJugarDeNuevo;
        cin >> opcionJugarDeNuevo;
        jugarDeNuevo = (opcionJugarDeNuevo == 'S' || opcionJugarDeNuevo == 's');
    }
    Sleep(1000);
    cout << "                                                       Gracias por jugar" << endl;
}
void juego2()
{
    cout<<"Eres un joven humano al que se le ha adjudicado la tarea de derrotar una bestia que esta aterrorizando tu pueblo"<<endl;
    cout<<"Tendrás que valerte por ti mismo y conseguirlo, mucha suerte, la vas a necesitar, enserio"<<endl;
    cout<<"Solo estás equipado con una pequeña espada oxidada y una armadura ligera de cuero, ten cuidado de lo que eliges, cualquier paso en falso te podría llevar a la muerte"<<endl;
    cout<<"Tienes solo 100 de vida, si esta llega a 0... el viaje acabó"<<endl;
    cout<<"Puedes recuperar 20 de salud con pociones, por ahora solo tienes una, tendras que conseguir el resto"<<endl;
    cout<<"Si los efectos de curacion exceden los 100 de vida al utilizarse, el efecto se reducirá en 1/4"<<endl;
    
    srand(time(NULL));
    int i;
    while(pv>0)
    {   
        cout<<"En este momento posees "<<p<<" pociones"<<", "<<pv<<" de vida y "<<pp<<" de poder"<<endl;
        cout<<"¿Deseas tomar una pocion de recuperación? (si) (no)"<<endl;
        cin>>poc;
        if (poc == "si")
        {
            if (pv<90)
            {
                pv = pv + 12;;
            }
            if(pv>=90)
            {
                pv = pv + (12/4);
            }
        }
        if (poc == "no")
        {
            cout<<"continúas tu viaje"<<endl;
        }
        srand(time(NULL));
        i = 1 + rand() % (30 + 1 - 1);
        //Aquí comienza tu viaje, tendras que pasar por todos los escenarios propuestos
        if((i == 1)) 
        {
            //No te encontraste ningún monstruo
            cout<<"Después de caminar un rato, te encuentras con un bello paramo"<<'\n';
            cout<<'\n';
            cout<<"Debes elegir si quedarte a descansar o seguir con tu camino"<<'\n';
            cout<<'\n';
            cout<<"¿descansar o seguir? (escribir en minuscula)"<<'\n';
            cin>>c1;
            
            if(c1 == "descansar")
            {
                cout<<"Decides descansar y admirar el bello páramo que tienes en frente (recuperas 12 puntos de vida)";
                if (pv>100)
                {
                    pv = pv + (12/4);
                }
                if (pv<100)
                {
                    pv = pv + 12;
                }
            }
            if(c1 == "seguir")
            {
                cout<<"Decides no perder el tiempo y seguir con tu camino (pierdes 2 de vida debido al cansancio)"<<endl;
                pv = pv - 2;
            }
            if((c1!="seguir")&&(c1!="descansar"))
            {
                cout<<"No intentes pasarte de listo (pierdes 5 de vida por razones desconocidas)"<<endl;
                pv = pv - 5;
            }
            eliminarpos(i);
        }
        if((i == 2)) 
        {
            //No te encontraste ningún monstruo
            cout<<"Después de caminar un rato, te encuentras con un bello paramo"<<'\n';
            cout<<'\n';
            cout<<"Debes elegir si quedarte a descansar o seguir con tu camino"<<'\n';
            cout<<'\n';
            cout<<"¿descansar o seguir? (escribir en minuscula)"<<'\n';
            cin>>c2;
            
            if(c2 == "descansar")
            {
                cout<<"Decides descansar y admirar el bello páramo que tienes en frente (recuperas 10 puntos de vida)"<<endl;
                if (pv>88)
                {
                    pv = pv + (12/4);
                }
                if (pv<88)
                {
                    pv = pv + 12;
                }
            }
            if(c2 == "seguir")
            {
                cout<<"Decides no perder el tiempo y seguir con tu camino (pierdes 2 de vida debido al cansancio)"<<endl;
                pv = pv - 2;
            }
            if((c2!="seguir")&&(c2!="descansar"))
            {
                cout<<"No intentes pasarte de listo (pierdes 5 de vida por razones desconocidas)"<<endl;
                pv = pv - 5;
            }
            eliminarpos(i);
        }
        if((i == 3)) 
        {
            //No te encontraste ningún monstruo
            cout<<"Después de caminar un rato, te encuentras con un bello paramo"<<'\n';
            cout<<'\n';
            cout<<"Debes elegir si quedarte a descansar o seguir con tu camino"<<'\n';
            cout<<'\n';
            cout<<"¿descansar o seguir? (escribir en minuscula)"<<'\n';
            cin>>c3;
            
            if(c3 == "descansar")
            {
                cout<<"Decides descansar y admirar el bello páramo que tienes en frente (recuperas 10 puntos de vida)"<<endl;
                if (pv>88)
                {
                    pv = pv + (12/4);
                }
                if (pv<88)
                {
                    pv = pv + 12;
                }
            }
            if(c3 == "seguir")
            {
                cout<<"Decides no perder el tiempo y seguir con tu camino (pierdes 2 de vida debido al cansancio)"<<endl;
                pv = pv - 2;
            }
            if((c3!="seguir")&&(c3!="descansar"))
            {
                cout<<"No intentes pasarte de listo (pierdes 5 de vida por razones desconocidas)"<<endl;
                pv = pv - 5;
            }
            eliminarpos(i);
        }
        if((i == 4)) 
        {
            //No te encontraste ningún monstruo
            cout<<"Después de caminar un rato, te encuentras con un bello paramo"<<'\n';
            cout<<'\n';
            cout<<"Debes elegir si quedarte a descansar o seguir con tu camino"<<'\n';
            cout<<'\n';
            cout<<"¿descansar o seguir? (escribir en minuscula)"<<'\n';
            cin>>c4;
            
            if(c4 == "descansar")
            {
                cout<<"Decides descansar y admirar el bello páramo que tienes en frente (recuperas 10 puntos de vida)"<<endl;
                if (pv>88)
                {
                    pv = pv + (12/4);
                }
                if (pv<88)
                {
                    pv = pv + 12;
                }
            }
            if(c4 == "seguir")
            {
                cout<<"Decides no perder el tiempo y seguir con tu camino (pierdes 2 de vida debido al cansancio)"<<endl;
                pv = pv - 2;
            }
            if((c4!="seguir")&&(c4!="descansar"))
            {
                cout<<"No intentes pasarte de listo (pierdes 5 de vida por razones desconocidas)"<<endl;
                pv = pv - 5;
            }
            eliminarpos(i);
        }
        if((i == 5)) 
        {
            //No te encontraste ningún monstruo
            cout<<"Después de caminar un rato, te encuentras con un bello paramo"<<'\n';
            cout<<'\n';
            cout<<"Debes elegir si quedarte a descansar o seguir con tu camino"<<'\n';
            cout<<'\n';
            cout<<"¿descansar o seguir? (escribir en minuscula)"<<'\n';
            cin>>c5;
            
            if(c5 == "descansar")
            {
                cout<<"Decides descansar y admirar el bello páramo que tienes en frente (recuperas 10 puntos de vida)"<<endl;
                if (pv>88)
                {
                    pv = pv + (12/4);
                }
                if (pv<88)
                {
                    pv = pv + 12;
                }
            }
            if(c5 == "seguir")
            {
                cout<<"Decides no perder el tiempo y seguir con tu camino (pierdes 2 de vida debido al cansancio)"<<endl;
                pv = pv - 2;
            }
            if((c5!="seguir")&&(c5!="descansar"))
            {
                cout<<"No intentes pasarte de listo (pierdes 5 de vida por razones desconocidas)"<<endl;
                pv = pv - 5;
            }
            eliminarpos(i);
        }
        //Objetos útiles
        if(i==6)
        {
            cout<<"Luego de caminar un rato, encuentras una espada mucho mejor que la que tienes actualmente"<<endl;
            cout<<"Tu nivel de poder aumenta 15 puntos";
            pp = pp + 15;
            eliminarpos(i);
        }
        if(i==7)
        {
            cout<<"Luego de caminar un rato, encuentras una armadura mucho mejor que la que tienes actualmente"<<endl;
            cout<<"Tu nivel de poder aumenta 15 puntos";
            pp = pp + 15;
            eliminarpos(i);
        }
        if(i==8)
        {
            cout<<"Luego de caminar un rato, encuentras unas botas mucho mejor que la que tienes actualmente"<<endl;
            cout<<"Tu nivel de poder aumenta 10 puntos";
            pp = pp + 10;
            eliminarpos(i);
        }
        if(i==9)
        {
            cout<<"Luego de caminar un rato, encuentras un amuleto de la suerte"<<endl;
            cout<<"Tu nivel de poder aumenta 10 puntos";
            pp = pp + 10;
            eliminarpos(i);
        }
        //Te encontraste un duende
        if (i == 10)
        {
           cout<<"Oh, has encontrado a un duende. Se ve algo débil y puedes atacarlo por sorpresa. Piensa bien que harás."<<endl;
           cout<<"(atacar),(escapar),(razonar)";
           cin>>c7;
           if(c7 == "atacar")
           {
               cout<<"Decides atacar al duende sin piedad, a este no le da tiempo de reaccionar y logras darle un golpe mortal sin mucho esfuerzo"<<endl;
               cout<<"El duende tenía una pocion de salúd y algunos objetos útiles (pociones + 1, nivel de poder + 5 )"<<endl;
               pp = pp + 5;
               p = p + 1;
           }
           if(c7 == "escapar")
           {
               cout<<"Decides seguír con tu camino, no vale la pena el riesgo...";
           }
           if(c7 == "razonar")
           {
               cout<<"¿Enserio intentaste razonar con un duende?"<<endl;
               cout<<"El duende suelta un grito asqueroso y se abalanza sobre tí clavandote su pequeña daga en tu pierna, no te queda otra opcion mas que huír"<<endl;
               cout<<"pierdes 20 puntos de salud";
               pv = pv - 20;
           }
           if((c7!="atacar")&&(c7!="escapar")&&(c7!="razonar"))
           {
               cout<<"No intentes pasarte de listo, has lo que se te ordena, pierdes 20 de salud"<<endl;
               pv = pv - 20;
           }
           eliminarpos(i);
        }   
        if (i == 10)
        {
           cout<<"Oh, has encontrado a un duende. Se ve algo débil y puedes atacarlo por sorpresa. Piensa bien que harás."<<endl;
           cout<<"(atacar),(escapar),(razonar)";
           cin>>c8;
           if(c8 == "atacar")
           {
               cout<<"Decides atacar al duende sin piedad, a este no le da tiempo de reaccionar y logras darle un golpe mortal sin mucho esfuerzo"<<endl;
               cout<<"El duende tenía una pocion de salúd y algunos objetos útiles (pociones + 1, nivel de poder + 5 )";
               p = p + 1;
               pp = pp + 5;
           }
           if(c8 == "escapar")
           {
               cout<<"Decides seguír con tu camino, no vale la pena el riesgo...";
           }
           if(c8 == "razonar")
           {
               cout<<"¿Enserio intentaste razonar con un duende?"<<endl;
               cout<<"El duende suelta un grito asqueroso y se abalanza sobre tí clavandote su pequeña daga en tu pierna, no te queda otra opcion mas que huír"<<endl;
               cout<<"pierdes 20 puntos de salud";
               pv = pv - 20;
           }
           if((c8!="atacar")&&(c8!="escapar")&&(c8!="razonar"))
           {
               cout<<"No intentes pasarte de listo, has lo que se te ordena, pierdes 20 de salud"<<endl;
               pv = pv - 20;
           }
           eliminarpos(i);
        }   
        if(i == 12)
        {
            cout<<"Oh, has encontrado un duende. Parece tener unos arapos mal puestos y una cimitarra bastante filosa, parece estar devorando el cadaver de una dama"<<endl;
            cout<<"Este enemigo no parece del todo débil, piensa bien lo que harás"<<endl;
            cout<<"(atacar),(escapar),(razonar)";
            cin>>c12;
            if(c12 == "atacar")
            {
                cout<<"Decides atacar rapidamente para no darle oportunidad. Logras darle un buen golpe dejandolo incapacitado, sin embargo este logra darte un feo corte en el pecho"<<endl;
                cout<<"Pierdes 10 puntos de vida, el duende está agonizando en el suelo ¿que harás? (Darle el golpe de gracia (matarlo), (perdonarle la vida(dejarlo)))";
                pv = pv - 10;
                cin>>ca12;
                if(ca12 == "matarlo")
                {
                    cout<<"Liberas al pobre duende de su sufiremiento al aplastar su cabeza con tu pierna herida. Tomas la cimitarra del duende (Obtienes 10 de poder)";
                    pp = pp + 10;
                }
                if(ca12 == "dejarlo")
                {
                    cout<<"Dejas al duende agonizando y te retiras adolorido";
                }
                if ((ca12 != "matarlo")&&(ca12 != "dejarlo"))
                {
                    cout<<"No te pases de listo, te vas y pierdes 10 puntos de vida"<<endl;
                    pv = pv - 10;
                }
            }
            if(c12=="escapar")
            {
                cout<<"Decides huír del lugar. No vale el riesgo"<<endl;
            }
            if(c12=="razonar")
            {
                cout<<"Intentas entablar una conversacion con el duende, pero este te mira incredulo. El duende saca una pocion de sus arapos (pociones + 1), la deja en el suelo y sale corriendo"<<endl;
                cout<<"Que criaturas mas extrañas..."<<endl;
                p = p + 1;
            }
            if((c12!="atacar")&&(c12!="escapar")&&(c12 == "razonar"))
            {
                cout<<"No te pases de listo (pierdes 10 de salúd)"<<endl;
                pv = pv - 20;
            }
            eliminarpos(i);
        }
        if(i == 13)
        {
            cout<<"Oh, has encontrado un duende. Parece tener unos arapos mal puestos y una cimitarra bastante filosa, parece estar devorando el cadaver de una dama"<<endl;
            cout<<"Este enemigo no parece del todo débil, piensa bien lo que harás"<<endl;
            cout<<"(atacar),(escapar),(razonar)"<<endl;
            cin>>c13;
            if(c13 == "atacar")
            {
                cout<<"Decides atacar rapidamente para no darle oportunidad. Logras darle un buen golpe dejandolo incapacitado, sin embargo este logra darte un feo corte en el pecho"<<endl;
                cout<<"Pierdes 10 puntos de vida, el duende está agonizando en el suelo ¿que harás? (Darle el golpe de gracia (matarlo), (perdonarle la vida(dejarlo)))"<<endl;
                pv = pv - 10;
                cin>>ca13;
                if(ca13 == "matarlo")
                {
                    cout<<"Liberas al pobre duende de su sufiremiento al aplastar su cabeza con tu pierna herida. Tomas la cimitarra del duende (Obtienes 10 de poder)"<<endl;
                    pp = pp + 10;
                }
                if(ca13 == "dejarlo")
                {
                    cout<<"Dejas al duende agonizando y te retiras adolorido"<<endl;
                }
                if ((ca13 != "matarlo")&&(ca13 != "dejarlo"))
                {
                    cout<<"No te pases de listo, te vas y pierdes 10 puntos de vida"<<endl;
                    pv = pv - 10;
                }
            }
            if(c13=="escapar")
            {
                cout<<"Decides huír del lugar. No vale el riesgo"<<endl;
            }
            if(c13=="razonar")
            {
                cout<<"Intentas entablar una conversacion con el duende, pero este te mira incredulo. El duende saca una pocion de sus arapos, la deja en el suelo y sale corriendo"<<endl;
                cout<<"Que criaturas mas extrañas..."<<endl;
                p = p + 1;
            }
            if((c13!="atacar")&&(c13!="escapar")&&(c13 == "razonar"))
            {
                cout<<"No te pases de listo (pierdes 10 de salúd por razones desconocidas)"<<endl;
                pv = pv - 10;
            }
            eliminarpos(i);
        }
        if(i == 14)
        {
            cout<<"Te has encontrado un hada, sus alas son están corroidas y teñidas de un negro azabache. ¿Que harás?"<<endl;
            cout<<"(atacar), (huir), (razonar)"<<endl;
            cin>>c14;
            if (c14 == "atacar")
            {
                cout<<"!MUERE CRIATURA DEL MAL...¡ (gritas sin darle tiempo a la hada de reaccionar)"<<endl;
                cout<<"El hada deja atrás un poco de polvo el cual usas para hacer una pocion de vida (pociones + 1)"<<endl;
                p = p + 1;
            }
            if (c14 == "huir")
            {
                cout<<"Decides no  hacer nada, simplemente te vas"<<endl;
            }
            if(c14 == "razonar")
            {
                cout<<"Sin darte tiempo de pronunciar ni una palabra, el hada te lanza una maldicion. (pierdes 30 de vida y 10 puntos de fuerza)"<<endl;
                pv = pv - 30;
                pp = pp + 10;
            }
            if ((c14 != "atacar")&&(c14 != "huir")&&(c14 != "razonar"))
            {
                cout<<"No intentes pasarte de listo"<<endl;
            }
            eliminarpos(i);
        }
        if(i == 15)
        {
            cout<<"Te has encontrado con un hada. Sus hermosas alas están combinadas en decenas de colores. Que harás?"<<endl;
            cout<<"(atacar),(huir),(razonar)"<<endl;
            cin>>c15;
            if(c15 == "atacar")
            {
                cout<<"!MUERE CRIATURA DEL MAL...¡ (gritas sin darle tiempo a la hada de reaccionar)"<<endl;
                cout<<"El hada deja atrás un poco de polvo el cual usas para hacer una pocion de vida (pociones + 1)"<<endl;
                p = p + 1;
            }
            if(c15 == "huir")
            {
                cout<<"Decides no  hacer nada, simplemente te vas"<<endl;
            }
            if(c15 == "razonar")
            {
                cout<<"La hermosa hada te mira con ojos brillantes, te sonríe y se va volando tranquilamente"<<endl;
                cout<<"El hada te ha bendecido, ganas 40 puntos de fuerza"<<endl;
                pp = pp + 40;
            }
            if ((c15 != "atacar")&&(c15 != "huir")&&(c15 != "razonar"))
            {
                cout<<"No intentes pasarte de listo, pierdes 20 de vida por razónes desconocidas"<<endl;
                pv = pv - 20;
            }
            eliminarpos(i);
        }
        if(i == 16)
        {
            cout<<"Te has encontrado con un orco, ten mucho cuidado, son criaturas bastante poderosas (50 de poder) en este momento posees "<<pp<<" de poder, piensa bien en lo que haras"<<endl;
            cout<<"(atacar)(huir)(razonar)"<<endl;
            cin>>c16;
            if(c16 == "atacar")
            {
                if (pp>50)
                {
                    cout<<"Corres hacia el orco rapidamente y clavas tu arma en su cuello, logras darle de baja sin muchos problemas"<<endl;
                    cout<<"(pociones + 1)"<<endl;
                    p = p + 1;
                }
                if ((pp<=50)&&(pp>45))
                {
                    cout<<"Tomas a el orco por sorpresa y después de una encarnizada batalla logras ganarle al orco por muy poco, te encuentras muy herido (pierdes 40 de vida)"<<endl;
                    pv = pv - 40;
                }
                if(pp<45)
                {
                    cout<<"El orco te aplasta facilmente con su enorme brazo... fin del viaje..."<<endl;
                    pv = 0;
                }
            }
            if(c16 == "huir")
            {
                cout<<"Decides huir... no vale el riesgo"<<endl;
            }
            if(c16 == "razonar")
            {
                cout<<"Intentas hablar con el orco, pero este te responde *H-Humano... sabroso...*"<<endl;
                cout<<"No te queda de otra mas que luchar"<<endl;
                if (pp>50)
                {
                    cout<<"Corres hacia el orco rapidamente y clavas tu arma en su cuello, logras darle de baja sin muchos problemas"<<endl;
                    cout<<"(pociones + 1)"<<endl;
                    p = p + 1;
                }
                if ((pp<=50)&&(pp>45))
                {
                    cout<<"Tomas a el orco por sorpresa y después de una encarnizada batalla logras ganarle al orco por muy poco, te encuentras muy herido (pierdes 40 de vida)"<<endl;
                    pv = pv - 40;
                }
                if(pp<45)
                {
                    cout<<"El orco te aplasta facilmente con su enorme brazo... fin del viaje..."<<endl;
                    pv = 0;
                }
            }
            if((c16!="atacar")&&(c16!="huir")&&(c16!="razonar"))
            {
                cout<<"No intentes pasarte de listo, pierdes 20 puntos de vida"<<endl;
                pv = pv - 20;
            }
            eliminarpos(i);
        }
        if(i == 17)
        {
            cout<<"Te has encontrado con un orco, ten mucho cuidado, son criaturas bastante poderosas (50 de poder) en este momento posees "<<pp<<" de poder, piensa bien en lo que haras"<<endl;
            cout<<"(atacar)(huir)(razonar)"<<endl;
            cin>>c17;
            if(c17 == "atacar")
            {
                if (pp>50)
                {
                    cout<<"Corres hacia el orco rapidamente y clavas tu arma en su cuello, logras darle de baja sin muchos problemas"<<endl;
                    cout<<"(pociones + 1)"<<endl;
                    p = p + 1;
                }
                if ((pp<=50)&&(pp>45))
                {
                    cout<<"Tomas a el orco por sorpresa y después de una encarnizada batalla logras ganarle al orco por muy poco, te encuentras muy herido (pierdes 40 de vida)"<<endl;
                    pv = pv - 40;
                }
                if(pp<45)
                {
                    cout<<"El orco te aplasta facilmente con su enorme brazo... fin del viaje..."<<endl;
                    pv = 0;
                }
            }
            if(c17 == "huir")
            {
                cout<<"Decides huir... no vale el riesgo"<<endl;
            }
            if(c17 == "razonar")
            {
                cout<<"Intentas hablar con el orco, pero este te responde *H-Humano... sabroso...*"<<endl;
                cout<<"No te queda de otra mas que luchar"<<endl;
                if (pp>50)
                {
                    cout<<"Corres hacia el orco rapidamente y clavas tu arma en su cuello, logras darle de baja sin muchos problemas"<<endl;
                    cout<<"(pociones + 1)"<<endl;
                    p = p + 1;
                }
                if ((pp<=50)&&(pp>45))
                {
                    cout<<"Tomas a el orco por sorpresa y después de una encarnizada batalla logras ganarle al orco por muy poco, te encuentras muy herido (pierdes 40 de vida)"<<endl;
                    pv = pv - 40;
                }
                if(pp<45)
                {
                    cout<<"El orco te aplasta facilmente con su enorme brazo... fin del viaje..."<<endl;
                    pv = 0;
                }
            }
            if((c17 != "atacar")&&(c17 != "huir")&&(c17 != "razonar"))
            {
                cout<<"No intentes pasarte de listo, pierdes 20 puntos de vida"<<endl;
                pv = pv - 20;
            }
            eliminarpos(i);
        }
        if (i == 18)
        {
            cout<<"Te has encontrado un cofre sospechoso... puede ser un cofre real, un cofre con trampa o incluso un mimic..."<<endl;
            cout<<"(abrir)(irse) Que harás?"<<endl;
            cin>>c18;
            if(c18 == "abrir")
            {
                cout<<"Resultó ser un cofre inofensivo, tomas unos objetos útiles (+10 de poder)"<<endl;
                pp = pp + 10;
            }
            if(c18 == "irse")
            {
                cout<<"Decides retirarte... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
        }
        if (i == 19)
        {
            cout<<"Te has encontrado un cofre sospechoso... puede ser un cofre real, un cofre con trampa o incluso un mimic..."<<endl;
            cout<<"(abrir)(irse) Que harás?"<<endl;
            cin>>c19;
            if(c19 == "abrir")
            {
                cout<<"Resultó ser un cofre inofensivo, tomas unos objetos útiles (+10 de poder)"<<endl;
                pp = pp + 10;
            }
            if(c19 == "irse")
            {
                cout<<"Decides retirarte... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
        }
        if (i == 20)
        {
            cout<<"Te has encontrado un cofre sospechoso... puede ser un cofre real, un cofre con trampa o incluso un mimic..."<<endl;
            cout<<"(abrir)(irse) Que harás?"<<endl;
            cin>>c20;
            if(c20 == "abrir")
            {
                cout<<"Resultó ser un cofre inofensivo, tomas unos objetos útiles (+10 de poder)"<<endl;
                pp = pp + 10;
            }
            if(c20 == "irse")
            {
                cout<<"Decides retirarte... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
        }
        if(i == 21)
        {
            cout<<"Te has encontrado con un slime... ten mucho cuidado, es una masa de baba acida, puede causarte bastantes problemas"<<endl;
            cout<<"Que harás? (atacar)(ignorar)(huir)"<<endl;
            cin>>c21;
            if(c21=="atacar")
            {
                cout<<"Decides atacar a la baba deforme y consigues matarla sin muchos problemas"<<endl;
                cout<<"Sin embargo, algo de tu equipo se ha deshecho en sus fluidos... (pierdes 10 de poder)"<<endl;
                pp = pp - 10;
            }
            if(c21 == "ignorar")
            {
                cout<<"Decides ignorar a la criatura... el slime se abalanza hacia ti y te impregna de su asquerosa baba disolviendo muchas cosas de tu equipo (pierdes 30 de poder)"<<endl;
                pp = pp - 30;
            }
            if(c21 == "huir")
            {
                cout<<"Decides huir... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
        }
        if(i == 22)
        {
            cout<<"Te has encontrado con un slime... ten mucho cuidado, es una masa de baba acida, puede causarte bastantes problemas"<<endl;
            cout<<"Que harás? (atacar)(ignorar)(huir)"<<endl;
            cin>>c22;
            if(c22=="atacar")
            {
                cout<<"Decides atacar a la baba deforme y consigues matarla sin muchos problemas"<<endl;
                cout<<"Sin embargo, algo de tu equipo se ha deshecho en sus fluidos... (pierdes 10 de poder)"<<endl;
                pp = pp - 10;
            }
            if(c22 == "ignorar")
            {
                cout<<"Decides ignorar a la criatura... el slime se abalanza hacia ti y te impregna de su asquerosa baba disolviendo muchas cosas de tu equipo (pierdes 30 de poder)"<<endl;
                pp = pp - 30;
            }
            if(c22 == "huir")
            {
                cout<<"Decides huir... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
        }
        if (i == 23)
        {
            cout<<"Te has encontrado un cofre sospechoso... puede ser un cofre real, un cofre con trampa o incluso un mimic..."<<endl;
            cout<<"(abrir)(irse) Que harás?"<<endl;
            cin>>c23;
            if(c23 == "abrir")
            {
                cout<<"Resultó ser un mimic, una criatura realmente peligrosa. No te queda de otra mas que pelear (mimic = 40 de poder) posees "<<pp<<" de poder"<<endl;
                if (pp>40)
                {
                    cout<<"El mimic abre sus fauces y se dirige a tí, logras matarlo apenas pero terminas gravemente herido (-40 de vida)"<<endl;
                    cout<<"Te las arreglas para sobrevivir sin muchas complicaciones, tienes suerte de estar con vida"<<endl;
                    pv = pv - 40;
                }
                if ((pp<=40)&&(pp>45))
                {
                    cout<<"El mimic abre sus fauces y te devora sin mucho problema... es el fin del viaje..."<<endl;
                    pv = 0;
                }
            }
            if(c23 == "irse")
            {
                cout<<"Decides retirarte... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
        }
        if (i == 24)
        {
            cout<<"Te has encontrado un cofre sospechoso... puede ser un cofre real, un cofre con trampa o incluso un mimic..."<<endl;
            cout<<"(abrir)(irse) Que harás?"<<endl;
            cin>>c24;
            if(c24 == "abrir")
            {
                cout<<"Resultó ser un mimic, una criatura realmente peligrosa. No te queda de otra mas que pelear (mimic = 40 de poder) posees "<<pp<<" de poder"<<endl;
                if (pp>40)
                {
                    cout<<"El mimic abre sus fauces y se dirige a tí, logras matarlo apenas pero terminas gravemente herido (-40 de vida)"<<endl;
                    cout<<"Te las arreglas para sobrevivir sin muchas complicaciones, tienes suerte de estar con vida"<<endl;
                    pv = pv - 40;
                }
                if ((pp<=40)&&(pp>45))
                {
                    cout<<"El mimic abre sus fauces y te devora sin mucho problema... es el fin del viaje..."<<endl;
                    pv = 0;
                }
            }
            if(c24 == "irse")
            {
                cout<<"Decides retirarte... no vale el riesgo"<<endl;
            }
            if((c24!="abrir")&&(c24!="irse"))
            {
                cout<<"No cometas mas errores (pierdes 10 de vida)"<<endl;
                pv = pv - 10;
            }
            eliminarpos(i);
        }
        if(i == 25)
        {
            cout<<"Te has encontrado a un demonio, una criatura de la que se sabe muy poco (demonio = ??? poder ) posees "<<pp<<" poder"<<endl;
            cout<<"Que harás? (atacar) (huir) (razonar)"<<endl;
            cin>>c25;
            if (c25 == "atacar")
            {
                cout<<"decides atacar... pero antes de que la batalla empiece el demonio te corta la cabeza de un suave movimiento... El viaje terminó..."<<endl;
                pv = 0;
            }
            if(c25 == "huir"){
                cout<<"Decides alejarte del lugar rapidamente... logras pasar desapercibido..."<<endl;
            }
            if(c25 == "razonar")
            {
                cout<<"Antes de que puedas pronunciar una palabra, el demonio dice *Humano... realicemos un contrato... dame todas tus pociones y te daré el poder... entre mas tengas... mas poderoso serás...*"<<endl;
                cout<<"*Que decides?* (acepar)(negarse)"<<endl;
                cin>>ca25;
                if(ca25=="aceptar")
                {
                    cout<<"Muy bien... (murmura el demonio)"<<endl;
                    cout<<"El demonio se acerca a tí, pone una mano en tu pecho y pronuncia unas palabras en un idioma desconocido... luego toma tus pociones y se va"<<endl;
                    pp = pp + (6*p);
                    cout<<"Sientes como el poder crece en tí... tu poder actual es de "<<pp<<endl;
                    
                }
                if(ca25 == "negarse")
                {
                    cout<<"Una lastima... (murmura el demonio)"<<endl;
                    cout<<"El demonio te mira fijamente un momento y se retira sin decir nada mas..."<<endl;
                }
                if((ca25!="aceptar")&&(ca25!="negarse"))
                {
                    cout<<"No... no permitiré esya falta de respeto (murmura el demonio)"<<endl;
                    cout<<"El demonio se acerca a tí y te arranca el corazón... Fin del viaje..."<<endl;
                }
            }
            eliminarpos(i);
        }
        if(i == 26)
        {
            cout<<"Te encuentras con unos bandidos, los cuales te dicen *!Eh, tu, bastardo¡ dame dos de tus pociones o te rajo todo (bandidos = 40 poder) posees "<<pp<<" puntos de poder"<<endl;
            cout<<"¿Que haras? (huir) (pelear) (entregar)"<<endl;
            cin>>c26;
            if (c26 == "huir")
            {
                if(pp<25)
                {
                    cout<<"tratas de huir pero los bandidos de alcanzan y roban todas tus pertenencias "<<endl;
                    p = 0;
                    pp = 0;
                    cout<<"* Eso te pasa por tratar de huir, pequeña mierdecilla * (Te dice el bandido)"<<endl;
                    
                }
                if (pp>=25)
                {
                    cout<<"Lograste huír de los bandidos, ahora continúa tu viaje"<<endl;
                }
            }
            if (c26 == "pelear")
            {
                if (pp>=40)
                {
                    cout<<"Los bandidos no son rivales para tí, logras repelerlos facilmente"<<endl;
                    cout<<"Uno de los bandido se encuentra en el suelo agonizando... ¿que harás?"<<endl;
                    cout<<"(matarlo)(dejalo)"<<endl;
                    cin>>ca26;
                    if (ca26 == "matarlo")
                    {
                        cout<<"Decides darle el golpe final al bandido... para así saciar tu sed de sangre"<<endl;
                        cout<<"Te quedas con algunas de sus herramientas (+ 5 de poder)"<<endl;
                        pp = pp + 5; 
                    }
                    if (ca26 == "dejarlo")
                    {
                        cout<<"Decides tenér piedad con el bandido, le dejas una pocion de salud y te retiras (-1 pocion)"<<endl;
                        p = p - 1;
                    }
                }
                if(pp<40)
                {
                    cout<<"Tu poder no es suficiente para enfrentar a los bandidos"<<endl;
                    cout<<"Estos te despojan de todas tus pertenencias y te toman como un esclavo a la venta... El viaje ha terminado"<<endl;
                }
            }
            eliminarpos(i);
        }
        if(i == 27)
        {
            cout<<"Te encuentras con unos bandidos, los cuales te dicen *!Eh, tu, bastardo¡ dame dos de tus pociones o te rajo todo (bandidos = 40 poder) posees "<<pp<<" puntos de poder"<<endl;
            cout<<"¿Que haras? (huir) (pelear) (entregar)"<<endl;
            cin>>c27;
            if (c27 == "huir")
            {
                if(pp<25)
                {
                    cout<<"tratas de huir pero los bandidos de alcanzan y roban todas tus pertenencias "<<endl;
                    p = 0;
                    pp = 0;
                    cout<<"* Eso te pasa por tratar de huir, pequeña mierdecilla * (Te dice el bandido)"<<endl;
                    
                }
                if (pp>=25)
                {
                    cout<<"Lograste huír de los bandidos, ahora continúa tu viaje"<<endl;
                }
            }
            if (c27 == "pelear")
            {
                if (pp>=40)
                {
                    cout<<"Los bandidos no son rivales para tí, logras repelerlos facilmente"<<endl;
                    cout<<"Uno de los bandido se encuentra en el suelo agonizando... ¿que harás?"<<endl;
                    cout<<"(matarlo)(dejalo)"<<endl;
                    cin>>ca27;
                    if (ca27 == "matarlo")
                    {
                        cout<<"Decides darle el golpe final al bandido... para así saciar tu sed de sangre"<<endl;
                        cout<<"Te quedas con algunas de sus herramientas (+ 5 de poder)"<<endl;
                        pp = pp + 5; 
                    }
                    if (ca27 == "dejarlo")
                    {
                        cout<<"Decides tenér piedad con el bandido, le dejas una pocion de salud y te retiras (-1 pocion)"<<endl;
                        p = p - 1;
                    }
                }
                if(pp<40)
                {
                    cout<<"Tu poder no es suficiente para enfrentar a los bandidos"<<endl;
                    cout<<"Estos te despojan de todas tus pertenencias y te toman como un esclavo a la venta... El viaje ha terminado"<<endl;
                }
            }
            eliminarpos(i);
        }
        if (i == 28)
        {
            cout<<"Te has encontrado un cofre sospechoso... puede ser un cofre real, un cofre con trampa o incluso un mimic..."<<endl;
            cout<<"(abrir)(irse) Que harás?"<<endl;
            cin>>c20;
            if(c20 == "abrir")
            {
                cout<<"Resultó ser un cofre trampa, sufres las consecuancias y terminas gravemente herido"<<endl;
                pv = pv - 30;
            }
            if(c20 == "irse")
            {
                cout<<"Decides retirarte... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
        }
        if (i == 29)
        {
            cout<<"Te has encontrado un cofre sospechoso... puede ser un cofre real, un cofre con trampa o incluso un mimic..."<<endl;
            cout<<"(abrir)(irse) Que harás?"<<endl;
            cin>>c29;
            if(c29 == "abrir")
            {
                cout<<"Resultó ser un cofre trampa, sufres las consecuancias y terminas gravemente herido"<<endl;
                pv = pv - 30;
            }
            if(c29 == "irse")
            {
                cout<<"Decides retirarte... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
        }
        if (i == 30)
        {
            cout<<"Te has encontrado un cofre sospechoso... puede ser un cofre real, un cofre con trampa o incluso un mimic..."<<endl;
            cout<<"(abrir)(irse) Que harás?"<<endl;
            cin>>c30;
            if(c30 == "abrir")
            {
                cout<<"Resultó ser un cofre trampa, sufres las consecuancias y terminas gravemente herido"<<endl;}
                pv = pv - 30;
            }
            if(c30 == "irse")
            {
                cout<<"Decides retirarte... no vale el riesgo"<<endl;
            }
            eliminarpos(i);
    }
}
int main(){
    int juego;
    cout<<"qué juego desea jugar?, 1 es adivina criaturas y 2 una historia (1/2)" << endl;
    cin >> juego;
    cin.ignore();
    if (juego == 1){juego1();}
    if (juego == 2){juego2();}}
