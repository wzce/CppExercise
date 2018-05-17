#include<string>
#include<mutex>
/*
	����ģʽ
*/
std::mutex mux;

//����ģʽ
	class SingleTon{
	private:
		SingleTon(){}//���췽��˽�л�
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
			//�̰߳�ȫ��ģʽ,���������ʱ��ֱ������
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

//��ģʽ���̰߳�ȫ
	class HungrySingleTon{
	private:
		HungrySingleTon(){}
	public:
		static HungrySingleTon* getInstance(){
			static HungrySingleTon single;
			return &single;
		}

	};

