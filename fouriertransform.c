//
// Created by remo on 25.09.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definition of constant variables
#define PI 3.14159265358979323846
#define N 1024

// What is this doing?
typedef struct {
    double real;
    double imag;
} Complex;

Complex calculate_fouriertransformation(double *data, int k) {
    Complex result = {0.0, 0.0};

    for (int n = 0; n < N; n++) {
        double theta = -2.0 * PI * k * n / N;
        result.real += data[n] * cos(theta);
        result.imag += data[n] * sin(theta);
    }

    return result;
}

int main() {
    FILE *file = fopen("C:\\Users\\remo\\OneDrive\\Dokumente\\Studio\\Canon Impact Edit.wav", "rb");
    if (!file) {
        printf("Could not open file\n");
        return 1;
    }

    double *data = (double*) malloc(sizeof(double) * N);
    Complex *spectrum = (Complex*) malloc(sizeof(Complex) * N);

    while (fread(data, sizeof(double), N, file) == N) {
        for (int k = 0; k < N; k++) {
            spectrum[k] = calculate_fouriertransformation(data, k);
            printf("%d: %f + %fi\n", k, spectrum[k].real, spectrum[k].imag);
        }
    }

    fclose(file);
    free(data);
    free(spectrum);

    return 0;
}