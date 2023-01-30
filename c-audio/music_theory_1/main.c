#include <stdio.h>
int selectPitchClass(char note) {
    switch (note)
    {
        case 'C': case 'c':
        return 0;
        case 'D': case 'd':
        return 2;
        case 'E': case 'e':
        return 4;
        case 'F': case 'f':
        return 5;
        case 'G': case 'g':
        return 7;
        case 'A': case 'a':
        return 9;
        case 'B': case 'b':
        return 11;
        default:
        return -1;
    }
}

int main() {
    char note1, note2, dummy;
    int pc1, pc2, interval;
    // pc1 = 0, pc2 = 0, interval = 0;
    // note1 = '\n', note2 = '\n', dummy = '\n';
    printf("Please enter two natural notes\n");
     printf("First note:\n");
    scanf("%c%c", &note1, &dummy);
    printf("Second Note:\n");
    scanf("%c%c", &note2, &dummy);
    pc1 = selectPitchClass(note1);
    if(pc1 < 0) {
        printf("error %c is not a natural note\n", note1); return 1;
    }

    pc2 = selectPitchClass(note2);
    
    if(pc2 < 0) {
        printf("error %c is not a natural note\n", note2); return 1;
    }

    printf("Notes:%8c\t%c\n", note1, note2);
    printf("Pitch Class:%2d\t%d\n", pc1, pc2);
    printf("Interval:%8d\n", interval);

    interval = pc2 - pc1;
    if (interval < 0) interval += 12;
    else if (interval > 11) interval -= 12;
    switch (interval)
    {
    case 1:
        printf("minor 2nd up or major 7th down");
        break;
    case 2:
        printf("major 2nd up or minor 7th down");
        break;
    case 3:
        printf("minor 3rd up or major 6th down");
        break;
    case 4:
        printf("major 3rd up or minor 6th down");
        break;
    case 5:
        printf("perfect 4th up or perfect 5th down");
        break;
    case 6:
        printf("augmented 4th");
        break;
    case 7:
        printf("perfect 5th up or perfect 4th down");
        break;
    case 8:
        printf("minor 6th up or major 3rd down");
        break;
    case 9:
        printf("major 6th up or minor 3rd down");
        break;
    case 10:
        printf("minor 7th up or major 2nd down");
        break;
    case 11:
        printf("major 7th up or minor 2nd down");
        break;
    
    default:
        printf("unison");
        break;
    }

    return 0;
}