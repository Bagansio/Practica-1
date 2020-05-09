#include "cjt_especies.hh"
using namespace std;


Cjt_especies::Cjt_especies()
{
}

Cjt_especies::~Cjt_especies(){}

void Cjt_especies::anadir_especie(string identificador, string gen)
{
    Especie aux(identificador,gen);
    Conjunto.insert(aux);
}

void Cjt_especies::elimina_especie(string identificador)
{
    Conjunto.erase(busca_identificador(identificador));
}

Especie Cjt_especies::obtener_especie(string identificador)
{
    return *busca_identificador(identificador);
}


Especie Cjt_especies::especie_posicion(int i)
{
    set<Especie>::iterator it = Conjunto.begin();
    for (int j = 0; j < i; ++j) ++it;
    return *it;
}


bool Cjt_especies::existe_especie(string identificador)
{
    return busca_identificador(identificador) != Conjunto.end();
}

void Cjt_especies::lee_cjt_especies()
{

    int n;
    cin >> n;
    set<Especie> Conjunto;    
    for (int i = 0; i < n; ++i)
    {
        string id,gen;
        cin >> id >> gen;
        Especie aux(id,gen);
        Conjunto.insert(aux);
    }
    this->Conjunto = Conjunto;
}

void Cjt_especies::imprime_cjt_especies()
{
    for (set<Especie>::iterator it = Conjunto.begin(); it != Conjunto.end(); ++it)
    {
        Especie aux = *it;
        aux.imprime_especie();
    }
}

Matrix Cjt_especies::tabla_distancias(int k)
{
    int n = Conjunto.size();
    Matrix tabla(n,vector<double> (n));
    set<Especie>::iterator it_fila = Conjunto.begin();
    for (int i = 0; i < n; ++i)             // Filas
    {
        set<Especie>::iterator it_columna = Conjunto.begin();
        for (int j = 0; j < n; ++j)         // Columnas
        {
            Especie aux = *it_fila;
            tabla[i][j] = aux.distancia(*it_columna,k);
            ++it_columna;
        }
        ++it_fila;
    }
    return tabla;
}

void Cjt_especies::imprime_tabla_distancias(int k)
{
    Matrix tabla = tabla_distancias(k);
    int n = tabla.size();
    for (set<Especie>::iterator it = Conjunto.begin(); it != Conjunto.end(); ++it) 
    {
        Especie aux = *it;
        cout << ' ' << aux.consultar_id() << ' ';
    }
    cout << endl;
    set<Especie>::iterator it = Conjunto.begin();
    for (int i = 0; i < n; ++i)
    {
        Especie aux = *it;
        cout << aux.consultar_id();
        for (int j = 0; j < n; ++j)
        {
            cout << ' ' << tabla[i][j];
        }
        ++it;
        cout << endl;
    }
}

set<Especie>::iterator Cjt_especies::busca_identificador(string identificador)
{
    for(set<Especie>::iterator it = Conjunto.begin(); it != Conjunto.end(); ++it)
    {
        Especie aux = *it;
        if (aux.consultar_id() == identificador) return it;
    }
    return Conjunto.end();
}
