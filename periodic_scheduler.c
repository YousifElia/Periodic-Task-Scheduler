#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MS_TO_NS(ms) ((ms) * 1000000L)

void read_sensor() {
    printf("[10ms] Sensor read\n");
}

void control_logic() {
    printf("[50ms] Control logic\n");
}

void log_data() {
    printf("[100ms] Logging data\n");
}

int main() {
    struct timespec start, now;
    clock_gettime(CLOCK_MONOTONIC, &start);

    long elapsed_ms = 0;

    while (elapsed_ms < 1000) { // run for 1 second
        clock_gettime(CLOCK_MONOTONIC, &now);
        elapsed_ms = (now.tv_sec - start.tv_sec) * 1000 +
                     (now.tv_nsec - start.tv_nsec) / 1000000;

        if (elapsed_ms % 10 == 0)
            read_sensor();

        if (elapsed_ms % 50 == 0)
            control_logic();

        if (elapsed_ms % 100 == 0)
            log_data();

        usleep(1000); // sleep 1ms to reduce CPU load
    }

    return 0;
}
