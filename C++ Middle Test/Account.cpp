#include "Account.h"


void Account::deposit(int amount) {
    balance += amount;
    std::cout << amount << "원 입금되었습니다.\n";
}

void Account::withdraw(int amount) {
    if (amount > balance) {
        std::cout << "잔액 부족" << std::endl;
    }
    else {
        balance -= amount;
        std::cout << amount << "원 출금되었습니다.\n";
    }
}

void Account::checkBalance() {
    std::cout << "잔액 : " << balance << "원" << std::endl;
}

int Account::getAccountNumber() {
    return accountNumber;
}

std::string Account::getAccountName() {
    return ownerName;
}

std::string Account::getAccountPW() {
    return accountPW;
}