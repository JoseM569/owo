/*  * Universidad de La Frontera
 * Ingeniería Civil Electrónica/Telemática
 *
 * IIE-344 ESTRUCTURA DE DATOS Y ALGORITMOS
 *
 * Tarea 1
 *
 * Autor 1: Felipe Cuevas (f.cuevas04@ufromail.cl)
 * Autor 2: José Morales  (j.morales14@ufromail.cl)
 *
 * Fecha: viernes 19 de abril de 2024
 *
 * Descripción general del programa: Este programa permite gestionar los recursos humanos de una empresa, permitiendo registrar, listar, buscar, editar y eliminar trabajadores
 *Guardando la información en un archivo de texto llamado personal.txt y un archivo de texto llamado indice.txt.
 * Descripción de la organización: La organización es una empresa de desarrollo de software, que cuenta con 5 cargos: Desarrollador, Analista, Tester, Jefe de Proyecto y Gerente.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h> //Permite utilizar el getch(); que a diferencia del system(pasue); no traba el codigo,
#include "./lib/modificacion_trabajadores.h"
#include "./lib/busqueda_trabajadores.h"

void Ingreso_trabajadores();
void listatrabajadores();
void buscar_por_cargo();
void buscar_por_nombre();
void buscar_por_apellido();
void editartrabajador(int numlinea);
void eliminartrabajador(int numlinea);

char cadena[100];
int num_linea = 0;
int main()
{

    int opcion = 1;

    while (opcion != 8)
    {

        printf("\n********** Gestioon de recursos Humanos Empresa DMP SOFTWARE LTDA **********\n"); // Menu de opciones
        printf("\t  *1:Ingresar trabajador\n");
        printf("\t  *2:Listar trabajadores \n");
        printf("\t  *3:Listar trabajadores con mismo cargo\n");
        printf("\t  *4:Buscar trabajador por nombre\n");
        printf("\t  *5:Buscar trabajador por apellido\n");
        printf("\t  *6:Editar un trabajador\n");
        printf("\t  *7:Eliminar trabajador\n");
        printf("\t  *8:Terminar programa.\n");
        printf("***********************************************\n");
        printf("Indicar una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:
            printf("Registrar trabajador\n"); // TIPO DE DATO DEL TELEFONO.
            Ingreso_trabajadores();
            break;

        case 2:
            printf("Listar trabajadores: \n"); // LESTO
            listatrabajadores();
            break;

        case 3:
            printf("Listar trabajadores de un mismo cargo\n"); // LESTO
            buscar_por_cargo();
            break;

        case 4:
            printf("Buscar por nombre\n"); // A LA MITAD
            buscar_por_nombre();
            break;

        case 5:
            printf("Buscar por apellido\n"); // Lesto
            buscar_por_apellido();
            break;

        case 6:
            printf("Editar un trabajador\n"); // Lesto
            listatrabajadores();
            printf("\nElija el numero del trabajador que desea editar: ");
            scanf("%d", &num_linea);
            editartrabajador(num_linea);
            printf("\nSe ha editado correctamente al trabajador.\n");
            printf("Presione cualquier boton para continuar.");
            getch();
            break;

        case 7:

            printf("Eliminar trabajador\n");
            listatrabajadores();
            printf("\nElija el numero del trabajador que desea eliminar: ");
            scanf("%d", &num_linea);
            eliminartrabajador(num_linea);
            printf("Se ha eliminado correctamente al trabajador.\n");
            printf("Presione cualquier boton para continuar.");
            getch();
            break;

        case 8:
            printf("Cerrando programa Gestion de recursos humanos Empresa DMP SOFTWARE LTDA.\n");
            break;

        default:
            printf("Opcion no valida.\n");
        }
    }

    return 0;
}






