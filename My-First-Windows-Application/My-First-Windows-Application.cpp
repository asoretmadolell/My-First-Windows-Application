// My-First-Windows-Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void openFile( WCHAR* argv1 );

int wmain( int argc, WCHAR* argv[] )
{
	wprintf( L"\n------------------------\n\n" );

	for( int i = 0; i < argc; i++ )
	{
		wprintf( L"Argument %d: %s \n", i, argv[ i ] );
	}

	openFile( argv[ 1 ] );

	wprintf( L"\n\n------------------------" );

	return 0;
}

void openFile( WCHAR* argv1 )
{
	wprintf( L"\nThe argument we're interested in is the second one: %s\n\n", argv1 );

	FILE* stream;
	errno_t err;
	err = _wfopen_s( &stream, argv1, L"r" );

	if( err == 0 )
	{
		wprintf( L"The file %s has been opened.\n\n", argv1 );

		WCHAR str[ 100 ];

		//if (fgetws(str, 100, stream) == NULL) {	wprintf(L"read error or in \"fgetws\"\n");	}

		while( !feof( stream ) )
		{
			fgetws( str, 100, stream );
			wprintf( L"%s", str );
		}
	}
	else
	{
		wprintf( L"Error code: %d \n", err );
		return;
	}

	fclose( stream );
}