#ifndef _IOCONTROLLER_H
#define _IOCONTROLLER_H
//Този клас използва Singleton. Ползваната информация за Singleton е намерана на адрес: https://refactoring.guru/design-patterns/singleton
//Допълнителна информация, с която реших възникнали проблеми с имплементацията е намерена на адрес: https://stackoverflow.com/questions/1008019/c-singleton-design-pattern 
class IOController
{
private:
	//Член-данни:
	//static IOController* instance;/*!< Поинтър към Singleton инстанция на класа */  

	//Конструктори:
	//! Конструктор по подразбиране
	/*!	Той е private, защото класа имплементира Singleton и не трябва да можем да създаваме нови негови инстанции*/
	IOController();

	//! Оператор= 
	//! /*!	Той е private, защото класа имплементира Singleton, ако го оставим може да се създаде нов от компилатора, това носи опасност да създадем копия на инстанцията*/
	void operator=(const IOController& other);
public:
	//Селектори:
	//! Селектор за инстанцията накласа
	/*! Ако не е създадена инстация първо ще се създаде такава */
	static IOController& getInstance();

	void test();
};
#endif
