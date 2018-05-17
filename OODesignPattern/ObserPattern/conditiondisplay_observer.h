//#include"observer.h"
//#include"subject.h"
#include<iostream>

using namespace std;

class IObserver;
class ISubject;

class ConditionDisplay : public IObserver{
private:
	ISubject* weatherData;
	double temperature;
	double humidity;
public:
	ConditionDisplay(ISubject* weatherData){
		this->weatherData = weatherData;
		weatherData->registerObserver(this);
	};

	virtual void update(double temprature, double humidity, double presure);
	void display();
};

void ConditionDisplay::update(const double t, const double h,const double p){
	 temperature = t;
	 humidity = h;
	 display();
}

void ConditionDisplay::display(){
	cout << " Current temperatur is " << temperature << " ,and current humidity is " << humidity << endl;
}