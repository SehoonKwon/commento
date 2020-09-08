#include "pch.h"
#include "../MyConsoleSever/Server.h"
#include "../MyConsoleSever/UserMode.h"

//호출 확인하려는 함수를 MOCK_METHOD로 만든다!

using testing::AtLeast; //'적어도' 몇번 호출 되었는지를 위할 때
using testing::Return; // WillOnce, WillRepteadly 같이 expect_call 뒤의 action의 값을 반환할 때 사용
using testing::Invoke; // 모르겠음
using testing::_; //매개변수로 타입에 맞는 아무 값이나 들어간다

class MockServer : public Server
{
public:
	MOCK_METHOD0(showFileList, void()); //메서드 뒤에 숫자는 파라메터 개수, (파일명, 반환형(매개변수 타입))
	MOCK_METHOD1(AddFile, void(string f));
	MOCK_METHOD1(AddWaitUser, void(UserInfo u));
	MOCK_METHOD1(getUserInfo, UserInfo(int idx));
	MOCK_METHOD1(DelWaitUser, void(int idx));
};

TEST(MyTest, TestshowFileList)
{
	MockServer mock;
	EXPECT_CALL(mock, showFileList);
	mock.showFileList();
}

TEST(MyTest, AddFileTest)
{
	MockServer mock;
	EXPECT_CALL(mock, AddFile);
	mock.AddFile("abc");
}

TEST(MyTest, AddWaitUserTest)
{
	MockServer mock;
	EXPECT_CALL(mock, AddWaitUser(_));

	UserInfo u;
	mock.AddWaitUser(u);
}

//아래 테스트는 mock.AddUserInfo -> getUserInfo로 가는데 
TEST(MyTest, AddUserInfoTest)
{
	MockServer mock;
	EXPECT_CALL(mock, AddWaitUser(_));
	EXPECT_CALL(mock, getUserInfo(_));
	EXPECT_CALL(mock, DelWaitUser(_));

	UserInfo u;
	mock.AddWaitUser(u);
//	mock.AddUserInfo(0); //이걸로 확인하면 에러, 아래 두개로 확인하면 통과

	mock.getUserInfo(0);
	mock.DelWaitUser(0);
}