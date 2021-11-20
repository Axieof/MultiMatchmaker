# MultiMatchmaker

MultiMatchmaker is a **C++** project for a school assignment. It allows users to choose or create a player to play with, 
and match-make against other players in the system. There is no game for the players to play, as the 
winner is randomly assigned. The main purpose of this assignment is to make use of data structures 
to create a matchmaking algorithm.

# Description

This project makes use of a linked list implementation for the basic matchmaking algorithm.
It also features a **custom Web data structure** created by **Pritheev** AKA [@Axieof](https://github.com/Axieof "Pritheev's Profile") and **Caleb** AKA [@calebanana](https://github.com/calebanana "Caleb's Profile"), which is based 
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

The user will be greeted with a menu as such on the terminal

![image](https://user-images.githubusercontent.com/29113995/142734932-76ea7431-7bd7-47d3-bafc-cdd51c951ed2.png)

  * Option 0) Exit Application

Option 0 is to be used when you desire to leave the game and exit the application.

![image](https://user-images.githubusercontent.com/29113995/142735026-06f6cf34-b000-4245-abc1-79484e51b677.png)

  * Option 1) Create New Account

Option 1 is to allow the user to create an account, which will prompt the user to enter a username which will then be used to create a player class with initialized statistics.

![image](https://user-images.githubusercontent.com/29113995/142735036-ba16fbf8-6eed-4dd1-9a7d-dc3a73a5a6ce.png)

The user might be greeted with an error if an account username entered were to be conflicting with an existing username in the system, providing the message a new account created unsuccessfully. Upon seeing the message, the user can attempt option 1 again but enter a different username as each username needs to be unique.

![image](https://user-images.githubusercontent.com/29113995/142735049-0cab61eb-b7c2-4716-9a5b-924a07d29f42.png)

  * Option 2) Select Existing Account

Option 2 is for the user to select an existing account from the system. Upon entering option 2, the user is greeted with a menu displaying all current accounts in the system and a prompt to enter a username of the account they selected. The user is then to enter a username of an account they desire to use.

![image](https://user-images.githubusercontent.com/29113995/142735065-d3474b5a-6bde-4cbd-bfda-0a435e8dedd8.png)

  * Option 3) View Account Statistics

Option 3 is to be used when the user wants to view the statistics of their current player if an account was created (Option 1) or an account was selected (Option 2).

![image](https://user-images.githubusercontent.com/29113995/142735076-5cb00eef-1d86-46e2-862d-42b6b4b34354.png)

If the user does not have an account, the system would prompt them to select Option 1 or 2.

![image](https://user-images.githubusercontent.com/29113995/142735089-f36a3857-b4dd-42d0-84b2-c884c718f999.png)

  * Option 4) Join Queue

Option 4 is for user to be able to join the queue, where the user will be prompted to select a champion, where they enter a number from a menu displayed, upon where they will be placed into the queue. The system would also attempt to matchmake the player upon entry into the queue, with a success message if successful or unsuccessful message if unsuccessful.

![image](https://user-images.githubusercontent.com/29113995/142735103-bd5b8c3d-2f23-4803-932f-245b596f440a.png)

![image](https://user-images.githubusercontent.com/29113995/142735190-64a8dd4b-3693-4c20-a433-cc82247229e3.png)

  * Option 5) View Queue Status

Option 5 is to view the queue status, such as whether the current player is in the queue or not, and number of players within the queue as well as a display of their names and their champions.

![image](https://user-images.githubusercontent.com/29113995/142735204-4d038a6c-520d-47bf-8383-e446297bc0d6.png)

![image](https://user-images.githubusercontent.com/29113995/142735211-9c1f78df-62f1-4c1f-8893-c8796c403fb0.png)

![image](https://user-images.githubusercontent.com/29113995/142735216-30cedb0e-676b-4c4e-aff0-2625bd889b01.png)

  * Option 6) Change Champion

Option 6 is for the user to change champion if they wish to do so, but they will be kicked from the queue and will have to re-queue. The user will be prompted with a message to confirm whether they want to leave the queue to change champion and the user needs to reply with a Y for yes and N for no. Upon Y selected, the user will be presented with the champion selection screen, where they will be joined back to the queue after.

![image](https://user-images.githubusercontent.com/29113995/142735234-7df65b5e-ec11-486c-a4da-5a8862a76d3c.png)

  * Option 7) Leave The Queue

Option 7 is for the user to be able to leave the queue, where they will be prompted with a message and a reply of Y for yes and N for no.

![image](https://user-images.githubusercontent.com/29113995/142735262-b454a622-d817-4272-9cd0-bf8cc0d055c0.png)

  * Option 8) Initialize List Data

Option 8 is an initialization function that initializes some fake data into the system to replicate an online match with other users.

  * Option 9) Join Queue (Web Data Structure)

Option 9 is for the user to join the queue that utilizes the web matchmaking algorithm.

![image](https://user-images.githubusercontent.com/29113995/142735348-37bfde4a-6e75-40a8-b84a-873a232ff0b1.png)

  * Option 10) View Queue Status (Web Data Structure)

Option 10 is for the user to view the queue status of the web matchmaking algorithm, similar to Option 5.

  * Option 11) Print Chain

Option 11 is for the user to print the chain of a champion they select. The chain is the alternate linked list feature introduced into the web data structure.

![image](https://user-images.githubusercontent.com/29113995/142735374-0770f7a8-f053-4d0a-bd4e-9e0318766940.png)

  * Option 12) Initialize Web Data

Option 12 is for the user to initialize fake data into the web matchmaking algorithm to replicate users in a real online match.
