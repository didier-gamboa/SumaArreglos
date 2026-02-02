# Tarea 1 — Suma Paralela de 2 Arreglos (OpenMP)

## Descripción del proyecto
Este proyecto implementa una **suma paralela de dos arreglos** usando **OpenMP** en C++.

El programa:

- Declara tres arreglos `a`, `b` y `c` de tamaño `N`.
- Asigna valores a `a` y `b` (basados en un cálculo simple).
- Realiza la suma **en paralelo** con un `for` paralelizado mediante `#pragma omp parallel for`.
- Guarda el resultado en `c`.
- Imprime evidencia del paralelismo indicando **qué hilo** tomó cada bloque de trabajo (según el tamaño `chunk`).
- Imprime los primeros `mostrar` elementos de `a`, `b` y `c` para verificar el resultado.

**Archivo principal:** `SumaArreglo.cpp`


## Setup en Mac (Apple Silicon / M3)

En macOS, para compilar con OpenMP de forma sencilla se recomienda usar **GCC** instalado con Homebrew.

### 1) Instalar Homebrew (si no lo tienes)
Puedes instalarlo desde el sitio oficial de Homebrew.

### 2) Instalar GCC
```bash
brew install gcc
```

### 3) Verificar versión disponible de g++
Homebrew instala `g++` con sufijo de versión (por ejemplo `g++-14`):

```bash
ls /opt/homebrew/bin/g++-*
```

---

## Compilación y ejecución

### Compilar con OpenMP
Reemplaza `g++-14` por la versión que tengas instalada (por ejemplo `g++-13`, `g++-15`, etc.).

```bash
/opt/homebrew/bin/g++-14 SumaArreglo.cpp -fopenmp -o SumaArreglo
```

### Ejecutar
```bash
./SumaArreglo
```


## Notas
- El valor de `chunk` define el tamaño de los “bloques” que cada hilo procesa con `schedule(static, chunk)`.
- Para experimentar, puedes cambiar en el código:
  - `N` (tamaño de los arreglos),
  - `chunk` (tamaño de bloque por hilo),
  - `mostrar` (cuántos elementos se imprimen).
