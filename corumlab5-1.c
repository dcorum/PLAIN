#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

struct attendee{
int id, month, day, year;
char firstName[31], middleName[31], lastName[31], association[31], title[31];
struct attendee *prioradd;
};

void push(struct attendee *);
void pop(struct attendee *);
struct attendee *tosp;

int main() {
char input[31], test=0;
int choice=0, id=1, many;;
int month, day, year;

struct attendee *tmp;
tmp = malloc(sizeof(struct attendee));

while(test==0){
printf("\n#Menu \n1. Enter Attendee Information \n2. List All Attendees \n3. Quit\n\nWhat do you want to do? (1/2/3): ");
while(choice == 0){
fgets(input,128, stdin);
sscanf(input, "%d", &choice);
}

while(choice == 1){

printf("\n#Enter Attendee Information\n");



printf("Title: ");
fgets(input, 128, stdin);
if(input[0]=='\n'){
printf("\n## Attendees Added: %d\n", tmp->id); 
choice = 0;
break;
}
sscanf(input, "%31s", tmp->title);

printf("First Name: ");
fgets(input, 128, stdin);
sscanf(input, "%31s", tmp->firstName);

printf("Middle Name: ");
fgets(input, 128, stdin);
sscanf(input, "%31s", tmp->middleName);

printf("Last Name: ");
fgets(input, 128, stdin);
sscanf(input, "%31s", tmp->lastName);

printf("Association: ");
fgets(input, 128, stdin);
sscanf(input, "%31s", tmp->association);

printf("Membership Since(MM/DD/YYYY): ");
fgets(input, 128, stdin);
sscanf(input, "%d/%d/%d", &(tmp->month), &(tmp->day), &(tmp->year));

tmp->id = id;

push(tmp);

id=id+1;
}

while(choice == 3){
test=1;
break;
}
}
return 0;
}

void push(struct attendee *attendee){
struct attendee *new;

new = (struct attendee *) malloc(sizeof(struct attendee));
if(new == (struct attendee *) NULL){
printf("\nFailed to allocate mem\n");
exit(1);
}

strcpy(new->title,attendee->title);
strcpy(new->firstName,attendee->firstName);
strcpy(new->middleName,attendee->middleName);
strcpy(new->lastName,attendee->lastName);
strcpy(new->association,attendee->association);
new->month=attendee->month;
new->day=attendee->day;
new->year=attendee->year;
new->id=attendee->id;

new->prioradd = tosp;
tosp = new;

}

void pop(struct attendee *attendee){

}
