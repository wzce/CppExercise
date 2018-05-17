#pragma once
#include"gunstrategy.h"
#include"defensestragety.h"
#include"knifestragety.h"
#include<iostream>
#include<memory>
using namespace std;


class Soldier {
private:
	shared_ptr<IStrategy *> defenseStrategy;
public:
	Soldier() {
		defenseStrategy = make_shared<IStrategy *>(new KnifeStragety());
	}
	~Soldier() {
		std::cout << "Soldier destroy" << std::endl;
	}
	void defense();
	void setStrategy(shared_ptr<IStrategy *> s);
};

void Soldier::defense(){
	(*defenseStrategy)->defense();
}

void  Soldier::setStrategy(shared_ptr<IStrategy *> s) {
	this->defenseStrategy = s;
};