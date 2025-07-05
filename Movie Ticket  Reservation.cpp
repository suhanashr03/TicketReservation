#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>


using namespace std;

class Movie{
    int id;
    char name[30];
    char address[50];
    char phone[10];
    int movie;

public:
    void Menu();
    void add();
    void display();
    void ticket();
    void edit();
    int check(int);
    void modify(int);
    void delete_rec(int);
};

int main(){
    Movie m;
    system("cls");
    cout<<"\n\n\n\t\t\t ||||||||||||||||||||||||||||||||||||||||||||";
    cout<<"\n\t\t\t |                                          |";
    cout<<"\n\t\t\t |     MOVIE TICKET RESERVATION SYSTEM      |";
    cout<<"\n\t\t\t |                                          |";
    cout<<"\n\t\t\t ||||||||||||||||||||||||||||||||||||||||||||";
    cout<<"\n\n\t\t\t WELCOME \\~_~/";
    cout<<"\n\n\n\n\n\n\n\t\t\t Press any key to continue";
    getch();
    m.Menu();
    return 0;
}

void Movie::Menu(){
    int choice;
    while(choice!=5){
        system("cls");
        cout<<"\n\n\n\t\t\t *************************************";
        cout<<"\n\t\t\t *                                     *";
        cout<<"\n\t\t\t *               MAIN MENU             *";
        cout<<"\n\t\t\t *                                     *";
        cout<<"\n\t\t\t *************************************";
        cout<<"\n\n\n\t\t\t 1. Book A Ticket";
        cout<<"\n\t\t\t 2. Customer Records";
        cout<<"\n\t\t\t 3. Booked Seats";
        cout<<"\n\t\t\t 4. Edit Record";
        cout<<"\n\t\t\t 5. Exit";
        cout<<"\n\n\t\t\t Enter Your Choice: ";
        cin>>choice;

        switch(choice){
            case 1: add();
                break;
            case 2: display();
                break;
            case 3: ticket();
                break;
            case 4: edit();
                break;
            case 5: break;

            default:
            {
                cout<<"\n\n\t\t\t Wrong Choice";
                cout<<"\n\t\t\t Press any key to continue...";
            getch();
            }
        }
    }
}

int Movie::check(int n)
{
    int flag=0;
    ifstream fin("Record.dat",ios::in);
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(Movie));
        if(id==n)
        {
            flag=1;
            break;
        }
    }
    fin.close();
    return(flag);
}

void Movie::add(){
    system("cls");
    int n, flag;
    ofstream fout("Record.dat", ios::app);
    cout<<"\n\n\n\t -------------------------";
    cout<<"\n\t Enter Customer Details";
    cout<<"\n\t -------------------------";
    cout<<"\n\n\t Seat number: ";
    cin>>n;
    flag=check(n);
    if (flag)
        cout<<"\n\t Seat Taken Already!  ";
    else {
        id=n;
        cout<<"\n\t Name: ";
        cin>>name;
        cout<<"\t Phone No.: ";
        cin>>phone;
        cout<<"\t Email Address: ";
        cin>>address;
        cout<<"\n\t Movie List: ";
        cout<<"\n\t [1] Avengers";
        cout<<"\n\t [2] Harry Potter";
        cout<<"\n\t [3] Jumanji ";
        cout<<"\n\t     Enter the number indicating the movie you want to watch: ";
        cin>>movie;
        if (movie!=1 && movie!=2 && movie!=3 ){
            cout<<"\n\t Movie Not Found!!!\n\t Please delete your entry and Try again :(n";

        }
        fout.write((char*)this,sizeof(Movie));
        cout<<"\n\n\t Ticket is successfully booked :)";
    }
    cout<<"\n\t Press any key to continue";
    getch();
    fout.close();
}

void Movie::display(){ //function for displaying customer's records
    system("cls");
    ifstream fin("Record.dat",ios::in);
     int n,flag;
     cout<<"\n\n\n\t -----------------------------------------------------";
     cout<<"\n\t Enter Seat number for a particular customer's details :- ";
     cin>>n;
     cout<<"\t -----------------------------------------------------";
     while(!fin.eof()){
         fin.read((char*)this,sizeof(Movie));
         if(id==n){
             system("cls");
             cout<<"\n\n\n\t -------------------";
             cout<<"\n\t  Customer Details";
             cout<<"\n\t -------------------";
             cout<<"\n\n\t Seat number: "<<id;
             cout<<"\n\n\t Name: "<<name;
             cout<<"\n\t Phone no: "<<phone;
             cout<<"\n\t Email Address: "<<address;
             cout<<"\n\n\t -------------------------------------";
             if (movie==1){
                cout<<"\n\t Movie: Avengers";
                cout<<"\n\t Price: 1500.00 ";
             }
             else if (movie==2){
                cout<<"\n\t Movie: Harry Potter";
                cout<<"\n\t Price: 2000.00";
             }
             else if (movie==3){
                cout<<"\n\t Movie: Jumanji";
                cout<<"\n\t Price: 2500.00";
             }
             flag=1;
             break;
        }
            else //if(flag==0)
                flag=0;
                cout<<"\n\t Wrong Seat Number! ";
     }

    cout<<"\n\n\t Press any key to continue";
    getch();
    fin.close();
}

void Movie::ticket() //function to display all booking tickets
{
    system("cls");
    ifstream fin("Record.dat",ios::in);
    cout<<"\n\t\t\t\t\t\tList of Booked Seats";
    cout<<"\n\t\t\t\t  ----------------------------------------------";
    cout<<"\n\n";
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(Movie));
        cout<<"\t\t "<<id;
    }
    cout<<"\n\n\n\t\t\t Press any key to continue";
    getch();
    fin.close();
}

void Movie::edit() //function to editing records and view bill
{
    system("cls");
    int choice,n;
    cout<<"\n\n\n\t ---------";
    cout<<"\n\t EDIT MENU";
    cout<<"\n\t ---------";
    cout<<"\n\n\t [1] Modify Customer Record";
    cout<<"\n\t [2] Delete Customer Record";
    cout<<"\n\n\t Enter your choice:- ";
    cin>>choice;
    system("cls");

    cout<<"\n\t Enter Seat Number: " ;
    cin>>n;

    switch(choice)
    {
        case 1: modify(n);
        break;
        case 2: delete_rec(n);
        break;
        default:
            cout<<"\n Wrong Choice";
            break;
    }
    cout<<"\n\n\t Press any key to continue";
    getch();
}

void Movie::modify(int n) //function to edit customers record
{
    long pos,flag=0;
    fstream file("Record.dat",ios::in|ios::out|ios::binary);
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(Movie));
        if(id==n)
        {
            cout<<"\n\n\n\t -----------------";
            cout<<"\n\t Enter New Details";
            cout<<"\n\t -----------------";
            cout<<"\n\t Name: ";
            cin>>name;
            cout<<"\t Phone no: ";
            cin>>phone;
            cout<<"\t Email Address: ";
            cin>>address;
            cout<<"\n\t Movie List ";
            cout<<"\n\t [1] Avengers";
            cout<<"\n\t [2] Harry Potter";
            cout<<"\n\t [3] Jumanji";
            cout<<"\n\t Enter the Movie number you want to watch :- ";
            cin>>movie;
            file.seekg(pos);
            file.write((char*)this,sizeof(Movie));
            cout<<"\n Record is modified";
            flag=1;
            break;

        }
    }
    if(flag==0)
        cout<<"\n\t Sorry, You Have To Book A Ticket First! ";
    file.close();
}

void Movie::delete_rec(int n) //function for deleting record
{

    int flag=0;
    char ch;
    ifstream fin("Record.dat",ios::in);
    ofstream fout("temp.dat",ios::out);

     if (!fin || !fout) {
        cout << "Failed to open file\n";
        return;
    }
    Movie record;
    while (fin.read((char*)&record, sizeof(record))) {
         if (record.id == n) {
            flag = 1;
            cout << "The deleted record is:\n";
            record.display();
        }
        else {
            fout.write((char*)&record, sizeof(record));
        }
    }

    fout.close();
    fin.close();

    if (flag == 1) {
        remove("Record.dat");
        rename("temp.dat", "Record.dat");
        cout << "\n\t Record successfully deleted\n";
    }
    else {
        remove("temp.dat");
        cout << "\n\t Record not found\n";
    }
}
