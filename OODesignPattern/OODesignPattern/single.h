#include<string>
#include<mutex>
/*
	����ģʽ
*/

//����ģʽ
	class SingleTon{
	private:
		SingleTon(){}//���췽��˽�л�
		static SingleTon* instance;
		static std::mutex mux;
	public:
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
	
	}

	//��ģʽ���̰߳�ȫ
	class HungrySingleTon{
	private:
		HungrySingleTon(){}
	public:
		HungrySingleTon* getInstance(){
			static HungrySingleTon instance;
			return &instance;
		}

	};

