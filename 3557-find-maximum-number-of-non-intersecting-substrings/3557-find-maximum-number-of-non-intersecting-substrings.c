int maxSubstrings(char *word)
{
    int first[26];

    for (int i = 0; i < 26; i++)
        first[i] = -1;

    int answer = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int c = word[i] - 'a';

        /*
            First occurrence of this character.
        */

        if (first[c] == -1)
        {
            first[c] = i;
        }
        else
        {
            /*
                Need at least 4 characters.

                length = i - first[c] + 1

                Therefore:

                i - first[c] >= 3
            */

            if (i - first[c] >= 3)
            {
                answer++;

                /*
                    We selected a substring ending at i.

                    Everything before/equal to i is
                    no longer available for another
                    substring.

                    Reset the starting positions.
                */

                for (int j = 0; j < 26; j++)
                    first[j] = -1;
            }
        }
    }

    return answer;
}