/** @file Cjt_especies.hh
  @brief Especificación de la clase Conjunto de Especies
*/
#ifndef CJT_ESPECIES_HH
#define CJT_ESPECIES_HH


//#include "especie.hh"
#ifndef NO_DIAGRAM  
#include <vector>   
#include <map>      // Para no añadirlo al diagrama de la documentacion
#include <string>   
#include <iostream> 
#endif              
using namespace std;

typedef vector < vector < double > > Matrix;

/** @class Cjt_especies
  @brief Representa un conjunto de especies con identificador y gen.
*/
class Cjt_especies {

private:

    map<string,string> Conjunto;
    static int divisiones;

    map<string,int> kmer(string gen);

    void max_min(map<string,int> kmer1, map<string,int> kmer2,int& max,int& min);

public:

/** @brief Creadora por defecto del conjunto de especies.

  \pre <em>Cierto</em>
  \post El resultado es un conjunto de especies vacio
*/
    Cjt_especies(int k);


/** @brief Destructora por defecto.
 */ 
    ~Cjt_especies();


        //Modificadoras


/** @brief Añade una especie no repetida al conjunto.

  \pre No existe ese identificador en el parámetro implícito
  \post La especie se ha añadido al parámetro implícito
*/
    void anadir_especie(string identificador, string gen);


/** @brief Elimina una especie del conjunto.

  \pre Existe una especie con identificador = id en el parámetro implícito
  \post Se ha borrado la especie con identificador = id del parámetro implícito 
*/
    void elimina_especie(string identificador);


        //Consultoras


/** @brief Consulta el gen de una especie del conjunto.

  \pre Existe una especie en el parámetro implícito con dicho identificador
  \post El resultado es el gen de dicha especie
*/
    string obtener_gen(string identificador);

/** @brief Consulta el id de una especie del conjunto.

  \pre Existe una especie en el parámetro implícito que se ubica en dicha posicion del conjunto
  \post El resultado es el id de dicha especie
*/
    string obtener_id(int i);

/** @brief Consulta la distancia entre dos especies del conjunto.

  \pre Hay dos especies con los identificadores dados en el parámetro implícito
  \post El resultado es la distancia entre las dos especies
*/
    double distancia(string id1,string id2);

/** @brief Consulta si existe la especie en el conjunto

  \pre <em>Cierto</em>
  \post Devuelve <b>true</b> si existe dicha especie en el parámetro implícito <br> Devuelve <b>false</b> sino existe dicha especie en el parámetro implícito
*/
    bool existe_especie(string identificador);

/** @brief Consulta el tamaño del conjunto.

  \pre <em>Cierto</em>
  \post Devuelve el tamaño del parámetro implícito
*/
    int tamaño();

/** @brief  Operación de lectura.

  \pre <em>Cierto</em>
  \post El parámetro implícito contiene el conjunto de estudiantes leídos del canal estandard de entrada
*/
    void lee_cjt_especies();

/** @brief  Operación de escritura.

  \pre <em>Cierto</em>
  \post Se han escrito por el canal estandard de salida a las especies del conjunto que contiene el parámetro implícito
*/
    void imprime_cjt_especies();

/** @brief Consulta la tabla de distancias del conjunto de especies.
 * 
 * \pre <em>Cierto</em>
 * \post Devuelve una matriz de distancias entre cada par de especies del conjunto de especies
 */
    Matrix tabla_distancias();

/** @brief Imprime la tabla de distancias del conjunto de especies.
 * 
 * \pre <em>Cierto</em>
 * \post Imprime una tabla de distancias entre cada par de especies del conjunto de especies
 */
    void imprime_tabla_distancias();

/** @brief Consulta la tabla de distancias del conjunto de especies.
 * 
 * \pre <em>Cierto</em>
 * \post Imprime la tabla de distancias entre cada par de especies del conjunto de especies
 */
};
#endif