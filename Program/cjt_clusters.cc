#include "cjt_clusters.hh"

void Cjt_clusters::inicializar_clusters(Cjt_especies& Conjunto)  //transformarlo en un void que actualize bosque
{
    map<string,BinTree<tabla>> aux;
    vector<string> v = Conjunto.identificadores();
    int dimensiones = v.size();
    for (int i = 0; i < dimensiones; ++i)
    {
        aux[v[i]];
    }
    
    bosque = aux;
}


tabla Cjt_clusters::distancia_minima()
{
    int mida = tabla_dist.size();
    tabla min = tabla_dist[0];
    for (int i = 1; i < mida; ++i)
    {
        if (min.distancia > tabla_dist[i].distancia) min = tabla_dist[i];
    }
    return min;
}

void  Cjt_clusters::wpgma(Cjt_especies& Conjunto)
{
    tabla fusionar = distancia_minima();
    bosque[fusionar.id1 + fusionar.id2] =  BinTree<tabla>(fusionar,bosque[fusionar.id1],bosque[fusionar.id2]);
    bosque.erase(fusionar.id1);
    bosque.erase(fusionar.id2);
    actualizar_tabla(Conjunto);
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
