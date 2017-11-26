#include<iostream>
#include<string>
#include<map>
#include<set>
#include<sstream>
using namespace std;

void FindBooks(string str, map<string, set<string>> book_map)
{
	auto ret = book_map.find(str);
	if (ret == book_map.end()||ret->second.empty())
	{
		cout << "Not Found" << endl;
		return;
	}
	for (auto it = ret->second.cbegin(); it != ret->second.cend(); it++)
		cout << *it << endl;
}

int main(int argc, char *argv[])
{
	unsigned int N = 0, M = 0;
	unsigned int i = 0;
	cin >> N;
	cin.get();
	string ID, title, author, key_wds, publisher, year;
	map<string, set<string>> title_map;
	map<string, set<string>> author_map;
	map<string, set<string>> keywd_map;
	map<string, set<string>> publisher_map;
	map<string, set<string>> year_map;
	for (i = 0; i < N; i++)
	{
		getline(cin, ID);
		getline(cin, title);
		title_map[title].insert(ID);
		getline(cin, author);
		author_map[author].insert(ID);
		getline(cin,key_wds);
		stringstream stream(key_wds);
		string temp;
		while (stream >> temp)
		{
			keywd_map[temp].insert(ID);
		}
		getline(cin, publisher);
		publisher_map[publisher].insert(ID);
		getline(cin, year);
		year_map[year].insert(ID);
	}
	cin >> M;
	cin.get();
	for (i = 0; i<M; i++)
	{
		string temp;
		getline(cin, temp);
		cout << temp << endl;
		switch (temp[0])
		{
		case '1':
		{
			title.assign(temp,3,temp.size()-3);
			FindBooks(title, title_map);
			break;
		}
		case '2':
		{
			author.assign(temp, 3, temp.size() - 3);
			FindBooks(author, author_map);
			break;
		}
		case '3':
		{
			key_wds.assign(temp, 3, temp.size() - 3);
			FindBooks(key_wds, keywd_map);
			break;
		}
		case '4':
		{
			publisher.assign(temp, 3, temp.size() - 3);
			FindBooks(publisher, publisher_map);
			break;
		}
		case '5':
		{
			year.assign(temp, 3, temp.size() - 3);
			FindBooks(year, year_map);
			break;
		}
		default:
			cout << "Not Found" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}