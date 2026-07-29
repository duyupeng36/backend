#include <stdio.h>


enum corvid { magpie, raven, jay, chough, corvid_num, };

#define CORVID_NAMES  (constexpr char[corvid_num][8]){ [chough] = "chough", [raven] = "raven", [magpie] = "magpie", [jay] = "jay", }


int main(void) {

    for (unsigned i = 0; i < corvid_num; ++i) {
        printf("Corvid %u is the %s\n", i, CORVID_NAMES[i]);
    }
}
