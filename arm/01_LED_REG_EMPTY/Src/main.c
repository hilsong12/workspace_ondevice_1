
#include <stdint.h>

#define RCC_CR_HSEON    (1 << 16)     // HSE 오실레이터 ON 비트
#define RCC_CR_HSERDY   (1 << 17)     // HSE Ready 플래그
#define RCC_CR_PLLON    (1 << 24)     // PLL 오실레이터 ON 비트
#define RCC_CR_PLLRDY   (1 << 25)     // PLL Ready 플래그

#define RCC_PLLCFGR_PLLM_Pos   0       // PLLM 위치
#define RCC_PLLCFGR_PLLN_Pos   6       // PLLN 위치
#define RCC_PLLCFGR_PLLP_Pos   16      // PLLP 위치
#define RCC_PLLCFGR_PLLSRC_Pos 22      // PLL 소스 위치

#define FLASH_ACR_LATENCY_Pos 0        // 플래시 대기 시간
#define FLASH_ACR_LATENCY_3WS (3 << FLASH_ACR_LATENCY_Pos) // 3 Wait State 설정

#define RCC_CFGR_SW_Pos      0        // 시스템 클럭 소스 선택 위치
#define RCC_CFGR_SW_PLL      (2 << RCC_CFGR_SW_Pos)   // PLL 선택
#define RCC_CFGR_HPRE_Pos    4        // AHB 프리스케일러
#define RCC_CFGR_PPRE1_Pos   10       // APB1 프리스케일러
#define RCC_CFGR_PPRE2_Pos   13       // APB2 프리스케일러

#define RCC_AHB1ENR_GPIOAEN  (1 << 0) // GPIOA 클럭 활성화 비트
#define GPIOA_MODER_MODER5   (1 << (5 * 2))  // PA5를 출력 모드로 설정
#define GPIOA_ODR_ODR5       (1 << 5)  // PA5의 출력 데이터 비트

#define RCC_BASE 0x40023800 // RCC 레지스터의 기본 주소
#define FLASH_BASE 0x40023C00 // 플래시 레지스터의 기본 주소
#define GPIOA_BASE 0x40020000 // GPIOA 레지스터의 기본 주소

#define RCC_CR   (*(volatile uint32_t *)(RCC_BASE + 0x00))
#define RCC_PLLCFGR (*(volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_CFGR  (*(volatile uint32_t *)(RCC_BASE + 0x08))
#define FLASH_ACR  (*(volatile uint32_t *)(FLASH_BASE + 0x00))
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(volatile uint32_t *)(GPIOA_BASE + 0x14))
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30))  // RCC AHB1 Enable 레지스터 추가 정의

void SystemClock_Config(void)
{
    /* 1. HSE 활성화 */
    RCC_CR |= RCC_CR_HSEON;                    // HSE ON
    while (!(RCC_CR & RCC_CR_HSERDY));         // HSE Ready 플래그 대기

    /* 2. PLL 설정: PLLM, PLLN, PLLP 값 설정 */
    // HSE = 8MHz, 목표 SYSCLK = 100MHz
    RCC_PLLCFGR = (4 << RCC_PLLCFGR_PLLM_Pos) |    // PLLM = 4
                  (200 << RCC_PLLCFGR_PLLN_Pos)|    // PLLN = 200
                  (0x1 << RCC_PLLCFGR_PLLP_Pos)|    // PLLP = 4 (10: ÷4)
                  (1 << RCC_PLLCFGR_PLLSRC_Pos);    // PLL 소스 = HSE

    /* 3. PLL 활성화 */
    RCC_CR |= RCC_CR_PLLON;                    // PLL ON
    while (!(RCC_CR & RCC_CR_PLLRDY));         // PLL Ready 플래그 대기

    /* 4. AHB, APB1, APB2 분주기 설정 */
    RCC_CFGR |= (0 << RCC_CFGR_HPRE_Pos);     // AHB Prescaler = 1 (SYSCLK 그대로)
    RCC_CFGR |= (5 << RCC_CFGR_PPRE1_Pos);    // APB1 Prescaler = 4 (25MHz 최대)
    RCC_CFGR |= (4 << RCC_CFGR_PPRE2_Pos);    // APB2 Prescaler = 2 (50MHz 최대)

    /* 5. 플래시 메모리 설정 (Latency 조정) */
    FLASH_ACR |= FLASH_ACR_LATENCY_3WS;        // 3 Wait State (100MHz 동작 시 필요)

    /* 6. 시스템 클럭 소스로 PLL 선택 */
    RCC_CFGR |= RCC_CFGR_SW_PLL;              // SW[1:0] = 10 (PLL 선택)
    while ((RCC_CFGR & RCC_CFGR_SW_PLL) != RCC_CFGR_SW_PLL); // SWS 확인
}



int main()
{
    SystemClock_Config();  // 시스템 클럭 설정

    /* GPIO 설정 테스트용 */
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // GPIOA 클럭 활성화
    GPIOA_MODER |= GPIOA_MODER_MODER5;   // PA5를 출력 모드로 설정

    while (1) {
        GPIOA_ODR ^= GPIOA_ODR_ODR5;           // PA5 토글 (LED Blink)
        for (volatile int i = 0; i < 10000000; i++);  // 딜레이
    }
}

