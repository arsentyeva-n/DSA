#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    setlocale(LC_ALL, "RUS");

    /// for_each - применяет функцию к контейнеру

    vector<int> v{ 3, -4, 2, -8, 15, 267 };

    // Лямбда-функция вывода числа через пробел
    auto print = [](int n) { cout << n << ' '; };

    cout << "До:\t";
    for_each(v.begin(), v.end(), print);
    cout << '\n';

    // Лямбда-функция прибавления на единицу
    for_each(v.begin(), v.end(), [](int& n) { n++; });
    cout << "После:\t";
    for_each(v.begin(), v.end(), print);
    cout << '\n';

    int sum = 0;
    // [] - список  внешних захватываемых объектов, они могут захватываться как по ссылке, так и копированием
    for_each(v.begin(), v.end(), [&sum](int& x) { sum += x; });
    cout << "Сумма:\t";
    cout << sum << '\n';


    /// all_of, any_of, none_of - проверки условий
    
    vector<int> a{ -1, 3, 15, -23, -101 };

    // all_of - все ли удовлетворяют условию
    // проверяем все ли числа нечетные
    if (all_of(a.begin(), a.end(), [](int n) { return abs(n%2) == 1; }))
        cout << "Все удовлетворяют условию\n";
    else
        cout << "Не все удовлетворяют условию\n";
    
    
    // any_of - какой-нибудь элемент удовлетворяет ли условию
    vector<int> b{ 2, 4, -20, -100 };
    if (any_of(b.begin(), b.end(), [](int n) { return abs(n % 2) == 1; }))
        cout << "Хотя бы одно удовлетворяет условию\n";
    else
        cout << "Ни одно не удовлетворяет условию\n";

    // none_of - ни один не удовлетворяет условию
    vector<int> c{ 2, 4, -21, -100 };
    if (none_of(c.begin(), c.end(), [](int n) { return abs(n % 2) == 1; }))
        cout << "Ни один не удовлетворяет условию\n";
    else
        cout << "Одно из чисел удовлетворяет условию\n";


    /// transform - преобразует элементы

    //vector<int> v{ 3, -4, 2, -8, 15, 267 };

    cout << "\nДо:\t";
    for_each(v.begin(), v.end(), print);
    cout << '\n';
    
    // auto func = [](int n) {  return abs(n); };
    transform(v.begin(), v.end(), v.begin(), [](int n) {  return abs(n); });

    cout << "После:\t";
    for_each(v.begin(), v.end(), print);
    cout << '\n';


    /// copy_if -  копирует элементы, удовлетворяющие условию

    vector<int> v1{ 3, -4, 2, -8, 15, 267 };
    vector<int> v2;

    // back_inserter автоматически вызывает push_back()
    copy_if(v1.begin(), v1.end(), back_inserter(v2),  [](int n) {  return n < 0; });

    cout << "\nУдовлетворяют условию:\t";
    for_each(v2.begin(), v2.end(), print);
    cout << '\n';


}