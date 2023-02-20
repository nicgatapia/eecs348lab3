#include <stdio.h>
int main() {
    FILE *myFile;
    myFile = fopen("input.txt", "r");
    float monthArray[12];

    for (int i = 0; i < 12; ++i){
        fscanf(myFile, "%f\n", &monthArray);
    }

    for (int k = 0; k < 12; ++k){
        printf("%f\n", monthArray[k]);
    }
}

