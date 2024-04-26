#include <stdio.h>
#include <math.h>

int main() {
    float monto, tasaInteres, interesTotal = 0;
    int plazo;


    printf("Ingrese el monto del prestamo: ");
    scanf("%f", &monto);

    printf("Ingrese la tasa de interes (en porcentaje): ");
    scanf("%f", &tasaInteres);


    tasaInteres /= 100;


    printf("Ingrese el plazo del prestamo (en años): ");
    scanf("%d", &plazo);

    
    float r = tasaInteres / 12;
    int n = plazo * 12;
    float cuota = (monto * r) / (1 - pow(1 + r, -n));

    
    printf("\n| Año\t| Interes\t| Cuota\t\t|\n");

    
    float saldo = monto;
    for (int i = 1; i <= plazo; i++) {
        
        float interes = saldo * tasaInteres;
        interesTotal += interes;
        
        
        saldo += interes + cuota * 12;
        
        
        printf("| %d\t| %.2f\t\t| %.2f\t\t|\n", i, interes, cuota * 12);
    }


    
    printf("El total de intereses acumulados es: %.2f\n", interesTotal);
    printf("El saldo final es: %.2f\n", saldo);

    return 0;
}