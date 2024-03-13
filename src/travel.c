#include "travel.h"

int main(void) {
    char file_path[NMAX];
    input(file_path);
    int point_count = 0;
    Waypoint waypoints[NMAX];
    read_route(file_path, &point_count, waypoints);
    int result = calculate_trip(waypoints, point_count);
    output(result, point_count, waypoints);
    exit(EXIT_SUCCESS);
}

void input(char file_path[NMAX]) {
    if (scanf("%255s", file_path) != 1) exit_with_error();
}

void exit_with_error() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}

void read_route(char file_path[NMAX], int* point_count, Waypoint* waypoints) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) exit_with_error();
    char line[NMAX];
    while (fgets(line, (NMAX - 1), file) != NULL) {
        if (sscanf(line, "%255s %d %d", waypoints[*point_count].town, &waypoints[*point_count].x,
                   &waypoints[*point_count].y) != 3)
            exit_with_error();
        waypoints[*point_count].is_relax = 0;
        *point_count = *point_count + 1;
    }
    fclose(file);
}

int calculate_trip(Waypoint* points, int point_count) {
    int time_sum = 0;
    int count_to_relax = 0;
    for (int i = 1; i < point_count; i++) {
        int distance_to_point = abs(points[i].x - points[i - 1].x) + abs(points[i].y - points[i - 1].y);
        int time_to_point = distance_to_point / 60;
        if (distance_to_point % 60 != 0) time_to_point++;
        if (time_to_point > MAX_TIME_TO_MOVE) {
            printf("Travel is impossible!");
            exit(EXIT_SUCCESS);
        }
        time_sum += time_to_point;
        count_to_relax += time_to_point;
        if (count_to_relax > 8) {
            time_sum += RELAX;
            points[i - 1].is_relax = 1;
            count_to_relax = time_to_point;
        }
    }
    return time_sum;
}

void output(int result, int point_count, Waypoint* waypoints) {
    for (int i = 0; i < point_count; i++) {
        if (waypoints[i].is_relax == 1 || i == 0 || i == point_count - 1) printf("%s\n", waypoints[i].town);
    }
    printf("%d", result);
}