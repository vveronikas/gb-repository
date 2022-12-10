#include <iostream>
#include <optional>
#include <tuple>
#include <vector>
#include <fstream>
#include <algorithm>

struct Person
{
    std::string surname;
    std::string name;
    std::optional<std::string> patronymic;
};

std::ostream& operator<< (std::ostream& out, const Person& p)
{
    out << "Surename: " << p.surname << std::endl;
    out << "Name: " << p.name << std::endl;
    out << "Patronymic: " << p.patronymic.value_or(" - ") << std::endl;
    return out;
}

bool operator< (const Person& p1, const Person& p2)
{
    return std::tie(p1.name, p1.surname, p1.patronymic)
        < std::tie(p2.name, p2.surname, p2.patronymic);
}

bool operator== (const Person& p1, const Person& p2)
{
    return std::tie(p1.name, p1.surname, p1.patronymic) 
        == std::tie(p2.name, p2.surname, p2.patronymic);
}

struct PhoneNumber
{
    size_t countryCode;
    size_t cityCode;
    std::string number;
    std::optional<size_t> extNumber;
    void operator= (const PhoneNumber& n2)
    {
        countryCode = n2.countryCode;
        cityCode = n2.cityCode;
        number = n2.number;
        extNumber = n2.extNumber;
    }
};

std::ostream& operator<< (std::ostream& out, const PhoneNumber& n)
{
    out << "+" << n.countryCode << "(" << n.cityCode << ")" << n.number;
    if (n.extNumber.has_value()) 
        out << " " << n.extNumber.value();
    out << std::endl;
    return out;
}

bool operator< (const PhoneNumber& n1, const PhoneNumber& n2)
{
    return std::tie(n1.countryCode, n1.cityCode, n1.number, n1.extNumber)
        < std::tie(n2.countryCode, n2.cityCode, n2.number, n2.extNumber);
}

bool operator== (const PhoneNumber& n1, const PhoneNumber& n2)
{
    return std::tie(n1.countryCode, n1.cityCode, n1.number, n1.extNumber)
        == std::tie(n2.countryCode, n2.cityCode, n2.number, n2.extNumber);
}

class PhoneBook
{
protected:
    std::vector<std::pair<Person, PhoneNumber>> book;
public:
    PhoneBook(std::vector<std::pair<Person, PhoneNumber>> b) { book = b;}
    PhoneBook(std::ifstream& indata)
    {
        int i = 0;
        Person p;
        PhoneNumber n;
        std::string patronymic;
        size_t ext;

        if (!indata) {
            std::cerr << "Error: file could not be opened" << std::endl;
            exit(1);
        }
        while (!indata.eof()) {
            indata >> p.surname;
            indata >> p.name;
            indata >> patronymic;
            p.patronymic.emplace(patronymic);
            indata >> n.countryCode;
            indata >> n.cityCode;
            indata >> n.number;
            indata >> ext;
            n.extNumber.emplace(ext);

            book.push_back(std::pair(p, n));
        }
        indata.close();
    }
    ~PhoneBook() {}
    friend std::ostream& operator<< (std::ostream& out, PhoneBook& b);
    void SortByName()
    {
        std::sort(book.begin(), book.end(), [](std::pair<Person, PhoneNumber> pair1, std::pair<Person, PhoneNumber> pair2)
            {if (pair1.first.surname != pair2.first.surname) return pair1.first.surname < pair2.first.surname;
            else if (pair1.first.name != pair2.first.name) return pair1.first.name < pair2.first.name;
            else if (pair1.first.patronymic.has_value()) return pair1.first.patronymic < pair2.first.patronymic; });
    }
    void SortByPhone()
    {
        std::sort(book.begin(), book.end(), [](std::pair<Person, PhoneNumber> pair1, std::pair<Person, PhoneNumber> pair2)
            {if (pair1.second.countryCode != pair2.second.countryCode) return pair1.second.countryCode < pair2.second.countryCode;
            else if (pair1.second.cityCode != pair2.second.cityCode) return pair1.second.cityCode < pair2.second.cityCode;
            else if (pair1.second.number != pair2.second.number) return pair1.second.number < pair2.second.number;
            else if (pair1.second.extNumber.has_value()) return pair1.second.extNumber < pair2.second.extNumber; });
    }

    std::pair<std::string, PhoneNumber&> GetPhoneNumber(const std::string& surname)
    {
        size_t count = 0;
        PhoneNumber phone;
        for (auto it : book)
        {
            if (it.first.surname == surname)
            {
                count++;
                phone = it.second;
            }
        }
        if (count == 0) return { "not found", phone };
        else if (count > 1) return { "found more than 1", phone };
        else return { "", phone };
    }

    void ChangePhoneNumber(const Person& p, const PhoneNumber& n)
    {
        for (auto it : book)
        {
            if (it.first == p) it.second = n;
        }
    }
};

std::ostream& operator<< (std::ostream& out, PhoneBook& b)
{
    Person p;
    PhoneNumber n;
    for (const auto& [p, n] : b.book)
    {
        out << p << n;
    }
    return out;
}

int main()
{
    std::ifstream file("book.txt");
    PhoneBook book(file);
    std::cout << book;
    std::cout << "------SortByPhone-------" << std::endl;
    book.SortByPhone();
    std::cout << book;
    std::cout << "------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book;
    std::cout << "-----GetPhoneNumber-----" << std::endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона человека, либо строку с ошибкой
    auto print_phone_number = [&book](const std::string& surname) 
    { 
        std::cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (std::get<0>(answer).empty())
            std::cout << std::get<1>(answer);
        else
            std::cout << std::get<0>(answer);
        std::cout << std::endl;
    };
    // вызовы лямбды
    print_phone_number("Serebryakova");
    print_phone_number("Gromov");
    std::cout << "----ChangePhoneNumber----" << std::endl;
    book.ChangePhoneNumber(Person{ "Serebryakova", "Veronika", "Olegovna" },
        PhoneNumber{ 7, 123, "15344458", std::nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << book;
    return 0;
}