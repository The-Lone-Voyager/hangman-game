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


// This class is used solely to read in a word
// from the binary "words.dat" file that contains
// all the words that could be chosen as the current
// word to guess

#include <string>

#ifndef WORD_H
#define WORD_H

class Word
{
public:
   Word( const std::string &n = "" )
   {
      n.copy( w, n.size() );
      w[ n.size() ] = '\0';
   }

   const char *getWord() const
   {
      return w;
   }

private:
   char w[ 11 ];
};

#endif