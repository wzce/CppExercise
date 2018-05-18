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


// �ӷ�
class AddCommand : public Command
{
public:
	AddCommand(IReciever *reciever);
	int execute();
};

// ����
class SubtractCommand : public Command
{
public:
	SubtractCommand(IReciever *reciever);
	int execute();
};

// �˷�
class MultiplyCommand : public Command
{
public:
	MultiplyCommand(IReciever *reciever);
	int execute();
};

// ����
class DivideCommand : public Command
{
public:
	DivideCommand(IReciever *reciever);
	int execute();
};
