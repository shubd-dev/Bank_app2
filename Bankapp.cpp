#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
#include<string>
using namespace std;
class new_applicant
{
    int age;
    string dob;
    int year_of_birth;
    string name;
    char gender;
public:
    int id;
    new_applicant()
    {
        cout<<"Welcome and Thank you for Choosing this bank to store your money\n";
        cout<<"follow steps accordingly to register\n";
    }
    void get_data()
    {
        cout<<"Name:";
        cin>>name;
        cout<<"Your date of Birth(dd/mm/yyyy):";
        cin>>dob;
        cout<<"Enter your year of Birth again:";
        cin>>year_of_birth;
        age = 2020 - year_of_birth;
        cout<<"Enter Gender(M/F/O):";
        cin>>gender;
    }
    void verify_age()
    {
        if((2020 - year_of_birth) < 18)
        {
            cout<<"Sorry you are under aged.\n\tChildren's Bank-\n\t Comming Soon\n";
            sleep(3);
            exit(10);
        }
        else
        {
            cout<<"Please Enter govt. issued id no.:";
            cin>>id;
        }
    }
    void surity()
    {
        system("cls");
        cout<<"You have entered:\nName:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"Date of Birth:"<<dob<<endl;
        cout<<"Govt issued ID:"<<id<<endl;
        cout<<"Do you want to save your info:";
        char c;
        cin>>c;
        if(c == 'N' || c == 'n')
        {
            cout<<"Please enter your data again:";
            system("cls");
            get_data();
            verify_age();
            surity();
        }
        else
        {
            cout<<"All set for your registration\n";
        }
    }
    void registration()
    {
        string p = to_string(id)+".txt";
        ofstream new_app(p);
        new_app<<"id:"<<id<<"\nName:"<<name<<"\nage:"<<age;
        new_app<<"\nGender:"<<gender;
    }

    public:void new_a()
    {
        get_data();
        verify_age();
        surity();
        registration();
    }
};
class Existing: public new_applicant
{
    int tmp_id;
    string path;
public:
    void get_tmp_data()
    {
        cout<<"Please Enter your Govt issued id: ";
        cin>>tmp_id;
        path = to_string(tmp_id)+".txt";
        check(path);
    }
    void show_details()
    {
        fstream file;
        file.open(path,ios::in);
        if(!file)
        {
            cout<<"Error in opening file";
        }
        else
        {
            string cmd1 = "type "+path;
            const char* cmd = cmd1.c_str();
            system(cmd);
        }
        file.close();
    }
    void choose()
    {
        system("cls");
        cout<<"Welcome to your Account\n";
        cout<<"Select choice:\n1.Show your Details\n2.Change something\nOption:";
        int c;
        cin>>c;
        if(c == 1)
        {
            show_details();
        }
        else
        {
            cout<<"For changing your bank details:\n";
	cout<<"Create new application and we will delete existing one\n";
            string c1 = "del "+to_string(tmp_id)+".txt";
            const char* c2 = c1.c_str();
            system(c2);
            new_a();
        }
    }
    void check(string p)
    {
        ifstream ifile;
        ifile.open(p);
        if(ifile)
        {
            ifile.close();
            choose();
        }
        else
        {
            cout<<"You are not registered with this id "<<tmp_id<<endl;
            cout<<"Do you want to register?(Y/N)";
            char d;
            cin>>d;
            if(d == 'Y' || d == 'y')
            {
                new_a();
            }
        }
    }
    void exis_a()
    {
        get_tmp_data();
    }
};
int main(int argc, char** argv)
{
    if(argv[1] == "admin")
    {
        cout<<"To change some parameters of Bank Application"<<endl;
        cout<<"Admin features comming soon";
        exit(10);
    }
    int choice;
    restart_pro:
    system("cls");
    cout<<"Welcome to Bank Application Software\n";
    cout<<"1. Existing Customer\n2. New Customer\n";
    cin>>choice;
    if(choice == 1)
    {
        Existing e1;
        e1.exis_a();
        cout<<"\nThank you";
        exit(10);
    }
    if(choice == 2)
    {
        new_applicant a1;
        a1.new_a();
        cout<<"registration Success\n";
        cout<<"Exit? (Y/N)";
        char d;
        cin>>d;
        if(d == 'Y' || d == 'y')
        {
            exit(10);
            return 0;
        }
        if(d == 'N' || d == 'n')
        {
            goto restart_pro;
        }
    }
}