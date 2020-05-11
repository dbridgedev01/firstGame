#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
int ych,yto,cto,tosst,cch,ynum,cnum,ytotal=10000,ctotal=10000;
void scoreboard()
{
	gotoxy(65,6);
	cout<<"YOU";
	gotoxy(70,6);
	cout<<"COM";
	gotoxy(65,7);
	if(ytotal==10000)
		cout<<"DNB";
	else
		cout<<ytotal;
	gotoxy(70,7);
	if(ctotal==10000)
		cout<<"DNB";
	else
		cout<<ctotal;
	clrscr();
	gotoxy(1,6);
}
void batting()
{
	void bowling(void);
	clrscr();
	gotoxy(29,8);
	cout<<"Your batting starts in";
	for(int x=3;x;--x)
	{
		gotoxy(40,10);
		cout<<x;
		delay(1000);
	}
	clrscr();
	ytotal=0;
	randomize();
	cout<<"\n\n\nYour Batting\n\n\n";
	do
	{
		invalidbat:
		cout<<"\nYOU: ";
		cin>>ynum;
		if(ynum>0&&ynum<7)
		{
			cnum=random(6)+1;
			cout<<"COM: "<<cnum;
			if(ynum==cnum)
			{
				cout<<"\n\n!!!!OUT!!!!\n\n";
				cout<<"Your Score: "<<ytotal;
				break;
			}
			else
			{
				ytotal+=ynum;
				scoreboard();
				if(ytotal>ctotal)
				break;
			}
		}
		else
		{
			cout<<"Don't go above 6";
			goto invalidbat;
		}
	}while(1);
	getch();
	if(ctotal==10000)
	bowling();
}
void bowling()
{
	clrscr();
	gotoxy(30,8);
	cout<<"COM batting starts in";
	for(int x=3;x;--x)
	{
		gotoxy(40,10);
		cout<<x;
		delay(1000);
	}
	clrscr();
	ctotal=0;
	randomize();
	cout<<"\n\n\nCOM Batting\n\n\n";
	do
	{
		invalidbowl:
		cout<<"\nYOU: ";
		cin>>ynum;
		if(ynum>0&&ynum<7)
		{
			cnum=random(6)+1;
			cout<<"COM: "<<cnum;
			if(ynum==cnum)
			{
				cout<<"\n\n!!!!OUT!!!!\n\n";
				cout<<"COM Score: "<<ctotal;
				break;
			}
			else
			{
				ctotal+=cnum;
				scoreboard();
				if(ctotal>ytotal)
				break;
			}
		}
		else
		{
			cout<<"Wrong input";
			goto invalidbowl;
		}
	}while(1);
	getch();
	if(ytotal==10000)
	batting();
}
void toss()
{
	randomize();
	gotoxy(38,8);
	cout<<"TOSS";
	delay(3000);
	clrscr();
	cout<<"Choose odd(1) or even(2)";
	cin>>ych;
	cout<<"YOU: ";
	cin>>yto;
	cout<<"COM: ";
	cto=random(7);
	cout<<cto<<'\n';
	tosst=yto+cto;
	if((tosst%2==0&&ych==2)||(tosst%2==1&&ych==1))
	{
		cout<<"You win the toss\nBat(1) or Bowl(2): ";
		retoss:
		cin>>ych;
		if(ych==1)
		batting();
		else if(ych==2)
		bowling();
		else
		{
			cout<<"Invalid choice, please choose again\n";
			goto retoss;
		}
	}
	else if((tosst%2==0&&ych==1)||(tosst%2==1&&ych==2))
	{
		cout<<"You lose the toss\n";
		cch=random(1);
		if(cch==0)
		{
			cout<<"COM chooses to Bowl\n";
			getch();
			batting();
		}
		else
		{
			cout<<"COM chooses to Bat\n";
			getch();
			bowling();
		}
	}
}
void main()
{
	clrscr();
	randomize();
	toss();
	clrscr();
	if(ytotal>ctotal)
	{
		gotoxy(33,10);
		cout<<"Congratulations";
		gotoxy(34,11);
		cout<<"!!!YOU WIN!!!";
		gotoxy(35,12);
		cout<<"You win by "<<ytotal-ctotal<<" runs";
	}
	else if(ytotal==ctotal)
	{
		gotoxy(35,10);
		cout<<"Draw Match";
	}
	else if(ytotal<ctotal)
	{
		gotoxy(37,10);
		cout<<"Too bad";
		gotoxy(36,11);
		cout<<"YOU LOSE";
		gotoxy(32,12);
		cout<<"COM wins by "<<ctotal-ytotal<<" runs";
	}
	getch();
}
