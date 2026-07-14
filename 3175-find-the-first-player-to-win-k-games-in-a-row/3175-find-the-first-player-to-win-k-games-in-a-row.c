int findWinningPlayer(int* skills, int skillsSize, int k) {

    int champion = 0;
    int wins = 0;

    for (int i = 1; i < skillsSize; i++) {

        if (skills[champion] > skills[i]) {

            wins++;

        } else {

            champion = i;
            wins = 1;
        }

        if (wins >= k) {
            return champion;
        }
    }

    return champion;
}