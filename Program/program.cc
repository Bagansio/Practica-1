/**
 * @mainpage
 * 
 * Este programa sirve para la creación de árboles filogenéticos de especies a partir de su secuencia genética.
 * 
 * \page quees ¿Que es un árbol filogenético y algoritmo WPGMA
 *      
 *      Es un esquema arborescente que muestra las relaciones evolutivas entre varias especies que se cree que tienen una ascendencia común.

        Estos árboles se pueden generar de diversas formas, por ejemplo observando las diversas cualidades de cada especie y agruparlas:
        \image html arbol2.png  "Fig.1 Ejemplo de árbol a partir de las cualidades."

        En nuestro caso usaremos los genes y el algoritmo WPGMA. 

        <B> El algoritmo WPGMA: </B>

        Cada gen consiste en una secuencia de símbolos, los cuales representan los cuatro tipos de nucleótidos: Adenina (A), Citosina (C), Guanina (G) y Timina (T).

        Ejemplo de gen: AACTTGCGAGCTACAACCTGGGATTA

        Pues el algoritmo únicamente es un uso recursivo de dos pasos:
        
        <center> 1. Con estas secuencias sacamos una distancia por cada par de secuencias de todo el conjunto de especies creando así una tabla de distancias.</center> 

        <center> 2. Con esta tabla de distancias, el algoritmo nos dice que las dos especies con un antecesor común son las de menor distancia.</center> 
        
        Y finalmente ya tendremos hecho nuestro árbol.

 * \page Webgrafia
 * 
 *  <B>Figuras</B>
 * 
 * 
 *  Figura 1: https://cdn.kastatic.org/ka-perseus-images/211dc38a08cf29c0a48aac2cdba6dcec6c66e1e0.png
 * 
 * 
 */ 

#include "cjt_especies.hh"
#include "Cluster.hh"

string CORRECTO = "La funcion se ha realizado correctamente.";

//Peticiones
string PETICIONID = "Escriba el identificador de la especie:";
string PETICIONGEN = "Escriba el gen de la especie";

string EXCEPCION1 = "Ya existe esa especie en el conjunto.";
string EXCEPCION2 = "No existe esa especie en el conjunto.";

/** @brief Añade una especie al conjunto.

  Si ya existe una especie con el mismo identificador manda un mensaje de error.
*/
void crea_especie(Cjt_especies& Conjunto);


/** @brief Consulta gen de una especie del conjunto.

  Sino existe manda un mensaje de error.
*/
void obtener_gen(const Cjt_especies& Conjunto);


/** @brief Consulta distancia entre dos especies del conjunto.

  Sino existe alguna de las dos especies manda un mensaje de error.
*/
void obtener_distancia(const Cjt_especies& Conjunto);


/** @brief Elimina una especie del conjunto.

Sino existe tal especie manda un mensaje de error.
*/
void elimina_especie(Cjt_especies& Conjunto);


/** @brief Consulta si exista una especie en el conjunto.

  Sino existe tal especie manda un mensaje de error.
*/
void existe_especie(const Cjt_especies& Conjunto);


/** @brief Lectura de un conjunto de especies.

  \pre <em>Cierto</em>
  \post El Conjunto es totalmente modificado
*/
void lee_cjt_especies(Cjt_especies& Conjunto);


/** @brief Operación de escritura.

  \pre <em>Cierto</em>
  \post Se escribe el conjunto de especies por el canal estandar de salida
*/
void imprime_cjt_especies(const Cjt_especies& Conjunto);


/** @brief Operación de escritura de la tabla de distancias.

  \pre <em>Cierto</em>
  \post Se escribe la tabla de distancias de las especies del conjunto.
*/
void tabla_distancias(const Cjt_especies& Conjunto);


/** @brief Inicializa clústers con el conjunto.

  Imprime los clústers resultantes, así como la tabla de distancias entre clústers.
*/
void inicializa_clusters(const Cjt_especies& Conjunto, Cluster& cluster);


/** @brief Ejecuta un paso WPGMA.

  \pre Número de clústers del conjunto > 1
  \post Si el pre es cierto se ejecuta sino manda un mensaje de error
*/
void ejecuta_paso_wpgma(Cluster& cluster);


/** @brief Operación de escritura de un clúster.

  Sino existe manda un mensaje de error.
*/
void imprime_cluster(const Cluster& cluster);


/** @brief Imprime el árbol filogenético para el conjunto de especies actual.
*/
void imprime_arbol_filogenetico(const Cjt_especies& Conjunto, Cluster& cluster);



int main()
{
    cout << "Inserte un numero para dividir en partes el gen:" << endl;
    int k;
    string comanda;
    cin >> k;
    Cjt_especies Conjunto;
    Cluster cluster;
    while (cin >> comanda)
    {
        if (comanda == "crea_especie") //CREAR UNA ESPECIE AL CONJUNTO
        {
                                        //PETICION
          string id,gen;
          cout << PETICIONID << endl;
          cin >> id;
          cout << PETICIONGEN << endl;
          cin >> gen;
                                        //FUNCION
          if (Conjunto.existe_especie(id)) cout << EXCEPCION1;
          else
          {
            Conjunto.anadir_especie(id,gen);
            cout << CORRECTO;
          }
        }
        else if (comanda == "obtener_gen") //OBTENER UN GEN DE UNA ESPECIE
        {
                                        //PETICION
          string id;
          cout << PETICIONID << endl;
          cin >> id;
                                        //FUNCION
          if (Conjunto.existe_especie(id)) cout << "El gen es: " << Conjunto.obtener_especie(id).consultar_gen();
          else cout << EXCEPCION2;
        }
        else if (comanda == "distancia")
        {
                                        //PETICION
          string id1,id2;
          cout << PETICIONID << endl;
          cin >> id1;
          cout << PETICIONID << endl;
          cin >> id2;
                                        //FUNCION
          if (Conjunto.existe_especie(id1) and Conjunto.existe_especie(id2)) 
          {
            cout << "La distancia entre " << id1 << " y " << id2 << " es: ";
            cout << Conjunto.obtener_especie(id1).distancia(Conjunto.obtener_especie(id2), k);
          }
          else cout << EXCEPCION2;
        }

        else if (comanda == "elimina_especie") //ELIMINAR ESPECIE DEL CONJUNTO
        {
                                        //PETICION
          string id;
          cout << PETICIONID << endl;
          cin >> id;
                                        //FUNCION
          if (Conjunto.existe_especie(id))
          {
            Conjunto.elimina_especie(id);
            cout << CORRECTO;
          }
          else cout << EXCEPCION2;
        }

        else if (comanda == "existe_especie") //CONSULTAR SI EXISTE UNA ESPECIE EN EL CONJUNTO
        {
          string id;
          cout << PETICIONID <<endl;
          cin >> id;

          if (Conjunto.existe_especie(id)) cout << "Existe la especie " << id << " en el conjunto.";
          else cout << EXCEPCION2;
        }

        else if (comanda == "lee_cjt_especies") //LEE UN OCNJUNTO DE ESPECIES
        {
          Conjunto.lee_cjt_especies();
        }

        else if (comanda == "imprime_cjt_especies") //IMPRIME EL CONJUNTO DE ESPECIES
        {
          Conjunto.imprime_cjt_especies();
        }
      
        else if (comanda == "tabla_distancias") //ESCRIBE LA TABLA DE DISTANCIAS
        {

        }
        else if (comanda == "inicializa_clusters") inicializa_clusters(Conjunto,cluster);
        else if (comanda == "ejecuta_paso_wpgma") ejecuta_paso_wpgma(cluster);
        else if (comanda == "imprime_cluster") imprime_cluster(cluster);
        else if (comanda == "imprime_arbol_filogenetico") imprime_arbol_filogenetico(Conjunto,cluster);
        else if (comanda == "fin") break;
        cout << endl;
    }
}

