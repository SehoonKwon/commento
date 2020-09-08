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
	cout << "변경할 새 코드 입력" << endl;

	int newCode;
	cin >> newCode;
	Admin.code = newCode;
}

void AdminMode::UserInfo()
{
	int t;
	cout << "1. 유저 정보 출력  2. 유저 정보 수정" << endl;
	cin >> t;

	if (t == 1)
	{
		cout << "출력할 유저 ID 입력" << endl;
		int ID;
		cin >> ID;

		Server serv;
		serv.showUserInfo(ID);
	}
	else if (t == 2)
	{
		cout << "수정할 유저 ID 입력" << endl;
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

	cout << "추가할 용량 입력" << endl;
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
	// 생성자 오버로딩 했는데 왜 UserMode u(); 로 선언하면 u.FileDownload 가 안되지? 
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