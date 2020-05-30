#define A 0
#define B 1

#define EN 0
#define CN 1

#define NONE 0
#define OPEN 1
#define CLOSE 2

#define OFF 0
#define ON 1

#define MAX 9
#define MIN 10

#define DOWN 2
#define UP 1
#define STAY 0

struct Lift
{
    int flo_state;
    int flo_line;//�����ƶ�����������
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

void control( int op[2], int *ce, int *mouseX, int *mouseY, int *button);
void mov_next( struct Lift *lift);
void check( struct Lift *lift, int lift_ab);