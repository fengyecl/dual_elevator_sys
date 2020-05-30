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
    int flo_line;//电梯移动画线纵坐标
    int mov_state[2];//mov_state[0]表示运动趋势，mov_state[1]表示运动状态
    int door_line;
    int door_call;//电梯门开关需求
    int door_state;//电梯门开关状态
    int door_flag;//电梯门是否完全关闭
    int urge_call;
    int callup[11];//向上呼叫请求存储
    int calldown[11];//向下呼叫请求存储
    int button_in[9];//内部按键存储
};

void control( int op[2], int *ce, int *mouseX, int *mouseY, int *button);
void mov_next( struct Lift *lift);
void check( struct Lift *lift, int lift_ab);