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
    along with this program. 
    If not, see <https://www.gnu.org/licenses/gpl.txt>.

    Author contact: dakotabarron52@gmail.com */


/* Here are defined the member functions of the Hangman class
This class represents the hangman that appears on the screen,
including the gallows pole.
*/

#include <iostream>
#include <iomanip>
#include "Hangman.h"

using namespace std;

Hangman::Hangman( int p )
   : parts( p )
{
   // empty constructor body
}

/*
return how many body parts the hangman currently has. for example, if only
the head is showing, this will return 1; if the head and upper body
are showing, this will return 2; etc...
*/
int Hangman::getParts() const
{
   return parts;
}

// adds a body part to the hangman
void Hangman::addPart()
{
   ++parts;
}

/* draws the hangman with the current number of body parts.
ASCII characters are used to draw. we static cast the integer representing
an ASCII character to an unsigned char.
*/
void Hangman::draw() const
{
   // only draw gallows pole
   if ( parts == 0 )
   {
      cout << setw( 19 );

      for ( int i = 1; i <= 11; ++i )
         cout << static_cast< unsigned char >( 95 );

	  cout << endl;

	  cout << setw(19) << static_cast<unsigned char>(124);

	  // part head hangs on
	  cout << setw(10) << static_cast<unsigned char>(124) << endl;

      cout << setw( 19 ) << static_cast< unsigned char >( 124 ) << endl;
      cout << setw( 19 ) << static_cast< unsigned char >( 124 ) << endl;
      cout << setw( 19 ) << static_cast< unsigned char >( 124 ) << endl;
	  cout << setw(19) << static_cast< unsigned char >(124) << endl;
	  cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   // draw head on gallows pole
   else if ( parts == 1 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // part head hangs on
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // head
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

	   // part head hangs on
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // head
	   cout << setw(10) << "O" << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // body directly below head
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

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

	   // part head hangs on
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // head
	   cout << setw(10) << "O" << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // body directly below head
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // lower piece of body
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

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

	   // part head hangs on
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // head
	   cout << setw(10) << "O" << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // body directly below head
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // lower piece of body
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // right leg
	   cout << setw(11) << "\\" << endl;

	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 5 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // part head hangs on
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // head
	   cout << setw(10) << "O" << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // body directly below head
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // lower piece of body
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // left leg
	   cout << setw(9) << "/";

	   // right leg												
	   cout << setw(2) << "\\" << endl;

	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 6 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // part head hangs on
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // head
	   cout << setw(10) << "O" << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // body directly below head
	   cout << setw(10) << static_cast<unsigned char>(124);

	   // right arm
	   cout << "/" << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // lower piece of body
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // left leg
	   cout << setw(9) << "/";

	   // right leg
	   cout << setw(2) << "\\" << endl;

	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }

   else if ( parts == 7 )
   {
	   cout << setw(19);

	   for (int i = 1; i <= 11; ++i)
		   cout << static_cast< unsigned char >(95);

	   cout << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // part head hangs on
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // head
	   cout << setw(10) << "O" << endl;

	   cout << setw(19) << static_cast< unsigned char >(124);

	   // left arm
	   cout << setw(9) << "\\";

	   // body directly below head
	   cout << static_cast<unsigned char>(124);

	   // right arm
	   cout << "/" << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // lower piece of body
	   cout << setw(10) << static_cast<unsigned char>(124) << endl;

	   cout << setw(19) << static_cast<unsigned char>(124);

	   // left leg
	   cout << setw(9) << "/";

	   // right leg
	   cout << setw(2) << "\\" << endl;
	   
	   cout << setw(19) << static_cast<unsigned char>(124) << endl << endl;
   }  
}