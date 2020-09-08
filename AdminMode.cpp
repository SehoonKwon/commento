#include "AdminMode.h"
#include "UserMode.h"
#include "Server.h"

AdminMode::AdminMode(int cd)
{
	Admin.code = cd;
}

AdminMode::~AdminMode() {}

void AdminMode::ChangeAdminCode()
{
	cout << "������ �� �ڵ� �Է�" << endl;

	int newCode;
	cin >> newCode;
	Admin.code = newCode;
}

void AdminMode::UserInfo()
{
	int t;
	cout << "1. ���� ���� ���  2. ���� ���� ����" << endl;
	cin >> t;

	if (t == 1)
	{
		cout << "����� ���� ID �Է�" << endl;
		int ID;
		cin >> ID;

		Server serv;
		serv.showUserInfo(ID);
	}
	else if (t == 2)
	{
		cout << "������ ���� ID �Է�" << endl;
		int ID;
		cin >> ID;

		Server serv;
		serv.ModifyUserInfo(ID);
	}
}

int AdminMode::AddServerSize()
{
	Server serv;
	int Addcnt = serv.getAddCnt();
	if (Addcnt >= 3) return -1;

	cout << "�߰��� �뷮 �Է�" << endl;
	int X;
	cin >> X;

	serv.AddTotalSize(X);
	return 1;
}

void AdminMode::AcceptWaitUser()
{
	Server serv;
	serv.showWaitUser();
}

int AdminMode::FileUpload()
{
	UserMode *u = new UserMode();
	int res = u->FileUpload();
	return res;
}

int AdminMode::FileDownload()
{
	// ������ �����ε� �ߴµ� �� UserMode u(); �� �����ϸ� u.FileDownload �� �ȵ���? 
	UserMode u(0, 0, 0, 0, "", "", "");
	int res = u.FileDownload();
	return res;
}

int AdminMode::FildeDelete()
{
	UserMode u(0, 0, 0, 0, "", "", "");
	int res = u.FileDelete();
	return res;
}