/*!
*@file UserMode.h
*UserMode�� ���� ����
*/
#pragma once
#include <string>
using namespace std;

///���������� �����ϱ� ���� �ڷᱸ��
struct UserInfo
{
	int ID; ///< ���� ID
	int loginCnt; ///< ���� �α��� ���� ȸ��
	bool login_flag; ///< ���� �α��� �÷���
	bool dormant; ///< �޸���� �÷���
	string PASS; ///< ���� ��й�ȣ
	string JM; ///< ���� �ֹε�Ϲ�ȣ
	string userRW; ///< ������ ���� �����ִ� ����
};

///���� Ŭ������ ���� ����
class UserMode
{
private:
	UserInfo user; ///< ���� Ŭ������ ��������� ���������� ����
public:
	UserMode(); ///< �⺻ ������
	UserMode(int id, int cnt, bool lf, bool dm, string pass, string jm, string rw); ///< ������ �����ε�
	virtual ~UserMode(); ///< �Ҹ���

	
	///���� ���ε� �Լ�
	/// 
	///���ε� �� ���ϸ��� �Է� �ް� ���ϸ��� ũ�⿡ ����� ���� ũ�⸦ ���մϴ�.
	///
	///������ �ø��� ����� �뷮�� �ִٸ� ������ ���ε��ϰ� 1�� �����մϴ�. �׷��� �ʴٸ� -1�� �����մϴ�.
	///@return �Լ����� ���. ������ 1, ���н� -1
	int FileUpload();

	///���� �ٿ�ε� �Լ�
	///
	///���� ������ ���ε� �� ���ϸ���� ����մϴ�. �ٿ���� ���ϸ��� �Է� �޽��ϴ�.
	///
	///��Ͽ� �����ϴ� ���ϸ��̸� �ٿ�޾Ҵٴ� �޽����� �Բ� 1�� �����մϴ�.�׷��� �ʴٸ� -1�� �����մϴ�.
	///@return �Լ����� ���. ������ 1, ���н� -1
	int FileDownload();
	
	///���� ���� �Լ�
	///@return �Լ����� ���. ������ 1, ���н� -1
	int FileDelete();
};
