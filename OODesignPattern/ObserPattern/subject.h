// subject.h

class IObserver;

class ISubject{
public:
	virtual void registerObserver(IObserver* obesever) = 0;
	virtual void remove(IObserver* obesever) = 0;
	virtual void notify() = 0;  // 通知观察者
	virtual void update(double temprature, double humidity, double presure)=0;
}
;
 