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
#include "cjt_clusters.hh"

int main()
{
    int k;
    string comanda;
    cin >> k;
    Cjt_especies Conjunto(k);
    Cjt_clusters Clusters;
  
    while (cin >> comanda)
    {
        if (comanda == "crea_especie") //CREAR UNA ESPECIE AL CONJUNTO
        {
                                        //PETICION
          string id,gen;
          cin >> id >> gen;
                                        //FUNCION
          cout << "# " << comanda << ' ' << id << ' ' << gen;
          if (Conjunto.existe_especie(id)) cout << endl << "ERROR: La especie " << id << " ya existe.";
          else
          {
            Conjunto.anadir_especie(id,gen);
          }
          cout << endl;
        }
        else if (comanda == "obtener_gen") //OBTENER UN GEN DE UNA ESPECIE
        {
                                        //PETICION
          string id;
          cin >> id;
                                        //FUNCION
          cout << "# " << comanda << ' ' << id << endl;
          if (Conjunto.existe_especie(id)) cout << Conjunto.obtener_gen(id);
          else cout << "ERROR: La especie " << id << " no existe.";
          cout << endl;
        }
        else if (comanda == "distancia")
        {
                                        //PETICION
          string id1,id2;
          cin >> id1 >> id2;
                                        //FUNCION
          cout << "# " << comanda << ' ' << id1 << ' ' << id2 << endl;
          bool existe_id1 = Conjunto.existe_especie(id1);
          bool existe_id2 = Conjunto.existe_especie(id2);
          if (existe_id1 and existe_id2) 
          {
            cout << Conjunto.distancia(id1,id2);
          }
          else { 
              cout << "ERROR: " << "La especie ";
              if (not existe_id1 and not existe_id2) cout  << id1 << " y la especie " << id2 << " no existen.";
              else if (not existe_id1) cout << id1 << " no existe.";
              else cout << id2 << " no existe.";
          }
          cout << endl;
        }

        else if (comanda == "elimina_especie") //ELIMINAR ESPECIE DEL CONJUNTO
        {
                                        //PETICION
          string id;
          cin >> id;
                                        //FUNCION
          cout << "# " << comanda << ' ' << id << endl;
          if (Conjunto.existe_especie(id))
          {
            Conjunto.elimina_especie(id);
          }
          else cout << "ERROR: La especie " << id << " no existe." << endl;
        }

        else if (comanda == "existe_especie") //CONSULTAR SI EXISTE UNA ESPECIE EN EL CONJUNTO
        {
                                        //PETICION
          string id;
          cin >> id;
                                        //FUNCION
          cout << "# " << comanda << ' ' << id << endl;
          if (Conjunto.existe_especie(id)) cout << "SI";
          else cout << "NO";
          cout << endl;
        }

        else if (comanda == "lee_cjt_especies") //LEE UN OCNJUNTO DE ESPECIES
        { 
          Conjunto.lee_cjt_especies();
          cout <<  "# " << comanda << endl;
        }

        else if (comanda == "imprime_cjt_especies") //IMPRIME EL CONJUNTO DE ESPECIES
        {
           cout << "# " << comanda << endl;
          Conjunto.imprime_cjt_especies();
        }
        else if (comanda == "tabla_distancias") //IMPRIME LA TABLA DE DISTANCIAS
        {
          cout << "# " << comanda << endl;
          Conjunto.imprime_tabla_distancias();
        }
        else if (comanda == "inicializa_clusters")
        {
          cout << "# " << comanda << endl; 
          Clusters.inicializar_clusters(Conjunto);
          Clusters.imprime_tabla_distancias();
        }
        else if(comanda == "ejecuta_paso_wpgma")
        {
          cout << "# " << comanda << endl; 
          if(Clusters.wpgma())
          {
            Clusters.imprime_tabla_distancias();
          }
          else cout << "ERROR: num_clusters <= 1"  << endl;
        }
        else if (comanda == "imprime_cluster")
        {
            string id;
            cin >> id;

            cout << "# " << comanda << ' ' << id << endl;  
            if(not Clusters.imprime_cluster(id)) cout << "ERROR: El cluster " << id << " no existe.";
            cout << endl;
        }
        else if (comanda == "imprime_arbol_filogenetico")
        {
          cout << "# " << comanda << endl;
          if(not Clusters.imprime_arbol_filogenetico(Conjunto)) cout << "ERROR: El conjunto de clusters es vacio.";
          cout << endl;
        }
        else if (comanda == "fin") break;     //ACABA EL PROGRAMA
        cout << endl;
    }
}