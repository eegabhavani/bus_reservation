#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

 int p=0;
int bno;
class a
{
 char busn[10],driver[10],arrival[10],departure[10],from[10],to[10];
 char seat[8][4][10];
 public:
    void install(int);
    void allotment();
    void empty(int);
    void show();
    void avail();
    void position(int i);
}bus[100];
void vline(char ch)
{
  for (int i=0;i<80;i++)
  cout<<ch;
}
void a::install(int bno)
{
    while(p!=bno)
    {
    //installation
   cout<<p+1<<"enter the bus number";
   cin>>bus[p].busn;
   cout<<"enter the driver name:";
   cin>>bus[p].driver;
   cout<<"arrival time: ";
   cin>>bus[p].arrival;
   cout<<"depature time:";
   cin>>bus[p].departure;
   cout<<"from:";
   cin>>bus[p].from;
   cout<<"to:";
   cin>>bus[p].to;
   //making all the seats empty after installation
   bus[p].empty(p);
   p++;
  }
}
 void a::allotment()
 {
    int x,n,seat,i,j;
    char number[5],name[10];
    top:
     cout<<"\nbus no:";
     cin>>number;
     for(n=0;n<bno;n++)
     {
     if(strcmp(bus[n].busn,number)==0)
     {
      x=0;
     break;
     }
     }
     if(x!=0)
     {
      cout<<"\nincorrect bus number";
      cout<<"\nenter the valid bus number";
      goto top;
      }
       reserve:
       cout<<"\n seat number: ";
       cin>>seat;
       if(seat>32)
       {
	  cout<<"\n there are only 32 seats available in this bus.";
	  cout<<"\nenter the valid seat number.";
	  goto reserve;
       }
       else
       {
	 if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"empty")==0)
	 {
	   cout<<"\nenter the passenger's name: ";
	   cin>>name;
	   strcpy(bus[n].seat[seat/4][(seat%4)-1],name);
	 }
	 else
	   cout<<"\nthe seat number is already reserved for\t"<<bus[n].seat[seat/4][(seat%4)-1];
       }
    if(bno<=n)
     {
	cout<<"\nenter correct bus number...";
	goto top;
     }
}
 void a::empty(int n)
 {
    for( int i=0;i<8;i++)
    {
	for(int j=0;j<4;j++)
	{
	  strcpy(bus[n].seat[i][j],"empty");
	}
    }
 }
 void a::show()
 {
    int n,x;
    char number[5];
    bshow:
    cout<<"\nenter the bus number:";
    cin>>number;
    for(n=0;n<p;n++)
    {
       if(strcmp(bus[n].busn,number)==0)
       {
       x=0;
       break;
       }
    }
    if(x!=0)
    {
    cout<<"\ninvalid bus number..!";
    cout<<"\nenter the valid bus number";
    goto bshow;
    }
    while(n<p)
    {
      vline('*');
      cout<<"\n";
      cout<<"bus no:\t "<<bus[n].busn
	  <<"\ndriver name:\t"<<bus[n].driver
	  <<"\narrival time:\t"<<bus[n].arrival
	  <<"\ndepature time:\t"<<bus[n].departure
	  <<"\n from :\t"<<bus[n].from
	  <<"\n to:\t"<<bus[n].to
	  <<"\n";
	  vline('*');
	  bus[n].position(n);
	  int a=1;
	  for(int i=0;i<8;i++)
	  {
	    for(int j=0;j<4;j++)
	    {
	       a++;
	       if(strcmp(bus[n].seat[i][j],"empty")!=0)
	       cout<<"\nthe seat no:\t"<< (a-1) <<"is already reserved for\t"<< bus[n].seat[i][j]<<" .";
	    }
	  }
	  break;
    }
    if(n>p)
    {
    cout<<"enter the valid bus number.";
    goto bshow;
    }
 }
 void a::position(int l)
 {
    int s=0,p=0;
    for(int i=0;i<8;i++)
    {
     cout<<"\n";
       for(int j=0;j<4;j++)
       {
	  s++;
	  if(strcmp(bus[1].seat[i][j],"empty")==0)
	  {
	    cout.width(5);
	    cout.fill(' ');
	    cout<<s<<".";
	    cout.width(10);
	    cout.fill(' ');
	    cout<<bus[l].seat[i][j];
	    p++;
	  }
	  else
	  {
	   cout.width(5);
	    cout.fill(' ');
	    cout<<s<<".";
	    cout.width(10);
	    cout.fill(' ');
	    cout<<bus[l].seat[i][j];
	  }
       }
    }
    cout<<"\n\n there are "<<  p  <<"seats empty in bus no:"<< bus[1].busn;
 }

 void a::avail()
 {

   for(int n=0;n<p;n++)
   {
    vline('*');
      cout<<"\nbus no:\t "<<bus[n].busn
	  <<"\ndriver name:\t"<<bus[n].driver
	  <<"\narrival time:\t"<<bus[n].arrival
	  <<"\ndepature time:\t"<<bus[n].departure
	  <<"\n from :\t"<<bus[n].from
	  <<"\n to:\t"<<bus[n].to
	  <<"\n";
     vline('*');
     cout<<"\n";
     vline('-');
     cout<<"\n";
   }
}

int main()
{
     int ch;
    //system("cls");
    cout<<"\n\n\n\n";
    cout<<"\t\t\t1.install\n\t\t\t";
    cout<<"2.reservation\n\t\t\t";
    cout<<"3.show\n\t\t\t";
    cout<<"4.available buses\n\t\t\t";
    cout<<"5.exit";
    do
    {
    cout<<"\n\t\tenter the choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:cout<<"enter the number of no.of buses whose information should be stored:";
      cin>>bno;
      bus[p].install(bno);
      break;
      case 2:bus[p].allotment();
      break;
      case 3:bus[0].show();
      break;
      case 4:bus[0].avail();
      break;
      case 5:exit(0);
    }
   }while(ch!=5);
    return 0;
  }
