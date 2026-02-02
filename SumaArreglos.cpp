#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10


void imprimeArreglo(float *d);

int main()
{
    std::cout << "Suma Paralela de 2 Arreglos con OpenMP\n";

    // Arreglos
    float a[N], b[N], c[N];
    int i;

    // Asignación de valores 
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10.0f;
        b[i] = (i + 3) * 3.7f;
    }

    // Tamaño de pedazos
    int pedazos = chunk;

    #pragma omp parallel
    {
        #pragma omp single
        std::cout << "OpenMP usando " << omp_get_num_threads()
                  << " hilos | chunk=" << pedazos << "\n";
    }

    #pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];

        if (i % pedazos == 0)
        {
            int tid = omp_get_thread_num();
            #pragma omp critical
            std::cout << "Inicio de bloque i=" << i
                      << " -> hilo " << tid
                      << " | c[i]=" << c[i] << "\n";
        }
    }

    // Impresión para comprobar 
    std::cout << "\nArreglo a (primeros " << mostrar << "):\n";
    imprimeArreglo(a);

    std::cout << "\nArreglo b (primeros " << mostrar << "):\n";
    imprimeArreglo(b);

    std::cout << "\nArreglo c = a + b (primeros " << mostrar << "):\n";
    imprimeArreglo(c);

    return 0;
}

void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << d[x] << " - ";
    }
    std::cout << "\n";
}
