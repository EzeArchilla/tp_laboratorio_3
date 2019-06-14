#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>



float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


int getIntPositivo(char* mensaje, char* eMensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    while( auxiliar < 0 )
    {
        printf( "%s", eMensaje );
        scanf( "%i", &auxiliar );
    }

    return auxiliar;
}

int getIntLimitado(char* mensaje, char* eMensaje, int lowLimit, int highLimit)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    while( auxiliar < lowLimit || auxiliar > highLimit )
    {
        printf( "%s", eMensaje );
        scanf( "%i", &auxiliar );
    }

    return auxiliar;
}



char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}



char getCharSexo()
{
    char auxiliar;
    printf("Ingrese el sexo [f/m]: ");
    fflush(stdin);
    scanf("%c",&auxiliar);
    auxiliar = toupper(auxiliar);
    while(auxiliar != 'F' && auxiliar != 'M')
    {
        printf("Error! Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%c",&auxiliar);
        auxiliar = toupper(auxiliar);
    }
    return auxiliar;
}

char getCharConfirm(char* mensaje, char* eMensaje)
{
    char auxiliar;
    printf(mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    auxiliar = toupper(auxiliar);
    while(auxiliar != 'S' && auxiliar != 'N')
    {
        printf(eMensaje);
        fflush(stdin);
        scanf("%c",&auxiliar);
        auxiliar = toupper(auxiliar);
    }
    return auxiliar;
}



char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}



int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}


int esMail(char str[])
{
    int i=0;
    int contadorArrobas = 0;
    int contadorPuntos = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '@') && (str[i] != '.') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '@')
            contadorArrobas++;
        if(str[i] == '.')
            contadorPuntos++;
        i++;
    }
    if(contadorArrobas==1 && (contadorPuntos == 1 || contadorPuntos == 2)) // debe tener un arroba y 1 o 2 puntos
        return 1;
    return 0;
}


int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

void getString(char* mensaje,char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


int getStringLetras(char* mensaje,char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char* mensaje,char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int lengthString(char str[],int length)
{
    int ret = 0;

    if(strlen(str) > length)
    {
        ret = 1;
    }

    return ret;
}

