#include <iostream>
#include <numeric>

class Figure
{
public:
	Figure() {};
	virtual double area() = 0;
};

class Circle : public Figure
{
private:
	double r;
public:
	Circle(double rad) { r = rad; };
	virtual double area() override { return 3.14 * pow(r,2); }
};

class Parallelogram : public Figure
{
private:
	double a;
	double h;
public:
	Parallelogram(double aa, double hh) { a = aa; h = hh; };
	virtual double area() override { return a * h; };
};

class Rectangle : public Parallelogram
{
private:
	double a;
	double b;
public:
	Rectangle(double aa, double bb) : Parallelogram(aa, bb) { a = aa; b = bb; };
	virtual double area() override { return a * b; };
};

class Square : public Parallelogram
{
private:
	double a;
public:
	Square(double aa) : Parallelogram(aa, aa) { a = aa; };
	virtual double area() override { return a * a; };
};

class Rhombus : public Parallelogram
{
private:
	double ac;
	double bd;
public:
	Rhombus(double a, double b) : Parallelogram(a, b) { ac = a; bd = b; };
	virtual double area() override { return ac * bd / 2; };
};

class Car
{
protected:
	std::string company;
	std::string model;
public:
	Car(std::string c, std::string m)
	{
		company = c;
		model = m;
		std::cout << "Car company = " << company << " model = " << model << std::endl;
	};
};

class PassengerCar : virtual protected Car
{
public:
	PassengerCar(std::string c, std::string m) : Car (c, m) 
	{
		std::cout << "PassengerCar company = " << company << " model = " << model << std::endl; 
	}
};

class Bus : virtual protected Car
{
public:
	Bus(std::string c, std::string m) : Car(c, m)
	{
		std::cout << "Bus company = " << company << " model = " << model << std::endl;
	}
}; 

class Minivan : virtual protected PassengerCar, virtual protected Bus
{
public:
	Minivan(std::string c, std::string m) : PassengerCar(c, m), Bus(c, m), Car(c,m)
	{
		std::cout << "Minivan company = " << company << " model = " << model << std::endl;
	}
};

class Fraction
{
private:
	int a;
	int b;
public:
	Fraction(int aa, int bb)
	{
		a = aa;
		if (bb == 0)
		{
			b = 1;
			std::cout << "The denominator cannot be zero. Now B=1" << std::endl;
		}
		else
			b = bb;
	};
	void print() { std::cout << a << "/" << b << std::endl;}

	Fraction operator+ (const Fraction &d)
	{
		int bb = std::lcm(b, d.b);
		int aa = a * (bb / b) + d.a * (bb / d.b);
		int g = std::gcd(aa, bb);
		return Fraction(aa/g, bb/g);
	}

	Fraction operator- (const Fraction& d)
	{
		int bb = std::lcm(b, d.b);
		int aa = a * (bb / b) - d.a * (bb / d.b);
		int g = std::gcd(aa, bb);
		return Fraction(aa/g, bb/g);
	}

	Fraction operator* (const Fraction& d)
	{
		int aa = a * d.a;
		int bb = b * d.b;
		int g = std::gcd(aa, bb);
		return Fraction(aa / g, bb / g);
	}

	Fraction operator/ (const Fraction& d)
	{
		int aa = a * d.b;
		int bb = b * d.a;
		int g = std::gcd(aa, bb);
		return Fraction(aa / g, bb / g);
	}

	Fraction operator- ()
	{
		return Fraction(-a, -b);
	}

	bool operator== (const Fraction& d)
	{
		int b1 = std::lcm(b, d.b);
		int a1 = a * (b1 / b);
		int a2 = d.a * (b1 / d.b);

		if (a1 == a2) return true;
		else return false;
	}

	bool operator< (const Fraction& d)
	{
		int b1 = std::lcm(b, d.b);
		int a1 = a * (b1 / b);
		int a2 = d.a * (b1 / d.b);

		if (a1 < a2) return true;
		else return false;
	}

	bool operator<= (const Fraction& d)
	{
		int b1 = std::lcm(b, d.b);
		int a1 = a * (b1 / b);
		int a2 = d.a * (b1 / d.b);

		if (a1 <= a2) return true;
		else return false;
	}

	friend bool operator!= (Fraction d1, Fraction d2)
	{
		if (d1 == d2) return false;
		else return true;
	}

	friend bool operator> (Fraction d1, Fraction d2)
	{
		if (d1 < d2) return false;
		else return true;
	}

	friend bool operator>= (Fraction d1, Fraction d2)
	{
		if (d1 <= d2) return false;
		else return true;
	}
};
enum CardSuit
{
	DIAMONDS,  // бубы
	HEARTS,    // черви
	CLUBS,     // трефы
	SPADERS    // пики
};

enum CardValue
{
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10,
	ACE = 1
};

class Card
{
private:
	CardSuit suit;
	CardValue value;
	bool isFace;
public:
	Card(CardSuit s, CardValue v) { suit = s, value = v, isFace = false; };

	void flip() 
	{
		if (isFace == true) isFace = false;
		else isFace = true;
	}
	int getValue() { return int(value); }
};

 

int main()
{
   /*1. Создать абстрактный класс Figure (фигура). 
   Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
   Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат),
   Rhombus (ромб). Для всех классов создать конструкторы. 
   Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
   Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.*/

	Circle c(2);
	std::cout << "Area of Circle = " << c.area() << std::endl;

	Parallelogram p(2,1);
	std::cout << "Area of Parallelogram = " << p.area() << std::endl;

	Rectangle r(2, 1);
	std::cout << "Area of Rectangle = " << r.area() << std::endl;

	Square s(2);
	std::cout << "Area of Square = " << s.area() << std::endl;

	Rhombus rm(2, 1);
	std::cout << "Area of Rhombus = " << rm.area() << std::endl;

	/*Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
	Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
	От этих классов наследует класс Minivan (минивэн). 
	Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
	Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
	Обратить внимание на проблему «алмаз смерти». */

	Minivan m("Toyota", "Hiace");

	/*Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
	Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
		математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
		унарный оператор (-)
		логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
	Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
	Продемонстрировать использование перегруженных операторов*/

	Fraction d1(3, 7);
	Fraction d2(2, 6);

	Fraction d = d1 + d2;
	d.print();

	d = d1 - d2;
	d.print();

	d = d1 * d2;
	d.print();

	d = d1 / d2;
	d.print();

	d = -d;
	d.print();

	if (d1 == d2) std::cout << "Fractions are equal" << std::endl;
	else std::cout << "Fractions are NOT equal" << std::endl;

	if (d1 != d2) std::cout << "Fractions are NOT equal" << std::endl;
	else std::cout << "Fractions are egual" << std::endl;

	if (d1 > d2) std::cout << "d1 is greater then d2" << std::endl;
	else std::cout << "d2 is greater then d1" << std::endl;

	if (d1 >= d2) std::cout << "d1 is greater or equeal then d2" << std::endl;
	else std::cout << "d2 is greater or equal then d1" << std::endl;

	if (d1 < d2) std::cout << "d1 is less then d2" << std::endl;
	else std::cout << "d2 is less then d1" << std::endl;

	if (d1 <= d2) std::cout << "d1 is less or equeal then d2" << std::endl;
	else std::cout << "d2 is less or equal then d1" << std::endl;

	/*Создать класс Card, описывающий карту в игре БлэкДжек.
	У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
	Сделать поля масть и значение карты типом перечисления (enum). 
	Положение карты - тип bool. Также в этом классе должно быть два метода: 
		метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
		метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/

	Card c1(DIAMONDS, KING);
	std::cout << "King value is " << c1.getValue() << std::endl;
}
