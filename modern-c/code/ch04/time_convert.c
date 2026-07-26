/* time_convert.c - 时间转换 */
#include <stdio.h>
#include <stdlib.h>

constexpr long seconds_per_minute = 60;
constexpr long minutes_per_hour = 60;

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long seconds = strtol(argv[1], nullptr, 0);
    if (seconds < 0) {
        fprintf(stderr, "seconds must be greater than 0.\n");
        return EXIT_FAILURE;
    }
    long hours = seconds / (seconds_per_minute * minutes_per_hour);
    long minutes = seconds % (seconds_per_minute * minutes_per_hour) / seconds_per_minute;
    seconds = seconds % seconds_per_minute; // 剩余多少秒
    
    printf("%02ld:%02ld:%02ld\n", hours, minutes, seconds);
    return EXIT_SUCCESS; 
}
