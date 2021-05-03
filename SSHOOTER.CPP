#include<process.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include"sts.cpp"
#include"level.cpp"
#include"level1.cpp"
#include"level2.cpp"
#include"level3.cpp"
class player
{     char name[20];
      int xp;
      int sp1;
      int sp2;
      int shoot;
      char pass[10];
     public:
      int id;
      int lev;
      player()
      {  xp=sp1=sp2=shoot=0;
      }
      void addxp()
      {   xp+=500;
      }
      int checktakexp()
      {   if(xp>=2000)
	  { xp-=2000;
	    return(1);
	  }
	  return(0);
      }
      void addsp1()
      {   sp1++;
      }
      void addsp2()
      {   sp2++;
      }
      void addshoot()
      {   shoot++;
      }
      void getpass()
      {   cin>>pass;
      }
      int checkpass();
      void retname()
      {   cout<<name;
      }
      void inname()
      {   cin>>name;
      }
      int retsp1()
      {   return(sp1);
      }
      int retsp2()
      {   return(sp2);
      }
      int retshoot()
      {   return(shoot);
      }
      int retidval()
      {   return(id);
      }
      void retid()
      {   cout<<id;
      }
      int retxp()
      {  return(xp);
      }
};
int player::checkpass()
{   char p[10];
    cin>>p;
    if(strcmp(pass,p)==0)
      return(1);
    return(0);
}
void main()
{
     int choice=6;
     char ch;
     do{
      int y=0;
      do{
       clrscr();
       ch='y';
       gotoxy(30,1);
       cout<<"MAIN-MENU";
       cout<<"\n\t\t-->Press w and s to navigate up and down";
       cout<<"\n\t\t-->Press k to choose option";
       gotoxy(25,8);
       cout<<"New Game";
       gotoxy(25,9);
       cout<<"Load game";
       gotoxy(25,10);
       cout<<"Credits";
       gotoxy(25,11);
       cout<<"Trailer";
       gotoxy(25,12);
       cout<<"Quit";
       gotoxy(24,8+y);
       cout<<">";
       ch=getch();
       if(ch=='w'||ch=='W')
       { if(y>0)
	   y--;
	 else
	   y=4;
       }
       else if(ch=='s'||ch=='S')
       { if(y<4)
	  y++;
	 else
	  y=0;
       }
       else if(ch=='k'||ch=='k')
	 choice=y+1;
       }while(ch!='q'&&ch!='Q'&&ch!='k'&&ch!='K');
       clrscr();
       if(choice==5)
	 exit(0);
       else if(choice==3)
       {    cout<<"All work done by Akshat Srivastav";
	    getch();
       }
       else if(choice==4)
       { clrscr();
	 cout<<">>t to fasten trailer";
	 gotoxy(33,11);
	 char c='y';
	 char ch[22]={"INTRODUCING"};
	 for(int i=0;ch[i]!='\0';i++)
	 {  if(c=='t')
	      c='y';
	    else if(c=='q')
	      exit(0);
	    else
	      delay(100);
	    if(kbhit())
	      c=getch();
	    cout<<ch[i];
	 }
	 delay(500);
	 strcpy(ch,"STARSHIP SPACESHOOTER");
	 for(i=1;i<11;i++)
	 {  clrscr();
	    cout<<">>t to fasten trailer";
	    gotoxy(36,i);
	    cout<<"*";
	    if(c=='t')
	      c='y';
	    else
	      delay(200);
	    if(kbhit())
	      c=getch();

	  }
	  delay(200);
	  clrscr();
	  cout<<">>t to fasten trailer";
	  gotoxy(29,11);
	  for(i=0;ch[i]!='\0';i++)
	  {  if(c=='t'||i==0)
	       c='y';
	     else
	     delay(100);
	     if(kbhit())
	       c=getch();
	     cout<<ch[i];
	  }
	  delay(2000);
	  intro();
       }
       else if(choice==1)
       { clrscr();
	 cout<<"\t\tNEW GAME";
	 cout<<"\nEnter player name --------------------";
	 player p;
	 p.lev=1;
	 gotoxy(19,2);
	 p.inname();
	 fstream f;
	 f.open("starshoot.txt",ios::out|ios::in|ios::binary);
	 if(f.fail())
	 { cerr<<"File cannot be opened";
	   getch();
	   exit(1);
	 }
	 f.seekp(0,ios::end);
	 if(!f.tellp())
	 { p.id=1;
	 }
	 else
	 { player p2;
	   int x=sizeof(p2);
	   f.seekp(-1*x,ios::end);
	   f.read((char*)&p2,x);
	   p.id=p2.id+1;
	 }
	 cout<<"\nEnter Password ";
	 p.getpass();
	 f.write((char*)&p,sizeof(p));
	 f.close();
	 clrscr();
	 cout<<"ACCOUNT CREATED!!!";
	 getch();
	 choice=2;
       }
       if(choice==2)
       { player p;
	 fstream f;
	 if(f.fail())
	 { cerr<<"Unable to open file";
	   getch();
	   exit(1);
	 }
	 int i;
	 do{
	 clrscr();
	 cout<<"\t\tLOAD GAME";
	 f.open("starshoot.txt",ios::in|ios::binary);
	 while(f.read((char*)&p,sizeof(p)))
	 {  cout<<"\n\t"<<p.retidval();
	    p.retname();
	 }
	 char ch='n';
	 f.close();
	   f.open("starshoot.txt",ios::in|ios::binary);
	   if(ch=='n'||ch=='N')
	   { cout<<"\n Enter your id number(press 0 to exit to main menu)- ";
	     cin>>i;
	   }
	   if(i==0)
	     break;
	   f.seekg(0,ios::beg);
	   while(f.read((char*)&p,sizeof(p)))
	   {
	      if(i==p.retidval())
	      {	i=0;
		break;
	      }
	   }
	   f.close();
	   if(i!=0)
	   { cout<<"\nWrong password";
	     getch();
	     continue;
	   }
	   if(i==0)
	   { clrscr();
	     cout<<"\t\tLOAD GAME\n";
	     cout<<"Enter your password ";
	     i=p.checkpass()+1;
	  if(i==2)
	  { cout<<"Welcome ";
	    p.retname();
	    i=0;
	  do{
	  do{
	  clrscr();
	  cout<<"\t\t";
	  p.retname();
	  cout<<"\n\t\t-->PRESS R TO VIEW YOUR STATS<-- ";
	  cout<<"\n\t\t-->PRESS T TO VIEW SHOP<--";
	  cout<<"\n\t\t-->NOTE: YOU CAN QUIT LEVEL BY PRESSING Q";
	  cout<<"\n\t\t-->NOTE: YOU CAN PAUSE GAME BY PRESSING P";
	  ch='y';
	  gotoxy(25,5);
	  cout<<"MAIN-MENU";
	  gotoxy(25,8);
	  cout<<"LEVEL 0";
	  gotoxy(25,9);
	  cout<<"LEVEL 1";
	  gotoxy(25,10);
	  cout<<"LEVEL 2";
	  gotoxy(25,11);
	  cout<<"LEVEL 3";
	  gotoxy(25,12);
	  cout<<"Quit";
	  gotoxy(24,8+y);
	  cout<<">";
	  ch=getch();
	  if(ch=='r'||ch=='R')
	  { clrscr();
	    cout<<"\nPLAYER XP:"<<p.retxp()<<"\t\tPLAYER LEV1SP:"<<p.retshoot()<<"\n\nPLAYERLEV2SP:"<<p.retsp1()<<"\t\tPLAYERLEV3SP:"<<p.retsp2();
	    cout<<"\n\nCAN ACCESS UPTO LEVEL(OF 3)"<<p.lev;
	    getch();
	  }
	  else if(ch=='t'||ch=='T')
	  { clrscr();
	    cout<<"INFO:To buy upgrade from the shop, player must have enough xp";
	    cout<<"\nEach upgrade is specific to each level as each level is different";
	    cout<<"\nEach upgrade has a limit of 4 and costs 2000 xp";
	    cout<<"\nEnter 0 to quit";
	    cout<<"\n\n\tLevel 1:";
	    if(p.retshoot()==4)
	      cout<<"FULL!!";
	    else
	      cout<<p.retshoot()+1;
	    cout<<"\n\n\tLEVEL 2:";
	    if(p.retsp1()==4)
	      cout<<"FULL!!";
	    else
	      cout<<p.retsp1()+1;
	    cout<<"\n\n\tLEVEL 3:";
	    if(p.retsp2()==4)
	      cout<<"FULL!!";
	    else
	      cout<<p.retsp2()+1;
	    cin>>choice;
	    if(choice==1)
	    { clrscr();
	      if(p.retshoot()==4)
		cout<<"Value is full";
	      else if(p.checktakexp())
	      {	p.addshoot();
		f.open("starshoot.txt",ios::in|ios::out|ios::binary);
		int x=sizeof(p);
		f.seekp((p.id-1)*x,ios::beg);
		f.write((char*)&p,x);
		f.close();
	      }
	      else
	      {	cout<<"Not enough xp";
		getch();
	      }
	    }
	    else if(choice==2)
	    { clrscr();
	      if(p.retsp1()==3)
		cout<<"Value is full";
	      else if(p.checktakexp())
	      {	p.addsp1();
		f.open("starshoot.txt",ios::in|ios::out|ios::binary);
		int x=sizeof(p);
		f.seekp((p.id-1)*x,ios::beg);
		f.write((char*)&p,x);
		f.close();
	      }
	      else
	      {	cout<<"Not enough xp";
		getch();
	      }
	    }
	    else if(choice==3)
	    { clrscr();
	      if(p.retsp2()==3)
		cout<<"Value is full";
	      else if(p.checktakexp())
	      {	p.addsp2();
		f.open("starshoot.txt",ios::in|ios::out|ios::binary);
		int x=sizeof(p);
		f.seekp((p.id-1)*x,ios::beg);
		f.write((char*)&p,x);
		f.close();
	      }
	      else
	      {	cout<<"Not enough xp";
		getch();
	      }
	    }
	  }
	  else if(ch=='w'||ch=='W')
	  { if(y>0)
	      y--;
	    else
	      y=4;
	  }
	  else if(ch=='s'||ch=='S')
	  { if(y<4)
	      y++;
	    else
	      y=0;
	  }
	  else if(ch=='k')
	    choice=y+1;
       }while(ch!='q'&&ch!='Q'&&ch!='k'&&ch!='K');
       if(ch=='q'||ch=='Q')
	 break;
       if(choice==2)
       { clrscr();
	 level(1);
	 int x=game1(p.retshoot());
	 if(x==1)
	 { if(p.lev<2)
	     p.lev=2;
	   p.addxp();
	   f.open("starshoot.txt",ios::in|ios::out|ios::binary);
	   x=sizeof(p);
	   f.seekp((p.id-1)*x,ios::beg);
	   f.write((char*)&p,x);
	   f.close();
	 }
       }
       else if(choice==5)
       { clrscr();
	 cout<<"BYE";
	 choice=0;
	 getch();
       }
       else if(choice==3)
       { clrscr();
	 if(p.lev>=2)
	 { level(2);
	   int x=game2();
	 if(x==1)
	 { if(p.lev<3)
	     p.lev=3;
	   p.addxp();
	   f.open("starshoot.txt",ios::in|ios::out|ios::binary);
	   x=sizeof(p);
	   f.seekp((p.id-1)*x,ios::beg);
	   f.write((char*)&p,x);
	   f.close();
	 }
	 }
	 else
	   cout<<"Level is not accessible by you ";
       }
       else if(choice==4)
       { clrscr();
	 if(p.lev>=3)
	 { level(3);
	   int x=game3(p.retsp2());
	 if(x==1)
	 { p.addxp();
	   f.open("starshoot.txt",ios::in|ios::out|ios::binary);
	   x=sizeof(p);
	   f.seekp((p.id-1)*x,ios::beg);
	   f.write((char*)&p,x);
	   f.close();
	 }
	 }
	 else
	   cout<<"Level is not accesible by you";
       }
       else if(choice==1)
       { clrscr();
	 cout<<">>t to fasten trailer";
	 gotoxy(33,11);
	 char c='y';
	 char ch[22]={"INTRODUCING"};
	 for(int i=0;ch[i]!='\0';i++)
	 {  if(c=='t')
	      c='y';
	    else if(c=='q')
	      exit(0);
	    else
	      delay(100);
	    if(kbhit())
	      c=getch();
	    cout<<ch[i];
	 }
	 delay(500);
	 strcpy(ch,"STARSHIP SPACESHOOTER");
	 for(i=1;i<11;i++)
	 {  clrscr();
	    cout<<">>t to fasten trailer";
	    gotoxy(36,i);
	    cout<<"*";
	    if(c=='t')
	      c='y';
	    else
	      delay(200);
	    if(kbhit())
	      c=getch();

	  }
	  delay(200);
	  clrscr();
	  cout<<">>t to fasten trailer";
	  gotoxy(29,11);
	  for(i=0;ch[i]!='\0';i++)
	  {  if(c=='t'||i==0)
	       c='y';
	     else
	     delay(100);
	     if(kbhit())
	       c=getch();
	     cout<<ch[i];
	  }
	  delay(2000);
	  intro();
       }

       }while(choice);
       }
       }
       f.close();
       i=1;
       }while(i);
       }
       }while(choice);

}