#include "cjt_especies.hh"
#include "Cluster.hh"

string CORRECTO = "La funcion se ha realizado correctamente.";

//Peticiones
string PETICIONID = "Escriba el identificador de la especie:";
string PETICIONGEN = "Escriba el gen de la especie";

string EXCEPCION1 = "Ya existe esa especie en el conjunto.";
string EXCEPCION2 = "No existe esa especie en el conjunto.";

string INICIO = "Inserte su instruccion: ";
int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);

    cout << "Inserte un numero para dividir en partes el gen:" << endl;
    int k;
    string comanda;
    cin >> k;
    Cjt_especies Conjunto;
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
          if (Conjunto.existe_especie(id)) cout << "El gen de " << id << " es: " << Conjunto.obtener_especie(id).consultar_gen();
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
        else if (comanda == "tabla_distancias")  //IMPRIME LA TABLA DE DISTANCIAS
        {
          Conjunto.imprime_tabla_distancias(k);
        }
        else if (comanda == "fin") break;

        cout << endl;
    }
}