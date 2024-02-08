#pragma once
#include <iostream>
#include <string>
using namespace std;
class Player
{
private:
	string name;
	char op;
public:
	Player() {	
		name = " ";
		op = ' ';
	}
	Player(string name,char op) {
		this->name = name;
		this->op = op;
	}
	void setname(string name) {
		this->name = name;
	}
	void setop(char op) {
		this->op = op;
	}
	string getname() {
		return name;
	}
	char getOp() {
		return op;
	}
};

