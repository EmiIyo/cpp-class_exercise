#include <iostream>

using namespace std;

class BankAccount {

public:
	BankAccount(string name, string surname, float balance = 0, string phone_number = "");
	BankAccount(const BankAccount &oth);
	~BankAccount();
	bool ControlNameSurname(string nameOrSurname);
	bool ControlPhoneNumber(string phoneNumber);
	void displayProfile();
	void credit(float);
	void withdraw(float);
	void sendMoney(BankAccount &othBankAccount, float amount);
	void setPersonName(string name);
	void setPersonSurname(string surname);
	void setPersonPhone(string phone);
	void setPersonBalance(float balance = 0);
	float getPersonBalance()const;
	string getPersonName() const;
	string getPersonSurname() const;
	string getPersonPhone() const;

private:
	string personName, personSurname, personPhone;
	float accountBalance;
};

BankAccount::BankAccount(string name, string surname, float balance, string phone_number) 
{
	if (!ControlNameSurname(name))
	{
		cout << "Error: invalid name." << endl;
		cout << "--------------" << endl;
	}
	if (!ControlNameSurname(surname))
	{
		cout << "Error: invalid surname." << endl;
		cout << "--------------" << endl;
	}
	if (!ControlPhoneNumber(phone_number))
	{
		cout << "Error: invalid number." << endl;
		cout << "--------------" << endl;
	}

	cout << "Ilk degerler atandi." << endl;
	cout << "--------------" << endl;
	personName = name;
	personSurname = surname;
	personPhone = phone_number;
	accountBalance = balance;
};

BankAccount::~BankAccount() 
{
	cout << "Destructor." << endl;
};

BankAccount::BankAccount(const BankAccount& oth)
{
	personName = oth.personName;
	personSurname = oth.personSurname;
	personPhone = oth.personPhone;
	accountBalance = oth.accountBalance;
}

bool BankAccount::ControlNameSurname(string nameOrSurname)
{
	int i = 0;

	while (nameOrSurname[i])
	{
		if (nameOrSurname[i] != ' ')
			if (!isalpha(nameOrSurname[i]))
				return 0;
		i++;
	}
	return 1;
}

bool BankAccount::ControlPhoneNumber(string number)
{
	int i = 0;
	if (number == "")
		return 1;

	while (number[i])
	{
		if (!isdigit(number[i]))
			return 0;
		i++;
	}
	if (i == 11)
		return 1;
	else
		return 0;
}

void BankAccount::displayProfile()
{
	cout << "Name: " << personName << endl;
	cout << "Surname: " << personSurname << endl;
	cout << "Phone: " << personPhone << endl;
	cout << "Balance: " << accountBalance << " TL" <<endl;
	cout << "--------------" << endl;
}

void BankAccount::credit(float amount)
{
	if (amount < 0)
	{
		cout << "ERROR: invalid amount." << endl;
		cout << "--------------" << endl;
		return;
	}
	accountBalance += amount;
	cout << "Balance is updated. New balance: "<< accountBalance << " TL" <<endl;
	cout << "--------------" << endl;
}

void BankAccount::withdraw(float amount)
{
	if (amount < 0 || amount > accountBalance)
	{
		cout << "ERROR: invalid amount." << endl;
		cout << "--------------" << endl;
		return;
	}
	accountBalance -= amount;
	cout << "Balance is updated. New balance: " << accountBalance << " TL" << endl;
	cout << "--------------" << endl;
}

void BankAccount::sendMoney(BankAccount& oth, float amount)
{
	if (oth.accountBalance < amount)
	{
		cout << "ERROR: invalid amount." << endl;
		cout << "--------------" << endl;
		return;
	}
	oth.accountBalance -= amount;
	accountBalance += amount;
}

void BankAccount::setPersonName(string name)
{
	if (ControlNameSurname(name))
	{
		personName = name;
		cout << "Name is changed." << endl;
		cout << "--------------" << endl;
	}
}

void BankAccount::setPersonSurname(string surname)
{
	if (ControlNameSurname(surname))
	{
		personSurname = surname;
		cout << "Surname is changed." << endl;
		cout << "--------------" << endl;
	}
}

void BankAccount::setPersonPhone(string phone)
{
	if (ControlPhoneNumber(phone))
	{
		personPhone = phone;
		cout << "Phone number is changed." << endl;
		cout << "--------------" << endl;
	}
}

void BankAccount::setPersonBalance(float amount)
{
	if (amount >= 0)
	{
		accountBalance = amount;
		cout << "Balance is changed." << endl;
		cout << "--------------" << endl;
	}
}

float BankAccount::getPersonBalance()const
{
	return accountBalance;
}

string BankAccount::getPersonName()const
{
	return personName;
}

string BankAccount::getPersonSurname()const
{
	return personSurname;
}

string BankAccount::getPersonPhone()const
{
	return personPhone;
}