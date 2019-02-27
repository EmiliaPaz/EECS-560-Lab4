/*
  File Name: Executive.cpp
  Author: Emilia Paz Ojeda
  KUID: 2889275
  Email Address: emilia.paz@ku.edu
  Description:  Cpp file for Executive class.
                Reads the file and initializes the linked list
                Prints the menu and loops through the options
  Last Changed: February 4th, 2019
*/

#include "Executive.h"
#include "HashTable_Open.h"
#include "HashTable_Closed.h"
#include "ItemNotFoundException.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <stdlib.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////
//////////                    Constructors                            //////////
////////////////////////////////////////////////////////////////////////////////
Executive::Executive(char* fileName)
{
    printMenu();
}

////////////////////////////////////////////////////////////////////////////////
//////////                     Destructor                             //////////
////////////////////////////////////////////////////////////////////////////////
Executive::~Executive()
{

}


////////////////////////////////////////////////////////////////////////////////
//////////                      Methods                               //////////
////////////////////////////////////////////////////////////////////////////////
void Executive::printMenu()
{
    int option=0;
    while(option!=3)
    {
        std::cout << "------------------------------------------------------------ \n \n"
                  << "Please choose one of the following commands: \n"
                  << "1. Test HashTables \n"
                  << "2. Performance Comparison \n"
                  << "3. Exit \n \n";
        std::cout << "Select an option: ";
        std::cin >> option ;
        // Invalid option input
        while (std:: cin.fail() || option<1 || option>3)
        {
            std:: cin.clear() ;
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            std::cout << "Sorry, your input did not seem to be valid. Try again: ";
            std::cin >> option;
        }

        // 1. Insert
        if(option==1)
        {
            std::ifstream inFile;
            inFile.open("test.txt");
            if(inFile.is_open())
            {
                int input=0;
                // Get size
                HashTable_Open<int> * HT_open = new HashTable_Open<int>(7);
                HashTable_Closed<int> * HT_closed_qp = new HashTable_Closed<int>(7,'q',5,10);
                HashTable_Closed<int> * HT_closed_dh = new HashTable_Closed<int>(7,'d',5,10);

                // Get every number from the text file
                while (inFile >> input)
                {
                    HT_open->insert(input);
                    HT_closed_qp->insert(input);
                    HT_closed_dh->insert(input);
                }

                std::cout << "Open Hashing: \n";
                HT_open->print();
                std::cout << "Hash Table with Quadratic Probing: \n";
                HT_closed_qp->print();
                std::cout << "Hash Table with Double Hashing: \n";
                HT_closed_dh->print();

                delete HT_open;
                delete HT_closed_qp;
                delete HT_closed_dh;

                inFile.close();
            }
            else
            {
                std::cout << "No test file \n";
            }

        }

        // 2. Performance comparison
        else if(option==2)
        {
            int m = 1000003;
            int R = 100003;
            int k = 20;
            int num;

            std::ofstream outFile;
            outFile.open("results.txt");

            // Declare hashtables
            HashTable_Open<int> * HT_open = nullptr;
            HashTable_Closed<int> * HT_closed_qp = nullptr;
            HashTable_Closed<int> * HT_closed_dh = nullptr;

            // Declare results grid
            float ** results_o = new float*[3];
            float ** results_qp = new float*[3];
            float ** results_dh = new float*[3];
            for(int i=0; i<3; i++)
            {
                results_o[i] = new float[5];
                results_qp[i] = new float[5];
                results_dh[i] = new float[5];
            }

            // Initialize results grid
            for(int x=0; x<3; x++)
            {
                for(int y=0; y<5; y++)
                {
                    results_o[x][y] = 0 ;
                    results_qp[x][y] = 0 ;
                    results_dh[x][y] = 0 ;
                }
            }


            clock_t t;
            srand(time(NULL));

            // 0.1m , 0.2m, 0.3m, 0.4m, 0.5m different random numbers
            for(int i=1; i<=5; i++)
            {
                // Repeat 5 times
                for(int j=1; j<=5; j++)
                {
                    int kInsert = 0.1*m*i;
                    // Create tables
                    HT_open = new HashTable_Open<int>(m);
                    HT_closed_qp = new HashTable_Closed<int>(m,'q',R,k);
                    HT_closed_dh = new HashTable_Closed<int>(m,'d',R,k);

                    bool unique = true;
                    float t_o=0, t_qp=0, t_dh=0;
                    // 1. Insert 0.1m random numbers into the tables
                    for(int k=1; k<=kInsert; k++)
                    {
                        // generate a random number between 1 and 5m inclusively
                        num = rand() % (5*m) + 1;
                        if(HT_closed_dh->find(num))
                        {
                            // Duplicate number
                            k--;
                            unique = false;
                        }
                        else
                        {
                            unique = true;
                        }

                        if(unique)
                        {
                            ////////// Insert random number ////////////
                            // Open
                            t = clock();
                            HT_open->insert(num);
                            t_o = t_o + clock() - t;

                            // Quadratic probing
                            t = clock();
                            HT_closed_qp->insert(num);
                            t_qp = t_qp + clock() - t;

                            // Double hashing
                            t = clock();
                            HT_closed_dh->insert(num);
                            t_dh = t_dh + clock() - t;
                        }
                    }

                    float t_o_find_s=0, t_o_find_u=0;
                    float t_qp_find_s=0, t_qp_find_u=0;
                    float t_dh_find_s=0, t_dh_find_u=0;
                    int kFind = 0.01*m*i;
                    // 2. Generate 0.01m random numbers and find them in the tables
                    for(int k=1; k<=kFind; k++)
                    {
                        // generate a random number between 1 and 5m inclusively
                        num = rand() % (5*m) + 1;
                        ////////// Find random number ////////////
                        // Open
                        t = clock();
                        // Succesful
                        if(HT_open->find(num))
                        {
                            t_o_find_s = t_o_find_s + clock() - t;
                        }
                        // Unsuccesful
                        else
                        {
                            t_o_find_u = t_o_find_u + clock() - t;
                        }

                        // Quadratic probing
                        t = clock();
                        // Succesful
                        if(HT_closed_qp->find(num))
                        {
                            t_qp_find_s = t_qp_find_s + clock() - t;
                        }
                        // Unsuccesful
                        else
                        {
                            t_qp_find_u = t_qp_find_u + clock() - t;
                        }

                        // Double hashing
                        t = clock();
                        // Succesful
                        if(HT_closed_dh->find(num))
                        {
                            t_dh_find_s = t_dh_find_s + clock() - t;
                        }
                        // Unsuccesful
                        else
                        {
                            t_dh_find_u = t_dh_find_u + clock() - t;
                        }

                    }
                    t_o = t_o/CLOCKS_PER_SEC*1000;
                    t_o_find_s = t_o_find_s/CLOCKS_PER_SEC * 1000;
                    t_o_find_u = t_o_find_u/CLOCKS_PER_SEC * 1000;
                    t_qp = t_qp/CLOCKS_PER_SEC*1000;
                    t_qp_find_s = t_qp_find_s/CLOCKS_PER_SEC * 1000;
                    t_qp_find_u = t_qp_find_u/CLOCKS_PER_SEC * 1000;
                    t_dh = t_dh/CLOCKS_PER_SEC*1000;
                    t_dh_find_s = t_dh_find_s/CLOCKS_PER_SEC * 1000;
                    t_dh_find_u = t_dh_find_u/CLOCKS_PER_SEC * 1000;


                    outFile << kInsert << " test #:" << j << "\n";
                    outFile << "OPENHASHING build: " << t_o << " found: " << t_o_find_s << "  not-found: " << t_o_find_u << "\n";
                    outFile << "QUADRATICPROBING: build: " << t_qp << " found: " << t_qp_find_s << "  not-found: " << t_qp_find_u << "\n";
                    outFile << "DOUBLEHASHING: build: " << t_dh << " found: " << t_dh_find_s << "  not-found: " << t_dh_find_u << "\n";
                    outFile << "\n";
                    // Open Hashing
                    results_o[0][i-1] = results_o[0][i-1] + t_o;
                    results_o[1][i-1] = results_o[1][i-1] + t_o_find_s;
                    results_o[2][i-1] = results_o[2][i-1] + t_o_find_u;

                    // Quadratic Probing
                    results_qp[0][i-1] = results_qp[0][i-1] + t_qp;
                    results_qp[1][i-1] = results_qp[1][i-1] + t_qp_find_s;
                    results_qp[2][i-1] = results_qp[2][i-1] + t_qp_find_u;

                    // Double Hashing
                    results_dh[0][i-1] = results_dh[0][i-1] + t_dh;
                    results_dh[1][i-1] = results_dh[1][i-1] + t_dh_find_s;
                    results_dh[2][i-1] = results_dh[2][i-1] + t_dh_find_u;

                    // Delete tables
                    delete HT_open;
                    delete HT_closed_qp;
                    delete HT_closed_dh;
                }
                // Average Open Hashing
                results_o[0][i-1] = results_o[0][i-1] / 5;
                results_o[1][i-1] = results_o[1][i-1] / 5;
                results_o[2][i-1] = results_o[2][i-1] / 5;
                // Average Quadratic Probing
                results_qp[0][i-1] = results_qp[0][i-1] / 5;
                results_qp[1][i-1] = results_qp[1][i-1] / 5;
                results_qp[2][i-1] = results_qp[2][i-1] / 5;
                // Average Double Hashing
                results_dh[0][i-1] = results_dh[0][i-1] / 5;
                results_dh[1][i-1] = results_dh[1][i-1] / 5;
                results_dh[2][i-1] = results_dh[2][i-1] / 5;
            }

            std::cout << "\n Open Hashing \n";
            printGrid(results_o);

            std::cout << "\n Quadratic Probing \n";
            printGrid(results_qp);

            std::cout << "\n Double Hashing \n";
            printGrid(results_dh);


            // Delete results grids
            deleteGrid(results_o);
            deleteGrid(results_dh);
            deleteGrid(results_qp);
        }

    }
    std::cout << "Done! \n";

}


void Executive::printGrid(float** grid)
{
    std::string options[3] = {"Build    ","Found    ","Not found"};
    for(int x=0; x<3; x++)
    {
        std::cout << options[x] << ": ";
        for(int y=0; y<5; y++)
        {
            std::cout << grid[x][y] << " " ;
        }
        std::cout << "\n";
    }
}

void Executive::deleteGrid(float** grid)
{
    for(int i=0; i<3; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
}
