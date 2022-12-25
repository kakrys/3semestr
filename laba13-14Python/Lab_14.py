# Дан текстовый файл с некоторым текстом на русском или английском языках произвольной длины (организовать чтение).
# Выбрав некоторую хеш-функцию, создать хеш-таблицу с:
#Лаба №14 “со списками”
def HashFunction(s):  # Хэш-функция (переводим символы в числа,складываем их,а затем делим на 32)
    result = 0
    for i in range(len(s)):
        result += ord(s[i])
    result = result % 32
    return result


def insert(mas, line):  # Операция Вставка
    key = HashFunction(line)
    if mas[key] != []:
        first = line
        second = mas[key]
        flag = True
        i = 0
        while (first[i] == second[i]):
            i+=1
        else:
            flag = False
        if flag:
            return "This row is already in the table"
        else:
            k = 0
            mas[key].append(line)
    else:
        mas[key].append(line)


def delete(mas, line):   # Операция удаление
    key = HashFunction(line)
    for i in range(len(mas[key])):
        if mas[key][i] == line:
            del mas[key][i]


def find(mas, line):   # Операция поиск
    key = HashFunction(line)
    if mas[key] != []:
        for i in range(len(mas[key])):
            if mas[key][i] == line:
                return mas[key][i]
    else:
        return "None"


if __name__ == "__main__":
    mas = [[] for i in range(32)]
    file = open("TextFileforlab13-14.txt", 'r')
    for line in file:
        line = ' '.join(line.split())
        insert(mas, line)
    for i in range(len(mas)):
        print(i, mas[i])
    a = find(mas, "We all like different genres, but we never argue with each other.")
    print(a)
    b = find(mas, "We begin to prepare in advance.")
    delete(mas, "We all like different genres, but we never argue with each other.")
    a = find(mas, "We all like different genres, but we never argue with each other.")
    print(a)
    print(b)