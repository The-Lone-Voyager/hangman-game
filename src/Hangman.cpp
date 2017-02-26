/*  Hangman - This program is a portable Hangman game written in C++11
    Copyright (C) 2016 Dakota Barron

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/gpl.txt>.

    Author contact: dakotabarron52@gmail.com */


// Here are defined the member functions of the Hangman class

#include <iostream>
#include <iomanip>
#include "Hangman.h"

using namespace std;

Hangman::Hangman( int p )
   : parts( p )
{
   // empty constructor body
}

int Hangman::getParts() const
{
   return parts;
}

void Hangman::addPart()
{
   ++parts;
}

void Hangman::draw() const
{
   if ( parts == 0 )
   {
      cout << setw( 19 );

      for ( int i = 1; i <= 11; ++i )
         cout << static_cast< unsigned char >( 95 );

	  cout << endl;

	  cout << setw(19) << static_cast<unsigned char>(124);
	  cout << setw(10) << static_cast<unsigned char>(124) << endl;
      cout << setw( 19 ) << static_cast< unsigned char >( 124 ) << endl;
      cout << setw( 19 ) << static_cast< unsigned char >( 124 ) << endl;
      cout << setw( 19 ) << static_cast< unsigned char >( 124 ) << endl;
	  cout << setw(19) << static_cast< unsigned char >(124) << endl;
	  cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 1 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;		// part head hangs on
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << "O" << endl;
	   cout << setw(19) << static_cast< unsigned char >(124) << endl;
	   cout << setw(19) << static_cast< unsigned char >(124) << endl;
	   cout << setw(19) << static_cast< unsigned char >(124) << endl;
	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;

   }

   else if ( parts == 2 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// part head hangs on
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << "O" << endl;
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// body directly below head
	   cout << setw(19) << static_cast< unsigned char >(124) << endl;
	   cout << setw(19) << static_cast< unsigned char >(124) << endl;
	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 3 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// part head hangs on
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << "O" << endl;
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// body directly below head
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// lower piece of body
	   cout << setw(19) << static_cast< unsigned char >(124) << endl;
	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 4 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// part head hangs on
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << "O" << endl;
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// body directly below head
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// lower piece of body
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(11) << "\\" << endl;									// right leg
	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 5 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// part head hangs on
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << "O" << endl;										// head
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// body directly below head
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// lower piece of body
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(9) << "/";												// left leg
	   cout << setw(2) << "\\" << endl;										// right leg
	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 6 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// part head hangs on
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << "O" << endl;										// head
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << static_cast<unsigned char>(124);					// body directly below head
	   cout << "/" << endl;													// right arm
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// lower piece of body
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(9) << "/";												// left leg
	   cout << setw(2) << "\\" << endl;										// right leg
	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 7 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// part head hangs on
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(10) << "O" << endl;										// head
	   cout << setw(19) << static_cast< unsigned char >(124);
	   cout << setw(9) << "\\";												// left arm
	   cout << static_cast<unsigned char>(124);								// body directly below head
	   cout << "/" << endl;													// right arm
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;			// lower piece of body
	   cout << setw(19) << static_cast<unsigned char>(124);
	   cout << setw(9) << "/";												// left leg
	   cout << setw(2) << "\\" << endl;										// right leg
	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }  
}