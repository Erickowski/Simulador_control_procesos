/* Hecho por:
Perez Mata Erick Daniel
F-43 ISC
Sistemas operativos
M. en C.C. Alejandro Romero Herrera
*/
#include<stdio.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
#define MAX 15

int MAT[MAX][MAX];
int i,j=10;
int d=0,e=0,o=0,k=0;

void ale(void)
{
    MAT[0][1]=(rand()%2);
    MAT[1][1]=(rand()%2);
    MAT[2][1]=(rand()%2);
    MAT[3][1]=(rand()%2);
    MAT[4][1]=(rand()%2);
    MAT[5][1]=(rand()%2);
    MAT[6][1]=(rand()%2);
    MAT[7][1]=(rand()%2);
    MAT[8][1]=(rand()%2);
    MAT[9][1]=(rand()%2);
    MAT[0][2]=(rand()%999);
    MAT[1][2]=(rand()%999);
    MAT[2][2]=(rand()%999);
    MAT[3][2]=(rand()%999);
    MAT[4][2]=(rand()%999);
    MAT[5][2]=(rand()%999);
    MAT[6][2]=(rand()%999);
    MAT[7][2]=(rand()%999);
    MAT[8][2]=(rand()%999);
    MAT[9][2]=(rand()%999);
    MAT[0][3]=(rand()%1024);
    MAT[1][3]=(rand()%1024);
    MAT[2][3]=(rand()%1024);
    MAT[3][3]=(rand()%1024);
    MAT[4][3]=(rand()%1024);
    MAT[5][3]=(rand()%1024);
    MAT[6][3]=(rand()%1024);
    MAT[7][3]=(rand()%1024);
    MAT[8][3]=(rand()%1024);
    MAT[9][3]=(rand()%1024);
}

void imprime (void)
{
    pf(" # de proceso\t Estatus\t PID\t Memoria\t\n");
    for(i=0; i<j; i++)
    {
        pf("\t%i \t    %i \t\t %i \t  %i kb\n",MAT[i][0],MAT[i][1],MAT[i][2],MAT[i][3]);
    }
}

void imprime2(void)
{
    d=0;
    e=0;
    o=0;
    for(i=0; i<j; i++)
    {
        if(MAT[i][1]==1) d++;
        else e++;
    }
    for(i=0; i<j; i++)
    {
        o+=MAT[i][3];
    }
    pf("Procesos activos  Procesos inactivos  Memoria utilizada\n");
    pf("\t%i\t\t  %i\t\t  %i kb\n",d,e,o);
}

void elimina (pid)
{
    int k=0;
    while(1)
    {
        if(MAT[k][2]==pid) break;
        else k++;
    }
    for(i=0; i<j-k; i++)
    {
        MAT[k+i][0]=MAT[k+i+1][0];
        MAT[k+i][1]=MAT[k+i+1][1];
        MAT[k+i][2]=MAT[k+i+1][2];
        MAT[k+i][3]=MAT[k+i+1][3];
    }
    j--;
}

int comprueba(pid)
{
    k=0;
    while(1)
    {
        if(k<10)
        {
            if(MAT[k][2]==pid)
            {
                break;
            }
            else k++;
        }
        else
        {
            return 1;
            break;
        }
    }
}

int main(void)
{
    char opc[1];
    int pid,h=0;
    MAT[0][0]=1;
    MAT[1][0]=2;
    MAT[2][0]=3;
    MAT[3][0]=4;
    MAT[4][0]=5;
    MAT[5][0]=6;
    MAT[6][0]=7;
    MAT[7][0]=8;
    MAT[8][0]=9;
    MAT[9][0]=10;
    ale();
    do
    {
        sf("%s",&opc);
        switch(opc[0])
        {
        case 'M':
        case 'm':
            switch(opc[1])
            {
            case 'L':
            case 'l':
                imprime();
                imprime2();
                system("pause");
                system("cls");
                break;
            case 'P':
            case 'p':
                pf("PID del proceso a eliminar: ");
                sf("%i",&pid);
                if(comprueba(pid)!=1)
                {
                    elimina(pid);
                    pf("Operacion exitosa\n\n");
                    pf("Lista de procesos ACTUALIZADA\n");
                    imprime();
                    imprime2();
                    system("pause");
                    system("cls");
                }
                else
                {
                    pf("Operacion fallida, PID incorrecto\n");
                    system("pause");
                    system("cls");
                }
                break;
            default:
                pf("Comando no valido\n");
                system("pause");
                system("cls");
                break;
            }
            break;
        case 'N':
        case 'n':
            switch(opc[1])
            {
            case 'L':
            case 'l':
                MAT[0][0]=1;
                MAT[1][0]=2;
                MAT[2][0]=3;
                MAT[3][0]=4;
                MAT[4][0]=5;
                MAT[5][0]=6;
                MAT[6][0]=7;
                MAT[7][0]=8;
                MAT[8][0]=9;
                MAT[9][0]=10;
                j=10;
                ale();
                system("pause");
                system("cls");
                break;
            default:
                pf("Comando no valido\n");
                system("pause");
                system("cls");
                break;
            }
            break;
        case 'E':
        case 'e':
            switch(opc[1])
            {
            case 'X':
            case 'x':
                h=1;
                break;
            default:
                pf("Comando no valido\n");
                system("pause");
                system("cls");
                break;
            }
            break;
        case 'B':
        case 'b':
            switch(opc[1])
            {
            case 'M':
            case 'm':
                pf("PID del proceso a buscar: ");
                sf("%i",&pid);
                if(comprueba(pid)!=1)
                {
                    pf("Proceso encontrado:\n");
                    pf(" # de proceso\t Estatus\t PID\t Memoria\t\n");
                    pf("\t%i \t    %i \t\t %i \t  %i kb\n",MAT[k][0],MAT[k][1],MAT[k][2],MAT[k][3]);
                    system("pause");
                    system("cls");
                }
                else
                {
                    pf("Operacion fallida, PID incorrecto\n");
                    system("pause");
                    system("cls");
                }

                break;
            default:
                pf("Comando no valido\n");
                system("pause");
                system("cls");
                break;
            }
            break;
        default:
            pf("Comando no valido\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(h!=1);
}
