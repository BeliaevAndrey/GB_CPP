## Основы программирования на C++
### Урок 11. Функции в программировании

Цели практической работы

Приобрести практическое понимание работы с функциями.
Научиться:
* объявлять свои функции с заданными типами возвращаемого значения и аргументами,
* задавать собственное тело функции,
* вызывать функции в программе и в других функциях.

Что входит в работу
1. Реализовать шифр Цезаря.
2. Разработать программу проверки корректности email-адреса.
3. Разработать программу валидации IP-адреса.
4. Разработать программу оценки результатов игры в крестики-нолики.


## Общие условия
Разработка выполняется в среде VS Code.

## Задание 1. Шифр Цезаря

### Что нужно сделать
В древности для шифрования сообщений использовался такой способ: все буквы в сообщении сдвигались на одно и то же число позиций в алфавите. Число позиций могло быть как положительным, так и отрицательным и являлось параметром шифра — его ключом. Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается (то есть буква с номером 27 — это снова буква a, буква с номером 28 — это буква b и так далее).
Например, слово abracadabra при сдвиге на десять позиций превратится в klbkmknklbk. Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно. Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку, зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decrypt_caesar, выполняющую обратное преобразование. Считаем, что входные строки состоят лишь из английских букв. Если там содержатся и другие символы, то их надо игнорировать.


Пример 1
```
The quick brown fox jumps over the lazy dog
```
Результат
```
Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl
```

Пример 2
```
Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum
```
Результат
```
Knqdl hortl cnknq rhs zlds bnmrdbsdstq zchohrbhmf dkhs rdc cn dhtrlnc sdlonq hmbhchctms ts kzanqd ds cnknqd lzfmz zkhptz Ts dmhl zc lhmhl udmhzl pthr mnrsqtc dwdqbhszshnm tkkzlbn kzanqhr mhrh ts zkhptho dw dz bnllncn bnmrdptzs Cthr ztsd hqtqd cnknq hm qdoqdgdmcdqhs hm unktoszsd udkhs drrd bhkktl cnknqd dt etfhzs mtkkz ozqhzstq Dwbdosdtq rhms nbbzdbzs btohczszs mnm oqnhcdms rtms hm btkoz pth neehbhz cdrdqtms lnkkhs zmhl hc drs kzanqtl
```

### Рекомендации
Уже имея функцию encrypt_caesar, функцию decrypt_caesar можно реализовать в одну строчку.
Функция шифрования принимает на вход строку и смещение. Нужно добавить смещение к числовому значению очередной буквы, но учесть зацикленность нашего алфавита.
У английской буквы ‘A’ числовое значение 65. Вы можете узнать остальные значения при помощи cout << int(‘интересующая вас буква’);

То есть для получения числового значения символа добавляем одинарные кавычки. Чтобы проверить, попадает ли символ в диапазон, нужно сделать if(symbol >= ‘x’ && symbol <=’z’).
Коды у заглавных и строчных символов разные. Чтобы ограничить число верхним пределом, можно воспользоваться оператором %.
При делении с остатком на число 26 никогда не получим число больше него. Значит не выйдем за пределы алфавита, а снова попадём в его начало (27 % 26 даёт 1, то есть снова первый символ). Чтобы зашифровать символ s, нам нужно:

1. Отнять от него значение первого символа алфавита (‘a’ или ‘A’ — вам потребуются два условия для двух разных случаев). Получим порядковый номер символа в алфавите.
2. Добавить смещение шифра, которое указывает пользователь.
3. Полученное значение разделить с остатком на 26. Получим порядковый номер символа в алфавите с учётом его зацикленности. Осталось получить этот символ, зная его номер. Для этого к коду первого символа алфавита (‘a’ или ‘A’) добавляем полученный порядковый номер.

Что оценивается
Корректность работы программы по созданию зашифрованной версии слова или текста.


## Задание 2. Проверка корректности email-адреса

### Что нужно сделать
Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.
Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @. Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов. Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. Точка не может быть первым или последним символом, а кроме того, две точки не могут идти подряд. В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:
```
!#$%&'*+-/=?^_{|}~`
```
Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.

### Примеры

### Корректные адреса:
```
simple@example.com
very.common@example.com
disposable.style.email.with+symbol@example.com
other.email-with-hyphen@example.com
fully-qualified-domain@example.com
user.name+tag+sorting@example.com (может на самом деле быть перенаправлен на user.name@example.com в зависимости от почтового сервиса)
x@example.com (однобуквенная локальная часть)
example-indeed@strange-example.com
admin@mailserver1
example@s.example
mailhost!username@example.org
user%example.com@example.org
```

### Некорректные адреса:
```
John..Doe@example.com (две точки не могут идти подряд)
Abc.example.com (нет символа @)
A@b@c@example.com (символ @ должен быть только один)
a"b(c)d,e:f;g<h>i[j\k]l@example.com (есть недопустимые символы)
1234567890123456789012345678901234567890123456789012345678901234+x@example.com (первая часть длиннее 64 символов)
i_like_underscore@but_its_not_allow_in this_part.example.com (во второй части есть недопустимый символ «»)
```
### Рекомендации
* Активно используйте оператор индексации строки str[i], но помните, что индексы начинаются с нуля, а не с единицы.
* Создайте отдельные функции, которые выдают первую и вторую части адреса для их последующего анализа.
* Для валидации отдельных символов внутри части используйте дополнительные строки-словари, состоящие из всех корректных символов для соответствующей части.
При разработке вспомогательных функций получения первой и второй части адреса воспользуйтесь циклом, который проверяет текущий символ.
* Если символ равен ‘@’, значит мы нашли границу между частями адреса. В функции нахождения первой части в этом месте надо остановиться и вернуть все символы, что были раньше (их можно накапливать в std::string при помощи оператора +=). Во второй функции все символы после ‘@’ тем же оператором добавляются к результату.
* Строка-словарь — это строка, которая в нашем случае содержит весь английский алфавит и символы. Каждый символ адреса надо сравнить с каждым символом из этого списка «допустимых символов» в цикле.
В этом задании очень важно разбить код на отдельные функции, каждая из которых делает небольшую часть работы.

### Что оценивается
Корректные результаты валидации адресов электронной почты. Должны устанавливаться как валидные адреса, так и невалидные.


## Задание 3. Валидация IP-адреса

### Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4). IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, быть не должно.
Пользователь вводит строку, задающую IP-адрес через стандартный ввод. В результате программа должна вывести слово Valid, если адрес корректен, и слово Invalid, если это не так.

### Примеры
### Корректные:
```
127.0.0.1
255.255.255.255
1.2.3.4
55.77.213.101
```

### Некорректные:
```
255.256.257.258 (есть числа больше 255)
0.55.33.22. (лишняя точка в конце)
10.00.000.0 (лишние нули)
23.055.255.033 (опять лишние нули)
65.123..9 (две точки подряд)
a.b.c.d (посторонние символы вместо чисел и точек)
```

### Рекомендации
* Активно используйте оператор индексации строки str[i], но помните, что индексы начинаются с нуля, а не с единицы.
* Создайте отдельную функцию для получения отдельных чисел из IP-адреса и валидируйте эти отдельные числа.
* Для валидации отдельных цифр у чисел следует использовать оператор сравнения с константами символов. Символы от ‘0’ до ‘9’ расположены последовательно и поэтому уместны операторы <= и >=.
Вам потребуется функция, принимающая на вход строку со всем IP-адресом и порядковый номер октета. Октет — это часть IP-адреса между точками. Он содержится в восьми битах, отсюда и название (окта — восемь). 2^8 = 256. Отсюда уже предел значения октета — 255. То есть вызов get_address_part(“192.168.1.1”, 1) вернёт 168. Данная функция проходит по всей строке и ищет разделители — точки, одновременно с этим накапливает символы в строку, которую вернёт в результате. При нахождении разделителя нужно вернуть полученную строку. Проверку её корректности нужно делать в другой функции (проверить длину == 3 и то, что число в строке находится в диапазоне [0,255] ).

### Что оценивается
Корректность валидации заданного пользователем адреса.

Как отправить задание на проверку
Пришлите ссылку на repl.it или файл .срр с решением через форму ниже. Также вы можете создать открытый репозиторий в GitHub с содержимым проекта.


## Задание 4. Оценка результатов игры в крестики-нолики

### Что нужно сделать
Петя и Вася играли в крестики-нолики и не стёрли результаты своей игры. Теперь перед вами табличка 3 × 3, которая осталась после их поединка. Вы хотите понять, выиграл ли кто-то из них или они не доиграли.
На вход программе даётся три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля. Крестик обозначается символом X (английская заглавная буква X), нолик — символом O (заглавная английская буква O), пустая клетка — точкой.
Если ввод некорректен, то есть такая таблица не могла получиться в ходе настоящей игры, то надо написать в ответ слово Incorrect.
Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики — Vanya won, иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.

Примеры
```
X..
OXO
OOO
```
Ответ: Incorrect (потому что ноликов в конце игры не может быть больше, чем крестиков).

```
X..
.X.
OO.
```
Ответ: Nobody (потому что они не доиграли).
```
XXO
OOX
XOX
```
Ответ: Nobody (потому что это ничья).
```
XO.
XO.
X.O
```
Ответ: Incorrect (крестики уже победили, и ноликов не может быть столько же).
```
OX.
XOX
X.O
```
Ответ: Incorrect (потому что нолики выиграли за три хода, и на поле за это время не могло успеть появиться четыре крестика).
```
..X
OX.
X.O
```
Ответ: Petya won.
```
0..
...
...
```
Ответ: Incorrect (потому что допускаются только символы X, O и точка, а цифра 0 не является допустимым символом).

### Рекомендации
* Активно используйте оператор индексации строки str[i], но помните, что индексы начинаются с нуля, а не с единицы.
* Чтобы обращаться к элементам игрового поля, стоит написать отдельную функцию получения элемента поля по его координатам (x, y). В таком случае часть алгоритмов поиска победителя можно обобщить.
* Функции проверки поля на корректность можно отделить от функций и алгоритмов проверки победителя.
* При достаточной модульности функций некоторые операции можно реализовать через уже существующие процедуры. К примеру, если уже есть проверка победителя в строке и имеется функция получения колонки по индексу, то функцию поиска победителя в колонке можно реализовать через обе процедуры.
* Проход по диагонали поля можно осуществить в цикле, используя счётчик цикла в качестве обоих координат элемента. Для второй диагонали нужно обратить одну из координат (2 − x или 2 − y).
* Общие условия некорректности поля таковы:
    - выявлено несколько победителей одновременно;
    - нолики победили, а крестиков больше, чем ноликов;
    - крестики победили, а ноликов столько же или больше;
    - нолики и крестики победили несколько раз;
    - на поле есть невалидные символы.

Для упрощения лучше создать отдельные функции для проверки победителя в строке или столбце, которые на вход принимают строку, а на выходе выдают символ победителя. То есть ‘X’, ‘O’ или ‘.’

### Что оценивается
Корректность работы программы по анализу игры на различных вводных данных.