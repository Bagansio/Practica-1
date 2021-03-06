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

  map<string,BinTree<pair<string,double>>> bosque;

  map<string,map<string,double>> tabla_dist;

  void actualizar_tabla(const pair<string,string>& fusionar);

  void imprime_clusters(const BinTree<pair<string,double>>& arbol);

public:

    //CONSTRUCTORAS


/** @brief Creadora por defecto.

 * Se ejecuta automáticamente al declarar un cluster.
  \pre <em>Cierto</em>
  \post El resultado es un cluster vacio
*/
    Cjt_clusters() {}

    //DESTRUCTORA

/** @brief Destructora por defecto.
*/
    ~Cjt_clusters() {}

    //CONSULTORAS

/** @brief Consulta la distancia mínima entre dos elementos del conjunto

  \pre <em> Cierto </em>
  \post Devuelve los identificadores y la distancia de los dos elementos con menor distancia entre ellos
*/
    pair<string,string> distancia_minima(double& min);


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
    bool wpgma();

/** @brief 

  \pre 
  \post 
*/
    void imprime_tabla_distancias();

/** @brief Operación de escritura.

  \pre <em>Cierto</em>
  \post Se han escrito por el canal estandar de salida el cluster
*/
    bool imprime_cluster(string id);

/** @brief Operación de escritura.

  \pre <em>Cierto</em>
  \post Se han escrito por el canal estandar de salida el cluster y las distancias entre ellos
*/
    bool imprime_arbol_filogenetico(Cjt_especies& Conjunto);
}; 
#endif