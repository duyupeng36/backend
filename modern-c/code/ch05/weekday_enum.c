
#include <stdio.h>
enum weekday : size_t { SUN, MON, TUE, WED, THU, FRI, SAT, DAYS_OF_WEEK };

char const*const weekday[DAYS_OF_WEEK] = {
    [SUN] = "Sunday",
    [MON] = "Monday",
    [TUE] = "Tuesday",
    [WED] = "Wednesday",
    [THU] = "Thursday",
    [FRI] = "Friday",
    [SAT] = "Saturday",
};

int main(void) {
    for (size_t i = SUN; i < DAYS_OF_WEEK; ++i) {
        puts(weekday[i]);
    }
}

