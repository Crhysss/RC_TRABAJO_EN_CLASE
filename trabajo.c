#include <stdio.h>
#include <locale.h>
/*Este programa guarda los datos de estudiantes que ingresaron a la Universidad en 7 carreras
en cinco años. El usuario, mediante un menú, puede visualizar 1. Año en el que ingresaron más estudiantes
2. Carrera con más alumnos en el último año 3. Año en donde más alumnos ingresaron a Ing. de Software*/

void opcion1(int matriz2017[7][2],int matriz2018[7][2], int matriz2019[7][2], int matriz2020[7][2],int matriz2021[7][2]);

int main(){
    //esta función permite establecer una configuraci´´on regional para poder imprimir carcateres especiales como "ñ" o las tildes
    setlocale(LC_ALL, "");
    int opcion;
    //se establecen los valores de las matrices para luego hacer los calculos y comparaciones
    int matriz2017[7][2]={
        {100,50},{150,75},{152,70},{10,8},{5,4},{70,60},{80,30}   };
    int matriz2018[7][2]={
        {150,155},{30,20},{100,50},{5,100},{99,86},{78,54},{3,60} };
    int matriz2019[7][2]={
        {200,115},{100,78},{90,65},{50,42},{20,15},{15,7},{60,89} };
    int matriz2020[7][2]={
        {28,92},{183,18},{33,32},{93,93},{123,26},{51,34},{52,54} };
    int matriz2021[7][2]={
        {156,78},{200,46},{75,38},{90,47},{34,15},{82,98},{69,74} };
    //función switch para imprimir un menú
    do {
        printf("---- Men\xFA ----\n 1. A\xf1o en el que ingreso la mayor cantidad de alumnos\n 2. Carrera que recibi\xF3 la mayor cantidad de alumnos en el \xFaltimo a\xf1o\n 3. A\xf1o en donde Software recibi\xF3 la mayor cantidad de alumnos\n 4. Salir\n Opcion:  ");
        scanf("%d", &opcion);
//system ("cls") para borrar los mensajes mostrados anteriormente
        switch (opcion) {
            case 1:
                system("cls");
                opcion1(matriz2017,matriz2018,matriz2019,matriz2020,matriz2021);
                break;
            case 2:
                system("cls");
                opcion2(matriz2021);
                break;
            case 3:
                system("cls");
                opcion3(matriz2017,matriz2018,matriz2019,matriz2020,matriz2021);
                break;
            case 4:
                system("cls");
                printf("Saliendo...\n");
                break;
            default:
                system("cls");
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
        }
        printf("\n");

    } while (opcion != 4);
}
//funcion llamada opcion1 que se encarga de resolver la primera pregunta
void opcion1(int matriz2017[7][2],int matriz2018[7][2], int matriz2019[7][2], int matriz2020[7][2],int matriz2021[7][2]){
    int i, j;
    int mayor = 0;
    int anoMayor = 0;
    int sumas[5] = {0};
    int anos[5] = {2017, 2018, 2019, 2020, 2021};
//dentro del vector sumas se registra la suma de cada matriz para despues entrar a la condición IF
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 2; j++) {
            sumas[0] += matriz2017[i][j];
            sumas[1] += matriz2018[i][j];
            sumas[2] += matriz2019[i][j];
            sumas[3] += matriz2020[i][j];
            sumas[4] += matriz2021[i][j];
        }
    }
    for (i = 0; i < 5; i++) {
        if (sumas[i] > mayor) {
            mayor = sumas[i];
            anoMayor = anos[i];
        }
    }
    printf("El a\xf1o en donde m\xE1s estudiantes ingresaron a la universidad fue %d.\n", anoMayor);
    //el quetenga suma mayor es el año en donde mas estudiantes entraron
}
void opcion2(int matriz2021[7][2]) {
    int i, j;
    int total;
    int mayor=0, fila=0;
    //en este string se le pone nombre a cada fila de la ultima matriz
    char carreras[7][25]={
        "Ing. Software","Administraci\xF3n", "Econom\xEDa", "Relaciones internacionales", "Matem\xE1ticas","Contabilidad", "Ing. Industrial" 
    };
    //solo se suma la primera fila
    for (i = 0; i < 7; i++) {
        total= 0;
        for (j = 0; j < 2; j++) {
            total+= matriz2021[i][j];
            if(total>mayor){
                mayor=total;
                fila=i;
            }
        }
    }
    printf("La carrera en donde mas estudiantes ingresaron el ultimo a\xf1o es: %s\n",carreras[fila]);
}
void opcion3(int matriz2017[7][2], int matriz2018[7][2], int matriz2019[7][2], int matriz2020[7][2], int matriz2021[7][2]){
    int i,j;
    int mayor=0;
    int anoMayor=0;
    //al igual que en la funcion opcion1 se ocupa el vector sumas y años para determinar en que año entraron más estudiantes
    int sumas[5] = {0};
    int anos[5] = {2017, 2018, 2019, 2020, 2021};
    for(i=0;i<1;i++){
        for(j=0;j<1;j++){
            sumas[0] += matriz2017[i][j];
            sumas[1] += matriz2018[i][j];
            sumas[2] += matriz2019[i][j];
            sumas[3] += matriz2020[i][j];
            sumas[4] += matriz2021[i][j];
        }
    }
    for (i = 0; i < 5; i++) {
        if (sumas[i] > mayor) {
            mayor = sumas[i];
            anoMayor = anos[i];
        }
    }
    printf("El a\xf1o en donde m\xE1s estudiantes ingresaron a la carrera de Ing. Software fue: %d\n", anoMayor);
}