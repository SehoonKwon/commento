/*!
*@file Server.h
*Server에 대한 설명
*/
#pragma once
#include "AdminMode.h"
#include "UserMode.h"
#include <vector>
#include <iostream>
using namespace std;

#define endl "\n"

///서버의 자료구조
struct ServerInfo
{
	int TotalSize; ///< 서버의 전체 용량
	int CurSize; ///< 현재 사용중인 용량
	int AddCnt; ///< 서버용량 추가 횟수
	vector<UserInfo> ID_List; ///< 서버에 저장된 유저들
	vector<UserInfo> WaitUserList; ///< 서버에 저장된 가입대기 유저들
	vector<AdminInfo> Admin_List; ///< 서버에 저장된 관리자들
	vector<string> File_List; ///< 서버에 저장된 파일들
};

///서버 클래스에 대한 설명
class Server
{
private:
	ServerInfo serv; ///< 서버 클래스 멤버변수
public:
	///생성자
	Server();

	///소멸자
	virtual ~Server();

	///서버 전체용량을 구하는 함수
	///@return TotalSize
	int getTotalSize();

	///현재 사용중인 용량을 구하는 함수
	///@return CurSize
	int getCurUse();

	///서버 용량추가를 한 횟수를 구하는 함수
	///@return AddCnt
	int getAddCnt();

	///로그인 함수
	///
	///해당 ID, PASS와 일치하는 ID를 찾고 결과를 리턴한다.
	///@return 로그인 성공시 1, 실패시 -1
	int Login(int id, string pass);

	///서버에 저장된 파일들을 출력하는 함수
	void showFileList();

	///서버 용량 정보를 출력하는 함수
	void showServerInfo();

	///가입대기인 유저들을 출력 함수
	void showWaitUser();

	///해당 ID를 가진 유저의 정보를 출력하는 함수
	void showUserInfo(int ID);

	///새로운 유저를 추가하는 함수
	void AddUserInfo(int idx);

	///가입대기 유저 추가하는 함수
	void AddWaitUser(UserInfo u);

	///현재 사용량을 증가시키는 함수. 음수 값을 통해 반대로 사용량을 줄일 수도 있다.
	void AddCurUse(int add);

	///서버 전체용량을 추가하는 함수
	void AddTotalSize(int add);

	///서버에 파일 추가하는 함수
	void AddFile(string f);

	///유저 권한을 변경하는 함수
	void ModifyUserInfo(int ID);

	///가입 대기중인 유저 리스트에서 삭제
	void DelWaitUser(int idx);

	///같은 파일명이 있는지 탐색하는 함수
	///@return 탐색 성공시 찾은 파일명, 실패시 Can't find
	string FindFile(string str);

	///해당 인덱스의 유저 정보를 반환하는 함수
	///@return 해당 인덱스의 유저정보
	UserInfo getUserInfo(int idx);
};