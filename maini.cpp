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

void Ingreso_trabajadores()
{

    /*
     * Nombre de la función: Ingreso_trabajadores.
     * Tipo de función: void.
     * Parámetros: La funcion no recibe ningun parametro.
     * Dato de retorno: Ninguno ya que es un void;
     * Descripción de la función: La funcion Ingreso_trabajadores abre los archivos "personal.txt" con el modo de apertura "a+" que permite lectura y escritura del archivo, ademas si el archivo no existiera este lo crearia,
        * e "indice.txt" con el modo de apertura "a" que permite agregar informacion al final del archivo.
        *Una vez definidos los archivos con el comando FILE* nombredearchivo , y abiertos con el comando fopen("nombrearchivo","modo de apertura"); procedemos a definir distintas variables de tipo char e int que nos
        *ayudaran a almacenar los datos para registrar un trabajador, luego pondremos un if-else que nos pondra la posicion de los datos en personal de forma [posicion]apellido,cargo en el indice.txt
        *Luego procedemos a preguntarle al usuario los distintos datos y guardamos esa informacion en las variables correspondientes para luego imprimla en una linea en nuestros archivos de texto.
        *Finalmente cerramos los archivos con el comando fclose(nombrearchivo); y mostramos un mensaje en pantalla de que se ha realizado el registro correctamente.
     */

    FILE *personal = fopen("personal.txt", "a+");
    FILE *indice = fopen("indice.txt", "a");

    char nombre[15], apellido[15], correo[50], rut[10], f_contratacion[10];
    int telefono, count = 1;

    if (fgets(cadena, sizeof(cadena), personal) == NULL)
    {
        fprintf(indice, "%d ", count);
    }
    else
    {
        rewind(personal);
        while (fgets(cadena, sizeof(cadena), personal) != NULL)
        {
            count++;
        }
        printf("%d\n", count);
        fprintf(indice, "%d ", count);
    }

    printf("Ingrese el nombre del trabajador: "); // Ingresar y escribir nombre del trabajador
    scanf("%s", nombre);
    fprintf(personal, "%s,", nombre);

    printf("Ingrese el apellido del trabajador: "); // Ingresar y escribir apellido del trabajador
    scanf("%s", apellido);
    fprintf(personal, "%s,", apellido);
    fprintf(indice, "%s, ", apellido);

    printf("Ingrese el rut del trabajador sin puntos y con guion: "); // Ingresar y escribir rut del trabajador
    scanf("%s", rut);
    fprintf(personal, "%s,", rut);

    printf("Ingrese el telefono del trabajador: "); // Ingresar y escribir telefono del trabajador
    scanf("%d", &telefono);
    fprintf(personal, "%d,", telefono);

    printf("Ingrese el correo del trabajador: "); // Ingresar y escribir correo del trabajador
    scanf("%s", correo);
    fprintf(personal, "%s,", correo);

    printf("Ingrese el fecha de contatacion del trabajador(DD/MM/YYYY): "); // Ingresar y escribir fecha de contratacion del trabajador
    scanf("%s", f_contratacion);
    fprintf(personal, "%s,", f_contratacion);
    printf("\n\n\n");

    int casocargo = 0;
    bool antiloop = true;

    while (antiloop)
    {

        printf("Seleccione el cargo del trabajador: "); // Ingresar y escribir cargo del trabajador
        printf("\n********** Cargos: **********\n");
        printf("\t *1:Desarrollador\n");
        printf("\t *2:Analista \n");
        printf("\t *3:Tester\n");
        printf("\t *4:Jefe de Proyecto\n");
        printf("\t *5:Gerente\n");
        printf("*************************\n");

        scanf("%d", &casocargo);

        switch (casocargo)
        {

        case 1:
            fprintf(personal, "Desarrollador\n");
            fprintf(indice, "Desarrollador\n");
            antiloop = false;
            break;

        case 2:
            fprintf(personal, "Analista\n");
            fprintf(indice, "Analista\n");
            antiloop = false;
            break;

        case 3:
            fprintf(personal, "Tester\n");
            fprintf(indice, "Tester\n");
            antiloop = false;
            break;

        case 4:
            fprintf(personal, "Jefe de Proyecto\n");
            fprintf(indice, "Jefe de Proyecto\n");
            antiloop = false;
            break;

        case 5:
            fprintf(personal, "Gerente\n");
            fprintf(indice, "Gerente\n");
            antiloop = false;
            break;

        default:
            printf("Seleccion no valida\n");
            system("pause");
        }
    }

    fclose(personal);
    fclose(indice);
    printf("Se ha registrado de manera satisfactoria al trabajador.\n");
    printf("Presione cualquier boton para continuar.");
    getch();
}

void listatrabajadores()
{

    /*
     * Nombre de la función: listatrabajadores.
     * Tipo de función: void.
     * Parámetros: La funcion no recibe ningun parametro.
     * Dato de retorno: Ninguno ya que es un void;
     * Descripción de la función: La funcion listatrabajadores abre el archivo "personal.txt" con el modo de apertura "r" que permite leer informacion de el arhivo anteriormente mencionado.
        *Una vez definido el archivo con el comando FILE* nombredearchivo , y abiertos con el comando fopen("nombrearchivo","modo de apertura"); procedemos a condicionar el funcionamiento de la
        *impresion de los miembros del personal, empezando con un if que si el archivo no se puede abrir, se imprime un mensaje de error, Luego procedemos a crear y limitar un while que se ejecutara
        *mientras fgets(cadena, sizeof(cadena), personal) no sea igual a NULL, dentro de este while se imprime en pantalla la informacion de cada linea en nuestros archivos de texto. Finalmente
        *cerramos los archivos con el comando fclose(nombrearchivo);
     */

    FILE *personal = fopen("personal.txt", "r");
    if (personal == NULL) // Si el archivo no se puede abrir, se imprime un mensaje de error
    {

        printf("Error al abrir el archivo\n");
    }
    int count = 1;
    // Leer y mostrar todas las líneas del archivo
    while (fgets(cadena, sizeof(cadena), personal) != NULL)
    {

        printf("----------------------------------------------------------------\n");
        printf("%d,%s", count, cadena);

        count++;
    }
    printf("\n----------------------------------------------------------------\n");
    fclose(personal);
    printf("Presione cualquier boton para continuar.");
    getch();
}

void buscar_por_cargo()
{

    /*
     * Nombre de la función: buscar_por_cargo.
     * Tipo de función: void.
     * Parámetros: La funcion no recibe ningun parametro.
     * Dato de retorno: Ninguno ya que es un void;
     * Descripción de la función: La funcion buscar_por_cargo define ciertas variables y arreglos a ser usados en el programa, luego abre el archivo "personal.txt" con el modo de apertura "r" que leer informacion de el arhivo anteriormente mencionado.
     *Una vez definido el archivo con el comando FILE* nombredearchivo , y abiertos con el comando fopen("nombrearchivo","modo de apertura"); pedimos al usuario que ingrese un numero que correspondera a un cargo en especifico,
     *Luego procedemos a condicionar el funcionamiento de la impresion de los miembros del personal, empezando con un switch que se ejecutara dependiendo del numero ingresado por el usuario, dentro de este switch se
     *imprime en pantalla la informacion de cada linea en nuestros archivos de texto que coincida con el cargo ingresado por el usuario. Finalmente cerramos los archivos con el comando fclose(nombrearchivo);
     */

    int cargo = 0;
    char comparador[4], Cargo_1[] = "Desarrollador", Cargo_2[] = "Analista", Cargo_3[] = "Tester", Cargo_4[] = "Jefe de Proyecto", Cargo_5[] = "Gerente";
    FILE *personal = fopen("personal.txt", "r");

    if (personal == NULL)
    {

        printf("Error al abrir el archivo.");
    }

    printf("Seleccione el cargo que desea buscar: \n");
    printf("1: Desarrollador\n2: Analista\n3: Tester\n4: Jefe de Proyecto\n5: Gerente\n");
    scanf("%d", &cargo);

    switch (cargo)
    {

    case 1:
        printf("Estos son los trabajadores con el cargo 'Desarrollador'\n");
        while (fgets(cadena, sizeof(cadena), personal) != NULL)
        {

            if (strstr(cadena, Cargo_1) != NULL)
            {

                printf("%s", cadena);
            }
        }
        break;

    case 2:
        printf("Estos son los trabajadores con el cargo 'Analista'\n");
        while (fgets(cadena, sizeof(cadena), personal) != NULL)
        {

            if (strstr(cadena, Cargo_2) != NULL)
            {

                printf("%s", cadena);
            }
        }
        break;

    case 3:
        printf("Estos son los trabajadores con el cargo 'Tester'\n");
        while (fgets(cadena, sizeof(cadena), personal) != NULL)
        {

            if (strstr(cadena, Cargo_3) != NULL)
            {

                printf("%s", cadena);
            }
        }
        break;

    case 4:
        printf("Estos son los trabajadores con el cargo 'Jefe de Proyecto'\n");
        while (fgets(cadena, sizeof(cadena), personal) != NULL)
        {

            if (strstr(cadena, Cargo_4) != NULL)
            {

                printf("%s", cadena);
            }
        }
        break;

    case 5:
        printf("Estos son los trabajadores con el cargo 'Gerente'\n");
        while (fgets(cadena, sizeof(cadena), personal) != NULL)
        {

            if (strstr(cadena, Cargo_5) != NULL)
            {

                printf("%s", cadena);
            }
        }
        break;

    default:
        printf("Opción ingresada no es válida.");
        break;
    }

    fclose(personal);
    printf("Presione cualquier boton para continuar.");
    getch();
}

void buscar_por_nombre()
{

    /*
     * Nombre de la función: buscar_por_nombre.
     * Tipo de función: void.
     * Parámetros: La funcion no recibe ningun parametro.
     * Dato de retorno: Ninguno ya que es un void;
     * Descripción de la función:La funcion buscar_por_nombre abre el archivo "personal.txt" con el modo de apertura "r" que permite la lectura del arhivo anteriormente mencionado.
     *Se crea un arreglo de caracteres llamado nombre[25]; y se le pide al usuario que ingrese un nombre para buscar, luego se crea un while que se ejecutara mientras fgets(cadena, sizeof(cadena), personal) no sea igual a NULL,lo cual hace que el valor de la linea
     *de "personal.txt" se guarde en la string linea y se ejecutara hasta que llegemos al final del archivo, en este caso es al encontrar una linea vacia en "personal.txt".
     *dentro de este while se crea un if que si strstr(cadena, nombre) no es igual a NULL, lo que hace esta condicion es primero comparar el texto guardado en cadena con el
     *el nombre ingresado en el string nombre[25]; gracias a la funcion strstr, luego  se imprime en pantalla la informacion de cada linea en nuestros archivos de texto que coincida con el nombre ingresado por el usuario.
     *Finalmente cerramos los archivos con el comando fclose(nombrearchivo);.
     */

    FILE *personal = fopen("personal.txt", "r");
    char nombre[25];
    int contador = 0;
    printf("Ingrese el nombre que desea buscar: ");
    scanf("%s", nombre);
    while (fgets(cadena, sizeof(cadena), personal) != NULL)
    {

        if (strstr(cadena, nombre) != NULL)
        {
            contador++;
            printf("%s", cadena);
        }
    }

    if (contador == 0)
    {

        printf("No hay coincidencias.\n");
    }
    fclose(personal);
    printf("Presione cualquier boton para continuar.");
    getch();
}

void buscar_por_apellido()
{

    /*
     * Nombre de la función: buscar_por_apellido.
     * Tipo de función: void.
     * Parámetros: La funcion no recibe ningun parametro.
     * Dato de retorno: Ninguno ya que es un void;
     * Descripción de la función: La funcion buscar_por_apellido abre el archivo "personal.txt" con el modo de apertura "r" que permite la lectura del arhivo anteriormente mencionado.
     *Se crea un arreglo de caracteres llamado apellido y se le pide al usuario que ingrese un apellido, luego se crea un while que se ejecutara mientras fgets(cadena, sizeof(cadena), personal) no sea igual a NULL,lo cual hace que el valor de la linea
     *de "personal.txt" se guarde en la string linea y se ejecutara hasta que llegemos al final del archivo, en este caso es al encontrar una linea vacia en "personal.txt".
     *dentro de este while se crea un if que si strstr(cadena, apellido) no es igual a NULL, lo que hace esta condicion es primero comparar el texto guardado en cadena con el
     *el apellido ingresado en el string apellido[25]; gracias a la funcion strstr, luego  se imprime en pantalla la informacion de cada linea en nuestros archivos de texto que coincida con el apellido ingresado por el usuario.
     *Finalmente cerramos los archivos con el comando fclose(nombrearchivo);.
     */

    FILE *personal = fopen("personal.txt", "r");
    char apellido[25];
    printf("Ingrese el apellido que desea buscar: ");
    scanf("%s", apellido);
    while (fgets(cadena, sizeof(cadena), personal) != NULL)
    {

        if (strstr(cadena, apellido) != NULL)
        {

            printf("%s", cadena);
        }
    }
    if (strstr(cadena, apellido) == nullptr)
    {

        printf("No hay coincidencias.");
    }
    fclose(personal);

    printf("Presione cualquier boton para continuar.");
    getch();
}

void editartrabajador(int numlinea)
{

    /*
     * Nombre de la función: editartrabajador.
     * Tipo de función: void.
     * Parámetros: La funcion recibe un parametro de tipo int llamado numlinea que nos ayudara a identificar la linea que se desea editar en nuestros archivos de texto.
     * Dato de retorno: Ninguno ya que es un void;
     * Descripción de la función: La funcion editartrabajador abre los archivos "personal.txt" e "indice.txt" con el modo de apertura "r" que permite leer el contenido de los archivos anteriormente mencionados,
     *y los archivos "personaltemp.txt" e "indicetemp.txt" con el modo de apertura "w" que permite crear los archivos y escribir informacion en ellos. Luego se crean distintos arreglo de caracteres, uno llamado linea y otros que nos ayudaran
     *para guardar la informacion nueva sobre los trabajadores, y se define una variable de tipo int llamada count. Luego se crea un while que se ejecutara mientras fgets(linea, sizeof(linea), personal) no sea igual a NULL, lo cual hace que el valor de la linea
     *de "personal.txt" se guarde en la string linea y se ejecutara hasta que llegemos al final del archivo, en este caso es al encontrar una linea vacia en "personal.txt". Dentro de este while se crea un if que si count es
     *diferente a numlinea, se imprime la informacion de cada linea en nuestro archivo de texto "personaltemp.txt" y a la vez añadimos 1 a count;. Luego si count es igual al numero de linea que queremos editar se le pregunta al usuario los distintos datos y se guarda
     *esa informacion en las variables correspondientes para luego imprimirla en la linea que queriamos editar en nuestro archivo de texto "personaltemp.txt", luego repetimos lo mismo para los archivos "indice.txt" e "indicetemp.txt" Finalmente cerramos los
     *archivos con el comando fclose(nombrearchivo); y eliminamos los archivos originales para luego cambiar el nombre del archivo temporal al original asi realizado correctamente la edicion del trabajdor en la linea indicada.
     */

    FILE *Personal = fopen("personal.txt", "r");
    FILE *Indice = fopen("indice.txt", "r");
    FILE *PersonalTemp = fopen("personaltemp.txt", "w");
    FILE *IndiceTemp = fopen("indicetemp.txt", "w");

    char linea[256], nombre[15], apellido[15], correo[50], rut[10], f_contratacion[10];
    int count = 0, telefono, casocargo = 0;

    while (fgets(linea, sizeof(linea), Personal) != NULL)
    {
        count++;
        if (count != numlinea)
        {
            fprintf(PersonalTemp, "%s", linea);
        }
        else
        {
            printf("Ingrese el nuevo nombre del trabajador: "); // Ingresar y escribir nombre del trabajador
            scanf("%s", nombre);
            fprintf(PersonalTemp, "%s,", nombre);

            printf("Ingrese el nuevo apellido del trabajador: "); // Ingresar y escribir apellido del trabajador
            scanf("%s", apellido);
            fprintf(PersonalTemp, "%s,", apellido);

            printf("Ingrese el rut del trabajador sin puntos y con guion: "); // Ingresar y escribir rut del trabajador
            scanf("%s", rut);
            fprintf(PersonalTemp, "%s,", rut);

            printf("Ingrese el nuevo telefono del trabajador: "); // Ingresar y escribir telefono del trabajador
            scanf("%d", &telefono);
            fprintf(PersonalTemp, "%d,", telefono);

            printf("Ingrese el nuevo correo del trabajador: "); // Ingresar y escribir correo del trabajador
            scanf("%s", correo);
            fprintf(PersonalTemp, "%s,", correo);

            printf("Ingrese la fecha de contatacion del trabajador(DD/MM/YYYY): "); // Ingresar y escribir fecha de contratacion del trabajador
            scanf("%s", f_contratacion);
            fprintf(PersonalTemp, "%s,", f_contratacion);
            printf("\n\n\n");

            bool antiloop = true;

            while (antiloop)
            {

                printf("Seleccione el nuevo cargo del trabajador: "); // Ingresar y escribir cargo del trabajador
                printf("\n********** Cargos: **********\n");
                printf("\t *1:Desarrollador\n");
                printf("\t *2:Analista \n");
                printf("\t *3:Tester\n");
                printf("\t *4:Jefe de Proyecto\n");
                printf("\t *5:Gerente\n");
                printf("*************************\n");

                scanf("%d", &casocargo);

                switch (casocargo)
                {

                case 1:
                    fprintf(PersonalTemp, "Desarrollador\n");
                    antiloop = false;
                    break;

                case 2:
                    fprintf(PersonalTemp, "Analista\n");
                    antiloop = false;
                    break;

                case 3:
                    fprintf(PersonalTemp, "Tester\n");
                    antiloop = false;
                    break;

                case 4:
                    fprintf(PersonalTemp, "Jefe de Proyecto\n");
                    antiloop = false;
                    break;

                case 5:
                    fprintf(PersonalTemp, "Gerente\n");
                    antiloop = false;
                    break;

                default:
                    printf("Seleccion no valida\n");
                    system("pause");
                }
            }
        }
    }
    count = 0;
    while (fgets(linea, sizeof(linea), Indice) != NULL)
    {
        count++;
        if (count != numlinea)
        {
            fprintf(IndiceTemp, "%s", linea);
        }
        else
        {
            fprintf(IndiceTemp, "%d %s, ", count, apellido);
            bool antiloop = true;
            switch (casocargo)
            {

            case 1:
                fprintf(IndiceTemp, "Desarrollador\n");
                antiloop = false;
                break;

            case 2:
                fprintf(IndiceTemp, "Analista\n");
                antiloop = false;
                break;

            case 3:
                fprintf(IndiceTemp, "Tester\n");
                antiloop = false;
                break;

            case 4:
                fprintf(IndiceTemp, "Jefe de Proyecto\n");
                antiloop = false;
                break;

            case 5:
                fprintf(IndiceTemp, "Gerente\n");
                antiloop = false;
                break;

            default:
                printf("Seleccion no valida\n");
                system("pause");
            }
        }
    }
    fclose(Personal);
    fclose(PersonalTemp);
    fclose(Indice);
    fclose(IndiceTemp);

    remove("personal.txt");
    rename("personalTemp.txt", "personal.txt");

    remove("indice.txt");
    rename("indicetemp.txt", "indice.txt");
}

void eliminartrabajador(int numlinea)
{

    /*
     * Nombre de la función: eliminartrabajador.
     * Tipo de función: void.
     * Parámetros: La funcion recibe un parametro de tipo int llamado numlinea que nos ayudara a identificar la linea que se desea eliminar en nuestros archivos de texto.
     * Dato de retorno: Ninguno ya que es un void;
     * Descripción de la función: La funcion eliminartrabajador abre los archivos "personal.txt" e "indice.txt" con el modo de apertura "r" que permite leer la informacion de los arhivos anteriormente mencionados,
     *y los archivos "personaltemp.txt" e "indicetemp.txt" con el modo de apertura "w" que permite la creacion del archivo y escritura de informacion en los arhivos anteriormente mencionados. Luego se crea un arreglo de caracteres llamado linea
     * y se define una variable de tipo int llamada count. Luego se crea un while que se ejecutara mientras fgets(linea, sizeof(linea), personal) no sea igual a NULL, dentro de este while se crea un if que si count es
     *diferente a numlinea, se imprime en "personaltemp.txt" la informacion de cada linea en nuestros archivos de texto. Luego se crea un segundo while que se ejecutara mientras fgets(linea, sizeof(linea), Indice) no sea igual a NULL,
     *dentro de este while se crea un if que si count es diferente a numlinea, se imprime en "indicetemp.txt" la informacion de cada linea en nuestros archivos de texto, ademas se hace la actualizacion del numero identificador
     *el cual se utiliza para enlazar en numero del indice con la informacion completa del trabajador en "personal.txt". Finalmente cerramos los archivos con el comando fclose(nombrearchivo);
     *para luego borrar los archivos originales "personal.txt" e "indice.txt" y renombrar los archivos "personaltemp.txt" e "indicetemp.txt" a el nombre de los archivos originales.
     */

    FILE *Personal = fopen("personal.txt", "r");
    FILE *Indice = fopen("indice.txt", "r");
    FILE *PersonalTemp = fopen("personaltemp.txt", "w");
    FILE *IndiceTemp = fopen("indicetemp.txt", "w");

    char linea[256];
    int count = 0;

    while (fgets(linea, sizeof(linea), Personal) != NULL)
    {
        count++;
        if (count != numlinea)
        {
            fprintf(PersonalTemp, "%s", linea);
        }
    }

    count = 0;
    while (fgets(linea, sizeof(linea), Indice) != NULL)
    {
        printf("1era linea: %c\n",linea[0]);
        count++;
        if ((count != numlinea)&&(count<numlinea))
        {
            if (linea[0] == '1')//De aqui en adelante es para actualizar el numero identificador de manera correcta.
            {   
                fprintf(IndiceTemp, "%s", linea);
            }
            else
            {
                fprintf(IndiceTemp, "%s", linea);
            }
            
        }else{ if(count>numlinea){
                linea[0] = (linea[0] - 1);
                fprintf(IndiceTemp, "%s", linea);
            }
            }// Hasta aqui es la actualizacion de los numeros.
    }
    fclose(Personal);
    fclose(PersonalTemp);
    fclose(Indice);
    fclose(IndiceTemp);

    remove("personal.txt");
    rename("personalTemp.txt", "personal.txt");

    remove("indice.txt");
    rename("indicetemp.txt", "indice.txt");
}
