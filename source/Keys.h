#ifndef KEYS_H
#define KEYS_H

#include <map>
#include "CharSet.h"
#include "Invoke.h"

namespace keys
{
	inline CharSet validNameChar 
	{
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'_','$',
		'0','1','2','3','4','5','6','7','8','9'
	};
	
	inline CharSet validFirstChar 
	{
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'_','$'
	};
	
	inline CharSet validInputChar 
	{
		' ','=',
		'+','-','*','/',
		'(',')',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'_','$',
		'0','1','2','3','4','5','6','7','8','9'
	};
	
	inline CharSet operatorChar 
	{
		'+','-','*','/',
		'(',')'
	};
	
	inline CharSet operatorChar_noBracket
	{
		'+','-','*','/'
	};
	
	inline CharSet bracketChar 
	{
		'(',')'
	};
	
	inline CharSet blankChar
	{
		' ','\n','\t'
	};
	
	
	inline int endl = 13;
	
	inline int _left = -224075;
	
	inline int _right = -224077;
	
	inline int _delete = -224083;
	
	inline int _backspace = 8;
	
	inline int esc = 27;
	
	inline int ctrlT = 20;
	
	inline CharSet exitConfirmChar
	{
		esc,endl
	};
	
	
	bool isASCII(int c);
}

#endif
