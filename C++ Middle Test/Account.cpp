#include "Account.h"


void Account::deposit(int amount) {
    balance += amount;
    std::cout << amount << "�� �ԱݵǾ����ϴ�.\n";
}

void Account::withdraw(int amount) {
    if (amount > balance) {
        std::cout << "�ܾ� ����" << std::endl;
    }
    else {
        balance -= amount;
        std::cout << amount << "�� ��ݵǾ����ϴ�.\n";
    }
}

void Account::checkBalance() {
    std::cout << "�ܾ� : " << balance << "��" << std::endl;
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