#include <stdio.h>
#include <string.h>

int main()
{
    struct inside {
        char location[10];
        char* location_ptr;
    };

    struct outside {
        char best_Character[10];
        char* dwarf_ptr;
        struct inside setting;
        struct inside* setting_ptr;
    };

    struct outside Hobbit;
    strcpy(Hobbit.best_Character, "Thorin");
    Hobbit.dwarf_ptr = &Hobbit.best_Character[0];

    // Try only using this pointer for all required changes, not the struct itself.
    struct outside* Hobbit_ptr = &Hobbit;

    char favorite[] = "Bilbo";
    char dwarf[] = "Bombur";


    printf("access directly: %s\n", Hobbit_ptr->best_Character);
    printf("access via pointer: %s\n", Hobbit_ptr->dwarf_ptr);

    struct inside chapter1;
    strcpy(chapter1.location, "Shire");
    Hobbit.setting = chapter1;
    Hobbit.setting_ptr = &Hobbit.setting;
    Hobbit.setting.location_ptr = &Hobbit.setting.location[0];

    char new_location[] = "Mirkwoord";


    return 0;
}