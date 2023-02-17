#include <iostream> 
#include "header.h"

using namespace std;

int main()
{
    BankAccount Person1 ("Emrecan", "Acar", 0, "05123456789");
    BankAccount Person2("Furkan", "Iscan", 100, "05001112233");

    cout << "Name: " << Person1.getPersonName() << endl;
    cout << "Surname: " << Person1.getPersonSurname() << endl;
    cout << "Phone: " << Person1.getPersonPhone() << endl;
    cout << "Balance: " << Person1.getPersonBalance() << endl;

    Person2.credit(100);
    Person1.credit(100);

    Person1.withdraw(30);

    Person1.sendMoney(Person2, 70);
    Person1.displayProfile();
    Person2.displayProfile();

    return 0;
}

