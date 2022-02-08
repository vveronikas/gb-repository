#include <iostream>

class Person
{
private:
	std::string name;
	size_t age;
	char gender;
	size_t weight;
public:
	Person(std::string n, size_t a, char g, size_t w) { name = n; age = a; gender = g; weight = w; };
	void changeName(std::string n) { name = n; };
	void changeAge(size_t a) { age = a; };
	void changeWeight(size_t w) { weight = w; };
	void print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "Gender: " << gender << std::endl;
		std::cout << "Weight: " << weight << std::endl;
	}
};

class Student : public Person
{
private:
	size_t year;
public:
	Student( std::string n, size_t a, char g, size_t w, size_t y, int* count): Person(n, a, g, w) { year = y; *count = (*count) + 1; };
	void changeYear(size_t y) { year = y; };
	void increaseYear(size_t n) 
	{ 
		if (year != NULL)
			year = year + n;
		else
			std::cout << "Year is empty!" << std::endl;
	}
	void print()
	{
		Person::print();
		std::cout << "Year: " << year << std::endl << std::endl;
	}
};

class Fruit
{
private:
	std::string name;
	std::string color;
public:
	Fruit(std::string c, std::string n) { color = c; name = n; };
	std::string getName() { return name; };
	std::string getColor() { return color; };
};

class Apple : public Fruit
{
public:
	Apple(std::string c, std::string n = "apple") : Fruit(c, n) {};
};

class Banana : public Fruit
{
public:
	Banana() : Fruit("yellow", "banana") {};
};

class GrannySmith : public Apple
{
public:
	GrannySmith() : Apple("green", "Granny Smith apple") {};
};

int main()
{
   /*Создать класс Person (человек) с полями: имя, возраст, пол и вес.
   Определить методы переназначения имени, изменения возраста и веса. 
   Создать производный класс Student (студент), имеющий поле года обучения.
   Определить методы переназначения и увеличения этого значения. 
   Создать счетчик количества созданных студентов. 
   В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.*/

	int* count = new int;
	*count = 0;

	Student s1("Veronika", 23, 'F', 53, 2022, count);
	s1.print();

	Student s2("Kosya", 27, 'M', 76, 2021, count);
	s2.print();

	Student s3("Alisa", 32, 'F', 60, 2020, count);
	s3.print();

	std::cout << "Nubmber of students: " << *count << std::endl;

	delete count;

	/*Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
	У Fruit есть две переменные-члена: name (имя) и color (цвет).
	Добавить новый класс GrannySmith, который наследует класс Apple.*/

	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	/*Изучить правила игры в Blackjack.
	Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование. 
	Сколько будет классов в программе? Какие классы будут базовыми, а какие производными? 
	Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы.*/


	//Базовый класс Игрок, производный Дилер 
	// ...

}

