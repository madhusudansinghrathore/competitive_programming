/*
Tweedle-Dee and Tweedle-Dum are playing a fierce match of binary Nim. This novel game is played with N stacks, each of them containing only 1-s and 0

-s.

Just like in normal Nim, Tweedle-Dee and Tweedle-Dum alternate turns; in their turn, a player must choose one non-empty stack and remove a positive number of elements from the top of this stack. However, Tweedle-Dee may only choose a stack with 0
at the top (and remove elements from it afterwards), and similarly, Tweedle-Dum may only choose a stack with 1

at the top. The player that cannot make a move for the first time wins.

Ada does not want to wait for the end of the game, so she asked you to determine the winner of the game if you are given the starting player. Remember that Tweedle-Dee and Tweedle-Dum are legendary grandmasters of combinatorial games, so they both always play optimally.
Input

    The first line of the input contains a single integer T

denoting the number of test cases. The description of T
test cases follows.
The first line of each test case contains an integer N
, followed by a space and a string S
denoting the player that starts the game.
Each of the following N
lines contains a single binary string B representing a stack; the first character of B

    corresponds to the top element of the stack and the last character to the bottom element.

Output

For each test case, print a single line containing the string "Dee" if Tweedle-Dee wins the match or "Dum" if Tweedle-Dum wins.
Constraints

    1≤T≤500

1≤N≤50
1≤|B|≤50
each character in B
is either '1' or '0'
S

    is either "Dee" or "Dum"

Example Input

1
2 Dee
010
101

Example Output

Dee
*/

#include<iostream> 
#include<string>

using namespace std;

unsigned short int t, n, i, temp_str_len, st_no;
string boolean_str[50], str;
bool turn_of_dee=false, no_win;

void stack_no( char cond ){
	temp_str_len=0; // length max
	st_no=-1;

	for(i=0; i<n; ++i){
		if( boolean_str[i].length() > temp_str_len && cond==boolean_str[i][0] ){
			st_no=i;
			cout << st_no << endl << boolean_str[i];
		}
	}
}

int main(){
	
	scanf("%hu", &t);

	while(t--){
		cin >> n >> str;
		
		for(i=0; i<n; ++i){
			cin >> boolean_str[i];
		}

		str=="Dee"? turn_of_dee=true: turn_of_dee=false;
		no_win=true;
		
		while( no_win ){

			if( turn_of_dee ){
				stack_no('0');
				if( st_no==-1 ){
					str="Dee";
					no_win=false;
				}else{
					boolean_str[i].erase(0, 1);
					turn_of_dee=false;
				}
			}else{
				stack_no('1');
				if( st_no==-1 ){
					str="Dum";
					no_win=false;
				}else{
					boolean_str[i].erase(0, 1);
					turn_of_dee=true;
				}
			}
		}

		cout << str << "\n";
	}
	return 0;
}