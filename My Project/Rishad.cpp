#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include<conio.h>
using namespace std;
class password
{
  private:
      char username [30];
      char pass [12];
  public:
    void get_fix();

};




void password::get_fix()
{
    cout<<"Input User name: ";
    cin>>username;
    cout<<"Enter User Password: ";
    char ch;
    int i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            pass[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else if(ch==32||ch==9)
        {
            continue;
        }
        else
        {
            pass[i]=ch;
            i++;
            cout<<"*";
        }
    }
    pass[i]='\0';
    cout<<"\n";
    if((strcmp(username,"rishad")==0)&&(strcmp(pass,"43080023")==0))
    {
        cout<<"";
    }
    else
    {
        cout<<"\n\n !!Sorry Try Again.....\n"<<endl;
        getch();
        system("cls");
        get_fix();
    }
}


class staff
{
public:

    int Id;
    char Name[50],Post[50],Department[50];
    int Salary;
    int account_create();
    int show_account()  const;
    void modify_account();
    int return_id() const;
    int time();
};

int staff::time()
{
    float Fine;
    float en,ex;
    cout<<"Give your entry time : ";
    cin>>en;
    cout<<"Give your exit time : ";
    cin>>ex;
    float fine;
    fine=Salary*0.05;
    if(en<8 || ex>17)
        cout<<"THANK YOU,you have no fine....."<<endl;
    else
    {
        cout<<"THANK YOU,you have  5% fine Today....."<<endl;
        cout<<"Now your salary is = "<<fine;
    }
}

int staff::return_id() const
{
	return Id;
}

int staff::show_account() const
{
    cout<<Id<<setw(15)<<Name<<setw(15)<<Post<<setw(15)<<Department<<setw(15)<<Salary<<endl;
}

int staff::account_create()
{
    system("Cls");
    cout<<"Enter Staff ID:";
    cin>>Id;
    cout<<"Enter Staff Name:";
    cin.ignore();
    cin.getline(Name,50);
    cout<<"Enter Staff Post:";
    cin.getline(Post,50);
    cout<<"Enter Staff Department:";
    cin.getline(Department,50);
    cout<<"Enter Staff Salary:";
    cin>>Salary;

    cout<<"Thank You.\nPress Enter to go back to main page."<<endl;
    cin.get();
}

void case_show();
void write_account();
void display_all();
void edit_account(int n);
void delete_account(int);


int main()
{
    staff m;
    int c;
    int num;
    do
    {
        system("cls");
        case_show();
        cin>>c;
        cout<<endl<<endl;
        switch(c)
        {
        case 1:
            write_account();
            break;
        case 2:
            display_all();
            break;
        case 4:
            cout<<"\n\n\tEnter The ID NO. : "; cin>>num;
            cout<<endl;
            edit_account(num);
            break;
        case 3:
            cout<<"\n\n\tEnter The ID No. : "; cin>>num;
			delete_account(num);
			break;
        case 5:
            m.time();
            break;
        case 0:
            return 0;
            break;
        default:
            cout<<"Invalid choice ";
        }
        cout<<endl;
        cout<<"Press enter to continue... ";
        cin.get();
        cin.ignore();
    }
    while(c<=11);
return 0;
}


void delete_account(int n)
{
	staff m;
	ifstream inFile;
	ofstream outFile;
	inFile.open("staff.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
	}
	outFile.open("Temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(staff)))
	{
		if(m.return_id()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&m), sizeof(staff));
		}
	}
	inFile.close();
	outFile.close();
	remove("staff.txt");
	rename("Temp.txt","staff.txt");
	cout<<"\n\n\tRecord Deleted ..";
    cout<<"\n\nPress Enter To Return Main Menu.";
}


void edit_account(int n)
{
	bool found=false;
	staff m;
	fstream File;
	File.open("staff.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&m), sizeof(staff));
		if(m.return_id()==n)
		{
			m.show_account();
			cout<<"\n\n\tEnter The New Details of account"<<endl;
			m.account_create();
			int pos=(-1)*static_cast<int>(sizeof(staff));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&m), sizeof(staff));
			cout<<"\n\n\t Record Uptxted";
			cout<<"\n\n\tPress Enter To Return Main Menu.";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t Record Not Found ";
}


void display_all()
{
	staff m;
	ifstream inFile;
	inFile.open("staff.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
	}
	cout<<"\t\t\t\tALL ACCOUNT HOLDER LIST\n\n";

	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(staff)))
	{
		m.show_account();

	}
	inFile.close();
}
void write_account()
{
	staff m;
	ofstream outFile;
	outFile.open("staff.txt",ios::binary|ios::app);
	m.account_create();
	outFile.write(reinterpret_cast<char *> (&m), sizeof(staff));
	outFile.close();
}

void case_show()
{
    int i;
   system("Cls");
   system("color 0");
   cout<<"\n\t\t                   _____           ";
   cout<<"\n\t\t                  |_   _|              ";
   cout<<"\n\t\t   *------*        |   |       *------*";
   cout<<"\n\t\t   *-*  *-*        |   |       *-*  *-*";
   cout<<"\n\t\t     *  *     _____|___|_____    *  *       ";
   cout<<"\n\t\t     *  *    |  ___     ___  |   *  *       ";
   cout<<"\n\t\t     *  *    |_|   |   |   |_|   *  *       ";
   cout<<"\n\t\t     *  *          |   |         *  *       ";
   cout<<"\n\t\t     *  *     B    |   |    A    *  *       ";
   cout<<"\n\t\t     *  *         _|   |_        *  *       ";
   cout<<"\n\t\t     *  *        |_______|       *  *       ";
   cout<<"\n\t\t     *  *__________|   |_________*  *       ";
   cout<<"\n\t\t     *_____________|   |____________*       ";
   cout<<"\n\t\t                 __|   |__                  ";
   cout<<"\n\t\t                |_________|                \n\n\n\n";


    password p;
    p.get_fix();
    cout<<"Please Wait";
    for(i=0;i<=3;i++)
    {
        cout<<"*";
        Sleep(1000);
    }
   system("cls");
   //system("color 3f");
    cout << "\t\t\t<====== STAFF MANAGEMENT SYSTEM ======>";
    cout <<"\n\n                                          ";
    cout << "\n\n";
    cout<<"\n\n\t\t\t     MAIN SCREEN";
    cout<<"\n\t\t\t====================\n\n";
    cout<<"Enter your choice: "<<endl;
    cout<<"1.Add staff information"<<endl;
    cout<<"2.Show all staff information"<<endl;
    cout<<"3.Delete staff information"<<endl;
    cout<<"4.Edit staff information"<<endl;
    cout<<"5.Add Time"<<endl;
    cout<<"0.exit program"<<endl;
    cout<<"enter your choice"<<endl;

}
