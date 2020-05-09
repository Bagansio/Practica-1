#include "Cluster.hh"

Cluster::~Cluster()
{
    destrucion_recursiva(arbol);
}


void Cluster::destrucion_recursiva(BinTree<string>& aux)
{
        destrucion_recursiva(aux.left());
        destrucion_recursiva(aux.right());
        delete aux;
}

Cluster::Cluster(Cjt_especies& Conjunto)
{
    Matrix tabla = Conjunto.tabla_distancias();
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
    string derecha = Conjunto.obtener_id(min_f);
    string izquierda = Conjunto.obtener_id(min_c);
    if (derecha < izquierda)
    {
        string aux = derecha;
        derecha = izquierda;
        izquierda = aux;
    }
    BinTree<string> left(izquierda);
    BinTree<string> right(derecha);
    arbol = BinTree<string> (izquierda+derecha,left,right);
}

Cluster::Cluster(string id, Cluster& izq, Cluster& derecha)
{
    arbol = BinTree<string>(id,izq.arbol.left(),derecha.arbol.right());
}

Cluster Cluster::izquierda()
{
    Cluster aux;
    aux.arbol = arbol.left();
    return aux;
}

Cluster Cluster::derecha()
{
    Cluster aux;
    aux.arbol = arbol.right();
    return aux;
}

void Cluster::imprime_cluster()
{
    if (not arbol.empty())
    {
        
        izquierda().imprime_cluster();
        cout << arbol.value() << endl;
        derecha().imprime_cluster();
    }
}