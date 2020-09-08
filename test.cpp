#include "pch.h"
#include "../MyConsoleSever/Server.h"
#include "../MyConsoleSever/UserMode.h"

//ȣ�� Ȯ���Ϸ��� �Լ��� MOCK_METHOD�� �����!

using testing::AtLeast; //'���' ��� ȣ�� �Ǿ������� ���� ��
using testing::Return; // WillOnce, WillRepteadly ���� expect_call ���� action�� ���� ��ȯ�� �� ���
using testing::Invoke; // �𸣰���
using testing::_; //�Ű������� Ÿ�Կ� �´� �ƹ� ���̳� ����

class MockServer : public Server
{
public:
	MOCK_METHOD0(showFileList, void()); //�޼��� �ڿ� ���ڴ� �Ķ���� ����, (���ϸ�, ��ȯ��(�Ű����� Ÿ��))
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

//�Ʒ� �׽�Ʈ�� mock.AddUserInfo -> getUserInfo�� ���µ� 
TEST(MyTest, AddUserInfoTest)
{
	MockServer mock;
	EXPECT_CALL(mock, AddWaitUser(_));
	EXPECT_CALL(mock, getUserInfo(_));
	EXPECT_CALL(mock, DelWaitUser(_));

	UserInfo u;
	mock.AddWaitUser(u);
//	mock.AddUserInfo(0); //�̰ɷ� Ȯ���ϸ� ����, �Ʒ� �ΰ��� Ȯ���ϸ� ���

	mock.getUserInfo(0);
	mock.DelWaitUser(0);
}