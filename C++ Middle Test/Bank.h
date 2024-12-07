#include <random>
#include <conio.h> //_getch
#include "Account.h"

class Bank {
private:
	std::vector<Account> accounts;
public:
    //���� ����
	void createAccount();

    //���� ��ȣ ���� Ȯ��
	Account* manageAccount(int);

    //����� �̸��� ��ġ�� ���� ���� Ȯ��
    Account* manageAccountToName(std::string);
};

void Bank::createAccount() {
    std::string accU_Name, accPw;
    int accNum;

    //���� ��ȣ ���� ���� �� �ߺ� Ȯ�� (�ݺ�)
    while (1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);

        accNum = dis(gen);

        //�ߺ�Ȯ��
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accNum)
                return;
        }
        break;
    }

    //1�� 1���� Ȯ��
    std::cout << "������� �̸��� �Է��ϼ���. : ";
    std::cin >> accU_Name;
    for (auto& account : accounts) {
        if (account.getAccountName() == accU_Name) {
            std::cout << "�� ��� 1���� ���¸� �̿밡���մϴ�." << std::endl;
            return;
        }
    }

    //��й�ȣ ����
    std::cout << "��й�ȣ�� �����ϼ���. : ";
    std::cin >> accPw;

    //���� ����(���� �迭�� �߰�)
    accounts.emplace_back(accNum, accU_Name, accPw);
    std::cout << "���°� ���� �Ǿ����ϴ�." << std::endl;
    std::cout << "���� ��ȣ�� " << accNum << " �Դϴ�." << std::endl;
}

Account* Bank::manageAccount(int accNum) {
    //���� ��ȣ ���� Ȯ��
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accNum) {
            return &account;
        }
    }
    std::cout << "���¸� ã�� �� �����ϴ�." << std::endl;
    return nullptr;
}

Account* Bank::manageAccountToName(std::string accName) {
    //����� �̸��� ���� Ȯ��
    for (auto& account : accounts) {
        if (account.getAccountName() == accName) {
            return &account;
        }
    }
    std::cout << "����� �̸��� ��ġ�� ���¸� ã�� �� �����ϴ�." << std::endl;
    return nullptr;
}