#include <iostream>
#include <time.h>

using namespace std;

int main() {
    srand((unsigned int)time(0));
    int iNumber[25] = {};
    
    // Put numbers between 1~25
    for (int i = 0; i < 25; i++) {
        iNumber[i] = i + 1;
    }
    
    //mix number
    int iTemp, idx1, idx2;
    for (int i = 0; i < 100; i++) {
        idx1 = rand() % 25;
        idx2 = rand() % 25;
        
        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }
    
    int iBingo = 0;
    
    while (true) {
        system("cls");
        
        // Print number 5 x 5 format
        for (int i=0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                
                if(iNumber[i * 5 + j] == INT_MAX)
                    cout << "*\t";
                else
                    cout << iNumber[i * 5 + j] << "\t";
            }
            cout << endl;
        }
        cout << "Bingo Line : " << iBingo << endl;
        
        // over 5 lines of bingo, Finish the game
        if(iBingo >= 5)
            break;
        cout << "Input a number (0 : exit) : ";
        int iInput;
        cin >> iInput;
        
        if(iInput == 0)
            break;
        else if(iInput < 1 || iInput > 25)
            continue;
        
        bool bAcc = true; // check the number that was already choosed, default is duplicated number so true
        
        //Check all of the number in table
        // and find the same number player choose
        for (int i =0; i < 25; i++) {
            // if find the same number
            // it is not duplicated number so bAcc is false
            if(iInput == iNumber[i]){
                bAcc = false;
                
                // To change number to '*', use special value ' INT_MAX '
                iNumber[i] = INT_MAX;
                
                //and then we don't need to find number anymore
                // so we exit the for iteration
                break;
            }
        }
        
        // if bAcc value is true, we cannot change the number to '*'
        // continue the while again
        if(bAcc)
            continue;
        
        //When we check the bingo line every time, we will count the bingo line with initializing
        iBingo = 0;
        
        //Check vertical, horizontal line
        int iStar1 = 0, iStar2 = 0;
        for (int i = 0; i < 5; i++) {
            // Before checking the one line, initialize star 0
            iStar1 = iStar2 = 0;
            
            for (int j = 0; j < 5; j++) {
                // Count the horizotal stars
                if(iNumber[i * 5 + j] == INT_MAX)
                    ++iStar1;
                
                // Count the vertical stars
                if(iNumber[j * 5 + i] == INT_MAX)
                    ++iStar2;
            }
            // after j for iteration, we can put the horizontal star in iStar1 variable
            // if iStar1 is 5, we can guess this line is bingo
            if(iStar1 == 5)
                ++iBingo;
            
            if(iStar2 == 5)
                ++iBingo;
        }
        // From left-top size to right-bottom bingo line check
        iStar1 = 0;
        for (int i = 0; i < 25; i += 6) {
            if(iNumber[i] == INT_MAX)
                ++iStar1;
        }
        if(iStar1 == 5 )
            ++iBingo;
        // From right-top size to left-bottom bingo line check
        iStar1 = 0;
        for (int i = 4; i <=20; i +=4) {
            if(iNumber[i] == INT_MAX)
                ++iStar1;
        }
        if(iStar1 == 5)
            ++iBingo;
    }
    
    
    return 0;
}
