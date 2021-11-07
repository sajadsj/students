/*
 * Title: Students
 * Project aim: Learning linked list data structure
 * by: SajadSojoudi@gmail.com
*/

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//variables
struct student_t
{
    char name[33];
    char fam[33];
    char code[11];
    unsigned int  id;
    int   gender;
    float avg;
    char address[257];
    char tell[12];

    struct student_t* next;
};

struct student_t* HEAD = NULL;


//General functions
void add(char* name, char* fam, char* code, int id, int gender, float avg, char* address, char* tell)
{
    struct student_t* head = NULL;

    head = HEAD;

    struct student_t* temp = NULL;
    struct student_t* p = NULL;

    temp = malloc(sizeof(struct student_t));

    strcpy(temp->name, name);
    strcpy(temp->fam, fam);
    strcpy(temp->code, code);
    temp->id = id;
    temp->gender = gender;
    temp->avg = avg;
    strcpy(temp->address, address);
    strcpy(temp->tell, tell);

    temp->next = NULL;

    if (head == NULL)      // if list is empty, make temp as firet node
    {
        head = temp;
    }

    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;

        p->next = temp;
    }

    HEAD = head;
   
}

void printlist()
{
    struct student_t* p = HEAD;
    while (p != NULL)
    {
        printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\n\t\tThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", p->name,
            p->fam,
            p->code,
            p->id,
            p->gender,
            p->avg,
            p->address,
            p->tell);

        p = p->next;
    }
}

int repetition_check()
{
    struct student_t* p1 = HEAD;
    struct student_t* p2 = HEAD;
    int count = 0,rep=0;

    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            if (p1->id == p2->id)
            {
                rep++;
            }
            p2 = p2->next;
        }

        p2 = HEAD;
        count++;
        p1 = p1->next;
    }
    if (rep > count)
    {
        printf("\n\n\aThere is a repitation in the IDs\n\n");
        return 1; //repitition
    }
    else
        return 0;
}

void add_by_user()
{
    int n = 0;
    printf("\n\t\tHow many students do you want to add?");
    scanf("%d", &n);

    char name[33], fam[33], code[11], address[257], tell[13];
    int id = 0, gender = 0;
    float avg = 0;
    int i = 1, rep =0;
   
    while (i<= n && rep == 0)
   // for (int i = 1; i <= n; i++)
    {
        printf("\n\t\tPlease Enter %d est/end student information", i);

        printf("\n\t\tEnter name:\n\t\t");
        scanf("%s", name);

        printf("\n\t\tEnter Family:\n\t\t");
        scanf("%s", fam);

        printf("\n\t\tEnter Code:\n\t\t");
        scanf("%s", code);

        printf("\n\t\tEnter ID:\n\t\t");
        scanf("%d", &id);

        printf("\n\t\tEnter Gender 0 = boy, 1= girl:\n\t\t");
        scanf("%d", &gender);

        printf("\n\t\tEnter avg:\n\t\t");
        scanf("%f", &avg);

        printf("\n\t\tEnter address:\n\t\t");
        scanf("%s", address);

        printf("\n\t\tEnter tell:\n\t\t");
        scanf("%s", tell);

        add(name, fam, code, id, gender, avg, address, tell);
        rep = repetition_check();     
        i++;
    }
    if (rep == 0)
        return;
    //printlist(HEAD);
}

void add_from_file()
{
    FILE* fileobj = fopen("./students_info.txt", "r");

    if (fileobj == NULL)
    {
        printf("fopen failed");
        exit(-1);
    }

    printf("\n\t\tReading frome file...");

    char name[33], fam[33], code[11], address[257], tell[12];
    float avg = 0;
    int id = 0, gender = 0;


    while (!feof(fileobj))

    {
        fscanf(fileobj, "%s %s %s %d %d %f %s %s", &name, &fam, &code, &id, &gender, &avg, &address, &tell);
        add(name, fam, code, id, gender, avg, address, tell);     
    }
    fclose(fileobj);
   int rep= repetition_check();
   if (rep == 1)
       exit(-1);
   else if (rep == 0)
       printf("\n\t\tReading frome file is done");
       return;
    //printlist(HEAD);
}

void del_item()
{
    
    struct student_t *temp = HEAD, * prev = NULL;
    int key=0;

    printf("Enter the id of the student do you want to delete:");
    scanf("%d", &key);

    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->id == key)
    {
        HEAD = temp->next;  
        free(temp);               
        return;
    }

    // Search for the key to be deleted, keep track of the 
   
    while (temp != NULL && temp->id != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list 
    if (temp == NULL) return;

    // Unlink the node from linked list 
    prev->next = temp->next;

    free(temp); 
}

void edit()
{
    int s_id;
    struct student_t* current;

    printf("\n\t\tEnter ID to edit:\n\t\t ");
    scanf("%d", &s_id);

    current = HEAD;


    while (current != NULL)
    {
        if (current->id == s_id)
        {
            printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                current->fam,
                current->code,
                current->id,
                current->gender,
                current->avg,
                current->address,
                current->tell);          
            break;
        }
        current = current->next;
    }
    


    int com_e = 0;

    while (com_e != 9)
    {
        printf("\n\t\tWhich item do you want to edit?\n \n\t\t1: Name\n\t\t2: Family\n\t\t3: Code\n\t\t4: ID\n\t\t5: Gender\n\t\t6: Avg\n\t\t7: Address\n\t\t8: Tell\n\n\t\t9: Exit editing\n\n\t\tEnter your Command:\n\t\t");

        scanf("%d", &com_e);

        switch (com_e)
        {
        case 1:
            printf("\n Enter the new name:");
            scanf("%s", current->name);
            break;

        case 2:
            printf("\n Enter the new fam:");
            scanf("%s", current->fam);
            break;

        case 3:
            printf("\n Enter the new code:");
            scanf("%s", current->code);
            break;

        case 4:
            printf("\n Enter the new id:");
            scanf("%d", &current->id);
            repetition_check();
            break;

        case 5:
            printf("\n Enter the new gender:");
            scanf("%d", &current->gender);
            break;

        case 6:
            printf("\n Enter the new avg:");
            scanf("%f", &current->avg);
            break;

        case 7:
            printf("\n Enter the new address:");
            scanf("%s", current->address);
            break;

        case 8:
            printf("\n Enter the new tell:");
            scanf("%s", current->tell);
            break;
        }
    }
    printf("Item edited");
    printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
        current->fam,
        current->code,
        current->id,
        current->gender,
        current->avg,
        current->address,
        current->tell);
   
}

void print_to_file()
{
    FILE* out_file = fopen("./out.txt" , "w");
    if (out_file == NULL)
    {
        printf("\nfopen fail!\a\n");
        return;
    }
    else
    {
       printf("\n\t\tWriting to file...");
 
        struct student_t* p = HEAD;

        while (p != NULL)
        {
            fprintf(out_file, "\n\nThe name is %s\nThe family is %s\nThe code is %s\n\t\tThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n",
                p->name,
                p->fam,
                p->code,
                p->id,
                p->gender,
                p->avg,
                p->address,
                p->tell);

            p = p->next;
        }   

       fclose(out_file);

        printf("\n\t\tWriting to file is done");
    }

}

//Search's Functions
void search_id(int com_s)
{
    if (com_s != 4)
    printf("Wrong Com_s");

    int s_id;
    struct student_t* current;

    printf("\n\t\tEnter ID to search:\n\t\t ");
    scanf("%d", &s_id);

    current = HEAD;

    // Iterate till last element until key is not found
    while (current != NULL)
    {    
        if (current->id == s_id)
        {
            printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                current->fam,
                current->code,
                current->id,
                current->gender,
                current->avg,
                current->address,
                current->tell);
        }
        current = current->next;
    }


 // if (current == NULL) 
     // printf ("ID is not in the list");
}

void search_name(int com_s)
{
    char* name_s[33];
    if (com_s != 1)
        printf("Wrong Com_s");
    else
    {
        printf("\n\t\tEnter the name:");
        scanf("%s", name_s);
        struct student_t* current;
        current = HEAD;


        while (current != NULL)
        {
            if (strcmp (name_s, current->name)==0)
            {
                printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                    current->fam,
                    current->code,
                    current->id,
                    current->gender,
                    current->avg,
                    current->address,
                    current->tell);
            }
            current = current->next;
        }

    }

}

void search_fam(int com_s)
{
    char* fam_s[33];
    if (com_s != 2)
        printf("Wrong Com_s");
    else
    {
        printf("\n\t\tEnter the Fam:");
        scanf("%s", fam_s);
        struct student_t* current;
        current = HEAD;


        while (current != NULL)
        {
            if (strcmp(fam_s, current->fam) == 0)
            {
                printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                    current->fam,
                    current->code,
                    current->id,
                    current->gender,
                    current->avg,
                    current->address,
                    current->tell);
            }
            current = current->next;
        }

    }

}

void search_code(int com_s)
{
    char* code_s[11];
    if (com_s != 3)
        printf("Wrong Com_s");
    else
    {
        printf("\n\t\tEnter the code:");
        scanf("%s", code_s);
        struct student_t* current;
        current = HEAD;


        while (current != NULL)
        {
            if (strcmp(code_s, current->code) == 0)
            {
                printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                    current->fam,
                    current->code,
                    current->id,
                    current->gender,
                    current->avg,
                    current->address,
                    current->tell);
            }
            current = current->next;
        }

    }

}

void search_address(int com_s)
{
    char* address_s[33];
    if (com_s != 7)
        printf("Wrong Com_s");
    else
    {
        printf("\n\t\tEnter the address:");
        scanf("%s", address_s);
        struct student_t* current;
        current = HEAD;


        while (current != NULL)
        {
            if (strcmp(address_s, current->address) == 0)
            {
                printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                    current->fam,
                    current->code,
                    current->id,
                    current->gender,
                    current->avg,
                    current->address,
                    current->tell);
            }
            current = current->next;
        }

    }

}

void search_tell(int com_s)
{
    char* tell_s[33];
    if (com_s != 8)
        printf("Wrong Com_s");
    else
    {
        printf("\n\t\tEnter the tell:");
        scanf("%s", tell_s);
        struct student_t* current;
        current = HEAD;


        while (current != NULL)
        {
            if (strcmp(tell_s, current->tell) == 0)
            {
                printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                    current->fam,
                    current->code,
                    current->id,
                    current->gender,
                    current->avg,
                    current->address,
                    current->tell);
            }
            current = current->next;
        }

    }

}

void search_gender(int com_s)
{
    if (com_s != 5)
        printf("Wrong Com_s");

    int s_gender;
    struct student_t* current;

    printf("\n\t\tEnter gender to search:\n\t\t ");
    scanf("%d", &s_gender);

    current = HEAD;

    // Iterate till last element until key is not found
    while (current != NULL)
    {
        if (current->gender == s_gender)
        {
            printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                current->fam,
                current->code,
                current->id,
                current->gender,
                current->avg,
                current->address,
                current->tell);
        }
        current = current->next;
    }
}

void search_avg(int com_s)
{
    if (com_s != 6)
        printf("Wrong Com_s");

    float s_avg;
    struct student_t* current;

    printf("\n\t\tEnter avg to search:\n\t\t ");
    scanf("%f", &s_avg);

    current = HEAD;

    // Iterate till last element until key is not found
    while (current != NULL)
    {
        if (current->avg == s_avg)
        {
            printf("\n\nThe name is %s\nThe family is %s\nThe code is %s\nThe id is %d\nThe gender is %d\nThe avg is %f\nThe address is %s\nThe tell is %s\n", current->name,
                current->fam,
                current->code,
                current->id,
                current->gender,
                current->avg,
                current->address,
                current->tell);
        }
        current = current->next;
    }
}


//Sort & list's functions

void swap(struct student_t* a, struct student_t* b)
{

    char *temp[257];
    int temp_int = 0;
    float temp_f = 0;

    temp_int = a->id;
    a->id = b->id;
    b->id = temp_int;

    strcpy(temp, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name,temp);

    strcpy(temp, a->fam);
    strcpy(a->fam, b->fam);
    strcpy(b->fam, temp);

    strcpy(temp, a->code);
    strcpy(a->code, b->code);
    strcpy(b->code, temp);

    temp_int = a->gender;
    a->gender = b->gender;
    b->gender = temp_int;

    temp_f = a->avg;
    a->avg = b->avg;
    b->avg = temp_f;

    strcpy(temp, a->address);
    strcpy(a->address, b->address);
    strcpy(b->address, temp);

    strcpy(temp, a->tell);
    strcpy(a->tell, b->tell);
    strcpy(b->tell, temp);
}

void sort()  //bubbleSort
{
    int swapped = 0, i = 0;
    struct student_t* ptr1=NULL;
    struct student_t* lptr = NULL;
    struct student_t* temp = NULL;

    /* Checking for empty list */
    if (HEAD == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = HEAD;

        while (ptr1->next != lptr)
        {
            if (ptr1->id > ptr1->next->id)
            {
                swap(ptr1, ptr1->next);
/*
                temp->next = ptr1;
                ptr1 = ptr1->next;
                ptr1->next = temp->next;
  */              

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//Main
int main()
{
    int com = 0, com_s=0,d=0;

    while (1)
    {
        printf("\n\n1: Add student(s)\n2: All Informations\n3: Delete\n4: Edit\n5: Search\n6: Exit\nEnter your Command:\n");
        scanf("%d", &com);

        switch (com)
        {

        case 1:
            printf("\n\t1: Read Frome File\n\t2: Enter data");
            printf("\n\tEnter your Command:");
            int com1 = 0;
            scanf("%d", &com1);


            if (com1 == 2)
            {
                add_by_user();
            }
            else if (com1 == 1)
            {
                add_from_file();
            }

            else
            {
                printf("\n\t\tWrrong command!\n");
            }
            break;

        case 2:
            printf("\n\t1: Print to File\n\t2: Print on screen");
            printf("\n\tEnter your Command:");
            int com2 = 0;
            scanf("%d", &com2);

            if (com2 == 2)
            {
                sort();
                printlist();
            }
            else if (com2 == 1)
            {
                sort();
                print_to_file();
            }
            else
            {
                printf("\n\t\tWrrong command!\n");
            }
            break;

        case 3:
            printf("\n\t\tEnter 1 for delete an item\n\t\tand 2 for delete all students data\n\t\t");
            scanf("%d", &d);

            if (d == 1)
            {
                del_item();
            }
            else if (d == 2)
            {
                    HEAD = NULL;
            }

            else
                printf("\nWrrog command \n");
            break;

        case 4:
            edit();
            break;
        case 5:

            com_s = 0;
    
            while (com_s != 9)
            {
                printf("\n\t\tWhich item do you want to search: \n\t\t1: Name\n\t\t2: Family\n\t\t3: Code\n\t\t4: ID\n\t\t5: Gender\n\t\t6: Avg\n\t\t7: Address\n\t\t8: Tell\n\n\t\t9: Exit Search\n\n\t\tEnter your Command:\n\t\t");
              
                scanf("%d", &com_s);

                switch (com_s)
                {
                case 1:
                    search_name(com_s);
                    break;

                case 2:
                    search_fam(com_s);
                    break;

                case 3:
                    search_code(com_s);
                    break;

                case 4:
                    search_id(com_s);
                    break;

                case 5:
                    search_gender(com_s);
                    break;

                case 6:
                    search_avg(com_s);
                    break;

                case 7:
                    search_address(com_s);
                    break;

                case 8:
                    search_tell(com_s);
                    break;
                }
            }
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nError! operator is not correct\n \a");
        }
    }

    return 0;
}
