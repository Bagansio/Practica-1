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
/*
void  Cjt_clusters::wpgma(Cjt_especies& Conjunto)
{
    double dist;
    pair<string,string> fusionar = distancia_minima(dist);
    bosque[fusionar.first + fusionar.second] =  BinTree<pair<string,double>>(make_pair(fusionar.first + fusionar.second,dist),bosque[fusionar.first],bosque[fusionar.second]);
    bosque.erase(fusionar.first);
    bosque.erase(fusionar.second);
    //actualizar_tabla(Conjunto);
}

void Cjt_clusters::actualizar_tabla(Cjt_especies& Conjunto,const tabla& fusionar)
{
    int elementos = tabla_dist.size();
    elementos -= bosque.size();

    vector<tabla> aux(elementos);
    int izq,der;
    izq = der = 0;
    for (int i = 0; i < elementos; ++i)
    {
        bool meter = false;
        while (not meter)
        {
            if (tabla_dist[izq] == fusionar) ++izq;
            else if (fusionar.id1 == tabla_dist[izq].id1 or fusionar.id1 == tabla_dist[izq].id2)
            
                while(tabla_dist[der].id1 == fusionar.id2)
            }
            
        }
        if(tabla_dist[izq])


        while(tabla_dist[j]. and tabla_dist[k].)
        {
            if (tabla_dist[j]) ++j;
            if (tabla_dist[k]) ++k;
        }
    }
}
*/