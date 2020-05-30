#define A 0
#define B 1

#define OFF 0
#define ON 1

#define DOWN 2
#define UP 1
#define STAY 0

#define MAX 9
#define MIN 10

#define TMOVE 5
#define TSTAY 5

struct Lift
{
    int flo_state;
    int flo_line;
    int mov_state[2];//mov_state[0]��ʾ�˶����ƣ�mov_state[1]��ʾ�˶�״̬
    int door_line;
    int door_call;//�����ſ�������
    int door_state;//�����ſ���״̬
    int door_flag;//�������Ƿ���ȫ�ر�
    int urge_call;
    int callup[11];//���Ϻ�������洢
    int calldown[11];//���º�������洢
    int button_in[9];//�ڲ������洢
};

void strategy( int flo_goal, struct Lift *lift_a, struct Lift *lift_b );
int time_compare( int flo_goal, int flo_state_a, int mov_state_a, int *callup_a, int *calldown_a, int flo_state_b, int mov_state_b, int *callup_b, int *calldown_b);
int time_move( int m, int n, int mov_state, int *callup, int *calldown);
int time_stay( int m, int n, int mov_state, int *callup, int *calldown);