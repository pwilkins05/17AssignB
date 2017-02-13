#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>


/*******************************
 *
 * Yahtzee
 *
 * Starter code by Paul Wilkins
 * Last Modified: 02/04/2014
 *
 *******************************/

// TODO: switch to using arrays for scores
// TODO switch to using array for dice
// TODO: add yahtzee bonus score (Attempted by Liam - full implementation of scoreYahtzee function.)
// TODO: implement scoring functions (see switch statement, line 125)
// TODO: make ask reroll accept lowercase letters (attempted solution by Aaron)
// BUG: dice not holding correct values

using namespace std;

void printRoll(int n1, int n2, int n3, int n4, int n5);
bool askReroll(int n);
void printSeparator();
void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
                int fivesScore, int sixesScore, int threeOfAKind,
                int fourOfAKind, int fullHouse, int smallStraight,
                int largeStraight, int yahtzee, int chance);
void printScoreLine(string name, int score);
int getScoreOption(int onesScore, int twosScore, int threesScore, int foursScore,
                   int fivesScore, int sixesScore, int threeOfAKind,
                   int fourOfAKind, int fullHouse, int smallStraight,
                   int largeStraight, int yahtzee, int chance);
int tabulateDice(int n, int d1, int d2, int d3, int d4, int d5);
int scoreOnes(int o);
int scoreYahtzee(int ones, int twos, int threes, int fours,
                 int fives, int sixes, int previousYahtzee,
                 bool isBonus); //Liam's implementation w/ yahtzee bonus.


const int NUM_CATEGORIES = 13;
const int SIDES = 6;
const int EMPTY = -1;
enum Category { ONES = 1, TWOS, THREES, FOURS, FIVES, SIXES, THREE_OF_A_KIND,
                    FOUR_OF_A_KIND, FULL_HOUSE, SMALL_STRAIGHT, LARGE_STRAIGHT,
                    YAHTZEE, CHANCE };

int main()
{

    int dice [5] = { die1, die2, die3, die4, die5 };    //put dice into an array
    bool redo1, redo2, redo3, redo4, redo5;
    bool bonus = false; //haven't had any yahtzees yet.

    int ones, twos, threes, fours, fives, sixes;

    int onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore;
    int threeOfAKind;
    int fourOfAKind;
    int fullHouse;
    int smallStraight;
    int largeStraight;
    int yahtzee = 0;
    int chance;

    onesScore = twosScore = threesScore = foursScore = fivesScore = sixesScore = EMPTY;
    threeOfAKind = fourOfAKind = fullHouse = smallStraight = largeStraight = yahtzee = chance = EMPTY;

    cout << "Welcome to Yahtzee!" << endl;
    srand(time(0));


//Altered formulas used to obtain values by adding 1 to account for possible 0 remainder from Modulus Operation.
    for (int turn = 0; turn < NUM_CATEGORIES; turn++)
    {
        int round = 1;
        ones = twos = threes = fours = fives = sixes = 0;
        die1 = rand() % SIDES + 1;
        die2 = rand() % SIDES + 1;
        die3 = rand() % SIDES + 1;
        die4 = rand() % SIDES + 1;
        die5 = rand() % SIDES + 1;

        printRoll(dice);     //hoping that this successfully rolls the dice

        do
        {
            redo1 = askReroll(1);
            redo2 = askReroll(2);
            redo3 = askReroll(3);
            redo4 = askReroll(4);
            redo5 = askReroll(5);

            if (redo1)
            {
                die1 = rand() % SIDES + 1;
            }
            if (redo2)
            {
                die2 = rand() % SIDES + 1;
            }
            if (redo3)
            {
                die3 = rand() % SIDES + 1;
            }
            if (redo4)
            {
                die4 = rand() % SIDES + 1;
            }
            if (redo5)
            {
                die5 = rand() % SIDES + 1;
            }

            printRoll(dice);      //Again, replaced list of dice with the array
            round++;
        } while ((redo1 || redo2 || redo3 || redo4 || redo5) && round < 3);

        ones = tabulateDice(1, dice);            // cleaned up more lists of dice
        twos = tabulateDice(2, dice);            // with the array
        threes = tabulateDice(3, dice);
        fours = tabulateDice(4, dice);
        fives = tabulateDice(5, dice);
        sixes = tabulateDice(6, dice);

        int scoreOption = getScoreOption(onesScore, twosScore, threesScore, foursScore,
                                         fivesScore, sixesScore, threeOfAKind,
                                         fourOfAKind, fullHouse, smallStraight,
                                         largeStraight, yahtzee, chance);


		/*
			I am not very good with cpp but I think this should work
			The score ones takes the tabulateDice and mulitplies it by 1 since that is the value
			of the dice being tabulated.
		*/

        switch (scoreOption)
        {
            case ONES:
                onesScore = scoreOnes(ones);
                break;
		/*
            case TWOS:
                twosScore = scoreTwos(ones, twos, threes, fours, fives, sixes);
                break;
            case THREES:
                threesScore = scoreThrees(ones, twos, threes, fours, fives, sixes);
                break;
            case FOURS:
                foursScore = scoreFours(ones, twos, threes, fours, fives, sixes);
                break;
            case FIVES:
                fivesScore = scoreFives(ones, twos, threes, fours, fives, sixes);
                break;
            case SIXES:
                sixesScore = scoreSixes(ones, twos, threes, fours, fives, sixes);
                break;
            case THREE_OF_A_KIND:
                threeOfAKind = scoreThreeOfAKind(ones, twos, threes, fours, fives, sixes);
                break;
            case FOUR_OF_A_KIND:
                fourOfAKind = scoreFourOfAKind(ones, twos, threes, fours, fives, sixes);
                break;
            case FULL_HOUSE:
                fullHouse= scoreFullHouse(ones, twos, threes, fours, fives, sixes);
                break;
            case SMALL_STRAIGHT:
                smallStraight = scoreSmallStraight(ones, twos, threes, fours, fives, sixes);
                break;
            case LARGE_STRAIGHT:
                largeStraight = scoreLargeStraight(ones, twos, threes, fours, fives, sixes);
                break; */
            case YAHTZEE:
                yahtzee = scoreYahtzee(ones, twos, threes, fours, fives, sixes, yahtzee, bonus);
                if(yahtzee > 0)
                    bonus = true;
                //Technically, by  official yahtzee rules, you also score in another category in addition to bonus yahtzee points but that would require a very different approach.
                //if someone wants to try implementing that ruleset go ahead.
                break;
        }
            /*case CHANCE:
                chance = scoreChance(ones, twos, threes, fours, fives, sixes);
                break;

        }*/

        printScore(onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore,
                   threeOfAKind, fourOfAKind, fullHouse, smallStraight, largeStraight, yahtzee, chance);
    }
}

/*********************************************************
 *
 * Score Option methods
 * ------------------
 * This function calculates the score for the dice rolled.
 *
 *********************************************************/
int scoreOnes(int o)
{
	return 1 * o;
}

/*********************************************************
 *
 * scoreYahtzee
 * ------------------
 * This function determines if dice are a yahtzee
 * and if that yahtzee is a yahtzee bonus,
 * then returns the new yahtzee score.
 *
 *********************************************************/
int scoreYahtzee(int ones, int twos, int threes, int fours, int fives, int sixes, int previousYahtzee, bool isBonus)
{
    if(ones == 5 || twos == 5 || threes == 5 || fours == 5 || fives == 5 || sixes == 5) //if there is 5 of any particular die type
    {
        if(isBonus)
            return previousYahtzee += 100; //score a bonus 100 in yahtzee if one has already been scored
        else
            return 50; //score a regular yahtzee if one hasn't already been scored
    }
    else //if not
        return 0; //score 0 in the yahtzee category.
}


/*********************************************************
 *
 * printRoll
 * ------------------
 * This function prints out the current state of the dice,
 * with blank lines before and after the print-out.
 *
 *********************************************************/
void printRoll(int n1, int n2, int n3, int n4, int n5)
{
    cout << endl;
    cout << "Your roll is:" << endl;
    cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;
    cout << endl;
}

/*********************************************************
 *
 * askReroll
 * ------------------
 * This function ask the user if they'd like to reroll one
 * one of the dice.  The function takes an integer which is
 * the number of the die being rerolled, and returns true if
 * the die should be rerolled, false otherwise.  The integer
 * argument is used only for instruction display, this function
 * does not actually reroll any dice.  Responses accepted are
 * 'Y' and 'N'.
 *
 *********************************************************/
// Took at guess at how to change this to also accept lower case.
bool askReroll(int n)
{
    char ch;
    while (true)
    {
        cout << "Would you like to reroll die " << n << "? (Y/N) ";
        cin >> ch;
		ch = toupper(ch);

        switch (ch)
        {
            case 'Y':
                return true;
			case 'y':
				return true;
            case 'N':
                return false;
			case 'n':
				return false;
            default:
                cout << "Invalid response" << endl;
        }
    }

}



/********************************
 *
 * printScore
 * --------------------
 * This function prints out the complete score table
 * for the yahtzee game in its current state.
 *
 ********************************/
void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
                int fivesScore, int sixesScore, int threeOfAKind,
                int fourOfAKind, int fullHouse, int smallStraight,
                int largeStraight, int yahtzee, int chance)
{
    printSeparator();
    printScoreLine("Ones", onesScore);
    printSeparator();
    printScoreLine("Twos", twosScore);
    printSeparator();
    printScoreLine("Threes", threesScore);
    printSeparator();
    printScoreLine("Fours", foursScore);
    printSeparator();
    printScoreLine("Fives", fivesScore);
    printSeparator();
    printScoreLine("Sixes", sixesScore);
    printSeparator();
    printScoreLine("Three of a kind", threeOfAKind);
    printSeparator();
    printScoreLine("Four of a kind", fourOfAKind);
    printSeparator();
    printScoreLine("Full House", fullHouse);
    printSeparator();
    printScoreLine("Small Straight", smallStraight);
    printSeparator();
    printScoreLine("Large Straight", largeStraight);
    printSeparator();
    printScoreLine("Yahtzee", yahtzee);
    printSeparator();
    printScoreLine("Chance", chance);
    printSeparator();
}

/********************************
 *
 * printSeperator
 * --------------------
 * This helper function prints out a single
 * separator line used as part of the score
 * printing function.
 *
 ********************************/
void printSeparator()
{
    cout << "+-------------------+-------+" << endl;
}

/********************************
 *
 * printScoreLine
 * --------------------
 * This function prints out a single line of the score.
 * The string argument is the name of the category, while
 * the in is the value of the score.  The category name is left
 * aligned, while the score value is right aligned.
 *
 ********************************/
void printScoreLine(string name, int score)
{
    cout << "| " << left << setw(18) << name << "| ";
     if (score >=0)
     {
         cout << right << setw(5) << score;
     }
     else
     {
         cout << "     ";
     }
     cout << " |" << endl;
}

/********************************
 *
 * getScoreOption
 * --------------------
 * This function gets the score category which the player wishes to score
 * with the current roll.  The function ensures that the response corresponds
 * to a valid category.  It also check to make sure that the selected category
 * has not yet been scored (unscored categories contain the value EMPTY).
 *
 ********************************/
int getScoreOption(int onesScore, int twosScore, int threesScore, int foursScore,
                   int fivesScore, int sixesScore, int threeOfAKind,
                   int fourOfAKind, int fullHouse, int smallStraight,
                   int largeStraight, int yahtzee, int chance)
{
    int ans;
    bool valid = false;
    cout << "Here are the categories: " << endl;
    cout << "1. Ones" << endl;
    cout << "2. Twos" << endl;
    cout << "3. Threes" << endl;
    cout << "4. Fours" << endl;
    cout << "5. Fives" << endl;
    cout << "6. Sixes" << endl;
    cout << "7. Three of a kind" << endl;
    cout << "8. Four of a kind" << endl;
    cout << "9. Full House" << endl;
    cout << "10. Small Straight" << endl;
    cout << "11. Large Straight" << endl;
    cout << "12. Yahtzee" << endl;
    cout << "13. Chance" << endl;
    do
    {
        cout << "How would you like to score this? ";
        cin >> ans;
        while (ans < 0 || ans > NUM_CATEGORIES)
        {
            cout << "Please enter a number between 1 and " << NUM_CATEGORIES << ": ";
            cin >> ans;
        }
        switch (ans)
        {
            case ONES:
                if (onesScore == EMPTY) valid = true;
                break;
            case TWOS:
                if (twosScore == EMPTY) valid = true;
                break;
            case THREES:
                if (threesScore == EMPTY) valid = true;
                break;
            case FOURS:
                if (foursScore == EMPTY) valid = true;
                break;
            case FIVES:
                if (fivesScore == EMPTY) valid = true;
                break;
            case SIXES:
                if (sixesScore == EMPTY) valid = true;
                break;
            case THREE_OF_A_KIND:
                if (threeOfAKind == EMPTY) valid = true;
                break;
            case FOUR_OF_A_KIND:
                if (fourOfAKind == EMPTY) valid = true;
                break;
            case FULL_HOUSE:
                if (fullHouse == EMPTY) valid = true;
                break;
            case SMALL_STRAIGHT:
                if (smallStraight == EMPTY) valid = true;
                break;
            case LARGE_STRAIGHT:
                if (largeStraight == EMPTY) valid = true;
                break;
            case YAHTZEE:
                if (yahtzee == EMPTY || yahtzee > 0) valid = true; //making sure you can still score here for new bonus yahtzee
                break;
            case CHANCE:
                if (chance == EMPTY) valid = true;
                break;
        }
        if (!valid)
        {
            cout << "That category has already been used. Please use another." << endl;   //Added please to make the program more nice
        }
    } while (!valid);

    return ans;
}

/********************************
 *
 * tabulateDice
 * --------------------
 * This function calculates and returns the number of dice
 * which show the value n.
 *
 ********************************/
int tabulateDice(int n, int d1, int d2, int d3, int d4, int d5)
{
    int ans = 0;
    if (d1 == n) ans++;
    if (d2 == n) ans++;
    if (d3 == n) ans++;
    if (d4 == n) ans++;
    if (d5 == n) ans++;
    return ans;
}
