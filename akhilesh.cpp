#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
  static int G=0;
using namespace std;
class Booth
{    int veh_type;
     int load;
    int j_type;
     string pass;
     int tax;
     public:
	 void Add_vehicle()
	 {     string s="truck",s1="bus",s2="car",s3="van",s4="motorbike",s5="Government";
	       // string p="yes";
	       int fare;
	    ofstream off("akhilesh.txt",ios::app);
	cout<<"Enter the Type of vehicle from these : \n1.truck \n2.bus \n3.car \n4.van \n5.motorbike \n6.government";
	cin>>veh_type;
	if(veh_type==1)
	off<<s;
	if(veh_type==2)
	off<<s1;
	if(veh_type==3)
	off<<s2;
	if(veh_type==4)
	off<<s3;
	if(veh_type==5)
	off<<s4;
	off<<endl;
	if(veh_type!=6)
	{
	
	cout<<"Enter the load of vehicle : ";
	cin>>load;
	off<<load;
	off<<endl;
	cout<<"Enter the type of Journey \n1. one_sided  \n2. round_trip: ";
	cin>>j_type;
	if(j_type==1)
	off<<"one-sides";
	if(j_type==2)
	off<<"round-trip";
    off<<endl;
	cout<<"Do you Have pass (Enter yes or no): ";
	cin>>pass;
	off<<pass;
    off<<endl;}
	if(veh_type==1)
	{    fare=80;
}
if(veh_type==2)
{
	fare=60;
}
if(veh_type==3)
{
	fare=30;
}
if(veh_type==4)
{
	fare=40;
}
if(veh_type==5)
{
	fare=20;
}
if(veh_type==6)
{  G++;
	cout<<"you don't have to pay money";
}
if(veh_type!=6)
	    {
		  if(pass=="yes")
	     {
	     	fare=fare*0.5;
	     	cout<<"50% discount is applied for your pass"<<endl;
		 }
	     if(load<100&&j_type==1)
	     {
	     	cout<<"your tax is Rs."<<fare<<" : Enter your tax amount :: ";
	     	cin>>tax;
	     	while(tax<fare)
	     	{
	     		cout<<"Please Enter more than "<<fare<<"Rs.";
	     		cin>>tax;
			 }
	     	off<<fare;
           off<<endl;
	     	/*do
	     	{
	     		cout<<"Re-enter your tax amount ,should be more than "<<fare<<"Rs."<<endl;
	     		cin>>tax;
			 }while(tax<fare);*/
			 cout<<"-------fees successfully submitted------- "<<endl;
			 cout<<"amount to be returned "<<(tax-fare)<<endl;
		 }
		 if((load>100||load==100)&&j_type==1)
	  {
	  	fare=fare*2;
	  	cout<<"you tax is doubled due to overweight"<<endl;
	  		cout<<"your tax is Rs."<<fare<<" : Enter your tax amount :: ";
	     	cin>>tax;
	     	while(tax<fare)
	     	{
	     		cout<<"Please Enter more than "<<fare<<"Rs.";
	     		cin>>tax;
			 }
	     	off<<fare;
           off<<endl;
	  	cout<<"-------fees successfully submitted------- "<<endl;
			 cout<<"amount to be returned "<<(tax-fare)<<endl;
	  }
	  if((load>100||load==100)&&j_type==2)
	  {
	  	fare=fare*3;
	  	cout<<"your tax is tripled due to overweight and round-trip journey"<<endl;
	  		cout<<"your tax is Rs."<<fare<<" : Enter your tax amount :: ";
	     	cin>>tax;
	     	while(tax<fare)
	     	{
	     		cout<<"Please Enter more than "<<fare<<"Rs.";
	     		cin>>tax;
			 }
	     	off<<fare;
           off<<endl;
           cout<<"-------fees successfully submitted------- "<<endl;
			 cout<<"amount to be returned "<<(tax-fare)<<endl;
	  }
	  if(load<100&&j_type==2)
	  {  cout<<"your tax is doubled due to round-trip journey"<<endl;
	  	fare=fare*2;
	  		cout<<"your tax is Rs."<<fare<<" : Enter your tax amount :: ";
	     	cin>>tax;
	     	while(tax<fare)
	     	{
	     		cout<<"Please Enter more than "<<fare<<"Rs.";
	     		cin>>tax;
			 }
	     	off<<fare;
           off<<endl;
           cout<<"-------fees successfully submitted------- "<<endl;
			 cout<<"amount to be returned "<<(tax-fare)<<endl;
	  }
}
	//off.write((char*)this,sizeof(*this));
	off.close();
	

}	 void Show_data()
	 {   string s;
	 int i=0;
	 int t=1;
	ifstream iff("akhilesh.txt");
	while(iff)
	{    getline(iff,s);
	if(i==0)
	{   cout<<t<<". vehicle type ="<<s<<endl;
		t++;
	}
		if(i==1)
		cout<<"load of vehicle ="<<s<<endl;
		if(i==2)
		cout<<"journey type ="<<s<<endl;
		if(i==3)
		cout<<"with pass ="<<s<<endl;
		if(i==4)
		cout<<"tax payed ="<<s<<endl<<endl;
	//	cout<<"------------------end-------------------------";
            i++;
				if(i==5)
		{ i=0;
		}
	}
	cout<<"total goverment vehicles pass ="<<G<<endl;
	iff.close();
}
};
int main()
{    int x;
char choice;
Booth b;
	cout<<"\t\t\t\t\tHello User Welcome to my program"<<endl<<"press 1 to start the program "<<endl;
	cin>>x;
	if(x==1)
	{   do{
	cout<<"\t\t\t\tchoose an option to proceed : "<<endl;
		cout<<"1. Add vehicles \n2. show Vehicles passed today";
		cin>>x;
		if(x==1)
		{
			b.Add_vehicle();
		}
		if(x==2)
		{
			b.Show_data();
		}
		cout<<"do you want program to run again (Enter y for yes)"<<endl;
		cin>>choice;
	}while(choice=='y'||choice=='Y');
	}
}
