
        switch (scoreOption)
        {
            case ONES:
                onesScore = ones;
                break;
            case TWOS:
                twosScore = twos * 2;
                break;
            case THREES:
                threesScore = threes * 3;
                break;
            case FOURS:
                foursScore = fours * 4;
                break;
            case FIVES:
                fivesScore = fives * 5;
                break;
            case SIXES:
                sixesScore = sixes * 6
                break;
            case THREE_OF_A_KIND:
                if (ones == 3)
			threeOfAKind = ones;
		else if (twos == 3)
			threeOfAKind = twos * 2;
		else if (threes == 3)
			threeOfAKind = threes * 3;
		else if (fours == 3)
			threeOfAKind = fours * 4;
		else if (fives == 3)
			threeOfAKind = sives * 5;
		else if (sixes == 3)
			threeOfAKind = sixes * 6;
		else
			threeOfAKind = 0;
                break;
	}
	/* To do finish off scoring logic
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
                break;
            case YAHTZEE:
                yahtzee = scoreYahtzee(ones, twos, threes, fours, fives, sixes);
                break;
            case CHANCE:
                chance = scoreChance(ones, twos, threes, fours, fives, sixes);
                break;
        }*/





