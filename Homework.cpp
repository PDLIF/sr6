

// вначале зачем-то начал решать с применением ООП, но уже после 4-ой задачи решил обходиться созданием только одних функций


#include <iostream>
#include <math.h>

double calculateTrapezoidArea(double b1, double b2, double h) {                                                         // задание1
    if (b1 <= 0 || b2 <= 0 || h <= 0) {
        std::cout << "Все значения (основания и высота) должны быть положительными числами." << std::endl;
        return -1;  // Возвращаем -1 в случае ошибки
    }

    // Вычисляем площадь трапеции
    double area = (b1 + b2) * h / 2;

    return area;
}

class Circle {                                                                                                              // задание 2
private:
    int r;
    const float pi = 3.14159;

public:
    void setRadius(int r) {
        this->r = r;
    }

    float getLength() {
        float len = 2 * pi * r;
        return len;
    }

    float getSquare() {
        float square = pi * r * r;
    }

    Circle(int _r) {
        r = _r;
    }
};

class RightTriangle {                                                                                                       // задание 3
private:
    int firstSide;
    int secondSide;

public:
    float getSquare() {
        return firstSide * secondSide / 2;
    }

    float getHypotenuse() {
        return sqrt(firstSide * firstSide + secondSide * secondSide);
    }

    RightTriangle(int _firstSide, int _secondSide) {
        this->firstSide = _firstSide;
        this->secondSide = _secondSide;
    }
};

class Number {                                                                                                              // задание 4
private:
    int number;
public:
    int getSumOfDigits() {
        int sum = 0;
        int number = this->number;

        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }

        return sum;
    }

    Number(int _number) {
        this->number = _number;
    }
};

void cartesianToPolar(double x, double y) {                                                                             // задание 6

    double r;
    double tan;

    r = sqrt(x * x + y * y);

    tan = atan2(y, x);

    std::cout << "Radius: " << r << std::endl;
    std::cout << "Angle in radians: " << tan << std::endl;
}

void solveQuadraticEquation(double a, double b, double c) {                                                                 // задание 7

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // Два действительных корня
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);

        std::cout << "Equasion has two roots x1 = " << root1 << ", x2 = " << root2 << std::endl;
    }
    else if (discriminant == 0) {
        // Один корень
        double root = -b / (2 * a);
        std::cout << "Equasion has only one root: x = " << root << std::endl;
    }
    else {
        // Нет действительных корней
        std::cout << "Equasion has no root." << std::endl;
    }
}


void findMedians(double a, double b, double c) {                                                                     // задание 8
    // Проверка на существование треугольника
    if (a + b > c && a + c > b && b + c > a) {
        // Находим координаты точек, соответствующих вершинам исходного треугольника
        double x1 = 0, y1 = 0;
        double x2 = a, y2 = 0;
        double x3 = (c * c + b * b - a * a) / (2 * c), y3 = sqrt(b * b - x3 * x3);

        // Находим координаты точек, соответствующих медианам
        double mx1 = (x2 + x3) / 2, my1 = (y2 + y3) / 2;
        double mx2 = (x1 + x3) / 2, my2 = (y1 + y3) / 2;
        double mx3 = (x1 + x2) / 2, my3 = (y1 + y2) / 2;

        std::cout << "Median passing through vertex A(" << x1 << ", " << y1 << ") and through the middle of BC: (" << mx2 << ", " << my2 << ")\n";
        std::cout << "Median passing through vertex B(" << x2 << ", " << y2 << ") and through the middle of AC: (" << mx1 << ", " << my1 << ")\n";
        std::cout << "Median passing through vertex C(" << x3 << ", " << y3 << ") and through the middle of AB: (" << mx3 << ", " << my3 << ")\n";
    }
    else {
        std::cout << "Triangle with the given parameters does not exist.";
    }
}

void calculateHoursAndMinutes(int seconds) {                                                                           // задание 9

    // Проверка на корректность входных данных
    if (seconds < 0) {
        std::cout << "Ошибка: Количество секунд не может быть отрицательным!" << std::endl;
        return;
    }

    // Рассчитываем количество часов
    float hours = seconds / 3600;

    // Рассчитываем количество минут
    float minutes = (seconds % 3600) / 60;

    std::cout << "Passed " << hours << " hours and " << minutes << " minutes" << std::endl;
}

bool isIsoscelesTriangle(double a, double b, double c) {                                                               // задание 10
    // Проверяем, является ли треугольник с заданными сторонами невырожденным
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        std::cout << "Треугольник с такими сторонами не существует." << std::endl;
        return false;
    }

    // Проверяем, является ли треугольник равнобедренным
    if (a == b || a == c || b == c) {
        std::cout << "Треугольник является равнобедренным." << std::endl;
        return true;
    }
    else {
        std::cout << "Треугольник не является равнобедренным." << std::endl;
        return false;
    }
}

double calculateTotalCost(double purchaseAmount) {                                                                       // задание 11
    const double discountThreshold = 1000.0;
    const double discountRate = 0.1;

    // Проверяем, превышает ли сумма покупки порог для скидки
    if (purchaseAmount > discountThreshold) {
        // Применяем скидку
        double discount = purchaseAmount * discountRate;
        double discountedTotal = purchaseAmount - discount;

        std::cout << "Поздравляем! Вы получили скидку 10%." << std::endl;
        std::cout << "Итоговая стоимость с учетом скидки: " << discountedTotal << " рублей." << std::endl;

        return discountedTotal;
    }
    else {
        // Сумма покупки не превышает порог для скидки
        std::cout << "Итоговая стоимость без скидки: " << purchaseAmount << " рублей." << std::endl;

        return purchaseAmount;
    }
}

void weightRecommendation(double height, double currentWeight) {                                                                // задание 12
    // Рассчитываем идеальный вес по формуле
    double idealWeight = height - 100.0;

    // Проверяем отношение текущего веса к идеальному
    if (currentWeight < idealWeight) {
        std::cout << "Рекомендация: Попробуйте набрать немного веса для достижения идеального веса." << std::endl;
    }
    else if (currentWeight > idealWeight) {
        std::cout << "Рекомендация: Попробуйте сбросить немного веса для достижения идеального веса." << std::endl;
    }
    else {
        std::cout << "Ваш вес уже находится в пределах идеального." << std::endl;
    }
}

int generateRandomNumber() {                                                                                                // задание 13
    // Генерируем случайное число от 1 до 9
    return rand() % 9 + 1;
}

void multiplicationTest() {
    // Инициализируем генератор случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Генерируем два случайных числа
    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();

    // Вычисляем произведение этих чисел
    int correctResult = num1 * num2;

    // Предлагаем тестируемому ввести результат
    int userResult;
    std::cout << "Умножьте " << num1 << " на " << num2 << ": ";
    std::cin >> userResult;

    // Проверяем, правильно ли введен результат
    if (userResult == correctResult) {
        std::cout << "Поздравляем! Вы правильно умножили числа." << std::endl;
    }
    else {
        std::cout << "Ошибочка! Правильный ответ: " << correctResult << std::endl;
    }
}

double calculateCallCost(double duration, int dayOfWeek) {                                                                       // задание 14
    const double weekdayRate = 0.5;  // Тариф в будние дни
    const double weekendRate = 0.4;  // Тариф в выходные дни (со скидкой)

    // Проверяем, является ли день недели субботой или воскресеньем
    if (dayOfWeek == 6 || dayOfWeek == 7) {
        // Применяем скидку 20% для выходных
        double cost = duration * weekendRate;
        std::cout << "Стоимость переговоров в выходной день: " << cost << " рублей." << std::endl;
        return cost;
    }
    else {
        // Для буднего дня применяем обычный тариф
        double cost = duration * weekdayRate;
        std::cout << "Стоимость переговоров в будний день: " << cost << " рублей." << std::endl;
        return cost;
    }
}

void displayMonthAndSeason(int monthNumber) {                                                                                // задание 15
    if (monthNumber < 1 || monthNumber > 12) {
        std::cout << "Некорректный номер месяца. Введите число от 1 до 12." << std::endl;
        return;
    }

    // Определение названия месяца
    const char* monthNames[] = {
        "Январь", "Февраль", "Март", "Апрель",
        "Май", "Июнь", "Июль", "Август",
        "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    const char* season;

    // Определение времени года
    if (monthNumber >= 3 && monthNumber <= 5) {
        season = "Весна";
    }
    else if (monthNumber >= 6 && monthNumber <= 8) {
        season = "Лето";
    }
    else if (monthNumber >= 9 && monthNumber <= 11) {
        season = "Осень";
    }
    else {
        season = "Зима";
    }

    std::cout << "Месяц: " << monthNames[monthNumber - 1] << std::endl;
    std::cout << "Время года: " << season << std::endl;
}

void addKopeikaWord(int number) {                                                                                               // задание 16
    if (number < 1 || number > 99) {
        std::cout << "Введите число в диапазоне от 1 до 99." << std::endl;
        return;
    }

    // Определяем последнюю цифру числа
    int lastDigit = number % 10;

    // Определяем форму слова "копейка" в зависимости от последней цифры
    std::string kopeikaForm;
    if (lastDigit == 1 && number != 11) {
        kopeikaForm = "копейка";
    } else if ((lastDigit >= 2 && lastDigit <= 4) && (number < 12 || number > 14)) {
        kopeikaForm = "копейки";
    } else {
        kopeikaForm = "копеек";
    }

    std::cout << "Ваше число: " << number << " " << kopeikaForm << std::endl;
}

bool isPalindrome(int number) {                                                                                                         // задание 17
    if (number < 1000 || number > 9999) {
        std::cout << "Введите четырехзначное число." << std::endl;
        return false;
    }

    // Извлекаем цифры числа
    int digit4 = number % 10;
    int digit3 = (number / 10) % 10;
    int digit2 = (number / 100) % 10;
    int digit1 = (number / 1000) % 10;

    // Проверяем, является ли число палиндромом
    return (digit1 == digit4 && digit2 == digit3);
}

void analyzeThreeDigitNumber(int number) {                                                                                                      // задание 18
    if (number < 100 || number > 999) {
        std::cout << "Введите трехзначное число." << std::endl;
        return;
    }

    // Извлекаем цифры числа
    int digit3 = number % 10;
    int digit2 = (number / 10) % 10;
    int digit1 = (number / 100) % 10;

    // Задача 19.1: Является ли произведение цифр больше числа b?
    int b = 50;
    int productOfDigits = digit1 * digit2 * digit3;
    if (productOfDigits > b) {
        std::cout << "Произведение цифр больше " << b << "." << std::endl;
    }
    else {
        std::cout << "Произведение цифр не больше " << b << "." << std::endl;
    }

    // Задача 19.2: Кратна ли 7 сумма цифр?
    int sumOfDigits = digit1 + digit2 + digit3;
    if (sumOfDigits % 7 == 0) {
        std::cout << "Сумма цифр кратна 7." << std::endl;
    }
    else {
        std::cout << "Сумма цифр не кратна 7." << std::endl;
    }
}

bool canFitRectangle(double a, double b, double c, double d) {                                                                                           // задание 19
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        std::cout << "Стороны прямоугольника должны быть положительными числами." << std::endl;
        return false;
    }

    // Проверяем, можно ли поместить прямоугольник со сторонами a, b в прямоугольник со сторонами c, d
    if ((a <= c && b <= d) || (a <= d && b <= c)) {
        std::cout << "прямоугольник со сторонами " << a << " и " << b << " можно поместить в прямоугольник со сторонами " << c << " и " << d << "." << std::endl;
        return true;
    }
    else {
        std::cout << "Прямоугольник со сторонами " << a << " и " << b << " нельзя поместить в прямоугольник со сторонами " << c << " и " << d << "." << std::endl;
        return false;
    }
}

void displayDataSizes() {                                                                                                   // задание 20
    std::cout << "Размер типа данных char: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Размер типа данных int: " << sizeof(int) << " байт" << std::endl;
    std::cout << "Размер типа данных float: " << sizeof(float) << " байт" << std::endl;
    std::cout << "Размер типа данных double: " << sizeof(double) << " байт" << std::endl;
    std::cout << "Размер типа данных long: " << sizeof(long) << " байт" << std::endl;
    std::cout << "Размер типа данных long long: " << sizeof(long long) << " байт" << std::endl;
    std::cout << "Размер типа данных bool: " << sizeof(bool) << " байт" << std::endl;
    std::cout << "Размер указателя: " << sizeof(int*) << " байт" << std::endl;
}


int main() {

    double base1 = 5, base2 = 5, height = 7;

    Circle circ(10); 

    RightTriangle triangle(5, 6); 

    Number number(1234); 

    double x = 3, y = 7; 
    double a = 3, b = 7, c = 9;
    double firstSide = 10, secondSide = 20, thirdSide = 15;
    int seconds = 7231;
    double purchaseAmount = 1001;
    double height = 185, currentWeight = 70;

    double duration = 2.5;
    int dayOfWeek = 3;

    int monthNumber = 9;

    int kopeika = 55;

    int polyndrome = 55;

    int threeDigitNumber = 321;

    std::cout << "Введите длину первого основания (b1): ";
    std::cin >> base1;

    std::cout << "Введите длину второго основания (b2): ";
    std::cin >> base2;

    std::cout << "Введите высоту трапеции (h): ";
    std::cin >> height;

    double result = calculateTrapezoidArea(base1, base2, height);

    if (result != -1) {
        std::cout << "Площадь трапеции: " << result << std::endl;
    }


    std::cout << "Square of the circle equals: " << circ.getLength() << std::endl;

    std::cout << "Square of the triangle equals: " << triangle.getSquare() << std::endl; 
    std::cout << "Hypotenuse of the triangle equals: " << triangle.getHypotenuse() << std::endl;

    std::cout << "Sum of digits of the number equals: " << number.getSumOfDigits() << std::endl; 

    cartesianToPolar(x, y); 

    solveQuadraticEquation(a, b, c); 

    findMedians(firstSide, secondSide, thirdSide); 
   
    calculateHoursAndMinutes(seconds); 

    isIsoscelesTriangle(firstSide, secondSide, thirdSide); 

    calculateTotalCost(purchaseAmount); 

    weightRecommendation(height, currentWeight); 

    multiplicationTest(); 

    displayMonthAndSeason(monthNumber); 

    addKopeikaWord(kopeika); 

    if (isPalindrome(polyndrome)) { 
        std::cout << "Это четырехзначное число является полиндромом" << std::endl;
    }
    else {
        std::cout << "Это четырехзначное число не является полиндромом" << std::endl;
    }

    analyzeThreeDigitNumber(threeDigitNumber);

    displayDataSizes();

    return 0;
}

