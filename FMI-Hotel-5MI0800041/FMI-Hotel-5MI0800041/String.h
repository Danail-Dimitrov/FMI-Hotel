#ifndef STRING_H
#define STRING_H
#include <iostream>
//!Помощен клас, които представлява имплементация на стринг
class String
{	
private:
	//Член-данни
	char* data; /*!< Стринга */  

	//! Копира стойонстите на параметрите на друг обект в този
	/*!	Първо вика deleteMemory(), осигурявайки, че няма да има изтичане на памет
	*/
	void copy(const String& other);
	//!	Освобождава паметта, заета от обекта
	/*!	Показателя data се променя да сочи към nullptr, за да не се хвърля грешка, ако метод се опита да промени паметта, към която той сочи преди изтриването
	*/
	void deleteMemory();

	//!	Метод за четене
	/*!
	*	Метод, които осъществява четене от даден поток (по подразбиране std::cin) до подаден разделител.
	*
	*	Параметри:
	*		- char separator\n
	*		  Символт до които се чете
	*		- int initialCapacity\n
	*		  Началната големина на масивът в, които се чете, той е саморазсширяващ се, тази променлива помага да се намали броя разсширявания. За думи ще започвам с 50 а за по дълъг тест с 500 символа
	* 		- std::istream& stream\n
	*		  Потокът от които се чете		
	* 
	*	Връща:
	*		- std::istream&
	*/
	std::istream& read(const char separator, std::istream& stream = std::cin, int initialCapacity = 50);
public:
	//Конструктори
	//! Конструктор по подразбиране
	/*! Създава нов масив с един елемет - "\0"*/
	String();
	//! Конструктор с параметри
	/*! Задава стойността на параметъра на член-данната
	*	Параметри:
	*		- char* data	  
	*/
	String(const char* data);
	//!	Копи конструктор
	/*!	Създава нов обект като ползва друг за образец
	*	Параметри:
	*		- const String& other
	*/
	String(const String& other);

	//Мутатори
	//!	Мутатор за данни
	/*!
	*	Параметри:
	*		- char* data
	*/
	void setData(const char* data);

	//Селектори:
	//!	Селектор за данни
	/*!
	*	Връща:
	*		char*
	*/
	char* getData() const { return data; }

	//Оператори:
	//!	Оператор =
	/*!	Променя обекта като ползва друг като образец
	*	Параметри:
	*		- const String& other 
	*/
	String& operator=(const String& other);

	//Методи:
	//! Метод за четене до разделител
	/*!	Дава възможност за четене до даден разелител (по подразбиране ' ') от дадеин поток (по подразбиране std::cin)
	*	Параметри:
	*		- const char separator\n
	*		  Рзделителят до които се чете
	*		- std::istream& stream\n
	*		  Потокът от които се чете
	*/
	void get(const char separator = ' ', std::istream& stream = std::cin);
	
	//!	Деконструктор
	~String();

	//Приятелски функции:
	//!	Oператор <<
	/*!
	*	Приятелска функция с която извеждаме данните за стринг чрез поток
	*
	*	Параметри:
	*		- std::ostream& stream
	*		- const String& obj
	*
	*	Връща:
	*		- std::ostream&
	*/
	friend std::ostream& operator<<(std::ostream& stream, const String& obj);
	//!	Oператор >>
	/*!
	*	Приятелска функция с която четем от поток до нов ред 
	*
	*	Параметри:
	*		- std::istream& stream
	*		- const String& obj
	*
	*	Връща:
	*		- std::istream&
	*/
	friend std::istream& operator>>(std::istream& stream, String& obj);
};
#endif
