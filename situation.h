#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Situation;

struct Choice
{
	
	string description;
	string outcome;
};


class Situation
{
private:
	string m_Narration;
	vector<Choice> m_Choices;

public:
	Situation(){}

	~Situation(){}

	string run()
	{
		system("CLS");
		cout << m_Narration << endl;

		for (int i = 0; i < m_Choices.size(); i++)
		{
			cout << "(" << i + 1 << ") " << m_Choices[i].description << endl;
		}

		int choice;
		while (1)	
		{
			cin >> choice;
			if (choice >= 1 && choice <= m_Choices.size())	{ break; }
			cout << "Please choose a number between 1 and 3" << endl;
		}
		choice = choice - 1;
		return m_Choices[choice].outcome;
		
	}

	void setNarration(string text)
	{
		m_Narration = text;
	}

	string getNarration()
	{
		return m_Narration;
	}

	void addChoice(string description, string outcome)
	{
		Choice choice;
		choice.description = description;
		choice.outcome = outcome;
		m_Choices.push_back(choice);

	}
};
