#pragma once
#include<iostream>
#include"defensestragety.h"
//class IStrategy;
class KnifeStragety : public IStrategy {
public:
	KnifeStragety() {
		damageValue = 100;
	}

	~KnifeStragety() {
		std::cout << " KinifeStrategy destroy." << std::endl;
	}

	virtual void defense();//�����Ĳ���
};

void KnifeStragety::defense() {
	std::cout << " defense with knife strategy." << " Minus "<<damageValue<<" blood" << std::endl;
}