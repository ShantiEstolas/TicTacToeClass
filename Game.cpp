#include "Game.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::initialize()
{
    turnCounter=0;
    cout << "initializing...\n";
    m_board.initialize();
    m_p1.setName("Tikoy");
    m_p1.setIcon('+');
    m_p2.setName("Bert");
    m_p2.setIcon('*');

    cout << "Player 1: " << m_p1.getName() << endl;
    cout << "Player 2: " << m_p2.getName() << endl;


    m_currentPlayer = &m_p1;
    m_board.render();

}

void Game::update()
{
    turnCounter+=1;
    bool gameUpdater;
    m_isComplete = checkWin();

    if (!m_isComplete){

        if(turnCounter==10)
        {
            if(m_isComplete==false)
            {
                    cout<< "Game Over!.\nTie.";
                    exit(0);
            }
        }

        else
        {

            gameUpdater =  m_board.update(m_currentPlayer->getMove(), m_currentPlayer->getIcon());
            if (gameUpdater){
                render();
                cout << "updating...\n";
                switchPlayer();
                cout << "Switching player...\n";
            }

            else
            {
                turnCounter-=1;
                render();
                cout << "Invalid move!\n";
            }
        }

    }

    else
    {

        switchPlayer();
        cout << "Game over.\n";

        if (m_currentPlayer == &m_p1)
        {
            cout << "Player 1 win.\n";
        }

        else
        {
            cout << "Player 2 win.\n";
        }

    }

}

void Game::render()
{
    //m_board.initialize();
    m_board.render();
}

bool Game::checkWin()
{


    if ((m_board.box[0] == m_board.box[1]) && (m_board.box[1] == m_board.box[2]))
        return true;
    else if ((m_board.box[3] == m_board.box[4]) && (m_board.box[4] == m_board.box[5]))
        return true;
    else if ((m_board.box[6] == m_board.box[7]) && (m_board.box[7] == m_board.box[8]))
        return true;
    else if ((m_board.box[0] == m_board.box[3]) && (m_board.box[3] == m_board.box[6]))
        return true;
    else if ((m_board.box[1] == m_board.box[4]) && (m_board.box[4] == m_board.box[7]))
        return true;
    else if ((m_board.box[2] == m_board.box[5]) && (m_board.box[5] == m_board.box[8]))
        return true;
    else if ((m_board.box[0] == m_board.box[4]) && (m_board.box[4] == m_board.box[8]))
        return true;
    else if ((m_board.box[2] == m_board.box[4]) && (m_board.box[4] == m_board.box[6]))
        return true;
    else
        return false;
}

void Game::switchPlayer()
{
    if (m_currentPlayer == &m_p1)
    {
        m_currentPlayer = &m_p2;
    }

    else if (m_currentPlayer == &m_p2)
    {
        m_currentPlayer = &m_p1;
    }
}

void Game::run()
{
    m_isComplete = checkWin();
    while (!m_isComplete)
    {
        update();
    }
}

