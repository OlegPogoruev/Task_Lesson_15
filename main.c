#include <stdio.h>
#include <string.h>
#define MAX_LEN_NAME 255
#define MAX_LEN_SURNAME 255
#define MAX_LEN_PHONE 255


//number of entries in the phone book
#define NUMBER_ENTIRES 10

struct phonebook_element{
    char array_name[MAX_LEN_NAME];
    char array_surname[MAX_LEN_SURNAME];
    char array_phone[MAX_LEN_PHONE];
};

struct phonebook_element phonebook_array[NUMBER_ENTIRES];


int main(void)
{
    char temp_number;
    char temp_name_array[MAX_LEN_NAME] = {"Ivan_0"};
    char temp_surname_array[MAX_LEN_SURNAME] = {"Ivanov_0"};
    char temp_phone_array[MAX_LEN_PHONE] = {"89238277580"};
    unsigned int i, j;

    for(i = 0; i < NUMBER_ENTIRES; ++i)
    {
        temp_name_array[5] = i + 0x30;
        temp_surname_array[7] = i + 0x30;
        temp_phone_array[10] = i + 0x30;

        for(j = 0; j < MAX_LEN_NAME; ++j)
        {
            phonebook_array[i].array_name[j] = temp_name_array[j];
        }

        for(j = 0; j < MAX_LEN_SURNAME; ++j)
        {
            phonebook_array[i].array_surname[j] = temp_surname_array[j];
        }

        for(j = 0; j < MAX_LEN_PHONE; ++j)
        {
            phonebook_array[i].array_phone[j] = temp_phone_array[j];
        }

//        printf("Name = %s\n", phonebook_array[i].array_name);
//        printf("Surname = %s\n", phonebook_array[i].array_surname);
//        printf("Phone = %s\n", phonebook_array[i].array_phone);
    }
    printf("1 - add and rename abonent\n");
    printf("2 - list PhoneBook abonent\n");
    printf("3 - search abonent to name\n");
    printf("4 - delete abonent to number\n");
    printf("5 - exit\n");
    int c;
    unsigned int nc = 0;
    char temp_array[255];
    while(1)
    {

        nc = 0;
        while ((c = getchar()) != '\n')
        {
            temp_array[nc] = c;
            ++nc;
        }
        temp_array[nc] = 0;

        if((temp_array[0] == '1') && (1 == nc))
        {
            // 1 - добавить абонента
            printf("Enter number abonent\n");
            nc = 0;
            while ((c = getchar()) != '\n')
            {
                temp_array[nc] = c;
                ++nc;
            }
            temp_array[nc] = 0;
            if(((temp_array[0] < '0') || (temp_array[0] > '9')) && (1 != nc))
            {
                printf("Input Error number abonent\n");
                temp_array[0] = '1';  nc = 1;
            }
            else
            {
                temp_number = temp_array[0] - 0x30;
                printf("Enter name abonent\n");
                nc = 0;
                while ((c = getchar()) != '\n')
                {
                    temp_name_array[nc] = c;
                    ++nc;
                }
                temp_name_array[nc] = 0;
                if(nc > MAX_LEN_NAME)
                {
                    printf("Input Error name\n");
                    temp_array[0] = '1'; nc = 1;
                }
                else
                {
                    printf("Enter surname abonent\n");
                    nc = 0;
                    while ((c = getchar()) != '\n')
                    {
                        temp_surname_array[nc] = c;
                        ++nc;
                    }
                    temp_surname_array[nc] = 0;
                    if(nc > MAX_LEN_SURNAME)
                    {
                        printf("Input Error surname\n");
                        temp_array[0] = '1';  nc = 1;
                    }
                    else
                    {

                        printf("Enter phone number\n");
                        nc = 0;
                        while ((c = getchar()) != '\n')
                        {
                            temp_phone_array[nc] = c;
                            ++nc;
                        }
                        temp_phone_array[nc] = 0;
                        if(nc > MAX_LEN_PHONE)
                        {
                            printf("Input Error phone\n");
                            temp_array[0] = '1';  nc = 1;
                        }
                        else
                        {
                            for(j = 0; j < MAX_LEN_NAME; ++j)
                            {
                                phonebook_array[temp_number].array_name[j] = temp_name_array[j];
                            }
                            for(j = 0; j < MAX_LEN_SURNAME; ++j)
                            {
                                phonebook_array[temp_number].array_surname[j] = temp_surname_array[j];
                            }
                            for(j = 0; j < MAX_LEN_PHONE; ++j)
                            {
                                phonebook_array[temp_number].array_phone[j] = temp_phone_array[j];
                            }
                            temp_array[0] = '1';  nc = 1;
                        }
                    }

                }



            }


        }

        if((temp_array[0] == '2') && (1 == nc))
        {
            // 2 - список абонентов
            for(i = 0; i < NUMBER_ENTIRES; ++i)
            {
                printf("%2d Name = %s\n", i, phonebook_array[i].array_name);
                printf("%2d Surname = %s\n", i, phonebook_array[i].array_surname);
                printf("%2d Phone = %s\n", i, phonebook_array[i].array_phone);
            }
        }

        if((temp_array[0] == '3') && (1 == nc))
        {
            // 3 - Найти абоннента (неважно по имени или телефону)
            printf("Enter name search abonent\n");
            nc = 0;
            while ((c = getchar()) != '\n')
            {
                temp_name_array[nc] = c;
                ++nc;
            }
            temp_name_array[nc] = 0;
            if(nc > MAX_LEN_NAME)
            {
                printf("Input Error name\n");
                temp_array[0] = '3';  nc = 1;
            }
            else
            {
                char temp = 1;
                for(j = 0; j < NUMBER_ENTIRES; ++j)
                {
                    if(!strcmp (phonebook_array[j].array_name, temp_name_array))
                    {
                        temp = 0;
                        temp_number = j;
                        break;
                    }
                }

                if(!temp)
                {
                    printf("Name = %s\n", phonebook_array[temp_number].array_name);
                    printf("Surname = %s\n", phonebook_array[temp_number].array_surname);
                    printf("Phone = %s\n", phonebook_array[temp_number].array_phone);
                }
                else
                {
                    printf("No name in list\n");
                }
                temp_array[0] = '3'; nc = 1;
            }
        }

        if((temp_array[0] == '4') && (1 == nc))
        {
            // 4 - Удаление абонента
            printf("Enter number delete abonent\n");
            nc = 0;
            while ((c = getchar()) != '\n')
            {
                temp_array[nc] = c;
                ++nc;
            }
            temp_array[nc] = 0;
            if(((temp_array[0] < '0') || (temp_array[0] > '9')) || (1 != nc))
            {
                printf("Input Error number abonent\n");
                temp_array[0] = '4';  nc = 1;
            }
            else
            {
                temp_number = temp_array[0] - 0x30;
                for(j = 0; j < MAX_LEN_NAME; ++j)
                {
                    phonebook_array[temp_number].array_name[j] = 0;
                }
                for(j = 0; j < MAX_LEN_SURNAME; ++j)
                {
                    phonebook_array[temp_number].array_surname[j] = 0;
                }
                for(j = 0; j < MAX_LEN_PHONE; ++j)
                {
                    phonebook_array[temp_number].array_phone[j] = 0;
                }
                temp_array[0] = '4';  nc = 1;
            }

        }

        if((temp_array[0] == '5') && (1 == nc))
        {
            // 5 - Выйти
            break;
        }

        if(((temp_array[0] < '0') || (temp_array[0] > '5')) || (1 != nc))
        {
            printf("Input Error\n");
        }


    }

    printf("The End\n");


    return 0;
}

