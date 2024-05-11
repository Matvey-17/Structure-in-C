#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 100


struct user {
    char last_name[50];
    int number_book;
    char faculty[100];
    char group[100];
};


struct table
{
    struct user Users[MAX_USER];
    int cnt;
};


void setuser(struct table *p, int i) {
    printf("Введите фамилию: ");
    scanf("%s", p->Users[i].last_name);
    printf("Введите номер зачетной книжки: ");
    scanf("%d", &(p->Users[i].number_book));
    printf("Введите название факультета: ");
    scanf("%s", p->Users[i].faculty);
    printf("Введите название группы: ");
    scanf("%s", p->Users[i].group);
    printf("\n");
}


void setusers(struct table *Students, int n) {
    for (int i = Students->cnt; i < Students->cnt+n; i++) {
        setuser(Students, i);
    }
    Students->cnt+=n;
}


void showtable(struct table *Students) {
    for (int i = 0; i < Students->cnt; i++) {
        printf("Фамилия - %s\n", Students->Users[i].last_name);
        printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
        printf("Факультет - %s\n", Students->Users[i].faculty);
        printf("Название группы - %s\n", Students->Users[i].group);
        printf("\n");
    }
}


int sort_table_last_name(const void *a, const void *b) {
    struct user *userA = (struct user *)a;
    struct user *userB = (struct user *)b;
    return strcmp(userA->last_name, userB->last_name);
}


int sort_table_number_book(const void *a, const void *b) {
    struct user *userA = (struct user *)a;
    struct user *userB = (struct user *)b;
    return (userA->number_book - userB->number_book);
}


int sort_table_faculty(const void *a, const void *b) {
    struct user *userA = (struct user *)a;
    struct user *userB = (struct user *)b;
    return strcmp(userA->faculty, userB->faculty);
}


int sort_table_group(const void *a, const void *b) {
    struct user *userA = (struct user *)a;
    struct user *userB = (struct user *)b;
    return strcmp(userA->group, userB->group);
}


void delete_recording(struct table *Students, int number_recording) {
    for (int i = number_recording - 1; i < Students->cnt-1; i++) {
        Students->Users[i] = Students->Users[i + 1];
    }
    printf("Запись %d удалена\n", number_recording);
    printf("\n");
    Students->cnt--;
}


void search_last_name(struct table *Students, char *last_name_search) {
    for (int i = 0; i < Students->cnt; i++) {
        if (strlen(Students->Users[i].last_name) >= strlen(last_name_search)) {
            if (strstr(Students->Users[i].last_name, last_name_search)) {
                printf("Фамилия - %s\n", Students->Users[i].last_name);
                printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
                printf("Факультет - %s\n", Students->Users[i].faculty);
                printf("Название группы - %s\n", Students->Users[i].group);
                printf("\n");
            }
            else {
            printf("\n");
            }
        }
        else {
            if (strstr(last_name_search, Students->Users[i].last_name)) {
                printf("Фамилия - %s\n", Students->Users[i].last_name);
                printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
                printf("Факультет - %s\n", Students->Users[i].faculty);
                printf("Название группы - %s\n", Students->Users[i].group);
                printf("\n");
            }
            else {
            printf("\n");
            }
        }
    }
}


void search_number_book(struct table *Students, char *number_book_search) {
    char str_number_book[50];
    for (int i = 0; i < Students->cnt; i++) {
        sprintf(str_number_book, "%d", Students->Users[i].number_book);
        if (strlen(str_number_book) >= strlen(number_book_search)) {
            if (strstr(str_number_book, number_book_search)) {
                printf("Фамилия - %s\n", Students->Users[i].last_name);
                printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
                printf("Факультет - %s\n", Students->Users[i].faculty);
                printf("Название группы - %s\n", Students->Users[i].group);
                printf("\n");
            }
            else {
                printf("\n");
            }
        }
        else {
            if (strstr(number_book_search, str_number_book)) {
                printf("Фамилия - %s\n", Students->Users[i].last_name);
                printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
                printf("Факультет - %s\n", Students->Users[i].faculty);
                printf("Название группы - %s\n", Students->Users[i].group);
                printf("\n");
            }
            else {
                printf("\n");
            }
        }
    }
}


void search_faculty(struct table *Students, char *faculty_search) {
    for (int i = 0; i < Students->cnt; i++) {
        if (strlen(Students->Users[i].faculty) >= strlen(faculty_search)) {
            if (strstr(Students->Users[i].faculty, faculty_search)) {
                printf("Фамилия - %s\n", Students->Users[i].last_name);
                printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
                printf("Факультет - %s\n", Students->Users[i].faculty);
                printf("Название группы - %s\n", Students->Users[i].group);
                printf("\n");
            }
            else {
                printf("\n");
            }
        }
        else {
            if (strstr(faculty_search, Students->Users[i].faculty)) {
                printf("Фамилия - %s\n", Students->Users[i].last_name);
                printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
                printf("Факультет - %s\n", Students->Users[i].faculty);
                printf("Название группы - %s\n", Students->Users[i].group);
                printf("\n");
            }
            else {
                printf("\n");
            }
        }
    }
}


void search_group(struct table *Students, char *group_search) {
    for (int i = 0; i < Students->cnt; i++) {
        if (strlen(Students->Users[i].group) >= strlen(group_search)) {
            if (strstr(Students->Users[i].group, group_search)) {
                printf("Фамилия - %s\n", Students->Users[i].last_name);
                printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
                printf("Факультет - %s\n", Students->Users[i].faculty);
                printf("Название группы - %s\n", Students->Users[i].group);
                printf("\n");
            }
            else {
                printf("\n");
            }
        }
        else {
            if (strstr(group_search, Students->Users[i].group)) {
                printf("Фамилия - %s\n", Students->Users[i].last_name);
                printf("Номер зачетной книжки - %d\n", Students->Users[i].number_book);
                printf("Факультет - %s\n", Students->Users[i].faculty);
                printf("Название группы - %s\n", Students->Users[i].group);
                printf("\n");
            }
            else {
                printf("\n");
            }
        }
    }
}


void change_recording(struct table *Students, int number_change) {
    setuser(Students, number_change - 1);
}


void save_file_table(struct table *Students, FILE *file) {
    file = fopen("file.txt", "w");
    for (int i = 0; i < Students->cnt; i++) {
        fprintf(file, "Фамилия - %s\n", Students->Users[i].last_name);
        fprintf(file, "Номер зачетной книжки - %d\n", Students->Users[i].number_book);
        fprintf(file, "Факультет - %s\n", Students->Users[i].faculty);
        fprintf(file, "Название группы - %s\n", Students->Users[i].group);
        fprintf(file, "\n");
    }
    fclose(file);
}


void load_file(FILE *file) {
    char str_file[1000];
    file = fopen("file.txt", "r");
    if (file) {
        while (fgets(str_file, 1000, file) != NULL) {
            printf("%s", str_file);
        }
    }
}


void menu() {
    printf("[1] Добавить студентов в таблицу\n");
    printf("[2] Загрузка из файла\n");
    printf("[3] Сохранение таблицы в файл\n");
    printf("[4] Просмотр данных таблицы\n");
    printf("[5] Сортировка таблицы\n");
    printf("[6] Поиск элемента в таблице\n");
    printf("[7] Удалить запись в таблице\n");
    printf("[8] Изменить запись в таблице\n");
    printf("[9] Сумма всех студентов\n");
    printf("[0] Выход\n\n");
}


int main() {
    struct table Students;
    menu();
    FILE *file;
    int number;
    int number_pole;
    int number_recording;
    int number_change;
    char last_name_search[50];
    char number_book_search[50];
    char faculty_search[100];
    char group_search[100];
    int n;
    Students.cnt = 0;
    while (1) {
        printf("Введите команду: ");
        scanf("%d", &number);
        printf("\n");
        if (number == 0) break;
        switch (number)
        {
            case 1:
                printf("Введите количество студентов: ");
                scanf("%d", &n);
                setusers(&Students, n);
                break;
            case 4:
                showtable(&Students);
                break;
            case 5:
                printf("[1] Фамилия\n");
                printf("[2] Номер зачетной книжки\n");
                printf("[3] Факультет\n");
                printf("[4] Группа\n");
                printf("Введите по какому полю хотите отсортировать таблицу: ");
                scanf("%d", &number_pole);
                printf("\n");
                switch (number_pole) {
                    case 1:
                        qsort(Students.Users, Students.cnt, sizeof(struct user), sort_table_last_name);
                        break;
                    case 2:
                        qsort(Students.Users, Students.cnt, sizeof(struct user), sort_table_number_book);
                        break;
                    case 3:
                        qsort(Students.Users, Students.cnt, sizeof(struct user), sort_table_faculty);
                        break;
                    case 4:
                        qsort(Students.Users, Students.cnt, sizeof(struct user), sort_table_group);
                        break;
                }
                break;
            case 7:
                printf("Введите номер записи, которую хотите удалить: ");
                scanf("%d", &number_recording);
                if (number_recording > Students.cnt || number_recording == 0) {
                    printf("Запись не найдена\n");
                    printf("\n");
                    break;
                }
                else {
                    delete_recording(&Students, number_recording);
                    break;
                }
            case 6:
                printf("[1] Фамилия\n");
                printf("[2] Номер зачетной книжки\n");
                printf("[3] Факультет\n");
                printf("[4] Группа\n");
                printf("Введите по какому полю хотите найти элемент в таблице: ");
                scanf("%d", &number_pole);
                printf("\n");
                switch (number_pole) {
                    case 1:
                        printf("Введите фамилию для поиска: ");
                        scanf("%s", last_name_search);
                        search_last_name(&Students, last_name_search);
                        break;
                    case 2:
                        printf("Введите номер зачетной книжки для поиска: ");
                        scanf("%s", number_book_search);
                        search_number_book(&Students, number_book_search);
                        break;
                    case 3:
                        printf("Введите факультет для поиска: ");
                        scanf("%s", faculty_search);
                        search_faculty(&Students, faculty_search);
                        break;
                    case 4:
                        printf("Введите название группы для поиска: ");
                        scanf("%s", group_search);
                        search_group(&Students, group_search);
                        break;
                }
                break;
            case 8:
                printf("Введите номер записи, которую хотите изменить: ");
                scanf("%d", &number_change);
                if (number_change > Students.cnt) {
                    printf("Запись не найдена\n");
                    printf("\n");
                    break;
                }
                else {
                    change_recording(&Students, number_change);
                    printf("Запись %d удалена\n", number_change);
                    printf("\n");
                    break;
                }
            case 9:
                printf("Сумма всех студентов: %d\n", Students.cnt);
                printf("\n");
                break;
            case 3:
                save_file_table(&Students, file);
                printf("Запись сохранена в текстовый файл\n");
                printf("\n");
                break;
            case 2:
                load_file(file);
                break;
        }
    }
    return 0;
}

