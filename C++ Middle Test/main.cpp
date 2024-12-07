#include "Bank.h"
#include <Windows.h> //sleep
#define Exit 6

std::string getPasswordInput(const std::string&); //��й�ȣ �Է� �� *�� ġȯ

int main() {
    Bank bank;
    int choice, accountnumber, amount;
    std::string accountU_name, accountpw;
    char temp;

    do {
        std::cout << "1. ���� ����\n2. �Ա�\n3. ���\n4. �ܾ� ��ȸ\n5. ���� ã��\n6. ����\n���� : ";
        std::cin >> choice;

        //������ ���� ���� ó��
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            choice = Exit + 1;
        }

        //������
        switch (choice) {
        case 1:
            //���� ����
            system("cls");
            bank.createAccount();
            std::cout << "�ƹ� Ű�� ���� �Ѿ�ϴ�.";
            temp = _getch();
            break;
        case 2:
            //�Ա�
            system("cls");
            std::cout << "���� ��ȣ�� �Է��ϼ���. : ";
            std::cin >> accountnumber;
            
            //���� ��ȣ Ȯ�� -> ��й�ȣ Ȯ�� �� ���� ó��
            {
                Account* account = bank.manageAccount(accountnumber);
                if (account) {
                    std::cout << "��й�ȣ�� �Է��ϼ���. : ";
                    std::string accountpw = getPasswordInput("");
                    if (accountpw == account->getAccountPW()) {
                        while(1){
                            std::cout << "�Ա��� �ݾ��� �Է��ϼ���. : ";
                            std::cin >> amount;
                            if (std::cin.fail()) { // �ݾ� ���� ���� ó��
                                std::cin.clear();
                                std::cin.ignore(INT_MAX, '\n');
                                std::cout << "���ڸ� �Է��ϼ���." << std::endl;
                                continue;
                            }
                            else if (amount < 0) { // �ݾ� ���� ���� ó�� (������ ��� 0������ ó��)
                                amount = 0;
                            }
                            account->deposit(amount); // �Ա�
                            account->checkBalance();
                            break;
                        }

                    }
                    else {
                        std::cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << std::endl;
                    }
                }
            }
            std::cout << "�ƹ� Ű�� ���� �Ѿ�ϴ�.";
            temp = _getch();
            break;
        case 3:
            //���
            system("cls");
            std::cout << "���� ��ȣ�� �Է��ϼ���. : ";
            std::cin >> accountnumber;

            //���� ��ȣ Ȯ�� -> ��й�ȣ Ȯ�� �� ���� ó��
            {
                Account* account = bank.manageAccount(accountnumber);
                if (account) {
                    std::cout << "��й�ȣ�� �Է��ϼ���. : ";
                    std::string accountpw = getPasswordInput("");
                    if (accountpw == account->getAccountPW()) {
                        while (1) {
                            std::cout << "����� �ݾ��� �Է��ϼ���. : ";
                            std::cin >> amount;
                            if (std::cin.fail()) { // �ݾ� ���� ���� ó��
                                std::cin.clear();
                                std::cin.ignore(INT_MAX, '\n');
                                std::cout << "���ڸ� �Է��ϼ���" << std::endl;
                                continue;  
                            }
                            else if (amount < 0) { // �ݾ� ���� ���� ó�� (������ ��� 0������ ó��)
                                amount = 0;
                            }
                            account->withdraw(amount); // ���
                            account->checkBalance();
                            break;
                        }
                    }
                    
                }
            }
            std::cout << "�ƹ� Ű�� ���� �Ѿ�ϴ�.";
            temp = _getch();
            break;
        case 4:
            //�ܾ� ��ȸ
            system("cls");
            std::cout << "���� ��ȣ�� �Է��ϼ���. : ";
            std::cin >> accountnumber;

            //���� ��ȣ Ȯ�� -> ��й�ȣ Ȯ�� �� ���� ó��
            {
                Account* account = bank.manageAccount(accountnumber);
                if (account) {
                    std::cout << "��й�ȣ�� �Է��ϼ���. : ";
                    std::string accountpw = getPasswordInput("");
                    if (accountpw == account->getAccountPW()) {
                        account->checkBalance(); // �ܾ� ��ȸ
                    }
                    else {
                        std::cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << std::endl;
                    }
                }
            }
            std::cout << "�ƹ� Ű�� ���� �Ѿ�ϴ�.";
            temp = _getch();
            break;
        case 5:
            //���� ã��
            system("cls");
            std::cout << "����� �̸��� �Է��ϼ���. : ";
            std::cin >> accountU_name;

            //����� �̸� Ȯ�� -> ��й�ȣ Ȯ�� �� ���� ó��
            {
                Account* account = bank.manageAccountToName(accountU_name);
                if (account) {
                    std::cout << "��й�ȣ�� �Է��ϼ���. : ";
                    std::string accountpw = getPasswordInput("");
                    if (accountpw == account->getAccountPW()) {
                        int num = account->getAccountNumber(); // ���� ��ȣ �ҷ�����
                        std::cout << "���� ��ȣ�� '" << num << "' �Դϴ�.";
                    }
                    else {
                        std::cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << std::endl;
                    }
                }
            }
            std::cout << "�ƹ� Ű�� ���� �Ѿ�ϴ�.";
            temp = _getch();
            break;
        case Exit:
            system("cls");
            std::cout << "������..." << std::endl;
            Sleep(1000);
            break;
        default: // ���ڳ� ������ �� ���� ��� Ȯ��
            system("cls");
            std::cout << "���� �������Դϴ�." << std::endl;
            std::cout << "�ƹ� Ű�� ���� �Ѿ�ϴ�.";
            temp = _getch();
        }

        system("cls");
    } while (choice != Exit);


    return 0;
}

std::string getPasswordInput(const std::string& prompt) {
    std::string password;
    char ch;

    std::cout << prompt;

    while ((ch = _getch()) != '\r') { 
        if (ch == '\b') {
            if (!password.empty()) {
                std::cout << "\b \b";
                password.pop_back(); 
            }
        }
        else {
            std::cout << '*';
            password += ch;
        }
    }

    std::cout << std::endl;
    return password;
}
