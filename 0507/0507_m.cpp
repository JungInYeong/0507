// �ǽ�1 ȸ�� ��� �ۼ��ϱ�

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    // ���ϸ� �Է� �ޱ�
    string filename;
    cout << "���ϸ��� �Է��ϼ���: ";
    getline(cin, filename);

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "���� ���� ����" << endl;
        return 1;
    }

    int num;
    cout << "�� ���� ȸ���� �����Ͻðڽ��ϱ�? : ";
    cin >> num;
    cin.ignore(); // cin�� getline ���̾��� ignore �����(?)

    cout << num << "���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���." << endl;

    vector<string>lines;
    string name;
    for (int i = 0; i < num; i++)
    {
        cout << i + 1 << "��° ȸ�� : ";
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
            cout << "���� ���� ����" << endl;
            return 1;
        }

    }
    cout << "\n-----------------------ȸ�����-----------------------" << endl;
    string line;
    while (getline(member, line))
    {
        cout << line << endl;
    }
 
    member.close();
    return 0;
}