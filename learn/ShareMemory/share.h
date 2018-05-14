#pragma once
#include <string>
#include <cstring>
#include <wtypes.h>
#include <map>
#include<tchar.h>

using namespace std;

std::wstring s2ws(const std::string& s);

#define  MEMORYSIZE 102400000 //ÿ���ڴ�Ĵ�С

struct MemoryAddr{
	string StrName;
	LPVOID pBuffer;
	HANDLE m_Handle;
};

class SharedMemory
{
public:
	SharedMemory(void);
	~SharedMemory(void);
public:
	string strMapName;                // �ڴ�ӳ���������
	string strComData;        // �����ڴ��е�����
	int MemoeryNum; //�����ڴ���

	map<int, MemoryAddr>MemoryInfo;

	LPVOID Init(string MeName);
	void   IntPutData(string MeName, string str);
	string OutPutData(string MeName);
	string GetAllData();
};

/*********/


SharedMemory::SharedMemory(void)
{
	MemoeryNum = 0;
}

SharedMemory::~SharedMemory(void)
{
	map<int, MemoryAddr>::iterator it;

	for (it = MemoryInfo.begin(); it != MemoryInfo.end(); it++)
	{
		::UnmapViewOfFile(it->second.pBuffer);
		::CloseHandle(it->second.m_Handle);
	}

	MemoryInfo.clear();
}

LPVOID SharedMemory::Init(string MeName)
{
	
	//char[MeName.size()+1] s = MeName;
	MemoryAddr mMemoryAddr;
	LPVOID pBuffer;


	LPCWSTR memoryName = s2ws(MeName).c_str();
	// ������ͼ��һ���������ڴ�ӳ���ļ�����  
	HANDLE hMap = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, memoryName);

	if (NULL == hMap)
	{    // ��ʧ�ܣ�����֮
		hMap = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, MEMORYSIZE, memoryName);
		// ӳ������һ����ͼ���õ�ָ�����ڴ��ָ�룬�������������
		pBuffer = ::MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	}
	else
	{    // �򿪳ɹ���ӳ������һ����ͼ���õ�ָ�����ڴ��ָ�룬��ʾ�����������
		pBuffer = ::MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	}

	mMemoryAddr.StrName = MeName.c_str();
	mMemoryAddr.pBuffer = pBuffer;
	mMemoryAddr.m_Handle = hMap;

	MemoryInfo.insert(pair<int, MemoryAddr>(MemoeryNum, mMemoryAddr));

	MemoeryNum++;

	return pBuffer;
}

void SharedMemory::IntPutData(string MeName, string str)
{
	map<int, MemoryAddr>::iterator itr;
	for (itr = MemoryInfo.begin(); itr != MemoryInfo.end(); itr++)
	{
		if (MeName == itr->second.StrName)
		{
			strcpy((char*)itr->second.pBuffer, str.c_str());
		}
	}
}

std::string SharedMemory::OutPutData(string MeName)
{
	map<int, MemoryAddr>::iterator iter;

	for (iter = MemoryInfo.begin(); iter != MemoryInfo.end(); iter++)
	{
		if (iter->second.StrName == MeName)
		{
			return (char*)iter->second.pBuffer;
		}
	}
}

std::string SharedMemory::GetAllData()
{
	string str = "";
	map<int, MemoryAddr>::iterator ir;
	for (ir = MemoryInfo.begin(); ir != MemoryInfo.end(); ir++)
	{
		string strTemp = "";
		strTemp.append(ir->second.StrName);
		strTemp.append(":");
		strTemp.append((char*)ir->second.pBuffer);
		str.append(strTemp.c_str());
		str.append(",");
	}
	return str;
}

std::wstring s2ws(const std::string& s)

{

	int len;

	int slength = (int)s.length() + 1;

	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);

	wchar_t* buf = new wchar_t[len];

	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);

	std::wstring r(buf);

	delete[] buf;

	return r.c_str();

}