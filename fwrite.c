#include <stdio.h>
#include <time.h>

/* 128 * 8 = 1024 octets */
#define SIZE 128
#define REPEAT 8

/* 1024 octets x 1024 = 1 Mo */
#define NB 1024

#define FILENAME "fichier.txt"

struct thestruct
{
  char str[SIZE];
};

int main(void)
{
   FILE *stream;
   struct thestruct s;
   int i,nb;
   int size=REPEAT/*,out=REPEAT*/;
   float stat;

time_t t[2];

	printf("Entrer la taille du fichier en Mo :\n");
   if( (scanf("%d",&nb) == 0) || (nb <= 0)   ) {printf("Erreur lors de la saisie du nombre.\n");fflush(stdin);getc(stdin);return 1;}
	stat=(float)nb;

t[0] = time(NULL);

   if ((stream = fopen(FILENAME, "wb")) == NULL) /* open file TEST.$$$ */
   {
      fprintf(stderr, "Impossible d'ouvrir le fichier %s en ecriture.\n",FILENAME);
      return 1;
   }
	for(i=0;i<SIZE;){s.str[i++]='-';s.str[i++]='\\';s.str[i++]='|';s.str[i++]='/';}
	for(i=0;i<nb*NB;i++)
   {
		/* write struct s to file */
   	if( /*(out=*/fwrite(&s, sizeof(s), REPEAT, stream)/*)*/ != size ) {/*printf("%d != %d\n",out,size);*/printf("Erreur lors de l'ecriture du fichier.\n");fflush(stdin);getc(stdin);return 1;}
   }
   fclose(stream); /* close file */

t[1] = time(NULL);
t[1]-=t[0];
stat/=(float)t[1];
printf("Temps d'ecriture du fichier :\n%ld seconde(s), soit %.1f Mo/s.",t[1],stat);
fflush(stdin);getc(stdin);
   return 0;
}