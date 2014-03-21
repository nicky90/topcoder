/*
Problem Statement
    
  A mysterious new restaurant is open in the city for only N days. Happy to hear that, Ash and Elsh would like to have lunch     at the restaurant on as many days as possible.  The restaurant sells M types of dishes. Being a mysterious restaurant, it has mysterious rules for the customers:  
They can only buy one single dish per day.
If they buy a dish of type j on the i-th day, then on the same day next week, i.e., on the (i+7)-th day, they can only buy a dish of type j.
  If they don't buy any dishes on any day, then they can't buy any dishes again from the restaurant.
  Mysteriously, the price of each type of dish varies every day. You are given a vector <string> prices consisting of N  elements, each containing M characters. prices[i][j] represents the price of the j-th type of dish on the i-th day, encoded as follows: 
  '0' - '9': denotes the price of 0 - 9 dollars.
  'A' - 'Z': denotes the price of 10 - 35 dollars.
  'a' - 'z': denotes the price of 36 - 61 dollars.
  Ash and Elsh have only budget dollars allocated for having lunch in the restaurant. Return the maximum number of days they could have lunch in the restaurant.


Definition
    
Class:
  MysteriousRestaurant
Method:
  maxDays
Parameters:
  vector <string>, int
Returns:
  int
Method signature:
  int maxDays(vector <string> prices, int budget)
(be sure your method is public)


Limits
    
Time limit (s): 2.000
Memory limit (MB): 64


Constraints
  -prices will contain between 1 and 50 elements, inclusive.
  -Each element of prices will contain the same number of characters, between 1 and 50 characters, inclusive.
  -Each character in prices will be '0'-'9', 'a'-'z', or 'A'-'Z'.
  -budget will be between 0 and 10,000, inclusive.


Examples

0)

{"26", "14", "72", "39", "32", "85", "06"}
13
Returns: 5
The restaurant is open for 7 days. They can have lunch for 5 days, each picking the cheaper dish from the two available types. The total prices would be 2+1+2+3+2 = 10.

1)

{"26", "14", "72", "39", "32", "85", "06", "91"}
20
Returns: 8
In this case, it is better to buy the second type of dish on the first and the eighth day, so they can have lunch for the entire 8 days.

2)

{"SRM", "512"}
4
Returns: 0
They don't have sufficient budget.

3)

{"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"}
256
Returns: 10
 */


class MysteriousRestaurant {
public:
	int maxDays(vector<string> prices, int budget) {
		vector<int> daily[prices.size()];
		for (int i = 0; i < prices.size(); ++i) {
			for (int j = 0; j < prices[i].size(); ++j) {
				int tmp = prices[i][j];
				if ('0'<=tmp && tmp<='9')
					tmp = tmp - '0';
				else if ('A'<=tmp && tmp<='Z')
					tmp = tmp - 'A' + 10;
				else if ('a'<=tmp && tmp<='z')
					tmp = tmp - 'a' + 36;
				
				if (i >= 7)
					tmp += daily[i-7][j];
				daily[i].push_back(tmp);
			}
			
			if (i < 7)
				budget -= *min_element(daily[i].begin(), daily[i].end());
			else {
				budget += *min_element(daily[i-7].begin(), daily[i-7].end());
				budget -= *min_element(daily[i].begin(), daily[i].end());
			}
			
			if (budget <= 0)
				return i+(budget==0);
		}
		return -1;
	}
};
