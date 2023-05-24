Implementarea simplă a unui sistem de gestionare a echipelor de joc
Acest proiect este o implementare simplă a unui sistem de gestionare a echipelor de joc. Este scris în limbajul de programare C și oferă funcționalități precum citirea informațiilor despre echipe și jucători dintr-un fișier de intrare, calcularea scorului pentru fiecare echipă și eliminarea unui număr de echipe în funcție de anumite criterii.

Structuri de date
player: reprezintă un jucător și conține următoarele câmpuri:

name: un șir de caractere care stochează numele jucătorului.
surname: un șir de caractere care stochează prenumele jucătorului.
score: un pointer către un întreg care stochează scorul jucătorului.
team: reprezintă o echipă și conține următoarele câmpuri:

name: un șir de caractere care stochează numele echipei.
players: un pointer către un vector de jucători (player).
nr_players: un pointer către un întreg care stochează numărul de jucători din echipă.
score: un pointer către un întreg care stochează scorul echipei.
node: reprezintă un nod într-o listă dublu înlănțuită și conține următoarele câmpuri:

team: un pointer către o echipă (team).
next: un pointer către nodul următor în listă.
previous: un pointer către nodul precedent în listă.
Funcții și operații
print_player: afișează informațiile despre un jucător într-un fișier dat.
print_team: afișează informațiile despre o echipă și jucătorii săi într-un fișier dat.
print_list: afișează informațiile despre toate echipele și jucătorii într-o listă de echipe într-un fișier dat.
print_teams: afișează doar numele tuturor echipelor dintr-o listă de echipe într-un fișier dat.
citeste_jucator: citește informațiile despre un jucător dintr-un fișier dat și le stochează într-o structură player.
citeste_echipa: citește informațiile despre o echipă și jucătorii săi dintr-un fișier dat și le stochează într-o structură team.
citeste_lista_echipe: citește un număr dat de echipe dintr-un fișier dat și le stochează într-o listă de echipe.
calculeaza_scor_echipa: calculează și adaugă scorul unei echipe în funcție de scorurile jucătorilor să
