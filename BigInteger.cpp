#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include<bits/stdc++.h>
#include "BigInteger.h"


/*
	The +ve sign of BigInteger is denoted by false
	where as the -ve sign of BigInteger is denoted by true
*/
//empty constructor
BigInteger::BigInteger(){
	number = "0";
	sign = true;
}

BigInteger::BigInteger(string s){
	if(isdigit(s[0])){
		setNumber(s);
		sign = false; // false for +ve number and true for -ve
	}else{
		setNumber(s.substr(1));
		sign = (s[0]=='-'); 
	}
}

BigInteger::BigInteger(string s, bool sign){
	setNumber(s);
	setSign(sign);
}


BigInteger::BigInteger(int n){
	stringstream ss;
	string s;
	ss<<n;
	ss>>s;
	
	if(isdigit(s[0])){
		setNumber(s);
		setSign(false);//for positive
	}else{
		setNumber(s.substr(1));
		setSign(s[0]=='-');
	}
	
}

void BigInteger::setNumber(string s){
	number = s;
}


const string& BigInteger::getNumber(){
	return number;
}

void BigInteger::setSign(bool s){
	sign = s;
}

const bool& BigInteger::getSign(){
	return sign;
}

BigInteger BigInteger::absolute(){
	return BigInteger(getNumber()); // since the getNumber will return only the number part 
}


//this function is for assignment
void BigInteger::operator = (BigInteger b){
	setNumber(BigInteger::getNumber());
	setSign(BigInteger::getSign());
} 

//this function return is equal or not

bool BigInteger::operator ==(BigInteger b){
	return isEqual((*this),b);
}


bool BigInteger::operator !=(BigInteger b){
	return !isEqual((*this),b);
}


bool BigInteger::operator < (BigInteger b){
	return isLess((*this),b);
}

bool BigInteger::operator > (BigInteger b){
	return isGreater((*this),b);
}

bool BigInteger::operator <=(BigInteger b){
	return isLess((*this),b) || isEqual((*this),b);
}

bool BigInteger::operator >=(BigInteger b){
	return isGreater((*this),b) || isEqual((*this),b);
}

BigInteger BigInteger::operator ++()//preincrement
{
	(*this)=(*this)+1;
	return (*this);
}

BigInteger& BigInteger::operator ++(int)//postincrement
{
	BigInteger& p=(*this);
	(*this)=(*this)+1;
	return p;
}

BigInteger BigInteger::operator --(){
	(*this) = (*this)-1;
	return (*this);
}

BigInteger& BigInteger::operator --(int)//post Decrement
{
	BigInteger& p = (*this);
	(*this)=(*this)-1;
	return p;
	
}

BigInteger BigInteger::operator +(BigInteger b){
	BigInteger addition;
	if(getSign()==b.getSign()){
		addition.setNumber(add(getNumber(),b.getNumber() ) );
		addition.setSign(getSign());
	}else{
		if(absolute()>BigInteger::absolute()){
			addition.setNumber(sub(getNumber(),b.getNumber()));
			addition.setSign(getSign());
		}else{
			addition.setNumber(sub(b.getNumber(),getNumber()));
			addition.setSign(b.getSign());
		}
	}
	if(addition.getNumber()=="0"){
		addition.setSign(false);
	}
	return addition;
}

BigInteger BigInteger::operator -(BigInteger b){
	BigInteger::setSign(!BigInteger::getSign());
	return (*this)+b;
}

BigInteger BigInteger::operator *(BigInteger b){
	BigInteger mul;
	mul.setNumber(multiply(getNumber(),BigInteger::getNumber()));
	mul.setSign(getSign()!=BigInteger::getSign());
	
	if(mul.getNumber()=="0")
		mul.setSign(false);
		
	return mul;
}

BigInteger BigInteger::operator /(BigInteger b){
	long long deno = toInt(BigInteger::getNumber());
	BigInteger div;
	div.setNumber(divide(getNumber(),deno).first);
	div.setSign(getSign() != BigInteger::getSign());
	
	if(div.getNumber()=="0"){
		div.setSign(false);
	}
	
	return div;
}

BigInteger BigInteger::operator %(BigInteger b){
	long long deno = toInt(BigInteger::getNumber());
	BigInteger rem;
	
	long long rem_int = divide(number,deno).second;
	rem.setNumber(toString(rem_int));
	rem.setSign(getSign() != BigInteger::getSign());
	
	if(rem.getNumber()=="0"){
		rem.setSign(false);
	}
	return rem;
} 

BigInteger& BigInteger::operator +=(BigInteger b){
	(*this)=(*this)+b;
	return (*this);
}

BigInteger& BigInteger::operator -=(BigInteger b){
	(*this)=(*this)-b;
	return (*this);
}

BigInteger& BigInteger::operator *=(BigInteger b){
	(*this)=(*this)*b;
	return (*this);
}

BigInteger& BigInteger::operator /=(BigInteger b){
	(*this)=(*this)/b;
	return (*this);
}

BigInteger& BigInteger::operator %=(BigInteger b){
	(*this)=(*this)%b;
	return (*this);
}




#endif
