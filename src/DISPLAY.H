#define A 0
#define B 1

#define DOWN 2
#define UP 1
#define STAY 0

#define OFF 0
#define ON 1


void dis_button_in( int button_in[9], int lift);
void dis_button_out( int button_out[15]);
void dis_number( int flo_state, int lift);
void clean_out_num( int lift, int i);
void clean_in_num( int lift);
void dis_arrow( int mov_state, int lift);
void clean_out_arrow( int lift, int i);
void clean_in_arrow( int lift);


void dis_person( int m, int n);