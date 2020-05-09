#include "cjt_especies.hh"
using namespace std;


Cjt_especies::Cjt_especies(int k)
{
    divisiones = k;
}

Cjt_especies::~Cjt_especies(){}

void Cjt_especies::anadir_especie(string identificador, string gen)
{
    Conjunto[identificador] = gen;
}

void Cjt_especies::elimina_especie(string identificador)
{
    Conjunto.erase(identificador);
}

string Cjt_especies::obtener_gen(string identificador)
{
    return Conjunto[identificador];
}

string Cjt_especies::obtener_id(int i)
{
    map<string,string>::iterator it = Conjunto.begin();
    for (int j = 0; j < i; ++j) ++it;
    return (*it).first; 
}   

bool Cjt_especies::existe_especie(string identificador)
{
    return Conjunto.find(identificador) != Conjunto.end();
}

int Cjt_especies::tamaño()
{
    return Conjunto.size();
}

double Cjt_especies::distancia(string gen1,string gen2)
{
    map<string,int> kmer1 = kmer(gen1);
    map<string,int> kmer2 = kmer(gen2);
    int max,min;
    max_min(kmer1,kmer2,max,min);
    cout << "max: " << max << "     " << "min: " << min << endl;
    return (1 - (double(min) / max)) * 100;
}

void Cjt_especies::lee_cjt_especies()
{

    int n;
    cin >> n;
    map<string,string> Conjunto;    
    for (int i = 0; i < n; ++i)
    {
        string id,gen;
        cin >> id >> gen;
        Conjunto[id] = gen;
    }
    this->Conjunto = Conjunto;
}

void Cjt_especies::imprime_cjt_especies()
{
    for (map<string,string>::iterator it = Conjunto.begin(); it != Conjunto.end(); ++it)
    {
        cout << it->first << ' ' << it->second << endl;
    }
}

Matrix Cjt_especies::tabla_distancias()
{
    int n = Conjunto.size();
    Matrix tabla(n,vector<double> (n));
    map<string,string>::iterator it_fila = Conjunto.begin();
    for (int i = 0; i < n; ++i)             // Filas
    {
        map<string,string>::iterator it_columna = Conjunto.begin();
        for (int j = 0; j < n; ++j)         // Columnas
        {
            tabla[i][j] = distancia((*it_columna).second,(*it_fila).second);
            ++it_columna;
        }
        ++it_fila;
    }
    return tabla;  
}

map<string,int> Cjt_especies::kmer(string gen)
{
    int mida_gen = gen.length();
    map<string,int> kmer1;
    for (int i = 0; i <= mida_gen - divisiones; ++i) 
    {
        string aux = gen.substr(i,divisiones);       //crea un string aux hasta k posiciones desde i
        ++kmer1[aux];                       //poner el string aux en el map y si ya existe sumarle 1
    }
    return kmer1;
}

void Cjt_especies::max_min(map<string,int> kmer1, map<string,int> kmer2,int& max,int& min)
{
    max = min = 0;
    map<string,int>::iterator it1 = kmer1.begin();
    map<string,int>::iterator it2 = kmer2.begin();
    while (it1 != kmer1.end() and it2 != kmer2.end())
    {
        if (it1->first == it2->first)
        {
            if (it1->second > it2->second)
            {
                max += it1->second;
                min += it2->second;
            } 
            else
            { 
                max += it2->second;
                min += it1->second;
            }
            ++it1;
            ++it2;
        }
        else if (it1->first > it2->first)
        {
            max += it2->second;
            ++it2;
        }
        else
        {
            max += it2->second;
            ++it1;
        } 
    }
    map<string,int>::iterator end; 
    if (it1 == kmer1.end())
    { 
        end = kmer2.end();
        it1 = it2;
    }
    else end = kmer1.end();
    while (it1 != end)
    {
        max += it1->second;
        ++it1;
    }
}