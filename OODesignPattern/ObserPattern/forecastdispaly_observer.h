#pragma once
//#include"observer.h"
//#include"subject.h"
#include<iostream>

using namespace std;

class IObserver;
class ISubject;

class ForecastDisplay : public IObserver {
private:
	ISubject* weatherData;
	double temperature;
	double humidity;
	double presure;
public:
	ForecastDisplay(ISubject* weatherData) {
		this->weatherData = weatherData;
		weatherData->registerObserver(this);
	}
	~ForecastDisplay() {}
	virtual void update(double temprature, double humidity, double presure);
	void forecast();
};

void ForecastDisplay::update(const double t, const double h, const double p) {
	temperature = t;
	humidity = h;
	presure = p;
	forecast();
}

void ForecastDisplay::forecast() {
	cout << " The forecast temperatur is " << temperature
		<< " ,and the net forecast day's humidity is " << humidity <<
		" presure is " << presure<< endl;
}