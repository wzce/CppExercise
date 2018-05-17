#pragma once
#include<iostream>
#include"defensestragety.h"
//class IStrategy;
class GunStragety : public IStrategy {
public:
	GunStragety() {
		damageValue = 500;
	}

	~GunStragety() {
		std::cout << " GunStrategy destroy." << std::endl;
	}
	virtual void defense();//¹¥»÷µÄ²ßÂÔ
};

void GunStragety::defense() {
	std::cout << " defense with gun stragety." << " Minus " << damageValue << " blood" << std::endl;
}