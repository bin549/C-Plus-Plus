
class Book
{
public:
	Book();
	Book(char *name, int isbn, float price);
	Book(const Book &book);
	Book operator=(const Book &book);
	~Book();
	bool operator>(const Book &book);
	bool operator<(const Book &book);
	bool operator==(const Book &book);
	friend ostream &operator<<(ostream &os, const Book &book);
	friend istream &operator>>(istream &is, Book &book);

private:
	char *name_;
	int isbn_;
	float price_;
};

ostream &operator<<(ostream &os, const Book &book)
{
	os << "---------BookInfo---------" << endl;
	os << "------Name: " << book.name_ << "--------" << endl;
	os << "------ISBN: " << book.isbn_ << "--------" << endl;
	os << "------Price: " << book.price_ << "--------" << endl;
	os << "--------------------------" << endl;
	return os;
}

istream &operator>>(istream &is, Book &book)
{
	cout << "Please Enter the Info of Book:\n";
	cout << "Name:";
	cin >> book.name_;
	cout << "ISBN:";
	is >> book.isbn_;
	cout << "Price:";
	is >> book.price_;
	return is;
}