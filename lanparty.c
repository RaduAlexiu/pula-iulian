#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>

typedef struct player
{
    char *name;
    char *surname;
    int *score;
} player;

typedef struct team
{
    char *name;
    player *players;
    int *nr_players;
    int *score;
} team;

typedef struct node
{
    team *team;
    struct node *next;
    struct node *previous;
} node;

void print_player(player *player, FILE *f3)
{
    fprintf(f3, "%s %s %d\n", player->name, player->surname, *(player->score));
}

void print_team(team *team, FILE *f3)
{
    fprintf(f3, "%s\n", team->name);
    for (int i = 0; i < *(team->nr_players); i++)
    {
        print_player(&(team->players[i]), f3);
    }
}

void print_list(node *head, FILE *f3)
{
    node *current = head;
    while (current != NULL)
    {
        print_team(current->team, f3);
        current = current->next;
        fprintf(f3, "\n");
    }
}

void print_teams(node *head, FILE *f3)
{
    node *current = head;
    while (current != NULL)
    {
        fprintf(f3, "%s\n", current->team->name);
        current = current->next;
    }
}

void citeste_jucator(player *player, FILE *f2, FILE *f3)
{
    char name[100];
    char surname[100];
    int score;
    fscanf(f2, "%s %s %d", name, surname, &score);
    player->name = strdup(name);
    player->surname = strdup(surname);
    player->score = (int *)malloc(sizeof(int));
    *(player->score) = score;
}

void citeste_echipa(team *team, FILE *f2, FILE *f3)
{
    char name[100];
    int nr_players;
    fscanf(f2, "%d %[^\n]s", &nr_players, name);
    team->name = strdup(name);
    team->nr_players = (int *)malloc(sizeof(int));
    *(team->nr_players) = nr_players;
    team->players = (player *)malloc(*(team->nr_players) * sizeof(player));
    for (int i = 0; i < *(team->nr_players); i++)
    {
        citeste_jucator(&(team->players[i]), f2, f3);
    }
}

node *citeste_lista_echipe(int nr_teste, FILE *f2, FILE *f3)
{
    node *head = NULL;
    node *previous = NULL;

    for (int i = 0; i < nr_teste; i++)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->team = (team *)malloc(sizeof(team));
        citeste_echipa(new_node->team, f2, f3);

        new_node->previous = previous;
        new_node->next = head;
        if (head != NULL)
        {
            head->previous = new_node;
        }
        head = new_node;
        previous = new_node;
    }

    return head;
}

// Functie care calculeaza si adauga scorul unei echipe
void calculeaza_scor_echipa(team *team)
{
    int scor = 0;
    for (int i = 0; i < *(team->nr_players); i++)
    {
        scor += *(team->players[i].score);
    }
    team->score = (int *)malloc(sizeof(int));
    *(team->score) = scor;
}

// Functie care calculeaza si adauga scorul tuturor echipelor
void calculeaza_scoruri(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        calculeaza_scor_echipa(current->team);
        current = current->next;
    }
}

int numara_echipe(node *head)
{
    int nr_echipe = 0;
    node *current = head;
    while (current != NULL)
    {
        nr_echipe++;
        current = current->next;
    }
    return nr_echipe;
}

void elimina_echipa(node *echipa)
{
    node *previous = echipa->previous;
    node *next = echipa->next;
    if (previous != NULL)
    {
        previous->next = next;
    }
    if (next != NULL)
    {
        next->previous = previous;
    }
    if (previous == NULL)
    {
        next->previous = NULL;
    }
}

node *gaseste_echipa_min(node *head)
{
    node *current = head;
    node *min = head;
    while (current != NULL)
    {
        if (*(current->team->score) < *(min->team->score))
        {
            min = current;
        }
        current = current->next;
    }
    return min;
}

int putere_2(int n)
{
    int p = 1;
    while (p * 2 <= n)
    {
        p *= 2;
    }
    return p;
}

void elimina_echipe(node *head)
{
    int nr_echipe = numara_echipe(head);
    // Debug print
    printf("nr_echipe: %d\n", nr_echipe);
    int nr_echipe_eliminate = nr_echipe - putere_2(nr_echipe);
    // Debug print
    printf("nr_echipe_eliminate: %d\n", nr_echipe_eliminate);
    for (int i = 0; i < nr_echipe_eliminate; i++)
    {
        node *echipa_min = gaseste_echipa_min(head);
        // elimina_echipa(echipa_min);
    }
}

int main(int argc, char *argv[])
{
    FILE *f1 = fopen(argv[1], "r");
    int c1, c2, c3, c4, c5;
    fscanf(f1, "%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);
    fclose(f1);

    FILE *f2 = fopen(argv[2], "r");
    FILE *f3 = fopen(argv[3], "w");

    if (c1 == 1)
    {
        int nr_teste;
        fscanf(f2, "%d", &nr_teste);
        node *head = citeste_lista_echipe(nr_teste, f2, f3);
        // Calculeaza scorul fiecarei echipe
        calculeaza_scoruri(head);

        if (c2 == 1)
        {
            // eliminarea echipelor
            elimina_echipe(head);
        }

        print_teams(head, f3);
        fprintf(f3, "");
    }

    return 0;
}
