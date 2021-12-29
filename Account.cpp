
#include <iostream>
#include <string.h>
using namespace std;

class Accounts
{
    int acc_no, acc_type;

protected:
    char cus_name[20];
    int cheque_no;

public:
    int get_type()
    {
        return acc_type;
    }
    void getdata()
    {
        system("CLS");
        cout << "Enter Customer name:";
        cin.ignore();
        cin.getline(cus_name,20);
        cout << "Enter account No.:";
        cin >> acc_no;
        cout << "Enter account type\n1.Saving Account\n2.Current Account(Must be Mininmum amount in Current Account: 200):";
        cin >> acc_type;
        if(acc_type==2)
        cheq();

    }

    void show()
    {
        cout << "Account Holder name:" << cus_name << endl;
        cout << "Account Number:" << acc_no << endl;
        cout << "Account type\n1.Saving Account \n2.Current Account:" << acc_type << endl;



    }

    void cheq()
        {
            cout << "Enter your cheque no.";
            cin >> cheque_no;
        }

};
class sav_act : public Accounts
{
 int balance;
public:
    void Depoist()
    {
        int dep;
        cout << "Enter  the amount you want to depoist :";
        cin >> dep;

        balance +=dep;

    }
    void Withdraw()
    {
        int w_draw;
        cout << "Enter Withdrawl money:";
        cin >> w_draw;
        if (w_draw > balance)
        {
            cout << "\nInsufficient Balance:";
        }
        else
            balance -= w_draw;

    }
    void get_balance()
    {
        cout<<"Enter Account balance:";
        cin>>balance;
            }
            void show_balance()
            {
                cout<<"Current balance is :"<<balance<<endl;
            }
     void Interest()
    {
        int sim_int,t;

        cout<<"Enter time interval in year:";
        cin>>t;
        sim_int = (balance * t *20)/100;//interest on 20%;
        cout<<"Interest on years:"<<sim_int<<endl;
      cout<<"After one year "<<sim_int<<" rupee interest ."<<endl;

    }

};
class curr_act : public Accounts
{
 int balance;

    public:
        void Depoist()
    {
        int dep;
        cout << "Enter  the amount you want to depoist :";
        cin >> dep;

        balance +=dep;
        cout<<"Depoist money is successfully complete."<<endl;


    }
    void Withdraw()
    {
        int w_draw;
        cout << "Enter Withdrawl money:";
        cin >> w_draw;
        if (w_draw > balance)
        {
            cout << "\nInsufficient Balance:";
        }
        else
            balance -= w_draw;
        cout<<"Withdraw money is successfully complete."<<endl;

    }
        void get_balance()
    {
        cout<<"Enter Account balance:";
        cin>>balance;
            }
    void show_balance()
            {
                cout<<"Current balance is :"<<balance<<endl;
            }
        void penelty()
        {

            if (balance < 200)
            {
                cout<<"After one year 20 rupee decrease on your account."<<endl;
            }
            else
            {
                cout<<"NO penelty on your balance."<<endl;
            }

        }


};
    int main()
    {
        Accounts a1;
        curr_act c1;
        sav_act s1;

        char ch;
        int num;
        while (ch!=7)
        {
        system("CLS");
        cout << "\n\n\t\t\t\t================================\n";
        cout << "\t\t\t\tBANK MANAGEMENT SYSTEM OF ROHAN";
        cout << "\n\t\t\t\t================================\n";

        cout << "\t\t\t\t    ::MAIN MENU::\n";
        cout << "\n\t\t\t\t1. NEW ACCOUNT";
        cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
        cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
        cout << "\n\t\t\t\t4. CHECK BALANCE ";
        cout << "\n\t\t\t\t5. CHECK INTEREST ON SAVING ACCOUNT ";
        cout << "\n\t\t\t\t6. CHECK PANELTY ON CURRENT ACCOUNT ";
        cout << "\n\t\t\t\t7. EXIT ";
        cout<<"\n\n\t\t\t\tSelect Your Option (1-7): ";
        cin >> ch;

        switch (ch)
        {
            case '1':
            a1.getdata();
            if(a1.get_type()==1)
                s1.get_balance();
            else
                c1.get_balance();
            break;
            case '2':
                system("CLS");
            if(a1.get_type()==1)
                s1.Depoist();
            else
                c1.Depoist();
            break;
            break;
            case '3':
                system("CLS");
            if(a1.get_type()==1)
                s1.Withdraw();
            else
                c1.Withdraw();
            break;
            break;
            case '4':
                system("CLS");
            a1.show();
            if(a1.get_type()==1)
                s1.show_balance();
            else
                c1.show_balance();

            break;
            case '5':
                system("CLS");
            s1.Interest();
            break;
            case '6':
                system("CLS");
            c1.penelty();
            break;
            case '7':
            exit(1);
           default:
            cout << "\a";
        }
        cout<<"\n\n\nPress any key to go main menu...."<<endl;
        cin.ignore();
        cin.get();

        }



        return 0;
    }
