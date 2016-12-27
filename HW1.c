#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HUMAN 2
#define ANIMAL 1
#define PC 0
#define NONE 3

int respect = 40;
int pcrmnum = 0;

struct Creature {
     int type;
} ;

struct Room {
    int state;
    struct Room* n;
    struct Room* s;
    struct Room* e;
    struct Room* w; 
    struct Creature* creatures[10];
    int numOfCreatures;
} ;

void look (struct Room*, struct Creature*);
void movenorth(struct Room*, struct Creature*, int);
void movesouth(struct Room*, struct Creature*, int);
void moveeast(struct Room*, struct Creature*, int);
void movewest(struct Room*, struct Creature*, int);

void parse(char *arg, struct Room* rooms, struct Creature* creatures) {
        int i, j, g;
        char qolon = ':';
        char *found;

        found = strchr(arg, qolon);
        if (found) {
            char *token1;
            char *token2;
            char *line = arg;
            const char *search = ":";

            token1 = strtok(line, search);
            token2 = strtok(NULL, search);
            
            if (strcmp(token2, "dirty") == 0) {
                if (rooms[pcrmnum].state >= 0 && rooms[pcrmnum].state <= 2) {
                    rooms[pcrmnum].state++;
                    for (i = 0; i < 10 ; i++) {
                    if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == ANIMAL) {
                        respect--;
                        if (rooms[pcrmnum].creatures[i] == &creatures[atoi(token1)]) { //if the one who did the action was an animal
                            respect--;
                            respect--; 
                            printf("%d growls a lot. Respect is now %d\n", atoi(token1), respect);
                                if (rooms[pcrmnum].state == 2) {
                                    if (rooms[pcrmnum].n != NULL && rooms[pcrmnum].n->numOfCreatures < 10) {
                                        movenorth(rooms, creatures, atoi(token1));
                                    } else if (rooms[pcrmnum].s != NULL && rooms[pcrmnum].s->numOfCreatures < 10) {
                                        movesouth(rooms, creatures, atoi(token1));
                                    } else if (rooms[pcrmnum].e != NULL && rooms[pcrmnum].e->numOfCreatures < 10) {
                                        moveeast(rooms, creatures, atoi(token1));
                                    } else if (rooms[pcrmnum].w != NULL && rooms[pcrmnum].w->numOfCreatures < 10) {
                                        movewest(rooms, creatures, atoi(token1));
                                    } else {
                                    
                                }
                                }
                        } else {
                        for (j = 0; 1 ; j++) {
                            if (rooms[pcrmnum].creatures[i] == &creatures[j]) {
                                printf("%d growls. Respect is now %d\n", j, respect);
                                if (rooms[pcrmnum].state == 2) {
                                    if (rooms[pcrmnum].n != NULL && rooms[pcrmnum].n->numOfCreatures < 10) {
                                        movenorth(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].s != NULL && rooms[pcrmnum].s->numOfCreatures < 10) {
                                        movesouth(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].e != NULL && rooms[pcrmnum].e->numOfCreatures < 10) {
                                        moveeast(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].w != NULL && rooms[pcrmnum].w->numOfCreatures < 10) {
                                        movewest(rooms, creatures, j);
                                    } else {
                                    
                                }
                                }
                                break;
                            }
                        }
                        }
                    }
                    if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == HUMAN) {
                        respect++;
                        if (rooms[pcrmnum].creatures[i] == &creatures[atoi(token1)]) { //if the one who did the action was an human
                            respect++;
                            respect++; 
                            printf("%d smiles a lot. Respect is now %d\n", atoi(token1), respect);
                    } else {
                    for (j = 0; 1 ; j++) {
                            if (rooms[pcrmnum].creatures[i] == &creatures[j]) {
                                printf("%d smiles. Respect is now %d\n", j, respect);
                                break;
                            }
                        }
                    }
                }
                }
                }
            } else if (strcmp(token2, "clean") == 0) {
                if (rooms[pcrmnum].state >= 0 && rooms[pcrmnum].state <= 2) {
                    rooms[pcrmnum].state--;
                    for (i = 0; i < 10 ; i++) {
                    if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == ANIMAL) {
                        respect++;
                        if (rooms[pcrmnum].creatures[i] == &creatures[atoi(token1)]) { //if the one who did the action was an animal
                            respect++;
                            respect++; 
                            printf("%d licks your face a lot. Respect is now %d\n", atoi(token1), respect);
                    } else {
                        for (j = 0; 1 ; j++) {
                            if (rooms[pcrmnum].creatures[i] == &creatures[j]) {
                                printf("%d licks your face. Respect is now %d\n", j, respect);
                                break;
                            }
                        }
                    }
                    }
                    if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == HUMAN) {
                        respect--;
                        if (rooms[pcrmnum].creatures[i] == &creatures[atoi(token1)]) { //if the one who did the action was a human
                            respect--;
                            respect--; 
                            printf("%d grumbles a lot. Respect is now %d\n", atoi(token1), respect);
                                if (rooms[pcrmnum].state == 0) {
                                    if (rooms[pcrmnum].n != NULL && rooms[pcrmnum].n->numOfCreatures < 10) {
                                        movenorth(rooms, creatures, atoi(token1));
                                    } else if (rooms[pcrmnum].s != NULL && rooms[pcrmnum].s->numOfCreatures < 10) {
                                        movesouth(rooms, creatures, atoi(token1));
                                    } else if (rooms[pcrmnum].e != NULL && rooms[pcrmnum].e->numOfCreatures < 10) {
                                        moveeast(rooms, creatures, atoi(token1));
                                    } else if (rooms[pcrmnum].w != NULL && rooms[pcrmnum].w->numOfCreatures < 10) {
                                        movewest(rooms, creatures, atoi(token1));
                                    } else {
                                    
                                }
                                }
                        } else {
                        for (j = 0; 1 ; j++) {
                            if (rooms[pcrmnum].creatures[i] == &creatures[j]) {
                                printf("%d grumbles. Respect is now %d\n", j, respect);
                                if (rooms[pcrmnum].state == 0) {
                                    if (rooms[pcrmnum].n != NULL && rooms[pcrmnum].n->numOfCreatures < 10) {
                                        movenorth(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].s != NULL && rooms[pcrmnum].s->numOfCreatures < 10) {
                                        movesouth(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].e != NULL && rooms[pcrmnum].e->numOfCreatures < 10) {
                                        moveeast(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].w != NULL && rooms[pcrmnum].w->numOfCreatures < 10) {
                                        movewest(rooms, creatures, j);
                                    } else {
                                    
                                }
                                }
                                break;
                            }
                        }
                        }
                    }
                }
                }
            } else if (strcmp(token2, "north") == 0) {
                movenorth(rooms, creatures, atoi(token1)); //if he can't leave he will growl?????
            } else if (strcmp(token2, "south") == 0) {
                movesouth(rooms, creatures, atoi(token1));
            } else if (strcmp(token2, "east") == 0) {
                moveeast(rooms, creatures, atoi(token1));
            } else if (strcmp(token2, "west") == 0) {
                movewest(rooms, creatures, atoi(token1));
            }
        } else {
            bool b = false;
                for (i = 0; !b ; i++) {
                    for (j = 0; (j < 10) && !b ; j++) {
                        if (rooms[pcrmnum].creatures[j] == &creatures[i] && creatures[i].type == PC) {
                            g = i;
                            b = true;
                        }
                    }
            }
            if (strcmp(arg, "look") == 0) {
                look(rooms, creatures);
            } else if (strcmp(arg, "clean") == 0) {
                if (rooms[pcrmnum].state >= 0 && rooms[pcrmnum].state <= 2) {
                    rooms[pcrmnum].state--;
                
                for (i = 0; i < 10 ; i++) {
                    if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == ANIMAL) {
                        respect++;
                        for (j = 0; 1 ; j++) {
                            if (rooms[pcrmnum].creatures[i] == &creatures[j]) {
                                printf("%d licks your face. Respect is now %d\n", j, respect);
                                break;
                            }
                        }
                    }
                    if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == HUMAN) {
                        respect--;
                        for (j = 0; 1 ; j++) {
                            if (rooms[pcrmnum].creatures[i] == &creatures[j]) {
                                printf("%d grumbles. Respect is now %d\n", j, respect);
                                if (rooms[pcrmnum].state == 0) {
                                    if (rooms[pcrmnum].n != NULL && rooms[pcrmnum].n->numOfCreatures < 10) {
                                        movenorth(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].s != NULL && rooms[pcrmnum].s->numOfCreatures < 10) {
                                        movesouth(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].e != NULL && rooms[pcrmnum].e->numOfCreatures < 10) {
                                        moveeast(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].w != NULL && rooms[pcrmnum].w->numOfCreatures < 10) {
                                        movewest(rooms, creatures, j);
                                    } else {
                                    
                                }
                                }
                                break;
                            }
                        }
                    }
                }
                }
            } else if (strcmp(arg, "dirty") == 0) {
                if (rooms[pcrmnum].state >= 0 && rooms[pcrmnum].state <= 2) {
                    rooms[pcrmnum].state++;
                    for (i = 0; i < 10 ; i++) {
                    if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == ANIMAL) {
                        respect--;
                        for (j = 0; 1 ; j++) {
                            if (rooms[pcrmnum].creatures[i] == &creatures[j]) {
                                printf("%d growls. Respect is now %d\n", j, respect);
                                if (rooms[pcrmnum].state == 2) {
                                    if (rooms[pcrmnum].n != NULL && rooms[pcrmnum].n->numOfCreatures < 10) {
                                        movenorth(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].s != NULL && rooms[pcrmnum].s->numOfCreatures < 10) {
                                        movesouth(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].e != NULL && rooms[pcrmnum].e->numOfCreatures < 10) {
                                        moveeast(rooms, creatures, j);
                                    } else if (rooms[pcrmnum].w != NULL && rooms[pcrmnum].w->numOfCreatures < 10) {
                                        movewest(rooms, creatures, j);
                                    } else {
                                    
                                    }
                                }
                                break;
                            }
                        }
                    }
                    if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == HUMAN) {
                        respect++;
                        for (j = 0; 1 ; j++) {
                            if (rooms[pcrmnum].creatures[i] == &creatures[j]) {
                                printf("%d smiles. Respect is now %d\n", j, respect);
                                break;
                            }
                        }
                    }
                }
                }
            } else if (strcmp(arg, "north") == 0) {
                movenorth(rooms, creatures, g);
                printf("(You)\n"); 
            } else if (strcmp(arg, "south") == 0) {
                movesouth(rooms, creatures, g);
                printf("(You)\n");
            } else if (strcmp(arg, "east") == 0) {
                moveeast(rooms, creatures, g);
                printf("(You)\n");
            } else if (strcmp(arg, "west") == 0) {
                movewest(rooms, creatures, g);
                printf("(You)\n");
            } 
        }
}

void look (struct Room* rooms, struct Creature* creatures) { 
    int i, j;
    printf("Room %d, ", pcrmnum);
    if (rooms[pcrmnum].state == 0) {
        printf("clean, ");
    } else if (rooms[pcrmnum].state == 1) {
        printf("half-dirty, ");
    } else if (rooms[pcrmnum].state == 2) {
        printf("dirty, ");
    }
    printf("neighbors ");
    if (rooms[pcrmnum].n != NULL) {
        for (i = 0; i < 10; i++) {
            if (rooms[pcrmnum].n == &rooms[i]) {
                printf("%d to the north", i);
                break;
            }
        }
    } 
    if (rooms[pcrmnum].s != NULL) {
        for (i = 0; i < 10; i++) {
            if (rooms[pcrmnum].s == &rooms[i]) {
                printf("%d to the south", i);
                break;
            }
        }
    } 
    if (rooms[pcrmnum].e != NULL) {
        for (i = 0; i < 10; i++) {
            if (rooms[pcrmnum].e == &rooms[i]) {
                printf("%d to the east", i);
                break;
            }
        }
    } 
    if (rooms[pcrmnum].w != NULL) {
        for (i = 0; i < 10; i++) {
            //printf("yes");
            if (rooms[pcrmnum].w == &rooms[i]) {
                //printf("maybe");
                printf("%d to the west", i);
                break;
            }
        }
    }
    printf(", contains:\n");
    printf("PC\n");
    int m, n;
    for (i = 0; i < 9; i++) {
        if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == ANIMAL) {
            for (j = 0; 1; j++) {
                if (rooms[pcrmnum].creatures[i] == &(creatures[j])) {
                    m = j;
                    break;
                }
            }
            printf("animal %d\n", m);
        }
    } 
    for (i = 0; i < 9; i++) {
        if (rooms[pcrmnum].creatures[i] != NULL && rooms[pcrmnum].creatures[i]->type == HUMAN) {
            for (j = 0; 1 ; j++) {
                if (rooms[pcrmnum].creatures[i] == &(creatures[j])) {
                    n = j;
                    break;
                }
            }
            printf("human %d\n", n);
        }
    }

}

void movenorth(struct Room* rooms, struct Creature* creatures, int crtr) {
    int i, j, y, h;
    if (rooms[pcrmnum].n != NULL) {
        for (i = 0; 1 ; i++) {
            if (rooms[pcrmnum].n == &rooms[i]) {
                y = i;
                break;
            }
        }
        for (j = 0; 1 ; j++) {
            if (rooms[pcrmnum].creatures[j] == &creatures[crtr]) {
                h = j;
                rooms[pcrmnum].creatures[j] = NULL; 
                break;
            }
        }
        if (rooms[y].state == 2 && creatures[crtr].type == ANIMAL) {
            rooms[y].state--;
        } 
        if (rooms[y].state == 0 && creatures[crtr].type == HUMAN) {
            rooms[y].state++;
        }
        for (i = 0; i < 10 ; i++) {
            if (rooms[y].creatures[i] == NULL) {
                rooms[y].creatures[i] = &creatures[crtr];
                break;
            }
        }
        printf("%d leaves towards the north\n", crtr);
        if (creatures[crtr].type == PC) {
            pcrmnum = y;
        }
    }
}

void movesouth(struct Room* rooms, struct Creature* creatures, int crtr) {
    int i, j, y, h;
    if (rooms[pcrmnum].s != NULL) {
        for (i = 0; 1 ; i++) {
            if (rooms[pcrmnum].s == &rooms[i]) {
                y = i;
                break;
            }
        }
        for (j = 0; 1 ; j++) {
            if (rooms[pcrmnum].creatures[j] == &creatures[crtr]) {
                h = j;
                rooms[pcrmnum].creatures[j] = NULL;
                break;
            }
        }
        if (rooms[y].state == 2 && creatures[crtr].type == ANIMAL) {
            rooms[y].state--;
        } 
        if (rooms[y].state == 0 && creatures[crtr].type == HUMAN) {
            rooms[y].state++;
        }
        for (i = 0; i < 10 ; i++) {
            if (rooms[y].creatures[i] == NULL) {
                rooms[y].creatures[i] = &creatures[crtr];
                break;
            }
        }
        printf("%d leaves towards the south\n", crtr);
        if (creatures[crtr].type == PC) {
            pcrmnum = y;
        }
    }
}

void moveeast(struct Room* rooms, struct Creature* creatures, int crtr) {
    int i, j, h, y;
    if (rooms[pcrmnum].e != NULL) {
        for (i = 0; 1 ; i++) {
            if (rooms[pcrmnum].e == &rooms[i]) {
                y = i;
                break;
            }
        }
        for (j = 0; 1; j++) {
            if (rooms[pcrmnum].creatures[j] == &creatures[crtr]) {
                h = j;
                rooms[pcrmnum].creatures[j] = NULL; 
                break;
            }
        }
        if (rooms[y].state == 2 && creatures[crtr].type == ANIMAL) {
            rooms[y].state--;
        } 
        if (rooms[y].state == 0 && creatures[crtr].type == HUMAN) {
            rooms[y].state++;
        }
        for (i = 0; i < 10 ; i++) {
            if (rooms[y].creatures[i] == NULL) {
                rooms[y].creatures[i] = &creatures[crtr];
                break;
            }
        }
        printf("%d leaves towards the east\n", crtr);
        if (creatures[crtr].type == PC) {
            pcrmnum = y;
        }
    }
}

void movewest(struct Room* rooms, struct Creature* creatures, int crtr) {
    int i, y, j, h;
    if (rooms[pcrmnum].w != NULL) {
        for (i = 0; 1 ; i++) {
            if (rooms[pcrmnum].w == &rooms[i]) {
                y = i;
                break;
            }
        }
        for (j = 0; 1 ; j++) {
            if (rooms[pcrmnum].creatures[j] == &creatures[crtr]) {
                h = j;
                rooms[pcrmnum].creatures[j] = NULL;
                break;
            }
        }
        if (rooms[y].state == 2 && creatures[crtr].type == ANIMAL) {
            rooms[y].state--;
        } 
        if (rooms[y].state == 0 && creatures[crtr].type == HUMAN) {
            rooms[y].state++;
        }
        for (i = 0; i < 10 ; i++) {
            if (rooms[y].creatures[i] == NULL) {
                rooms[y].creatures[i] = &creatures[crtr];
                break;
            }
        }
        printf("%d leaves towards the west\n", crtr);
        if (creatures[crtr].type == PC) {
            pcrmnum = y;
        }
    }
}

int main(int argc, char* argv[]) {

    int i, j;

    printf("Please enter the number of rooms: \n");
    int numOfRooms;
    scanf("%d", &numOfRooms);

    struct Room* rooms = (struct Room*) malloc(sizeof(struct Room) * numOfRooms);

    printf("Please enter the state of the room and its neighbors: \n");
    for (i = 0 ; i < numOfRooms ; i++) {
      printf("Room %d: ", i);
      int state, north, south, east, west;
      scanf("%d %d %d %d %d", &state, &north, &south, &east, &west);
      rooms[i].state = state;
      if (north != -1) {
          rooms[i].n = &(rooms[north]);
      }
      if (south != -1) {
          rooms[i].s = &(rooms[south]);
      }
      if (east != -1) {
          rooms[i].e = &(rooms[east]);
      }
      if (west != -1) {
          rooms[i].w = &(rooms[west]);
      }
    }

    printf("Please enter the number of creatures: \n");
    int numOfCreatures;
    scanf("%d", &numOfCreatures);

    struct Creature* creatures = (struct Creature*) malloc(sizeof(struct Creature) * numOfCreatures);

    printf("Please enter the type of creature and its location: \n");
    for (i = 0 ; i < numOfCreatures; i++) {
      printf("Creature %d: ", i);
      int type, location;
      scanf("%d %d", &type, &location);
      creatures[i].type = type;
      for (int j = 0 ; j < 10 ; j++) {
        if (rooms[location].creatures[j] == NULL) {
          rooms[location].creatures[j] = &(creatures[i]);
          rooms[location].numOfCreatures += 1;
          break;
        }
      }
      if (creatures[i].type == PC) {
          pcrmnum = location;
        }
    }

   char *command;
   do {

    printf("Please enter a commnad: \n");
    //char command[64];
    scanf("%s", command);
    parse(command, rooms, creatures);

   } while (strcmp(command, "exit") != 0); 

    free(creatures);
    free(rooms);
    return 0;
}