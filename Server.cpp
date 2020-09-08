#include "Server.h"

Server::Server()
{
	serv.TotalSize = 30; // ������ �ʱ� �뷮�� 30���� ����
	serv.CurSize = 0;
	serv.AddCnt = 0;
	serv.ID_List.clear();
	serv.WaitUserList.clear();
	serv.File_List.clear();
}

Server::~Server() {}

int Server::getTotalSize()
{
	return serv.TotalSize;
}

int Server::getCurUse()
{
	return serv.CurSize;
}

int Server::getAddCnt()
{
	return serv.AddCnt;
}

int Server::Login(int id, string pass)
{

	for (int i = 0; i < serv.ID_List.size(); i++)
	{
		if (id == serv.ID_List[i].ID && pass == serv.ID_List[i].PASS)
		{
			cout << "�ȳ��ϼ��� " << id << "��" << endl;
			Server::showServerInfo();
			return 1;
		}
	}

	return -1;
}

void Server::showFileList()
{
	for (int i = 0; i < serv.File_List.size(); i++)
		cout << serv.File_List[i] << " ";

	cout << endl;
}

void Server::showServerInfo()
{
	int Total = Server::getTotalSize();
	int Cur = Server::getCurUse();
	int Avail = Total - Cur;

	cout << "��ü �뷮 : " << Total << " ���� ��뷮 : " << Cur << " ��밡���� ���� : " << Avail << endl;
}

void Server::showWaitUser()
{
	for (int i = 0; i < serv.WaitUserList.size(); i++)
	{
		UserInfo temp = serv.WaitUserList[i];
		cout << "��û�� ID : " << temp.ID << endl;
		cout << " ��û�� ���� : " << temp.userRW << endl;
	}
	cout << endl;
}

void Server::showUserInfo(int ID)
{
	for (int i = 0; i < serv.ID_List.size(); i++)
	{
		if (ID == serv.ID_List[i].ID)
		{
			UserInfo temp = serv.ID_List[i];
			cout << "���� ID : " << ID << endl;
			
			cout << "PASS : ";
			for (int j = 0; j < temp.PASS.size(); j++)
			{
				if (j < 3) cout << temp.PASS[j];
				else cout << "*";
			}
			cout << endl;

			cout << "�ֹε�Ϲ�ȣ : ";
			for (int j = 0; j < temp.JM.size(); j++)
			{
				if (j < 7) cout << temp.JM[j];
				else cout << "*";
			}
			cout << endl;

			cout << "�������� : " << temp.userRW << endl;
			break;
		}
	}
}

void Server::AddUserInfo(int idx)
{
	UserInfo u = Server::getUserInfo(idx);
	serv.ID_List.push_back(u);
	Server::DelWaitUser(idx);
}

void Server::AddWaitUser(UserInfo u)
{
	serv.WaitUserList.push_back(u);
}

void Server::AddCurUse(int add)
{
	serv.CurSize += add;
}

void Server::AddTotalSize(int add)
{
	serv.TotalSize += add;
}

void Server::AddFile(string f)
{
	serv.File_List.push_back(f);
}

void Server::ModifyUserInfo(int ID)
{
	for (int i = 0; i < serv.ID_List.size(); i++)
	{
		if (ID == serv.ID_List[i].ID)
		{
			cout << "���� �������� : " << serv.ID_List[i].userRW << endl;
			cout << "���ο� ���� �Է� :";

			string str;
			cin >> str;
			serv.ID_List[i].userRW = str;
			break;
		}
	}
}

void Server::DelWaitUser(int idx)
{
	serv.WaitUserList.erase(serv.WaitUserList.begin() + idx);
}

string Server::FindFile(string str)
{
	for (int i = 0; i < serv.File_List.size(); i++)
	{
		if (str == serv.File_List[i])
			return str;
	}

	return "Can't find";
}

UserInfo Server::getUserInfo(int idx)
{
	return serv.WaitUserList[idx];
}