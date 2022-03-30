/************************************************************
	Filename:      program3.cpp
	Author:        Mohammed Alturki
	Date Created:  4/1/2021
	Purpose:       Driver for reading from the file and inserting Pokemon in a BST
*************************************************************/
#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "Pokemon.h"

using namespace std;

int main()
{
    BinaryTree<Pokemon> tree;
    ifstream inFile;
    string temp;
    int numPokemon = 0;
    int pokemonID;
    string pokemonName;
    

    inFile.open("pokedex.txt");
    if(!inFile)
    {
        cout << "\nSorry, I was unable to open the file." << endl;
    }
    else    
    {  
        //reading from the file
        while(getline(inFile, temp, '#'))
        {
            pokemonID = stoi(temp);              //store it in temp

            getline(inFile, temp, '#');   //reading from the file
            pokemonName = temp;     //store in temp

            //creating a new Pokemon object
            Pokemon p = Pokemon(pokemonID, pokemonName);
            //if the Pokemon is a dublicate
            if(tree.searchNode(p))
            {
                cout << "Oops!  The Pokemon with index " << pokemonID << " is already in the Pokedex\n";
            }
            else
            {
                tree.insertNode(p); 
                numPokemon++;
            }   
        }
        cout << endl << numPokemon << " Pokemon have been added to the Podedex!\n\n";
    }

    //displaying Pokemons in order traversal
    cout << "\n*******************POKEDEX:********************\n\n\n";
    tree.displayInOrder();
}