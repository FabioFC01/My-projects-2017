#include <iostream>
#include <ctime> // Needed for the true randomization
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

double random_number(int a, int b) {
	double n;

	n = (double)(((((double)std::rand()) / RAND_MAX) * (b - a) + a));

	return n;
}

int testa_o_croce(int &punteggio_utente, string nome_utente) {
	//dichiarazioni variabili
	int risultato;
	int scelta;
	int soldi;
	//input variabili
	cout << "Hai scelto Testa o croce!" << endl;
	cout << "Se vincerai guadagnerai tanti soldi quanti ne hai scommessi" << endl;
	cout << "Se perderai la scommessa perderai i soldi scommessi" << endl;
	cout << "Inserisci i soldi che vuoi scommettere";
	cin >> soldi;
	cout << "Inserisci 0 per testa e 1 per croce : ";
	cin >> scelta;

	//estrazione risultato
	risultato = (int)(((((int)std::rand()) / RAND_MAX)));

	//rivelazione risultato
	cout << endl;
	if (risultato == scelta) {
		cout << "Complimenti! Hai vinto la scommessa!" << endl;
		cout << "Al tuo punteggio si aggiungono " << soldi << " soldi!!!" << endl;
		punteggio_utente += soldi;
		cout << "Punteggio di " << nome_utente << " : " << punteggio_utente << endl;
	}
	else {
		cout << "Che sfortuna! Hai perso la scommessa!" << endl;
		cout << "Il numero vincente era il numero " << risultato << endl;
		cout << "Al tuo punteggio verranno tolti " << soldi << " soldi." << endl;
		punteggio_utente -= soldi;
		cout << "Punteggio di " << nome_utente << " : " << punteggio_utente << endl;
	}
	cout << endl;
	return punteggio_utente;
}

int roulette(int &punteggio_utente, string nome_utente) {
	//dichiarazioni variabili
	int risultato;
	int scelta_gioco;
	int scelta_numero;
	int soldi;
	//input variabili
	cout << "Hai scelto Roulette!" << endl;
	cout << "Puoi scegliere se scommettere tra:" << endl;
	cout << "1 - Un singolo numero su 36" << endl;
	cout << "2 - Numeri pari o dispari" << endl;
	cout << "Nel primo caso vincerai 36 volte la scommessa" << endl;
	cout << "Nel secondo caso vincerai 2 volte la scommessa" << endl;
	cout << "In entrambi i casi se perdi perdi la scommessa da te fatta" << endl;

	cout << "Seleziona 1 per il primo caso, 2 per il seconodo : " << endl;
	cin >> scelta_gioco;
	cout << " ----------------------------------------------------------------------- " << endl;

	//gioco 1
	if (scelta_gioco == 1) {
		cout << "Hai scelto il primo gioco" << endl;
		cout << "Seleziona i soldi da scommettere" << endl;
		cin >> soldi;
		cout << "Inserisci un numero intero tra 1 e 36 (estremi compresi)" << endl;
		cin >> scelta_numero;

		risultato = random_number(1, 37);

		if (risultato == scelta_numero) {
			cout << "Complimenti! Hai vinto la scommessa!" << endl;
			cout << "Al tuo punteggio si aggiungono " << 36*soldi << " soldi!!!" << endl;
			punteggio_utente += 36*soldi;
			cout << "Punteggio di " << nome_utente << " : " << punteggio_utente << endl;
		}
		else {
			cout << "Che sfortuna! Hai perso la scommessa!" << endl;
			cout << "Il numero vincente era il numero " << risultato << endl;
			cout << "Al tuo punteggio verranno tolti " << soldi << " soldi." << endl;
			punteggio_utente -= soldi;
			cout << "Punteggio di " << nome_utente << " : " << punteggio_utente << endl;
		}
	}

	//gioco 2
	if (scelta_gioco == 2) {
		cout << "Hai scelto il secondo gioco" << endl;
		cout << "Seleziona i soldi da scommettere" << endl;
		cin >> soldi;
		cout << "Inserisci 0 per un numero pari, 1 per uno dispari" << endl;
		cin >> scelta_numero;

		risultato = random_number (0,2);

		if (risultato % 2 == scelta_numero) {
			cout << "Complimenti! Hai vinto la scommessa!" << endl;
			cout << "Al tuo punteggio si aggiungono " << soldi << " soldi!!!" << endl;
			punteggio_utente += soldi;
			cout << "Punteggio di " << nome_utente << " : " << punteggio_utente << endl;
		}
		if (risultato % 2 != scelta_numero) {
			cout << "Che sfortuna! Hai perso la scommessa!" << endl;
			cout << "Il numero vincente era il numero " << risultato << endl;
			cout << "Al tuo punteggio verranno tolti " << soldi << " soldi." << endl;
			punteggio_utente -= soldi;
			cout << "Punteggio di " << nome_utente << " : " << punteggio_utente << endl;
		}
	}
	return punteggio_utente;
}

//riasssunto funzioni programma
	//a = numero minimo, b = numero massimo
	double random_number(int a, int b);
	int testa_o_croce	(int &punteggio_utente, string nome_utente);
	int roulette		(int &punteggio_utente, string nome_utente);

int main()
{
	//dichiarazione variabili
	int punteggio_utente = 100;
	string nome_utente;
	int scelta = 10;

	//inizio programma
	cout << "Benvenuto in Game Of Chance!!!" << endl;
	cout << "Inserisci il tuo nome utente : ";
	getline(cin, nome_utente);
	cout << "Il punteggio di partenza di " << nome_utente << " e' di 100 monete." << endl;
	//gioco di probabilità
	while (scelta != 0) {
		cout << " -------------------------------------------------------------------- " << endl;
		cout << "Quale dei seguenti giochi vuoi fare?" << endl;
		cout << "0 - Esci dal programma" << endl;
		cout << "1 - Testa o croce" << endl;
		cout << "2 - Roulette" << endl;

		cin >> scelta;
		if (scelta == 1) {
			testa_o_croce(punteggio_utente, nome_utente);
		}
		if (scelta == 2) {
			roulette(punteggio_utente, nome_utente);
		}
	}

	system("pause");
	return 0;
}