#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;
    vector<string> transactionHistory;

public:
    // Constructor
    BankAccount(string name, double initialBalance) {
        ownerName = name;
        balance = initialBalance;
        transactionHistory.push_back("Account opened with balance: " + to_string(initialBalance));
    }

    // Deposit money
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount! Deposit must be positive." << endl;
            return;
        }
        balance += amount;
        transactionHistory.push_back("Deposited: " + to_string(amount));
        cout << "Deposit successful! New balance: " << balance << endl;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount! Withdrawal must be positive." << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient funds! Current balance: " << balance << endl;
            return;
        }
        balance -= amount;
        transactionHistory.push_back("Withdrew: " + to_string(amount));
        cout << "Withdrawal successful! New balance: " << balance << endl;
    }

    // Check balance
    void checkBalance() {
        cout << "Current balance: " << balance << endl;
    }

    // Show transaction history
    void showHistory() {
        cout << "\n=== Transaction History ===" << endl;
        for (size_t i = 0; i < transactionHistory.size(); i++) {
            cout << i + 1 << ". " << transactionHistory[i] << endl;
        }
    }

    string getOwnerName() {
        return ownerName;
    }
};

int main() {
    string name;
    double initialBalance;

    cout << "=== Welcome to Bank Account Simulator ===" << endl;
    cout << "Enter account owner name: ";
    cin >> name;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Show Transaction History" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                account.showHistory();
                break;
            case 5:
                cout << "Goodbye, " << account.getOwnerName() << "!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}