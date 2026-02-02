#include <iostream>
#include <omp.h>

// Constantes de “precompilación”
#define N 1000
#define chunk 100
#define mostrar 10

// Prototipo
void imprimeArreglo(float *d);

int main()
{
    std::cout << "Suma Paralela de 2 Arreglos con OpenMP\n";

    // Arreglos
    float a[N], b[N], c[N];
    int i;

    // Asignación de valores (puedes cambiar la fórmula o usar aleatorios)
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10.0f;
        b[i] = (i + 3) * 3.7f;
    }

    // Tamaño de pedazos
    int pedazos = chunk;

    // Evidencia: cuántos hilos usa OpenMP
    #pragma omp parallel
    {
        #pragma omp single
        std::cout << "OpenMP usando " << omp_get_num_threads()
                  << " hilos | chunk=" << pedazos << "\n";
    }

    // For paralelo con OpenMP + evidencia de qué hilo toma cada bloque
    #pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];

        // Evidencia: imprime el inicio de cada "chunk"
        if (i % pedazos == 0)
        {
            int tid = omp_get_thread_num();
            #pragma omp critical
            std::cout << "Inicio de bloque i=" << i
                      << " -> hilo " << tid
                      << " | c[i]=" << c[i] << "\n";
        }
    }

    // Impresión para comprobar (primeros "mostrar" valores)
    std::cout << "\nArreglo a (primeros " << mostrar << "):\n";
    imprimeArreglo(a);

    std::cout << "\nArreglo b (primeros " << mostrar << "):\n";
    imprimeArreglo(b);

    std::cout << "\nArreglo c = a + b (primeros " << mostrar << "):\n";
    imprimeArreglo(c);

    return 0;
}

// Implementación
void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << d[x] << " - ";
    }
    std::cout << "\n";
}
