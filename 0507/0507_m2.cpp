// 실습2 회원 명부 작성하기, 로그인 기능

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    // 파일명 입력 받기
    string filename;
    cout << "파일명을 입력하세요: ";
    getline(cin, filename);

    ofstream file(filename);

    cout << endl;

    if (!file.is_open()) {
        cout << "파일 열기 실패" << endl;
        return 1;
    }

    int num;
    cout << "몇 명의 회원을 저장하시겠습니까? : ";
    cin >> num;
    cin.ignore(); // cin과 getline 같이쓰면 ignore 써야함(?)

    cout << endl;

    cout << num << "명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << endl << endl;

    vector<string>lines;
    string name, pw;
    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << "번째 회원 ";
        cout << "이름 : ";
        getline(cin, name);
        cout << i + 1 << "번째 회원 ";
        cout << "비밀번호 : ";
        getline(cin, pw);
        lines.push_back(name + " " + pw); // 이름과 비밀번호를 공백으로 구분해서 저장
        cout << endl;
    }

    for (auto& line : lines)
    {
        file << line << endl;
    }

    file.close();

    ifstream member(filename);
    {
        if (!member.is_open())
        {
            cout << "파일 열기 실패" << endl;
            return 1;
        }

    }
    cout << "\n-----------------------회원명부-----------------------" << endl << endl;
    string line;
    while (getline(member, line))
    {
        cout << line << endl << endl;
    }

    member.close();


    string input_name, input_pw;
    bool login_success = false;
    
    while (!login_success)
    {
        cout << endl;

        cout << "이름을 입력하세요: ";
        getline(cin, input_name);
        cout << "비밀번호를 입력하세요: ";
        getline(cin, input_pw);

        cout << endl;

        for (auto& info : lines)
        {
            size_t pos = info.find(' '); // 공백을 기준으로 이름과 비밀번호를 분리
            name = info.substr(0, pos);
            pw = info.substr(pos + 1);
            if (name == input_name && pw == input_pw)
            {
                login_success = true;
                cout << "로그인 성공" << endl;
                break;
            }
        }
        if (!login_success)
        {
            cout << "로그인 실패" << endl;
            cout << "이름 또는 비밀번호가 일치하지 않습니다. 다시 입력해주세요." << endl;
        }

    }
    

    return 0;
}