#include <iostream>

class Account {
private:
	int accountNumber;
	int balance;
	std::string accountPW;
	std::string ownerName;

public:
    //생성자 (계좌 번호, 사용자 이름, 비밀번호, 잔액(초기 0원))
    Account(const int& accNum, const std::string& accU_Name, const std::string& accPw)
        :accountNumber(accNum), ownerName(accU_Name), accountPW(accPw), balance(0) {}

    //입금
    void deposit(int);

    //출금
    void withdraw(int);

    //잔액 조회
    void checkBalance();

    //계좌 번호 불러오기
    int getAccountNumber();
    
    //사용자 이름 불러오기
    std::string getAccountName();

    //비밀번호 불러오기
    std::string getAccountPW();
};