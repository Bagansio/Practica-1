#include "cjt_especies.hh"
using namespace std;

Cjt_especies::Cjt_especies(int k)
{ 
    Especie aux;
    aux.modifica_divisiones(k);
}
    

Cjt_especies::~Cjt_especies()
{ 
}

void Cjt_especies::anadir_especie(string identificador, string gen)
{
    Especie aux(gen);
    Conjunto[identificador] = gen;
}

void Cjt_especies::elimina_especie(string identificador)
{
    Conjunto.erase(identificador);
}


string Cjt_especies::obtener_gen(string identificador)
{
    return Conjunto[identificador].consultar_gen();
}

double Cjt_especies::distancia(string id1,string id2)
{
    return Conjunto[id1].distancia(Conjunto[id2]);
}



bool Cjt_especies::existe_especie(string identificador)
{
    return Conjunto.find(identificador) != Conjunto.end();
}

vector<string> Cjt_especies::identificadores()
{
    vector<string> v(Conjunto.size());
    int i = 0;
    for (map<string,Especie>::iterator it = Conjunto.begin(); it != Conjunto.end(); ++it)
    {
        v[i] = it->first;
        ++i;
    }
    return v;

}

map<string,map<string,double>> Cjt_especies::obtener_tabla_distancias()
{
    tabla_distancias();
    return tabla_dist;
}

void Cjt_especies::lee_cjt_especies()
{

    int n;
    cin >> n;
    map<string,Especie> Conjunto;  
    for (int i = 0; i < n; ++i)
    {
        string id,gen;
        cin >> id >> gen;
        Especie aux(gen);
        Conjunto[id] = gen;
    }
    this->Conjunto = Conjunto;
}

void Cjt_especies::imprime_cjt_especies()
{
    for (map<string,Especie>::iterator it = Conjunto.begin(); it != Conjunto.end(); ++it)
    {
        cout << it->first << ' ' << (it->second).consultar_gen() << endl;
    }
}

void Cjt_especies::tabla_distancias()
{
    map<string,map<string,double>> tabla;
    for (map<string,Especie>::iterator it1 = Conjunto.begin(); it1 != Conjunto.end(); ++it1)
    {
        map<string,Especie>::iterator it2 = it1;
        ++it2;
        map<string,double> aux;
        while (it2 != Conjunto.end())
        {
            aux[it2->first] = it1->second.distancia(it2->second);
            ++it2;
        }
        tabla[it1->first] = aux;
    }
    tabla_dist = tabla;
}

void Cjt_especies::imprime_tabla_distancias()
{
    tabla_distancias();
    for(map<string,map<string,double>>::iterator it = tabla_dist.begin(); it != tabla_dist.end(); ++it)
    {
        cout << it->first << ':';
        for(map<string,double>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
        {
            cout << ' ' << it2->first << " (" << it2->second << ')';
        }
        cout << endl;
    }
}
