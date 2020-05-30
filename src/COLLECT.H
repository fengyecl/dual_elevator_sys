#define MODE0 0
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4
#define MODE5 5
#define MODE6 6
#define MODE7 7

#define OFF 0
#define ON 1



void collect_page( int page, int op[2], int *mouseX, int *mouseY,int *button);
void collect_lift( int op[2], int *ce, int *mp, int *mouseX, int *mouseY, int *button);