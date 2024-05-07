// 실습1 회원 명부 작성하기

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    // 파일명 입력 받기
    string filename;
    cout << "파일명을 입력하세요: ";
    getline(cin, filename);

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "파일 열기 실패" << endl;
        return 1;
    }

    int num;
    cout << "몇 명의 회원을 저장하시겠습니까? : ";
    cin >> num;
    cin.ignore(); // cin과 getline 같이쓰면 ignore 써야함(?)

    cout << num << "명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << endl;

    vector<string>lines;
    string name;
    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << "번째 회원 : ";
        getline(cin, name);

        lines.push_back(name);
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
    cout << "\n-----------------------회원명부-----------------------" << endl;
    string line;
    while (getline(member, line))
    {
        cout << line << endl;
    }
 
    member.close();
    return 0;
}