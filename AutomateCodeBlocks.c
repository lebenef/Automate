#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
int AFD(char *mot,char *tl,char *ms,char **ts, int **tt,int nbe,int ei,int ef)
{

    int e=ei,l=0,k=0,lgtm=strlen(mot);
    char s=mot[l];
    char t=tl[0];
    while(l<lgtm)
	  {
            if(ts[e][(int)(s-t)] != '$')
            {
             ms[k]=ts[e][(int)(s-t)];
             k++;
            }
            e=tt[e][(int)(s-t)];
            l++;
            s=mot[l];
    }
	  ms[k]='\0';

    if((e==ef)){return 0;}

    else {return -1;}
}


int main(int argc, char *argv[])
{
 int i,j,k;
 int nbl=0;
 int nbe=0;
 int es,ei,ef;
 char mot[100];
 char ms[100];
 char re,ss;
 char tl[26];
 int **tt;
 char **ts;
 bool ok=true;

 printf("Indiquez le nombre de lettres du langage :\n");
 scanf("%d",&nbl);

 for(i=0;i<nbl;i++)
  {
    printf("Indiquez la %d lettre :\n",i+1);
    scanf("%s",&tl[i]);
  }


 printf("Indiquez le nombre d'etats :\n");
 scanf("%d",&nbe);

 tt=(int**)malloc(sizeof(int*)*nbe);
 tt[0]=(int*)malloc (sizeof(int)*nbl*nbe);

  for(i=0;i<nbe;i++)
  {
      tt[i]=(*tt+nbl*i);
  }


  ts=(char**)malloc(sizeof(char*)*nbe);

  for(i=0;i<nbe;i++)
  {
     ts[i]=(char*)malloc (sizeof(char)*nbl*nbe);
  }



 for(i=0;i<nbe;i++)
 {
  for(k=0;k<nbl;k++)
  {

  printf("Table de transition pour l'etat %d la transition %c \n",i,tl[k]);


     printf("Saisissez l'etat suivant :\n");
     scanf("%d",&es);


      tt[i][k]=es;
  }
}


     printf("Veuillez saisir l'etat initial: \n");
     scanf("%d",&ei);
     printf("Veuillez saisir l'etat final : \n");
     scanf("%d",&ef);

 printf("Alphabet de sortie, saisir $ si la sortie est  mot est vide !\n");

	for(i = 0;i<nbe;i++)
  {
		for (j=0;j<nbl;j++)
    {
			printf("Pour l'etat %d avec la lettre %c la sortie est :\n",i,tl[j]);

				scanf("%s",&ss);
			   ts[i][j] = ss;

		}
	}

ok=true;
while(ok==true)
{
     printf("Veuillez saisir un mot: \n");
     scanf("%s",mot);

  if(AFD(mot,tl,ms,ts,tt,nbe,ei,ef)==0)
    {
     printf("le mot est reconnu\nLe mot de sortie est : %s\n",ms);
    }
       else  printf("le mot n'est pas  reconnu\n");

    printf("Voulez-vous saisir un nouveau mot  ? o ou n :\n");
    scanf("%s",&re);

     if(re!='o') ok=false;
}
 return 0;
}
