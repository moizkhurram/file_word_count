#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct word
{
	word* next;
	string w;
};
struct node
{
	node* prev;
	node* next;
	word* word;
	char ch;
};

class doubly
{
	node* head;
public:

	void make_alpha_ll()
	{
		node* temp2 = NULL;
		for (char obj = 'a'; obj <= 'z'; obj++)
		{
			node* temp = new node;
			temp->ch = obj;
			temp->word = NULL;

			temp->prev = temp2;
			if (obj != 'a')
				temp2->next = temp;
			if (obj == 'a')
				head = temp;
			if (obj == 'z')
			{
				temp->next = NULL;
			}
			temp2 = temp;
		}
	}

	void print()
	{
		cout << "\nUSEFUL STATISTICS :\n";
		node* temp = head;
		word* tw = NULL;
		int total_words = 0;
		for (temp; temp != NULL; temp = temp->next)
		{
			int ch_w = 0;
			tw = temp->word;



			if (tw != NULL)
			{
				cout << "\n\n" << temp->ch << ":\t";
				for (tw; tw != NULL; tw = tw->next)
				{
					cout << tw->w << " ";
					total_words++;
					ch_w++;
				}
				cout << "\n\t" << "total words for this char :" << ch_w++;
			}


		}
		cout << "\n\n TOTAL WORDS :" << total_words;

	}
	void make_words_ll(string filename)
	{
		node* chr_temp = head;
		word* temp = NULL, * temp2 = NULL;
		while (chr_temp != NULL)
		{
			temp = NULL;
			temp2 = NULL;
			fstream file;
			string words;
			file.open(filename.c_str());

			while (file >> words)
			{
				if (words[0] == chr_temp->ch)
				{

					temp = new word;

					if (chr_temp->word == NULL)
					{
						chr_temp->word = temp;
					}
					if (temp2 != NULL)
					{
						temp2->next = temp;

					}
					temp->w = words;
					temp->next = NULL;
				}


				temp2 = temp;


			}

			file.close();
			chr_temp = chr_temp->next;
		}

	}


};


int main()
{

	doubly a;
	a.make_alpha_ll();

	a.make_words_ll("D:/test.txt"); //input path to a file 

	a.print();

}