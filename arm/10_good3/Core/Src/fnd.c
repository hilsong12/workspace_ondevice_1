#include "fnd.h"
#include "main.h"

const uint8_t FND_NUM[10] = {
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
};

GPIO_TypeDef* FND_PORT[7] = {FND_A_GPIO_Port,FND_B_GPIO_Port,FND_C_GPIO_Port,
                             FND_D_GPIO_Port,FND_E_GPIO_Port,FND_F_GPIO_Port,FND_G_GPIO_Port};

uint16_t FND_PIN[7] = {FND_A_Pin,FND_B_Pin,FND_C_Pin,FND_D_Pin,FND_E_Pin,FND_F_Pin,FND_G_Pin};

void FND_Update(uint8_t floor){
    uint8_t seg=FND_NUM[floor];
    for(uint8_t i=0;i<7;i++)
        HAL_GPIO_WritePin(FND_PORT[i],FND_PIN[i],(seg>>i)&0x01);
}
