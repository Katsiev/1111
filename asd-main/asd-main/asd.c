#include <stdlib.h>
#include <stdio.h>
#include <string.h>
FILE *fi,*fo; // объявляется две файловые для открытия in.txt и out.txt
char text[81]; // массив в который мы поместим текст из файла
struct rec {char name[81],device[81],manuf[81]; long price;}
   zakazy[100],rectmp;
int maxz=0;
char *p;
//////////////////////////////////////////////////////////////////////
int findrec(void) //  функция которая исчет совпаления среди заказсчиков
{int i;
for (i=1;i<=maxz;i++) {
    if (strcmp(zakazy[i].name,rectmp.name)==0)
               return i;
}
return 0;
    
}
//////////////////////////////////////////////////////////////////////
void sort(void)
{int i,exflag;
if (maxz<=1) 
return;
do {exflag=1;for (i=1;i<=maxz-1;i++)
    {if (zakazy[i].price<zakazy[i+1].price)
        {rectmp=zakazy[i+1];
         zakazy[i+1]=zakazy[i];
         zakazy[i]=rectmp;
         exflag=0;
        }
    }
   }
while (exflag==0);
}
/////////////////////////////////////////////////////////////////////// 
void main(void)
{int fr;
fi=fopen("in.txt","r");
while (!feof(fi))
    {text[0]=0;fgets(text,81,fi);
     if (strlen(text)>2)
     {
     p=strtok(text," ");
     if (p!=NULL) strcpy(rectmp.name,p);
     p=strtok(NULL," ");
     if (p!=NULL) strcpy(rectmp.device,p);
     p=strtok(NULL," ");
     if (p!=NULL) strcpy(rectmp.manuf,p);
     p=strtok(NULL," ");
     if (p!=NULL) rectmp.price=atol(p);
     fr=findrec();
     if (fr!=0) zakazy[fr].price+=rectmp.price;
     else {maxz++;zakazy[maxz]=rectmp;}
     
    }
fclose(fi);

   sort();
   fclose(fo);
  }
}
