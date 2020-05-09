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
    string gen;                                 //gen
    static int divisiones;                      //divisiones en la que se dividira el gen para hacer el kmer
    map<string,int> kmer;                       //kmer
    

    map<string,int> obtener_kmer();
    void max_min(map<string,int>& kmer1, map<string,int>& kmer2,double& max,double& min);

public:

    //Constructores

/** @brief Creadora por defecto.

    Se ejecuta automáticamente al declarar una especie.
    \pre <em>Cierto</em>
    \post El resultado es una especie
 */
    Especie();



/** @brief Creadora de una especie con gen.
  
  \pre Un string gen
  \post El resultado es una especie con this -> gen = gen
*/
    Especie(string gen);

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

/** @brief Consulta la distancia entre dos especies.

  \pre Hay dos especies con los identificadores dados en el parámetro implícito
  \post El resultado es la distancia entre las dos especies
*/
    double distancia(Especie e1);


    // MODIFICADORAS


/** @brief Modifica el valor de divisiones.

  \pre  k > 0
  \post Divisiones pasa a ser igual a k
*/
    static void modifica_divisiones(int k);
    // OPERATOR

/*
    bool operator < (const Especie& aux) const 
    {
      return id < aux.id;
    }
    bool operator > (const Especie& aux) const 
    {
      return id > aux.id;
    }
*/
};
#endif