#include <cstdlib>
#include <iostream>

using namespace std;

//Function prototypes
void fillArr(char **&, int, int, int, int);
void output(char **, int, int);
void delArr(char **&, int);

int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned>(time(0)));

    //Declare and initialize variables
    int row = 20, col = 20;//Length and width
    int numStars = 50;//Number of stars to show in image
    int noise = 3;//Max magnitude of noise
    char **img;//The image

    //Fill array
    fillArr(img, row, col, numStars, noise);

    //Output array
    output(img, row, col);

    //Delete image
    delArr(img, row);

    //A Sebastian Production
    return 0;
}

void fillArr(char **& img, int row, int col, int numStars, int noise) {
    //Create image
    img = new char*[row];
    for(int i = 0; i < row; ++i) {
        img[i] = new char[col];
    }

    //Fill with noise
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            img[i][j] = rand() % noise + '0';//Noise, 0-2 char
        }
    }

    //Fill with stars
    for(int i = 0; i < numStars; ++i) {
        int n = rand() % row;
        int m = rand() % col;
        if(img[n][m] > '0' + noise) i--;
        else img[n][m] = '3'+71;//Stars
    }
}

void delArr(char **& img, int row) {
    for(int i = 0; i < row; ++i) {
        delete [] img[i];
    }
    delete [] img;
}

void output(char **img, int row, int col) {
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            cout<<img[i][j]<<" ";
        }
        cout<<endl;
    }
}