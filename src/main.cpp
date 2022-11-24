#include <cstring>

#include "profile.h"


static int help()
{
    // TODO - help.
    return 0;
}

static void manager_prompt(Himitsu::Profile &profile)
{

}


int main(int argc, char *argv[])
{
    Himitsu::Profile profile;

    if (argv[1] == NULL) {
        return help();
    } else if (!strcmp(argv[1], "--make-profile")) {
        if (argv[2] == NULL) return help();
        if (argv[3] == NULL) return help();
        if (argv[4] == NULL) return help();
        profile.mk_new_prof(argv[2], argv[3], argv[4]);
    } else if (!strcmp(argv[1], "--delete-profile")) {
        if (argv[2] == NULL) return help();
        if (argv[3] == NULL) return help();
        if (argv[4] == NULL) return help();
        profile.del_prof(argv[2], argv[3], argv[3]);
    } else if (!strcmp(argv[1], "--start-manager")) {
        manager_prompt(profile);
    }
}
