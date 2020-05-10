/** @file   Cluster.hh
    @brief  Especificación de la clase Cluster
*/
#ifndef CJT_CLUSTER_HH
#define CJT_CLUSTER_HH

#include "cjt_especies.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <set>
#endif 



/** @class Cluster
 *  @brief Representa un cluster formado por especies con identificador y gen.
 */
class Cjt_clusters  
{

private:

  map<string,BinTree<tabla>> bosque;

  vector<tabla> tabla_dist;

  void actualizar_tabla(Cjt_especies& Conjunto,const tabla& fusionar);

public:

    //CONSTRUCTORAS


/** @brief Creadora por defecto.

 * Se ejecuta automáticamente al declarar un cluster.
  \pre <em>Cierto</em>
  \post El resultado es un cluster vacio
*/
    Cjt_clusters();

    //DESTRUCTORA

/** @brief Destructora por defecto.
*/
    ~Cjt_clusters();

    //CONSULTORAS

/** @brief Consulta la distancia mínima entre dos elementos del conjunto

  \pre <em> Cierto </em>
  \post Devuelve los identificadores y la distancia de los dos elementos con menor distancia entre ellos
*/
    tabla distancia_minima();


        //MODIFICADORAS

/** @brief Inicializa los clusters con el conjunto de especies.

  \pre <em>Cierto</em>
  \post Se inicializan los clusters
*/
    void inicializar_clusters(Cjt_especies& Conjunto);


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