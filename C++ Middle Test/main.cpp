#include "Bank.h"
#include <Windows.h> //sleep
#define Exit 6

std::string getPasswordInput(const std::string&); //비밀번호 입력 시 *로 치환

int main() {
    Bank bank;
    int choice, accountnumber, amount;
    std::string accountU_name, accountpw;
    char temp;

    do {
        std::cout << "1. 계좌 생성\n2. 입금\n3. 출금\n4. 잔액 조회\n5. 계좌 찾기\n6. 종료\n선택 : ";
        std::cin >> choice;

        //선택지 문자 예외 처리
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            choice = Exit + 1;
        }

        //선택지
        switch (choice) {
        case 1:
            //계좌 생성
            system("cls");
            bank.createAccount();
            std::cout << "아무 키를 눌러 넘어갑니다.";
            temp = _getch();
            break;
        case 2:
            //입금
            system("cls");
            std::cout << "계좌 번호를 입력하세요. : ";
            std::cin >> accountnumber;
            
            //계좌 번호 확인 -> 비밀번호 확인 및 예외 처리
            {
                Account* account = bank.manageAccount(accountnumber);
                if (account) {
                    std::cout << "비밀번호를 입력하세요. : ";
                    std::string accountpw = getPasswordInput("");
                    if (accountpw == account->getAccountPW()) {
                        while(1){
                            std::cout << "입금할 금액을 입력하세요. : ";
                            std::cin >> amount;
                            if (std::cin.fail()) { // 금액 문자 예외 처리
                                std::cin.clear();
                                std::cin.ignore(INT_MAX, '\n');
                                std::cout << "숫자를 입력하세요." << std::endl;
                                continue;
                            }
                            else if (amount < 0) { // 금액 음수 예외 처리 (음수의 경우 0원으로 처리)
                                amount = 0;
                            }
                            account->deposit(amount); // 입금
                            account->checkBalance();
                            break;
                        }

                    }
                    else {
                        std::cout << "비밀번호가 틀렸습니다." << std::endl;
                    }
                }
            }
            std::cout << "아무 키를 눌러 넘어갑니다.";
            temp = _getch();
            break;
        case 3:
            //출금
            system("cls");
            std::cout << "계좌 번호를 입력하세요. : ";
            std::cin >> accountnumber;

            //계좌 번호 확인 -> 비밀번호 확인 및 예외 처리
            {
                Account* account = bank.manageAccount(accountnumber);
                if (account) {
                    std::cout << "비밀번호를 입력하세요. : ";
                    std::string accountpw = getPasswordInput("");
                    if (accountpw == account->getAccountPW()) {
                        while (1) {
                            std::cout << "출금할 금액을 입력하세요. : ";
                            std::cin >> amount;
                            if (std::cin.fail()) { // 금액 문자 예외 처리
                                std::cin.clear();
                                std::cin.ignore(INT_MAX, '\n');
                                std::cout << "숫자를 입력하세요" << std::endl;
                                continue;  
                            }
                            else if (amount < 0) { // 금액 음수 예외 처리 (음수의 경우 0원으로 처리)
                                amount = 0;
                            }
                            account->withdraw(amount); // 출금
                            account->checkBalance();
                            break;
                        }
                    }
                    
                }
            }
            std::cout << "아무 키를 눌러 넘어갑니다.";
            temp = _getch();
            break;
        case 4:
            //잔액 조회
            system("cls");
            std::cout << "계좌 번호를 입력하세요. : ";
            std::cin >> accountnumber;

            //계좌 번호 확인 -> 비밀번호 확인 및 예외 처리
            {
                Account* account = bank.manageAccount(accountnumber);
                if (account) {
                    std::cout << "비밀번호를 입력하세요. : ";
                    std::string accountpw = getPasswordInput("");
                    if (accountpw == account->getAccountPW()) {
                        account->checkBalance(); // 잔액 조회
                    }
                    else {
                        std::cout << "비밀번호가 틀렸습니다." << std::endl;
                    }
                }
            }
            std::cout << "아무 키를 눌러 넘어갑니다.";
            temp = _getch();
            break;
        case 5:
            //계좌 찾기
            system("cls");
            std::cout << "사용자 이름을 입력하세요. : ";
            std::cin >> accountU_name;

            //사용자 이름 확인 -> 비밀번호 확인 및 예외 처리
            {
                Account* account = bank.manageAccountToName(accountU_name);
                if (account) {
                    std::cout << "비밀번호를 입력하세요. : ";
                    std::string accountpw = getPasswordInput("");
                    if (accountpw == account->getAccountPW()) {
                        int num = account->getAccountNumber(); // 계좌 번호 불러오기
                        std::cout << "계좌 번호는 '" << num << "' 입니다."<<std::endl;
                    }
                    else {
                        std::cout << "비밀번호가 틀렸습니다." << std::endl;
                    }
                }
            }
            std::cout << "아무 키를 눌러 넘어갑니다.";
            temp = _getch();
            break;
        case Exit:
            system("cls");
            std::cout << "종료중..." << std::endl;
            Sleep(1000);
            break;
        default: // 문자나 선택지 외 숫자 출력 확인
            system("cls");
            std::cout << "없는 선택지입니다." << std::endl;
            std::cout << "아무 키를 눌러 넘어갑니다.";
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
