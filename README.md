Politechnika Śląska
Wydział Matematyk Stosowanej
Kierunek Informatyka
Gliwice, 04.02.2022



Programowanie I
projekt zaliczeniowy
"Snake"

Adrian Adamek gr. lab. 2/3


1. Opis projektu.

Tematem projektu jest gra typu Snake napisana w języku C++. Założeniem projektu jest wykonanie gry inspirowanej grą Snake wydaną po raz pierwszy w październiku 1976 roku pod nazwą Blockade i spopularyzowaną na przełomie XX i XXI wieku dzięki wersjom dla telefonów komórkowych firmy Nokia które przypominać ma projekt. Polega ona na zjadaniu jabłek i powiększaniu  rozmiarów węża. Każde zjedzenie jabłka zwiększa ilość zdobytych punktów o 1.

2. Wymagania 

1. Proste menu umożliwiające rozpoczęcie rozgrywki
2. Generowanie planszy na której pojawiać się będą punkty
3. Wydłużanie się Węża po zebraniu punktu
4. Możliwość sterowania 
5. Zliczanie punktów zdobytych przez gracza

3. Przebieg realizacji 

Projekt składa się z jednego pliku Źródło.cpp w którym znajduje się funkcja main, wszystkie potrzebne funkcje oraz cały kod. 
W projekcie zostało utworzone menu z nagłówkiem „Snake” umożliwiające rozpoczęcie rozgrywki, lub zakończenie programu obsługiwane za pomocą strzałek.
Przy wyborze rozpoczęcia rozgrywki należy wpisać wielkość planszy oraz szybkość odświeżania. Podane są wartości sugerowane, które pozwalają na wypełnienie całej konsoli. Od tych wartości zależna jest utworzona możliwość wyboru poziomu trudności rozgrywki.
Sama rozgrywka działa poprzez tworzenie planszy jako tablicy, w której pola przyjmują wartości p-puste pole, s-miejsce gdzie znajduje się wąż, a-miejsce wylosowania jabłka. Wartości zostają porównywane i zostaje wykonana odpowiednia akcja. Poruszanie działa na zasadzie pobierania klawiszy i porównania ich wartości. 
Ustawiony został również wygląd konsoli, aby przypominał on grę ze starych telefonów Nokii.
Biblioteki:
conio.h – konieczna do obsługi funkcji _getch i obsługi klawiatury w programie
ctime – obsługa czasu konieczna do ustalenia szybkości poruszania
random – obsługa losowania

4. Instrukcja użytkownika 

a.Wybór rozpoczęcia gry w menu
 
 ![obraz](https://user-images.githubusercontent.com/66797963/153300426-999010fe-1a0b-45d3-a2f9-3d59b30bdda9.png)

b. Wprowadzenie wielkości planszy i szybkości poruszania

![obraz](https://user-images.githubusercontent.com/66797963/153300531-8010318e-6540-4c5b-9dda-bedaed274187.png)

c. Zapoznanie się z metodą kontroli

![obraz](https://user-images.githubusercontent.com/66797963/153300552-b7510731-9bd9-4d05-b568-aa6af580c650.png)

d. Poruszanie się wężem, zbieranie pożywienia i aktywne kontrolowanie liczby zdobytych punktów poniżej planszy
 
 ![obraz](https://user-images.githubusercontent.com/66797963/153300571-ee43fb53-0d61-4e18-8aef-fe3a99ce75f6.png)

e. W momencie przegranej pojawienie się komunikatu koniec gry i liczby zdobytych punktów. Powrót do menu
 
 ![obraz](https://user-images.githubusercontent.com/66797963/153300609-64776ea2-f439-4527-a1fa-4207886f541d.png)

5. Podsumowanie i wnioski.

Zrealizowane zostały wszystkie założenia Największy problem sprawiła kontrola poruszania się i wychwycenie sytuacji przegranej. Dalszym kierunkiem rozwoju może być stworzenie innych map.
