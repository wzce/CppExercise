// subject.h

class IObserver;

class ISubject{
public:
	virtual void register1(IObserver* obesever) = 0;
	virtual void remove(IObserver* obesever) = 0;
	virtual void notify() = 0;  // 通知观察者
}
;
 