#include<string>

#define max 10000

using namespace std;

class BigInteger{
	
	string number;
	bool sign;
	
public:
	//0 parameter constructor
	BigInteger();
	
	// string as a parameter
	BigInteger(string s);
	BigInteger(string s, bool sin);
	
	//number as a parameter
	BigInteger(int n);
	
	
	//member functions
	
	void setNumber(string s);
	
	const string& getNumber();// will retreive the number
	
	void setSign(bool sign); // sets the sign for the number
	
	const bool& getSign();// returns the sign of the number
	
	BigInteger absolute(); // returns the absolute value of the number
	
	//Operators
	void operator = (BigInteger b);
	bool operator == (BigInteger b);
	bool operator != (BigInteger b);
	bool operator >= (BigInteger b);
	bool operator <= (BigInteger b);
	bool operator > (BigInteger b);
	bool operator < (BigInteger b);
	
	
	BigInteger operator ++();
	BigInteger& operator ++(int);
	BigInteger operator --();
	BigInteger& operator --(int);
	BigInteger operator +(BigInteger b);
	BigInteger operator -(BigInteger b);
	BigInteger operator *(BigInteger b);
	BigInteger operator /(BigInteger b);
	BigInteger& operator +=(BigInteger b);
	BigInteger& operator -=(BigInteger b);
	BigInteger& operator *=(BigInteger b);
	BigInteger& operator /=(BigInteger b);
	BigInteger operator %(BigInteger b);
	BigInteger& operator %=(BigInteger b);
	operator string(); // converts BigInteger to String

	private:
	bool isEqual(BigInteger n1,BigInteger n2);
	
	bool isLess(BigInteger n1,BigInteger n2);
	
	bool isGreater(BigInteger n1,BigInteger n2);
	
	string add(BigInteger n1,BigInteger n2);
	
	string sub(BigInteger n1,BigInteger n2);
	
	string multiply(BigInteger n1, BigInteger n2);
	
	pair<string,long long> divide(string n, long long div);
	
	string toString(long long n);
	
	long long toInt(string s);
	
		
	
};

