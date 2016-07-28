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

    Author contact: dakota.barron@yahoo.com */


// This is the file that contains main() and that actually runs the game

// COMPILE INSTRUCTIONS: make sure Main.cpp, Hangman.h, Hangman.cpp,
//                       and Word.h are in the same directory, then compile
//                       Main.cpp and Hangman.cpp into an .exe
//                       Please note that you must compile this program in a compiler that
//                       implements or has option to compile as C++11 standard.

// NOTE: some complilers will issue warning messages for conversion and also
// unrecognized escape sequences used to draw the hangman. Just ignore these warnings.

// In order to run the game successfully, the "words.dat" file
// must be in the same directory as the .exe file created during compilation

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <random>
#include <ctime>
#include <array>
#include "Hangman.h"
#include "Word.h"

using namespace std;

void start(); // shows copyright info
void clear(); // clears the screen

int main()
{
   clear();
   start();

   ifstream inWord( "words.dat", ios::in | ios::binary );

   if ( !inWord )
   {
      cout << "Unable to locate the words file called \"words.dat\"" << endl;
      cout << "Please check the program directory and make sure that the \"words.dat\" file is in there" << endl;
      return 0;
   }

   map< char, bool, less< char > > letters;

   for ( char c = 'a'; c <= 'z'; ++c )
   {
      letters.insert( make_pair( c, false ) );
   }

   const size_t SIZE = 123356;

   array< bool, SIZE > wordsChosen = {};


   default_random_engine engine( static_cast< unsigned int >( time( nullptr ) ) );
   uniform_int_distribution< unsigned int > randomInt( 0, ( SIZE ) );

   string word;

   int response = 'y';

   do
   {
      Hangman hangman( 0 );
      enum GameStatus{ CONTINUE, WIN, LOSE };
      GameStatus status = CONTINUE;

      size_t chosen = 0;

      do
      {
         chosen = randomInt( engine );
        
      } while ( wordsChosen[ chosen ] );

      wordsChosen[ chosen ] = true;

      inWord.seekg( chosen * sizeof( Word ) );

      Word wordObject;

      inWord.read( reinterpret_cast< char * >( &wordObject ), sizeof( Word ) );

      word = wordObject.getWord();

      while ( status == CONTINUE )
      {
         clear();
         hangman.draw();
         cout << "\nGuess the word: ";
         
         for ( int c : word )
         {
            if ( ( letters[ static_cast< char >( c ) ] ) )
            {
               cout.put( static_cast< char >( toupper( c ) ) );
               cout << " ";
            }

            else
               cout << "_ ";
         }

         cout << "\n\nYour guess: ";
         int guess;
         guess = cin.get();
         
         if ( isalpha( guess ) )
         {
            if ( cin.get() != '\n' )
            {
               cin.ignore( 10000, '\n' );
               cout << "\nPlease enter one character, immediately followed by RETURN";
               cout << "\nPress enter to continue...";
               cin.ignore( 10000, '\n' );
               continue;
            }
         }

         else if ( !( isalpha( guess ) ) )
         {
            if ( guess != '\n' )
               cin.ignore( 10000, '\n' );

            cout << "\nPlease enter one character, immediately followed by RETURN";
            cout << "\nPress enter to continue...";
            cin.ignore( 10000, '\n' );
            continue;
         }

         if ( isupper( guess ) )
            guess = tolower( guess );

         if ( letters[ static_cast< char >( guess ) ] )
         {
            cout << "\nYou have already guessed that letter\n";
            cout << "Press enter to continue...";
            cin.ignore( 10000, '\n' );
            continue;
         }

         else
         {
            letters[ static_cast< char >( guess ) ] = true;

            if ( ( word.find( static_cast< char >( guess ) ) ) == string::npos )
               hangman.addPart();
         }
      
         status = WIN;

         for ( unsigned int i = 0; i < word.size(); ++i )
         {
            if ( !( letters[ word[ i ] ] ) )
               status = CONTINUE;
         }

         if ( hangman.getParts() == 7 )
            status = LOSE;
      }

      if ( status == LOSE )
      {
         clear();
         hangman.draw();
         cout << "\nGuess the word: ";
         
         for ( char c : word )
         {
            if ( letters[ c ] )
            {
               cout.put( static_cast< char > ( toupper( c ) ) );
               cout << " ";
            }

            else
               cout << "_ ";
         }

         cout << "\n\nYou LOSE" << endl;
         cout << "The word was: ";
         
         for ( int c : word )
            cout.put( static_cast< char >( toupper( c ) ) );
      }

      else if ( status == WIN )
      {
         clear();
         hangman.draw();
         cout << "\nGuess the word: ";
         
         for ( char c : word )
         {
            if ( letters[ c ] )
            {
               cout.put( static_cast< char >( toupper( c ) ) );
               cout << " ";
            }

            else
               cout << "_ ";
         }

         cout << "\nYou WIN" << endl;
         cout << "Congratulations!!! You guessed my word.";
      
      }

      for ( char c = 'a'; c <= 'z'; ++c )
      {
         letters[ c ] = false;
      }

      bool goodResponse = false;

      while ( !goodResponse )
      {
         cout << "\nPlay again? y/n: ";
         response = cin.get();
         
         if ( isalpha( response ) )
         {
            if ( cin.get() != '\n' )
            {
               clear();
               cout << "\nPlease enter \"y\" or \"n\" immediately followed by RETURN";
               cin.ignore( 10000, '\n' );
               continue;
            }

            else if ( ( response != 'y' ) && ( response != 'n' )
                    && ( response != 'Y' ) && ( response != 'N' ) )
            {
               clear();
               cout << "\nPlease enter \"y\" or \"n\" immediately followed by RETURN";
               continue;
            }

            else
            {
               goodResponse = true;
            }
         }

         else if ( !( isalpha( response ) ) )
         {
            if ( response != '\n' )
               cin.ignore( 10000, '\n' );

            clear();
            cout << "\nPlease enter \"y\" or \"n\" immediately followed by RETURN";
            continue;
         }

      }

   } while ( response == 'y' );

   return 0;
}

void start() // this function just shows the copyright notice when the game first starts
{
   cout << "Copyright (C) 2016 Dakota Barron\n\n"
      << "This program comes with ABSOLUTELY NO WARRANTY;\n"
      << "This is free software, and you are welcome to redistribute it\n"
      << "under certain conditions; See the COPYING file included\n"
      << "with this software or go to <https://www.gnu.org/licenses/gpl.txt> for details." << endl;

   cout << "\nPress enter to continue...";

   while ( cin.get() != '\n' );

   return;
}

void clear()
{
   cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

   return;
}