/************************************************************
	Filename:      Pokemon.h
	Author:        Mohammed Alturki
	Date Created:  4/1/2021
	Purpose:       Class file for Pokemon and overloaded operators
*************************************************************/
#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>
using namespace std;

class Pokemon
{
    private:
        int pokemonID;
        string pokemonName;

    public:
        //constructor with default arguments
        Pokemon(int ppokemonID = 0, string ppokemonName = "None")
        {
            pokemonID = ppokemonID;
            pokemonName = ppokemonName;
        }

        void setID(int id)
        {
            pokemonID = id;
        }
        void setName(string n)
        {
            pokemonName = n;
        }

        int getID()
        {
            return pokemonID;
        }

        string getName()
        {
            return pokemonName;
        }

        //< overloaded operator to be able to insert in binary search tree & search
        bool operator < (const Pokemon &p)
        { 
            return pokemonID < p.pokemonID;
        }
        
        //<< overloaded operator for printing Pokemon
        friend ostream &operator << (ostream &strm, Pokemon &p)
        {

            strm << "Pokemon Index Number: " << p.pokemonID << " \t ";
            strm << " Name: " << p.pokemonName;
            return strm;
        }

        //== overloaded operator to be able to search
        bool operator ==(const Pokemon& p)
		{
			if(this->pokemonID == p.pokemonID)
				return true;
			else
				return false;
		}
};

#endif