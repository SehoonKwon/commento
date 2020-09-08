/*!
*@file AdminMode.h
*AdminMode에 대한 설명
*/

#pragma once

///관리자 정보 자료구조
struct AdminInfo
{
	int code; ///< 관리자 코드
};

///@brief 관리자 클래스에 대한 정보
class AdminMode
{
private:
	AdminInfo Admin; ///관리자 클래스의 멤버변수는 관리자 정보로 저장
public:
	AdminMode(int cd); ///< 생성자
	virtual ~AdminMode(); ///< 소멸자

	///관리자 코드변경 함수
	///
	///코드를 새로 입력받고 기존 관리자 코드를 새 코드로 변경합니다.
	void ChangeAdminCode();

	///유저관리 함수
	///
	///원하는 기능을 선택합니다. 
	///
	///1을 입력하면 정보를 알고싶은 유저의 ID를 입력받고 해당 ID를 가진 유저의 정보를 출력합니다.
	///
	///2를 입력하면 권한을 수정하고 싶은 유저의 ID를 입력받고 해당 ID를 가진 유저의 권한을 변경합니다.
	void UserInfo();

	///서버용량 추가 함수
	///
	///서버의 용량추가 횟수가 3회가 넘었다면 추가없이 -1을 리턴합니다
	///
	///횟수가 남았다면 추가할 용량을 입력받고 서버 용량을 추가합니다
	///@return 추가 성공시 1, 실패시 -1
	int AddServerSize();

	///가입관리 함수
	void AcceptWaitUser();

	///파일 업로드 함수. 유저 클래스의 파일 업로드 메서드를 이용합니다.
	///@return 업로드 성공시 1, 실패시 -1
	int FileUpload();

	///파일 다운로드 함수. 유저 클래스의 파일 업로드 메서드를 이용합니다.
	///@return 다운로드 성공시 1, 실패시 -1
	int FileDownload();

	///파일 삭제 함수. 유저 클래스의 파일 업로드 메서드를 이용합니다.
	///@return 삭제 성공시 1, 실패시 -1
	int FildeDelete(); 
};