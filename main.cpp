#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include"MMSystem.h"
#include<windows.h> //Plays audio track
//#include<bits/stdc++.h>
//-lwinmm
//PlaySoundA(TEXT("welcome.wav"), NULL, SND_SYNC);
using namespace std;
int ch;
void switch_menu();
void add_details();
class mainframe
{
	public:
	
	void forwardstar()
	{
		for(int i=0;i<110;i++)
		cout<<"*";
	}
	
	void display(){
	
	cout<<"\t\t\t\t";
	forwardstar();
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t";
	cout<<"\t\t\t\t\t    WELCOME TO WEATHER FORECASTING"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t MADE BY ADITYA SHREE"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t   REG. NO: 11703895"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t        CSE202"<<endl;
    cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t";
	forwardstar();
	getch();
	}};
	
	
	void menudisplay(){
		mainframe ob1;
		system("cls");  // Used for clearing screen.
	    cout<<"\t\t\t\t";	
		ob1.forwardstar();
		cout<<"\n\n\n\n\n\n\n";
	    cout<<"\t\t\t\t\t\t\t\t\t\t";
		cout<<"1: Add city details"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t";
		cout<<"2: View report"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t";
		cout<<"3: Exit"<<endl;
		cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter your choice : ";
		cin>>ch;		
		cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t";
	ob1.forwardstar();
		switch_menu();
	}
	void login(){
	system("cls");
	
	mainframe ob1;
	int aUserId ,apwd;
	cout<<"\t\t\t\t";
	ob1.forwardstar();
	cout<<"\n\t\t\t\t\t------------------ADMIN LOGIN------------------";
	PlaySoundA(TEXT("username.wav"), NULL, SND_SYNC);
	cout<<"\n\t\t\t\t\tUser Id : ";
	cin>>aUserId;
	cout<<"\n\t\t\t\t\tEnter Password : ";
	cin>>apwd;
	if(apwd == 1 && aUserId == 1){
		cout<<"\n\n\t\t\t\t\t\tLOGIN SUCCESSFULL\n\n\t\t\t\t\tPress any key to continue....";
		getch();
		add_details();
	}
	else{
		ob1.forwardstar();
		cout<<"\n\n\n\n\t\t\t\t\t------------------ACCESS DENIED------------------";
		menudisplay();
	}
	}
	
void add_details()
{
system("cls");
string city,atmosphere;
string humidity,temperature,hightemp,lowtemp;
mainframe ob1;
//cout<<"\n\n\n\n\n\n\n";
cout<<"\t\t\t\t";
ob1.forwardstar();
cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter city name: ";
cin>>city;
for(int i=0;i<city.size();i++){
	city[i] = tolower(city[i]);
}
cout<<"\n\t\t\t\t\t\t\t\tEnter the humidity : ";
cin>>humidity;
cout<<"\n\t\t\t\t\t\t\t\tEnter the temperature : ";
cin>>temperature;
cout<<"\n\t\t\t\t\t\t\t\tEnter the max. temp : ";
cin>>hightemp;
cout<<"\n\t\t\t\t\t\t\t\tEnter the min. temp : ";
cin>>lowtemp;
char s1[100],s3[100];
strcpy(s1,city.c_str());
strcat(s1,".txt");
ofstream fout;
fout.open(s1);
string s2;
s2 = "\t\t\t\t\t\t   ***********Weather Report of "+city+"***********\n"+"\t\t\t\t\t\t\t\t1.City Name : "+city+"\n\t\t\t\t\t\t\t\t2.Humidity : "+humidity+"\n\t\t\t\t\t\t\t\t3.Temperature : "
			+temperature+"\n\t\t\t\t\t\t\t\t4.Max.Temp : "+hightemp+"\n\t\t\t\t\t\t\t\t5.Min. Temp : "+lowtemp;
char s4[200];
strcpy(s4,s2.c_str());
fout.write(s4,strlen(s4));
}

void view_details(){
	system("cls");
	string city;
	mainframe ob2;
	//cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t";
	ob2.forwardstar();
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEnter city name: ";
	cin>>city;
	for(int i=0;i<city.size();i++){
	city[i] = tolower(city[i]);
	}
	char s1[100];
	strcpy(s1,city.c_str());
	strcat(s1,".txt");
	ifstream fin;
	fin.open(s1);
	if(fin.fail()){
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tCITY DOES NOT EXISTS...";
		getch();
		menudisplay();
	}
	char ch; 
	system("cls");
    while(!fin.eof())
    {
        fin.get(ch);//ch=fin.get();
        cout<<ch;
	}
	getch();
}	

void switch_menu(){
	switch(ch){
		case 1:
			login();
			menudisplay();
			break;
		case 2:
			view_details();
			menudisplay();
			break;
		case 3:
			exit(0);
		default:
			cout<<"Please enter correct choice.";
			menudisplay();
	} 
}
	
int main()
{
	system("color 1a");
	mainframe ob;
	ob.display();
	menudisplay();
	return 0;
	
}

