#include "UserMode.h"
#include "AdminMode.h"
#include "Server.h"

UserMode::UserMode()
{
	user.ID = 0;
	user.loginCnt = 0;
	user.login_flag = 0;
	user.dormant = 0;
	user.PASS = "";
	user.JM = "";
	user.userRW = "";
}

UserMode::UserMode(int id, int cnt, bool lf, bool dm, string pass, string jm, string rw)
{
	user.ID = id;
	user.loginCnt = cnt;
	user.login_flag = lf;
	user.dormant = dm;
	user.PASS = pass;
	user.JM = jm;
	user.userRW = rw;
}

UserMode ::~UserMode() {}

int UserMode::FileUpload()
{
	string Fname;
	cout << "파일명 입력" << endl;
	cin >> Fname;
	int Fsize = Fname.size() * 2; //한글은 2바이트이므로 글자수 * 2

	Server serv;
	int Total = serv.getTotalSize();
	int Cur = serv.getCurUse();
	int Avail = Total - Cur;
	
	if (Fsize > Avail)
	{
		return -1;
	}
	else
	{
		serv.AddCurUse(Fsize);
		serv.AddFile(Fname);
		return 1;
	}
}

//해시로 ? -> 일단 벡터로하자
int UserMode::FileDownload()
{
	Server serv;
	serv.showFileList();

	string Fname;
	cout << "다운받을 파일명 입력" << endl;
	cin >> Fname;

	string ans = serv.FindFile(Fname);
	
	cout << ans;
	if (ans == "Can't find") return -1;
	else return 1;
}

int UserMode::FileDelete()
{
	string Fname;
	cout << "삭제 할 파일명 입력" << endl;
	cin >> Fname;

	Server serv;
	string ans = serv.FindFile(Fname);

	if (ans == "Can't find")
	{
		cout << ans << endl;
		return -1;
	}
	else
	{
		cout << Fname << " is deleted" << endl;
		int Fsize = Fname.size() * 2;
		serv.AddCurUse(-Fsize); // 음수 값 넣어서 용량 확보
		return 1;
	}
}