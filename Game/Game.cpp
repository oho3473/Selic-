///
/// 
/// 
///배경음 완료(?)
///
/// 2023.05.25  17:25 selic! 유승운 윤유경 이동휴 이정환
/// Beta 1.0.0.ver

#include "Game.h"
#include "GameLogic.h"
#include <WinUser.h>
#include "SoundManager.h"
#define MAX_LOADSTRING 100
#define ID_EDIT 100

// 전역 변수:
HINSTANCE g_hInst;                                             // 현재 인스턴스입니다.
HWND g_hWnd;                                                   // 현재 윈도우 핸들
WCHAR szTitle[MAX_LOADSTRING] = L"Selic!";                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING] = L"Selic";          // 기본 창 클래스 이름입니다.
POINT g_WindowSize = { GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };
RECT ClientRect;
ULONG_PTR g_gdiplusToken;


//텍스트 입력창의 핸들
HWND g_hEdit;

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	///윈도우 등록
	WNDCLASSEXW wcex;

	//gdi 등록
	Gdiplus::GdiplusStartupInput gdiplus_Startup_Input;
	if (Gdiplus::GdiplusStartup(&g_gdiplusToken, &gdiplus_Startup_Input, NULL) != Gdiplus::Ok)
	{
		MessageBox(NULL, TEXT("GDI+ 라이브러리를 초기화할 수 없습니다."), TEXT("알림"), MB_OK);
		return 0;
	}

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;   //CS_DBLCLKS //더블클릭인식
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAME));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_GAME);
	wcex.lpszClassName = L"Selic";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wcex);

	///윈도우 생성 및 초기화

	g_hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

#ifdef _DEBUG
	HWND g_hWnd = CreateWindowW(L"Selic", szTitle, WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
		0, 0, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr, nullptr, hInstance, nullptr);
#else
	HWND g_hWnd = CreateWindowW(L"Selic", szTitle, WS_POPUP | WS_EX_TOPMOST,
		0, 0, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr, nullptr, hInstance, nullptr);
#endif // DEBUG


	if (!g_hWnd)
	{
		return FALSE;
	}

	if (FAILED(GameLogic::GetInstance()->M_Init(g_hWnd, g_WindowSize)))
	{
		MessageBox(nullptr, L"GameLogic 객체 초기화 실패", L"ERROR", MB_OK);
		return false;
	}




	ShowWindow(g_hWnd, nCmdShow);
	UpdateWindow(g_hWnd);

	///무한 루프

	MSG msg;

	// 기본 메시지 루프입니다:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (WM_QUIT == msg.message)
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			GameLogic::GetInstance()->M_Game_Loop();
		}
	}

	//gdo 해제
	Gdiplus::GdiplusShutdown(g_gdiplusToken);
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND g_hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_LBUTTONDOWN:
			SetFocus(g_hEdit);
			break;
		
	case WM_CREATE:
			SystemParametersInfo(SPI_SETBEEP, FALSE, NULL, SPIF_SENDCHANGE);
			//여유가 되면 에디트박스 투명 및 글자 투명화 OnCtlColor
			g_hEdit = CreateWindowW(L"edit",
				NULL,
				WS_CHILD | 
				WS_VISIBLE | 
				/*WS_BORDER |*/
				ES_AUTOHSCROLL,
				300, 1500, 300, 1500, g_hWnd, (HMENU)ID_EDIT,
				g_hInst, NULL);
			
			//에딧박스 글자수 제한
			SendMessage(g_hEdit, EM_LIMITTEXT, (WPARAM)32, 0);
			/// 에디트 콘트롤이 입력을 받게한다면
			SetFocus(g_hWnd);
			keybd_event(VK_HANGEUL, 0, 0, 0);
			keybd_event(VK_HANGEUL, 0, KEYEVENTF_KEYUP, 0);
			break;
			
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				//100은 주로 정적(static) 텍스트 컨트롤의 식별자로 사용되는 값입니다. 
				//정적 텍스트 컨트롤은 사용자에게 읽기 전용 텍스트를 표시하는 데 사용됩니다
				case ID_EDIT:
					switch (HIWORD(wParam))
					{
						/// 문자열의 변경
						//글자를 일정이상 적으면 더이상 안들어가야댐
						case EN_CHANGE:
							//파괴했던 에디트 박스를 다시 전역 변수에 넣어준다
							g_hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
							SetFocus(g_hEdit);
							//테스트 코드
							SoundManager::GetInstance()->M_PlayEffect(SOUND_LIST::KEYBOARDEFFECT, SOUND_CHANNEL::SOUND_CHANNEL_KEYBOARDCHANNEL, 0.3f);
							/// 에디트 문자열 복사 + 스테이지별로 복사 안하기
							GetWindowTextW(g_hEdit, KeyManager::GetInstance()->m_copytext, TEXTMAXLENGTH);
#ifdef _DEBUG
							/// 타이틀바 재설정
							SetWindowTextW(g_hWnd, KeyManager::GetInstance()->m_copytext);
#endif
							break; 
					}
			}
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(g_hWnd, message, wParam, lParam);
	}
	return 0;
}
