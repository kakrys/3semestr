#include <iostream>
#include <stack>
#include <string>

bool function(std::string s_string)
{
    std::stack <char> mas;
    for (int i = 0; i < s_string.length(); i++) // �������� �� ������� ��������� ������������������(� � ������������)
    {
        if (s_string[i] == '(')
        {
            mas.push(s_string[i]);
        }
        if (mas.empty() && (s_string[i] == ')'))
        {
            return false;
        }
        // top - ��������� � �������� �������� ������
        if (s_string[i] == ')' && mas.top() != '(')
            return false;
        if (s_string[i] == ')' && mas.top() == '(')
        {
            mas.pop();
        }
    }
    if (mas.empty()) { return true;  }
    return false;
}

// ���������� ����� ������� / ���������� ����� �����
std::string length(std::string str, int& j)
{
    std::string len;
    for (int i = j; (str[i] >= '0') && (str[i] <= '9'); i++)
    {
        len += str[i];
        j++;
    }
    j--;
    return len;
}

int count(std::string str) // ������������ ���������
{
    std::stack <std::string> numbers; // �����
    std::stack <char> elements;
    int a = 0;
    int b = 0;
    str += '=';
    for (int i = 0; str[i] != '='; i++)
    {
        // ���� ����� ���� ������ �����, �� �������� ������� length, ������� ������ ����� � ������� i � ����� for. ������� ����� � ����  
        if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i] != '(' && str[i] != ')')
        {
            numbers.push(length(str, i));
        }
        // if mat. operation
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            // ���� ����, ���� �� ��������� ���.������� �� ������, ��
            if (!elements.empty())
            {
                //������� � ������� ���������� (* � / ������������ + � -)
                if ((str[i] == '+' || str[i] == '-') && (elements.top() == '/' || elements.top() == '*') && numbers.size() >= 2)
                {
                    //��������������� �������� ������ � ����� �����
                    b = stoi(numbers.top());
                    //�������� �������� �������� �����
                    numbers.pop();
                    a = stoi(numbers.top());
                    numbers.pop();
                    // �������� ������� �� 0
                    if (b == '0' && elements.top() == '/')
                    {
                        std::cout << " !!! ZERO !!! ";
                        return 0;
                    }
                    if (elements.top() == '/')
                        numbers.push(std::to_string(a / b));
                    if (elements.top() == '*')
                        numbers.push(std::to_string(a * b));
                    // �������� �������� �������� ����� 
                    elements.pop();
                }
            }
            // if stack != zero
            if (!elements.empty())
            {
                // ���� ������ ������� ������(��� ������) ��������� � ��� ���������, ��� ��������� � ������ ����� ���. ��������, �� 
                if ((str[i] == '+' || str[i] == '-') && (elements.top() == '+' || elements.top() == '-') && numbers.size() >= 2)
                {
                    b = stoi(numbers.top());
                    numbers.pop();
                    a = stoi(numbers.top());
                    numbers.pop();
                    if (elements.top() == '+') { numbers.push(std::to_string(a + b));  }
                    if (elements.top() == '-') { numbers.push(std::to_string(a - b));  }
                }
            }
        }
        if (str[i] == '(') // ���� ������� �������� ������, ������� ����� ��������� ����� ������ �����������
        {
            // ��������� ���������, ������� ����� ���������
            std::string str2;

            int left_boarder = 1;
            int right_boarder = 0;
            // ������� ��������� ������ ������
            for (int j = i + 1; left_boarder != right_boarder; j++)
            {
                // ���������� �����������
                str2 += str[j];
                if (str[j] == '(')
                    left_boarder += 1;
                if (str[j] == ')')
                    right_boarder += 1;
                i++;
            }
            // ��������� �������� �� �����
            str2.pop_back();
            // ���������� �������� ���� �� ��������� � ������
            numbers.push(std::to_string(count(str2)));
        }
        if (!elements.empty())
        {
            if ((str[i] == '/' || str[i] == '*') && (elements.top() == '/' || elements.top() == '*'))
            {
                b = stoi(numbers.top());
                numbers.pop();
                a = stoi(numbers.top());
                numbers.pop();

                // �������� ������� �� 0, ����������� �� �������
                if (b == '0' && elements.top() == '/')
                {
                    std::cout << " !!! ZERO !!! ";
                    return 0;
                }

                if (elements.top() == '/' && b != '0') { numbers.push(std::to_string(a / b));  }
                if (elements.top() == '*') { numbers.push(std::to_string(a * b)); }
                // �������� �������� �������� �����
                elements.pop();
                elements.push(str[i]);
            }
            if ((str[i] == '/' || str[i] == '*') && (elements.top() == '+' || elements.top() == '-')) { elements.push(str[i]); }
            if ((str[i] == '+' || str[i] == '-') && (elements.top() != '/' && elements.top() != '*')) { elements.push(str[i]); }
        }
        // ��������� ����� ������ ������� � ���� ��������
        if ((elements.empty() && (str[i] < '0' || str[i]>'9')) && str[i] != ')') { elements.push(str[i]); }
    }
    // ���� ���� ��������� �� ������ � � ��� ������ 2 �����, � ����� � ������� ����������� ���������� ��������
    while (!elements.empty() && numbers.size() >= 2)
    {
        b = stoi(numbers.top());
        numbers.pop();
        a = stoi(numbers.top());
        numbers.pop();
        // �������� ������� �� 0, ����������� �� �������
        if (b == 0 && elements.top() == '/')
        {
            std::cout << " !!! ZERO !!! ";
            return 0;
        }
        if (elements.top() == '/' && b != '0') { numbers.push(std::to_string(a / b)); }
        if (elements.top() == '*') { numbers.push(std::to_string(a * b)); }
        if (elements.top() == '+') { numbers.push(std::to_string(a + b)); }
        if (elements.top() == '-') { numbers.push(std::to_string(a - b)); }
        elements.pop();
    }
    return stoi(numbers.top());
}

int main()
{
    std::string stroka;
    std::cin >> stroka;
    std::cout << "Result = " << count(stroka);
    return 0;
}