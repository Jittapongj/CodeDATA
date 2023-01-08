#include <stdio.h>

struct me {
    int age;
    int height;
    int weight;
};

void set( struct me *state ); //Prototype

int main() {
    struct me d;
    set(&d);
    printf("Toon age : %d year\n", d.age);
    printf("Toon height : %d cm\n", d.height);
    printf("Toon weight : %d kg\n", d.weight);
    return 0;
}

void set( struct me *state ){
    (*state).age = 21;
    (*state).height = 175;
    (*state).weight = 52;
}