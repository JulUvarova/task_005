#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 256
#define SPEED 60
#define RELAX 8
#define MAX_TIME_TO_MOVE 8

typedef struct {
    char town[NMAX];
    int x;
    int y;
    int is_relax;
} Waypoint;

void exit_with_error();
void input(char file_path[NMAX]);
void read_route(char file_path[NMAX], int* poit_count, Waypoint* waypoints);
int calculate_trip(Waypoint* points, int poit_count);
void output(int result, int point_count, Waypoint* waypoints);
