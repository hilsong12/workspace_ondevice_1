
#ifndef INC_RCCAR_H_
#define INC_RCCAR_H_

#include "main.h"

//모터 속도 제어
#define speed_low 500
#define speed_middle 750
#define speed_high 1000

//바퀴 제어
#define left_forward tim->ccr1
#define left_backward tim->ccr2
#define right_forward tim->ccr3
#define right_backward tim->ccr4

//모터 구동
void rcCar_init();
void rcCar_mode();
void rcCar( char data);

//방향설정
void move_front();
void move_backward();
void move_left();
void move_right();
void move_stop();


#endif /* INC_RCCAR_H_ */
