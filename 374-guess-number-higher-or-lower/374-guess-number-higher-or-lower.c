/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n)
{
	unsigned int l = 1, r = n;
    
    while (n = guess((l + r + 1) / 2))
        if (n < 0)
            r = (l + r + 1) / 2 - 1;
        else
            l = (l + r + 1) / 2 + 1;
    
    return ((l + r + 1) / 2);
}