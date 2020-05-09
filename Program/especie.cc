#include "especie.hh"

using namespace std;

int Especie::divisiones = 0;

Especie::Especie()
{
    gen = "a";
}


Especie::Especie(string gen)
{
    this -> gen = gen;
    kmer = obtener_kmer();
}

Especie::~Especie(){}

string Especie::consultar_gen()
{
    return gen;
}


double Especie::distancia(Especie especie2)
{
    double max,min;
    max_min(kmer,especie2.kmer,max,min);
    return (1 - (min / max)) * 100;
}

map<string,int> Especie::obtener_kmer()
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

void Especie::escribir_kmer()
{
    for (map<string,int>::iterator it = kmer.begin(); it != kmer.end(); ++it)
    {
        cout << it->first << ' ' << it->second << endl;
    }
}

void Especie::modifica_divisiones(int k)
{
    divisiones = k;
}


void Especie::max_min(map<string,int>& kmer1, map<string,int>& kmer2,double& max,double& min)
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
    cout << endl << max << endl << min << endl;
}
