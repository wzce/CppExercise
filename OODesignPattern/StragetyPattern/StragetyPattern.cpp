// StragetyPattern.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"
#include"gunstrategy.h"
#include"defensestragety.h"
#include"knifestragety.h"
#include"soldier.h"
#include<iostream>
using namespace std;
int main()
{
	shared_ptr<IStrategy *> knife= make_shared<IStrategy *>(new KnifeStragety());
	shared_ptr<IStrategy *> gun=make_shared<IStrategy *>(new GunStragety());

	Soldier s;
	s.defense();
	cout << "------------------------------" << endl;

	s.setStrategy(gun);
	s.defense();

	knife.reset();
	gun.reset();

    return 0;
}

