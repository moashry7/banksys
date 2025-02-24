#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>

using namespace std;

class Person {
protected:
    string name;
    string password;
    int id;

public:
    // Default constructor
    Person() : name("Unknown"), id(0000), password("password123") {}

    // Parameterized constructor
    Person(string name, int id, string password) {
        setName(name);
        setId(id);
        setPassword(password);
    }
    // Function name check
    bool nameCheck(const string& str) {
        for (char c : str) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }

    // Setter Name

    void setName(string name) {

        while (true) {

            if (name.length() >= 5 && name.length() <= 20 && nameCheck(name)) {
                this-> name= name;
                return;
            }
            cout << "Enter a name with only alphabetic characters And It must be 5 - 20 characters  .Try Again: ";
            cin >> name;
        }

    }

    // Setter and validation for ID (Only numbers)

    void setId(int id) {
        if (id <= 0) {
            cout << "Invalid ID! It must be a number. Try again: ";
            int count = 0;
            while (count < 3) {
                cin >> id;
                if (id > 0) {
                    this->id = id;
                    return;
                }
                count++;
                if (count == 3) {
                    cout << "Too many invalid attempts! Exiting..." << endl;
                    exit(1);
                }
                cout << "Invalid ID! It must be a number > 0. Try again: ";
            }
        }
       this-> id = id;
    }

    // Setter and validation for Password (At least 8 characters)

    void setPassword(string password) {
        if (password.length() < 8) {
            cout << "Invalid password! It must be at least 8 characters long. Try again: ";
            int count = 0;
            while (count < 3) {
                cin >> password;
                if (password.length() > 8) {
                    this->password = password;
                    return;
                }
                count++;
                if (count == 3) {
                    cout << "Too many invalid attempts! Exiting..." << endl;
                    exit(1);
                }
                cout << "Invalid password! It must be at least 8 characters long. Try again: ";

            }
        }

       this-> password = password;
    }

    // Getters
    string getName() const { return name; }
    int getId() const { return id; }
    string getPassword() const { return password; }

    // Pure virtual function
    virtual void printInfo() const = 0;

    // Virtual destructor
    virtual ~Person() {}
};

// Derived class to implement printInfo()
class Client : public Person {
private:
    double balance;
public:
    // Default constructor
    Client() : Person() {
        balance = 1500;
    }

    // Parameterized constructor
    Client(string name, int id, string password, double balance) : Person(name, id, password)
    {
        setBalance(balance);
    }

    //setter
    void setBalance(double balance) {
        //if (isValidBalance(balance))this->balance = balance;
        if (balance < 1500) {
            cout << "Invalid Balance!\n Minimum Balance Must Be 1500 .Try Again ";
            int count = 0;
            while (count < 3) {
                cin >> balance;
                if (balance > 1500) {
                    this->balance = balance;
                    return;
                }
                count++;
                if (count == 3) {
                    cout << "Too many invalid attempts! Exiting..." << endl;
                    exit(1);
                }
                else cout << "Minimum balance must be 1500.\n";


            }
        }
        this->balance = balance;
    }
    //getter
    double getBalance() const { return balance; }
    //meth
    void deposit(double amount) {
        if (amount < 0) {
            {
                cout << "Invalid deposit amount!\n Deposit Must Be Positive Number .Try Again ";
                int count = 0;
                while (count < 3) {
                    cin >> amount;
                    if (amount > 0) {
                        balance += amount;
                        cout << "Deposit successful!\n New balance: " << balance << "\n";
                        return;
                    }
                    count++;
                    if (count == 3) {
                        cout << "Too many invalid attempts! Exiting..." << endl;
                        exit(1);
                    }
                    else cout << " Deposit Must Be Positive Number .Try Again.\n";


                }
            }
        }
            balance += amount;
            cout << "Deposit successful!\n New balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount < 0 || balance - amount <= 1500) {
            {
                cout << "Insufficient balancet!\n The Amount Must Be < Balance Limit  .Try Again ";
                int count = 0;
                while (count < 3) {
                    cin >> amount;
                    if (amount > 0 && (balance - amount) >= 1500) {
                        balance -= amount;
                        cout << "Withdraw successful!\n New balance: " << balance << "\n";
                        return;
                    }
                    count++;
                    if (count == 3) {
                        cout << "Too many invalid attempts! Exiting..." << endl;
                        exit(1);
                    }
                    else cout << " The Amount Must Be < Balance Limit  .Try Again.\n";


                }
            }
        }
        balance -= amount;
        cout << "Withdraw successful!\n New balance: " << balance << "\n";
    }

    void transferTo(double amount, Client& c) {

               withdraw(amount);
            c.deposit( amount);
            cout << "Transfer successful!\n New balance: " << balance << "\n";
      //  else cout << "Transfer failed!\n Insufficient balance!.\n";
    }

    void checkBalance() {
        cout << "Current balance: " << balance << "\n";
    }
        // Override printInfo function
        void printInfo() const override {
            cout << "Client Info:\n";
            cout << "Name: " << name << "\nID: " << id << "n\Password" << password << "\nBalance" << balance << endl;
        }
    };

    // Derived class Employee
    class Employee : public Person {
    protected:

        double salary;

    public:
        // Default constructor
        Employee() : Person(), salary(5000) {}

        // Parameterized constructor
        Employee(string name, int id, string password, double salary)
            : Person(name, id, password), salary(salary) {
            setSalary(salary);
        }
        void setSalary(double salary) {
            if (salary < 5000) {
                cout << "Invalid salary!\n Minimum salary Must Be 5000 .Try Again ";
                int count = 0;
                while (count < 3) {
                    cin >> salary;
                    if (salary > 1500) {
                        this->salary = salary;
                        return;
                    }
                    count++;
                    if (count == 3) {
                        cout << "Too many invalid attempts! Exiting..." << endl;
                        exit(1);
                    }
                    else cout << "Minimum salary must be 5000.\n";


                }
            }
            this->salary = salary;
        }

        // Getters
        double getSalary() const { return salary; }

    // Override printInfo function
        void printInfo() const override {
            cout << "Employee Info:\n";
            cout << "Name: " << name << "\nID: " << id << "n\Password" << password << "\nSalary: " << salary << endl;
        }
    };

    // Derived class Admin

    class Admin : public Employee
    {
    public:
        // Default constructor
        Admin() : Employee() {}
        // Parameterized constructor
        Admin(string name, int id, string password, double salary) :Employee(name, id, password, salary) {}


        // Override printInfo function
        void printInfo() const override {
            cout << "Admin Info:\n";
            cout << "Name: " << name << "\nID: " << id << "n\Password" << password << "\nSalary: " << salary << endl;
        }



    };

    void START()
    {
        cout << "*       *  *****  *       *****   ****   *       *  ***** " << endl;
        cout << "*   *   *  *      *      *       *    *  * *   * *  *     " << endl;
        cout << "*  * *  *  ****   *     *        *    *  *  * *  *  ****  " << endl;
        cout << "* *   * *  *      *      *       *    *  *   *   *  *     " << endl;
        cout << "*       *  *****  *****   *****   ****   *       *  ***** " << endl;
        cout << "                     TO ALAHLY BANK                       " << endl;
        Sleep(5000);
        system("cls");

    }

    void registerClient() {
        Client c1, c2("mohamed", 246, "mohamed123", 5000);
        string clientName, clientPassword;
        int clientId;
        double amount;
        cout << "Enter Client Name: ";
        cin >> clientName;
        c1.setName(clientName);

        cout << "Enter Client ID: ";
        cin >> clientId;
        c1.setId(clientId);

        cout << "Enter Client Password: ";
        cin >> clientPassword;
        c1.setPassword(clientPassword);

        cout << "Enter Client balanc: ";
        cin >> amount;
        c1.setBalance(amount);


        cout << "Enter Client deposit: ";
        cin >> amount;
        c1.deposit(amount);

        cout << "Enter Client withdraw: ";
        cin >> amount;
        c1.withdraw(amount);

        cout << "Enter Client transfer: ";
        cin >> amount;

        c1.transferTo(amount, c2);
        c1.checkBalance();
        c2.checkBalance();

        cout << "\nDisplaying Client Info:\n";
        c1.printInfo();


    }

    void registerEmployee()
    {
        Employee emp;
        string empName, empPassword;
        int empId;
        double salary;

        cout << "\nEnter Employee Name: ";
        cin >> empName;
        emp.setName(empName);

        cout << "Enter Employee ID: ";
        cin >> empId;
        emp.setId(empId);

        cout << "Enter Employee Password: ";
        cin >> empPassword;
        emp.setPassword(empPassword);

        cout << "Enter Employee Salary: ";
        cin >> salary;
        emp.setSalary(salary);

        cout << "\nDisplaying Employee Info:\n";
        emp.printInfo();

    }

    void registerAdmin() {
        Admin ad;
        string adName, adIdStr, adPassword;
        int adID;
        double adsalary;

        cout << "\nEnter Admin Name: ";
        cin >> adName;
        ad.setName(adName);

        cout << "Enter Admin ID: ";
        cin >> adID;
        ad.setId(adID);

        cout << "Enter Admin Password: ";
        cin >> adPassword;
        ad.setPassword(adPassword);

        cout << "Enter Admin Salary: ";
        cin >> adsalary;
        ad.setSalary(adsalary);

        cout << "\nDisplaying Admin Info:\n";
        ad.printInfo();

    }


    void workerMenu() {
        int choice;
        do {
            cout << "\nSelect login type:\n";
            cout << "1. Login as Employee\n";
            cout << "2. Login as Admin\n";
            cout << "3. Exit\n";
            cout << "Enter Your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                registerEmployee();
                break;
            case 2:
                registerAdmin();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 3);
    }

    int main() {
        START();
        int choice;
        do{
            cout << "\nSelect login type:\n";
            cout << "1. Login as Client\n";
            cout << "2. Login as Employee\n";
            cout << "3. Exit\n";
            cout << "Enter Your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                registerClient();

            case 2:
                workerMenu();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 3);


           return 0;
    }
