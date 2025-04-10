#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char nombres[5][30];
    char Materias[3][30];
    float calificaciones[5][3];
    int estudiantes = 5;
    int asignaturas_count = 3;
    int Contador = 0, cont1 = 0, Seleccion, Longitud;
    do
    {
        printf("_____________________________________________\n");
        printf("Seleccione la opcion.\n");
        printf("1. Registrar estudiantes.\n");
        printf("2. Registro de materias.\n");
        printf("3. Ingreso de calificaciones de las materias.\n");
        printf("4. Resultados de las calificaciones.\n");
        printf("5. Resultados de los estudiantes y sus respectivas notas.\n");
        printf("6. Salir\n");
        printf("_____________________________________________\n");
        printf(">>>>:");
        scanf("%d", &Seleccion);
        switch (Seleccion)
        {
        case 1:
            if (Contador < 5)
            {
                for (int i = 0; i < 5; i++)
                {
                    printf("Ingrese el nombre del estudiante %d: ", Contador + 1);
                    fflush(stdin);
                    fgets(nombres[Contador], 30, stdin);
                    Longitud = strlen(nombres[Contador]) - 1;
                    nombres[Contador][Longitud] = '\0';
                    Contador++;
                }
            }
            else
            {
                printf("No se pueden ingresar mas estudiantes.\n");
            }
            break;
        case 2:
            if (cont1 < 3)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("Ingrese el nombre de la materia %d: ", cont1 + 1);
                    fflush(stdin);
                    fgets(Materias[cont1], 30, stdin);
                    Longitud = strlen(Materias[cont1]) - 1;
                    Materias[cont1][Longitud] = '\0';
                    cont1++;
                }
            }
            else
            {
                printf("No se pueden ingresar mas materias.\n");
            }
            break;
        case 3:
            for (int i = 0; i < estudiantes; i++)
            {
                printf("Estudiante: %s\n", nombres[i]);
                for (int j = 0; j < asignaturas_count; j++)
                {
                    float nota;
                    do
                    {
                        printf("Nota en %s (0-10): ", Materias[j]);
                        scanf("%f", &nota);
                        if (nota < 0 || nota > 10)
                            printf("Recuerde solo puede ingresar notas superiores a 0 e inferiores a 10.\n Intente de nuevo.\n");
                    } while (nota < 0 || nota > 10);
                    calificaciones[i][j] = nota;
                }
            }
            break;
        case 4:
            printf("\nResultados de calificaciones.\n");
            printf("%-15s", "Estudiante");
            for (int j = 0; j < asignaturas_count; j++)
            {
                printf("| %-15s", Materias[j]);
            }
            printf("\n");
            for (int i = 0; i < estudiantes; i++)
            {
                printf("%-15s", nombres[i]);
                for (int j = 0; j < asignaturas_count; j++)
                {
                    printf("| %-15.2f", calificaciones[i][j]);
                }
                printf("\n");
            }
            break;
            break;
        case 5:
            printf("\nPromedio por estudiante:\n");
            for (int i = 0; i < estudiantes; i++)
            {
                float suma = 0;
                for (int j = 0; j < asignaturas_count; j++)
                {
                    suma += calificaciones[i][j];
                }
                printf("%s: %.2f\n", nombres[i], suma / asignaturas_count);
            }
            printf("\nPromedio por asignatura:\n");
            for (int j = 0; j < asignaturas_count; j++)
            {
                float suma = 0;
                for (int i = 0; i < estudiantes; i++)
                {
                    suma += calificaciones[i][j];
                }
                printf("%s: %.2f\n", calificaciones[j], suma / estudiantes);
            }
            printf("\nMaxima nota y minima nota por estudiante:\n");
            for (int i = 0; i < estudiantes; i++)
            {
                float max = calificaciones[i][0], min = calificaciones[i][0];
                for (int j = 1; j < asignaturas_count; j++)
                {
                    if (calificaciones[i][j] > max)
                        max = calificaciones[i][j];
                    if (calificaciones[i][j] < min)
                        min = calificaciones[i][j];
                }
                printf("%s -> Máx: %.2f, Mín: %.2f\n", nombres[i], max, min);
            }
            printf("\nMaxima nota y minima nota por asignatura:\n");
            for (int j = 0; j < asignaturas_count; j++)
            {
                float max = calificaciones[0][j];
                float min = calificaciones[0][j];

                for (int i = 1; i < estudiantes; i++)
                {
                    if (calificaciones[i][j] > max)
                        max = calificaciones[i][j];
                    if (calificaciones[i][j] < min)
                        min = calificaciones[i][j];
                }

                printf("%s -> Máx: %.2f, Mín: %.2f\n", calificaciones[j], max, min);
            }
            printf("\nAprobados y reprobados por asignatura:\n");
            for (int j = 0; j < asignaturas_count; j++)
            {
                int aprobados = 0;
                for (int i = 0; i < estudiantes; i++)
                {
                    if (calificaciones[i][j] >= 6)
                    {
                        aprobados++;
                    }
                }
                int reprobados = estudiantes - aprobados;
                printf("%s estudiante aprobados: %d, estudiante reprobados: %d\n", Materias[j], aprobados, reprobados);
            }
            break;
        case 6:
            printf("Ejecucion Finalizada.");
            break;
        default:
            break;
        }
    } while (Seleccion != 6);
    return 0;
}