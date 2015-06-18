#include <iostream>


/* ΪCMyString��Ӹ�ֵ�����*/
class CMyString{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);

	CMyString& operator=(const CMyString& str);

	~CMyString();
private:
	char* m_pData;
};

CMyString& CMyString::operator=(const CMyString& str){

	/*  һ��ķ���
	*	if(str.m_pData == m_pData) return *this;
	*	delete []m_pData;
	*	m_pData = NULL;
	*	m_pData = new char[strlen(str.m_pData) + 1];
	*	strcpy(m_pData, str.m_pData);
	*	return *this;
	*/

	if (str.m_pData != m_pData){
		CMyString tmp_str(str);

		char* tmp_pData = m_pData;
		m_pData = tmp_str.m_pData;
		tmp_str.m_pData = tmp_pData;
	}

	return *this;
}

int main()
{
	
	
	return 0;
}