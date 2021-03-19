#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Yarismalar
{
    int parkurU;
    int engelSayisi;
    int engelMetresi;

} Yarisma;


bool PrimeControl(int n1, int n2);
void DosyaAc();
void DosyayaYazdir(int hp);
FILE * fpointer;

int main()
{

    DosyaAc();

    int hp = 100;

    Yarisma yarisma1;

    srand(time(NULL));

    //parkur uzunluğu 50 ile 100 arasında random olarak atanıyor.
    yarisma1.parkurU = 50+(rand()%51);

    //Engel Sayisi 2 ile 5 arasında random olarak atanıyor.
    yarisma1.engelSayisi= 2+rand()%4;

    yarisma1.engelMetresi;

    DosyayaYazdir(hp);

    for(int i=1; i<=yarisma1.engelSayisi; i++ )
    {
        //engel çıkacağı metre 5 ile parkurun uzunluğa kadar random olarak atanıyor.
        yarisma1.engelMetresi = 5+(rand()% yarisma1.parkurU-4);

        if( hp > 0 )
        {
            fprintf(fpointer,"*Yarismaci %d. metreye kadar bir engel karsilasmadi!\n %d. metrede bir engel var.\n",yarisma1.engelMetresi,yarisma1.engelMetresi);

            if(PrimeControl(hp,yarisma1.engelMetresi))
            {
                hp=hp-yarisma1.engelMetresi;

                fprintf(fpointer, "yarismacinin yasam puani : %d\n\n", hp);
            }
        }
    }

    DosyayaYazdir(hp);

    fclose(fpointer);

    return 0;
}

void DosyaAc()
{
    fpointer = fopen("log.txt", "w+");

    if(fpointer == NULL)
    {
        printf("Error opening file\n");

        exit(1);
    }
}



//asal control fonksiyonu
bool PrimeControl(int n1, int n2)
{
    int i, counter=0;

    for(i=1; i <= n1 && i <= n2; ++i)
    {
        if(n1%i==0 && n2%i==0)
        {
            counter++;
        }
    }
    if (counter < 2)
    {
        fprintf(fpointer, "\t%d ve %d naralarinda asaldir!! \n\n", n1, n2 );

        return true;
    }
    else
    {
        fprintf(fpointer, "\t%d ve %d naralarinda asal degildir!! \n\n", n1, n2);

        return false;
    }
}

void DosyayaYazdir(int hp)
{

    if (hp==100)
    {

        fputs("yarisma basladi ! \n", fpointer);

        fprintf(fpointer, "Yarismacinin Hp = %d\n\n", hp);
    }
    else
    {

        if(hp<=0)
        {
            fputs("Uzgunum !!, Yarismayi tamamlayamadin!!\n", fpointer);
        }
        else
        {
            fprintf(fpointer, "Tebrikler !! yarismayi %d puan ile bitirdiniz !!\n", hp);
        }

    }

}
