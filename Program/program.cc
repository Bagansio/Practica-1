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

string INICIO = "Inserte su instruccion: ";
string CORRECTO = "La funcion se ha realizado correctamente.";

//Peticiones
string PETICIONID = "Escriba el identificador de la especie:";
string PETICIONGEN = "Escriba el gen de la especie";
//Excepciones
string EXCEPCION1 = "Ya existe esa especie en el conjunto.";
string EXCEPCION2 = "No existe esa especie en el conjunto.";
string EXCEPCION3 = "No se puede realizar el algoritmo WPGMA.";

cout.setf(ios::fixed);
cout.precision(4);

int main()
{


    cout << "Inserte un numero para dividir en partes el gen:" << endl;
    int k;
    string comanda;
    cin >> k;
    Cjt_especies Conjunto(k);
    Cluster clusters;
    while (cout << INICIO << endl and cin >> comanda)
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
          if (Conjunto.existe_especie(id)) cout << "El gen de " << id << " es: " << Conjunto.obtener_gen(id);
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
            cout << Conjunto.distancia(id1,id2);
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
        else if (comanda == "tabla_distancias") //IMPRIME LA TABLA DE DISTANCIAS
        {
          Conjunto.imprime_tabla_distancias();
        }
        else if (comanda == "inicializa_clusters") //INICIALIZA LOS CLUSTERS Y LOS IMPRIME
        {
          clusters = Cluster(Conjunto);
          clusters.imprime_cluster();
        }
        else if (comanda == "ejecuta_paso_wpgma") //EJECUTA 
        {
          if (Conjunto.tamaño() - cluster.tamaño() > 1)
          {
            cluster.wpgma(Conjunto);
            cluster.imprime_tabla();
          }
          else cout << EXCEPCION3;

        }
        else if (comanda == "imprime_cluster") //IMPRIME CLUSTER
        {
          clusters.imprime_cluster();
        }
        else if (comanda == "imprime_arbol_filogenetico") //IMPRIME ARBOL FILOGENETICO
        {
          if(Conjunto.tamaño() > 1) 
          {
            cluster = Cluster(Conjunto);
            while (Conjunto.tamaño() - cluster.tamaño() > 1)
            {
              cluster.wpgma(Conjunto);
            }
            cluster.imprime_arbol_filogenetico();
          }
          else cout << "El conjunto de clústers es vacío."
        }
        else if (comanda == "fin") break;     //ACABA EL PROGRAMA
        cout << endl;
    }
}