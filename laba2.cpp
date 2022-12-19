#include <iostream>
#include <stack>
#include <string>

bool function(std::string s_string)
{
    std::stack <char> mas;
    for (int i = 0; i < s_string.length(); i++) // Проверка на наличие скобочной последовательности(и её правильности)
    {
        if (s_string[i] == '(')
        {
            mas.push(s_string[i]);
        }
        if (mas.empty() && (s_string[i] == ')'))
        {
            return false;
        }
        // top - обращение к верхнему элементу списка
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

// Вовщращаем число целиком / Опрелеляем длину числа
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

int count(std::string str) // подсчитываем выражение
{
    std::stack <std::string> numbers; // числа
    std::stack <char> elements;
    int a = 0;
    int b = 0;
    str += '=';
    for (int i = 0; str[i] != '='; i++)
    {
        // если перед нами начало числа, то вызываем функцию length, которая вернет число и сдвинет i в цикле for. Заносим число в стек  
        if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i] != '(' && str[i] != ')')
        {
            numbers.push(length(str, i));
        }
        // if mat. operation
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            // если стек, куда мы добавляем мат.символы не пустой, то
            if (!elements.empty())
            {
                //считаем в порядке приоритета (* и / приоритетнее + и -)
                if ((str[i] == '+' || str[i] == '-') && (elements.top() == '/' || elements.top() == '*') && numbers.size() >= 2)
                {
                    //преобразовываем числовую строку в целые числа
                    b = stoi(numbers.top());
                    //удаление верхнего элемента стека
                    numbers.pop();
                    a = stoi(numbers.top());
                    numbers.pop();
                    // проверка деления на 0
                    if (b == '0' && elements.top() == '/')
                    {
                        std::cout << " !!! ZERO !!! ";
                        return 0;
                    }
                    if (elements.top() == '/')
                        numbers.push(std::to_string(a / b));
                    if (elements.top() == '*')
                        numbers.push(std::to_string(a * b));
                    // удаление верхнего элемента стека 
                    elements.pop();
                }
            }
            // if stack != zero
            if (!elements.empty())
            {
                // если данный элемент строки(мат символ) совпадает с тем элементом, что находится в начале стека мат. символов, то 
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
        if (str[i] == '(') // если элемент исходной строки, которую нужно посчитать равне скобке открывающей
        {
            // объявляем подстроку, которую нужно посчитать
            std::string str2;

            int left_boarder = 1;
            int right_boarder = 0;
            // находит выражение внутри скобки
            for (int j = i + 1; left_boarder != right_boarder; j++)
            {
                // записываем посимвольно
                str2 += str[j];
                if (str[j] == '(')
                    left_boarder += 1;
                if (str[j] == ')')
                    right_boarder += 1;
                i++;
            }
            // извлекаем элементы из стека
            str2.pop_back();
            // рекурсивно вызывает себя от выражения в скобке
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

                // проверка деления на 0, обязательна по условию
                if (b == '0' && elements.top() == '/')
                {
                    std::cout << " !!! ZERO !!! ";
                    return 0;
                }

                if (elements.top() == '/' && b != '0') { numbers.push(std::to_string(a / b));  }
                if (elements.top() == '*') { numbers.push(std::to_string(a * b)); }
                // удаление верхнего элемента стека
                elements.pop();
                elements.push(str[i]);
            }
            if ((str[i] == '/' || str[i] == '*') && (elements.top() == '+' || elements.top() == '-')) { elements.push(str[i]); }
            if ((str[i] == '+' || str[i] == '-') && (elements.top() != '/' && elements.top() != '*')) { elements.push(str[i]); }
        }
        // добавляем самый первый элемент в стек символов
        if ((elements.empty() && (str[i] < '0' || str[i]>'9')) && str[i] != ')') { elements.push(str[i]); }
    }
    // пока стек элементов не пустой и в нем больше 2 чисел, в стеке с числами выполняются оставшиеся операции
    while (!elements.empty() && numbers.size() >= 2)
    {
        b = stoi(numbers.top());
        numbers.pop();
        a = stoi(numbers.top());
        numbers.pop();
        // проверка деления на 0, обязательна по условию
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