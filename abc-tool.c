//
// Created by Luca Stiegel on 23.02.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Rohdaten
 */
typedef struct artikel {
    char name[30];
    int artikelverbrauchsmenge;
    double bezugspreis;
}artikel_t;


artikel_t neuer_artikel(int artikelverbrauchsmenge_data,double bezugspreis_data){
     artikel_t artikel1 = {
            artikel1.artikelverbrauchsmenge = artikelverbrauchsmenge_data,
            artikel1.bezugspreis = bezugspreis_data
    };
    return artikel1;
}

void main(){

    artikel_t artikelarray[10];
    int verbrauchsmengensumme = 0;
    double verbrauchswert = 0.0;

    /**
     * Eingabe
     */
    int anzahl;
    printf("Bitte Anzahl der Artikel angeben: ");
    scanf("%d",&anzahl);

    for(int i = 0; i < anzahl; i++){
        char artikelname_temp[20];
        int artikelverbauchsmenge_temp;
        double bezugspreis_temp;

        printf("Artikel%d:\n",i);
        printf("Artikelname:");
        scanf("%s", artikelname_temp);
        printf("Artikelverbrauchsmenge:");
        scanf("%d", &artikelverbauchsmenge_temp);
        verbrauchsmengensumme += artikelverbauchsmenge_temp;
        printf("Bezugspreis:");
        scanf("%lf", &bezugspreis_temp);
        verbrauchswert += bezugspreis_temp;

        artikel_t artikel2 = neuer_artikel(artikelverbauchsmenge_temp, bezugspreis_temp);
        strcpy(artikel2.name, artikelname_temp);
        artikelarray[i] = artikel2;
    }

    /**
     * Feld sortieren
     */
    for (int c = 0 ; c < anzahl; c++)
    {
        for (int d = 0 ; d < anzahl+1; d++)
        {
            if (artikelarray[d].bezugspreis > artikelarray[d+1].bezugspreis)
            {
                /*temp struct*/
                artikel_t swap = { "temp",
                                   artikelarray[d].artikelverbrauchsmenge,
                                   artikelarray[d].bezugspreis
                                   };
                strcpy(swap.name, artikelarray[d].name);

                /*struct +1 = struct*/
                strcpy(artikelarray[d].name, artikelarray[d+1].name);
                artikelarray[d].bezugspreis = artikelarray[d+1].bezugspreis;
                artikelarray[d].artikelverbrauchsmenge = artikelarray[d+1].artikelverbrauchsmenge;

                /* struct +1 = swap struct*/
                strcpy(artikelarray[d+1].name, swap.name);
                artikelarray[d+1].bezugspreis = swap.bezugspreis;
                artikelarray[d+1].artikelverbrauchsmenge = swap.artikelverbrauchsmenge;
            }else{
            }
        }
    }




    printf("Artikelname\t");
    printf("Verbrauchsmenge\t");
    printf("\t");
    printf("Bezugspreis\n");
    for(int j = anzahl+1; j > 0; j--){
        if( artikelarray[j].bezugspreis > 0.01) {
            printf("%-16s", artikelarray[j].name);
            printf("%-20d\t", artikelarray[j].artikelverbrauchsmenge);
            printf("%.2lf\n", artikelarray[j].bezugspreis);
        }
    }
    printf("_____________________________________________________\n");
    printf("Verbrauchssumme:");
    printf("%-9d",verbrauchsmengensumme);
    printf("Verbrauchswert:%.2lf\n",verbrauchswert);






}