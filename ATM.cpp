#include<conio.h>
#include <iostream>
#include <string>

using namespace std;


//  user1.setData(012345,"Raunak" , 1111, 52000.85, "9998877766");  // setting default data



class ATM    //class ATM
{
private :                                           // private member variable

    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:

    // SetData to set the data into the private member variable
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a,string mobile_No_a)
    {
        account_no = account_No_a;       // assigning the formal argument to the private member var's
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_No_a;
    }

        // getAccountNo function is returning the user's account no.
    long int getAccountNo ()
    {
        return account_no;
    }

    //getName is returning the user's Name
    string getName()
    {
        return name;
    }

    //getPIN is returning PIN
    int getPin()
    {
        return PIN;
    }
        // getBalance returns the Balance in A/c
    double getBalance()
    {
        return balance;
    }

    string getMobileNo()
    {
        return mobile_no;
    }

        // setMobile func is updating the user mobile no
    void setMobile(string mob_prev, string mob_new)
    {
        if(mob_prev == mobile_no)  // for verifying the old M-Number
        {
            mobile_no = mob_new;    //and update with new, if old matches
            cout<<" Successfully Updated Mobile No. "<<mobile_no;
            _getch();               // getch(); to hold the screen until press any key
        }

        else                             // if old no. doesn't get verified doesnt update the no.
        {
            cout<< "Incorrect !!! Old Mobile No. ";
            _getch();
        }
    }
        // cashWithdraw is used to withdraw money from ATM
    void cashWithdraw(int amount_a)
    {
        if (amount_a> 0 && amount_a <balance)  //check amount validity
        {
            balance -= amount_a;    // balance = balance - amount_a
            cout<<" Please Collect your Cash ";
            cout<<" Available Balance :" <<balance;
            _getch();
        }
    }
};

int main ()
{
    int choice = 0, enterPIN;            // enterPin and enterA/c --> user authentication
    long int enterAccountNo;
    system("cls");                  //CLS is used to clear the screen after output is generated
    ATM user1;          // object of classATM
    user1.setData(2511,"Raunak" , 2511, 52000.85, "9998877766");  // setting default data

    do
    {
        system("cls");
        cout<< endl << " *****Welcome to ATM *****"<< endl;
        cout<< endl << " Enter Account no. " ;
        cin>>enterAccountNo;

        cout<<endl<< "Enter PIN ";
        cin>> enterPIN;

            // verifying whether entered values matches with user details
        if( (enterAccountNo == user1.getAccountNo()) &&(enterPIN == user1.getPin()) )
        {
            do
            {
                int amount=0;
                string oldMobileNo ,newMobileNo;

                system("cls");

                // User InterFace
                cout << endl << "*******WELCOME to the ATM **********"<< endl;
                cout << endl << "SELECT from Below Options" ;
                cout << endl << "1. Check Balance " ;
                cout << endl << "2. Cash Withdraw"  ;
                cout << endl << "3. Show user Details"  ;
                cout << endl << "4. Update Mobile No."  ;
                cout << endl << "5. Exit" << endl;
                cin>> choice;             // taking user choice

                switch(choice)
                {
                    case 1:                              // user presses 1
                        cout<< endl<<" Your Balance is : " << user1.getBalance();

                        _getch();
                        break;

                    case 2:                             // user presses 2
                        cout<< endl<< "Enter the Amount " ;
                        cin>>amount;
                        user1.cashWithdraw(amount);     // calling withdraw func to deduct and valid the amount

                        break;
                    case 3:
                        cout<< endl << "****User Details ***" ;
                        cout<< endl << "-> Account No. "<< user1.getAccountNo();
                        cout<< endl << "-> Name "<< user1.getName();
                        cout<< endl << "-> Balance "<< user1.getBalance();
                        cout<< endl << "-> Mobile No.  "<< user1.getMobileNo();

                        _getch();
                        break;
                    case 4:
                        cout<<endl<< "Enter old Mobile No. ";
                        cin>> oldMobileNo;
                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;

                    case 5:
                        exit(0);

                    default:
                        cout<< endl << " Enter Valid Data !!";
                }

            }while(1);              // menu  ( condition will always TRUE and loop is Capable of running infinite time )
        }

    }
    while(1);


}

