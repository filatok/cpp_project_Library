#include <iostream>
using namespace std;

class LibraryData
{
	private:
		string name;
		int cardId;
	public:
		LibraryData(){
			name = "";
			cardId = 0;
		}
		
		LibraryData(string onoma, int Id){
			name = onoma;
			cardId = Id;
		}
		
		void SetLibraryData(string onoma, int Id){
			name = onoma;
			cardId = Id;
		}
		
		string GetName() {
				return name;
			}
	
		int GetCardId()	{
			return cardId;
		}
		
		~LibraryData(){};
};

class PersonalCard: public LibraryData
{
	private:
		string books[3];
	public:
		PersonalCard(): LibraryData(){
			int i;
			for (i=0; i<3; i++){
				books[i] = "";
			}
		}
		
		PersonalCard(string onoma, int ID): LibraryData(onoma, ID){
			int i;
			for (i=0; i<3; i++){
				books[i] = "";
			}
		}
		
		void SetPersonalCard(string onoma, int ID, string T[3]){
			int i;
			SetLibraryData(onoma, ID);
			for (i=0; i<3; i++)
			{
				books[i] = T[i];
			}
		}
		
		void ShowPersonalCard(){
			int i;
			cout << "ID: " << GetCardId() << endl;
			cout << "name: " << GetName() << endl;
			for (i=0; i<3; i++){
				if (books[i] != "")
				{
					cout << "Title: " << books[i] << endl;
				}
			}
			cout << "-----------------------------------------------"<< endl;
		}
		
		void Danizmos(string title){
			int i;
			bool danismos_isPossible = false;
			for (i=0; i<3; i++){
				if (books[i] == ""){
					books[i] = title;
					danismos_isPossible = true;
					break;}
			}
			if (danismos_isPossible == false) {cout << "Ehete piasei to epitrepomeno orio!" << endl; }	
		}
		
		void Epistrofi(string title){
			int i;
			bool book_exist = false;
			
			for (i=0; i<3; i++){
				if (books[i] == title){
					books[i] = "";
					book_exist = true;
					break;	
				}		
			}
			if (book_exist == false) {cout << "Den exete parei auto to biblio!" << endl; }	
		}
		
		~PersonalCard(){};
};

class StudentCard: public LibraryData
{
	private:
		string books[5];
	public:
		StudentCard(): LibraryData(){
			int i;
			for (i=0; i<5; i++){
				books[i] = "";
			}
		}
		
		StudentCard(string onoma, int ID): LibraryData(onoma, ID){
			int i;
			for (i=0; i<5; i++){
				books[i] = "";
			}
		}
		
		void SetStudentCard(string onoma, int ID, string T[5]){
			int i;
			SetLibraryData(onoma, ID);
			for (i=0; i<5; i++)
			{
				books[i] = T[i];
			}
		}
		
		void ShowStudentCard(){
			int i;
			cout << "ID: " << GetCardId() << endl;
			cout << "name: " << GetName() << endl;
			for (i=0; i<5; i++){
				if (books[i] != "")
				{
					cout << "Title: " << books[i] << endl;
				}
			}
			cout << "-----------------------------------------------"<< endl;
			
		}
		
		void Danizmos(string title){
			int i;
			bool danismos_isPossible = false;
			for (i=0; i<5; i++){
				if (books[i] == ""){
					books[i] = title;
					danismos_isPossible = true;
					break;}
			}
			if (danismos_isPossible == false) {cout << "Ehete piasei to epitrepomeno orio!" << endl; }	
		}
		
		void Epistrofi(string title){
			int i;
			bool book_exist = false;
			
			for (i=0; i<5; i++){
				if (books[i] == title){
					books[i] = "";
					book_exist = true;
					break;	
				}		
			}
			if (book_exist == false) {cout << "Den exete parei auto to biblio!" << endl; }	
		}
		
		~StudentCard(){};
};

int Menu(){
	int e;
	cout << "Epilekste energeia:" << endl;
	cout << "1. Daneismos" << endl;
	cout << "2. Epistrofi" << endl;
	cout << "3. Eksodos" << endl;
	cin >> e;
	return e;
}

int main()
{
	int a, e;
	string b;
	
	PersonalCard p1("Olga", 11);

	PersonalCard p2("Ilias", 22);
	
	StudentCard s1("Valeria", 33);

	StudentCard s2("Lia", 44);
	
	while (1){
		cout << "-----------------------------------------------"<< endl;
		cout << "Eisagete ton arithmo tis kartas sas:" << endl;
		cin >> a;
		if (a == p1.GetCardId() || a == p2.GetCardId() || a == s1.GetCardId() || a == s2.GetCardId())
		{
			cout << "Eisagete titlo bibliou:" << endl;
			cin >> b;
	
			e = Menu();
			if (e == 1){
				if (a == p1.GetCardId()){
					p1.Danizmos(b);
				}
				else if (a == p2.GetCardId()){
					p2.Danizmos(b);
				}
				else if (a == s1.GetCardId()){
					s1.Danizmos(b);
				}
				else if (a == s2.GetCardId()){
					s2.Danizmos(b);
				}
				else {
					cout << "Lathos ID kartas" << endl;
				}
			}
			else if (e==2){
				if (a == p1.GetCardId()){
					p1.Epistrofi(b);
				}
				else if (a == p2.GetCardId()){
					p2.Epistrofi(b);
				}
				else if (a == s1.GetCardId()){
					s1.Epistrofi(b);
				}
				else if (a == s2.GetCardId()){
					s2.Epistrofi(b);
				}
				else {
					cout << "Lathos ID kartas" << endl;
				}
			}		
			else if (e==3){
				cout << "|||||||||||||| LIBRARY DATA ||||||||||||||" << endl;
				p1.ShowPersonalCard();
				p2.ShowPersonalCard();
				s1.ShowStudentCard();
				s2.ShowStudentCard();
				break;
				}
			else {
			cout << "Lathos epilogi" << endl;
			}
			}	
		
			else {
				cout << "Lathos ID kartas" << endl;
			}	
	}
		
	return 0;	
}
