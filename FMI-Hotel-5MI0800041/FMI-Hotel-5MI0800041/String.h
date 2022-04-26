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
public:
	//Конструктори
	//! Конструктор по подразбиране
	/*! Създава нов масив с един елемет - "\0"*/
	String();
	//! Основен конструктор
	/*! Задава стойността на параметъра на член-данната
	*	Параметри:
	*		- char* data	  
	*/
	String(char* data);
	//!	Копи конструктор
	/*!	Създава нов обект като ползва друг за образец
	*	Параметри:
	*		- const String& other
	*/
	String(const String& other);

	//Селектори:
	//!	Селектор за данни
	/*!
	*	Връща:
	*		char*
	*/
	char* getData() { return data; }

	//Оператори:
	//!	Оператор =
	/*!	Променя обекта като ползва друг като образец
	*	Параметри:
	*		- const String& other 
	*/
	String& operator=(const String& other);
	
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
	*	Приятелска функция с която извеждаме данните за стринг чрез поток
	*
	*	Параметри:
	*		- std::istream& stream
	*		- const String& obj
	*
	*	Връща:
	*		- std::istream&
	*/
	friend std::istream& operator>>(std::istream& stream, const String& obj);
};
#endif
