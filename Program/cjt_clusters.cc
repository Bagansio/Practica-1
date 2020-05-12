#include "cjt_clusters.hh"

void Cjt_clusters::inicializar_clusters(Cjt_especies& Conjunto)  //transformarlo en un void que actualize bosque
{
    map<string,BinTree<pair<string,double>>> aux;
    vector<string> v = Conjunto.identificadores();
    int dimensiones = v.size();
    for (int i = 0; i < dimensiones; ++i)
    {
        aux[v[i]] = BinTree<pair<string,double>>(make_pair(v[i],0));
    }
    
    bosque = aux;
    tabla_dist = Conjunto.obtener_tabla_distancias();
}


pair<string,string> Cjt_clusters::distancia_minima(double& min)
{
    map<string,map<string,double>>::iterator it1 = tabla_dist.begin();
    pair<string,string> dist_min;
    min = 100;       //distancia más lejana
    while(it1 != tabla_dist.end())
    {
        for(map<string,double>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
        {
            if (min > it2->second)
            {
                dist_min = make_pair(it1->first,it2->first);
                min = it2->second;
            }
        }
        ++it1;
    }
    return dist_min;
}

bool  Cjt_clusters::wpgma()
{
    if (bosque.size() > 1)
    {
    double dist;
    pair<string,string> fusionar = distancia_minima(dist);
    bosque[fusionar.first + fusionar.second] = BinTree<pair<string,double>>(make_pair(fusionar.first + fusionar.second,dist/2),bosque[fusionar.first],bosque[fusionar.second]);
    bosque.erase(fusionar.first);
    bosque.erase(fusionar.second);
    actualizar_tabla(fusionar);
    return true;
    }
    else return false;
}

void Cjt_clusters::arbol_filogenetico()
{
    while(wpgma());
}

void Cjt_clusters::actualizar_tabla(const pair<string,string>& fusionar)
{
    map<string,double> aux;
    map<string,map<string,double>>::iterator it = tabla_dist.begin();
    bool encontrado = false;
    while(it != tabla_dist.end() and it->first != fusionar.second)
    {
        if (it->first == fusionar.first)
        {
            encontrado = true;
            for(map<string,double>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            {
                if(it2->first != fusionar.second)
                {
                    double distancia = it2->second;
                    if(fusionar.second > it2->first)
                    {
                        distancia += tabla_dist[it2->first][fusionar.second];
                    }
                    else
                    {
                        distancia += tabla_dist[fusionar.second][it2->first];
                    }
                    aux[it2->first] = distancia / 2;
                }
            }
        }
        else
        {
            if (not encontrado)
            {
                it->second[fusionar.first+fusionar.second] = (it->second[fusionar.first] + it->second[fusionar.second]) / 2;
                it->second.erase(fusionar.first);
            }
            it->second.erase(fusionar.second);
        } 
        ++it;
    }
    tabla_dist[fusionar.first + fusionar.second] = aux;
    tabla_dist.erase(fusionar.first);
    tabla_dist.erase(fusionar.second);
}

void Cjt_clusters::imprime_tabla_distancias()
{
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

bool Cjt_clusters::imprime_cluster(string id)
{
    if (bosque.find(id) != bosque.end())
    {
        imprime_clusters(bosque[id]);
        return true;
    }
    else return false;
}

void Cjt_clusters::imprime_clusters(const BinTree<pair<string,double>>& arbol)
{
    if (not arbol.empty())
    {
        cout << '[';
        if (arbol.value().second != 0) cout << '(' << arbol.value().first << ", " << arbol.value().second  << ") ";
        else cout << arbol.value().first;
        imprime_clusters(arbol.left());
        imprime_clusters(arbol.right());
        cout << ']';
    }
}

bool Cjt_clusters::imprime_arbol_filogenetico(Cjt_especies& Conjunto)
{
    inicializar_clusters(Conjunto);
    if (bosque.size() == 0) return false;
    arbol_filogenetico();
    imprime_clusters(bosque.begin()->second);
    return true;
}