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


// This is the file that contains main() and that actually runs the game

// See README for compile instructions

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

   /*
   in order for the program to work, the words.dat file must be in the
   same directory as the compiled executable. Therefore, the first thing
   we do is create the ifstream object and check if the file was found
   */

   ifstream inWord( "words.dat", ios::in | ios::binary );

   if ( !inWord )
   {
      clear();
      cout << "Unable to locate the words file called \"words.dat\"" << endl;
      cout << "Please check the program directory and make sure that the "
         "\"words.dat\" file is in there" << endl;
      return 0;
   }

   // if the program gets here, then we know the words.dat file was found

   /*
   each character of the alphabet is paired with a bool value in a map. 
   this map keeps track of which characters have already been guessed by
   the user.
   */
   map< char, bool, less< char > > letters;

   // initialize the map (false means letter has not been guessed yet)
   for ( char c = 'a'; c <= 'z'; ++c )
   {
      letters.insert( make_pair( c, false ) );
   }

   /*
   the number of words in the words.dat file. this number was known when
   the binary file was created. if another binary file is created with a
   different number of words, just change it once here.
   */
   const size_t SIZE = 123357; // number of words in the "words.dat" file

   // max number of missed guesses allowed to a user before they lose
   const int MAX_MISSES = 7;

   // keeps track of which words have been played already
   array< bool, SIZE > wordsChosen = {};

   // getting set up to generate random numbers
   default_random_engine engine(static_cast< unsigned int >(time(nullptr)));
   uniform_int_distribution< unsigned int > randomInt(0, (SIZE - 1));

   string word; // the current word to be guessed by the user

   /*
   used to tell whether or not the user wants to play again.
   initially set to 'y' so that the game will run at least once
   */
   int response = 'y';

   do
   {
      // initialize a new hangman
      Hangman hangman( 0 );

      /*
      used to tell whether the game should continue with another guess or
      end with either a win or a loss
      */
      enum GameStatus{ CONTINUE, WIN, LOSE };
      GameStatus status = CONTINUE;

      /*
      the index of the word in words.dat that will be guessed by the user
      */
      size_t chosen = 0;

      // now get a random word that hasn't been played yet from words.dat

      // generate a random index that corresponds to a new unplayed word
      do
      {
         chosen = randomInt( engine );
        
      } while ( wordsChosen[ chosen ] );

      /* 
      the word at this index will now be played, so set the appropriate
      value in wordsChosen to true
      */
      wordsChosen[ chosen ] = true;

      // now read in the word from the binary file

      inWord.seekg( chosen * sizeof( Word ) );

      // Word class makes it easier to read a word from the binary file
      Word wordObject;

      inWord.read(reinterpret_cast< char * >(&wordObject), sizeof(Word));

      word = wordObject.getWord();

      // now the string variable named word contains the word to be played

      /*
      while the user has not won or lost, ask them for a letter
      */
      while ( status == CONTINUE )
      {
         clear();
	      cout << "Copyright (C) 2016 - Dakota Barron" << endl << endl;

         // draw the current state of the hangman
         hangman.draw();

         cout << "\nGuess the word: ";
         
         /*
         for each letter in the word being played, output a '_' if the user
         has not guessed it yet. if the user has guessed that letter
         correctly, output that letter
         */
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

         cout << "\n\nPlease enter one letter, then press ENTER: ";
         int guess;
         guess = cin.get();
         
         // must validate user input, make sure it is alphabetical character

         if ( isalpha( guess ) )
         {
            if ( cin.get() != '\n' )
            {
               cin.ignore( 10000, '\n' );

			   cout << "\n\nINVALID INPUT";
               cout << "\nPress enter to continue...";
               cin.ignore( 10000, '\n' );
               continue;
            }
         }

         else if ( !( isalpha( guess ) ) )
         {
            if ( guess != '\n' )
               cin.ignore( 10000, '\n' );

			cout << "\n\nINVALID INPUT";
			cout << "\nPress enter to continue...";
            cin.ignore( 10000, '\n' );
            continue;
         }

         if ( isupper( guess ) )
            guess = tolower( guess );

         // make sure user does not guess same letter twice
         if ( letters[ static_cast< char >( guess ) ] )
         {
            cout << "\n\nYou have already guessed that letter\n";
            cout << "Press enter to continue...";
            cin.ignore( 10000, '\n' );
            continue;
         }

         else
         {
            /*
            if we get here we know the user entered a letter that has
            not been guessed yet
            */

            // so mark the letter as guessed
            letters[ static_cast< char >( guess ) ] = true;

            // if the letter is not in the word, add a part to the hangman
            if ((word.find(static_cast< char >(guess))) == string::npos)
               hangman.addPart();
         }
      
         // assume WIN status. might change below.
         status = WIN;

         for ( unsigned int i = 0; i < word.size(); ++i )
         {
            /*
            if user has not guessed all the letters in the word, then they
            must continue to play
            */
            if ( !( letters[ word[ i ] ] ) )
               status = CONTINUE;
         }

         // if user has had the max number of bad guesses, they lose
         if ( hangman.getParts() == MAX_MISSES )
            status = LOSE;
      }

      /*
      once the above loop is broken out of, we know the user has either
      won or lost
      */

      // display appropriate messages for winning and losing

      if ( status == LOSE )
      {
         clear();
         cout << "Copyright (C) 2016 - Dakota Barron" << endl << endl;
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
         cout << "Copyright (C) 2016 - Dakota Barron" << endl << endl;
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

      // used for input validation, assume input is not good
      bool goodResponse = false;

      /*
      ask user if they want to play again. only 'y' or 'n' (case insensitive)
      will be accepted as valid responses. loop until the user gives a valid
      response.
      */
      while ( !goodResponse )
      {
         cout << "\nPlay again? y/n: ";
         response = cin.get();
         
         if ( isalpha( response ) )
         {
            if ( cin.get() != '\n' )
            {
               clear();
               cout << "Copyright (C) 2016 - Dakota Barron" << endl << endl;
               cout << "\nPlease enter \"y\" or \"n\" immediately " 
                  "followed by RETURN";
               cin.ignore( 10000, '\n' );
               continue;
            }

            else if ( ( response != 'y' ) && ( response != 'n' )
                    && ( response != 'Y' ) && ( response != 'N' ) )
            {
               clear();
               cout << "Copyright (C) 2016 - Dakota Barron" << endl << endl;
               cout << "\nPlease enter \"y\" or \"n\" immediately "
                  "followed by RETURN";
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
            cout << "Copyright (C) 2016 - Dakota Barron" << endl << endl;
            cout << "\nPlease enter \"y\" or \"n\" immediately followed by "
            "RETURN";
            continue;
         }

      }

   } while ( response == 'y' || response == 'Y' );

   return 0;
}

// this function just shows the copyright notice when the game first starts
void start() 
{
   cout << "Copyright (C) 2016 Dakota Barron\n\n"
      << "This program comes with ABSOLUTELY NO WARRANTY;\n"
      << "This is free software, and you are welcome to redistribute it\n"
      << "under certain conditions; See the LICENSE file included\n"
      << "with this software or go to <https://www.gnu.org/licenses/gpl.txt> " 
         "for details." << endl;

   cout << "\nPress enter to continue...";

   while ( cin.get() != '\n' );

   return;
}

// this function clears the screen in a portable way
void clear()
{
   for (int i = 0; i < 100; ++i) // most portable way to clear the screen
      cout << endl;              // not dependent on system calls
   return;
}
