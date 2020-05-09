#include "Cluster.hh"

Cluster::Cluster(const Cjt_especies& Conjunto, int k)
{
    Matrix tabla = Conjunto.tabla_distancias(k);
    int min_f, min_c;
    min_f = min_c = 0;
    int n = tabla.size();
    double min = tabla[0][1];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (tabla[i][j] < min)
            {
                min = tabla[i][j];
                min_f = i;
                min_c = j;
            }
        }
    }
    Especie derecha = Conjunto.obtener_especie_posicion(min_f);
    Especie izquierda = Conjunto.obtener_especie_posicion(min_c);
    if (derecha.consultar_id() < izquierda.consultar_id())
    {
        Especie aux = derecha;
        derecha = izquierda;
        izquierda = aux;
    }
}