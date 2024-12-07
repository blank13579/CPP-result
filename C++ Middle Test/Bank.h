#include <random>
#include <conio.h> //_getch
#include "Account.h"

class Bank {
private:
	std::vector<Account> accounts;
public:
    //계좌 생성
	void createAccount();

    //계좌 번호 유무 확인
	Account* manageAccount(int);

    //사용자 이름과 일치한 계좌 유무 확인
    Account* manageAccountToName(std::string);
};

void Bank::createAccount() {
    std::string accU_Name, accPw;
    int accNum;

    //계좌 번호 랜덤 생성 후 중복 확인 (반복)
    while (1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);

        accNum = dis(gen);

        //중복확인
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accNum)
                return;
        }
        break;
    }

    //1인 1계좌 확인
    std::cout << "사용자의 이름을 입력하세요. : ";
    std::cin >> accU_Name;
    for (auto& account : accounts) {
        if (account.getAccountName() == accU_Name) {
            std::cout << "한 명당 1개의 계좌만 이용가능합니다." << std::endl;
            return;
        }
    }

    //비밀번호 생성
    std::cout << "비밀번호를 설정하세요. : ";
    std::cin >> accPw;

    //계좌 개설(계좌 배열에 추가)
    accounts.emplace_back(accNum, accU_Name, accPw);
    std::cout << "계좌가 개설 되었습니다." << std::endl;
    std::cout << "계좌 번호는 " << accNum << " 입니다." << std::endl;
}

Account* Bank::manageAccount(int accNum) {
    //계좌 번호 유무 확인
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accNum) {
            return &account;
        }
    }
    std::cout << "계좌를 찾을 수 없습니다." << std::endl;
    return nullptr;
}

Account* Bank::manageAccountToName(std::string accName) {
    //사용자 이름의 계좌 확인
    for (auto& account : accounts) {
        if (account.getAccountName() == accName) {
            return &account;
        }
    }
    std::cout << "사용자 이름과 일치한 계좌를 찾을 수 없습니다." << std::endl;
    return nullptr;
}