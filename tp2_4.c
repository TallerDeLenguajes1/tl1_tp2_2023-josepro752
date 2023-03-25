#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct compu {
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
};

void presentar (struct compu lista[]);
void masVieja (struct compu lista[]);
void mayorVelocidad (struct compu lista[]);

int main () {
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    srand(time(NULL));
    struct compu pcs[5];
    int aleatorio;
    for (int i = 0; i < 5;i++) {
        aleatorio = 1 + rand() % 3;
        pcs[i].velocidad = aleatorio;
        aleatorio = 2015 + rand() % 8;
        pcs[i].anio = aleatorio;
        aleatorio = 1 + rand() % 8;
        pcs[i].cantidad = aleatorio;
        aleatorio = 0 + rand() % 6;
        pcs[i].tipo_cpu = tipos[aleatorio];
    }
    presentar(pcs);
    masVieja(pcs);
    mayorVelocidad(pcs);
    return 0;
}

void presentar (struct compu lista[]) {
    for (int i = 0; i < 5;i++) {
        printf("*** Computadora numero %d ***\n", (i+1));
        printf("Procesador: ");
        puts(lista[i].tipo_cpu);
        printf("Velocidad en GHz: %d\n", lista[i].velocidad);
        printf("Anio de fabricacion: %d\n", lista[i].anio);
        printf("Cantidad de nucleos: %d\n\n", lista[i].cantidad);
    }
}

void masVieja (struct compu lista[]) {
    int vieja = 9999;
    int ite;
    for (int i = 0; i < 5;i++) {
        if (lista[i].anio < vieja) {
            vieja = lista[i].anio;
            ite = i;
        }
    }
    printf("*** Computadora mas vieja ***\n");
    printf("Procesador: ");
    puts(lista[ite].tipo_cpu);
    printf("Velocidad en GHz: %d\n", lista[ite].velocidad);
    printf("Anio de fabricacion: %d\n", lista[ite].anio);
    printf("Cantidad de nucleos: %d\n\n", lista[ite].cantidad);
}

void mayorVelocidad (struct compu lista[]) {
    int velocidad = 0;
    int ite;
    for (int i = 0; i < 5;i++) {
        if (lista[i].velocidad > velocidad) {
            velocidad = lista[i].velocidad;
            ite = i;
        }
    }
    printf("*** Computadora mas veloz ***\n");
    printf("Procesador: ");
    puts(lista[ite].tipo_cpu);
    printf("Velocidad en GHz: %d\n", lista[ite].velocidad);
    printf("Anio de fabricacion: %d\n", lista[ite].anio);
    printf("Cantidad de nucleos: %d\n\n", lista[ite].cantidad);
}