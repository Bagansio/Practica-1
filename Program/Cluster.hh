/** @file   Cluster.hh
    @brief  Especificación de la clase Cluster
*/
#ifndef CLUSTER_HH
#define CLUSTER_HH

#include "cjt_especies.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif 

/** @class Cluster
 *  @brief Representa un cluster formado por especies con identificador y gen.
 */
class Cluster  
{

private:

BinTree<string> arbol;


public:

    //CONSTRUCTORAS


/** @brief Creadora por defecto.

 * Se ejecuta automáticamente al declarar un cluster.
  \pre <em>Cierto</em>
  \post El resultado es un cluster vacio
*/
    Cluster();

/** @brief Creador de un cluster a partir de un conjunto de especies.

  \pre  Un conjunto de especies
  \post El resultado es un cluster formado 
*/
    Cluster(Cjt_especies& Conjunto);

/** @brief Creador de un cluster a partir de dos cluster hijos.

  \pre  Un identificador y dos cluster hijos
  \post El resultado es un cluster padre
*/
    Cluster(string id, Cluster& izq, Cluster& derecha);

    //DESTRUCTORA

/** @brief Destructora por defecto.
*/
    ~Cluster();

    //CONSULTORAS


/** @brief Consultora del cluster hijo izquierdo a partir de un cluster padre.

  \pre  Un cluster padre
  \post El resultado es el cluster hijo izquierdo
*/
    Cluster izquierda();

  
/** @brief Consultora del cluster hijo derecho a partir de un cluster padre.

  \pre  Un cluster padre
  \post El resultado es el cluster hijo derecho
*/
    Cluster derecha();

/** @brief Consultora del numero de hijos totales.
 
  \pre  <em>Cierto</em>
  \post El resultado es numero de hijos totales.
*/
    int tamaño();

/** @brief Consulta la tabla de distancias del cluster.

  \pre  <em>Cierto</em>
  \post Imprime la tabla de distancias del cluster
*/
    Matrix tabla_distancias(Cjt_especies& Conjunto);

        //MODIFICADORAS


/** @brief Ejecuta un paso del algoritmo WPGMA.

  \pre Número de clústers del conjunto > 1
  \post Se ejecuta el paso WPGMA
*/
    void wpgma(Cjt_especies& Conjunto);

/** @brief Operación de escritura.

  \pre <em>Cierto</em>
  \post Se han escrito por el canal estandar de salida el cluster
*/
    void imprime_cluster();

/** @brief Operación de escritura.

  \pre <em>Cierto</em>
  \post Se han escrito por el canal estandar de salida el cluster y las distancias entre ellos
*/
    void imprime_arbol_filogenetico();
}; 
#endif