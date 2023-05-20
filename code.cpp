#include <iostream>
#include <vector>

using namespace std;

class Account
{
	//Assign variables to handle customer details
	int ac_no;
	string name;
	unsigned int amt;
	static int count;
	//Declaration of the required function
	public:
	Account();
	deposit();
	withdraw();
	//delete();
};
//Function Definition
int Account::count = 0;
Account::Account()
{
	//Getting the deatils of the customer
	++count;
	ac_no = 1000 + count;
	cout<<"Enter the name :";
	cin>>name;
	amt = 0;
	//getting the minimum amount from customer to start the account
	do
	{
		cout<<"Enter the amount greater than or equal to 500  :";
		cin>>amt;
	}
	while(amt < 500);
	cout<<"bank account created successfully... your account number is "<<ac_no<<endl;
}
Account::deposit()
{
	unsigned int x = 0;
	cout<<"Hello "<<name<<"!"<<endl;
	cout<<"Enter the amount to deposit :";
	cin>>x;
	amt = amt + x;
	cout<<"Deposit successfull... Your New balance is.. "<<amt<<endl;
}
Account::withdraw()
{
	unsigned int x = 0;
	cout<<"Hello "<<name<<"!"<<endl;
	cout<<"Enter the amount to withdraw :";
	do
	{
		cin>>x;
		if(x > amt - 500)
		{
			cout<<"Account doesn't have enough money to withdraw"<<endl;
			return 0;
		}
		if(x % 100 != 0)
			cout<<"Enter valid amount to withdraw"<<endl;
	}
	while(x % 100 != 0);
	
	amt = amt - x;
	cout<<"Rupees "<<x<<" successfully withdrawn.. Your New balance is .. "<<amt<<endl;
	
}
bool checkValidAc(vector<Account>& acc, int x)
{
	int n = acc.size();
	if(n == 0)
	{
		cout<<"\nThere is no account"<<endl;
	}
	if(x < 1000 || x > 10000 || x - 1000 > n)
	{
		cout<<"\nInvalid account number"<<endl;
		return false;
	}
	return true;
}
int main()
{
	int UserInput;
	unsigned int x = 0;
	vector<Account> acc;
	//function declaration
	bool checkValidAc(vector<Account>&, int);
	cout<<"\t\t\t\t"<<"Bank of Money"<<endl;
	start:
	cout<<"******************************************************************************"<<endl;
	cout<<"\n\t\t\t"<<"Welcome to XOX Bank"<<endl;
	cout<<"1. Create Account\n";
	cout<<"2. Deposit Money\n";
	cout<<"3. Withdraw Money\n";
	cout<<"0. Exit\n";
	//Asking the user to enter valid option and get valid input
	cout<<"PLease mention the number for desired function"<<endl;
	do
	{
		cin>>UserInput;
		if(UserInput < 0 || UserInput > 4)
			cout<<"Enter valid input"<<endl;
	}
	while(UserInput < 0 || UserInput > 4);
	
	switch(UserInput)
	{
		case 0:
			goto end;
		
		case 2:
			cout<<"Enter your account number =";
			cin>>x;
			if(checkValidAc(acc, x))
			{
				x = x - 1000 - 1;
				acc[x].deposit();
			}
			break;
			
		case 3:
			cout<<"Enter your account number =";
			cin>>x;
			if(checkValidAc(acc, x))
			{
				x = x - 1000 - 1;
				acc[x].withdraw();
			}
			break;
			
		case 1:
			Account a;
			acc.push_back(a);
			break;
	}
	goto start;
	end:
		cout<<"System shutdown";
		return 0;
}
