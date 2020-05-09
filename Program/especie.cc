#include "especie.hh"

using namespace std;


//Especie::Especie(){}

Especie::Especie(string identificador, string gen)
{
    id = identificador;
    this -> gen = gen;
}

Especie::~Especie(){}

string Especie::consultar_gen()
{
    return gen;
}

string Especie::consultar_id()
{
    return id;
}

double Especie::distancia(Especie especie2, int k)
{
    map<string,int> kmer1 = kmer(gen,k);
    map<string,int> kmer2 = kmer(especie2.gen,k);
    int max,min;
    max_min(kmer1,kmer2,max,min);
    cout << "max: " << max << "     " << "min: " << min << endl;
    return (1 - (double(min) / max)) * 100;
}

void Especie::imprime_especie()
{
    cout << "IDENTIFICADOR: " << id << " GEN: " << gen << endl;
}

map<string,int> Especie::kmer(string gen,int k)
{
    int mida_gen = gen.length();
    map<string,int> kmer1;
    for (int i = 0; i <= mida_gen - k; ++i) 
    {
        string aux = gen.substr(i,k);       //crea un string aux hasta k posiciones desde i
        ++kmer1[aux];                       //poner el string aux en el map y si ya existe sumarle 1
    }
    return kmer1;
}

void Especie::max_min(map<string,int>& kmer1, map<string,int>& kmer2,int& max,int& min)
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
