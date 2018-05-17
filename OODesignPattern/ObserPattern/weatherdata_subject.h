

#include<list>
#include<iostream>
//#include"subject.h"
//#include"observer.h"
using namespace std;

class IObserver;
class ISubject;

class WeatherDataSubject : public ISubject{
public:
	~WeatherDataSubject() {}
	WeatherDataSubject(){}
	WeatherDataSubject(double t,double h,double p):temperature(t),humidity(h),presure(p){}
	virtual void registerObserver(IObserver* obesever);
	virtual void remove(IObserver* obesever);
	virtual void notify();  // 通知观察者
	virtual void update(double temprature, double humidity, double presure);

private:
	double temperature;
	double humidity;
	double presure;
	list<IObserver * > obsercers;

};

 void WeatherDataSubject::registerObserver(IObserver *observer){
	 obsercers.push_back(observer);
 }

 void WeatherDataSubject::remove(IObserver*obsever){
	 obsercers.remove(obsever);
 }

 void WeatherDataSubject::notify(){
	 list<IObserver*>::iterator it = obsercers.begin();
	 while (it != obsercers.end())
	 {
		 (*it)->update(temperature,humidity,presure);
		 it++;
	 }

	 std::cout << "Weather data changes ----------------------" << endl <<endl;;
 }

 void WeatherDataSubject::update(const double t, const double h, const double p) {
	 temperature = t;
	 humidity = h;
	 presure = p;
	 notify();
 }