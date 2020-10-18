#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
int a,i,j,b,d,k,e;
int ri[1][2];
int cmd();
char pname[20];
int pscore;
void createquestion();
void checkanswer();
void readanswer();
void openingscreen();
void starbox();
void outline();
void clearscreen();
void contentfirstpage();
void fancy(char d[]);
void readquestion();
void borders();
void rick();
void score();
void playgame();
void whichrick();
void mrick();
void gameoversetup();
void clearpage(int aa,int ab,int ac,int ad);
void playername();
void playerscore();
class game
{
	char question[50],answer[50];
	public:
	char* retques() { return question;}
	char* retans()  { return answer;  }
	void inputquestion();
	void inputanswer();
};
void game::inputquestion()
{
		cout<<"Please enter question "<<endl;
		gets(question);
}
void game::inputanswer()
{
		cout<<"Please enter answer of question "<<i+1<<endl;
		gets(answer);
}
void playername()
{
	clearpage(3,77,2,24);
	gotoxy(10,10);cout<<"Please Enter Player Name : ";
	gets(pname);
	clearpage(4,77,3,22);
}
void main()
{
	clrscr();
	openingscreen();
	contentfirstpage();
	getch();
}
void playerscore()
{

	pscore=e;
	gotoxy(30,10);cout<<" you have scored "<<pscore;
}
void createquestion()
{
	fstream f;
	f.open("GAMEQUES.dat",ios::out|ios::binary);
	game d[10];
	for(i=1;i<=10;i++)
	{
		d[i].inputquestion();
		d[i].inputanswer();
		f.write((char*)&d,sizeof(d));
	}
	f.close();
}
void readquestion()
{
	fstream f;
	f.open("GAMEQUES.dat",ios::in|ios::binary);
	game d[10];
	while(f)
	{
		f.read((char*)&d,sizeof(d));
		if(f.eof())
		break;
	}
	cout<<d[i].retques()<<endl;
	f.close();
}
void checkanswer()
{
	fstream f;
	f.open("GAMEQUES.dat",ios::in|ios::binary);
	game d[10];
	char playeranswer[50];
	cout<<"Enter Answer :";
	gets(playeranswer);
	while(f)
	{
		f.read((char*)&d,sizeof(d));
		if(f.eof())
		break;
	}
	if(strcmpi(playeranswer,d[i].retans())==0)
	{
	      gotoxy(32,10);
	      cout<<"Correct! ";
	      e++;
	}
	else
	{
	      gotoxy(32,10);
	      cout<<"Wrong. ";
	      getch();
	      cout<<"Answer is "<<d[i].retans();
	      b++;
		  whichrick();
	}
	f.close();
}
void openingscreen()
{
	gotoxy(33,12);
	clrscr();
	char wrek[9]="WREKONIN";
	gotoxy(33,5);

	fancy(wrek);
	borders();

}
void outline()  //outline during gamestart
{

	rick();
	//for dividing the plane in two parts
	for(j=1;j<=25;j++)
	{
		gotoxy(25,j);cout<<"Û";
		delay(10);
	}
	// for making box for score
	for(j=14;j<=17;j++)
	{
		gotoxy(47,j);cout<<"*";
		delay(10);
	}
	for(j=14;j<=17;j++)
	{
		gotoxy(65,j);cout<<"*";
		delay(10);
	}
	for(i=47;i<=65;i++)
	{
		gotoxy(i,14);cout<<"*";
		delay(10);
	}
	for(i=47;i<=65;i++)
	{
		gotoxy(i,17);cout<<"*";
		delay(10);
	}
	gotoxy(48,15);
	cout<<" Correct   Wrong "<<endl<<endl;
}
void borders()
{
	_setcursortype(_NOCURSOR);
	for(i=1;i<=79;i++)
	{
		gotoxy(i,1);cout<<"²";
		gotoxy(i,25);cout<<"²";
		delay(20);
	}
	for(j=1;j<=25;j++)
	{
		gotoxy(1,j);cout<<"²²";
		gotoxy(78,j);cout<<"²²";
		delay(20);
	}
}

void clearscreen()     //when the question is answered
{
	for(a=26;a<=77;a++)
	{
		for(j=2;j<=11;j++)
		{
			gotoxy(a,j); cout<<" ";
		}
	}
}
void gameoversetup()     // shows gameover
{	//borders
	borders();
	//game
	delay(100);
	gotoxy(3,2);cout<<  "   _____________                                                           ";
	gotoxy(3,3);cout<<  " |                                                                         ";
	gotoxy(3,4);cout<<  " |   __________                |         |              |    ------------- ";
	gotoxy(3,5);cout<<  " |  |                         | |        | '          ' |   |    _________|";
	gotoxy(3,6);cout<<  " |  |                        |   |       |  |       |   |   |   |          ";
	gotoxy(3,7);cout<<  " |  |      _______          |     |      | '  |    |  ' |   |   |_________ ";
	gotoxy(3,8);cout<< " |  |             | |      |||||||||     | ||  |  |  || |   |    _________|";
	gotoxy(3,9);cout<< " |  |___________  | |     |         |    | | |  ||  | | |   |   |          ";
	gotoxy(3,10);cout<< " |______________  | |    |           |   | |  |    |  | |   |   |_________ ";
	gotoxy(3,11);cout<< "		    | |   |             |  | |   |  |   | |   |             |";
	gotoxy(3,12);cout<< "	            | |  |               | | |    ||    | |    ------------- ";

	//over
	delay(100);

	 gotoxy(3,13);cout<<  "  ------------                                            ___________    ";
	 gotoxy(3,14);cout<<  " |  ________  |  |               |    -------------      | | -------||   ";
	 gotoxy(3,15);cout<<  " | |        | |  | |           | |   |    _________|     | |        ||   ";
	 gotoxy(3,16);cout<<  " | |        | |   | |         | |    |   |               | |        ||   ";
	 gotoxy(3,17);cout<<  " | |        | |    | |       | |     |   |_________      | |        ||   ";
	 gotoxy(3,18);cout<<  " | |        | |     | |     | |      |    _________|     | | -------||   ";
	 gotoxy(3,19);cout<<  " | |        | |      | |   | |       |   |               | | |  |        ";
	 gotoxy(3,20);cout<<  " | |________| |       | | | |        |   |_________      | |    | |      ";
	 gotoxy(3,21);cout<<  " |            |        || ||         |             |     | |      | |    ";
	 gotoxy(3,22);cout<<  "   -----------          |||           -------------      | |        | |  ";


	getch();
}
void starbox()    // question box
{
	for(a=30;a<=74;a++)
	{
		gotoxy(a,4);cout<<"*";
		gotoxy(a,11);cout<<"*";
	}
	for(j=4;j<=11;j++)
	{
		gotoxy(30,j);cout<<"*";
		gotoxy(74,j);cout<<"*";
	}
}
void playgame()
{
	_setcursortype(_NORMALCURSOR);
	playername();
	outline();
	for(i=0;i<10;i++)
	{
		starbox();
		gotoxy(32,6);
		readquestion();
		gotoxy(32,8);
		checkanswer();
		score();
		clearscreen();
		if(b==4)
		{
			clrscr();
			gameoversetup();
			clearpage(3,77,2,22);
			playerscore();
			getch();
			e=0;
			b=0;
			clearpage(3,77,2,22);
			contentfirstpage();

		}
		if(e+b==10)
		{
			clrscr();
			gameoversetup();
			getch();
			clrscr();
			playerscore();
			getch();
			e=0;
			b=0;
			contentfirstpage();

		}
	}
}
void score()     //keeps score
{
	gotoxy(49,16);
	cout<<"   "<<e<<"        "<<b<<endl;
	getch();
}
void whichrick()     //displays different types of rick(s)
{

	if(b==1)
	{
		ri[1][1]=0;
		ri[1][2]=5;
		mrick();
	}

	else if(b==2)
	{
		ri[1][1]=5;
		ri[1][2]=10;
		mrick();
	}
	else if(b==3)
	{
		ri[1][1]=10;
		ri[1][2]=15;
		mrick();
	}
}
void clearpage(int aa,int ab,int ac,int ad) //clearing page during transition of options and other stuff
{
	for(a=aa;a<=ab;a++)
	{
		for(j=ac;j<=ad;j++)
		{
			gotoxy(a,j); cout<<" ";
		}
	}
}
int cmd()      //code for using keyboard arrows
{
	char ch;
	ch=getch();
	int val;
	switch(ch)
	{

		case 'M':val=2; break;
		case 'K':val= 3; break;
		case 13 :val= 4; break;

	}
	return val;
}
/*
		up     72 H
		down   80 P
		left   75 K
		right  77 M
		return 13
*/
void contentfirstpage()
{
	_setcursortype(_NOCURSOR);
	int x,y,z,p,q,r,s,g,h,temp;
	char ch;
	char  help[5][33]={"WRECKONIN : GET WRECKED !",
			    "HI! I'M RICK AND I AM A WRECK!",
			    "THE GOAL OF THE GAME IS TO RECKON",
			    "THE CORRECT WORD AND SAVE ME FROM",
			    "GETTING WRECKED!!!"
			    };



	char about[5][33]={"DEVELOPERS :",
			    "ARYAN & AKASH",
			    "CLASS 12 C  ",
			    "St. Columbas School",
			    "             ",
			    };



	char l[12]=" PLAY GAME ";
	p=strlen(l);
	char m[10]=" HELP ";
	q=strlen(m);
	char n[10]=" ABOUT ";
	r=strlen(n);
	char o[10]=" EXIT ";
	s=strlen(o);
	char arrowl,arrowr;
	arrowl=17;
	arrowr=16;
	gotoxy(61,10); cout<<arrowl;
	gotoxy(71,10); cout<<arrowr;
	gotoxy(63,10);  cout<<"OPTIONS ";

	for(g=0;g<=p;g++)
	{
		gotoxy(63+g,12);
		delay(100);
		cout<<l[g];

	}
	rick();
	x=1;
	while(1)
	{
	cmd();
	h=cmd();
	if(h==4)
	{
			if(x==1)
			{
				playgame();
				break;
			}
			else if(x==4)
			{
				exit(0);
				break;
			}
	}
	else if(h==2)
	{
		if(x==1)
		{
			clearpage(24,60,3,22);
			for(g=0;g<=q;g++)
			{
				gotoxy((63+q)-g,12);
				delay(30);
				cout<<m;
				x=2;
			}
			for(g=0;g<=20;g++)
			{
				gotoxy((40)-g,5);
				delay(20);
				rick();
				for(i=0;i<5;i++)
				{
					for(j=0;j<33;j++)
					{
						gotoxy(25+j,14+i);cout<<help[i][j];//about
					}
				}

			}

		}
		else if(x==2)
		{
			clearpage(24,60,3,22);
			for(g=0;g<=r;g++)
			{
				gotoxy((63+r)-g,12);
				delay(30);
				cout<<n;
				x=3;
			}
			for(g=0;g<=20;g++)
			{
				gotoxy((40)-g,5);
				delay(20);
				rick();
				for(i=0;i<5;i++)
				{
					for(j=0;j<33;j++)
					{
						gotoxy(25+j,14+i);cout<<about[i][j];//about
					}
				}

			}
		}
		else if(x==3)
		{
			clearpage(24,60,3,22);
			for(g=0;g<=s;g++)
			{
				gotoxy((63+s)-g,12);
				delay(30);
				cout<<o;
				x=4;
			}

		}
	}
	else if(h==3)
	{
		if(x==1)
		{
			gotoxy(63,18);
		}
		else if(x==2)
		{
			clearpage(24,60,3,22);
			for(g=0;g<=p;g++)
			{
				gotoxy((63-p)+g,12);
				delay(30);
				cout<<l;
				x=1;
			}

		}
		else if(x==3)
		{
			clearpage(24,60,3,22);
			for(g=0;g<=q;g++)
			{
				gotoxy((60-q)+g+3,12);
				delay(30);
				cout<<m;
				x=2;
			}
			for(g=0;g<=20;g++)
			{
				gotoxy((40)-g,5);
				delay(20);
				rick();
				for(i=0;i<5;i++)
				{
					for(j=0;j<33;j++)
					{
						gotoxy(25+j,14+i);cout<<help[i][j];//help
					}
				}

			}
		}
		else if(x==4)
		{
			clearpage(24,60,3,22);
			for(g=0;g<=r;g++)
			{
				gotoxy((60-r)+g+3,12);
				delay(30);
				cout<<n;
				x=3;
			}
			for(g=0;g<=20;g++)
			{
				gotoxy((40)-g,5);
				delay(20);
				rick();
				for(i=0;i<5;i++)
				{
					for(j=0;j<33;j++)
					{
						gotoxy(25+j,14+i);cout<<about[i][j];//about
					}

				}
			}
		}

	}

   }
}
 //     ± 177
 //     Û 987
  //	Þ 222
void rick()
{
	gotoxy(5,2);   cout<<"        ,          "<<endl;
	gotoxy(5,3);   cout<<"      ,   ,        "<<endl;
	gotoxy(5,4);   cout<<"      .....        "<<endl;
	gotoxy(5,5);   cout<<"     | o o |       "<<endl;
	gotoxy(5,6);   cout<<"     |  _  |       "<<endl;
	gotoxy(5,7);   cout<<"      \\   /        "<<endl;
	gotoxy(5,8);   cout<<" ......|.|.......  "<<endl;
	gotoxy(5,9);   cout<<" | ..        .. |  "<<endl;
	gotoxy(5,10);  cout<<" | |.        .| |  "<<endl;
	gotoxy(5,11);  cout<<" | |.        .| |  "<<endl;
	gotoxy(5,12);  cout<<" | |.        .| |  "<<endl;
	gotoxy(5,13);  cout<<" |_|.        .|_|  "<<endl;
	gotoxy(5,14);  cout<<" (,).        .(,)  "<<endl;
	gotoxy(5,15);  cout<<"    . . . .  .     "<<endl;
	gotoxy(5,16);  cout<<"    *        *     "<<endl;
	gotoxy(5,17);  cout<<"    *   *    *     "<<endl;
	gotoxy(5,18);  cout<<"    *  *  *  *     "<<endl;
	gotoxy(5,19);  cout<<"    * *    * *     "<<endl;
	gotoxy(5,20);  cout<<"    * *    * *     "<<endl;
	gotoxy(5,21);  cout<<"    * *    * *     "<<endl;
	gotoxy(5,22);  cout<<"    *.*    *.*     "<<endl;
	gotoxy(5,23);  cout<<"    | |    | |     "<<endl;
	gotoxy(5,24);  cout<<"  (___)    (___)   "<<endl;
}
void mrick()
{

	char rick[24][19]={
	   "                   ",	
       "        ,          ",
       "      ,   ,        ",
       "      .....        ",
       "     | o o |       ",
       "     |  _  |       ",
       "      \\   /        ",
       " ......|.|.......  ",
       " | ..        .. |  ",
       " | |.        .| |  ",
       " | |.        .| |  ",
       " | |.        .| |  ",
       " |_|.        .|_|  ",
       " (,).        .(,)  ",
       "    . . . .  .     ",
       "    *        *     ",
       "    *   *    *     ",
       "    *  *  *  *     ",
       "    * *    * *     ",
       "    * *    * *     ",
       "    * *    * *     ",
       "    *.*    *.*     ",
       "    | |    | |     ",
       "  (___)    (___)   ",
       } ;
       _setcursortype(_NOCURSOR);
       int x,y,j;
       for(int a=ri[1][1];a<=ri[1][2];a++)    //24(r),19(c)
       {
		for(int m=0;m<=23-a;m++)
		{
			gotoxy(4,2+a+m);
			for(int k=0;k<=18;k++)
			{
				cout<<rick[m][k];
			}
		}
		delay(100);
       }
       
}
void fancy(char d[])
{
	
	
	
	int a,c=10,e,f;
	char b;
	f=strlen(d);

	for(i=0;i<f;i++)
	{
		gotoxy(33+i,5);
		for(i=1;i<=f;i++)
		{
			a=i;
			b=a;
			for(e=1;e<=c;e++)
			{
				delay(10);
				cout<<b;
				gotoxy(33+i-1,5);
			}
			cout<<d[i-1];

		}
		c=c+10;

	}
}


