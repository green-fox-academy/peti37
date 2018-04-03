#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer comp;
    comp.cpu_speed_GHz = 3.4;
    comp.ram_size_GB = 4;
    comp.bits = 32;

    Notebook note;
    note.cpu_speed_GHz = 2.8;
    note.ram_size_GB = 8;
    note.bits = 64;

    printf("PC data: cpu: %.1f, ram: %d, bits: %d\n", comp.cpu_speed_GHz, comp.ram_size_GB, comp.bits);
    printf("NoteBook data: cpu: %.1f, ram: %d, bits: %d", note.cpu_speed_GHz, note.ram_size_GB, note.bits);

    return 0;
}
