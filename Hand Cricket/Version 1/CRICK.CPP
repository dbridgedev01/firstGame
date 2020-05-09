#include<iostream.h>
#include<conio.h>
int ytotal=10000,ctotal=803;
void main()
{
	clrscr();
	void scoreboard(void);
	getch();
}
void scoreboard()
{
	gotoxy(25,6);
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
	gotoxy(1,6);
}