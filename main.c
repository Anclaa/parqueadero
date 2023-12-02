#include <stdio.h> 
#include <math.h>

int cant_p = 0;
char placa[10][10];
char modelo[10][5];
char colores[10][5];
int autofuera[10];

void agregarAuto() {
    if (cant_p >= 50) {
        printf("El inventario está lleno\n");
        return;
    }
    printf("Ingrese la placa: ");
    scanf("%s", &placa[cant_p]);

    printf("Ingrese el modelo: ");
    scanf("%s", &modelo[cant_p]);

    printf("Ingrese el color: ");
    scanf("%s", &colores[cant_p]);
    cant_p++;
    printf("Auto agregado agregado con éxito\n");
}

float horas(int hora, int minutos) {
  int ht;
  hora = hora * 60;
  ht = hora + minutos;
  return ht;
}

float calc_hora(float a, float b) {
  float hf;
  if(a>b){
    hf= a-b;
  }
  if(a<b){
    hf= b-a;
  }
  return hf;
}

float precio_fra(float f){
  float pf;
  pf = f*1.5;
  return pf;
}

void mostrarParqueadero() {
    printf("Parqueadero de autos:\n");

    for (int i = 0; i < cant_p; i++) {
        if (strcmp(placa[i], "0") != 0) {
            printf("Auto %d:\n", i + 1);
            printf("Placa: %s\n", placa[i]);
            printf("Modelo: %s\n", modelo[i]);
            printf("Color: %s\n", colores[i]);

            if (autofuera[i]!= 0) {
                printf("Estado: Ya salió\n");
            } else {
                printf("Estado: Aún está estacionado\n");
            }

            printf("\n");
        }
    }
}

int main() {

    int op;
    int h,min, he, hf, minf;
    char a[10];
    float b,c;

    do {
        printf("Menu:\n");
        printf("1. Agregar AUTO\n");
        printf("2. buscar AUTO\n");
        printf("3. sacar auto\n");
        printf("4 salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                agregarAuto();
                printf("Ingrese la hora de entrada: ");
                scanf("%d",&h);
                printf("Ingrese el minuto de entrada: ");
                scanf("%d",&min);
                he= horas(h, min);
                break;
            case 2:
                printf("Que auto gusta buscar: ");
                scanf("%s", &a);
                for (int i = 0; i < 10; i++) {
                    if(strcmp(placa[i],a)==0){
                    printf("Auto %d:\n", i + 1);
                    printf("Placa: %s\n", placa[i]);
                    printf("Modelo: %s\n", modelo[i]);
                    printf("Color: %s\n", colores[i]);
                    
                    printf("\n");
                    break;
                    }
                }
                break;
            case 3:
                printf("Cual es el auto a salir: ");
                scanf("%s", &a);
                for (int i = 0; i < 10; i++) {
                    if(strcmp(placa[i],a)==0){
                    printf("Auto %d:\n", i + 1);
                    printf("Placa: %s\n", placa[i]);
                    printf("Modelo: %s\n", modelo[i]);
                    printf("Color: %s\n", colores[i]);
                    autofuera[i] = 1;
                    printf("\n");
                      break;
                    }
                }
                printf("Ingrese la hora de salida: ");
                scanf("%d",&hf);
                printf("Ingrese el minuto de salida: ");
                scanf("%d",&minf);
                hf= horas(hf, minf);
                b=calc_hora(he, hf);
                b = b/60;
                c=precio_fra(b);
                printf("El precio a pagar es: %.2f\n", ceil(c));
                printf("El vehiculo ha salido\n.");
                break;
            case 4:
              printf("Saliendo del programa...\n");
                break;
            default:
                  printf("Opción inválida\n");
                  break;
        }
    } while (op != 4);

  printf("\nEstado del parqueadero\n");
  mostrarParqueadero();
  
    return 0;
}