#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct s
{
    char song_name[100];
    char singer_name[100];
    char genre[100];
};
typedef struct s SONG;
struct node
{
    SONG song;
    struct node *next;
    struct node *prev;
};
typedef struct node playLL;
playLL *head = NULL;
playLL *current = NULL;
void readSong(SONG s)
{
    printf("===============================\n");
    printf("|| song name   : %10s\n", s.song_name);
    fflush(stdout);
    printf("|| singer name : %10s\n", s.singer_name);
    fflush(stdout);
    printf("|| genre       : %10s\n", s.genre);
    printf("===============================\n");
}
playLL *inserAtLast(SONG sng)

{
    playLL *newNode = (playLL *)malloc(sizeof(playLL));
    newNode->song = sng;
    newNode->next = newNode;
    newNode->prev = newNode;
    if (newNode == NULL)
    {
        printf("NOT SPACE AVAILABLE\n");
        return head;
    }
    if (head == NULL)
    {
        head = newNode;
        current = head; // updating current
        return head;
    }
    playLL *ptr = head->prev;
    // while (ptr->next != head)
    //     ptr = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = head;
    head->prev = newNode;
    return head;
}
void readPlayLL()
{
    if (head == NULL)
        printf("playlist is empty\n");
    playLL *ptr = head;
    while (ptr->next != head)
    {
        readSong(ptr->song);
        ptr = ptr->next;
    }
    readSong(ptr->song);
}
int matching(SONG sf, SONG st)
{
    if ((!strcmp(sf.song_name, st.song_name)))
        return 1;
    return 0;
}
playLL *deleteSong(SONG s, int isLoop)
{
    if (head == NULL)
        return head;
    playLL *ptr = head;
    while (!matching(s, ptr->song) && ptr->next != head)
        ptr = ptr->next;
    if (!matching(s, ptr->song) && ptr->next == head)
    {
        printf("song not found in list");
        return head;
    }
    else
    {
        if (ptr == head && ptr->next == head && ptr->prev == head)
        {
            free(head);
            head = NULL;
            current = NULL; // updating current
            // return head;
        }
        if (ptr == head)
        {
            ptr->next->prev = head->prev;
            ptr->prev->next = head->next;
            head = head->next;
            if (current == ptr) // updating current
                current = head;
            free(ptr);
            ptr = NULL;
        }
        else if (ptr->next == head)
        {
            ptr->prev->next = head;
            head->prev = ptr->prev;
            if (isLoop == 0)
            {
                if (current == ptr && current->next == head) // updating current
                    current = NULL;
            }
            else
            {
                if (current == ptr && current->next == head) // updating current
                    current = head;
            }
            free(ptr);
            ptr = NULL;
        }
        else
        {

            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            if (current == ptr)
                current = ptr->next; // updating current
            free(ptr);
            ptr = NULL;
        }
    }
    printf("SONG DELETED!");
    return head;
}
void playParticular(SONG s)
{
    if (head == NULL)
        return;
    playLL *ptr = head;
    while (!matching(s, ptr->song) && ptr->next != head)
        ptr = ptr->next;
    if (!matching(s, ptr->song) && ptr->next == head)
    {
        printf("song not found in list");
        return;
    }
    else
    {
        readSong(ptr->song);
        printf("->>is playing\n");
        printf("*******************************\n");
        current = ptr;
    }
}
void playFirst()
{
    if (head == NULL)
    {
        printf("playlist is empty\n");
        return;
    }
    else
    {
        current = head;
        readSong(head->song);
        printf("->>is playing\n");
        printf("*******************************\n");
    }
}
playLL *shuffleSong(SONG s1, SONG s2)
{
    if (head == NULL)
        return head;
    playLL *ptr = head;
    playLL *ptr2 = head;
    while (!matching(s1, ptr->song) && ptr->next != head)
        ptr = ptr->next;
    if (!matching(s1, ptr->song) && ptr->next == head)
        ptr = NULL;
    while (!matching(s2, ptr2->song) && ptr2->next != head)
        ptr2 = ptr2->next;
    if (!matching(s2, ptr2->song) && ptr2->next == head)
        ptr2 = NULL;
    if (ptr == NULL || ptr2 == NULL)
        return head;
    SONG temp = ptr->song;
    ptr->song = ptr2->song;
    ptr2->song = temp;

    return head;
}
void playNext(int isLoop)
{
    if (current->next == head && isLoop == 0)
    {

        printf("It's last song! (no song ahead it)\n");
        return;
    }
    current = current->next;
    readSong(current->song);
    printf("->>is playing\n");
    printf("*******************************\n");
}
void playPrevious(int isLoop)
{
    if (current->prev->next == head && isLoop == 0)
    {

        printf("It's first song! (no song before it)\n");
        return;
    }
    current = current->prev;
    readSong(current->song);
    printf("->>is playing\n");
    printf("*******************************\n");
}
int playListPrompt(int isloop)
{
    // playLL *head = NULL;
    int n, choice;
    SONG s;
    SONG s1, s2;
    // current = head;

    while (1)
    {
        printf("\n1.Insert a new song");
        printf("\n2.Delete song");
        printf("\n3.Display all song");
        printf("\n4.Play next");
        printf("\n5.Play previous");
        printf("\n6.Play particular");
        printf("\n7.Shuffle song");
        printf("\n8.Play first");
        printf("\n9.Back");
        printf("\nenter your choice:");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:

            printf("song name:");
            fflush(stdin);
            gets(s.song_name);

            fflush(stdin);
            printf("singer name:");
            gets(s.singer_name);

            fflush(stdin);
            printf("genre name:");
            gets(s.genre);

            fflush(stdin);

            head = inserAtLast(s);
            break;

        case 2:
            printf("enter the song name to delete:\n");

            printf("song name:");
            fflush(stdin);
            gets(s.song_name);

            fflush(stdin);

            head = deleteSong(s, isloop);
            getch();
            break;

        case 3:
            readPlayLL(head);
            getch();
            break;
        case 4:
            playNext(isloop);
            getch();
            break;
        case 5:
            playPrevious(isloop);
            getch();

            break;
        case 6:
            printf("enter the song name to play:\n");

            printf("song name:");
            fflush(stdin);
            gets(s.song_name);

            fflush(stdin);

            playParticular(s);
            getch();
            break;
        case 7:
            printf("enter 1 song name :\n");

            printf("song name:");
            fflush(stdin);
            gets(s1.song_name);

            printf("enter 2 song name :\n");

            printf("song name:");
            fflush(stdin);
            gets(s2.song_name);

            fflush(stdin);

            head = shuffleSong(s1, s2);
            break;
        case 8:
            playFirst(head);
            getch();
            break;
        case 9:
            return 1;
        default:
            printf("Invalid Choice\n");
            getch();
        }
        system("cls");
        choice = 0;
    }
    return 0;
}
int main()
{
    int x;
    while (x != 2)
    {
        printf("\n0. Without LOOP");
        printf("\n1. With LOOP");
        printf("\n2. Exit");
        fflush(stdin);
        scanf("%d", &x);
        switch (x)
        {
        case 0:
            playListPrompt(0);
            break;
        case 1:
            playListPrompt(1);
            break;
        case 2:
            exit(1);
        default:
            printf("\nINVALID CHOICE");
        }
        system("cls");
    }
    return 0;
}