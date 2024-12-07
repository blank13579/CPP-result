#include <iostream>

class Account {
private:
	int accountNumber;
	int balance;
	std::string accountPW;
	std::string ownerName;

public:
    //������ (���� ��ȣ, ����� �̸�, ��й�ȣ, �ܾ�(�ʱ� 0��))
    Account(const int& accNum, const std::string& accU_Name, const std::string& accPw)
        :accountNumber(accNum), ownerName(accU_Name), accountPW(accPw), balance(0) {}

    //�Ա�
    void deposit(int);

    //���
    void withdraw(int);

    //�ܾ� ��ȸ
    void checkBalance();

    //���� ��ȣ �ҷ�����
    int getAccountNumber();
    
    //����� �̸� �ҷ�����
    std::string getAccountName();

    //��й�ȣ �ҷ�����
    std::string getAccountPW();
};