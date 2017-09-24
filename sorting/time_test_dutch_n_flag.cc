string DutchFlagSort(string strColoredBalls) {
    int size = strColoredBalls.size();
    int nonB = size - 1;
    int nonR = 0;

    
    while (strColoredBalls[nonB] == 'B') {
        nonB--;
    }
    while (strColoredBalls[nonR] == 'R') {
        nonR++;
    }
    int i = nonR;
    

    
    while (i <= nonB) {
        if (strColoredBalls[i] == 'B') {
            swap(strColoredBalls[i], strColoredBalls[nonB]);
            nonB--;
        } else if (strColoredBalls[i] == 'R') {
            swap(strColoredBalls[i], strColoredBalls[nonR]);
            nonR++;            
        }
        if (strColoredBalls[i] == 'G') {
            i++;
        }
        while (strColoredBalls[nonB] == 'B') {
            nonB--;
        }
        while (strColoredBalls[nonR] == 'R') {
            nonR++;
        }
    }
    

    return strColoredBalls;
}

