#include<fstream.h>
#include<dos.h>
#include<conio.h>
#include<process.h>
void intro()
{    clrscr();
     char choice;
     int y=1;
     do{
	 clrscr();
	 gotoxy(36,y);
	   y++;
	 cout<<"0";
	 gotoxy(1,21);
	 for(int i=1;i<72;i++)
	 {  cout<<"-";
	    if(i==36)
	      cout<<"\b*";
	 }
	 delay(200);
	 if(kbhit())
	   choice=getch();
       }while(choice!='q'&&y!=13);
     choice='y';
     y=0;
     gotoxy(35,12);
     cout<<"+O+";
     delay(300);
     do{ clrscr();
	 y++;
	 gotoxy(35,12);
	 cout<<"+O+";
	 gotoxy(35,12+y);
	 cout<<"| |";
	 gotoxy(1,21);
	 for(int i=1;i<72;i++)
	 {  cout<<"-";
	    if(i==36)
	      cout<<"\b*";
	 }
	 delay(150);
	 if(kbhit())
	   choice=getch();
       }while(choice!='q'&&y!=8);
     choice='y';
     gotoxy(35,20);
     cout<<"   ";
     gotoxy(35,21);
     cout<<"|*|";
     delay(50);
     gotoxy(35,21);
     cout<<" * ";
     y=12;
     int x=21;
     do{
       delay(125);
       if(kbhit())
	 choice=getch();
       clrscr();
       x--;
       gotoxy(36,x);
       cout<<"*";
       gotoxy(36,y);
       cout<<"0";
       y--;
       x--;
       delay(125);
       clrscr();
       gotoxy(36,x);
       cout<<"*";
       gotoxy(36,y);
       cout<<"0";
       }while(x-y>3&&choice!='q');
     getch();
     choice='y';
     fstream f;
     f.open("dilgue.txt",ios::in);
     char c[200];
     f.seekp(ios::beg);
     int flag=0;
     do{
       clrscr();
       gotoxy(1,1);
       cout<<">>press q to pause, double press q to skip \n>>hold t to speed up";
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
	    delay(50);
	  if(kbhit())
	    choice=getch();
	  cout<<c[i];
       }
       f.getline(c,201,'\n');
       gotoxy(33,13);
       for(i=0;c[i]!='\0'&&choice!='q';i++)
       {  if(choice=='t')
	    choice='y';
	  else
	    delay(50);
	  if(kbhit())
	    choice=getch();
	  cout<<c[i];
       }
       flag++;
       delay(500);
       }while(choice!='q'&&!f.eof());
     getch();
     f.close();
}





