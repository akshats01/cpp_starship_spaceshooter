#include<dos.h>
//#include"level.cpp"
#include<process.h>
#include<conio.h>
#include<fstream.h>
#include"sideshoot.cpp"
int game1(int t=0)
{    //level(1)
     fstream f;
     f.open("dilgue2.txt",ios::in);
     char c[200],choice;
     f.seekp(ios::beg);
     int flag=0;
     do{
       clrscr();
       gotoxy(1,1);
       cout<<">>press p to pause, press q to skip \n>>hold t to speed up";
       gotoxy(36,9);
       cout<<"*";
       gotoxy(36,6);
       cout<<"0";
       f.getline(c,201,'\n');
       gotoxy(30,12);
       cout<<"0: ";
       for(int i=0;c[i]!='\0'&&choice!='q';i++)
       {  if(choice=='t')
	    choice='y';
	  else
	    delay(75);
	  if(kbhit())
	    choice=getch();
	  if(choice=='p'||choice=='P')
	    getch();
	  else if(choice=='Q'||choice=='q')
	    break;
	  cout<<c[i];
       }
       f.getline(c,201,'\n');
       gotoxy(33,13);
       for(i=0;c[i]!='\0'&&choice!='q';i++)
       {  if(choice=='t')
	    choice='y';
	  else
	    delay(75);
	  if(kbhit())
	    choice=getch();
	 if(choice=='p'||choice=='P')
	   getch();
	 else if(choice=='q'||choice=='Q')
	   break;
	 cout<<c[i];
       }
       flag++;
       delay(1000);
       }while(choice!='q'&&!f.eof());
     int j=32;
     do{
       clrscr();
       gotoxy(j,9);
       cout<<"*";
       gotoxy(j,6);
       cout<<"0";
       delay(50);
       j--;
       if(kbhit())
	 choice=getch();
      }while(choice!='q'&&choice!='Q'&&j>0);
     j=6;
     do{
       clrscr();
       gotoxy(1,9);
       cout<<"*";
       gotoxy(2,j);
       cout<<"0";
       delay(50);
       j--;
       if(kbhit())
	 choice=getch();
       }while(choice!='q'&&choice!='Q'&&j>0);
     gotoxy(2,1);
     cout<<"O";
     j=2;
     for(;j<23;j++)
     {  gotoxy(2,j);
	delay(50);
	cout<<"|";
     }
     int x;
     do{
       x=sshoot(t);
       if(x==0)
       { clrscr();
	 cout<<"Do you want to restart?(y/n)";
	 char c;
	 cin>>c;
	 if(c=='n'||c=='N')
	   x=-1;
	 else
	   continue;
       }
       }while(x==0);
     if(x==-1)
       x=0;
     return(x);
}