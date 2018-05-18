#pragma once

class IReciever;

class Command{
protected:
	IReciever *receiver;
	
public:
	Command(IReciever *r){
		receiver = r;
	}
	virtual int execute() = 0;
};


// 加法
class AddCommand : public Command
{
public:
	AddCommand(IReciever *reciever);
	int execute();
};

// 减法
class SubtractCommand : public Command
{
public:
	SubtractCommand(IReciever *reciever);
	int execute();
};

// 乘法
class MultiplyCommand : public Command
{
public:
	MultiplyCommand(IReciever *reciever);
	int execute();
};

// 除法
class DivideCommand : public Command
{
public:
	DivideCommand(IReciever *reciever);
	int execute();
};
