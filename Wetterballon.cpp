
#include <iostream>

using namespace std;

const int ANZAHL_MAX_MONATE = 13;

const int ANZAHL_MAX_WETTERBALLON = 21;

double eingabeWerte[ANZAHL_MAX_MONATE][ANZAHL_MAX_WETTERBALLON];

int eingegebeneMonate = 12;

int eingegebeneBallons = 20;
void eingabe();
void berrechnung();
void ausgabe();
void eingabeVonWerte(int);

int main()
{
	eingabe();
	berrechnung();
	ausgabe();

}


void eingabe() {

	cout << "Eingabe von Luftdruck-Werten in bar. \n";
	cout << "Letzter Beobachtungsminat (1...12): ";
	cin >> eingegebeneMonate;
	cout << "\nAnzahl der Messballons:             ";
	cin >> eingegebeneBallons;
	for (int i = 1; i < eingegebeneMonate + 1; ++i) {
		eingabeVonWerte(i);
	}
}

void eingabeVonWerte(int monat) {
	cout << "\n \n " << monat << ". Monat.";
	for (int i = 1; i < eingegebeneBallons + 1; ++i) {
		cout << "\n Druck bei Ballon Nr. " << i << "? ";
		cin >> eingabeWerte[monat][i];
	}
}

void berrechnung() {
	double temp = 0;
	for (int j = 1; j < eingegebeneMonate + 1; ++j) {
		for (int i = 1; i < eingegebeneBallons + 1; ++i) {
			temp += eingabeWerte[j][i];
		}
		temp = temp / eingegebeneBallons;
		eingabeWerte[j][0] = (int)(temp * 100 + 0.5) / 100.0;
		temp = 0;
	}

	for (int j = 0; j < eingegebeneBallons + 1; ++j) {
		for (int i = 0; i < eingegebeneMonate + 1; ++i) {
			temp += eingabeWerte[i][j];
		}	
		temp = temp / eingegebeneMonate;
		eingabeWerte[0][j] = (int)(temp * 100 + 0.5) / 100.0;
		temp = 0;
	}
}

void ausgabe() {
	cout << "\n \n Druckmessungen. \n";
	cout << "Feld links oben:         Gesamtdurchschnitt aller gemessenen Druecke. \n";
	cout << "Oberste Zeile (Monat 0): Durchschnittsdruecke aller Monate bei jedem Ballon. \n";
	cout << "Linke Spalte (Ballon 0): Durchschnittsdruecke aller Ballons in jedem Monat.";
	
	cout << "\n \n \t \t \t Ballon Nr. \n \t";
	for (int i = 0; i < eingegebeneBallons + 1; ++i) {
		cout << "\t" << i;
	}
	for (int i = 0; i < eingegebeneMonate + 1; ++i) {
		cout << "\n Monat   " << i;
		for (int j = 0; j < eingegebeneBallons + 1; ++j) {
			cout << "\t" << eingabeWerte[i][j];
		}
	}
}