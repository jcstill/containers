#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
#include "../List/List.h"
using namespace std;

class String{
	private:
		int size;										// Current size of the String
		int capacity;									// Total capacity of the String
		List<char> str;									// Actual String stored as a list
		char* array;
		
		void copy(const String&);			//FIXME		// Deep copy the String
	public:
		String();										// Default Constructor
		String(int);									// Non-default Constructor
		String(const String&);				//FIXME		// Copy Constructor
		~String();										// Destructor
		// Capacity and sizing functions
		int sizeOf() const;								// Returns size of the String
		int length() const;								// Returns size of the String
		void resize(int);								// Resize String - Can modify String
		int capacityOf() const;							// Returns the size of allocated storage
		void reserve(int);								// Resize String - Can't modify String
		void clear();									// Clear the String - Resets capacity to 0
		bool isEmpty();									// Check if String is empty
		void shrink_to_fit();							// Shrink capacity to fit size
		// Element access
		char operator[](int) const;						// Return character in String
		char at(int) const;								// Return character in String
		char back() const;								// Return last character
		char front() const;								// Return first character
		// Modifiers
		String& operator+=(const String&);				// Append String to end of this String
		String& operator+=(const char*);				// Append const char* to end of this String - ei.( "Hello World" )
		String& operator+=(char);						// Append char to end of this String - ei.( 'Y' )
		String& append(const String&);					// Append String to end of this String
		String& append(const char*);					// Append const char* to end of this String - ei.( "Hello World" )
		String& append(char);							// Append char to end of this String - ei.( 'Y' )
		void push_back(const char);						// Append character to String
		String& assign(const String&);					// Replaces this String with String passed in
		String& assign(const char*);					// Replaces this String with const char* passed in - ei.( "Hello World" )
		String& assign(char);							// Replaces this String with char passed in - ei.( 'Y' )
		String& insert(int, const String&);				// Inserts a copy of String into this String
		String& insert(int, const char*);				// Inserts a copy of const char* into this String - ei.( "Hello World" )
		String& insert(int, char);						// Inserts a copy of char into this String - ei.( 'Y' )
		void erase(int, int);							// Erase portion of string ()
		String& replace(int, int, const String&);		// Replace portion of this String with String
		String& replace(int, int, const char*);			// Replace portion of this String with const char* - ei.( "Hello World" )
		String& replace(int, int, char);				// Replace portion of this String with char - ei.( 'Y' )
		void swap(String&);								// Swaps contents of this String with String
		void pop_back();								// Delete last character
		// String Operations
		// const char* c_str();						// Return pointer to char array of String
		// const char* data() const;						//




// get_allocator
// copy
// find
// rfind
// find_first_of
// find_last_of
// find_first_not_of
// find_last_not_of
// substr
// compare










		void print();									// 
};

String::String(){
	List<char> str;
	size = 0;
	capacity = 0;
	// array = NULL;
}
String::String(int x){
	List<char> str(x);
	size = x;
	capacity = x;
	// array = NULL;
}
String::String(const String& x){
	List<char> str;
	size = 0;
	capacity = 0;
	// array = NULL;
	copy(x);
}
String::~String(){
	str.~List();
	size = 0;
	capacity = 0;
	// if(array != NULL){
		// cout << "yeet\n";
		// delete [] array;
	// }
}
void String::copy(const String& x){
	for(int i=0; i<x.sizeOf(); i++){
		str.push_back(x.at(i));
		size++;
		capacity++;
	}
}
// Capacity and sizing functions
void String::pop_back(){
	str.pop_back();
	size--;
	capacity--;
}
void String::push_back(char x){
	str.push_back(x);
	size++;
	capacity++;
}
int String::sizeOf() const{
	return size;
}
int String::length() const{
	return size;
}
void String::resize(int x){
	if(x > size){
		for(int i=size-x; i<0; i++){
			str.push_back('\0');
		}
	}else if(x < size){
		for(int i=x; i<size; i++){
			str.pop_back();
		}
	}
	size = x;
	capacity = x;
}
int String::capacityOf() const{
	return capacity;
}
void String::reserve(int x){
	if(x > capacity){
		for(int i=capacity-x; i<0; i++){
			str.push_back('\0');
		}
		capacity = x;
	}else if(x < capacity && x < size){
		shrink_to_fit();
	}else if(x < capacity && x > size){
		for(int i=0; i<capacity-x; i++){
			str.pop_back();
		}
		capacity = x;
	}
}
void String::clear(){
	resize(0);
}
bool String::isEmpty(){
	return size == 0;
}
void String::shrink_to_fit(){
	for(int i=capacity; i>size; i--){
		str.pop_back();
	}
	capacity = size;
}
// Element access
char String::operator[](int x) const{
	return str.retAt(x);
}
char String::at(int x) const{
	return str.retAt(x);
}
char String::back() const{
	return str.retEnd();
}
char String::front() const{
	return str.retFront();
}
// Modifiers
String& String::operator+=(const String& x){
	for(int i=0; i<x.sizeOf(); i++){
		str.push_back(x.at(i));
		size++;
		capacity++;
	}
	return *this;
}
String& String::operator+=(const char* x){
	int constsize = 0;
	while(x[constsize] != '\0'){
		constsize++;
	}
	for(int i=0; i<constsize; i++){
		str.push_back(x[i]);
		size++;
		capacity++;
	}
	return *this;
}
String& String::operator+=(char x){
	str.push_back(x);
	size++;
	capacity++;
	return *this;
}
String& String::append(const String& x){
	for(int i=0; i<x.sizeOf(); i++){
		str.push_back(x.at(i));
		size++;
		capacity++;
	}
	return *this;
}
String& String::append(const char* x){
	int constsize = 0;
	while(x[constsize] != '\0'){
		constsize++;
	}
	for(int i=0; i<constsize; i++){
		str.push_back(x[i]);
		size++;
		capacity++;
	}
	return *this;
}
String& String::append(char x){
	str.push_back(x);
	size++;
	capacity++;
	return *this;
}
String& String::assign(const String& x){
	clear();
	for(int i=0; i<x.sizeOf(); i++){
		str.push_back(x.at(i));
		size++;
		capacity++;
	}
	return *this;
}
String& String::assign(const char* x){
	clear();
	int constsize = 0;
	while(x[constsize] != '\0'){
		constsize++;
	}
	for(int i=0; i<constsize; i++){
		str.push_back(x[i]);
		size++;
		capacity++;
	}
	return *this;
}
String& String::assign(char x){
	clear();
	str.push_back(x);
	size++;
	capacity++;
	return *this;
}
String& String::insert(int y, const String& x){
	for(int i=x.sizeOf()-1; i>=0; i--){
		str.insert(x.at(i), y);
		size++;
		capacity++;
	}
	return *this;
}
String& String::insert(int y, const char* x){
	int constsize = 0;
	while(x[constsize] != '\0'){
		constsize++;
	}
	for(int i=constsize-1; i>=0; i--){
		str.insert(x[i], y);
		size++;
		capacity++;
	}
	return *this;
}
String& String::insert(int y, char x){
	str.insert(x, y);
	size++;
	capacity++;
	return *this;
}
void String::String::erase(int x, int y){
	int tmp = 0;
	if(x > y){
		tmp = x;
		x = y;
		y = tmp;
	}
	str.clear(x, y);
	tmp = y - x +1;
	size -= tmp;
	capacity -= tmp;
}
String& String::replace(int y, int len, const String& x){
	erase(y, y+len);
	insert(y, x);
	return *this;
}
String& String::replace(int y, int len, const char* x){
	erase(y, y+len);
	insert(y, x);
	return *this;
}
String& String::replace(int y, int len, char x){
	erase(y, y+len);
	insert(y, x);
	return *this;
}
void String::swap(String& x){
	String tmp(x);
	x.assign(*this);
	assign(tmp);
	tmp.~String();
}
// String Operations
// const char* String::c_str(){
// 	delete [] array;
// 	array = new char[size+1];
// 	for(int i=0; i<size; i++){
// 		array[i] = at(i);
// 	}
// 	array[size] = '\0';
// 	return array;
// }


















// String::operator=

void String::print(){
	str.print();
}

#endif



/*
Move Constructor
Move Assignment Operator
The overloaded Assignment Operator
*/