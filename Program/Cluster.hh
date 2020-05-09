/** @file   Cluster.hh
    @brief  Especificación de la clase Cluster
*/
#ifndef CLUSTER_HH
#define CLUSTER_HH

#include "Cjt_especies.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif 

/** @class Cluster
 *  @brief Representa un cluster formado por especies con identificador y gen.
 */
class Cluster  
{

private:

BinTree<string> cluster;

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
    Cluster(const Cjt_especies& Conjunto, int k);

    //DESTRUCTORA

/** @brief Destructora por defecto.
*/
    ~Cluster();

    //CONSULTORAS


/** @brief Consulta la tabla de distancias del cluster.

  \pre  <em>Cierto</em>
  \post Imprime la tabla de distancias del cluster
*/
    void tabla_distancias();

        //MODIFICADORAS


/** @brief Ejecuta un paso del algoritmo WPGMA.

  \pre Número de clústers del conjunto > 1
  \post Se ejecuta el paso WPGMA
*/
    void wpgma();

/** @brief Operación de escritura.

  \pre <em>Cierto</em>
  \post Se han escrito por el canal estandar de salida al cluster
*/
    void imprime_cluster();
}; 
#endif