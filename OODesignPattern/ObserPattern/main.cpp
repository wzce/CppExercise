#include"observer.h";
#include"subject.h";
#include"conditiondisplay_observer.h";
#include"forecastdispaly_observer.h";
#include"weatherdata_subject.h";
#include<iostream>
using namespace std;
/**
*/

int main() {
	ISubject *weatherSubject = new WeatherDataSubject();
	IObserver *conditionObserver = new ConditionDisplay(weatherSubject);
	IObserver *forecastObserver = new ForecastDisplay(weatherSubject);

	double p = 32.3, t = 23.04, h = 32.3;

	for (int i = 0; i < 20;i++) {
		weatherSubject->update(p+i,t+i,h+i);
	}
	cout << "***************************************移除订阅者******************************************" << endl;
	weatherSubject->remove(conditionObserver);

	for (int i = 0; i < 5; i++) {
		weatherSubject->update(p + i, t + i, h + i);
	}
	//释放资源
	delete weatherSubject;
	delete conditionObserver;
	delete forecastObserver;

	return 1;
}