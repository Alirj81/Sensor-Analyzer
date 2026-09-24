#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_DATA 10000

typedef struct {
        char dateandTime[20];
        char model[20];
        char valuetext[20];
        char state[20];
    } Data;
typedef struct{
    char Device[20];
    int Valid_readings;
    float Sum;
    float Average;
    float Minimum;
    float Maximum;
    int WARNING;
    int CRITICAL;
}output;

void update_stats(output *stat, float value, const char *state){
    if (stat->Valid_readings == 0) {
        stat->Minimum = value;
        stat->Maximum = value;
    } 
    else {
    if (value < stat->Minimum) {
        stat->Minimum = value;
    }

    if (value > stat->Maximum) {
        stat->Maximum = value;
        }
    }
    if (strcmp(state, "WARNING") == 0) {
        stat->WARNING++;
    } else if (strcmp(state, "CRITICAL") == 0) {
        stat->CRITICAL++;
    }
    stat->Valid_readings++;
    stat->Sum += value;
    stat->Average = stat->Sum / stat->Valid_readings;
    

}

int find_or_create_device(output stats[], int *device_count, const char *model){
    if (device_count == NULL || model == NULL) {
        return -1; // Invalid input
    }
    else{
        for (int i = 0; i < *device_count; i++) {
            if (strcmp(stats[i].Device, model) == 0) {
                return i; // Return index of found device
            }
        }
        // Device not found, create a new entry
        strcpy(stats[*device_count].Device, model);
        stats[*device_count].Valid_readings = 0;
        stats[*device_count].Sum = 0.0f;
        stats[*device_count].Average = 0.0f;
        stats[*device_count].WARNING = 0;
        stats[*device_count].CRITICAL = 0;
        (*device_count)++;
        return *device_count - 1; // Return index of newly created device
    }
}

int main(){
    int i = 0;
    char input[10000];
    char askedmodel[20];
    output stats [MAX_DATA];
    Data data;
    FILE *file = fopen("read.txt", "r");
    bool value_valid;
    int valid = 0; int malformed = 0;
    int device_count = 0;
    int index = 0;
    if (file == NULL) {
        return 1;
    }
    

    while (fgets(input, sizeof input, file) != NULL) {
        int fields = sscanf(input, "%19[^;];%19[^;];%19[^;];%19[^\n]", data.dateandTime, data.model, data.valuetext, data.state);
        if (fields == 4) {
                char *end;
                float value = strtof(data.valuetext, &end);

                if (end == data.valuetext || *end != '\0') {
                    value_valid = false;
                } else {
                    value_valid = true;
                }
                if (value_valid) {
                // use value
                index = find_or_create_device(stats, &device_count, data.model);
                if (index != -1) {
                update_stats(&stats[index], value, data.state);
                }
                i++;
                valid++;
                } 
                else {
                malformed++;
                }
    }
        else if (fields != 4) {
    malformed++;
    continue;
}

    fclose(file);
    return 0;
    }
}

