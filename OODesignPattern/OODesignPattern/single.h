#include<string>
#include<mutex>
/*
	单列模式
*/
std::mutex mux;

//懒汉模式
	class SingleTon{
	private:
		SingleTon(){}//构造方法私有化
		static SingleTon* instance;
	public:
		~SingleTon(){
			if (instance !=NULL ){
				delete instance;
				instance = NULL;
			}
		}
		static SingleTon* getInstance();

		static SingleTon* getInstanceSafe(){
			//线程安全的模式,创建对象的时候直接上锁
			mux.lock();
			if (instance == NULL){
				instance = new SingleTon();
			}
			mux.unlock();
			return instance;
		}
	};

	  SingleTon* SingleTon::getInstance(){
		  if (instance == NULL){
			  instance = new SingleTon();
		 }
		  return instance;
	}
	 
	  SingleTon* SingleTon::instance(NULL);

//恶汉模式，线程安全
	class HungrySingleTon{
	private:
		HungrySingleTon(){}
	public:
		static HungrySingleTon* getInstance(){
			static HungrySingleTon single;
			return &single;
		}

	};

