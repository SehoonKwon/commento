/*!
*@file UserMode.h
*UserMode에 대한 설명
*/
#pragma once
#include <string>
using namespace std;

///유저정보를 저장하기 위한 자료구조
struct UserInfo
{
	int ID; ///< 유저 ID
	int loginCnt; ///< 유저 로그인 실패 회수
	bool login_flag; ///< 유저 로그인 플래그
	bool dormant; ///< 휴면상태 플래그
	string PASS; ///< 유저 비밀번호
	string JM; ///< 유저 주민등록번호
	string userRW; ///< 유저가 현재 갖고있는 권한
};

///유저 클래스에 대한 정보
class UserMode
{
private:
	UserInfo user; ///< 유저 클래스의 멤버변수는 유저정보로 저장
public:
	UserMode(); ///< 기본 생성자
	UserMode(int id, int cnt, bool lf, bool dm, string pass, string jm, string rw); ///< 생성자 오버로딩
	virtual ~UserMode(); ///< 소멸자

	
	///파일 업로드 함수
	/// 
	///업로드 할 파일명을 입력 받고 파일명의 크기에 비례해 파일 크기를 정합니다.
	///
	///파일을 올리기 충분한 용량이 있다면 파일을 업로드하고 1을 리턴합니다. 그렇지 않다면 -1을 리턴합니다.
	///@return 함수실행 결과. 성공시 1, 실패시 -1
	int FileUpload();

	///파일 다운로드 함수
	///
	///현재 서버에 업로드 된 파일명들을 출력합니다. 다운받을 파일명을 입력 받습니다.
	///
	///목록에 존재하는 파일명이면 다운받았다는 메시지와 함께 1을 리턴합니다.그렇지 않다면 -1을 리턴합니다.
	///@return 함수실행 결과. 성공시 1, 실패시 -1
	int FileDownload();
	
	///파일 삭제 함수
	///@return 함수실행 결과. 성공시 1, 실패시 -1
	int FileDelete();
};
