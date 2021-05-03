#include<conio.h>
#include"snipe.cpp"
#include<fstream.h>
#include<process.h>
//#include"level.cpp"
int game3(int t)
{    fstream f;
     //level(3);
     f.open("dilgue4.txt",ios::in);
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
      f.close();
      int x;
      do{
	x=play3(t);
	if(x==0)
	{ clrscr();
	  cout<<"Do you want to restart(y/n)?";
	  char c;
	  cin>>c;
	  if(c=='n'||c=='N')
	    break;
	  else
	    continue;
	}
	}while(x==0);
	if(x==-1)
	  x=0;
      return(x);
}