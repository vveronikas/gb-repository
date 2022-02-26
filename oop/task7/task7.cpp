#include <iostream>
#include <memory>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {};
    ~Date() {};
    int getDay() { return day; };
    int getMonth() { return month; };
    int getYear() { return year; };
    friend ostream& operator<<  (ostream& out, Date& d);
};

ostream& operator<< (ostream& out, Date& d)
{
    out << d.getDay() << "/" << d.getMonth() << "/" << d.getYear() << endl;
    return out;
}

Date& comparisonDate(const unique_ptr<Date> &d1, const unique_ptr<Date> &d2)
{
    if ((*d1).getYear() > (*d2).getYear()) return (*d1);
    else if ((*d1).getYear() < (*d2).getYear()) return (*d2);
    else
    {
        if ((*d1).getMonth() > (*d2).getMonth()) return (*d1);
        else if ((*d1).getMonth() < (*d2).getMonth()) return (*d2);
        else
        {
            if ((*d1).getDay() > (*d2).getDay()) return (*d1);
            else if ((*d1).getDay() < (*d2).getDay()) return (*d2);
            else return (*d2);
        }
    }
}

void switchDate(unique_ptr<Date>& d1, unique_ptr<Date>& d2)
{
    Date date1 = (*d1);
    Date date2 = (*d2);
    (*d1) = date2;
    (*d2) = date1;
}


int main()
{
    /*1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
    Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя today и date. 
    Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date, 
    а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
    Затем переместите ресурс, которым владеет указатель today в указатель date.
    Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.*/

    unique_ptr<Date> date(new Date(25, 02, 2022));
    unique_ptr<Date> today(new Date(26, 02, 2022));
    int d = (*today).getDay();
    int m = (*today).getMonth();
    int y = (*today).getYear();

    cout << (*today);

    date = move(today);

    cout << date << " " << (*date);
    cout << today << endl;

    /*2. По условию предыдущей задачи создайте два умных указателя date1 и date2. 
    Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date
    и сравнивает их между собой (сравнение происходит по датам).Функция должна вернуть более позднюю дату.
    Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
    Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.*/

    unique_ptr<Date> date1(new Date(21, 02, 2022));
    unique_ptr<Date> date2(new Date(22, 02, 2022));

    cout << comparisonDate(date1, date2);

    switchDate(date1, date2);
    cout << (*date1) << (*date2);
}


