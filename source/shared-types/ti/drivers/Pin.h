#ifndef PIN_H
#define PIN_H

#include <stdint.h>


extern "C" {

#define IOID_0                  0x00000000  // IO Id 0
#define IOID_1                  0x00000001  // IO Id 1
#define IOID_2                  0x00000002  // IO Id 2
#define IOID_3                  0x00000003  // IO Id 3
#define IOID_4                  0x00000004  // IO Id 4
#define IOID_5                  0x00000005  // IO Id 5
#define IOID_6                  0x00000006  // IO Id 6
#define IOID_7                  0x00000007  // IO Id 7
#define IOID_8                  0x00000008  // IO Id 8
#define IOID_9                  0x00000009  // IO Id 9
#define IOID_10                 0x0000000A  // IO Id 10
#define IOID_11                 0x0000000B  // IO Id 11
#define IOID_12                 0x0000000C  // IO Id 12
#define IOID_13                 0x0000000D  // IO Id 13
#define IOID_14                 0x0000000E  // IO Id 14
#define IOID_15                 0x0000000F  // IO Id 15
#define IOID_16                 0x00000010  // IO Id 16
#define IOID_17                 0x00000011  // IO Id 17
#define IOID_18                 0x00000012  // IO Id 18
#define IOID_19                 0x00000013  // IO Id 19
#define IOID_20                 0x00000014  // IO Id 20
#define IOID_21                 0x00000015  // IO Id 21
#define IOID_22                 0x00000016  // IO Id 22
#define IOID_23                 0x00000017  // IO Id 23
#define IOID_24                 0x00000018  // IO Id 24
#define IOID_25                 0x00000019  // IO Id 25
#define IOID_26                 0x0000001A  // IO Id 26
#define IOID_27                 0x0000001B  // IO Id 27
#define IOID_28                 0x0000001C  // IO Id 28
#define IOID_29                 0x0000001D  // IO Id 29
#define IOID_30                 0x0000001E  // IO Id 30
#define IOID_31                 0x0000001F  // IO Id 31


#define PIN_GEN             (((uint32_t)1)<<31) ///< Flags that generic options are used

#define PIN_INPUT_EN        (PIN_GEN|(0<<29))   ///< (*) Enable input buffer
#define PIN_INPUT_DIS       (PIN_GEN|(1<<29))   ///< Disable input buffer
#define PIN_HYSTERESIS      (PIN_GEN|(1<<30))   ///< Enable input buffer hysteresis
#define PIN_NOPULL          (PIN_GEN|(0<<13))   ///< (*) No pull-up or pull-down resistor
#define PIN_PULLUP          (PIN_GEN|(1<<13))   ///< Pull-up resistor enabled
#define PIN_PULLDOWN        (PIN_GEN|(2<<13))   ///< Pull-down resistor enabled
#define PIN_BM_INPUT_EN     (1<<29)             ///< Bitmask for input enable option
#define PIN_BM_HYSTERESIS   (1<<30)             ///< Bitmask input hysteresis option
#define PIN_BM_PULLING      (0x3<<13)           ///< Bitmask for pull-up/pull-down options

/// Bitmask for all input mode options
#define PIN_BM_INPUT_MODE   (PIN_BM_INPUT_EN|PIN_BM_HYSTERESIS|PIN_BM_PULLING)

#define PIN_GPIO_OUTPUT_DIS (PIN_GEN|(0<<23))   ///< (*) Disable output buffer when GPIO
#define PIN_GPIO_OUTPUT_EN  (PIN_GEN|(1<<23))   ///< Enable output buffer when GPIO
#define PIN_GPIO_LOW        (PIN_GEN|(0<<22))   ///< Output buffer drives to VSS when GPIO
#define PIN_GPIO_HIGH       (PIN_GEN|(1<<22))   ///< Output buffer drives to VDD when GPIO
#define PIN_PUSHPULL        (PIN_GEN|(0<<25))   ///< (*) Output buffer mode: push/pull
#define PIN_OPENDRAIN       (PIN_GEN|(2<<25))   ///< Output buffer mode: open drain
#define PIN_OPENSOURCE      (PIN_GEN|(3<<25))   ///< Output buffer mode: open source
#define PIN_SLEWCTRL        (PIN_GEN|(1<<12))   ///< Enable output buffer slew control
#define PIN_DRVSTR_MIN      (PIN_GEN|(0x0<<8))  ///< (*) Lowest drive strength
#define PIN_DRVSTR_MED      (PIN_GEN|(0x4<<8))  ///< Medium drive strength
#define PIN_DRVSTR_MAX      (PIN_GEN|(0x8<<8))  ///< Highest drive strength
#define PIN_BM_GPIO_OUTPUT_EN  (1<<23)          ///< Bitmask for output enable option
#define PIN_BM_GPIO_OUTPUT_VAL (1<<22)          ///< Bitmask for output value option
#define PIN_BM_OUTPUT_BUF   (0x3<<25)           ///< Bitmask for output buffer options
#define PIN_BM_SLEWCTRL     (0x1<<12)           ///< Bitmask for slew control options
#define PIN_BM_DRVSTR       (0xF<<8)            ///< Bitmask for drive strength options

/// Bitmask for all output mode options
#define PIN_BM_OUTPUT_MODE  (PIN_BM_GPIO_OUTPUT_VAL|PIN_BM_GPIO_OUTPUT_EN| \
                             PIN_BM_OUTPUT_BUF|PIN_BM_SLEWCTRL|PIN_BM_DRVSTR)

#define PIN_INV_INOUT       (PIN_GEN|(1<<24))   ///< Logically invert input and output
#define PIN_BM_INV_INOUT    (1<<24)             ///< Bitmask for input/output inversion option

#define PIN_IRQ_DIS         (PIN_GEN|(0x0<<16)) ///< (*) Disable IRQ on pin
#define PIN_IRQ_NEGEDGE     (PIN_GEN|(0x5<<16)) ///< Enable IRQ on negative edge
#define PIN_IRQ_POSEDGE     (PIN_GEN|(0x6<<16)) ///< Enable IRQ on positive edge
#define PIN_IRQ_BOTHEDGES   (PIN_GEN|(0x7<<16)) ///< Enable IRQ on both edges
#define PIN_BM_IRQ          (0x7<<16)           ///< Bitmask for pin interrupt option



}



#endif
