#include <stdio.h>

struct Toon {
    int age;
    int height;
    int weight;
};

int main() {
    struct Toon body;
    body.age = 21;
    body.height = 175;
    body.weight = 52;
    printf("Toon age : %d year\n", body.age );
    printf("Toon height : %d cm\n", body.height );
    printf("Toon weight : %d kg\n", body.weight );
    return 0;
}