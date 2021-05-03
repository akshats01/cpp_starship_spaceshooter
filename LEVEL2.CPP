#include<conio.h>
#include<fstream.h>
#include<process.h>
//#include"level.cpp"
#include"twocars.cpp"
int game2(int t=0)
{    //level(2);
     fstream f;
     f.open("dilgue3.txt",ios::in);
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
       do{
	 t=play2(t);
	 if(t==0)
	 { getch();
	   cout<<"Do you want to restart?(y/n)";
	   char c;
	   cin>>c;
	   if(c=='n'||c=='N')
	     break;
	   else
	     continue;
	 }
	 }while(t==0);
	 if(t==-1)
	   t=0;
       return(t);
}