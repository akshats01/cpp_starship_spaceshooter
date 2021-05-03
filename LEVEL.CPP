#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
void level(int lev)
{   clrscr();
    char ch[]={"LEVEL"};
    char chr='y';
    int x[5]={1,0,0,0,0};
    int t=0,k;
    do{ clrscr();
	if(t>=300)
	  t=0;
	k=t+100;
	for(int i=0;i<5;i++)
	{  if(t==0&&x[i]<12)
	   { x[i]++;
	     if(x[i]==1)
	       break;
	   }
	   if(x[i]>0)
	   { gotoxy(33+i,x[i]);
	     cout<<ch[i];
	   }
	}
	gotoxy(39,12);
	cout<<lev;
	for(;t<=k;t+=50)
	{  if(chr!='t'&&chr!='T')
	     delay(50);
	   if(kbhit())
	     chr=getch();
	   if(chr=='q'||chr=='Q')
	     exit(0);
	}
      }while(x[4]<12);
      getch();
}












































































































































































































































































