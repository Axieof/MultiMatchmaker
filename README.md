# MultiMatchmaker

MultiMatchmaker is a C++ project for a school assignment. It allows users to choose or create a player to play with, 
and match-make against other players in the system. There is no game for the players to play, as the 
winner is randomly assigned. The main purpose of this assignment is to make use of data structures 
to create a matchmaking algorithm.

# Description

This project makes use of a linked list implementation for the basic matchmaking algorithm.
It also features a custom Web data structure created by **Pritheev** AKA [@Axieof](https://github.com/Axieof "Pritheev's Profile") and **Caleb** AKA [@calebanana](https://github.com/calebanana "Caleb's Profile"), which is based 
off a linked list, for a more efficient version of the matchmaking algorithm.

# Application

The application allows users to have an account with statistics such as username, matches won, lost and win rate. Players are given the option to join the matchmaking queue, where they will be first given the option to pick from seven different champion types. After champion selection, players are put into a matchmaking queue which will assign them into teams of two based on champion type.
The application makes use of hash tables to hash and store the players as well as a linked list to act as a queue for players.

# Data Structures

1. Hash Table

   - A hash table is used to store various objects, so as to make searching for objects faster and more efficient   
![alt text](https://github.com/Axieof/MultiMatchmaker/blob/master/Images/HashTable.png "Hash Table Visualization")

3. Linked list

   - A linked list is used to store the players in nodes, and the program uses it as a basic matchmaking system by traversing through and finding the best match for a player who just entered the match   
![alt text](https://github.com/Axieof/MultiMatchmaker/blob/master/Images/LinkedList.png "Linked List Visualization")
   
5. Web

   - A custom advanced linked list that stores players similarly to the basic implementatin, but also stores in extending links information such as the next player with the same champion   
![alt text](https://github.com/Axieof/MultiMatchmaker/blob/master/Images/Web.png "Web Visualization")  

## Usage

  * Step 1) Clone the repository
  * Step 2) Run the program
  * Step 3) Follow the steps on the Main Menu UI to use the system

## Options

TODO - Include instructions adn descriptions on what each option does.
