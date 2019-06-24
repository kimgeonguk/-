#ifndef	__CWINDOW_H
#define __CWINDOW_H

#include <Windows.h>

#pragma comment(lib,"imm32.lib")

typedef LRESULT(CALLBACK* ONCOMMAND)(HWND hWnd, WPARAM wParam, LPARAM lParam);
typedef struct _ONMSG {
	UINT		uiMsg;									// ���b�Z�[�W�ԍ�
	ONCOMMAND	cmdProc;								// �R�[���o�b�N�A�h���X
} ONMSG, * LPONMSG;
class CWindow {

public:
	// �g���₷���悤�ɊO�֏o��
	static HINSTANCE	hInstance;						// ���C���E�C���h�E�̃C���X�^���X
	static HWND			hWnd;							// ���C���E�C���h�E�̃n���h��
	static BOOL			bActive;						// �A�N�e�B�u��

protected:
	// �E�C���h�E�֌W
	static WCHAR		mName[256];						// �A�v���P�[�V������(�N���X���Ƃ��Ă��g�p)
	static const WCHAR* cIconID;						// �A�C�R���̎��
	static HMENU		hMenu;							// ���j���[�n���h��
	static DWORD		dwStyle;						// �E�C���h�E�X�^�C��
	static DWORD		dwExStyle;						// �g���X�^�C��
	static LPONMSG		mMsg;							// �ǉ����b�Z�[�W�f�[�^
	static int			iMsg;							// �ǉ����b�Z�[�W�̐�

private:
	// �E�C���h�E���b�Z�[�W�����R�[���o�b�N
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	CWindow();
	virtual ~CWindow();
	void SetIcon(const WCHAR* icon);																				// �A�C�R���̕ύX(Create�̑O�ɕK�v�j
	BOOL SetWindowStyle(DWORD style);																				// �E�C���h�E�̃X�^�C���̕ύX(���I�ɕύX���\)
	void SetMenu(HMENU menu);
	BOOL Create(HINSTANCE hInst, const WCHAR* appName, BOOL show = TRUE, DWORD w = 640, DWORD h = 480, HWND parent = NULL);	// �����ŊǗ�����E�C���h�E�𐶐�����
	void Delete(void);																							// �����I�ɃE�B���h�E���폜����

	BOOL AddMsgProc(UINT msg, ONCOMMAND proc);																		// ���ꃁ�b�Z�[�W�̒ǉ�
	void ShowCursor(BOOL bShow);																					// �}�E�X�J�[�\���̕\���A��\��
	void ShowWindow(BOOL bShow);																					// �E�C���h�E�̕\���A��\��
	void Move(int x, int y);																						// �E�C���h�E�̈ړ�
	void Move(int x, int y, int w, int h);																			// �E�C���h�E�̈ړ�(���ƍ����������ɕύX)

	BOOL MoveClientWindowCenter(int w, int h);																		// �w��T�C�Y���N���C�A���g�̈�ɂȂ�悤�ɃE�C���h�E��z�u
	BOOL SetMenuItem(int menuid, BOOL check = FALSE, BOOL gray = FALSE);												// ���j���[�A�C�e���̏�ԕύX

	BOOL TextOutW(int x, int y, const WCHAR* str, COLORREF col = 0);													// ���݂̃t�H���g�Ńe�L�X�g�\��
};

#endif