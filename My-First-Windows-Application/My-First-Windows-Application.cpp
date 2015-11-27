// My-First-Windows-Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int wmain( int argc, WCHAR* argv[] )
{
	wprintf( L"\n------------------------\n\n" );

	for( int i = 0; i < argc; i++ )
	{
		wprintf( L"Argument %d: %s \n", i, argv[ i ] );
	}

	wprintf( L"\n\n------------------------" );

	return 0;
}
