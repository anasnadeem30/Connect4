/**
* ENGG1110 Problem Solving by Programming
*
* Course Project
*
* I declare that the project here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* https://www.cuhk.edu.hk/policy/academichonesty/
*
* Student Name : ANAS NADEEM
* Student ID : 1155165228
* Class/Section : ENGG1110E
* Date : 01/12/2021
*/

#include <stdio.h>
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2



void initGameBoard(int gameBoard[6][7]) {

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            gameBoard[i][j] = 0;
        }
    }
}



void printGameBoard(int gameBoard[6][7]) {

int row, column;
    for(row = 0; row < 6 ; row=row+1) {
        for(column = 0; column < 7; column=column+1) {
            if (gameBoard[row][column] == 0)
                printf ("| ");
            if (gameBoard[row][column] == 1)
                printf ("|O");
            if (gameBoard[row][column] == 2)
                printf ("|X");
        }
    printf("|\n");
    }
printf (" 1 2 3 4 5 6 7 ");
printf ("\n");
}



void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {

    int place = 0;
    scanf("%d", &place);

    while (place < 1 || place > 7){
      printf ("Input out of range. Please input again: \n");
      scanf("%d", &place);}

    while (gameBoard[0][place-1] != 0){
      printf ("Column is full. Please input again: \n");
      scanf ("%d", &place);
      }

    for (int i = 5;  i>=0; i--){
        if (gameBoard[i][place-1] == 0){
                gameBoard[i][place-1] = mark;
                break;
        }
    }
}


int hasWinner (int gameBoard[6][7]){

for (int i = 0; i < 6; i++){


    for (int j = 0; j < 4; j++){
      if (gameBoard[i][j] == 1 && gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j] == gameBoard[i][j+2] && gameBoard[i][j] == gameBoard[i][j+3]){
        return 1;
      }

      if (gameBoard[i][j] == 2 && gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j] == gameBoard[i][j+2] && gameBoard[i][j] == gameBoard[i][j+3]){
        return 1;
      }
    }

  }

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 7; j++){


      if (gameBoard[i][j] == 1 && gameBoard[i][j]==gameBoard[i+1][j] && gameBoard[i][j]==gameBoard[i+2][j] && gameBoard[i][j]==gameBoard[i+3][j]){
        return 1;
      }


      if (gameBoard[i][j] == 2 && gameBoard[i][j]==gameBoard[i+1][j] && gameBoard[i][j]==gameBoard[i+2][j] && gameBoard[i][j]==gameBoard[i+3][j]){
        return 1;
      }
    }
  }

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 4; j++){


      if (gameBoard[i][j] == 1 && gameBoard[i][j]==gameBoard[i+1][j+1] && gameBoard[i][j]==gameBoard[i+2][j+2] && gameBoard[i][j]==gameBoard[i+3][j+3]){
        return 1;
      }


      if (gameBoard[i][j] == 2 && gameBoard[i][j]==gameBoard[i+1][j+1] && gameBoard[i][j]==gameBoard[i+2][j+2] && gameBoard[i][j]==gameBoard[i+3][j+3]){
        return 1;
      }
    }
  }

  for (int i = 0; i < 3; i++){
    for (int j = 3; j < 9; j++){


      if (gameBoard[i][j] == 1 && gameBoard[i][j]==gameBoard[i+1][j-1] && gameBoard[i][j]==gameBoard[i+2][j-2] && gameBoard[i][j]==gameBoard[i+3][j-3]){
        return 1;
      }

      if (gameBoard[i][j] == 2 && gameBoard[i][j]==gameBoard[i+1][j-1] && gameBoard[i][j]==gameBoard[i+2][j-2] && gameBoard[i][j]==gameBoard[i+3][j-3]){
        return 1;
      }
    }
  }
  return 0;
}


int isFull(int gameBoard[6][7]) {
  if (gameBoard[0][0] != 0 && gameBoard[0][1] != 0 && gameBoard[0][2] != 0 && gameBoard[0][3] != 0 && gameBoard[0][4] != 0 && gameBoard[0][5] != 0 && gameBoard[0][6] != 0 ){
    return 1;
  }
  else return 0;
}

void placeMarkByComputerPlayer(int gameBoard[6][7], int mark){
  for (int i = 5; i >= 0; i--){
    for (int j = 0; j <= 6; j++){
        if (gameBoard[i][j] != 0)
        continue;
        gameBoard[i][j] =mark;
        if (hasWinner(gameBoard) == 1){
          return;
        }
        else{
          gameBoard[i][j] = 0;
        }
    }
  }
  for (int i = 5; i>= 0; i--){
    for (int j = 0; j <= 6; j++){
      if (gameBoard[i][j] != 0)
      continue;
      gameBoard[i][j] = 1;

      if (hasWinner(gameBoard) == 1){
        gameBoard[i][j] = 2;
        return;
      }
      else {
        gameBoard[i][j] = 0;
      }
      break;
    }
  }
  if (hasWinner(gameBoard) != 1){
    for (int i = 5; i >= 0; i--){
      for (int j = 6; j>= 0; j--){
        if (gameBoard[i][j] == 0){
          gameBoard[i][j] = mark;
          return;
        }
      }
    }
  }
}


int main()
{

    int gameBoard[6][7];
    int currentPlayer;
    int gameContinue;
    int numOfHumanPlayers;


    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameContinue = 1;

        printf("Enter the number of human players [1-2]:\n");
        scanf("%d", &numOfHumanPlayers);



    if (numOfHumanPlayers == 2){

        while(gameContinue!=0){
            printGameBoard(gameBoard);

            if (hasWinner (gameBoard) == 1){
              printf ("Congratulations! Player 2 wins!");
              break;
            }

            if (isFull (gameBoard) == 1){
              printf ("Draw game. ");
              break;
            }

            printf("Player 1's turn:\n");
            placeMarkByHumanPlayer(gameBoard, CIRCLE);
            printGameBoard(gameBoard);

            if (hasWinner (gameBoard) == 1){
              printf ("Congratulations! Player 1 wins!");
              break;
            }

            if (isFull (gameBoard) == 1){
              printf ("Draw game. ");
              break;
            }

            printf("Player 2's turn:\n");
            placeMarkByHumanPlayer(gameBoard, CROSS);
        }
    }
    else if (numOfHumanPlayers == 1){
        while(gameContinue!=0){
            printGameBoard(gameBoard);

            if (hasWinner (gameBoard) == 1){
              printf ("Computer wins!");
              break;
            }

            if (isFull (gameBoard) == 1){
              printf ("Draw game. ");
              break;
            }

            printf("Player 1's turn:\n");
            placeMarkByHumanPlayer(gameBoard, CIRCLE);
            printGameBoard(gameBoard);

            if (hasWinner (gameBoard) == 1){
              printf ("Congratulations! Player 1 wins!");
              break;
            }

            if (isFull (gameBoard) == 1){
              printf ("Draw game. ");
              break;
            }

            printf ("Computer's turn: \n");
            placeMarkByComputerPlayer(gameBoard, CROSS);
          }
    }

    return 0;
}
