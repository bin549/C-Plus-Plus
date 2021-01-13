#include <./Book.h>

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h> 

using namespace std;

Book::Book()
{ 
	name_ = new char[10];
	isbn_ = 0;
	price_ = 0.0;
}

Book::Book(char* name, int isbn, float price)
{
	name_ = new char[strlen(name)];
	strcpy(name, name_);
	isbn_ = isbn;
	price_ = price;
}

Book::Book(const Book& book) 
{
	name_ = new char[strlen(book.name_)];
	strcpy(book.name_, name_);
	isbn_ = book.isbn_;
	price_ = book.price_;
}

Book Book::operator=(const Book& book) 
{
	Book newBook;
	newBook.name_ = new char[strlen(book.name_)];
	strcpy(book.name_, newBook.name_);
	newBook.isbn_ = book.isbn_;
	newBook.price_ = book.price_;
	return newBook;
}

Book::~Book()
{
	delete [] name_;
}

bool Book::operator>(const Book& book)
{
	return price_ > book.price_;
}

bool Book::operator<(const Book& book) 
{
	return price_ < book.price_;
}

bool Book::operator==(const Book& book) 
{
	return price_ == book.price_;
}
