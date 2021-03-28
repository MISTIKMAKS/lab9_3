#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

struct Note
{
	string last_name;
	string name;
	string telephone;
	int day;
	int month;
	int year;
};

void Create(Note* n, const int N);
void Print(Note* n, const int N);
void Menu(Note* n, const int N);
void Sort(Note* n, const int N);
int Search(Note* n, const int N, const string btelephone);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Insert N: "; cin >> N;
	Note* n = new Note[N];

	Create(n, N);
	Print(n, N);
	Menu(n, N);
}
void Create(Note* n, const int N) {
	for (int i = 0; i < N; i++)
	{
		cout << "Person № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Name: "; getline(cin, n[i].name);
		cout << " Last Name: "; getline(cin, n[i].last_name);
		cout << " Telephone: "; getline(cin, n[i].telephone);
		cout << " Birthday Day : "; cin >> n[i].day;
		cout << " Birthday Month : "; cin >> n[i].month;
		cout << " Birthday Year: "; cin >> n[i].year;
		cout << endl;
	}
}
void Print(Note* n, const int N)
{
	cout << "============================================================================="
		<< endl;
	cout << "| № | Name | Last Name | Telephone | Day | Month | Year |"
		<< endl;
	cout << "-----------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(7) << left << n[i].name
			<< "| " << setw(7) << right << n[i].last_name << " "
			<< "| " << setw(10) << left << n[i].telephone
			<< "| " << setw(3) << right << n[i].day << "|" << " " << setw(3) << right
			<< n[i].month << "|" << " " << setw(5) << right << n[i].year << " |" << endl;
	}
	cout << "============================================================================="
		<< endl;
	cout << endl;
}
void Menu(Note* n, const int N) {
	int choice;

	do {
		cout << "--------------------------\n";
		cout << "Main Menu\n";
		cout << "Please make your selection\n";
		cout << "1 - Sort\n";
		cout << "2 - Search\n";
		cout << "3 - Quit\n";
		cout << "--------------------------\n";
		cout << "Selection: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "You Chosen 1 - Sort:\n";
			Sort(n, N);
			Print(n, N);
			break;
		case 2:
		{
			cout << "You Chosen 3 - Binary Search:\n";

			string btelephone;
			int found;

			cout << "Enter Keys For Search:" << endl;
			cout << " Telephone: ";
			cin >> btelephone;
			if ((found = Search(n, N, btelephone)) != -1) {
				cout << "Student Found On Position: " << found + 1 << endl;
			}
			else {
				cout << "Student Not Found" << endl;
			}
			break;
		}
		case 3:
			cout << "Goodbye! See Ya Later, Aligator!!!";
			break;
		default:
			cout << "--------------------------\n";
			cout << "Main Menu\n";
			cout << "Please make your selection\n";
			cout << "1 - Sort\n";
			cout << "2 - Search\n";
			cout << "3 - Quit\n";
			cout << "--------------------------\n";
			cout << "Selection: ";
			cin >> choice;
		}
	} while (choice != 3);
}
void Sort(Note* n, const int N) {
	Note tmp;
	for (int i0 = 0; i0 < N - 1; i0++) {
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {
			if (n[i1].year < n[i1 + 1].year) {
				tmp = n[i1];
				n[i1] = n[i1 + 1];
				n[i1 + 1] = tmp;
			}
			else if (n[i1].year == n[i1 + 1].year) {
				if (n[i1].month < n[i1 + 1].month) {
					tmp = n[i1];
					n[i1] = n[i1 + 1];
					n[i1 + 1] = tmp;
				}
				else if (n[i1].month == n[i1 + 1].month)
				{
					if (n[i1].day < n[i1 + 1].day) {
						tmp = n[i1];
						n[i1] = n[i1 + 1];
						n[i1 + 1] = tmp;
					}
				}
			}
		}
	}
}
int Search(Note* n, const int N, const string btelephone) {
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (n[m].telephone == btelephone) {
			return m;
		}
		if (n[m].telephone < btelephone)
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}