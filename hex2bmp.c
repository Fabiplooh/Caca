#include <stdio.h>
#include <stdlib.h>

void BMP_ecris(FILE * dest, __uint8_t** matrice, int l, int c){
    fwrite("BM", 1, 2, dest);
    __uint8_t tmp = 0;
    fwrite(&tmp, 0, 1, dest); //taille à 0 pour le moment
    fwrite(&tmp, 2, 1, dest); //Reservé
    fwrite(&tmp, 2, 1, dest); //Reservé
    fwrite(&tmp, 4, 1, dest); //Offset

    fwrite(&tmp, 4, 1, dest);
    fwrite(&c, 4, 1, dest);
    fwrite(&l, 4, 1, dest);
} 

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Mauvais nombre d'arguments\n");
    } else {
        FILE* s = fopen(argv[1], "r");
        FILE* d = fopen(argv[2], "w");
        if(s == NULL || d == NULL) {
            printf("Erreur lors de l'ouverture des fichiers\n");
        } else {
            int l;
            int c;
            char tmp;
            fscanf(s, "%d", &l);
            fscanf(s, "%d", &c);
            if(!l || !c) {
                printf("Erreur lors de la lecture des dimensions\n");
            } else {
                __uint8_t** m = malloc(l*sizeof(__uint8_t*));
                if(m == NULL) {
                    printf("Erreur lors de l'allocation de la matrice\n");
                } else {
                    for(int i = 0; i<l; i++) {
                        m[i] = malloc(c*sizeof(__uint8_t));
                        if(m[i] == NULL) {
                            printf("Erreur lors de l'allocation de la matrice\n");
                        } else {
                            for(int j = 0; j<c; j++) {
                                fscanf(s, "%hhx", &m[i][j]);
                                printf("%hhx ", m[i][j]);
                                fscanf(s, "%c", &tmp);
                            }
                        }
                    }
                }
            }
        }
        fclose(s);
        fclose(d);
    }
}
