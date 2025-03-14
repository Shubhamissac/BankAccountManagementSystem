#include<iostream>
#include<unistd.h>
#include<fstream>  // for file handling
#include<sstream>


using namespace std;

class Account{
    private:
    string AccountNo, Password;
    int Balance;
    public:
    Account():AccountNo(""),Password(""),Balance(0){}

     void setAccountNo(string id){
        AccountNo = id;
    }

     void setPassword(string pw){
        Password = pw;
    }

    void setBalance(int balance){
        Balance = balance;
    }

    string getAccountNo(){
        return AccountNo;
    }

    string getPassword(){
        return Password;
    }

    int getBalance(){
        return Balance;
    }


};

 void openAccount(Account user){
    system("cls");
    string id, pw;
    cout<<"\tEnter Account No: ";
    cin>>id;
    user.setAccountNo(id);

    cout<<"\tEnter Password: ";
    cin>>pw;
    user.setPassword(pw);

    user.setBalance(0);
    
    ofstream outfile("/workspaces/BankAccountManagementSystem/Account.txt", ios::app); // for rewritig values
   if(!outfile){
    cout<<"\tError file can't open!"<<endl;
   }
   else{
    outfile<<"\t"<<user.getAccountNo()<<" : "<<user.getPassword()<<" : "<<user.getBalance()<<endl;

    cout<<"\tAccount Created Successfully"<<endl;
   }
sleep(5000);
   outfile.close();
    

}

void addCash(){
system("cls");
string id;
cout<<"\tEnter Account No: ";
cin>>id;

ifstream infile("/workspaces/BankAccountManagementSystem/Account.txt");
ofstream outfile("/workspaces/BankAccountManagementSystem/AccountTemp.txt");
if(!infile || !outfile){
    cout<<"\tError: File Can't Open"<<endl;
}

string line;
bool found = false;

while(getline(infile, line)){
stringstream ss;
ss<<line;
string userId, userPW;
int userBalance;
char delimiter;

ss>>userId>>delimiter>>userPW>>delimiter>>userBalance;
if(id == userId){
    found = "true";
    int cash;
    cout<<"\tEnter Cash: ";
    cin>>cash;

    int newBalance = userBalance + cash;
    userBalance = newBalance;
    outfile<<"\t"<<userId<<" : "<<userPW<<" : "<<userBalance<<endl;
    cout<<"\tNew Balance is: "<<userBalance<<endl;
}
else{
    outfile<<line<<endl;
}
}
if(!found){
    cout<<"\tEnter Valid Account No.!"<<endl;
}
outfile.close();
infile.close();
remove("/workspaces/BankAccountManagementSystem/Account.txt");
rename("/workspaces/BankAccountManagementSystem/AccountTemp.txt", "/workspaces/BankAccountManagementSystem/Account.txt");
sleep(5000);
}

int main(){
    Account user;

    bool exit = false;
    while(!exit){
        system("cls");    // system clear screen
      int val;
        cout<<"\t Welcome To Bank Account Management System"<<endl;
        cout<<"\t*******************************************"<<endl;
        cout<<"\t1.Open New Account."<<endl;
        cout<<"\t2.Add Cash."<<endl;
        cout<<"\t3.Witdraw Cash."<<endl;
        cout<<"\t4.Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>val;

        if(val==1){
                openAccount(user);
        }

        else if(val == 2){
            addCash();
        }
        sleep(3000);


    }
   return 0; 
}