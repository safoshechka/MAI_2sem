import os
# Подключаем библитотеку os

key = int(input("Введите ключ: ")) 
# Введём ключ, т е число, которое показывает, на сколько мы 'сдвигаем', когда шифруем


def Ceaser(file):                         
# Создадим функцию шифрования по Цезарю

    alphabet = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz" 
    # Дублируем алфавит для последниъ пару букв, чтобы их можно было так же закадировать               
    encrypted = ""                         
    # Создадим "пустую" переменную, в которой будем записывать полученный шифр
    for string in file: 
    # Разобьем файл на строчки и прогоним каждую шифрованием 
        string = string.lower()
        # Разбиваем файл на строчки и приводим к нижнему регистру =)
        for letter in string:                
        # Прогоняем наше шифрование через каждую букву
            position = alphabet.find(letter) 
            # С помощью функции find берём позицию каждой буквы, чтоб потом прибавить ключ
            newposition = position + key     
            # Прибавляем к индексу, который получили выше, наш ключ
            if letter in alphabet:           
            # Проверим символы, так как у нас есть ещё запятые и пробелы, которые оставим без изменения
                encrypted = encrypted + alphabet[newposition] 
                # Записываем в нашу пустую строку нашу зашифрованную букву
            else:
                encrypted = encrypted + letter 
                # Пропускаем (и записываем) наши символы, которые шифровать не надо
    file.seek(0) 
    # Начинаем запись с начала файла (Ставим указатель на начало файла)
    file.write(encrypted) 
    # Запись результата функции в файл


def Find(pwd): 
# Создадим функцию, которая ищет все текстовые файлы 
    listdir = os.listdir(pwd)  
    # Создаём список всех элементов в текущей директории
    for element in listdir:
    # Берём каждый элемент из директории и прогоняем его
        path = pwd + "/" + element 
        # Создадим путь к текущему элементу 
        if os.path.isdir(path):  
        # Проверим, является ли элемент директорией 
            Find(path)  
            # Если да, то заходим в неё
        elif os.path.isfile(path):  
        # Если элемент файл
            if element.rfind("txt") == len(element) - 3: 
            # Проверяем, текстовый ли он 
                file = open(path, 'r+') 
                # Открываем файл на чтение + запись
                Ceaser(file)
                # Применяем наше шифрование 
                file.close() 
                # Закрываем файл


Find(os.getcwd())  
# Вызываем функцию с передачей в неё текущей директории
    
    
    
    
    
    
    
