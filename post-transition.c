// https://www.hackerrank.com/challenges/post-transition
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
   int min_weight;
   int max_weight;
   package* packages;
   int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;


void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < (t.offices + i)->packages_count; j++) {
            printf("\t\t%s\n", ((t.offices + i)->packages + j)->id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    package *new_packages_source, *new_packages_target;
    int packages_count_s, packages_count_t;
    post_office office_source, office_target;
    office_source = source->offices[source_office_index];
    office_target = target->offices[target_office_index];
    packages_count_s = office_source.packages_count;
    packages_count_t = office_target.packages_count;
    
    // count acceptable packages
    int weight, count_acceptable = 0;
    for (int i = 0; i < packages_count_s; i++) {
        weight = office_source.packages[i].weight;
        if (weight >= office_target.min_weight && weight <= office_target.max_weight) {
            count_acceptable++;
        }
    }
    // printf("Preparing to move %d packages.\n", count_acceptable);
    
    // create new package buffer for target post office
    new_packages_target = (package*) malloc(sizeof(package)*(packages_count_t+count_acceptable));
    memcpy(new_packages_target, office_target.packages, sizeof(package) * packages_count_t);
    
    // create new package buffer for source post office
    new_packages_source = (package*) malloc(sizeof(package)*(packages_count_s-count_acceptable));
    
    int package_index_target = packages_count_t;
    int package_index_source = 0;
    for (int i = 0; i < packages_count_s; i++) {
        weight = office_source.packages[i].weight;
        if (weight >= office_target.min_weight && weight <= office_target.max_weight) {
            // move to target office
            // printf("Moving package: %s\n", office_source.packages[i].id);
            new_packages_target[package_index_target++] = office_source.packages[i];
        } else {
            // keep at source office
            // printf("Not moving package: %s\n", office_source.packages[i].id);
            new_packages_source[package_index_source++] = office_source.packages[i];
        }
    }
    
    // printf("Original source packages: ");
    // for (int i = 0; i < office_source.packages_count; i++) {
    //     printf("%s%c", office_source.packages[i].id, i == (office_source.packages_count - 1)?'\n':' ');
    // }
    // printf("Original target packages: ");
    // for (int i = 0; i < office_target.packages_count; i++) {
    //     printf("%s%c", office_target.packages[i].id, i == (office_target.packages_count - 1)?'\n':' ');
    // }
    
    free(target->offices[target_office_index].packages);
    free(source->offices[source_office_index].packages);
    target->offices[target_office_index].packages = new_packages_target;
    source->offices[source_office_index].packages = new_packages_source;
    target->offices[target_office_index].packages_count += count_acceptable;
    source->offices[source_office_index].packages_count -= count_acceptable;
    
    
    // printf("New source packages: ");
    // for (int i = 0; i < source->offices[source_office_index].packages_count; i++) {
    //     printf("%s%c", source->offices[source_office_index].packages[i].id, i == (source->offices[source_office_index].packages_count - 1)?'\n':' ');
    // }
    // printf("New target packages: ");
    // for (int i = 0; i < target->offices[target_office_index].packages_count; i++) {
    //     printf("%s%c", target->offices[target_office_index].packages[i].id, i == (target->offices[target_office_index].packages_count - 1)?'\n':' ');
    // }
}

int count_packages_in_town(town t) {
    int count = 0;
    for (int i = 0; i < t.offices_count; i++) {
        count += t.offices[i].packages_count;
    }
    // printf("Town %s has %d packages.\n", t.name, count);
    return count;
}

town town_with_most_packages(town* towns, int towns_count) {
    town *max_t;
    int max_package_count = 0, package_count;
    for (int i = 0; i < towns_count; i++) {
        package_count = count_packages_in_town(*(towns + i));
        if (package_count > max_package_count) {
            max_package_count = package_count;
            max_t = (towns + i);
        }
    }
    // printf("Town %s has the most packages.\n", max_t->name);
    return *max_t;
}

town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp((towns+i)->name, name) == 0) {
            // printf("Found town: %s\n", (towns+i)->name);
            return towns + i;
        }
        // printf("%s =/= %s\n", (towns+i)->name, name);
    }
    return NULL;
}

int main()
{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town)*towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    
    // town* t = find_town(towns, towns_count, "A");
    // printf("Connected to town: %s\n", t->name);
    // print_all_packages(*t);
    // printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
    
    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];
    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
        case 1:
            scanf("%s", town_name);
            town* t = find_town(towns, towns_count, town_name);
            // printf("Connected to town: %s\n", t->name);
            print_all_packages(*t);
            break;
        case 2:
            scanf("%s", town_name);
            town* source = find_town(towns, towns_count, town_name);
            int source_index;
            scanf("%d", &source_index);
            scanf("%s", town_name);
            town* target = find_town(towns, towns_count, town_name);
            int target_index;
            scanf("%d", &target_index);
            send_all_acceptable_packages(source, source_index, target, target_index);
            break;
        case 3:
            printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
            break;
        }
    }
    return 0;
}
