#include "..\Array\TemplateArray.h"

class BoolVector
{
public:
	BoolVector();
	BoolVector(const char* mas);
	BoolVector(const BoolVector otherBoolVector);
	BoolVector(const int len);
	

private:
	cosnt int m_additionInLength = sizeof(char);

	TemplateArray<char> m_bits;
	int m_realLen = 0;
	int m_maxLen = m_realLen + m_additionInLength
	
};