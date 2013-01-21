/**
 * fwrite C language function call for file writing with dummy content for device test.
 * author: Sebastien COUDERT
 * UNIX (Linux, CygWin, MacOSX) compilation: gcc -o fwrite.linux64 fwrite.c -O3 --static
 * Windows compilation to do using favorite IDE.
**/

#include <stdio.h>
#include <time.h>

//#define FWRITE_DEBUG

/* 1024 bytes */
#define SIZE 1024

/* 1024 bytes x 1024 = 1 MB */
#define NB 1024

#define FILENAME "file.txt"

struct thestruct
{
  char str[SIZE];
};

int main(void)
{
   FILE *stream;
   struct thestruct s;
   int i,nb;
   float stat;

time_t t[2];

	printf("Enter file size in MBytes (MB):\n");
   if( (scanf("%d",&nb) == 0) || (nb <= 0)   ) {printf("Error when typing the number.\n");fflush(stdin);getc(stdin);return 1;}
	stat=(float)nb;

t[0] = time(NULL);

   if ((stream = fopen(FILENAME, "wb")) == NULL) /* open file TEST.$$$ */
   {
      fprintf(stderr, "Unable to open file \"%s\" for writing.\n",FILENAME);
      return 1;
   }
	for(i=0;i<SIZE;){s.str[i++]='-';s.str[i++]='\\';s.str[i++]='|';s.str[i++]='/';}
	for(i=0;i<nb*NB;i++)
   {
		/* write struct s to file */
#ifdef FWRITE_DEBUG
   int out;
#endif
   	if( (
#ifdef FWRITE_DEBUG
      out=
#endif
      (int)fwrite(&s, sizeof(s), 1, stream)) != 1 ) {
#ifdef FWRITE_DEBUG
      printf("sizeof(s)=%d\n",sizeof(s));
#endif
      printf("Erreur lors de l'ecriture du fichier.\n");fflush(stdin);getc(stdin);return 1;}
   }
   fflush(stream);
   fclose(stream); /* close file */

t[1] = time(NULL);
t[1]-=t[0];
stat/=(float)t[1];
printf("Writing elapsed time:\n%ld second(s), i.e. %.1f MB/s.\n",t[1],stat);
fflush(stdin);getc(stdin);
   return 0;
}

