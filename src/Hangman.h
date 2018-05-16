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


// This class is used to represent the hangman figure
// that is drawn before every player move

#ifndef HANGMAN_H
#define HANGMAN_H

class Hangman
{
public:
   explicit Hangman( int = 0 );
   void draw() const; // draw the hangman
   int getParts() const; // get the number of parts the hangman currently has
   void addPart(); // add another part to the hangman;

private:
   int parts; // number of body parts the hangman currently has
};

#endif