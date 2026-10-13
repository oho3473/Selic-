#include "pc.h"
#include "KeywordManager.h"
#include<cstdlib>
#include<ctime>

KeywordManager::KeywordManager()
{
}

KeywordManager::~KeywordManager()
{
	
}

void KeywordManager::M_ResetAnswerKeyword()
{
	for (size_t i = 0; i < m_vectorAnswer.size(); i++)
	{
		delete[] m_vectorAnswer[i];
	}
	m_vectorAnswer.clear();


	for (int i = 0; i < MAX_KEWORD; i++)
	{
		Word1_index[i] = rand() % (sizeof(m_firstword) / sizeof(m_firstword[0]));
		if (i == MAX_KEWORD - 1)
		{
			for (int j = 0; j < MAX_KEWORD - 1; j++)
			{
				for (int k = j + 1; k < MAX_KEWORD; k++)
				{
					if (Word1_index[j] == Word1_index[k])
					{
						i = -1;
						break;
					}
				}
			}
		}
	}

	//서로 다른 int 5개 저장
	for (int i = 0; i < MAX_KEWORD; i++)
	{
		Word2_index[i] = rand() % (sizeof(m_secondword) / sizeof(m_secondword[0]));
		//서로 다른 int 인지 체크
		if (i == MAX_KEWORD-1)
		{
			for (int j = 0; j < MAX_KEWORD - 1; j++)
			{
				for (int k = j + 1; k < MAX_KEWORD; k++)
				{
					if (Word2_index[j] == Word2_index[k])
					{
						i = -1;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < MAX_KEWORD; i++)
	{
		m_saveFWord[i] = nullptr;
		m_saveSWord[i] = nullptr;
		m_saveFWord[i] = m_firstword[Word1_index[i]];
		m_saveSWord[i] = m_secondword[Word2_index[i]];

	}
	
	// 화면에 출력된 단어들을 조합해서 수식어(5개)x공격마법(5개) 25개를 벡터에 저장
	for (int i = 0; i < MAX_KEWORD; i++)
	{
		for (int j = 0; j < MAX_KEWORD; j++)
		{
			//저장했던 서로 다른 인트값을 이용하여 조합해서 벡터 저장
			size_t bufferLength = wcslen(m_firstword[Word1_index[i]]) + 1 + wcslen(m_secondword[Word2_index[j]]) + 1;
			wchar_t* concatenated = new wchar_t[bufferLength];
			wcscpy_s(concatenated, bufferLength, m_firstword[Word1_index[i]]);
			wcscat_s(concatenated, bufferLength, L" ");
			wcscat_s(concatenated, bufferLength, m_secondword[Word2_index[j]]);

			m_vectorAnswer.push_back(concatenated);
		}
	}
	
}
 
void KeywordManager::M_SetShieldWord()
{
	m_ShieldWord = m_ShieldWords[rand() % (sizeof(m_ShieldWords) / sizeof(m_ShieldWords[0]))];
}

void KeywordManager::M_Init()
{
	srand(time(NULL));


	for (int i = 0; i < MAX_KEWORD; i++)
	{
		Word1_index[i] = rand() % (sizeof(m_firstword) / sizeof(m_firstword[0]));

		if (i == MAX_KEWORD-1)
		{
			for (int j = 0; j < MAX_KEWORD-1; j++)
			{
				for (int k = j + 1; k < MAX_KEWORD; k++)
				{
					if (Word1_index[j] == Word1_index[k])
					{
						i = -1;
						break;
					}
				}
			}
		}
	}

	//서로 다른 int 5개 저장
	for (int i = 0; i < MAX_KEWORD; i++)
	{
		Word2_index[i] = rand() % (sizeof(m_secondword) / sizeof(m_secondword[0]));

		//서로 다른 int 인지 체크
		if (i == 4)
		{
			for (int j = 0; j < MAX_KEWORD-1; j++)
			{
				for (int k = j + 1; k < MAX_KEWORD; k++)
				{
					if (Word2_index[j] == Word2_index[k])
					{
						i = -1;
						break;
					}
				}
			}
		}
	}

	for (int i=0;i< MAX_KEWORD;i++)
	{

		m_saveFWord[i] = m_firstword[Word1_index[i]];
		m_saveSWord[i] = m_secondword[Word2_index[i]];

	}

	// 화면에 출력된 단어들을 조합해서 수식어(5개)x공격마법(5개) 25개를 벡터에 저장
	for (int i = 0; i < MAX_KEWORD; i++)
	{
		for (int j = 0; j < MAX_KEWORD; j++)
		{
			//저장했던 서로 다른 인트값을 이용하여 조합해서 벡터 저장
			size_t bufferLength = wcslen(m_firstword[Word1_index[i]]) + 1 + wcslen(m_secondword[Word2_index[j]]) + 1;
			wchar_t* concatenated = new wchar_t[bufferLength];
			wcscpy_s(concatenated, bufferLength, m_firstword[Word1_index[i]]);
			wcscat_s(concatenated, bufferLength, L" ");
			wcscat_s(concatenated, bufferLength, m_secondword[Word2_index[j]]);

			m_vectorAnswer.push_back(concatenated);
		}
	}

 	M_SetShieldWord();

 }


std::vector<const wchar_t*> KeywordManager::M_Get_m_vectorAnswer()
{
	return m_vectorAnswer;
}


