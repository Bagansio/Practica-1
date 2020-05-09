/** @file especie.hh
 *  @brief Especificación de la clase Especie
 */

#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM  //
#include <map>      // Para no añadirlo al diagrama de la documentacion
#include <string>   //
#include <iostream> //
#endif              // 
using namespace std;


/** @class Especie
  @brief Representa una especie con identificador y gen.
*/
class Especie {

private:
    string id; //identificador
    string gen;

    

    map<string,int> kmer(string gen,int k);
    void max_min(map<string,int>& kmer1, map<string,int>& kmer2,int& max,int& min);

public:

    //Constructores

/** @brief Creadora por defecto.

    Se ejecuta automáticamente al declarar una especie.
    \pre <em>Cierto</em>
    \post El resultado es una especie
 */
    Especie();


/** @brief Creadora de una especie con id y gen.
  
  \pre Un string identificador y un string gen
  \post El resultado es una especie con id = identificador y this -> gen = gen
*/
    Especie(string identificador, string gen);

    //Destructora

/** @brief Destructora por defecto.
*/
    ~Especie();

    //Consultoras

/** @brief Consultora del gen de una especie.

  \pre <em>Cierto</em>
  \post El resultado es el gen del parámetro implícito
*/
   string consultar_gen(); 

/** @brief Consultora del identificador de una especie.

  \pre <em>Cierto</em>
  \post El resultado es el id del parámetro implícito
*/
   string consultar_id();

/** @brief Consulta la distancia entre dos especies.

  \pre Hay dos especies con los identificadores dados en el parámetro implícito
  \post El resultado es la distancia entre las dos especies
*/
    double distancia(Especie e1, int k);

/** @brief Operación de escritura.

  \pre <em>Cierto</em>
  \post Se ha escrito por el canal estandar de salida a la especie
*/
    void imprime_especie();
    

    // OPERATOR

    bool operator < (const Especie& aux) const 
    {
      return id < aux.id;
    }
    bool operator > (const Especie& aux) const 
    {
      return id > aux.id;
    }
};
#endif