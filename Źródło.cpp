#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <random> //pseudolosowanie
																			
void menu(); //deklaracja menu g³ównego
void snake(); //deklaracja funkcji wywo³uj¹cej gre
void sterowanie(); //delkaracja funkcji wyœwietlaj¹cej sposób sterowania
void wielkosc(); //deklaracja funkcji pobieraj¹cej wielkoœæ planszy i szybkoœæ
void wyglad(); //deklaracja funkcji dostosowuj¹cej wygl¹d


int psize, speed; //parametry dla wielkosc();
//parametry dla snake();
int positionX{}, positionY{};
int AppleX{}, AppleY{};
int length = 4;
int ile{};
int klawisz{};
char kierunek = 'r';
char pole[50][50]{};
int historyX[100]{}, historyY[100]{};
const int UP = 'W', DOWN = 'S', LEFT = 'A', RIGHT = 'D'; //deklaracja klawiszy sterowania
const int upm = 'w', downm = 's', leftm = 'a', rightm = 'd'; //deklaracja klawiszy sterowania
const char snakee = 219, apple = 177, pd = 188, pg = 187, lg = 201, ld = 200, poz = 205, pion = 186; //deklaracja wyœwietlanych znaków w grze

using namespace std;

int main() {
    wyglad();
    menu();
}

//eliminacja migotania ekranu przy odœwierzaniu
void screenclear() {
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
//menu g³ówne
void menu() {
    int z{}, m = 1;
    while (1) {
        system("cls");
        printf("\n\n");
        printf("\t\t\t  SSSS                       kk\n");
        printf("\t\t\t SS   SS                     kk\n");
        printf("\t\t\t SS   SS                     kk\n");
        printf("\t\t\t SS        nnnnn     aaaa    kk  kk    eeee\n");
        printf("\t\t\t  SSS      nn  nn   aa  aa   kk kk    ee  ee\n");
        printf("\t\t\t    SSS    nn  nn     aaaa   kkkk     eeeeee\n");
        printf("\t\t\t      SS   nn  nn    aa aa   kkk      ee\n");
        printf("\t\t\t SS   SS   nn  nn   aa  aa   kkkk     ee\n");
        printf("\t\t\t SS   SS   nn  nn   aa  aa   kk kk    ee  ee\n");
        printf("\t\t\t  SSSSS    nn  nn    aaaaa   kk  kk    eeee\n\n\n");

        if (m == 1) { printf("\t\t\t\t\t*ROZPOCZNIJ GRE*\n");}
        if (m == 1) { printf("\t\t\t\t\t WYJSCIE \n"); }
        if (m == 2) { printf("\t\t\t\t\t ROZPOCZNIJ GRE \n"); }
        if (m == 2) { printf("\t\t\t\t\t*WYJSCIE*\n");}
        z = _getch();
        //pobieranie ruchu strza³akimi i jego interpretacja
        if (z == 72) { m--; }
        if (m == 0) { m = +3; }
        if (z == 80) { if (m < 2) { m++; } }
        if ((z == 13) && (m == 1)) wielkosc();
        if ((z == 13) && (m == 2)) exit(1);			
    }
}
//informacja o sposobie sterowania
void sterowanie() {
    system("cls");
    cout << "\n\n\t\t\t\t STEROWANIE   w-a-s-d\n\n\t\t\t\t\t PAUZA p\n\n";
    system("pause");
    snake();
}
//pobieraniewielkoœci planszy i szybkoœci
void wielkosc() {
    cout << "Podaj welkosc planszy (zalecane 42):";
    cin >> psize;
    //zabezpieczenie wielkoœci
    if (psize < 5) psize = 5;
    if (psize > 42) psize = 42;
    cout << "Podaj szybkosc gry (zalecane 10): ";
    cin >> speed;
    //zabezpieszenie szybkoœci
    if (speed < 1) speed = 1;
    if (speed > 200) speed = 200;
    sterowanie();
}

void snake() {
    ile = 0;
    length = 4;
    //p-puste, s-snake, a-punkt
    //wyzerownie planszy
    for (int i = 0; i < psize; i++) {
        for (int j = 0; j < psize; j++) {
            pole[j][i] = 'p';
        }
    }
    //generator losowych zgodny z wielkoœci¹ planszy
    mt19937 generator(time(nullptr));
    uniform_int_distribution<int> dist(1, psize);

    //ustawienie pocz¹tku wê¿a
    positionX = dist(generator);
    positionY = dist(generator);
    pole[positionX][positionY] = 's';

    //ustawienie punktu w pustym miejscu
    do {
        AppleX = dist(generator);
        AppleY = dist(generator);
    } while (pole[AppleX][AppleY] != 'p');
    pole[AppleX][AppleY] = 'a';

    system("cls");

    //pêtla
    while(1) {
        //usuwanie koñca wê¿a podczas przemieszczania
        ile++;
        historyX[ile] = positionX;
        historyY[ile] = positionY;
        pole[historyX[ile - length]][historyY[ile - length]] = 'p';

        screenclear(); //eliminacja migotania

        cout << lg; //rysowanie naro¿nika planszy lewygórny

        //pozioma granica planszy góra
        for (int i = 0; i < psize; i++) {
            cout << poz << poz;
        }

        cout << pg; //rysowanie naro¿nika planszy prawygórny

        //rysowanie œrodka planszy i boków
        for (int i = 0; i < psize; i++) {
            cout << endl << pion;
            for (int j = 0; j < psize; j++) {
                if (pole[j][i] == 'p') 
                    cout << "  ";
                if (pole[j][i] == 's') 
                    cout << snakee << snakee;
                if (pole[j][i] == 'a') 
                    cout << apple << apple;

            }
            cout << pion;
        }
        cout << endl  << ld; //rysowanie naro¿nika planszy lewydolny

        //pozioma granica planszy dó³
        for (int i = 0; i < psize; i++) {
            cout << poz << poz;
        }

        cout << pd; //rysowanie naro¿nika planszy prawydolny

        Sleep(1000 / speed); //ustawienie szybkoœci odœwierzania - szybkoœci poruszania

        //pobieranie nacisku klawiszy i interpretacja
        if (_kbhit()) {
            klawisz = _getch();
            if (klawisz == 224)klawisz += _getch();
            if (klawisz == 0) klawisz -= _getch();

            //pauza
            if (klawisz == 'p' || klawisz == 'P')
                _getch();

            if ((klawisz == UP || klawisz == upm) && kierunek != 'd') kierunek = 'u';
            if ((klawisz == DOWN || klawisz == downm) && kierunek != 'u') kierunek = 'd';
            if ((klawisz == LEFT || klawisz == leftm) && kierunek != 'r') kierunek = 'l';
            if ((klawisz == RIGHT || klawisz == rightm) && kierunek != 'l') kierunek = 'r';
        }

        if (kierunek == 'r')positionX++;
        if (kierunek == 'l')positionX--;
        if (kierunek == 'u')positionY--;
        if (kierunek == 'd')positionY++;

        if (positionX == psize) positionX = 0;
        if (positionX == -1) positionX = psize - 1;
        if (positionY == psize) positionY = 0;
        if (positionY == -1) positionY = psize - 1;
        //najechanie wê¿em na "siebie"
        if (pole[positionX][positionY] == 's') {
            cout << endl << "KONIEC GRY  zdobytych punktow: " << length - 4 << endl; //koñcowy wynik
            break;
        }

        //gdy najedzie siê na punkt i losowanie nowego
        if (pole[positionX][positionY] == 'a') {
            length++;
            do {
                AppleX = dist(generator);
                AppleY = dist(generator);
            } while (pole[AppleX][AppleY] != 'p');
            pole[AppleX][AppleY] = 'a';
        }
        pole[positionX][positionY] = 's';
        //aktualny wynik
        cout << endl << "Punkty: " << length - 4 << endl;
    }
    system("pause");
}

//ustwienie wygl¹du konsoli
void wyglad() {
    char c = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT sr;
    sr.Left = 0;
    sr.Top = 0;
    sr.Right = 85;
    sr.Bottom = 45;
    SetConsoleWindowInfo(handle, true, &sr);
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo(handle, &sbi);
    // Zmiana tytulu okna konsoli
    SetConsoleTitle(L"Snake");
    //Zmiana koloru konsoli
    SetConsoleTextAttribute(handle, BACKGROUND_GREEN);
    // Ukrycie kursora konsoli
    CONSOLE_CURSOR_INFO kursor;
    kursor.dwSize = sizeof(CONSOLE_CURSOR_INFO);
    kursor.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &kursor);
}