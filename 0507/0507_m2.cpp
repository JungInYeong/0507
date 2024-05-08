// �ǽ�2 ȸ�� ��� �ۼ��ϱ�, �α��� ���

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    // ���ϸ� �Է� �ޱ�
    string filename;
    cout << "���ϸ��� �Է��ϼ���: ";
    getline(cin, filename);

    ofstream file(filename);

    cout << endl;

    if (!file.is_open()) {
        cout << "���� ���� ����" << endl;
        return 1;
    }

    int num;
    cout << "�� ���� ȸ���� �����Ͻðڽ��ϱ�? : ";
    cin >> num;
    cin.ignore(); // cin�� getline ���̾��� ignore �����(?)

    cout << endl;

    cout << num << "���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���." << endl << endl;

    vector<string>lines;
    string name, pw;
    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << "��° ȸ�� ";
        cout << "�̸� : ";
        getline(cin, name);
        cout << i + 1 << "��° ȸ�� ";
        cout << "��й�ȣ : ";
        getline(cin, pw);
        lines.push_back(name + " " + pw); // �̸��� ��й�ȣ�� �������� �����ؼ� ����
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
            cout << "���� ���� ����" << endl;
            return 1;
        }

    }
    cout << "\n-----------------------ȸ�����-----------------------" << endl << endl;
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

        cout << "�̸��� �Է��ϼ���: ";
        getline(cin, input_name);
        cout << "��й�ȣ�� �Է��ϼ���: ";
        getline(cin, input_pw);

        cout << endl;

        for (auto& info : lines)
        {
            size_t pos = info.find(' '); // ������ �������� �̸��� ��й�ȣ�� �и�
            name = info.substr(0, pos);
            pw = info.substr(pos + 1);
            if (name == input_name && pw == input_pw)
            {
                login_success = true;
                cout << "�α��� ����" << endl;
                break;
            }
        }
        if (!login_success)
        {
            cout << "�α��� ����" << endl;
            cout << "�̸� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
        }

    }
    

    return 0;
}