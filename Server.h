/*!
*@file Server.h
*Server�� ���� ����
*/
#pragma once
#include "AdminMode.h"
#include "UserMode.h"
#include <vector>
#include <iostream>
using namespace std;

#define endl "\n"

///������ �ڷᱸ��
struct ServerInfo
{
	int TotalSize; ///< ������ ��ü �뷮
	int CurSize; ///< ���� ������� �뷮
	int AddCnt; ///< �����뷮 �߰� Ƚ��
	vector<UserInfo> ID_List; ///< ������ ����� ������
	vector<UserInfo> WaitUserList; ///< ������ ����� ���Դ�� ������
	vector<AdminInfo> Admin_List; ///< ������ ����� �����ڵ�
	vector<string> File_List; ///< ������ ����� ���ϵ�
};

///���� Ŭ������ ���� ����
class Server
{
private:
	ServerInfo serv; ///< ���� Ŭ���� �������
public:
	///������
	Server();

	///�Ҹ���
	virtual ~Server();

	///���� ��ü�뷮�� ���ϴ� �Լ�
	///@return TotalSize
	int getTotalSize();

	///���� ������� �뷮�� ���ϴ� �Լ�
	///@return CurSize
	int getCurUse();

	///���� �뷮�߰��� �� Ƚ���� ���ϴ� �Լ�
	///@return AddCnt
	int getAddCnt();

	///�α��� �Լ�
	///
	///�ش� ID, PASS�� ��ġ�ϴ� ID�� ã�� ����� �����Ѵ�.
	///@return �α��� ������ 1, ���н� -1
	int Login(int id, string pass);

	///������ ����� ���ϵ��� ����ϴ� �Լ�
	void showFileList();

	///���� �뷮 ������ ����ϴ� �Լ�
	void showServerInfo();

	///���Դ���� �������� ��� �Լ�
	void showWaitUser();

	///�ش� ID�� ���� ������ ������ ����ϴ� �Լ�
	void showUserInfo(int ID);

	///���ο� ������ �߰��ϴ� �Լ�
	void AddUserInfo(int idx);

	///���Դ�� ���� �߰��ϴ� �Լ�
	void AddWaitUser(UserInfo u);

	///���� ��뷮�� ������Ű�� �Լ�. ���� ���� ���� �ݴ�� ��뷮�� ���� ���� �ִ�.
	void AddCurUse(int add);

	///���� ��ü�뷮�� �߰��ϴ� �Լ�
	void AddTotalSize(int add);

	///������ ���� �߰��ϴ� �Լ�
	void AddFile(string f);

	///���� ������ �����ϴ� �Լ�
	void ModifyUserInfo(int ID);

	///���� ������� ���� ����Ʈ���� ����
	void DelWaitUser(int idx);

	///���� ���ϸ��� �ִ��� Ž���ϴ� �Լ�
	///@return Ž�� ������ ã�� ���ϸ�, ���н� Can't find
	string FindFile(string str);

	///�ش� �ε����� ���� ������ ��ȯ�ϴ� �Լ�
	///@return �ش� �ε����� ��������
	UserInfo getUserInfo(int idx);
};